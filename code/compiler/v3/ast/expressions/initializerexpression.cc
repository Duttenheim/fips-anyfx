//------------------------------------------------------------------------------
//  @file initializerexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "initializerexpression.h"
#include "util.h"
#include "compiler.h"
#include "uintexpression.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
InitializerExpression::InitializerExpression(const std::vector<Expression*>& values)
    : values(values)
{
    this->symbolType = InitializerExpressionType;
    this->sizeExpression = new UIntExpression(values.size());
}

//------------------------------------------------------------------------------
/**
*/
InitializerExpression::~InitializerExpression()
{
    for (Expression* expr : this->values)
        delete expr;
    delete this->sizeExpression;
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
    if (this->sizeExpression)
    {
        uint32_t size;
        if (!this->sizeExpression->EvalUInt(compiler, size))
            return false;
        out.modifierValues.push_back(size);
    }
    else
    {
        out.modifierValues.push_back(0);
    }
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
