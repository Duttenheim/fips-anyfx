//------------------------------------------------------------------------------
//  shader.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include <istream>
#include <string>
#include <algorithm>
#include <sstream>
#include "shader.h"
#include "programrow.h"
#include "parameter.h"
#include "datatype.h"
#include "util.h"
#include "structure.h"
#include "varblock.h"
#include "sampler.h"
#include "typechecker.h"
#include "generator.h"
#include "constant.h"
#include "varbuffer.h"
#include "subroutine.h"
#include "glslang/Include/ResourceLimits.h"
#include "SPIRV/GLSL.std.450.h"
#include "glslang/Public/ShaderLang.h"

#define max(x, y) x > y ? x : y

TBuiltInResource DefaultResources;

void SetupDefaultResources()
{
DefaultResources.maxLights = 32;												;
DefaultResources.maxClipPlanes = 6;												;
DefaultResources.maxTextureUnits = 32;											;
DefaultResources.maxTextureCoords = 32;											;
DefaultResources.maxVertexAttribs =64											;
DefaultResources.maxVertexUniformComponents =4096								;
DefaultResources.maxVaryingFloats =64											;
DefaultResources.maxVertexTextureImageUnits =32									;
DefaultResources.maxCombinedTextureImageUnits =65535							;
DefaultResources.maxTextureImageUnits =32										;
DefaultResources.maxFragmentUniformComponents =4096								;
DefaultResources.maxDrawBuffers =32												;
DefaultResources.maxVertexUniformVectors =128									;
DefaultResources.maxVaryingVectors =8											;
DefaultResources.maxFragmentUniformVectors =16									;
DefaultResources.maxVertexOutputVectors =16										;
DefaultResources.maxFragmentInputVectors =15									;
DefaultResources.minProgramTexelOffset =-8										;
DefaultResources.maxProgramTexelOffset =7										;
DefaultResources.maxClipDistances =8											;
DefaultResources.maxComputeWorkGroupCountX =65535								;
DefaultResources.maxComputeWorkGroupCountY =65535								;
DefaultResources.maxComputeWorkGroupCountZ =65535								;
DefaultResources.maxComputeWorkGroupSizeX =1024									;
DefaultResources.maxComputeWorkGroupSizeY =1024									;
DefaultResources.maxComputeWorkGroupSizeZ =64									;
DefaultResources.maxComputeUniformComponents =1024								;
DefaultResources.maxComputeTextureImageUnits =16								;
DefaultResources.maxComputeImageUniforms =8										;
DefaultResources.maxComputeAtomicCounters =8									;
DefaultResources.maxComputeAtomicCounterBuffers =1								;
DefaultResources.maxVaryingComponents =60										;
DefaultResources.maxVertexOutputComponents =64									;
DefaultResources.maxGeometryInputComponents =64									;
DefaultResources.maxGeometryOutputComponents =128								;
DefaultResources.maxFragmentInputComponents =128								;
DefaultResources.maxImageUnits =8												;
DefaultResources.maxCombinedImageUnitsAndFragmentOutputs =8						;
DefaultResources.maxCombinedShaderOutputResources =8							;
DefaultResources.maxImageSamples =0												;
DefaultResources.maxVertexImageUniforms =0										;
DefaultResources.maxTessControlImageUniforms =0									;
DefaultResources.maxTessEvaluationImageUniforms =0								;
DefaultResources.maxGeometryImageUniforms =0									;
DefaultResources.maxFragmentImageUniforms =8									;
DefaultResources.maxCombinedImageUniforms =8									;
DefaultResources.maxGeometryTextureImageUnits =16								;
DefaultResources.maxGeometryOutputVertices =256									;
DefaultResources.maxGeometryTotalOutputComponents =1024							;
DefaultResources.maxGeometryUniformComponents =1024								;
DefaultResources.maxGeometryVaryingComponents =64								;
DefaultResources.maxTessControlInputComponents =128								;
DefaultResources.maxTessControlOutputComponents =128							;
DefaultResources.maxTessControlTextureImageUnits =16							;
DefaultResources.maxTessControlUniformComponents =1024							;
DefaultResources.maxTessControlTotalOutputComponents =4096						;
DefaultResources.maxTessEvaluationInputComponents =128							;
DefaultResources.maxTessEvaluationOutputComponents =128							;
DefaultResources.maxTessEvaluationTextureImageUnits =16							;
DefaultResources.maxTessEvaluationUniformComponents =1024						;
DefaultResources.maxTessPatchComponents =120									;
DefaultResources.maxPatchVertices =32											;
DefaultResources.maxTessGenLevel =64											;
DefaultResources.maxViewports =16												;
DefaultResources.maxVertexAtomicCounters =0										;
DefaultResources.maxTessControlAtomicCounters =0								;
DefaultResources.maxTessEvaluationAtomicCounters =0								;
DefaultResources.maxGeometryAtomicCounters =0									;
DefaultResources.maxFragmentAtomicCounters =8									;
DefaultResources.maxCombinedAtomicCounters =8									;
DefaultResources.maxAtomicCounterBindings =1									;
DefaultResources.maxVertexAtomicCounterBuffers =0								;
DefaultResources.maxTessControlAtomicCounterBuffers =0							;
DefaultResources.maxTessEvaluationAtomicCounterBuffers =0						;
DefaultResources.maxGeometryAtomicCounterBuffers =0								;
DefaultResources.maxFragmentAtomicCounterBuffers =1								;
DefaultResources.maxCombinedAtomicCounterBuffers =1								;
DefaultResources.maxAtomicCounterBufferSize =16384								;
DefaultResources.maxTransformFeedbackBuffers =4									;
DefaultResources.maxTransformFeedbackInterleavedComponents =64					;
DefaultResources.maxCullDistances =8											;
DefaultResources.maxCombinedClipAndCullDistances =8								;
DefaultResources.maxSamples =4													;

DefaultResources.limits.nonInductiveForLoops =1									;
DefaultResources.limits.whileLoops =1											;
DefaultResources.limits.doWhileLoops =1											;
DefaultResources.limits.generalUniformIndexing =1								;
DefaultResources.limits.generalAttributeMatrixVectorIndexing =1					;
DefaultResources.limits.generalVaryingIndexing =1								;
DefaultResources.limits.generalSamplerIndexing =1								;
DefaultResources.limits.generalVariableIndexing =1								;
DefaultResources.limits.generalConstantMatrixVectorIndexing =1					;
}

