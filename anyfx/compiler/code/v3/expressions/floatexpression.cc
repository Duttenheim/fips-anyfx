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
    this->symbolType = FloatType;
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
FloatExpression::EvalSymbol(Compiler* compiler)
{
    return this;
}

//------------------------------------------------------------------------------
/**
    Convert this float to an integer
*/
int 
FloatExpression::EvalInt(Compiler* compiler)
{
    return (int)this->value;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
FloatExpression::EvalUInt(Compiler* compiler)
{
    return (unsigned)this->value;
}

//------------------------------------------------------------------------------
/**
*/
float
FloatExpression::EvalFloat(Compiler* compiler)
{
    return this->value;
}

//------------------------------------------------------------------------------
/**
*/
bool
FloatExpression::EvalBool(Compiler* compiler)
{
    std::string err = Format("Float cannot be explicitly cast to bool");
    compiler->Error(err, this);
    return false;
}
} // namespace AnyFX