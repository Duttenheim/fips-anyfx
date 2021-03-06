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
class BoolExpression : public Expression
{
public:
	/// constructor
	BoolExpression(bool value);
	/// destructor
	virtual ~BoolExpression();

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
	bool value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------