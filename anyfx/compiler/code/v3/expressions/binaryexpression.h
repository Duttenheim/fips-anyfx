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
class BinaryExpression : public Expression
{
public:
	/// constructor
	BinaryExpression(const std::string& op, Expression* left, Expression* right);
	/// destructor
	virtual ~BinaryExpression();

	/// evaulate type of expression
    Symbol* EvalSymbol(Compiler* compiler) override;
	/// evaluates expression as an integer
	int EvalInt(Compiler* compiler) override;
	/// evaluates expression as an integer
	unsigned EvalUInt(Compiler* compiler) override;
	/// evaulates expression as a float
	float EvalFloat(Compiler* compiler) override;
	/// evaluates expression as bool
	bool EvalBool(Compiler* compiler) override;
private:

	/// helper functions for bool evaluations
	bool EvalBool(int lhs, int rhs, Compiler* compiler);
	bool EvalBool(float lhs, int rhs, Compiler* compiler);
	bool EvalBool(int lhs, float rhs, Compiler* compiler);
	bool EvalBool(float lhs, float rhs, Compiler* compiler);
	bool EvalBool(bool lhs, bool rhs, Compiler* compiler);

	std::string op;
	Expression* left;
	Expression* right;
}; 


} // namespace AnyFX
//------------------------------------------------------------------------------