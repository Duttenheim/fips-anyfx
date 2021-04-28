//------------------------------------------------------------------------------
//  @file type.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "type.h"
namespace AnyFX
{

#define __BEGIN_TYPES__ std::map<std::string, Symbol*> types; Type* newType = nullptr;
#define __MAKE_TYPE(typecode) newType = new Type(); newType->name = #typecode; newType->code = typecode;
#define __ADD_LOOKUP(name) types[#name] = newType;
#define __END_TYPES__ return types;

//------------------------------------------------------------------------------
/**
*/
Type::Type()
{

}

//------------------------------------------------------------------------------
/**
*/
Type::~Type()
{
    for (Function* fun : this->methods)
        delete fun;
    for (Variable* var : this->members)
        delete var;
}

//------------------------------------------------------------------------------
/**
*/
std::map<std::string, Symbol*>
Type::SetupDefaultTypes()
{
    __BEGIN_TYPES__

    __MAKE_TYPE(ReadWriteTexture1D);
    __ADD_LOOKUP(ReadWriteTexture1D);
    __ADD_LOOKUP(readWriteTexture1D);
    __ADD_LOOKUP(image1D);

    __MAKE_TYPE(ReadWriteTexture2D);
    __ADD_LOOKUP(ReadWriteTexture2D);
    __ADD_LOOKUP(readWriteTexture2D);
    __ADD_LOOKUP(image2D);

    __MAKE_TYPE(ReadWriteTexture2DMS);
    __ADD_LOOKUP(ReadWriteTexture2DMS);
    __ADD_LOOKUP(readWriteTexture2DMS);
    __ADD_LOOKUP(image2DMS);

    __MAKE_TYPE(ReadWriteTexture3D);
    __ADD_LOOKUP(ReadWriteTexture3D);
    __ADD_LOOKUP(readWriteTexture3D);
    __ADD_LOOKUP(image3D);

    __MAKE_TYPE(ReadWriteTextureCube);
    __ADD_LOOKUP(ReadWriteTextureCube);
    __ADD_LOOKUP(readWriteTextureCube);
    __ADD_LOOKUP(imageCube);

    __MAKE_TYPE(ReadWriteTexture1DArray);
    __ADD_LOOKUP(ReadWriteTexture1DArray);
    __ADD_LOOKUP(readWriteTexture1DArray);
    __ADD_LOOKUP(image1DArray);

    __MAKE_TYPE(ReadWriteTexture2DArray);
    __ADD_LOOKUP(ReadWriteTexture2DArray);
    __ADD_LOOKUP(readWriteTexture2DArray);
    __ADD_LOOKUP(image2DArray);

    __MAKE_TYPE(ReadWriteTexture2DMSArray);
    __ADD_LOOKUP(ReadWriteTexture2DMSArray);
    __ADD_LOOKUP(readWriteTexture2DMSArray);
    __ADD_LOOKUP(image2DMSArray);

    __MAKE_TYPE(ReadWriteTextureCubeArray);
    __ADD_LOOKUP(ReadWriteTextureCubeArray);
    __ADD_LOOKUP(readWriteTextureCubeArray);
    __ADD_LOOKUP(imageCubeArray);

    __MAKE_TYPE(Texture1D);
    __ADD_LOOKUP(Texture1D);
    __ADD_LOOKUP(texture1D);

    __MAKE_TYPE(Texture2D);
    __ADD_LOOKUP(Texture2D);
    __ADD_LOOKUP(texture2D);

    __MAKE_TYPE(Texture2DMS);
    __ADD_LOOKUP(Texture2DMS);
    __ADD_LOOKUP(texture2DMS);

    __MAKE_TYPE(Texture3D);
    __ADD_LOOKUP(Texture3D);
    __ADD_LOOKUP(texture3D);

    __MAKE_TYPE(TextureCube);
    __ADD_LOOKUP(TextureCube);
    __ADD_LOOKUP(textureCube);

    __MAKE_TYPE(Texture1DArray);
    __ADD_LOOKUP(Texture1DArray);
    __ADD_LOOKUP(texture1DArray);

    __MAKE_TYPE(Texture2DArray);
    __ADD_LOOKUP(Texture2DArray);
    __ADD_LOOKUP(texture2DArray);

    __MAKE_TYPE(Texture2DMSArray);
    __ADD_LOOKUP(Texture2DMSArray);
    __ADD_LOOKUP(texture2DMSArray);

    __MAKE_TYPE(TextureCubeArray);
    __ADD_LOOKUP(TextureCubeArray);
    __ADD_LOOKUP(textureCubeArray);

    __MAKE_TYPE(SampledTexture1D);
    __ADD_LOOKUP(SampledTexture1D);
    __ADD_LOOKUP(SampledTexture1D);

    __MAKE_TYPE(SampledTexture2D);
    __ADD_LOOKUP(SampledTexture2D);
    __ADD_LOOKUP(SampledTexture2D);

    __MAKE_TYPE(SampledTexture2DMS);
    __ADD_LOOKUP(SampledTexture2DMS);
    __ADD_LOOKUP(SampledTexture2DMS);

    __MAKE_TYPE(SampledTexture3D);
    __ADD_LOOKUP(SampledTexture3D);
    __ADD_LOOKUP(SampledTexture3D);

    __MAKE_TYPE(SampledTextureCube);
    __ADD_LOOKUP(SampledTextureCube);
    __ADD_LOOKUP(SampledTextureCube);

    __MAKE_TYPE(SampledTexture1DArray);
    __ADD_LOOKUP(SampledTexture1DArray);
    __ADD_LOOKUP(SampledTexture1DArray);

    __MAKE_TYPE(SampledTexture2DArray);
    __ADD_LOOKUP(SampledTexture2DArray);
    __ADD_LOOKUP(SampledTexture2DArray);

    __MAKE_TYPE(SampledTexture2DMSArray);
    __ADD_LOOKUP(SampledTexture2DMSArray);
    __ADD_LOOKUP(SampledTexture2DMSArray);

    __MAKE_TYPE(SampledTextureCubeArray);
    __ADD_LOOKUP(SampledTextureCubeArray);
    __ADD_LOOKUP(SampledTextureCubeArray);

    __MAKE_TYPE(InputAttachment);
    __ADD_LOOKUP(InputAttachment);
    __ADD_LOOKUP(inputAttachment);

    __MAKE_TYPE(InputAttachmentMS);
    __ADD_LOOKUP(InputAttachmentMS);
    __ADD_LOOKUP(inputAttachmentMS);

    __MAKE_TYPE(Float);
    __ADD_LOOKUP(float);

    __MAKE_TYPE(Float2);
    __ADD_LOOKUP(float2);
    __ADD_LOOKUP(vec2);

    __MAKE_TYPE(Float3);
    __ADD_LOOKUP(float3);
    __ADD_LOOKUP(vec3);

    __MAKE_TYPE(Float4);
    __ADD_LOOKUP(float4);
    __ADD_LOOKUP(vec4);

    __MAKE_TYPE(Int);
    __ADD_LOOKUP(int);

    __MAKE_TYPE(Int2);
    __ADD_LOOKUP(int2);
    __ADD_LOOKUP(ivec2);

    __MAKE_TYPE(Int3);
    __ADD_LOOKUP(int3);
    __ADD_LOOKUP(ivec3);

    __MAKE_TYPE(Int4);
    __ADD_LOOKUP(int4);
    __ADD_LOOKUP(ivec4);

    __MAKE_TYPE(UInt);
    __ADD_LOOKUP(uint);

    __MAKE_TYPE(UInt2);
    __ADD_LOOKUP(uint2);
    __ADD_LOOKUP(uvec2);

    __MAKE_TYPE(UInt3);
    __ADD_LOOKUP(unt3);
    __ADD_LOOKUP(uvec3);

    __MAKE_TYPE(UInt4);
    __ADD_LOOKUP(unt4);
    __ADD_LOOKUP(uvec4);

    __MAKE_TYPE(Bool);
    __ADD_LOOKUP(bool);

    __MAKE_TYPE(Bool2);
    __ADD_LOOKUP(bool2);
    __ADD_LOOKUP(bvec2);

    __MAKE_TYPE(Bool3);
    __ADD_LOOKUP(bool3);
    __ADD_LOOKUP(bvec3);

    __MAKE_TYPE(Bool4);
    __ADD_LOOKUP(bool4);
    __ADD_LOOKUP(bvec4);

    __MAKE_TYPE(Mat2x2);
    __ADD_LOOKUP(Matrix2x2);
    __ADD_LOOKUP(mat2x2);
    __ADD_LOOKUP(mat2);

    __MAKE_TYPE(Mat2x3);
    __ADD_LOOKUP(Matrix2x3);
    __ADD_LOOKUP(mat2x3);

    __MAKE_TYPE(Mat2x4);
    __ADD_LOOKUP(Matrix2x4);
    __ADD_LOOKUP(mat2x4);

    __MAKE_TYPE(Mat3x2);
    __ADD_LOOKUP(Matrix3x2);
    __ADD_LOOKUP(mat3x2);

    __MAKE_TYPE(Mat3x3);
    __ADD_LOOKUP(Matrix3x3);
    __ADD_LOOKUP(mat3x3);
    __ADD_LOOKUP(mat3);

    __MAKE_TYPE(Mat3x4);
    __ADD_LOOKUP(Matrix3x4);
    __ADD_LOOKUP(mat3x4);

    __MAKE_TYPE(Mat4x2);
    __ADD_LOOKUP(Matrix4x2);
    __ADD_LOOKUP(mat4x2);
    
    __MAKE_TYPE(Mat4x3);
    __ADD_LOOKUP(Matrix4x3);
    __ADD_LOOKUP(mat4x3);

    __MAKE_TYPE(Mat4x4);
    __ADD_LOOKUP(Matrix4x4);
    __ADD_LOOKUP(mat4x4);
    __ADD_LOOKUP(mat4);

    __MAKE_TYPE(Sampler);
    __ADD_LOOKUP(sampler);

    __MAKE_TYPE(Void);
    __ADD_LOOKUP(void);

    __END_TYPES__
}

std::map<Type::Code, uint32_t> codeToComponentCount =
{
    { Type::Float, 1 }
    , { Type::Float2, 2 }
    , { Type::Float3, 3 }
    , { Type::Float4, 4 }
    , { Type::Int, 1 }
    , { Type::Int2, 2 }
    , { Type::Int3, 3 }
    , { Type::Int4, 4 }
    , { Type::UInt, 1 }
    , { Type::UInt2, 2 }
    , { Type::UInt3, 3 }
    , { Type::UInt4, 4 }
    , { Type::Bool, 1 }
    , { Type::Bool2, 2 }
    , { Type::Bool3, 3 }
    , { Type::Bool4, 4 }
    , { Type::Mat2x2, 4 }
    , { Type::Mat2x3, 6 }
    , { Type::Mat2x4, 8 }
    , { Type::Mat3x2, 6 }
    , { Type::Mat3x3, 9 }
    , { Type::Mat3x4, 12 }
    , { Type::Mat4x2, 8 }
    , { Type::Mat4x3, 12 }
    , { Type::Mat4x4, 16 }
};

//------------------------------------------------------------------------------
/**
*/
const uint32_t
Type::ComponentCount()
{
    auto it = codeToComponentCount.find(this->code);
    if (it == codeToComponentCount.end())
        return 0;
    else
        return it->second;
}

std::map<Type::Code, Type::Code> codeToSingleComponent =
{
    { Type::Float, Type::Float }
    , { Type::Float2, Type::Float }
    , { Type::Float3, Type::Float }
    , { Type::Float4, Type::Float }
    , { Type::Int, Type::Int }
    , { Type::Int2, Type::Int }
    , { Type::Int3, Type::Int }
    , { Type::Int4, Type::Int }
    , { Type::UInt, Type::UInt }
    , { Type::UInt2, Type::UInt }
    , { Type::UInt3, Type::UInt }
    , { Type::UInt4, Type::UInt }
    , { Type::Bool, Type::Bool }
    , { Type::Bool2, Type::Bool }
    , { Type::Bool3, Type::Bool }
    , { Type::Bool4, Type::Bool }
    , { Type::Mat2x2, Type::Float }
    , { Type::Mat2x3, Type::Float }
    , { Type::Mat2x4, Type::Float }
    , { Type::Mat3x2, Type::Float }
    , { Type::Mat3x3, Type::Float }
    , { Type::Mat3x4, Type::Float }
    , { Type::Mat4x2, Type::Float }
    , { Type::Mat4x3, Type::Float }
    , { Type::Mat4x4, Type::Float }
};

//------------------------------------------------------------------------------
/**
*/
const Type::Code
Type::SingleComponent()
{
    auto it = codeToSingleComponent.find(this->code);
    if (it == codeToSingleComponent.end())
        return Type::Void;
    else
        return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const bool 
Type::IsScalar() const
{
    return this->code >= Float && this->code <= Mat4x4;
}

//------------------------------------------------------------------------------
/**
*/
const bool 
Type::IsReadWriteTexture() const
{
    return this->code >= ReadWriteTexture1D && this->code <= ReadWriteTextureCubeArray;
}

//------------------------------------------------------------------------------
/**
*/
const bool 
Type::IsTexture() const
{
    return this->code >= Texture1D && this->code <= TextureCubeArray;
}

//------------------------------------------------------------------------------
/**
*/
const bool 
Type::IsSampledTexture() const
{
    return this->code >= SampledTexture1D && this->code <= SampledTextureCubeArray;
}

//------------------------------------------------------------------------------
/**
*/
const bool 
Type::IsInputAttachment() const
{
    return this->code >= InputAttachment && this->code <= InputAttachmentMS;
}

//------------------------------------------------------------------------------
/**
*/
const bool Type::IsSampler() const
{
    return this->code == Sampler;
}

//------------------------------------------------------------------------------
/**
*/
const Type::Category 
Type::ToCategory() const
{
    if (this->IsReadWriteTexture())
        return Category::ReadWriteTextureCategory;
    else if (this->IsTexture())
        return Category::TextureCategory;
    else if (this->IsSampledTexture())
        return Category::SampledTextureCategory;
    else if (this->IsInputAttachment())
        return Category::InputAttachmentCategory;
    else if (this->IsScalar())
        return Category::ScalarCategory;
    else if (this->IsSampler())
        return Category::SamplerCategory;

    return Category::InvalidCategory;
}

} // namespace AnyFX
