//------------------------------------------------------------------------------
//  datatype.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "datatype.h"
#include "util.h"
#include "typechecker.h"
#include "structure.h"


namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
DataType::DataType() :
    style(Generic),
    type(Undefined)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
DataType::DataType(Style style, Type type)
    : style(style)
    , type(type)
{
}

//------------------------------------------------------------------------------
/**
*/
DataType::~DataType()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
DataType 
DataType::FromString(const std::string& str)
{
    static const std::map<const std::string, DataType> Lookup =
    {
        { "float",                          DataType(DataType::Generic, DataType::Float) }
        , { "int",                          DataType(DataType::Generic, DataType::Integer) }
        , { "uint",                         DataType(DataType::Generic, DataType::UInteger) }
        , { "int16_t",                      DataType(DataType::Generic, DataType::Short) }
        , { "uint16_t",                     DataType(DataType::Generic, DataType::UShort) }
        , { "int8_t",                       DataType(DataType::GLSL,    DataType::Byte) }
        , { "uint8_t",                      DataType(DataType::GLSL,    DataType::UByte) }
        , { "bool",                         DataType(DataType::Generic, DataType::Bool) }
        , { "string",                       DataType(DataType::Generic, DataType::String) }

        , { "textureHandle",                DataType(DataType::Generic, DataType::TextureHandle) }
        , { "imageHandle",                  DataType(DataType::Generic, DataType::ImageHandle) }
        , { "samplerHandle",                DataType(DataType::Generic, DataType::SamplerHandle) }

        , { "inputAttachment",              DataType(DataType::Generic, DataType::InputAttachment) }
        , { "inputAttachmentMS",            DataType(DataType::Generic, DataType::InputAttachmentMS) }
        , { "inputAttachmentInteger",       DataType(DataType::Generic, DataType::InputAttachmentInteger) }
        , { "inputAttachmentIntegerMS",     DataType(DataType::Generic, DataType::InputAttachmentIntegerMS) }
        , { "inputAttachmentUInteger",      DataType(DataType::Generic, DataType::InputAttachmentUInteger) }
        , { "inputAttachmentUIntegerMS",    DataType(DataType::Generic, DataType::InputAttachmentUIntegerMS) }

        , { "accelerationStructure",        DataType(DataType::Generic, DataType::AccelerationStructure) }
        , { "sampler",                      DataType(DataType::Generic, DataType::SamplerState) }

        , { "float2",                       DataType(DataType::HLSL, DataType::Float2) }
        , { "float3",                       DataType(DataType::HLSL, DataType::Float3) }
        , { "float4",                       DataType(DataType::HLSL, DataType::Float4) }
        , { "int2",                         DataType(DataType::HLSL, DataType::Integer2) }
        , { "int3",                         DataType(DataType::HLSL, DataType::Integer3) }
        , { "int4",                         DataType(DataType::HLSL, DataType::Integer4) }
        , { "uint2",                        DataType(DataType::HLSL, DataType::UInteger2) }
        , { "uint3",                        DataType(DataType::HLSL, DataType::UInteger3) }
        , { "uint4",                        DataType(DataType::HLSL, DataType::UInteger4) }
        , { "short2",                       DataType(DataType::HLSL, DataType::Short2) }
        , { "short3",                       DataType(DataType::HLSL, DataType::Short3) }
        , { "short4",                       DataType(DataType::HLSL, DataType::Short4) }
        , { "ushort2",                      DataType(DataType::HLSL, DataType::UShort2) }
        , { "ushort3",                      DataType(DataType::HLSL, DataType::UShort3) }
        , { "ushort4",                      DataType(DataType::HLSL, DataType::UShort4) }
        , { "byte2",                        DataType(DataType::HLSL, DataType::Byte2) }
        , { "byte3",                        DataType(DataType::HLSL, DataType::Byte3) }
        , { "byte4",                        DataType(DataType::HLSL, DataType::Byte4) }
        , { "ubyte2",                       DataType(DataType::HLSL, DataType::UByte2) }
        , { "ubyte3",                       DataType(DataType::HLSL, DataType::UByte3) }
        , { "ubyte4",                       DataType(DataType::HLSL, DataType::UByte4) }
        , { "bool2",                        DataType(DataType::HLSL, DataType::Bool2) }
        , { "bool3",                        DataType(DataType::HLSL, DataType::Bool3) }
        , { "bool4",                        DataType(DataType::HLSL, DataType::Bool4) }

        , { "float2x2",                     DataType(DataType::HLSL, DataType::Matrix2x2) }
        , { "float2x3",                     DataType(DataType::HLSL, DataType::Matrix2x3) }
        , { "float2x4",                     DataType(DataType::HLSL, DataType::Matrix2x4) }
        , { "float3x2",                     DataType(DataType::HLSL, DataType::Matrix3x2) }
        , { "float3x3",                     DataType(DataType::HLSL, DataType::Matrix3x3) }
        , { "float3x4",                     DataType(DataType::HLSL, DataType::Matrix3x4) }
        , { "float4x2",                     DataType(DataType::HLSL, DataType::Matrix4x2) }
        , { "float4x3",                     DataType(DataType::HLSL, DataType::Matrix4x3) }
        , { "float4x4",                     DataType(DataType::HLSL, DataType::Matrix4x4) }

        , { "Texture1D",                    DataType(DataType::HLSL, DataType::Texture1D) }
        , { "Texture1DArray",               DataType(DataType::HLSL, DataType::Texture1DArray) }
        , { "Texture2D",                    DataType(DataType::HLSL, DataType::Texture2D) }
        , { "Texture2DArray",               DataType(DataType::HLSL, DataType::Texture2DArray) }
        , { "Texture2DMS",                  DataType(DataType::HLSL, DataType::Texture2DMS) }
        , { "Texture2DMSArray",             DataType(DataType::HLSL, DataType::Texture2DMSArray) }
        , { "Texture3D",                    DataType(DataType::HLSL, DataType::Texture3D) }
        , { "TextureCube",                  DataType(DataType::HLSL, DataType::TextureCube) }
        , { "TextureCubeArray",             DataType(DataType::HLSL, DataType::TextureCubeArray) }

        , { "RWTexture1D",                  DataType(DataType::HLSL, DataType::Image1D) }
        , { "RWTexture1DArray",             DataType(DataType::HLSL, DataType::Image1DArray) }
        , { "RWTexture2D",                  DataType(DataType::HLSL, DataType::Image2D) }
        , { "RWTexture2DArray",             DataType(DataType::HLSL, DataType::Image2DArray) }
        , { "RWTexture2DMS",                DataType(DataType::HLSL, DataType::Image2DMS) }
        , { "RWTexture2DMSArray",           DataType(DataType::HLSL, DataType::Image2DMSArray) }
        , { "RWTexture3D",                  DataType(DataType::HLSL, DataType::Image3D) }
        , { "RWTextureCube",                DataType(DataType::HLSL, DataType::ImageCube) }
        , { "RWTextureCubeArray",           DataType(DataType::HLSL, DataType::ImageCubeArray) }

        , { "vec2",                         DataType(DataType::GLSL, DataType::Float2) }
        , { "vec3",                         DataType(DataType::GLSL, DataType::Float3) }
        , { "vec4",                         DataType(DataType::GLSL, DataType::Float4) }
        , { "ivec2",                        DataType(DataType::GLSL, DataType::Integer2) }
        , { "ivec3",                        DataType(DataType::GLSL, DataType::Integer3) }
        , { "ivec4",                        DataType(DataType::GLSL, DataType::Integer4) }
        , { "uvec2",                        DataType(DataType::GLSL, DataType::UInteger2) }
        , { "uvec3",                        DataType(DataType::GLSL, DataType::UInteger3) }
        , { "uvec4",                        DataType(DataType::GLSL, DataType::UInteger4) }
        , { "i16vec2",                      DataType(DataType::GLSL, DataType::Short2) }
        , { "i16vec3",                      DataType(DataType::GLSL, DataType::Short3) }
        , { "i16vec4",                      DataType(DataType::GLSL, DataType::Short4) }
        , { "u16vec2",                      DataType(DataType::GLSL, DataType::UShort2) }
        , { "u16vec3",                      DataType(DataType::GLSL, DataType::UShort3) }
        , { "u16vec4",                      DataType(DataType::GLSL, DataType::UShort4) }
        , { "i8vec2",                       DataType(DataType::GLSL, DataType::Byte2) }
        , { "i8vec3",                       DataType(DataType::GLSL, DataType::Byte3) }
        , { "i8vec4",                       DataType(DataType::GLSL, DataType::Byte4) }
        , { "u8vec2",                       DataType(DataType::GLSL, DataType::UByte2) }
        , { "u8vec3",                       DataType(DataType::GLSL, DataType::UByte3) }
        , { "u8vec4",                       DataType(DataType::GLSL, DataType::UByte4) }
        , { "bvec2",                        DataType(DataType::GLSL, DataType::Bool2) }
        , { "bvec3",                        DataType(DataType::GLSL, DataType::Bool3) }
        , { "bvec4",                        DataType(DataType::GLSL, DataType::Bool4) }

        , { "mat2",                         DataType(DataType::GLSL, DataType::Matrix2x2) }
        , { "mat2x2",                       DataType(DataType::GLSL, DataType::Matrix2x2) }
        , { "mat2x3",                       DataType(DataType::GLSL, DataType::Matrix2x3) }
        , { "mat2x4",                       DataType(DataType::GLSL, DataType::Matrix2x4) }
        , { "mat3x2",                       DataType(DataType::GLSL, DataType::Matrix3x2) }
        , { "mat3",                         DataType(DataType::GLSL, DataType::Matrix3x3) }
        , { "mat3x3",                       DataType(DataType::GLSL, DataType::Matrix3x3) }
        , { "mat3x4",                       DataType(DataType::GLSL, DataType::Matrix3x4) }
        , { "mat4x2",                       DataType(DataType::GLSL, DataType::Matrix4x2) }
        , { "mat4x3",                       DataType(DataType::GLSL, DataType::Matrix4x3) }
        , { "mat4",                         DataType(DataType::GLSL, DataType::Matrix4x4) }
        , { "mat4x4",                       DataType(DataType::GLSL, DataType::Matrix4x4) }

        , { "sampler1D",                    DataType(DataType::GLSL, DataType::Sampler1D) }
        , { "sampler1DArray",               DataType(DataType::GLSL, DataType::Sampler1DArray) }
        , { "sampler2D",                    DataType(DataType::GLSL, DataType::Sampler2D) }
        , { "sampler2DArray",               DataType(DataType::GLSL, DataType::Sampler2DArray) }
        , { "sampler2DMS",                  DataType(DataType::GLSL, DataType::Sampler2DMS) }
        , { "sampler2DMSArray",             DataType(DataType::GLSL, DataType::Sampler2DMSArray) }
        , { "sampler3D",                    DataType(DataType::GLSL, DataType::Sampler3D) }
        , { "samplerCube",                  DataType(DataType::GLSL, DataType::SamplerCube) }
        , { "samplerCubeArray",             DataType(DataType::GLSL, DataType::SamplerCubeArray) }

        , { "image1D",                      DataType(DataType::GLSL, DataType::Image1D) }
        , { "image1DArray",                 DataType(DataType::GLSL, DataType::Image1DArray) }
        , { "image2D",                      DataType(DataType::GLSL, DataType::Image2D) }
        , { "image2DArray",                 DataType(DataType::GLSL, DataType::Image2DArray) }
        , { "image2DMS",                    DataType(DataType::GLSL, DataType::Image2DMS) }
        , { "image2DMSArray",               DataType(DataType::GLSL, DataType::Image2DMSArray) }
        , { "image3D",                      DataType(DataType::GLSL, DataType::Image3D) }
        , { "imageCube",                    DataType(DataType::GLSL, DataType::ImageCube) }
        , { "imageCubeArray",               DataType(DataType::GLSL, DataType::ImageCubeArray) }

        , { "texture1D",                    DataType(DataType::GLSL, DataType::Texture1D) }
        , { "texture1DArray",               DataType(DataType::GLSL, DataType::Texture1DArray) }
        , { "texture2D",                    DataType(DataType::GLSL, DataType::Texture2D) }
        , { "texture2DArray",               DataType(DataType::GLSL, DataType::Texture2DArray) }
        , { "texture2DMS",                  DataType(DataType::GLSL, DataType::Texture2DMS) }
        , { "texture2DMSArray",             DataType(DataType::GLSL, DataType::Texture2DMSArray) }
        , { "texture3D",                    DataType(DataType::GLSL, DataType::Texture3D) }
        , { "textureCube",                  DataType(DataType::GLSL, DataType::TextureCube) }
        , { "textureCubeArray",             DataType(DataType::GLSL, DataType::TextureCubeArray) }

        , { "atomic_uint",                  DataType(DataType::GLSL, DataType::AtomicCounter) }

    };

    DataType ret;
    auto it = Lookup.find(str);
    if (it == Lookup.end())
    {
        ret.SetStyle(DataType::Generic); 
        ret.SetType(DataType::UserType); 
        ret.SetName(str);
    }
    else
    {
        ret = (*it).second;
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
std::string
DataType::ToGLSLType(const DataType& type)
{
    switch (type.type)
    {
    case Float:
        return "float";
    case Float2:
        return "vec2";
    case Float3:
        return "vec3";
    case Float4:
        return "vec4";
    case Double:
        return "double";
    case Double2:
        return "dvec2";
    case Double3:
        return "dvec3";
    case Double4:
        return "dvec4";
    case Integer:
        return "int";
    case Integer2:
        return "ivec2";
    case Integer3:
        return "ivec3";
    case Integer4:
        return "ivec4";
    case UInteger:
        return "uint";
    case UInteger2:
        return "uvec2";
    case UInteger3:
        return "uvec3";
    case UInteger4:
        return "uvec4";
    case Short:
        return "int16_t";
    case Short2:
        return "i16vec2";
    case Short3:
        return "i16vec3";
    case Short4:
        return "i16vec4";
    case UShort:
        return "uint16_t";
    case UShort2:
        return "u16vec2";
    case UShort3:
        return "u16vec3";
    case UShort4:
        return "u16vec4";
    case Byte:
        return "int8_t";
    case Byte2:
        return "i8vec2";
    case Byte3:
        return "i8vec3";
    case Byte4:
        return "i8vec4";
    case UByte:
        return "uint8_t";
    case UByte2:
        return "u8vec2";
    case UByte3:
        return "u8vec3";
    case UByte4:
        return "u8vec4";
    case Bool:
        return "bool";
    case Bool2:
        return "bvec2";
    case Bool3:
        return "bvec3";
    case Bool4:
        return "bvec4";
    case Matrix2x2:
        return "mat2x2";
    case Matrix2x3:
        return "mat2x3";
    case Matrix2x4:
        return "mat2x4";
    case Matrix3x2:
        return "mat3x2";
    case Matrix3x3:
        return "mat3x3";
    case Matrix3x4:
        return "mat3x4";
    case Matrix4x2:
        return "mat4x2";
    case Matrix4x3:
        return "mat4x3";
    case Matrix4x4:
        return "mat4x4";
    case SamplerState:
        return "sampler";
    case Sampler1D:
        return "sampler1D";
    case Sampler1DArray:
        return "sampler1DArray";
    case Sampler2D:
        return "sampler2D";
    case Sampler2DArray:
        return "sampler2DArray";
    case Sampler2DMS:
        return "sampler2DMS";
    case Sampler2DMSArray:
        return "sampler2DMSArray";
    case Sampler3D:
        return "sampler3D";
    case SamplerCube:
        return "samplerCube";
    case SamplerCubeArray:
        return "samplerCubeArray";
    case Image1D:
        return "image1D";
    case Image1DArray:
        return "image1DArray";
    case Image2D:
        return "image2D";
    case Image2DArray:
        return "image2DArray";
    case Image2DMS:
        return "image2DMS";
    case Image2DMSArray:
        return "image2DMSArray";
    case Image3D:
        return "image3D";
    case ImageCube:
        return "imageCube";
    case ImageCubeArray:
        return "imageCubeArray";
    case InputAttachment:
        return "subpassInput";
    case InputAttachmentMS:
        return "subpassInputMS";
    case InputAttachmentInteger:
        return "isubpassInput";
    case InputAttachmentIntegerMS:
        return "isubpassInputMS";
    case InputAttachmentUInteger:
        return "usubpassInput";
    case InputAttachmentUIntegerMS:
        return "usubpassInputMS";
    case Texture1D:
        return "texture1D";
    case Texture1DArray:
        return "texture1DArray";
    case Texture2D:
        return "texture2D";
    case Texture2DArray:
        return "texture2DArray";
    case Texture2DMS:
        return "texture2DMS";
    case Texture2DMSArray:
        return "texture2DMSArray";
    case Texture3D:
        return "texture3D";
    case TextureCube:
        return "textureCube";
    case TextureCubeArray:
        return "textureCubeArray";
    case TextureHandle:
    case ImageHandle:
    case SamplerHandle:
        return "uint";
    case AccelerationStructure:
        return "accelerationStructureEXT";
    case Void:
        return "void";
    case UserType:
        return type.name;
    case Undefined:
    default:
        return "undefined";
    }
}

//------------------------------------------------------------------------------
/**
*/
std::string
DataType::ToHLSLType(const DataType& type)
{
    switch (type.type)
    {
    case Float:
        return "float";
    case Float2:
        return "float2";
    case Float3:
        return "float3";
    case Float4:
        return "float4";
    case Double:
        return "double";
    case Double2:
        return "double2";
    case Double3:
        return "double3";
    case Double4:
        return "double4";
    case Integer:
        return "int";
    case Integer2:
        return "int2";
    case Integer3:
        return "int3";
    case Integer4:
        return "int4";
    case UInteger:
        return "uint";
    case UInteger2:
        return "uint2";
    case UInteger3:
        return "uint3";
    case UInteger4:
        return "uint4";
    case Short:
        return "int16_t";
    case Short2:
        return "int16_t2";
    case Short3:
        return "int16_t3";
    case Short4:
        return "int16_t4";
    case UShort:
        return "uint16_t";
    case UShort2:
        return "uint16_t2";
    case UShort3:
        return "uint16_t3";
    case UShort4:
        return "uint16_t4";
    case Bool:
        return "bool";
    case Bool2:
        return "bool2";
    case Bool3:
        return "bool3";
    case Bool4:
        return "bool4";
    case Matrix2x2:
        return "float2x2";
    case Matrix2x3:
        return "float2x3";
    case Matrix2x4:
        return "float2x4";
    case Matrix3x2:
        return "float3x2";
    case Matrix3x3:
        return "float3x3";
    case Matrix3x4:
        return "float3x4";
    case Matrix4x2:
        return "float4x2";
    case Matrix4x3:
        return "float4x3";
    case Matrix4x4:
        return "float4x4";
    case SamplerState:
        return "SamplerState";
    case Sampler1D:
        return "Texture1D";
    case Sampler1DArray:
        return "Texture1DArray";
    case Sampler2D:
        return "Texture2D";
    case Sampler2DArray:
        return "Texture2DArray";
    case Sampler2DMS:
        return "Texture2DMS";
    case Sampler2DMSArray:
        return "Texture2DMSArray";
    case Sampler3D:
        return "Texture3D";
    case SamplerCube:
        return "TextureCube";
    case SamplerCubeArray:
        return "TextureCubeArray";
    case Image1D:
        return "RWTexture1D";
    case Image1DArray:
        return "RWTexture1DArray";
    case Image2D:
        return "RWTexture2D";
    case Image2DArray:
        return "RWTexture2DArray";
    case Image3D:
        return "RWTexture3D";
    case TextureHandle:
    case ImageHandle:
    case SamplerHandle:
        return "uint";
    case Void:
        return "void";
    case UserType:
        return type.name;

        // these types are undefined for hlsl
    case ImageCube:
    case ImageCubeArray:
    case Image2DMS:
    case Image2DMSArray:
    case InputAttachment:
    case InputAttachmentMS:
    case InputAttachmentInteger:
    case InputAttachmentIntegerMS:
    case InputAttachmentUInteger:
    case InputAttachmentUIntegerMS:
    case Byte:
    case Byte2:
    case Byte3:
    case Byte4:
    case UByte:
    case UByte2:
    case UByte3:
    case UByte4:
    case Undefined:
    default:
        return "undefined";
    }
}

//------------------------------------------------------------------------------
/**
*/
std::string 
DataType::ToCType(const DataType & type)
{
    switch (type.type)
    {
    case Float:
    case Float2:
    case Float3:
    case Float4:
        return "float";
    case Double:
    case Double2:
    case Double3:
    case Double4:
        return "double";
    case Integer:
    case Integer2:
    case Integer3:
    case Integer4:
        return "int";
    case UInteger:
    case UInteger2:
    case UInteger3:
    case UInteger4:
        return "unsigned int";
    case Short:
    case Short2:
    case Short3:
    case Short4:
    case UShort:
    case UShort2:
    case UShort3:
    case UShort4:
        return "short";
    case Byte:
    case Byte2:
    case Byte3:
    case Byte4:
    case UByte:
    case UByte2:
    case UByte3:
    case UByte4:
        return "char";
    case Bool:
    case Bool2:
    case Bool3:
    case Bool4:
        return "bool";
    case Matrix2x2:
    case Matrix2x3:
    case Matrix2x4:
    case Matrix3x2:
    case Matrix3x3:
    case Matrix3x4:
    case Matrix4x2:
    case Matrix4x3:
    case Matrix4x4:
        return "float";
    case SamplerState:
        return "void*";
    case Sampler1D:
        return "void*";
    case Sampler1DArray:
        return "void*";
    case Sampler2D:
        return "void*";
    case Sampler2DArray:
        return "void*";
    case Sampler2DMS:
        return "void*";
    case Sampler2DMSArray:
        return "void*";
    case Sampler3D:
        return "void*";
    case SamplerCube:
        return "void*";
    case SamplerCubeArray:
        return "void*";
    case Image1D:
        return "void*";
    case Image1DArray:
        return "void*";
    case Image2D:
        return "void*";
    case Image2DArray:
        return "RWTexture2DArray";
    case Image3D:
        return "void*";
    case TextureHandle:
    case ImageHandle:
    case SamplerHandle:
        return "unsigned int";
    case Void:
        return "void*";
    case UserType:
        return type.name;

        // these types are undefined for hlsl
    case ImageCube:
        return "void*";
    case ImageCubeArray:
        return "void*";
    case Image2DMS:
        return "void*";
    case Image2DMSArray:
        return "void*";
    case InputAttachment:
    case InputAttachmentMS:
    case InputAttachmentInteger:
    case InputAttachmentIntegerMS:
    case InputAttachmentUInteger:
    case InputAttachmentUIntegerMS:
    case Undefined:
    default:
        return "void*";
    }
}

//------------------------------------------------------------------------------
/**
*/
std::string
DataType::ToProfileType(const DataType& dtype, const Header::Type& ttype)
{
    switch (ttype)
    {
    case Header::HLSL:
        return ToHLSLType(dtype);
    case Header::SPIRV:
    case Header::GLSL:
        return ToGLSLType(dtype);
    case Header::C:
        return ToCType(dtype);
    default:
        Error("Type cannot be converted");
        return "";
    }
}

//------------------------------------------------------------------------------
/**
*/
std::string
DataType::ToSignature(const DataType& type)
{
    switch (type.type)
    {
    case Float:
        return "f";
    case Float2:
        return "f2";
    case Float3:
        return "f3";
    case Float4:
        return "f4";
    case Double:
        return "d";
    case Double2:
        return "d2";
    case Double3:
        return "d3";
    case Double4:
        return "d4";
    case Integer:
        return "i";
    case Integer2:
        return "i2";
    case Integer3:
        return "i3";
    case Integer4:
        return "i4";
    case UInteger:
        return "ui";
    case UInteger2:
        return "ui2";
    case UInteger3:
        return "ui3";
    case UInteger4:
        return "ui4";
    case Short:
        return "s";
    case Short2:
        return "s2";
    case Short3:
        return "s3";
    case Short4:
        return "s4";
    case UShort:
        return "us";
    case UShort2:
        return "us2";
    case UShort3:
        return "us3";
    case UShort4:
        return "us4";
    case Byte:
        return "b";
    case Byte2:
        return "b2";
    case Byte3:
        return "b3";
    case Byte4:
        return "b4";
    case UByte:
        return "ub";
    case UByte2:
        return "ub2";
    case UByte3:
        return "ub3";
    case UByte4:
        return "ub4";
    case Bool:
        return "b";
    case Bool2:
        return "b2";
    case Bool3:
        return "b3";
    case Bool4:
        return "b4";
    case Matrix2x2:
        return "m22";
    case Matrix2x3:
        return "m23";
    case Matrix2x4:
        return "m24";
    case Matrix3x2:
        return "m32";
    case Matrix3x3:
        return "m33";
    case Matrix3x4:
        return "m34";
    case Matrix4x2:
        return "m42";
    case Matrix4x3:
        return "m43";
    case Matrix4x4:
        return "m44";
    case SamplerState:
        return "sam";
    case Sampler1D:
        return "sam1d";
    case Sampler1DArray:
        return "sam1da";
    case Sampler2D:
        return "sam2d";
    case Sampler2DArray:
        return "sam2da";
    case Sampler2DMS:
        return "sam2dms";
    case Sampler2DMSArray:
        return "sam2dmsa";
    case Sampler3D:
        return "sam3d";
    case SamplerCube:
        return "samc";
    case SamplerCubeArray:
        return "samca";
    case Image1D:
        return "ima1d";
    case Image1DArray:
        return "ima1da";
    case Image2D:
        return "ima2d";
    case Image2DArray:
        return "ima2da";
    case Image3D:
        return "ima3d";
    case ImageCube:
        return "imac";
    case ImageCubeArray:
        return "imaca";
    case Image2DMS:
        return "ima2dms";
    case Image2DMSArray:
        return "ima2dmsa";
    case InputAttachment:
        return "ia";
    case InputAttachmentMS:
        return "iams";
    case InputAttachmentInteger:
        return "iai";
    case InputAttachmentIntegerMS:
        return "iaims";
    case InputAttachmentUInteger:
        return "iau";
    case InputAttachmentUIntegerMS:
        return "iaums";
    case TextureHandle:
        return "th";
    case ImageHandle:
        return "ih";
    case SamplerHandle:
        return "sh";
    case Void:
        return "v";
    case UserType:
        return type.name;
    case Undefined:
    default:
        return "undefined";
    }
}

//------------------------------------------------------------------------------
/**
*/
std::string
DataType::ToString(const DataType& type)
{
    switch (type.type)
    {
    case Float:
        return "float";
    case Float2:
        return "float vector [2]";
    case Float3:
        return "float vector [3]";
    case Float4:
        return "float vector [4]";
    case Double:
        return "double";
    case Double2:
        return "double vector [2]";
    case Double3:
        return "double vector [3]";
    case Double4:
        return "double vector [4]";
    case Integer:
        return "int";
    case Integer2:
        return "int vector [2]";
    case Integer3:
        return "int vector [3]";
    case Integer4:
        return "int vector [4]";
    case UInteger:
        return "unsigned int";
    case UInteger2:
        return "unsigned int vector [2]";
    case UInteger3:
        return "unsigned int vector [3]";
    case UInteger4:
        return "unsigned int vector [4]";
    case Short:
        return "short";
    case Short2:
        return "short vector [2]";
    case Short3:
        return "short vector [3]";
    case Short4:
        return "short vector [4]";
    case UShort:
        return "unsigned short";
    case UShort2:
        return "unsigned short vector [2]";
    case UShort3:
        return "unsigned short vector [3]";
    case UShort4:
        return "unsigned short vector [4]";
    case Byte:
        return "byte";
    case Byte2:
        return "byte vector [2]";
    case Byte3:
        return "byte vector [3]";
    case Byte4:
        return "byte vector [4]";
    case UByte:
        return "unsigned byte";
    case UByte2:
        return "unsigned byte vector [2]";
    case UByte3:
        return "unsigned byte vector [3]";
    case UByte4:
        return "unsigned byte vector [4]";
    case Bool:
        return "bool";
    case Bool2:
        return "bool vector [2]";
    case Bool3:
        return "bool vector [3]";
    case Bool4:
        return "bool vector [4]";
    case Matrix2x2:
        return "matrix [2x2]";
    case Matrix2x3:
        return "matrix [2x3]";
    case Matrix2x4:
        return "matrix [2x4]";
    case Matrix3x2:
        return "matrix [3x2]";
    case Matrix3x3:
        return "matrix [3x3]";
    case Matrix3x4:
        return "matrix [3x4]";
    case Matrix4x2:
        return "matrix [4x2]";
    case Matrix4x3:
        return "matrix [4x3]";
    case Matrix4x4:
        return "matrix [4x4]";
    case SamplerState:
        return "sampler state";
    case Sampler1D:
        return "texture sampler [1D]";
    case Sampler1DArray:
        return "texture sampler [1D-Array]";
    case Sampler2D:
        return "texture sampler [2D]";
    case Sampler2DArray:
        return "texture sampler [2D-Array]";
    case Sampler2DMS:
        return "texture sampler [2D-Multisample]";
    case Sampler2DMSArray:
        return "texture sampler [2D-Multisample-Array]";
    case Sampler3D:
        return "texture sampler [3D]";
    case SamplerCube:
        return "texture sampler [Cube]";
    case SamplerCubeArray:
        return "texture sampler [Cube-Array]";
    case Image1D:
        return "image [1D]";
    case Image1DArray:
        return "image [1D-Array]";
    case Image2D:
        return "image [2D]";
    case Image2DArray:
        return "image [2D-Array]";
    case Image2DMS:
        return "image [2D-Multisample]";
    case Image2DMSArray:
        return "image [2D-Multisample-Array]";
    case Image3D:
        return "image [3D]";
    case ImageCube:
        return "image [Cube]";
    case ImageCubeArray:
        return "image [Cube-Array]";
    case Texture1D:
        return "texture [1D]";
    case Texture1DArray:
        return "texture [1D-Array]";
    case Texture2D:
        return "texture [2D]";
    case Texture2DArray:
        return "texture [2D-Array]";
    case Texture2DMS:
        return "texture [2D-Multisample]";
    case Texture2DMSArray:
        return "texture [2D-Multisample-Array]";
    case Texture3D:
        return "texture [3D]";
    case TextureCube:
        return "texture [Cube]";
    case TextureCubeArray:
        return "texture [Cube-Array]";
    case InputAttachment:
        return "input attachment";
    case InputAttachmentMS:
        return "input attachment [Multisample]";
    case InputAttachmentInteger:
        return "input attachment [Integer]";
    case InputAttachmentIntegerMS:
        return "input attachment [Integer multisample]";
    case InputAttachmentUInteger:
        return "input attachment [Unsigned integer]";
    case InputAttachmentUIntegerMS:
        return "input attachment [Unsigned integer multisample]";
    case TextureHandle:
        return "texture handle [uint]";
    case ImageHandle:
        return "image handle [uint]";
    case SamplerHandle:
        return "sampler handle [uint]";
    case Void:
        return "void";
    case String:
        return "string";
    case UserType:
        return type.name;
    case Undefined:
    default:
        return "undefined";
    }
}

//------------------------------------------------------------------------------
/**
*/
unsigned
DataType::ToByteSize(const DataType& type)
{
    switch (type.GetType())
    {
    case DataType::Float:
        return sizeof(float);
    case DataType::Float2:
        return 2 * sizeof(float);
    case DataType::Float3:
        return 3 * sizeof(float);
    case DataType::Float4:
        return 4 * sizeof(float);
    case DataType::Double:
        return sizeof(double);
    case DataType::Double2:
        return 2 * sizeof(double);
    case DataType::Double3:
        return 3 * sizeof(double);
    case DataType::Double4:
        return 4 * sizeof(double);
    case DataType::UInteger:
    case DataType::Integer:
    case DataType::TextureHandle:
    case DataType::ImageHandle:
    case DataType::SamplerHandle:
        return sizeof(int);
    case DataType::UInteger2:
    case DataType::Integer2:
        return 2 * sizeof(int);
    case DataType::UInteger3:
    case DataType::Integer3:
        return 3 * sizeof(int);
    case DataType::UInteger4:
    case DataType::Integer4:
        return 4 * sizeof(int);
    case DataType::Short:
    case DataType::UShort:
        return sizeof(short);
    case DataType::Short2:
    case DataType::UShort2:
        return 2 * sizeof(short);
    case DataType::Short3:
    case DataType::UShort3:
        return 3 * sizeof(short);
    case DataType::Short4:
    case DataType::UShort4:
        return 4 * sizeof(short);
    case DataType::Byte:
    case DataType::UByte:
        return sizeof(char);
    case DataType::Byte2:
    case DataType::UByte2:
        return 2 * sizeof(char);
    case DataType::Byte3:
    case DataType::UByte3:
        return 3 * sizeof(char);
    case DataType::Byte4:
    case DataType::UByte4:
        return 4 * sizeof(char);
    case DataType::Bool:
        return sizeof(bool);
    case DataType::Bool2:
        return 2 * sizeof(bool);
    case DataType::Bool3:
        return 3 * sizeof(bool);
    case DataType::Bool4:
        return 4 * sizeof(bool);
    case DataType::Matrix2x2:
        return 4 * sizeof(float);
    case DataType::Matrix2x3:
        return 6 * sizeof(float);
    case DataType::Matrix2x4:
        return 8 * sizeof(float);
    case DataType::Matrix3x2:
        return 6 * sizeof(float);
    case DataType::Matrix3x3:
        return 9 * sizeof(float);
    case DataType::Matrix3x4:
        return 12 * sizeof(float);
    case DataType::Matrix4x2:
        return 8 * sizeof(float);
    case DataType::Matrix4x3:
        return 12 * sizeof(float);
    case DataType::Matrix4x4:
        return 16 * sizeof(float);
    case DataType::UserType:
        {
            TypeChecker* typeChecker = TypeChecker::Instance();
            if (typeChecker->HasSymbol(type.GetName()))
            {
                Symbol* sym = typeChecker->GetSymbol(type.GetName());
                if (sym->GetType() == Symbol::StructureType)
                {
                    Structure* struc = (Structure*)sym;
                    if (struc->IsPointer())
                        return 8;
                    else
                        return struc->CalculateSize();
                }
                else if (sym->GetType() == Symbol::VarbufferType)
                {
                    // Reference to a Varbuffer
                    return 8;
                }
                
            }    
        }
    default:		// this is for all special types, such as texture handles etc.
        return sizeof(int);
    }
}

//------------------------------------------------------------------------------
/**
*/
DataType
DataType::ToPrimitiveType(const DataType& type)
{
    DataType ret;
    switch (type.GetType())
    {
    case DataType::Float:
    case DataType::Float2:
    case DataType::Float3:
    case DataType::Float4:
        ret.type = DataType::Float;
        break;

    case DataType::Double:
    case DataType::Double2:
    case DataType::Double3:
    case DataType::Double4:
        ret.type = DataType::Double;
        break;

    case DataType::TextureHandle:
    case DataType::ImageHandle:
    case DataType::SamplerHandle:
    case DataType::UInteger:
    case DataType::UInteger2:
    case DataType::UInteger3:
    case DataType::UInteger4:
        ret.type = DataType::UInteger;
        break;

    case DataType::Integer:
    case DataType::Integer2:
    case DataType::Integer3:
    case DataType::Integer4:
        ret.type = DataType::Integer;
        break;

    case DataType::Short:
    case DataType::Short2:
    case DataType::Short3:
    case DataType::Short4:
    case DataType::UShort:
    case DataType::UShort2:
    case DataType::UShort3:
    case DataType::UShort4:
        ret.type = DataType::Short;
        break;

    case DataType::Byte:
    case DataType::Byte2:
    case DataType::Byte3:
    case DataType::Byte4:
    case DataType::UByte:
    case DataType::UByte2:
    case DataType::UByte3:
    case DataType::UByte4:
        ret.type = DataType::Byte;
        break;

    case DataType::Bool:
    case DataType::Bool2:
    case DataType::Bool3:
    case DataType::Bool4:
        ret.type = DataType::Bool;
        break;

    case DataType::Matrix2x2:
    case DataType::Matrix2x3:
    case DataType::Matrix2x4:
    case DataType::Matrix3x2:
    case DataType::Matrix3x3:
    case DataType::Matrix3x4:
    case DataType::Matrix4x2:
    case DataType::Matrix4x3:
    case DataType::Matrix4x4:
        ret.type = DataType::Float;
        break;

    case DataType::UserType:
        ret.type = DataType::UserType;
        break;

    default:		// this is for all special types, such as texture handles etc.
        ret.type = DataType::Integer;
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
DataType::Dimensions
DataType::ToDimensions(const DataType& type)
{
    switch (type.type)
    {
    case Double:
    case Float:
    case Integer:
    case UInteger:
    case Short:
    case Bool:
    case UShort:
    case Byte:
    case UByte:
    case TextureHandle:
    case ImageHandle:
    case SamplerHandle:
        return { 1, 1 };
    case Float2:
    case Double2:
    case Integer2:
    case UInteger2:
    case Short2:
    case UShort2:
    case Byte2:
    case UByte2:
    case Bool2:
        return  { 2, 1 };
    case Double3:
    case Float3:
    case Integer3:
    case UInteger3:
    case Short3:
    case UShort3:
    case Byte3:
    case UByte3:
    case Bool3:
        return  { 3, 1 };
    case Double4:
    case Float4:
    case Integer4:
    case UInteger4:
    case Short4:
    case UShort4:
    case Byte4:
    case UByte4:
    case Bool4:
        return  { 4, 1 };
    case Matrix2x2:
        return  { 2, 2 };
    case Matrix2x3:
        return { 2, 3 };
    case Matrix2x4:
        return { 2, 4 };
    case Matrix3x2:
        return { 3, 2 };
    case Matrix3x3:
        return { 3, 3 };
    case Matrix3x4:
        return { 3, 4 };
    case Matrix4x2:
        return { 4, 2 };
    case Matrix4x3:
        return { 4, 3 };
    case Matrix4x4:
        return { 4, 4 };
    default:
        return { 0, 0 };
    }
}

} // namespace AnyFX
