//------------------------------------------------------------------------------
//  @file arrayindexexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "arrayindexexpression.h"
#include "util.h"
#include "compiler.h"
#include "v3/ast/types/type.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
ArrayIndexExpression::ArrayIndexExpression(Expression* left, Expression* right)
    : left(left)
    , right(right)
{
    this->symbolType = ArrayIndexExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
bool 
ArrayIndexExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    if (!this->left->EvalType(compiler, out))
        return false;
    if (out.modifiers.empty())
        return false;
    out.modifiers.pop_back();
    out.modifierExpressions.pop_back();
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
ArrayIndexExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return this->left->EvalSymbol(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
bool  
ArrayIndexExpression::EvalInt(Compiler* compiler, int& out) const
{
    return this->left->EvalInt(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
bool 
ArrayIndexExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    return this->left->EvalUInt(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
bool 
ArrayIndexExpression::EvalFloat(Compiler* compiler, float& out) const
{
    return this->left->EvalFloat(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
bool 
ArrayIndexExpression::EvalBool(Compiler* compiler, bool& out) const
{
    return this->left->EvalBool(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
std::string
ArrayIndexExpression::EvalString(Compiler* compiler) const
{
    std::string left, right;
    left = this->left->EvalString(compiler);
    right = this->right->EvalString(compiler);

    if (this->right != nullptr)
        return Format("%s[%s]", left.c_str(), right.c_str());
    else
        return Format("%s[]", left.c_str());
}

} // namespace AnyFX
