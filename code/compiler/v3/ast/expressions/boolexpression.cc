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
bool
BoolExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    out = Type::FullType{ "bool" };
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
BoolExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
BoolExpression::EvalInt(Compiler* compiler, int& out) const
{
    out = (int)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
BoolExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    out = (unsigned) this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
BoolExpression::EvalFloat(Compiler* compiler, float& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
BoolExpression::EvalBool(Compiler* compiler, bool& out) const
{
    out = this->value;
    return true;
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