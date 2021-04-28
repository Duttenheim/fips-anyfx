#pragma once
//------------------------------------------------------------------------------
/**
    The type symbol is the most primitive representation of a type

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "symbol.h"
#include <vector>
#include <map>
namespace AnyFX
{

struct Variable;
struct Function;
struct Type : public Symbol
{
    /// constructor
    Type();
    /// destructor
    virtual ~Type();

    enum Code
    {
        /// read-write textures
        ReadWriteTexture1D, ReadWriteTexture2D, ReadWriteTexture2DMS, ReadWriteTextureCube, ReadWriteTexture3D,
        ReadWriteTexture1DArray, ReadWriteTexture2DArray, ReadWriteTexture2DMSArray, ReadWriteTextureCubeArray,

        /// sample-only textures
        Texture1D, Texture2D, Texture2DMS, TextureCube, Texture3D,
        Texture1DArray, Texture2DArray, Texture2DMSArray, TextureCubeArray,

        /// sampler-combined textures
        SampledTexture1D, SampledTexture2D, SampledTexture2DMS, SampledTextureCube, SampledTexture3D,
        SampledTexture1DArray, SampledTexture2DArray, SampledTexture2DMSArray, SampledTextureCubeArray,

        /// input attachments
        InputAttachment, InputAttachmentMS,

        /// scalar types
        Float, Float2, Float3, Float4,
        Int, Int2, Int3, Int4,
        UInt, UInt2, UInt3, UInt4,
        Bool, Bool2, Bool3, Bool4,
        Mat2x2, Mat2x3, Mat2x4,
        Mat3x2, Mat3x3, Mat3x4,
        Mat4x2, Mat4x3, Mat4x4,

        /// user types (structs)
        UserType,

        /// special types
        Void, Sampler,

        /// fail when this type is detected as soon as possible
        InvalidType
    };

    enum Category
    {
        InvalidCategory,
        ReadWriteTextureCategory,
        TextureCategory,
        SampledTextureCategory,
        InputAttachmentCategory,
        ScalarCategory,
        UserTypeCategory,
        ConstantStructureCategory,
        MutableStructureCategory,
        VoidCategory,
        SamplerCategory
    };

    /// convert from Type to number of number of components (xyz, [2][3] etc)
    const uint32_t ComponentCount();
    /// convert from Type to single-component type (Int4 -> Int)
    const Code SingleComponent();

    /// check if type is read-write texture
    const bool IsReadWriteTexture() const;
    /// check if type is texture
    const bool IsTexture() const;
    /// check if type is texture-sampler pair
    const bool IsSampledTexture() const;
    /// check if type is input attachment
    const bool IsInputAttachment() const;
    /// check if type is scalar
    const bool IsScalar() const;
    /// check if type is sampler
    const bool IsSampler() const;
    /// return type as simplest resource type (rwtexture, texture, sampled texture, input attachment, sampler)
    const Category ToCategory() const;

    Code code;

    std::vector<Variable*> members;
    std::vector<Function*> methods;


    // setup all default shader types, like float, int, vec4, etc
    static std::map<std::string, Symbol*> SetupDefaultTypes();

};

} // namespace AnyFX
