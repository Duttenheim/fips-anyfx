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
	virtual DataType EvalType(TypeChecker& typechecker);

	/// evaluates expression as an integer
	virtual int EvalInt(TypeChecker& typechecker);
	/// evaluates expression as an integer
	virtual unsigned EvalUInt(TypeChecker& typechecker);
	/// evaulates expression as a float
	virtual float EvalFloat(TypeChecker& typechecker);
	/// evaluates expression as a boolean
	virtual bool EvalBool(TypeChecker& typechecker);
private:
	std::string symbol;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------