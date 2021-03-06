//------------------------------------------------------------------------------
//  expression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "expression.h"
#include "util.h"

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
Symbol*
Expression::EvalSymbol(Compiler* compiler)
{
    Error("Expression::EvalSymbol() called!\n");
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int
Expression::EvalInt(Compiler* compiler)
{
    Error("Expression::EvalInt() called!\n");
    return -1;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
Expression::EvalUInt(Compiler* compiler)
{
    Error("Expression::EvalUInt() called!\n");
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
float
Expression::EvalFloat(Compiler* compiler)
{
    Error("Expression::EvalFloat() called!\n");
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalBool(Compiler* compiler)
{
    Error("Expression::EvalBool() called!\n");
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
Expression::EvalString(Compiler* compiler)
{
    Error("Expression::EvalString() called!\n");
    return "";
}

} // namespace AnyFX