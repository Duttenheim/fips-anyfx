#pragma once
//------------------------------------------------------------------------------
/**
    AST for a struct
            
    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attribute.h"
#include "variable.h"
#include "types/type.h"
namespace AnyFX
{

struct Structure : public Type
{
    /// constructor
    Structure();

    std::string instanceName;
    Expression* arraySizeExpression;
    bool isArray;

    _IMPLEMENT_ANNOTATIONS()
    _IMPLEMENT_ATTRIBUTES()

    struct __Resolved : public Type::__Resolved
    {
        union UsageFlags
        {
            struct
            {
                bool isStorageBuffer : 1;
                bool isConstantBuffer : 1;
                bool isPush : 1;
            } flags;
            int bits;
        };
        UsageFlags usageFlags;

        Variable::__Resolved::AccessBits accessBits;

        static const uint8_t NOT_BOUND = 0xF;
        uint32_t group;
        uint32_t binding;

        // for alignment
        size_t byteSize;
        size_t baseAlignment;
    };
};

} // namespace AnyFX
