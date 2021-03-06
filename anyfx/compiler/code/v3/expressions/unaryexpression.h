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
class UnaryExpression : public Expression
{
public:
	/// constructor
	UnaryExpression(char op, Expression* expr);
	/// destructor
	virtual ~UnaryExpression();

    /// evaulate type of expression
    Symbol* EvalSymbol(Compiler* compiler) override;
    /// evaluates expression as an integer
    int EvalInt(Compiler* compiler) override;
    /// evaluates expression as an integer
    unsigned EvalUInt(Compiler* compiler) override;
    /// evaulates expression as a float
    float EvalFloat(Compiler* compiler) override;
    /// evaluates expression as a bool
    bool EvalBool(Compiler* compiler) override;

private:
	char op;
	Expression* expr;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------