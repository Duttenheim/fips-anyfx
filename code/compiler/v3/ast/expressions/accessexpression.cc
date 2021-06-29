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
AccessExpression::~AccessExpression()
{
    delete this->left;
    delete this->right;
}

//------------------------------------------------------------------------------
/**
*/
bool
AccessExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    Type::FullType leftType;
    bool ret = true;
    if (!this->left->EvalType(compiler, leftType))
    {
        compiler->Error(Format("Could not resolve type '%s'", leftType.name.c_str()), this->right);
        return false;
    }

    // if deref, pop modifier
    if (this->deref)
    {
        if (leftType.modifiers.empty())
            return false;
        leftType.modifierValues.pop_back();
        leftType.modifiers.pop_back();
    }

    Type* type = compiler->GetSymbol<Type>(leftType.name);

    Compiler::TypeScope scope(compiler, type);

    // get old type and replace type with current type
    std::string member;
    if (!this->right->EvalSymbol(compiler, member))
    {
        compiler->Error(Format("Could not resolve type '%s'", member.c_str()), this->right);
        return false;
    }
    
    if (type->IsVector())
    {
        // eval swizzled type
        unsigned swizzle;
        Type::SwizzleMask(member, swizzle);
        unsigned biggestComponent = Type::SwizzleMaskBiggestComponent(swizzle);
        unsigned numComponents = Type::SwizzleMaskComponents(swizzle);
        std::string vectorType = Type::ToVector(type->baseType, numComponents);
        out = Type::FullType{ vectorType };
    }
    else
    {
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
