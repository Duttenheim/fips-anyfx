//------------------------------------------------------------------------------
//  boolexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "boolexpression.h"
#include "util.h"
#include "compiler.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
BoolExpression::BoolExpression(bool value) :
    value(value)
{
    this->symbolType = BoolExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
BoolExpression::~BoolExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
BoolExpression::EvalSymbol(Compiler* compiler) const
{
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int
BoolExpression::EvalInt(Compiler* compiler) const
{
    return (int)this->value;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
BoolExpression::EvalUInt(Compiler* compiler) const
{
    return (unsigned) this->value;
}

//------------------------------------------------------------------------------
/**
*/
float
BoolExpression::EvalFloat(Compiler* compiler) const
{
    static std::string err = "Bool cannot be explicitly cast to float";
    compiler->Error(err, this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
bool
BoolExpression::EvalBool(Compiler* compiler) const
{
    return this->value;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
BoolExpression::EvalString(Compiler* compiler) const
{
    return this->value ? "true" : "false";
}
} // namespace AnyFX