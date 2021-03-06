#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::IntExpression
    
    An int expression is a simple expression which holds an integer.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
namespace AnyFX
{
class IntExpression : public Expression
{
public:
	/// constructor
	IntExpression(int value);
	/// destructor
	virtual ~IntExpression();

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
	int value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------