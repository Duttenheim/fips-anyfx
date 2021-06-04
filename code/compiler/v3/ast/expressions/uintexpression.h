#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::UIntExpression
    
    An unsigned expression is a simple expression which holds an unsigned integer.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
namespace AnyFX
{
struct UIntExpression : public Expression
{
public:
	/// constructor
    UIntExpression(int value);
	/// destructor
	virtual ~UIntExpression();

    /// eval type
    bool EvalType(Compiler* compiler, Type::FullType& out) const override;
    /// eval symbol
    bool EvalSymbol(Compiler* compiler, std::string& out) const override;
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

	unsigned int value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------