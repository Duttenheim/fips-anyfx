//------------------------------------------------------------------------------
//  @file accessexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "accessexpression.h"
#include "util.h"
#include "compiler.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
AccessExpression::AccessExpression(Expression* value)
    : value(value)
{
    this->symbolType = AccessExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
AccessExpression::EvalSymbol(Compiler* compiler) const
{
    return this->value->EvalSymbol(compiler);
}

//------------------------------------------------------------------------------
/**
*/
int 
AccessExpression::EvalInt(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to int", this->name.c_str());
    compiler->Error(msg, this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
AccessExpression::EvalUInt(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to uint", this->name.c_str());
    compiler->Error(msg, this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
float 
AccessExpression::EvalFloat(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to float", this->name.c_str());
    compiler->Error(msg, this);
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool 
AccessExpression::EvalBool(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to boolean", this->name.c_str());
    compiler->Error(msg, this);
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
AccessExpression::EvalString(Compiler* compiler) const
{
    return Format(".%s", this->value->EvalString(compiler).c_str());
}

} // namespace AnyFX
