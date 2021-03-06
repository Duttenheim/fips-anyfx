#pragma once
//------------------------------------------------------------------------------
/**
    AST for base class for render/blend state

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "symbol.h"
namespace AnyFX
{

struct State : public Symbol
{
    struct Entry
    {
        std::string name;
        Expression* value;
        Expression* arraySizeExpression;
    };
    std::vector<Entry> entries;
    Annotations annotations;

};

} // namespace AnyFX
