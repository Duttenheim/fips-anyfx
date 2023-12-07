//------------------------------------------------------------------------------
//  programloader.cc
//  (C) 2016 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "programloader.h"
#include "annotationloader.h"
#include "base/programbase.h"
#include "base/renderstatebase.h"
#include "base/programbase.h"
#include "base/shaderbase.h"
#include "base/subroutinebase.h"
#include "base/variablebase.h"
#include "shadereffect.h"
#include "gl4/gl4program.h"
#include "vk/vkprogram.h"
#include "shadertypes.h"
#include <assert.h>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ProgramLoader::ProgramLoader()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
ProgramLoader::~ProgramLoader()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void 
ReadShader(ProgramBase::ShaderDef* shader, int fourcc, std::string& shaderName, BinReader* reader)
{
    int magic = reader->ReadInt();
    assert(magic == fourcc);
    shaderName = reader->ReadString().c_str();
    unsigned numSubroutineMappings = reader->ReadUInt();
    for (unsigned i = 0; i < numSubroutineMappings; i++)
    {
        std::string var = reader->ReadString().c_str();
        std::string imp = reader->ReadString().c_str();
    }
    shader->binarySize = reader->ReadUInt();
    shader->binary = reader->ReadBytes(shader->binarySize);
}

//------------------------------------------------------------------------------
/**
*/
bool
BindShader(ProgramBase::ShaderDef* shader, const ShaderEffect* effect, const std::string& shaderName)
{
    if (!shaderName.empty())
    {
        ShaderBase* shaderBase = effect->GetShader(shaderName);
        shader->shader = shaderBase;
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
ProgramBase*
ProgramLoader::Load(BinReader* reader, ShaderEffect* effect)
{
	ProgramBase* program = 0;
	
	// we should create our implementation back-end first
	if (effect->header == Implementation::GLSL)
	{
		if (effect->major == 4) program = new GL4Program;
	}
	else if (effect->header == Implementation::SPIRV)
	{
		program = new VkProgram;
	}
	else
	{
		program = new ProgramBase;
	}
	
    std::string name = reader->ReadString().c_str();
	program->name = name;

	bool hasAnnotation = reader->ReadBool();
	if (hasAnnotation)
	{
		AnnotationLoader loader;
		loader.Load(reader, program);
	}

	// read and set tessellation data
	bool supportsTessellation = reader->ReadBool();
	unsigned patchSize = reader->ReadUInt();
	unsigned numVsInputs = reader->ReadUInt();
	unsigned numPsOutputs = reader->ReadUInt();
	program->supportsTessellation = supportsTessellation;
	program->patchSize = patchSize;
	program->numVsInputs = numVsInputs;
	program->numPsOutputs = numPsOutputs;

	program->vsInputSlots.resize(program->numVsInputs);
	unsigned i;
	for (i = 0; i < program->numVsInputs; i++)
	{
		program->vsInputSlots[i] = reader->ReadUInt();
	}

	program->psOutputSlots.resize(program->numPsOutputs);
	for (i = 0; i < program->numPsOutputs; i++)
	{
		program->psOutputSlots[i] = reader->ReadUInt();
	}

    // read and set transform feedback support
    bool supportsTransformFeedback = reader->ReadBool();
	program->supportsTransformFeedback = supportsTransformFeedback;

    std::string vs, hs, ds, gs, ps, cs, ms, rg, ra, rc, rm, ri;
    ReadShader(&program->shaderBlock.vs, 'VERT', vs, reader);
    ReadShader(&program->shaderBlock.hs, 'HULL', hs, reader);
    ReadShader(&program->shaderBlock.ds, 'DOMA', ds, reader);
    ReadShader(&program->shaderBlock.gs, 'GEOM', gs, reader);
    ReadShader(&program->shaderBlock.ps, 'PIXL', ps, reader);
    ReadShader(&program->shaderBlock.cs, 'COMP', cs, reader);
    ReadShader(&program->shaderBlock.ms, 'MESH', ms, reader);
    ReadShader(&program->shaderBlock.rg, 'RAYG', rg, reader);
    ReadShader(&program->shaderBlock.ra, 'RAYA', ra, reader);
    ReadShader(&program->shaderBlock.rc, 'RAYC', rc, reader);
    ReadShader(&program->shaderBlock.rm, 'RAYM', rm, reader);
    ReadShader(&program->shaderBlock.ri, 'RAYI', ri, reader);

	// read names of active blocks
	unsigned numActiveBlocks = reader->ReadUInt();
	for (i = 0; i < numActiveBlocks; i++)
	{
		program->activeVarblockNames.insert(reader->ReadString().c_str());
	}

	// read names of active variables
	unsigned numActiveVars = reader->ReadUInt();
	for (i = 0; i < numActiveVars; i++)
	{
		program->activeVariableNames.insert(reader->ReadString().c_str());
	}

	// read variable buffer offsets
	unsigned numOffsets = reader->ReadUInt();
	for (i = 0; i < numOffsets; i++)
	{
		std::string var = reader->ReadString().c_str();
		unsigned offset = reader->ReadUInt();
		program->variableBlockOffsets[var] = offset;
	}

	int magic = reader->ReadInt();
	assert('RSTA' == magic);
    std::string rs = reader->ReadString().c_str();

    if (BindShader(&program->shaderBlock.vs, effect, vs))
        program->valid = true;
    if (BindShader(&program->shaderBlock.hs, effect, hs))
        if (!vs.empty()) program->valid = true;
    if (BindShader(&program->shaderBlock.ds, effect, ds))
        if (!vs.empty() && !hs.empty()) program->valid = true;
    if (BindShader(&program->shaderBlock.gs, effect, gs))
        if (!vs.empty()) program->valid = true;
    if (BindShader(&program->shaderBlock.ps, effect, ps))
        if (!vs.empty()) program->valid = true;
    if (BindShader(&program->shaderBlock.cs, effect, cs))
        program->valid = true;
    if (BindShader(&program->shaderBlock.ms, effect, ms))
        program->valid = true;

	// find shaders previously loaded in the effect and attach them to this program
	if (!vs.empty())
	{
		ShaderBase* vertexShader = effect->GetShader(vs);
		program->shaderBlock.vs.shader = vertexShader;
		program->valid = true;
	}
	
	if (!ps.empty())
	{
		ShaderBase* pixelShader = effect->GetShader(ps);
		program->shaderBlock.ps.shader = pixelShader;
		if (!vs.empty()) program->valid = true;
	}
	
	if (!hs.empty())
	{
		ShaderBase* hullShader = effect->GetShader(hs);
		program->shaderBlock.hs.shader = hullShader;
		if (!vs.empty()) program->valid = true;
	}

	if (!ds.empty())
	{
		ShaderBase* domainShader = effect->GetShader(ds);
		program->shaderBlock.ds.shader = domainShader;
		if (!vs.empty() && !hs.empty()) program->valid = true;
	}

	if (!gs.empty())
	{
		ShaderBase* geometryShader = effect->GetShader(gs);
		program->shaderBlock.gs.shader = geometryShader;
		if (!vs.empty()) program->valid = true;
	}

	if (!cs.empty())
	{
		ShaderBase* computeShader = effect->GetShader(cs);
		program->shaderBlock.cs.shader = computeShader;
		program->valid = true;
	}

	// assert there is a render state
	assert(!rs.empty());
	RenderStateBase* renderState = effect->GetRenderState(rs);
	program->renderState = renderState;
	program->OnLoaded();
	return program;
}

} // namespace AnyFX