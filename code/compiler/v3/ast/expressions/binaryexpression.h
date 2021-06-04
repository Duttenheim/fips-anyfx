#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::BinaryExpression
    
    A binary expression is a two-part expression, using a left-hand side and right-hand side argument together with an operator.

    < expression op expression >
    
    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
namespace AnyFX
{
struct BinaryExpression : public Expression
{
public:
	/// constructor
	BinaryExpression(uint32_t op, Expression* left, Expression* right);
	/// destructor
	virtual ~BinaryExpression();

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

	/// helper functions for compile time bool evaluations
	bool EvalBool(int lhs, int rhs, Compiler* compiler) const;
	bool EvalBool(float lhs, int rhs, Compiler* compiler) const;
	bool EvalBool(int lhs, float rhs, Compiler* compiler) const;
	bool EvalBool(float lhs, float rhs, Compiler* compiler) const;
	bool EvalBool(bool lhs, bool rhs, Compiler* compiler) const;

	uint32_t op;
	Expression* left;
	Expression* right;
}; 


} // namespace AnyFX
//------------------------------------------------------------------------------