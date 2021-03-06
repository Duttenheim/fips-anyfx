//------------------------------------------------------------------------------
//  intexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "intexpression.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
IntExpression::IntExpression(int value) :
    value(value)
{
    this->symbolType = IntType;
}

//------------------------------------------------------------------------------
/**
*/
IntExpression::~IntExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
IntExpression::EvalSymbol(Compiler* compiler)
{
    return this;
}

//------------------------------------------------------------------------------
/**
*/
int
IntExpression::EvalInt(Compiler* compiler)
{
    return this->value;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
IntExpression::EvalUInt(Compiler* compiler)
{
    return (unsigned)this->value;
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
float
IntExpression::EvalFloat(Compiler* compiler)
{
    return (float)this->value;
}

//------------------------------------------------------------------------------
/**
*/
bool
IntExpression::EvalBool(Compiler* compiler)
{
    return this->value != 0;
}

} // namespace AnyFX