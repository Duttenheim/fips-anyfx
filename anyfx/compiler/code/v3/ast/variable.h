#pragma once
//------------------------------------------------------------------------------
/**
    AST variable (type name)

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "annotations.h"
#include <vector>
#include <map>
namespace AnyFX
{

struct Variable : public Attributable
{
    /// constructor
    Variable();

    std::string type;
    std::vector<std::string> values;
    Annotations annotations;

    std::vector<std::string> initializerTypes;
    std::vector<std::vector<Expression*>> initializers;

    Expression* arraySizeExpression;
    bool isArray;

    struct __Resolved : Symbol::__Resolved
    {
        enum Type
        {
            /// read-write textures
            ReadWriteTexture1D, ReadWriteTexture2D, ReadWriteTexture2DMS, ReadWriteTextureCube, ReadWriteTexture3D,
            ReadWriteTexture1DArray, ReadWriteTexture2DArray, ReadWriteTexture2DMSArray, ReadWriteTextureCubeArray,

            /// sample-only textures
            Texture1D, Texture2D, Texture2DMS, TextureCube, Texture3D,
            Texture1DArray, Texture2DArray, Texture2DMSArray, TextureCubeArray,

            /// sampler-combined textures
            Sampler1D, Sampler2D, Sampler2DMS, SamplerCube, Sampler3D,
            Sampler1DArray, Sampler2DArray, Sampler2DMSArray, SamplerCubeArray,
            
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

            /// compound types
            SamplerState, ConstantBuffer, StorageBuffer,

            /// special types
            Handle, Void,

            /// fail when this type is detected as soon as possible
            InvalidType
        };

        /// convert from string to Type
        static const Type StringToType(const std::string& str);
        /// convert from Type to number of number of components (xyz, [2][3] etc)
        static const uint32_t TypeToComponentCount(const Type& type);
        /// convert from Type to single-component type (Int4 -> Int)
        static const Type TypeToSingleComponent(const Type& type);

        enum AccessFlags
        {
            InvalidAccessFlags  = 0x0,
            Read                = 0x1,  // read only variable
            Write               = 0x2,  // write only variable
            ReadWrite           = 0x4,  // read-write variable
            Atomic              = 0x8,  // writes are performed atomically
            Volatile            = 0x10  // writes can happen outside of synchronization scopes
        };
        typedef unsigned int AccessFlagBits;

        /// convert from string to access flag
        static const AccessFlagBits StringToAccessFlags(const std::string& str);

        enum ParameterFlags
        {
            InvalidParameterFlags = 0x0,
            In                    = 0x1,
            Out                   = 0x2
        };
        typedef unsigned int ParameterFlagBits;

        /// convert from string to parameter flag
        static const ParameterFlagBits StringToParameterFlags(const std::string& str);

        ParameterFlagBits parameterFlags;
        AccessFlagBits accessFlags;
        Type type;

        bool isConst;       // set to true if variable has the 'const' qualifier
        bool isParameter;   // set to true if variable is passed to a function

        uint8_t group;
        uint8_t binding;

        union InitializerUnion
        {
            float f;
            int i;
            unsigned int u;
            bool b;
        };

        // per each array item, per each component of type
        std::vector<std::vector<InitializerUnion>> initializers;
        
    };
};
extern const std::map<std::string, Variable::__Resolved::Type> readWriteTextureTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> textureTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> samplerTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> inputAttachmentTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> scalarTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> samplerStateTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> constantBufferTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> storageBufferTypeLookup;
extern const std::map<std::string, Variable::__Resolved::Type> specialTypeLookup;
extern std::map<std::string, Variable::__Resolved::Type> stringToTypeLookup;

} // namespace AnyFX
