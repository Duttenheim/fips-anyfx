//------------------------------------------------------------------------------
//  symbolexpression.cc
//  (C) 2020 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "symbolexpression.h"
#include "ast/symbol.h"
#include "ast/variable.h"
#include "ast/function.h"
#include "compiler.h"
#include "util.h"
#include "v3/ast/types/type.h"
#include "v3/ast/structure.h"
#include <string>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
SymbolExpression::SymbolExpression(const std::string symbol)
    : symbol(symbol)
{
    this->symbolType = SymbolExpressionType;
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
bool 
SymbolExpression::EvalType(Compiler* compiler, Type::FullType& out) const
{
    Symbol* sym = compiler->GetSymbol(this->symbol);
    if (sym != nullptr)
    {
        if (sym->symbolType == Symbol::VariableType)
        {
            Variable* var = static_cast<Variable*>(sym);
            Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
            out = varResolved->type;
            return true;
        }
        else if (sym->symbolType == Symbol::StructureType)
        {
            Structure* struc = static_cast<Structure*>(sym);
            out = Type::FullType{ struc->name };
            return true;
        }
        else if (sym->symbolType == Symbol::TypeType)
        {
            Type* type = static_cast<Type*>(sym);
            out = Type::FullType{ type->name };
            return true;
        }
        else if (sym->symbolType == Symbol::FunctionType)
        {
            Function* fun = static_cast<Function*>(sym);
            out = fun->returnType;
            return true;
        }
    }
    out.name = this->symbol;
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalSymbol(Compiler* compiler, std::string& out) const
{
    out = this->symbol;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalInt(Compiler* compiler, int& out) const
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
            case VariableType:
            {
                Variable* var = static_cast<Variable*>(symbol);
                Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
                return varResolved->value->EvalInt(compiler, out);
            }
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalUInt(Compiler* compiler, unsigned& out) const
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
            case VariableType:
            {
                Variable* var = static_cast<Variable*>(symbol);
                Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
                return varResolved->value->EvalUInt(compiler, out);
            }
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalFloat(Compiler* compiler, float& out) const
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
            case VariableType:
            {
                Variable* var = static_cast<Variable*>(symbol);
                Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
                return varResolved->value->EvalFloat(compiler, out);
            }
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool
SymbolExpression::EvalBool(Compiler* compiler, bool& out) const
{
    Symbol* symbol = compiler->GetSymbol(this->symbol);
    if (symbol)
    {
        switch (symbol->symbolType)
        {
            case VariableType:
            {
                Variable* var = static_cast<Variable*>(symbol);
                Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
                return varResolved->value->EvalBool(compiler, out);
            }
        }
    }
    return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string
SymbolExpression::EvalString(Compiler* compiler) const
{
    return this->symbol;
}

} // namespace AnyFX