//------------------------------------------------------------------------------
//  uintexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "uintexpression.h"
#include "util.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
UIntExpression::UIntExpression(int value) :
    value(value)
{
    this->symbolType = UIntExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
UIntExpression::~UIntExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool
UIntExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    out = Type::FullType{ "uint" };
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
UIntExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
UIntExpression::EvalInt(Compiler* compiler, int& out) const
{
    out = (int)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
UIntExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    out = this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
bool
UIntExpression::EvalFloat(Compiler* compiler, float& out) const
{
    out = (float)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
UIntExpression::EvalBool(Compiler* compiler, bool& out) const
{
    out = this->value != 0;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
std::string
UIntExpression::EvalString(Compiler* compiler) const
{
    return Format("%d", this->value);
}

} // namespace AnyFX