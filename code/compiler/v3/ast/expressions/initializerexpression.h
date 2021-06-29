#pragma once
//------------------------------------------------------------------------------
/**
    Initializer expression

    < { expression0 .. expressionN } >

    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include <vector>

namespace AnyFX
{

struct InitializerExpression : public Expression
{
    /// constructor
    InitializerExpression(const std::vector<Expression*>& values);
    /// Destructor
    virtual ~InitializerExpression();

    /// eval type
    bool EvalType(Compiler* compiler, Type::FullType& out) const override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    Expression* sizeExpression;
    std::vector<Expression*> values;
};

} // namespace AnyFX