namespace AnyFX
{

unsigned long long Shader::bindingIndices[8];
//------------------------------------------------------------------------------
/**
*/
Shader::Shader() :
    glslShader(0),
    hlslShader(0),
    codeOffset(0),
    binary(NULL),
    binarySize(0),
    binaryValid(false)
{
    this->symbolType = ShaderType;
}

//------------------------------------------------------------------------------
/**
*/
Shader::~Shader()
{

}

//------------------------------------------------------------------------------
/**
*/
void 
Shader::Destroy()
{
    if (this->glslShader) delete this->glslShader;
    if (this->hlslShader) delete this->hlslShader;
    if (binary) delete[] binary;
    this->func->Destroy();
}

//------------------------------------------------------------------------------
/**
*/
void 
Shader::Setup()
{
    // get line and row from function
    this->line = this->func->GetLine();
    this->row = this->func->GetPosition();
    this->file = this->func->GetFile();

    // inform all parameters which shader they belong to
    const unsigned numParams = this->func->GetNumParameters();
    unsigned i;
    for (i = 0; i < numParams; i++)
    {
        Parameter* param = this->func->GetParameter(i);
        param->SetShader(this);
    }

    SetupDefaultResources();
}

//------------------------------------------------------------------------------
/**
*/
void 
Shader::Generate(Generator& generator, const std::vector<Symbol*>& symbols)
{
    // clear formatted code
    this->preamble.clear();

    // get header
    const Header& header = generator.GetHeader();

    if (header.GetType() == Header::GLSL)
    {
        std::string version = AnyFX::Format("#version %d%d%d\n", header.GetMajor(), header.GetMinor(), header.GetMinor() > 10 ? header.GetMinor() % 10 : 0);
        this->preamble.append(version);

        this->preamble.append("#extension GL_GOOGLE_cpp_style_line_directive : enable\n");
        this->preamble.append("#define GLSL\n");
    }
    else if (header.GetType() == Header::SPIRV)
    {
        std::string version = AnyFX::Format("#version 460 core\n");
        this->preamble.append(version);

        // add SPIR-V specific remaps and define flag
        //this->preamble.append("#define gl_InstanceID gl_InstanceIndex\n");
        this->preamble.append("#define gl_VertexID gl_VertexIndex\n");
        this->preamble.append("#extension GL_GOOGLE_cpp_style_line_directive : enable\n");
        this->preamble.append("#extension GL_ARB_separate_shader_objects : enable\n");
        this->preamble.append("#extension GL_ARB_shading_language_420pack : enable\n");
        this->preamble.append("#extension GL_KHR_shader_subgroup_quad : enable\n");
        this->preamble.append("#extension GL_EXT_buffer_reference : enable\n");
        this->preamble.append("#extension GL_EXT_buffer_reference2 : enable\n");
        this->preamble.append("#extension GL_EXT_shader_16bit_storage : enable\n");
        if (this->shaderType >= ProgramRow::RayGenerationShader && this->shaderType <= ProgramRow::CallShader)
        {
            this->preamble.append("#extension GL_EXT_ray_tracing : enable\n");
            this->preamble.append("#extension GL_EXT_ray_query : enable\n");
            this->preamble.append("#extension GL_EXT_ray_flags_primitive_culling : enable\n");
        }

        this->preamble.append("#define SPIRV\n");
    }

    // this list holds a couple of defines which are inserted into the preamble of the code in order to be able to separate functions depending on shader type
    const std::string shaderDefines[] =
    {
        "#define VERTEX_SHADER 1\n\n",
        "#define HULL_SHADER 1\n\n",
        "#define DOMAIN_SHADER 1\n\n",
        "#define GEOMETRY_SHADER 1\n\n",
        "#define PIXEL_SHADER 1\n\n",
        "#define COMPUTE_SHADER 1\n\n",
        "#define TASK_SHADER 1\n\n",
        "#define MESH_SHADER 1\n\n",
        "#define RAY_GEN_SHADER 1\n\n",
        "#define RAY_ANYHIT_SHADER 1\n\n",
        "#define RAY_CLOSESTHIT_SHADER 1\n\n",
        "#define RAY_MISS_SHADER 1\n\n",
        "#define RAY_INTERSECTION_SHADER 1\n\n"
    };
    this->preamble.append(shaderDefines[this->shaderType]);

    // undefine functions which GL will complain about when compiling for certain shader targets (likely they won't be used at all)
    if (this->shaderType != ProgramRow::PixelShader)
    {
        this->preamble.append("#define dFdx(val) val\n");
        this->preamble.append("#define dFdy(val) val\n");
        this->preamble.append("#define fwidth(val) val\n");
    }

    unsigned i;
    for (i = 0; i < symbols.size(); i++)
    {
        Symbol* sym = symbols[i];
        this->preamble.append(sym->Format(header));

        if (sym->GetType() == Symbol::FunctionType)
        {
            Function* func = (Function*)sym;
            this->indexToFileMap[func->GetFileIndex()] = std::pair<std::string, std::string>(func->GetName(), func->GetFile());
        }
        else if (sym->GetType() == Symbol::SubroutineType)
        {
            Subroutine* subroutine = (Subroutine*)sym;
            this->indexToFileMap[subroutine->GetFileIndex()] = std::pair<std::string, std::string>(subroutine->GetName(), subroutine->GetFile());
        }
    }
    /*
    for (i = 0; i < structures.size(); i++)
    {
        const Structure& structure = structures[i];
        this->preamble.append(structure.Format(header));
    }

    for (i = 0; i < samplers.size(); i++)
    {
        const Sampler& sampler = samplers[i];
        this->preamble.append(sampler.Format(header));
    }

    for (i = 0; i < vars.size(); i++)
    {
        const Variable& var = vars[i];

        if (!var.IsSubroutine())
        {
            // variable is formatted by resolving the internal type to the target type
            this->preamble.append(var.Format(header));
        }		
    }

    for (i = 0; i < blocks.size(); i++)
    {
        const VarBlock& block = blocks[i];
        this->preamble.append(block.Format(header));
    }

    for (i = 0; i < buffers.size(); i++)
    {
        const VarBuffer& buffer = buffers[i];
        this->preamble.append(buffer.Format(header));
    }

    for (i = 0; i < functions.size(); i++)
    {
        const Function& func = functions[i];
        this->preamble.append(func.GetCode());
        this->indexToFileMap[func.GetFileIndex()] = std::pair<std::string, std::string>(func.GetName(), func.GetFile());
    }

    for (i = 0; i < subroutines.size(); i++)
    {
        const Subroutine& subroutine = subroutines[i];
        this->preamble.append(subroutine.Format(header));
        this->indexToFileMap[subroutine.GetFileIndex()] = std::pair<std::string, std::string>(subroutine.GetName(), subroutine.GetFile());
    }

    for (i = 0; i < vars.size(); i++)
    {
        const Variable& var = vars[i];

        if (var.IsSubroutine())
        {
            // generate subroutine vars
            this->preamble.append(var.Format(header));
        }
    }
    */

    switch (header.GetType())
    {
    case Header::GLSL:
        this->CompileGLSL(this->GenerateGLSL(&generator, header.GetMajor(), header.GetMinor()), &generator);
        this->binaryValid = false;
        break;
    case Header::SPIRV:
        this->CompileSPIRV(this->GenerateGLSL(&generator, 4, 5), &generator);
        this->binaryValid = true;
        break;
    case Header::HLSL:
        break;
    case Header::Metal:
        break;
    case Header::Wii:
        break;
    case Header::PS:
        break;
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Shader::CompileGLSL(const std::string& code, Generator* generator)
{	
    // start compilation
    bool compilationSuccess = false;

    // this seems a bit weird, we attempt to compile when we perform type checking
    // however, we only perform a test compilation just to see if the formatted GLSL code is syntactically correct
    const EShLanguage shaderTable[] =
    {
        EShLangVertex,
        EShLangFragment,
        EShLangGeometry,		// only accepted in GLSL3+
        EShLangTessControl,		// only accepted in GLSL4+
        EShLangTessEvaluation,	// only accepted in GLSL4+
        EShLangCompute,			// only accepted in GLSL4.3+
    };

    // create array of strings
    int* lengths = new int[2];
    const char** sources = new const char*[2];

    // the preamble part of the code should be the responsibility of AnyFX to ALWAYS get right
    // the rest of the code patches are up to the programmer
    sources[0] = this->preamble.c_str();
    lengths[0] = this->preamble.length();
        
    // add the shader source lastly, as such, everything before should be already defined
    sources[1] = code.c_str();
    lengths[1] = code.length();

    EShMessages messages = EShMsgSuppressWarnings;

        // add platform specific message output
#if defined(_MSC_VER)
    messages = (EShMessages)(messages | EShMsgMSVCFormat);
#elif defined(__GNUC__) || defined(__clang__)
    messages = (EShMessages)(messages | EShMsgClangGCCFormat);
#endif

    glslang::TShader* shaderObject = new glslang::TShader(shaderTable[this->shaderType]);
    shaderObject->setStringsWithLengths(sources, lengths, 2);

    // perform compilation
    const Header& header = generator->GetHeader();
    int versionNumber = header.GetMajor() * 100 + header.GetMinor() * 10;
    if (!shaderObject->parse(&DefaultResources, versionNumber, false, messages))
    {
        std::string res(shaderObject->getInfoLog());
        generator->Error(res);
    }
    
    this->glslShader = shaderObject;
    delete[] sources;
    delete[] lengths;

    // merge code
    this->formattedCode = this->preamble + code;
}

//------------------------------------------------------------------------------
/**
*/
void
Shader::CompileSPIRV(const std::string& code, Generator* generator)
{
    // start compilation
    bool compilationSuccess = false;

    // Setup conversion table to map anyfx shader index with glslang
    static constexpr EShLanguage shaderTable[] =
    {
        EShLangVertex,
        EShLangTessControl,
        EShLangTessEvaluation,
        EShLangGeometry,
        EShLangFragment,
        EShLangCompute,
        EShLangTaskNV,
        EShLangMeshNV,
        EShLangRayGen,
        EShLangAnyHit,
        EShLangClosestHit,
        EShLangMiss,
        EShLangIntersect,
        EShLangCallable
    };

    // create array of strings
    int* lengths = new int[2];
    const char** sources = new const char*[2];

    // the preamble part of the code should be the responsibility of AnyFX to ALWAYS get right
    // the rest of the code patches are up to the programmer
    sources[0] = this->preamble.c_str();
    lengths[0] = this->preamble.length();

    // add the shader source lastly, as such, everything before should be already defined
    sources[1] = code.c_str();
    lengths[1] = code.length();

    EShMessages messages = (EShMessages)(EShMsgDefault | EShMsgRelaxedErrors | EShMsgSpvRules | EShMsgVulkanRules);

    // add platform specific message output
#if defined(_MSC_VER)
    messages = (EShMessages)(messages | EShMsgMSVCFormat);
#elif defined(__GNUC__) || defined(__clang__)
    messages = (EShMessages)(messages | EShMsgClangGCCFormat);
#endif

    glslang::TShader* shaderObject = new glslang::TShader(shaderTable[this->shaderType]);
    shaderObject->setStringsWithLengths(sources, lengths, 2);

    // perform compilation
    const Header& header = generator->GetHeader();
    shaderObject->setEnvTarget(glslang::EShTargetSpv, glslang::EShTargetSpv_1_5);
    if (!shaderObject->parse(&DefaultResources, 460, EProfile::ENoProfile, false, true, messages))
    {
        std::string res(shaderObject->getInfoLog());
        generator->Error(res);
    }

    this->glslShader = shaderObject;
    delete[] sources;
    delete[] lengths;

    // formatted code is left empty since SPIR-V use a binary representation
    this->formattedCode = this->preamble + code;
}

//------------------------------------------------------------------------------
/**
*/
void
Shader::Compile(BinWriter& writer)
{
    writer.WriteInt(this->shaderType);
    writer.WriteString(this->name);

    // if we have no binary, write shader code directly
    if (!binaryValid) writer.WriteString(this->formattedCode);
    else              writer.WriteString("");

    if (this->shaderType == ProgramRow::ComputeShader)
    {
        writer.WriteInt(max(1, this->func->GetIntFlag(FunctionAttribute::LocalSizeX)));
        writer.WriteInt(max(1, this->func->GetIntFlag(FunctionAttribute::LocalSizeY)));
        writer.WriteInt(max(1, this->func->GetIntFlag(FunctionAttribute::LocalSizeZ)));
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Shader::TypeCheck(TypeChecker& typechecker)
{
    // type check function, this will make sure the function is properly formatted
    this->func->TypeCheck(typechecker);

    if (this->shaderType == ProgramRow::HullShader)
    {
        bool hasInputSize = this->func->HasIntFlag(FunctionAttribute::InputVertices);
        if (!hasInputSize)
        {
            std::string message = AnyFX::Format("Tessellation Control Shader: '%s' needs to define [inputvertices], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }

        bool hasOutputSize = this->func->HasIntFlag(FunctionAttribute::OutputVertices);
        if (!hasOutputSize)
        {
            std::string message = AnyFX::Format("Tessellation Control Shader: '%s' needs to define [outputvertices], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }
    else if (this->shaderType == ProgramRow::DomainShader)
    {
        bool hasInputVertices = this->func->HasIntFlag(FunctionAttribute::InputVertices);
        bool hasInputTopology = this->func->HasIntFlag(FunctionAttribute::Topology);
        if (!hasInputVertices)
        {
            std::string message = AnyFX::Format("Tessellation Evaluation Shader: '%s' needs to define [inputvertices], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }		
        
        // input topology and spacing is not optional
        if (!hasInputTopology)
        {
            std::string message = AnyFX::Format("Tessellation Evaluation Shader '%s' needs to define [topology], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }
    else if (this->shaderType == ProgramRow::GeometryShader)
    {
        bool hasInput = this->func->HasIntFlag(FunctionAttribute::InputPrimitive);
        bool hasOutput = this->func->HasIntFlag(FunctionAttribute::OutputPrimitive);
        bool hasMaxVerts = this->func->HasIntFlag(FunctionAttribute::MaxVertexCount);

        if (!hasInput)
        {
            std::string message = AnyFX::Format("Geometry Shader '%s' needs to define [inputprimitive], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
        if (!hasOutput)
        {
            std::string message = AnyFX::Format("Geometry Shader '%s' needs to define [outputprimitive], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
        if (!hasMaxVerts)
        {
            std::string message = AnyFX::Format("Geometry Shader '%s' needs to define [maxvertexcount], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }
    else if (this->shaderType == ProgramRow::ComputeShader)
    {
        bool hasLocalX = this->func->HasIntFlag(FunctionAttribute::LocalSizeX);
        bool hasLocalY = this->func->HasIntFlag(FunctionAttribute::LocalSizeY);
        bool hasLocalZ = this->func->HasIntFlag(FunctionAttribute::LocalSizeZ);

        if (!(hasLocalX || hasLocalY || hasLocalZ))
        {
            std::string message = AnyFX::Format("Compute shader '%s' doesn't define any local size, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.LinkError(message, this->GetFile(), this->GetLine());
        }
    }
    else if (this->shaderType == ProgramRow::MeshShader)
    {
        bool hasLocalX = this->func->HasIntFlag(FunctionAttribute::LocalSizeX);
        bool hasOutput = this->func->HasIntFlag(FunctionAttribute::OutputPrimitive);
        bool hasMaxVerts = this->func->HasIntFlag(FunctionAttribute::MaxVertexCount);
        bool hasMaxPrims = this->func->HasIntFlag(FunctionAttribute::MaxPrimitives);

        if (!hasLocalX)
        {
            std::string message = AnyFX::Format("Mesh shader '%s' doesn't define any local size, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.LinkError(message, this->GetFile(), this->GetLine());
        }
        if (!hasOutput)
        {
            std::string message = AnyFX::Format("Mesh Shader '%s' needs to define [output_primitive], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
        if (!hasMaxVerts)
        {
            std::string message = AnyFX::Format("Mesh Shader '%s' needs to define [max_vertex_count], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
        if (!hasMaxPrims)
        {
            std::string message = AnyFX::Format("Mesh Shader '%s' needs to define [max_primitive_count], %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }
    }
}

} // namespace AnyFX
