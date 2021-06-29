#pragma once
//------------------------------------------------------------------------------
/**
    Member access expression

    < . expression >

    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include <vector>

namespace AnyFX
{

struct AccessExpression : public Expression
{
    /// constructor
    AccessExpression(Expression* left, Expression* right, bool deref);
    /// destructor
    virtual ~AccessExpression();

    /// eval type
    bool EvalType(Compiler* compiler, Type::FullType& out) const override;
    /// eval symbol
    bool EvalSymbol(Compiler* compiler, std::string& out) const override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    bool deref;
    Expression* left;
    Expression* right;
};

} // namespace AnyFX
