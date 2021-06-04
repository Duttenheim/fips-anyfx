#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::UnaryExpression
    
    A unary expression is a one-sided expression.

    Either

    < op expression >
    
    Or

    < expression op >
    
    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
namespace AnyFX
{
struct UnaryExpression : public Expression
{
public:
    /// constructor
    UnaryExpression(uint32_t op, uint32_t postOp, Expression* expr);
    /// destructor
    virtual ~UnaryExpression();

    /// eval type
    bool EvalType(Compiler* compiler, Type::FullType& out) const override;
    /// eval symbol
    bool EvalSymbol(Compiler* compiler, std::string& out) const override;
    /// evaluates expression as an integer
    bool EvalInt(Compiler* compiler, int& out) const override;
    /// evaluates expression as an integer
    bool EvalUInt(Compiler* compiler, unsigned& out) const override;
    /// evaulates expression as a float
    bool EvalFloat(Compiler* compiler, float& out) const override;
    /// evaluates expression as a boolean
    bool EvalBool(Compiler* compiler, bool& out) const override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    uint32_t op;
    uint32_t postOp;
    Expression* expr;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------