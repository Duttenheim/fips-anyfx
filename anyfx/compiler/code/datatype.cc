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
    DataType ret;
    if (str == "float") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::Float); }
    else if (str == "int") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::Integer); }
    else if (str == "bool") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::Bool); }
    else if (str == "uint") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::UInteger); }
    else if (str == "short") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::Short); }
    else if (str == "string") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::String); }
    else if (str == "void") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::Void); }
    else if (str == "textureHandle") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::TextureHandle); }
    else if (str == "imageHandle") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::ImageHandle); }
    else if (str == "samplerHandle") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::SamplerHandle); }
    else if (str == "inputAttachment") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::InputAttachment); }
    else if (str == "inputAttachmentMS") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::InputAttachmentMS); }
    else if (str == "inputAttachmentInteger") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::InputAttachmentInteger); }
    else if (str == "inputAttachmentIntegerMS") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::InputAttachmentIntegerMS); }
    else if (str == "inputAttachmentUInteger") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::InputAttachmentUInteger); }
    else if (str == "inputAttachmentUIntegerMS") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::InputAttachmentUIntegerMS); }
    else if (str == "accelerationStructure") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::AccelerationStructure); }
    else if (str == "sampler") { ret.SetStyle(DataType::Generic); ret.SetType(DataType::SamplerState); }

    // HLSL types
    else if (str == "float2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Float2); }
    else if (str == "float3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Float3); }
    else if (str == "float4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Float4); }
    else if (str == "int2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Integer2); }
    else if (str == "int3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Integer3); }
    else if (str == "int4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Integer4); }
    else if (str == "uint2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::UInteger2); }
    else if (str == "uint3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::UInteger3); }
    else if (str == "uint4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::UInteger4); }
    else if (str == "short2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Short2); }
    else if (str == "short3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Short3); }
    else if (str == "short4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Short4); }
    else if (str == "bool2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Bool2); }
    else if (str == "bool3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Bool3); }
    else if (str == "bool4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Bool4); }
    else if (str == "float2x2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix2x2); }
    else if (str == "float2x3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix2x3); }
    else if (str == "float2x4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix2x4); }
    else if (str == "float3x2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix3x2); }
    else if (str == "float3x3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix3x3); }
    else if (str == "float3x4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix3x4); }
    else if (str == "float4x2") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix4x2); }
    else if (str == "float4x3") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix4x3); }
    else if (str == "float4x4") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Matrix4x4); }
    else if (str == "Texture1D") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler1D); }
    else if (str == "Texture1DArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler1DArray); }
    else if (str == "Texture2D") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler2D); }
    else if (str == "Texture2DArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler2DArray); }
    else if (str == "Texture2DMS") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler2DMS); }
    else if (str == "Texture2DMSArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler2DMSArray); }
    else if (str == "Texture3D") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Sampler3D); }
    else if (str == "TextureCube") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::SamplerCube); }
    else if (str == "TextureCubeArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::SamplerCubeArray); }
    else if (str == "RWTexture1D") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image1D); }
    else if (str == "RWTexture1DArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image1DArray); }
    else if (str == "RWTexture2D") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image2D); }
    else if (str == "RWTexture2DArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image2DArray); }
    else if (str == "RWTexture2DMS") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image2DMS); }
    else if (str == "RWTexture2DMSArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image2DMSArray); }
    else if (str == "RWTexture3D") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::Image3D); }
    else if (str == "RWTextureCube") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::ImageCube); }
    else if (str == "RWTextureCubeArray") { ret.SetStyle(DataType::HLSL); ret.SetType(DataType::ImageCubeArray); }

    // GLSL types
    else if (str == "vec2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Float2); }
    else if (str == "vec3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Float3); }
    else if (str == "vec4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Float4); }
    else if (str == "ivec2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Integer2); }
    else if (str == "ivec3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Integer3); }
    else if (str == "ivec4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Integer4); }
    else if (str == "uvec2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::UInteger2); }
    else if (str == "uvec3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::UInteger3); }
    else if (str == "uvec4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::UInteger4); }
    else if (str == "svec2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Short2); }
    else if (str == "svec3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Short3); }
    else if (str == "svec4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Short4); }
    else if (str == "bvec2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Bool2); }
    else if (str == "bvec3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Bool3); }
    else if (str == "bvec4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Bool4); }
    else if (str == "mat2x2" || str == "mat2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix2x2); }
    else if (str == "mat2x3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix2x3); }
    else if (str == "mat2x4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix2x4); }
    else if (str == "mat3x2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix3x2); }
    else if (str == "mat3x3" || str == "mat3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix3x3); }
    else if (str == "mat3x4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix3x4); }
    else if (str == "mat4x2") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix4x2); }
    else if (str == "mat4x3") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix4x3); }
    else if (str == "mat4x4" || str == "mat4") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Matrix4x4); }
    else if (str == "sampler1D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler1D); }
    else if (str == "sampler1DArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler1DArray); }
    else if (str == "sampler2D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler2D); }
    else if (str == "sampler2DArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler2DArray); }
    else if (str == "sampler2DMS") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler2DMS); }
    else if (str == "sampler2DMSArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler2DMSArray); }
    else if (str == "sampler3D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Sampler3D); }
    else if (str == "samplerCube") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::SamplerCube); }
    else if (str == "samplerCubeArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::SamplerCubeArray); }
    else if (str == "image1D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image1D); }
    else if (str == "image1DArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image1DArray); }
    else if (str == "image2D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image2D); }
    else if (str == "image2DArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image2DArray); }
    else if (str == "image2DMS") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image2DMS); }
    else if (str == "image2DMSArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image2DMSArray); }
    else if (str == "image3D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Image3D); }
    else if (str == "imageCube") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::ImageCube); }
    else if (str == "imageCubeArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::ImageCubeArray); }
    else if (str == "texture1D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture1D); }
    else if (str == "texture1DArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture1DArray); }
    else if (str == "texture2D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture2D); }
    else if (str == "texture2DArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture2DArray); }
    else if (str == "texture2DMS") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture2DMS); }
    else if (str == "texture2DMSArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture2DMSArray); }
    else if (str == "texture3D") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::Texture3D); }
    else if (str == "textureCube") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::TextureCube); }
    else if (str == "textureCubeArray") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::TextureCubeArray); }
    else if (str == "atomic_uint") { ret.SetStyle(DataType::GLSL); ret.SetType(DataType::AtomicCounter); }

    // user defined type detected
    else { ret.SetStyle(DataType::Generic); ret.SetType(DataType::UserType); ret.SetName(str); }
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
		return "short";
	case Short2:
		return "svec2";
	case Short3:
		return "svec3";
	case Short4:
		return "svec4";
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
		return "short";
	case Short2:
		return "short2";
	case Short3:
		return "short3";
	case Short4:
		return "short4";
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
		return "undefined";
	case ImageCubeArray:
		return "undefined";
	case Image2DMS:
		return "undefined";
	case Image2DMSArray:
		return "undefined";
	case InputAttachment:
	case InputAttachmentMS:
	case InputAttachmentInteger:
	case InputAttachmentIntegerMS:
	case InputAttachmentUInteger:
	case InputAttachmentUIntegerMS:
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
		return "float";
	case Float2:
		return "float";
	case Float3:
		return "float";
	case Float4:
		return "float";
	case Double:
		return "double";
	case Double2:
		return "double";
	case Double3:
		return "double";
	case Double4:
		return "double";
	case Integer:
		return "int";
	case Integer2:
		return "int";
	case Integer3:
		return "int";
	case Integer4:
		return "int";
	case UInteger:
		return "unsigned int";
	case UInteger2:
		return "unsigned int";
	case UInteger3:
		return "unsigned int";
	case UInteger4:
		return "unsigned int";
	case Short:
		return "short";
	case Short2:
		return "short";
	case Short3:
		return "short";
	case Short4:
		return "short";
	case Bool:
		return "bool";
	case Bool2:
		return "bool";
	case Bool3:
		return "bool";
	case Bool4:
		return "bool";
	case Matrix2x2:
		return "float";
	case Matrix2x3:
		return "float";
	case Matrix2x4:
		return "float";
	case Matrix3x2:
		return "float";
	case Matrix3x3:
		return "float";
	case Matrix3x4:
		return "float";
	case Matrix4x2:
		return "float";
	case Matrix4x3:
		return "float";
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
        return sizeof(short);
    case DataType::Short2:
        return 2 * sizeof(short);
    case DataType::Short3:
        return 3 * sizeof(short);
    case DataType::Short4:
        return 4 * sizeof(short);
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

	case DataType::Double:
	case DataType::Double2:
	case DataType::Double3:
	case DataType::Double4:
		ret.type = DataType::Double;

	case DataType::TextureHandle:
	case DataType::ImageHandle:
	case DataType::SamplerHandle:
	case DataType::UInteger:
	case DataType::UInteger2:
	case DataType::UInteger3:
	case DataType::UInteger4:
		ret.type = DataType::UInteger;

	case DataType::Integer:
	case DataType::Integer2:
	case DataType::Integer3:
	case DataType::Integer4:
		ret.type = DataType::Integer;

	case DataType::Short:
	case DataType::Short2:
	case DataType::Short3:
	case DataType::Short4:
		ret.type = DataType::Short;

	case DataType::Bool:
	case DataType::Bool2:
	case DataType::Bool3:
	case DataType::Bool4:
		ret.type = DataType::Bool;

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

	case DataType::UserType:
		ret.type = DataType::UserType;

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
	case TextureHandle:
	case ImageHandle:
	case SamplerHandle:
		return { 1, 1 };
	case Float2:
	case Double2:
	case Integer2:
	case UInteger2:
	case Short2:
	case Bool2:
		return  { 2, 1 };
	case Double3:
	case Float3:
	case Integer3:
	case UInteger3:
	case Short3:
	case Bool3:
		return  { 3, 1 };
	case Double4:
	case Float4:
	case Integer4:
	case UInteger4:
	case Short4:
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
