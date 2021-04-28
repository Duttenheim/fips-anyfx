#pragma once
//------------------------------------------------------------------------------
/**
    AST variable (type name)

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attribute.h"
#include "annotation.h"
#include "type.h"
#include <vector>
#include <map>
namespace AnyFX
{

struct Variable : public Symbol
{
    /// constructor
    Variable();
    /// destructor
    ~Variable();

    std::string type;
    std::vector<std::string> values;
    _IMPLEMENT_ANNOTATIONS()
    _IMPLEMENT_ATTRIBUTES()

    std::vector<std::string> initializerTypes;
    std::vector<std::vector<Expression*>> initializers;

    Expression* arraySizeExpression;
    bool isArray;


    enum ImageFormat
    {
        InvalidImageFormat,

        // byte
        RGBA16, RGB10_A2, RGBA8, RG16, RG8,
        R16, R8, RGBA16_SNORM, RGBA8_SNORM, RG16_SNORM, RG8_SNORM,
        R16_SNORM, R8_SNORM,

        // float
        RGBA32F, RGBA16F, RG32F, RG16F, R11G11B10F,
        R32F, R16F, 

        // integer
        RGA32I, RGBA16I, RGBA8I, RG32I, RG16I, RG8I,
        R32I, R16I, R8I,

        // unsigned integer
        RGA32U, RGBA16U, RGB10_A2U, RGBA8U, RG32U, RG16U, RG8U,
        R32U, R16U, R8U
    };

    
    static std::map<std::string, ImageFormat> stringToFormats;
    static void SetupImageFormats();

    static ImageFormat StringToImageFormat(const std::string& format);
    static bool IsImageFormatInteger(ImageFormat format);
    static bool IsImageFormatUnsigned(ImageFormat format);

    struct __Resolved : Symbol::__Resolved
    {
        union AccessBits
        {
            struct
            {
                uint32_t readAccess : 1;
                uint32_t writeAccess : 1;
                uint32_t atomicAccess : 1;
                uint32_t volatileAccess : 1;
            } flags;
            uint32_t bits;
        };
        AccessBits accessBits;

        union ParameterBits
        {
            struct
            {
                uint32_t isIn : 1;
                uint32_t isOut : 1;
                uint32_t isPatch : 1;
                uint32_t isNoPerspective : 1;
                uint32_t isNoInterpolate : 1;
            } flags;
            uint32_t bits;
        };
        ParameterBits parameterBits;

        Type* type;

        union UsageBits
        {
            struct
            {
                uint32_t isConst : 1;                   // true if variable is const
                uint32_t isParameter : 1;               // true if variable is passed to a function
                uint32_t isStructMember : 1;            // true if variable is the member of a struct
                uint32_t isConstantBufferMember : 1;    // true if variable belongs to a struct const
                uint32_t isStorageBufferMember : 1;     // true if variable belongs to a struct mutable
                uint32_t isGroupShared : 1;             // true if variable is work group shared memory
            } flags;
            uint32_t bits;
        };
        UsageBits usageBits;
        
        static const uint8_t NOT_BOUND = 0xF;
        uint8_t group;          // resource group
        uint8_t binding;        // resource binding

        uint8_t inBinding;      // parameter input binding
        uint8_t outBinding;     // parameter output binding

        static const uint32_t NOT_ARRAY = 0x1;
        uint32_t arraySize;

        uint32_t byteSize;          // size in bytes
        uint32_t structureOffset;   // offset within structure
        uint32_t elementPadding;    // padding between elements
        uint32_t startPadding;      // padding before variable

        ImageFormat imageFormat;    // for read write images, this is the format

        struct Initializer
        {
            enum Type
            {
                FloatType,
                IntType,
                UIntType,
                BoolType
            };
            Type type;
            union Data
            {
                float f;
                int i;
                unsigned int u;
                bool b;
            } data;
        };

        // per each array item, per each component of type
        std::vector<std::vector<Initializer>> initializers;
        
    };
};


} // namespace AnyFX
