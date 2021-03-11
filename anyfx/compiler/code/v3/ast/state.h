#pragma once
//------------------------------------------------------------------------------
/**
    AST for base class for render/blend state

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "symbol.h"
#include "annotations.h"
#include <vector>
namespace AnyFX
{

struct Expression;
struct State : public Symbol
{
    /// destructor
    virtual ~State();

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
