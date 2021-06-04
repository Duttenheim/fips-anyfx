#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::BoolExpression
    
    A boolean expression holds a single boolean argument.
    
    (C) 2021 Gustav Sterbrant
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

	bool value;
}; 
} // namespace AnyFX
//------------------------------------------------------------------------------