//------------------------------------------------------------------------------
//  @file callexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "callexpression.h"
#include "util.h"
#include "compiler.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
CallExpression::CallExpression(const std::vector<Expression*>& args)
    : args(args)
{
    this->symbolType = CallExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
CallExpression::EvalSymbol(Compiler* compiler) const
{
    return compiler->GetSymbol(this->name);
}

//------------------------------------------------------------------------------
/**
*/
int 
CallExpression::EvalInt(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to int", this->name.c_str());
    compiler->Error(msg, this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
CallExpression::EvalUInt(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to uint", this->name.c_str());
    compiler->Error(msg, this);
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
float 
CallExpression::EvalFloat(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to float", this->name.c_str());
    compiler->Error(msg, this);
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool 
CallExpression::EvalBool(Compiler* compiler) const
{
    std::string msg = Format("Expression '%s' could not be evaluated to boolean", this->name.c_str());
    compiler->Error(msg, this);
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
CallExpression::EvalString(Compiler* compiler) const
{
    std::string args;
    for (Expression* expr : this->args)
    {
        args.append(expr->EvalString(compiler));
        if (expr != this->args.back())
            args.append(", ");
    }
    return Format("(%s)", args.c_str());
}

} // namespace AnyFX
