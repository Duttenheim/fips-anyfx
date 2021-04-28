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
UnaryExpression::UnaryExpression(uint32_t op, uint32_t postOp, Expression* expr)
    : op(op)
    , postOp(postOp)
    , expr(expr)
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
UnaryExpression::EvalSymbol(Compiler* compiler) const
{
    return this->expr->EvalSymbol(compiler);
}

//------------------------------------------------------------------------------
/**
*/
int
UnaryExpression::EvalInt(Compiler* compiler) const
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
UnaryExpression::EvalUInt(Compiler* compiler) const
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
UnaryExpression::EvalFloat(Compiler* compiler) const
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
UnaryExpression::EvalBool(Compiler* compiler) const
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

//------------------------------------------------------------------------------
/**
*/
std::string 
UnaryExpression::EvalString(Compiler* compiler) const
{
    if (this->op != 0x0)
    {
        return Format("%s%s", FourCCToString(this->op).c_str(), this->expr->EvalString(compiler).c_str());
    }
    else if (this->postOp != 0x0)
    {
        return Format("%s%s", this->expr->EvalString(compiler).c_str(), FourCCToString(this->op).c_str());
    }
}
} // namespace AnyFX