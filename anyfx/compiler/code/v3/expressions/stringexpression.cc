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
    this->symbolType = StringType;
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
StringExpression::EvalSymbol(Compiler* compiler)
{
    return this;
}

//------------------------------------------------------------------------------
/**
*/
int
StringExpression::EvalInt(Compiler* compiler)
{
    return std::stoi(this->value);
}

//------------------------------------------------------------------------------
/**
*/
unsigned
StringExpression::EvalUInt(Compiler* compiler)
{

    return std::stoul(this->value);
}

//------------------------------------------------------------------------------
/**
    Convert this integer to a float
*/
float
StringExpression::EvalFloat(Compiler* compiler)
{
    return std::stof(this->value);
}

//------------------------------------------------------------------------------
/**
*/
bool
StringExpression::EvalBool(Compiler* compiler)
{
    return this->value == "true";
}

//------------------------------------------------------------------------------
/**
*/
std::string 
StringExpression::EvalString(Compiler* compiler)
{
    return this->value;
}

} // namespace AnyFX