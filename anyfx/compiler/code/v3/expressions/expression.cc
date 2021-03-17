//------------------------------------------------------------------------------
//  expression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "expression.h"
#include "util.h"
#include "compiler.h"

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
    compiler->Error("INTERNAL COMPILER ERROR: Expression::EvalSymbol() called!\n", this);
    return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
int
Expression::EvalInt(Compiler* compiler)
{
    compiler->Error("INTERNAL COMPILER ERROR: Expression::EvalInt() called!\n", this);
    return -1;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
Expression::EvalUInt(Compiler* compiler)
{
    compiler->Error("INTERNAL COMPILER ERROR: Expression::EvalUInt() called!\n", this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
float
Expression::EvalFloat(Compiler* compiler)
{
    compiler->Error("INTERNAL COMPILER ERROR: Expression::EvalFloat() called!\n", this);
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool
Expression::EvalBool(Compiler* compiler)
{
    compiler->Error("INTERNAL COMPILER ERROR: Expression::EvalBool() called!\n", this);
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
Expression::EvalString(Compiler* compiler)
{
    compiler->Error("INTERNAL COMPILER ERROR: Expression::EvalString() called!\n", this);
    return "";
}

} // namespace AnyFX