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
    this->symbolType = UnaryExpressionType;
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
bool 
UnaryExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    Type::FullType type;
    this->expr->EvalType(compiler, type);
    if (this->op == '*')
    {
        if (type.modifiers.empty())
            return false;
        type.modifiers.pop_back();
        type.modifierExpressions.pop_back();
    }
    out = type;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
UnaryExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return this->expr->EvalSymbol(compiler, out);
}

//------------------------------------------------------------------------------
/**
*/
bool
UnaryExpression::EvalInt(Compiler* compiler, int& out) const
{
    if (this->op == '-')
    {
        return this->expr->EvalInt(compiler, out) * -1;
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool
UnaryExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    if (this->op == '-')
    {
        return this->expr->EvalUInt(compiler, out) * -1;
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool
UnaryExpression::EvalFloat(Compiler* compiler, float& out) const
{
    if (this->op == '-')
    {
        return this->expr->EvalFloat(compiler, out) * -1;
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
bool
UnaryExpression::EvalBool(Compiler* compiler, bool& out) const
{
    if (this->op == '!')
    {
        return !this->expr->EvalBool(compiler, out);
    }
    else
    {
        return false;
    }
}

//------------------------------------------------------------------------------
/**
*/
std::string
UnaryExpression::EvalString(Compiler* compiler) const
{
    std::string expString;
    expString = this->expr->EvalString(compiler);
    if (this->op != 0x0)
        return Format("%s%s", FourCCToString(this->op).c_str(), expString.c_str());
    else if (this->postOp != 0x0)
        return Format("%s%s", expString.c_str(), FourCCToString(this->op).c_str());
    else
        return Format("%s", expString.c_str());
}
} // namespace AnyFX