#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::StringExpression
    
    An int expression is a simple expression which holds a string
    
    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include <string>
namespace AnyFX
{
class StringExpression : public Expression
{
public:
	/// constructor
    StringExpression(std::string value);
	/// destructor
	virtual ~StringExpression();

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
    /// evaluates expression as string
    std::string EvalString(Compiler* compiler) override;
private:
	std::string value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------