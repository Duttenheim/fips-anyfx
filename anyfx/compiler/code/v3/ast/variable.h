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
namespace AnyFX
{

struct Variable : public Attributable
{

    std::string type;
    struct Attributes
    {
        bool isConst : 1;
        bool isArray : 1;
    } qualifiers;

    std::vector<std::string> values;
    Annotations annotations;

    Expression* arraySizeExpression;
    bool isArray;

};

} // namespace AnyFX
