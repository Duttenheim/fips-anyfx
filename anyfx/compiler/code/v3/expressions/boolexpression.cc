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
    this->symbolType = BoolType;
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
BoolExpression::EvalSymbol(Compiler* compiler)
{
    return this;
}

//------------------------------------------------------------------------------
/**
*/
int
BoolExpression::EvalInt(Compiler* compiler)
{
    return (int)this->value;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
BoolExpression::EvalUInt(Compiler* compiler)
{
    return (unsigned) this->value;
}

//------------------------------------------------------------------------------
/**
*/
float
BoolExpression::EvalFloat(Compiler* compiler)
{
    std::string err = Format("Bool cannot be explicitly cast to float");
    compiler->Error(err, this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
bool
BoolExpression::EvalBool(Compiler* compiler)
{
    return this->value;
}
} // namespace AnyFX