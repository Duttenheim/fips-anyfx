#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::SymbolExpression
    
    Evaluates, if possible, a symbol as a single value, currently this is
	only possible for constants.
    
    (C) 2020 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"

namespace AnyFX
{
class SymbolExpression : public Expression
{
public:
	/// constructor
	SymbolExpression(const std::string symbol);
	/// destructor
	virtual ~SymbolExpression();

	/// evaulate type of expression
	DataType EvalType(TypeChecker& typechecker) override;

	/// evaluates expression as an integer
	int EvalInt(TypeChecker& typechecker) override;
	/// evaluates expression as an integer
	unsigned EvalUInt(TypeChecker& typechecker) override;
	/// evaulates expression as a float
	float EvalFloat(TypeChecker& typechecker) override;
	/// evaluates expression as a boolean
	bool EvalBool(TypeChecker& typechecker) override;
	/// evaluates expression as a string
	std::string EvalString(TypeChecker& typechecker) override;
private:
	std::string symbol;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------