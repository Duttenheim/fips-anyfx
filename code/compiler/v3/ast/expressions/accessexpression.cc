//------------------------------------------------------------------------------
//  @file accessexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "accessexpression.h"
#include "util.h"
#include "compiler.h"
#include "v3/ast/variable.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
AccessExpression::AccessExpression(Expression* left, Expression* right, bool deref)
    : left(left)
    , right(right)
    , deref(deref)
{
    this->symbolType = AccessExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
bool
AccessExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    Type::FullType leftType;
    bool ret = true;
    ret &= this->left->EvalType(compiler, leftType);

    // if deref, pop modifier
    if (this->deref)
    {
        if (leftType.modifiers.empty())
            return false;
        leftType.modifierExpressions.pop_back();
        leftType.modifiers.pop_back();
    }

    Type* type = compiler->GetSymbol<Type>(leftType.name);

    Compiler::TypeScope scope(compiler, type);

    // get old type and replace type with current type
    std::string member;
    
    if (type->IsVector())
    {
        // eval swizzled type
        unsigned swizzle;
        ret &= Type::SwizzleMask(member, swizzle);
        unsigned biggestComponent = Type::SwizzleMaskBiggestComponent(swizzle);
        ret &= biggestComponent > type->columnSize;
        unsigned numComponents = Type::SwizzleMaskComponents(swizzle);
        std::string vectorType = Type::ToVector(type->baseType, numComponents);
        out = Type::FullType{ vectorType };
    }
    else
    {
        ret &= this->right->EvalSymbol(compiler, member);
        Variable* memberVar = static_cast<Variable*>(compiler->GetSymbol(member));
        if (memberVar == nullptr)
            return false;
        else
        {
            Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(memberVar->resolved);
            out = varResolved->type;
        }
    }

    // after unraveling, reset old type
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool
AccessExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return this->right->EvalSymbol(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
std::string
AccessExpression::EvalString(Compiler* compiler) const
{
    std::string left, right;
    left = this->left->EvalString(compiler);
    right = this->right->EvalString(compiler);
    return Format("%s.%s", left.c_str(), right.c_str());
}

} // namespace AnyFX
