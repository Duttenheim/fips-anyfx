//------------------------------------------------------------------------------
//  @file initializerexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "initializerexpression.h"
#include "util.h"
#include "compiler.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
InitializerExpression::InitializerExpression(const std::vector<Expression*>& values)
    : values(values)
{
    this->symbolType = InitializerExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
bool 
InitializerExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    bool ret = true;
    ret &= this->values.front()->EvalType(compiler, out);
    out.modifiers.push_back(Type::FullType::Modifier::ArrayLevel);
    out.modifierExpressions.push_back(nullptr);
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
std::string
InitializerExpression::EvalString(Compiler* compiler) const
{
    std::string ret;
    for (Expression* expr : this->values)
    {
        std::string str;
        str = expr->EvalString(compiler);
        ret.append(str);
        if (expr != this->values.back())
            ret.append(", ");
    }
    return ret;
}

} // namespace AnyFX
