#pragma once
//------------------------------------------------------------------------------
/**
    Function call expression

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include <vector>

namespace AnyFX
{

struct AccessExpression : public Expression
{
    /// constructor
    AccessExpression(Expression* value);

    Symbol* EvalSymbol(Compiler* compiler) const;
/// evaluates expression as an integer
    int EvalInt(Compiler* compiler) const;
    /// evaluates expression as an integer
    unsigned EvalUInt(Compiler* compiler) const;
    /// evaulates expression as a float
    float EvalFloat(Compiler* compiler) const;
    /// evaluates expression as a boolean
    bool EvalBool(Compiler* compiler) const;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const;

    Expression* value;
};

} // namespace AnyFX
