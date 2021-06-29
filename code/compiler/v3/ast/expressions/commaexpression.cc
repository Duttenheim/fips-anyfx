//------------------------------------------------------------------------------
//  @file commaexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "commaexpression.h"
#include "util.h"
#include "compiler.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
CommaExpression::CommaExpression(Expression* left, Expression* right)
    : left(left)
    , right(right)
{
    this->symbolType = CommaExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
CommaExpression::~CommaExpression()
{
    delete this->left;
    delete this->right;
}

//------------------------------------------------------------------------------
/**
*/
bool 
CommaExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    return this->right->EvalType(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
bool
CommaExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return this->right->EvalSymbol(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
std::string
CommaExpression::EvalString(Compiler* compiler) const
{
    std::string left, right;
    left = this->left->EvalString(compiler);
    right = this->right->EvalString(compiler);
    return Format("%s,%s", left.c_str(), right.c_str());
}

} // namespace AnyFX
