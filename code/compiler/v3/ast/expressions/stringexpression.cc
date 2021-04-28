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
Symbol*
StringExpression::EvalSymbol(Compiler* compiler) const
{
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int
StringExpression::EvalInt(Compiler* compiler) const
{
    return std::stoi(this->value);
}

//------------------------------------------------------------------------------
/**
*/
unsigned
StringExpression::EvalUInt(Compiler* compiler) const
{
    return std::stoul(this->value);
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
float
StringExpression::EvalFloat(Compiler* compiler) const
{
    return std::stof(this->value);
}

//------------------------------------------------------------------------------
/**
*/
bool
StringExpression::EvalBool(Compiler* compiler) const
{
    return this->value == "true";
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