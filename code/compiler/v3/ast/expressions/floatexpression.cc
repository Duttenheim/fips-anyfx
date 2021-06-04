//------------------------------------------------------------------------------
//  floatexpression.cc
//  (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "floatexpression.h"
#include "compiler.h"
#include "util.h"
#include "v3/ast/types/type.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
FloatExpression::FloatExpression(float value) 
    : value(value)
{
    this->symbolType = FloatExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
FloatExpression::~FloatExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool 
FloatExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    out = Type::FullType{ "float" };
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
FloatExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
    Convert this float to an integer
*/
bool  
FloatExpression::EvalInt(Compiler* compiler, int& out) const
{
    out = (int)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
FloatExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    out = (unsigned)this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
FloatExpression::EvalFloat(Compiler* compiler, float& out) const
{
    out = this->value;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
FloatExpression::EvalBool(Compiler* compiler, bool& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string
FloatExpression::EvalString(Compiler* compiler) const
{
    return Format("%f", this->value);
}
} // namespace AnyFX