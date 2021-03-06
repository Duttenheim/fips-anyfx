//------------------------------------------------------------------------------
//  unaryexpression.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "unaryexpression.h"
#include "util.h"
#include "compiler.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
UnaryExpression::UnaryExpression(char op, Expression* expr) :
    op(op),
    expr(expr)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
UnaryExpression::~UnaryExpression()
{
    delete this->expr;
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
UnaryExpression::EvalSymbol(Compiler* compiler)
{
    return this->expr->EvalSymbol(compiler);
}

//------------------------------------------------------------------------------
/**
*/
int
UnaryExpression::EvalInt(Compiler* compiler)
{
    if (this->op == '-')
    {
        return this->expr->EvalInt(compiler) * -1;
    }
    else
    {
        std::string msg = Format("Invalid operator '%c' for int", this->op);
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
unsigned
UnaryExpression::EvalUInt(Compiler* compiler)
{
    if (this->op == '-')
    {
        return this->expr->EvalUInt(compiler) * -1;
    }
    else
    {
        std::string msg = Format("Invalid operator '%c' for unsigned int", this->op);
        compiler->Error(msg, this);
        return -1;
    }
}

//------------------------------------------------------------------------------
/**
*/
float
UnaryExpression::EvalFloat(Compiler* compiler)
{
    if (this->op == '-')
    {
        return this->expr->EvalFloat(compiler) * -1;
    }
    else
    {
        std::string msg = Format("Invalid operator '%c' for float", this->op);
        compiler->Error(msg, this);
        return 0;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool
UnaryExpression::EvalBool(Compiler* compiler)
{
    if (this->op == '!')
    {
        return !this->expr->EvalBool(compiler);
    }
    else
    {
        std::string msg = Format("Invalid operator '%c' for bool", this->op);
        compiler->Error(msg, this);
        return false;
    }
}
} // namespace AnyFX