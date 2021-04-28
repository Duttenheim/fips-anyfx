#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::UnaryExpression
    
    A unary expression is a one-sided expression.
    
    (C) 2013 Gustav Sterbrant
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

    /// evaulate type of expression
    Symbol* EvalSymbol(Compiler* compiler) const override;
    /// evaluates expression as an integer
    int EvalInt(Compiler* compiler) const override;
    /// evaluates expression as an integer
    unsigned EvalUInt(Compiler* compiler) const override;
    /// evaulates expression as a float
    float EvalFloat(Compiler* compiler) const override;
    /// evaluates expression as a bool
    bool EvalBool(Compiler* compiler) const override;
        /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

	uint32_t op;
    uint32_t postOp;
	Expression* expr;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------