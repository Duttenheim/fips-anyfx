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
    Symbol* EvalSymbol(Compiler* compiler) override;
    /// evaluates expression as an integer
    int EvalInt(Compiler* compiler) override;
    /// evaluates expression as an integer
    unsigned EvalUInt(Compiler* compiler) override;
    /// evaulates expression as a float
    float EvalFloat(Compiler* compiler) override;
    /// evaluates expression as a bool
    bool EvalBool(Compiler* compiler) override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) override;
private:
	std::string symbol;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------