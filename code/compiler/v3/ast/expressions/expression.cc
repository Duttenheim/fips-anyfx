//------------------------------------------------------------------------------
//  expression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "expression.h"
#include "util.h"
#include "compiler.h"
#include "v3/ast/types/type.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Expression::Expression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Expression::~Expression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalInt(Compiler* compiler, int& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalFloat(Compiler* compiler, float& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalBool(Compiler* compiler, bool& out) const
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string
Expression::EvalString(Compiler* compiler) const
{
    return "";
}

} // namespace AnyFX