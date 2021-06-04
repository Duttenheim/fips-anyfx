//------------------------------------------------------------------------------
//  @file callexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "callexpression.h"
#include "util.h"
#include "compiler.h"
#include "ast/function.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
CallExpression::CallExpression(Expression* function, const std::vector<Expression*>& args)
    : function(function)
    , args(args)
{
    this->symbolType = CallExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
bool
CallExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    bool ret = true;
    std::string matchSymbol;
    ret &= this->function->EvalSymbol(compiler, matchSymbol);
    Symbol* symbol = compiler->GetSymbol(matchSymbol);
    if (symbol == nullptr)
    {
        out.name = matchSymbol;
        return false;
    }
    Function* matchingFunction = nullptr;

    // setup args for matching
    std::vector<Type::FullType> args;
    for (Expression* expr : this->args)
    {
        Type::FullType type;
        ret &= expr->EvalType(compiler, type);
        args.push_back(type);
    }
    std::vector<Symbol*> matches;

    // function case
    if (symbol->symbolType == Symbol::FunctionType)
    {
        matches = compiler->GetSymbols(matchSymbol);

        Symbol* match = Function::MatchOverload(compiler, matches, args);
        if (match)
            matchingFunction = static_cast<Function*>(match);
    }
    else if (symbol->symbolType == Symbol::TypeType)
    {
        // constructor case
        Type* type = static_cast<Type*>(symbol);
        matches = type->GetSymbols(matchSymbol);

        // if type constructor, allow for implicit conversion of individual arguments
        Symbol* match = Function::MatchOverload(compiler, matches, args, true);
        if (match)
            matchingFunction = static_cast<Function*>(match);
    }

    if (matchingFunction == nullptr)
        out = Type::FullType{ "" };
    else
        out = matchingFunction->returnType;

    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool 
CallExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    return this->function->EvalSymbol(compiler, out);
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
        std::string arg = expr->EvalString(compiler);
        args.append(arg);
        if (expr != this->args.back())
            args.append(", ");
    }
    std::string fun = this->function->EvalString(compiler);
    return Format("%s(%s)", fun.c_str(), args.c_str());
}

} // namespace AnyFX
