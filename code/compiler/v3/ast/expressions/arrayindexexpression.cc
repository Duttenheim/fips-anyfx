//------------------------------------------------------------------------------
//  @file arrayindexexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "arrayindexexpression.h"
#include "util.h"
#include "compiler.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
ArrayIndexExpression::ArrayIndexExpression(Expression* value)
    : value(value)
{
    this->symbolType = ArrayIndexExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
ArrayIndexExpression::EvalSymbol(Compiler* compiler) const
{
    return this->value->EvalSymbol(compiler);
}

//------------------------------------------------------------------------------
/**
*/
int 
ArrayIndexExpression::EvalInt(Compiler* compiler) const
{
    return this->value->EvalInt(compiler);
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
ArrayIndexExpression::EvalUInt(Compiler* compiler) const
{
    return this->value->EvalUInt(compiler);
}

//------------------------------------------------------------------------------
/**
*/
float 
ArrayIndexExpression::EvalFloat(Compiler* compiler) const
{
    std::string msg = Format("Array index may not be float", this->name.c_str());
    compiler->Error(msg, this);
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool 
ArrayIndexExpression::EvalBool(Compiler* compiler) const
{
    std::string msg = Format("Array index may not be bool", this->name.c_str());
    compiler->Error(msg, this);
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
ArrayIndexExpression::EvalString(Compiler* compiler) const
{
    return Format("[%s]", this->value->EvalString(compiler).c_str());
}

} // namespace AnyFX
