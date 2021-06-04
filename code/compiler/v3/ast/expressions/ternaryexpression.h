#pragma once
//------------------------------------------------------------------------------
/**
    Ternary expression

    < ? expression : expression >

    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include "ast/expressions/expression.h"
namespace AnyFX
{

struct TernaryExpression : public Expression
{
    /// constructor
    TernaryExpression(Expression* lhs, Expression* ifExpression, Expression* elseExpression);

    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    Expression* lhs;
    Expression* ifExpression;
    Expression* elseExpression;
};

} // namespace AnyFX
