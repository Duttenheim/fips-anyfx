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
struct SymbolExpression : public Expression
{
public:
	/// constructor
	SymbolExpression(const std::string symbol);
	/// destructor
	virtual ~SymbolExpression();

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

	std::string symbol;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------