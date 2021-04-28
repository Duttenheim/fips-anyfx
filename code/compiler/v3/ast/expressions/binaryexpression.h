#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::BinaryExpression
    
    A binary expression is a two-part expression, using a left-hand side and right-hand side argument together with an operator.
    
    (C) 2013 Gustav Sterbrant
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

	/// evaulate type of expression
    Symbol* EvalSymbol(Compiler* compiler) const override;
	/// evaluates expression as an integer
	int EvalInt(Compiler* compiler) const override;
	/// evaluates expression as an integer
	unsigned EvalUInt(Compiler* compiler) const override;
	/// evaulates expression as a float
	float EvalFloat(Compiler* compiler) const override;
	/// evaluates expression as bool
	bool EvalBool(Compiler* compiler) const override;
    /// evaluates to string
    std::string EvalString(Compiler* compiler) const override;

	/// helper functions for bool evaluations
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