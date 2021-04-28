#pragma once
//------------------------------------------------------------------------------
/**
    Ternary condition

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include "ast/expressions/expression.h"
namespace AnyFX
{

struct TernaryExpression : public Expression
{
    /// constructor
    TernaryExpression(Expression* ifStatement, Expression* elseStatement);

    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    Expression* ifStatement;
    Expression* elseStatement;
};

} // namespace AnyFX
