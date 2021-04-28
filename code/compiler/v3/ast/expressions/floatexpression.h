#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::FloatExpression
    
    A simple expression which holds a floating point value.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
namespace AnyFX
{
struct FloatExpression : public Expression
{
public:
	/// constructor
	FloatExpression(float value);
	/// destructor
	virtual ~FloatExpression();

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

	float value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------