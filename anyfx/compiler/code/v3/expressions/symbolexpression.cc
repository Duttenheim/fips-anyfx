//------------------------------------------------------------------------------
//  symbolexpression.cc
//  (C) 2020 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "symbolexpression.h"
#include "ast/symbol.h"
#include "ast/variable.h"
#include "compiler.h"
#include "util.h"
#include <string>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
SymbolExpression::SymbolExpression(const std::string symbol)
    : symbol(symbol)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
SymbolExpression::~SymbolExpression()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
SymbolExpression::EvalSymbol(Compiler* compiler)
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol == nullptr)
    {
        std::string err = Format("Symbol '%s' not declared", this->symbol.c_str());
        compiler->Error(err, this);
    }
    return symbol;
}

//------------------------------------------------------------------------------
/**
*/
int
SymbolExpression::EvalInt(Compiler* compiler)
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
        case VariableType:
        {
            Variable* var = static_cast<Variable*>(symbol);
            if (var->values.size() > 1)
            {
                std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", var->name.c_str());
                compiler->Error(msg, this);
            }
            else
            {
                return std::stoi(var->values[0].c_str());
            }
            break;
        }
        default:
            std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->name.c_str());
            compiler->Error(msg, this);
            break;
        }
    }
    return -1;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
SymbolExpression::EvalUInt(Compiler* compiler)
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
        case VariableType:
        {
            Variable* var = static_cast<Variable*>(symbol);
            if (var->values.size() > 1)
            {
                std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", var->name.c_str());
                compiler->Error(msg, this);
            }
            else
            {
                return std::stoul(var->values[0].c_str());
            }
            break;
        }
        default:
            std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->name.c_str());
            compiler->Error(msg, this);
            break;
        }
    }
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
float
SymbolExpression::EvalFloat(Compiler* compiler)
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
        case VariableType:
        {
            Variable* var = static_cast<Variable*>(symbol);
            if (var->values.size() > 1)
            {
                std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", var->name.c_str());
                compiler->Error(msg, this);
            }
            else
            {
                return std::stof(var->values[0].c_str());
            }
            break;
        }
        default:
            std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->name.c_str());
            compiler->Error(msg, this);
            break;
        }
    }
    return 0.0f;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalBool(Compiler* compiler)
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
        case VariableType:
        {
            Variable* var = static_cast<Variable*>(symbol);
            if (var->values.size() > 1)
            {
                std::string msg = AnyFX::Format("Expression '%s' could not be evaluated to single value", var->name.c_str());
                compiler->Error(msg, this);
            }
            else
            {
                return std::stoi(var->values[0].c_str());
            }
            break;
        }
        default:
            std::string msg = AnyFX::Format("Expression '%s' is of a type which can't be used as a literal", symbol->name.c_str());
            compiler->Error(msg, this);
            break;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
SymbolExpression::EvalString(Compiler* compiler)
{
    return this->symbol;
}

} // namespace AnyFX