#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::BoolExpression
    
    A boolean expression holds a single boolean argument.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
namespace AnyFX
{
struct BoolExpression : public Expression
{
public:
	/// constructor
	BoolExpression(bool value);
	/// destructor
	virtual ~BoolExpression();

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

	bool value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------