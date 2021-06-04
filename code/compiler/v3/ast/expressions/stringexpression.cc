//------------------------------------------------------------------------------
//  stringexpression.cc
//  (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "stringexpression.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
StringExpression::StringExpression(std::string value) :
    value(value)
{
    this->symbolType = StringExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
StringExpression::~StringExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool
StringExpression::EvalInt(Compiler* compiler, int& out) const
{
    out = std::stoi(this->value);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
StringExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    out = std::stoul(this->value);
    return true;
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
bool
StringExpression::EvalFloat(Compiler* compiler, float& out) const
{
    out = std::stof(this->value);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
StringExpression::EvalBool(Compiler* compiler, bool& out) const
{
    out = this->value == "true";
    return true;
}

//------------------------------------------------------------------------------
/**
*/
std::string
StringExpression::EvalString(Compiler* compiler) const
{
    return this->value;
}

} // namespace AnyFX