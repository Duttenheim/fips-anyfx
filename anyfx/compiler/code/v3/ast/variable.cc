//------------------------------------------------------------------------------
//  @file variable.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "variable.h"
#include "util.h"
#include <map>
namespace AnyFX
{

std::map<std::string, Variable::__Resolved::Type> stringToTypeLookup;
static bool isSetup = false;

//------------------------------------------------------------------------------
/**
*/
Variable::Variable()
    : arraySizeExpression(nullptr)
    , isArray(false)
{
    this->symbolType = VariableType;
    this->resolved = new Variable::__Resolved;

    // only setup once
    if (!isSetup)
    {
        stringToTypeLookup.insert(readWriteTextureTypeLookup.begin(), readWriteTextureTypeLookup.end());
        stringToTypeLookup.insert(textureTypeLookup.begin(), textureTypeLookup.end());
        stringToTypeLookup.insert(samplerTypeLookup.begin(), samplerTypeLookup.end());
        stringToTypeLookup.insert(inputAttachmentTypeLookup.begin(), inputAttachmentTypeLookup.end());
        stringToTypeLookup.insert(scalarTypeLookup.begin(), scalarTypeLookup.end());
        stringToTypeLookup.insert(samplerStateTypeLookup.begin(), samplerStateTypeLookup.end());
        stringToTypeLookup.insert(constantBufferTypeLookup.begin(), constantBufferTypeLookup.end());
        stringToTypeLookup.insert(storageBufferTypeLookup.begin(), storageBufferTypeLookup.end());
        stringToTypeLookup.insert(specialTypeLookup.begin(), specialTypeLookup.end());
        isSetup = true;
    }

    Variable::__Resolved* typeResolved = static_cast<Variable::__Resolved*>(this->resolved);
    typeResolved->type = Variable::__Resolved::InvalidType;
    typeResolved->accessFlags = 0x0;
    typeResolved->parameterFlags = 0x0;
    typeResolved->isConst = false;
    typeResolved->group = 0xF;
    typeResolved->binding = 0xF;
    typeResolved->isParameter = false;
}

const std::map<std::string, Variable::__Resolved::Type> readWriteTextureTypeLookup =
{
    { "ReadWriteTexture1D", Variable::__Resolved::ReadWriteTexture1D }
    , { "ReadWriteTexture2D", Variable::__Resolved::ReadWriteTexture2D }
    , { "ReadWriteTexture2DMS", Variable::__Resolved::ReadWriteTexture2DMS }
    , { "ReadWriteTextureCube", Variable::__Resolved::ReadWriteTextureCube }
    , { "ReadWriteTexture3D", Variable::__Resolved::ReadWriteTexture3D }
    , { "ReadWriteTexture1DArray", Variable::__Resolved::ReadWriteTexture1DArray }
    , { "ReadWriteTexture2DArray", Variable::__Resolved::ReadWriteTexture2DArray }
    , { "ReadWriteTexture2DMSArray", Variable::__Resolved::ReadWriteTexture2DMSArray }
    , { "ReadWriteTextureCubeArray", Variable::__Resolved::ReadWriteTextureCubeArray }
    , { "readWriteTexture1D", Variable::__Resolved::ReadWriteTexture1D }
    , { "readWriteTexture2D", Variable::__Resolved::ReadWriteTexture2D }
    , { "readWriteTexture2DMS", Variable::__Resolved::ReadWriteTexture2DMS }
    , { "readWriteTextureCube", Variable::__Resolved::ReadWriteTextureCube }
    , { "readWriteTexture3D", Variable::__Resolved::ReadWriteTexture3D }
    , { "readWriteTexture1DArray", Variable::__Resolved::ReadWriteTexture1DArray }
    , { "readWriteTexture2DArray", Variable::__Resolved::ReadWriteTexture2DArray }
    , { "readWriteTexture2DMSArray", Variable::__Resolved::ReadWriteTexture2DMSArray }
    , { "readWriteTextureCubeArray", Variable::__Resolved::ReadWriteTextureCubeArray }
    , { "image1D", Variable::__Resolved::ReadWriteTexture1D }
    , { "image2D", Variable::__Resolved::ReadWriteTexture2D }
    , { "image2DMS", Variable::__Resolved::ReadWriteTexture2DMS }
    , { "imageCube", Variable::__Resolved::ReadWriteTextureCube }
    , { "image3D", Variable::__Resolved::ReadWriteTexture3D }
    , { "image1DArray", Variable::__Resolved::ReadWriteTexture1DArray }
    , { "image2DArray", Variable::__Resolved::ReadWriteTexture2DArray }
    , { "image2DMSArray", Variable::__Resolved::ReadWriteTexture2DMSArray }
    , { "imageCubeArray", Variable::__Resolved::ReadWriteTextureCubeArray }
};

const std::map<std::string, Variable::__Resolved::Type> textureTypeLookup =
{
    { "Texture1D", Variable::__Resolved::Texture1D }
    , { "Texture2D", Variable::__Resolved::Texture2D }
    , { "Texture2DMS", Variable::__Resolved::Texture2DMS }
    , { "TextureCube", Variable::__Resolved::TextureCube }
    , { "Texture3D", Variable::__Resolved::Texture3D }
    , { "Texture1DArray", Variable::__Resolved::Texture1DArray }
    , { "Texture2DArray", Variable::__Resolved::Texture2DArray }
    , { "Texture2DMSArray", Variable::__Resolved::Texture2DMSArray }
    , { "TextureCubeArray", Variable::__Resolved::TextureCubeArray }
    , { "texture1D", Variable::__Resolved::Texture1D }
    , { "texture2D", Variable::__Resolved::Texture2D }
    , { "texture2DMS", Variable::__Resolved::Texture2DMS }
    , { "textureCube", Variable::__Resolved::TextureCube }
    , { "texture3D", Variable::__Resolved::Texture3D }
    , { "texture1DArray", Variable::__Resolved::Texture1DArray }
    , { "texture2DArray", Variable::__Resolved::Texture2DArray }
    , { "texture2DMSArray", Variable::__Resolved::Texture2DMSArray }
    , { "textureCubeArray", Variable::__Resolved::TextureCubeArray }
};

const std::map<std::string, Variable::__Resolved::Type> samplerTypeLookup =
{
    { "Sampler1D", Variable::__Resolved::Sampler1D }
    , { "Sampler2D", Variable::__Resolved::Sampler2D }
    , { "Sampler2DMS", Variable::__Resolved::Sampler2DMS }
    , { "SamplerCube", Variable::__Resolved::SamplerCube }
    , { "Sampler3D", Variable::__Resolved::Sampler3D }
    , { "Sampler1DArray", Variable::__Resolved::Sampler1DArray }
    , { "Sampler2DArray", Variable::__Resolved::Sampler2DArray }
    , { "Sampler2DMSArray", Variable::__Resolved::Sampler2DMSArray }
    , { "SamplerCubeArray", Variable::__Resolved::SamplerCubeArray }
    , { "sampler1D", Variable::__Resolved::Sampler1D }
    , { "sampler2D", Variable::__Resolved::Sampler2D }
    , { "sampler2DMS", Variable::__Resolved::Sampler2DMS }
    , { "samplerCube", Variable::__Resolved::SamplerCube }
    , { "sampler3D", Variable::__Resolved::Sampler3D }
    , { "sampler1DArray", Variable::__Resolved::Sampler1DArray }
    , { "sampler2DArray", Variable::__Resolved::Sampler2DArray }
    , { "sampler2DMSArray", Variable::__Resolved::Sampler2DMSArray }
    , { "samplerCubeArray", Variable::__Resolved::SamplerCubeArray }
};

const std::map<std::string, Variable::__Resolved::Type> inputAttachmentTypeLookup =
{
    { "InputAttachment", Variable::__Resolved::InputAttachment }
    , { "InputAttachmentMS", Variable::__Resolved::InputAttachmentMS }
    , { "inputAttachment", Variable::__Resolved::InputAttachment }
    , { "inputAttachmentMS", Variable::__Resolved::InputAttachmentMS }
};

const std::map<std::string, Variable::__Resolved::Type> scalarTypeLookup =
{
    { "Float", Variable::__Resolved::Float }
    , { "Float2", Variable::__Resolved::Float2 }
    , { "Float3", Variable::__Resolved::Float3 }
    , { "Float4", Variable::__Resolved::Float4 }
    , { "float", Variable::__Resolved::Float }
    , { "float2", Variable::__Resolved::Float2 }
    , { "float3", Variable::__Resolved::Float3 }
    , { "float4", Variable::__Resolved::Float4 }
    , { "vec2", Variable::__Resolved::Float2 }
    , { "vec3", Variable::__Resolved::Float3 }
    , { "vec4", Variable::__Resolved::Float4 }
    , { "Int", Variable::__Resolved::Int }
    , { "Int2", Variable::__Resolved::Int2 }
    , { "Int3", Variable::__Resolved::Int3 }
    , { "Int4", Variable::__Resolved::Int4 }
    , { "int", Variable::__Resolved::Int }
    , { "int2", Variable::__Resolved::Int2 }
    , { "int3", Variable::__Resolved::Int3 }
    , { "int4", Variable::__Resolved::Int4 }
    , { "ivec2", Variable::__Resolved::Int2 }
    , { "ivec3", Variable::__Resolved::Int3 }
    , { "ivec4", Variable::__Resolved::Int4 }
    , { "UInt", Variable::__Resolved::UInt }
    , { "UInt2", Variable::__Resolved::UInt2 }
    , { "UInt3", Variable::__Resolved::UInt3 }
    , { "UInt4", Variable::__Resolved::UInt4 }
    , { "uint", Variable::__Resolved::UInt }
    , { "uint2", Variable::__Resolved::UInt2 }
    , { "uint3", Variable::__Resolved::UInt3 }
    , { "uint4", Variable::__Resolved::UInt4 }
    , { "uvec2", Variable::__Resolved::UInt2 }
    , { "uvec3", Variable::__Resolved::UInt3 }
    , { "uvec4", Variable::__Resolved::UInt4 }
    , { "Bool", Variable::__Resolved::Bool }
    , { "Bool2", Variable::__Resolved::Bool2 }
    , { "Bool3", Variable::__Resolved::Bool3 }
    , { "Bool4", Variable::__Resolved::Bool4 }
    , { "bool", Variable::__Resolved::Bool }
    , { "bool2", Variable::__Resolved::Bool2 }
    , { "bool3", Variable::__Resolved::Bool3 }
    , { "bool4", Variable::__Resolved::Bool4 }
    , { "bvec2", Variable::__Resolved::Bool2 }
    , { "bvec3", Variable::__Resolved::Bool3 }
    , { "bvec4", Variable::__Resolved::Bool4 }
    , { "Mat2x2", Variable::__Resolved::Mat2x2 }
    , { "Mat2x3", Variable::__Resolved::Mat2x3 }
    , { "Mat2x4", Variable::__Resolved::Mat2x4 }
    , { "Mat3x2", Variable::__Resolved::Mat3x2 }
    , { "Mat3x3", Variable::__Resolved::Mat3x3 }
    , { "Mat3x4", Variable::__Resolved::Mat3x4 }
    , { "Mat4x2", Variable::__Resolved::Mat4x2 }
    , { "Mat4x3", Variable::__Resolved::Mat4x3 }
    , { "Mat4x4", Variable::__Resolved::Mat4x4 }
    , { "mat2x2", Variable::__Resolved::Mat2x2 }
    , { "mat2x3", Variable::__Resolved::Mat2x3 }
    , { "mat2x4", Variable::__Resolved::Mat2x4 }
    , { "mat3x2", Variable::__Resolved::Mat3x2 }
    , { "mat3x3", Variable::__Resolved::Mat3x3 }
    , { "mat3x4", Variable::__Resolved::Mat3x4 }
    , { "mat4x2", Variable::__Resolved::Mat4x2 }
    , { "mat4x3", Variable::__Resolved::Mat4x3 }
    , { "mat4x4", Variable::__Resolved::Mat4x4 }
    , { "mat22", Variable::__Resolved::Mat2x2 }
    , { "mat23", Variable::__Resolved::Mat2x3 }
    , { "mat24", Variable::__Resolved::Mat2x4 }
    , { "mat32", Variable::__Resolved::Mat3x2 }
    , { "mat33", Variable::__Resolved::Mat3x3 }
    , { "mat34", Variable::__Resolved::Mat3x4 }
    , { "mat42", Variable::__Resolved::Mat4x2 }
    , { "mat43", Variable::__Resolved::Mat4x3 }
    , { "mat44", Variable::__Resolved::Mat4x4 }
};
const std::map<std::string, Variable::__Resolved::Type> samplerStateTypeLookup =
{
    { "SamplerState", Variable::__Resolved::SamplerState }
    , { "sampler_state", Variable::__Resolved::SamplerState }
};

const std::map<std::string, Variable::__Resolved::Type> constantBufferTypeLookup =
{
    { "ConstantBuffer", Variable::__Resolved::ConstantBuffer }
    , { "constant_buffer", Variable::__Resolved::ConstantBuffer }
    , { "constants", Variable::__Resolved::ConstantBuffer }
    , { "constant", Variable::__Resolved::ConstantBuffer }
};

const std::map<std::string, Variable::__Resolved::Type> storageBufferTypeLookup =
{
    { "StorageBuffer", Variable::__Resolved::StorageBuffer }
    , { "storage_buffer", Variable::__Resolved::StorageBuffer }
    , { "buffer", Variable::__Resolved::StorageBuffer }
};

const std::map<std::string, Variable::__Resolved::Type> specialTypeLookup =
{
    { "Handle", Variable::__Resolved::Handle }
    , { "handle", Variable::__Resolved::Handle }
    , { "void", Variable::__Resolved::Void }
};

//------------------------------------------------------------------------------
/**
*/
const Variable::__Resolved::Type 
Variable::__Resolved::StringToType(const std::string& str)
{
    auto it = stringToTypeLookup.find(str);
    if (it != stringToTypeLookup.end())
        return it->second;
    else
        return InvalidType;
}

//------------------------------------------------------------------------------
/**
*/
const uint32_t 
Variable::__Resolved::TypeToComponentCount(const Type& type)
{
    return uint32_t();
}

//------------------------------------------------------------------------------
/**
*/
const Variable::__Resolved::Type
Variable::__Resolved::TypeToSingleComponent(const Type& type)
{
    return Type();
}

const std::map<std::string, Variable::__Resolved::AccessFlagBits> accessFlagsLookup =
{
    { "read", Variable::__Resolved::Read }
    , { "write", Variable::__Resolved::Write }
    , { "readwrite", Variable::__Resolved::ReadWrite }
    , { "read_write", Variable::__Resolved::ReadWrite }
    , { "atomic", Variable::__Resolved::Atomic }
    , { "volatile", Variable::__Resolved::Volatile }
};

//------------------------------------------------------------------------------
/**
*/
const Variable::__Resolved::AccessFlagBits
Variable::__Resolved::StringToAccessFlags(const std::string& str)
{
    auto it = accessFlagsLookup.find(str);
    if (it != accessFlagsLookup.end())
        return it->second;
    else
        return InvalidAccessFlags;
}

const std::map<std::string, Variable::__Resolved::ParameterFlagBits> parameterFlagsLookup =
{
    { "in", Variable::__Resolved::In }
    , { "out", Variable::__Resolved::Out }
    , { "inout", Variable::__Resolved::In | Variable::__Resolved::Out }
};

//------------------------------------------------------------------------------
/**
*/
const Variable::__Resolved::ParameterFlagBits
Variable::__Resolved::StringToParameterFlags(const std::string& str)
{
    auto it = parameterFlagsLookup.find(str);
    if (it != parameterFlagsLookup.end())
        return it->second;
    else
        return InvalidParameterFlags;
}

} // namespace AnyFX
