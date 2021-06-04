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
struct StringExpression : public Expression
{
public:
	/// constructor
    StringExpression(std::string value);
	/// destructor
	virtual ~StringExpression();

    /// evaluates expression as an integer
    bool EvalInt(Compiler* compiler, int& out) const override;
    /// evaluates expression as an integer
    bool EvalUInt(Compiler* compiler, unsigned& out) const override;
    /// evaulates expression as a float
    bool EvalFloat(Compiler* compiler, float& out) const override;
    /// evaluates expression as a boolean
    bool EvalBool(Compiler* compiler, bool& out) const override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

	std::string value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------