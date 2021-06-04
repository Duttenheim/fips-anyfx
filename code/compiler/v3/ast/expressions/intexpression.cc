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
bool
IntExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    out = Type::FullType{ "int" };
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
IntExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
IntExpression::EvalInt(Compiler* compiler, int& out) const
{
    out = this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
IntExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    out = (unsigned)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
bool
IntExpression::EvalFloat(Compiler* compiler, float& out) const
{
    out = (float)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
IntExpression::EvalBool(Compiler* compiler, bool& out) const
{
    out = this->value != 0;
    return true;
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