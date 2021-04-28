//------------------------------------------------------------------------------
//  floatexpression.cc
//  (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "floatexpression.h"
#include "compiler.h"
#include "util.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
FloatExpression::FloatExpression(float value) 
    : value(value)
{
    this->symbolType = FloatExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
FloatExpression::~FloatExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
FloatExpression::EvalSymbol(Compiler* compiler) const
{
    return nullptr;
}

//------------------------------------------------------------------------------
/**
    Convert this float to an integer
*/
int 
FloatExpression::EvalInt(Compiler* compiler) const
{
    return (int)this->value;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
FloatExpression::EvalUInt(Compiler* compiler) const
{
    return (unsigned)this->value;
}

//------------------------------------------------------------------------------
/**
*/
float
FloatExpression::EvalFloat(Compiler* compiler) const
{
    return this->value;
}

//------------------------------------------------------------------------------
/**
*/
bool
FloatExpression::EvalBool(Compiler* compiler) const
{
    std::string err = Format("Float cannot be explicitly cast to bool");
    compiler->Error(err, this);
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
FloatExpression::EvalString(Compiler* compiler) const
{
    return Format("%f", this->value);
}
} // namespace AnyFX