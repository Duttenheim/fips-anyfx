//------------------------------------------------------------------------------
//  samplerloader.cc
//  (C) 2016 gscept
//------------------------------------------------------------------------------
#include "samplerloader.h"
#include "base/samplerbase.h"
#include "shadereffect.h"

#include "gl4/gl4sampler.h"
#include "vk/vksampler.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
SamplerLoader::SamplerLoader()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
SamplerLoader::~SamplerLoader()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
SamplerBase* 
SamplerLoader::Load(BinReader* reader, ShaderEffect* effect)
{
	SamplerBase* sampler = 0;

	// get sampler
	if (effect->header == Implementation::GLSL)
	{
		if (effect->major == 4) sampler = effect->GetAlloc().Alloc<GL4Sampler>();
	}
	else if (effect->header == Implementation::SPIRV)
	{
		sampler = effect->GetAlloc().Alloc<VkSampler>();
	}
	else
	{
		sampler = effect->GetAlloc().Alloc<SamplerBase>();
	}
	
	// get name
    std::string name = reader->ReadString().c_str();
	sampler->name = name;
	sampler->binding = reader->ReadUInt();
	sampler->set = reader->ReadUInt();

	sampler->samplerSettings.filterMode =			(FilterMode)reader->ReadInt();
	sampler->samplerSettings.addressU =				(AddressMode)reader->ReadInt();
	sampler->samplerSettings.addressV =				(AddressMode)reader->ReadInt();
	sampler->samplerSettings.addressW =				(AddressMode)reader->ReadInt();
	sampler->samplerSettings.comparisonFunc =		(ComparisonFunc)reader->ReadInt();
	sampler->samplerSettings.borderColor =			(BorderColorMode)reader->ReadInt();
	sampler->samplerSettings.lodBias = reader->ReadFloat();
	sampler->samplerSettings.minLod = reader->ReadFloat();
	sampler->samplerSettings.maxLod = reader->ReadFloat();
	sampler->samplerSettings.maxAnisotropic = reader->ReadFloat();
	sampler->samplerSettings.isComparison = reader->ReadBool();
	sampler->samplerSettings.unnormalized = reader->ReadBool();
	
	// read textures
	unsigned numTextures = reader->ReadInt();
	sampler->textureVariables.resize(numTextures);
	unsigned i;
	for (i = 0; i < numTextures; i++)
	{
        std::string texture = reader->ReadString().c_str();
		VariableBase* var = effect->variables[texture];
		var->sampler = sampler;
		sampler->textureVariables[i] = var;		
	}

	sampler->OnLoaded();
	return sampler;
}

} // namespace AnyFX