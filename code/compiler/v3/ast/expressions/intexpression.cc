//------------------------------------------------------------------------------
//  intexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "intexpression.h"
#include "util.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
IntExpression::IntExpression(int value) :
    value(value)
{
    this->symbolType = IntExpressionType;
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
IntExpression::EvalSymbol(Compiler* compiler) const
{
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int
IntExpression::EvalInt(Compiler* compiler) const
{
    return this->value;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
IntExpression::EvalUInt(Compiler* compiler) const
{
    return (unsigned)this->value;
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
float
IntExpression::EvalFloat(Compiler* compiler) const
{
    return (float)this->value;
}

//------------------------------------------------------------------------------
/**
*/
bool
IntExpression::EvalBool(Compiler* compiler) const
{
    return this->value != 0;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
IntExpression::EvalString(Compiler* compiler) const
{
    return Format("%d", this->value);
}

} // namespace AnyFX