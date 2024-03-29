//------------------------------------------------------------------------------
//  varbufferloader.cc
//  (C) 2014 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "varbufferloader.h"
#include "shadereffect.h"
#include "base/varbufferbase.h"
#include "gl4/gl4varbuffer.h"
#include "vk/vkvarbuffer.h"
#include "annotationloader.h"
#include "types.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
VarbufferLoader::VarbufferLoader()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
VarbufferLoader::~VarbufferLoader()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
VarbufferBase*
VarbufferLoader::Load(BinReader* reader, ShaderEffect* effect)
{
	VarbufferBase* varbuffer = 0;

	if (effect->header == Implementation::GLSL)
    {
		if (effect->major == 4) varbuffer = effect->GetAlloc().Alloc<GL4Varbuffer>();
    }
	else if (effect->header == Implementation::SPIRV)
	{
		varbuffer = effect->GetAlloc().Alloc<VkVarbuffer>();
	}
	else
	{
		varbuffer = effect->GetAlloc().Alloc<VarbufferBase>();
	}

	// start loading
	std::string name = reader->ReadString().c_str();
	unsigned alignedSize = reader->ReadUInt();
    QualifierFlags qualifierFlags = reader->ReadUInt();
	unsigned binding = reader->ReadUInt();
	unsigned set = reader->ReadUInt();

	// load annotations
	bool hasAnnotation = reader->ReadBool();
	if (hasAnnotation)
	{
		AnnotationLoader loader;
		loader.Load(reader, varbuffer);
	}

	// load offsets
	unsigned numOffsets = reader->ReadUInt();
	unsigned i;
	for (i = 0; i < numOffsets; i++)
	{
		std::string name = reader->ReadString().c_str();
		unsigned offset = reader->ReadUInt();
		varbuffer->offsetsByName[name] = offset;
	}

	// load internal buffer
	varbuffer->name = name;
	varbuffer->alignedSize = alignedSize;
	varbuffer->qualifiers = qualifierFlags;
	varbuffer->set = set;
	varbuffer->binding = binding;

	varbuffer->OnLoaded();
    return varbuffer;
}
} // namespace AnyFX