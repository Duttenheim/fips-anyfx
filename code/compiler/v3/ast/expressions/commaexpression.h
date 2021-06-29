#pragma once
//------------------------------------------------------------------------------
/**
    Comma expression

    < expression , expression >

    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include <vector>

namespace AnyFX
{

struct CommaExpression : public Expression
{
    /// constructor
    CommaExpression(Expression* left, Expression* right);
    /// destructor
    virtual ~CommaExpression();

    /// eval type
    bool EvalType(Compiler* compiler, Type::FullType& out) const override;
    /// eval symbol
    bool EvalSymbol(Compiler* compiler, std::string& out) const override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    Expression* left;
    Expression* right;
};

} // namespace AnyFX
