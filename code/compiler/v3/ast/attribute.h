#pragma once
//------------------------------------------------------------------------------
/**
    An attribute holds some sort of symbol-related metadata

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <string>
#include "util.h"
#include "symbol.h"
#include "expressions/expression.h"
namespace AnyFX
{

struct Compiler;
struct Attribute
{
    std::string name;
    Expression* expression;

    /// converts attribute to string
    std::string ToString(Compiler* compiler) const;
};

//------------------------------------------------------------------------------
/**
*/
inline std::string 
Attribute::ToString(Compiler* compiler) const
{
    std::string ret;
    if (this->expression == nullptr)
        ret.append(Format("%s", this->name.c_str()));
    else
    {
        switch (this->expression->symbolType)
        {
        case Symbol::FloatExpressionType:
            ret.append(Format("%s(%f)", this->name.c_str(), this->expression->EvalFloat(compiler)));
            break;
        case Symbol::IntExpressionType:
            ret.append(Format("%s(%d)", this->name.c_str(), this->expression->EvalInt(compiler)));
            break;
        case Symbol::BoolExpressionType:
            ret.append(Format("%s(%d)", this->name.c_str(), this->expression->EvalInt(compiler)));
            break;
        case Symbol::StringExpressionType:
            ret.append(Format("%s(%s)", this->name.c_str(), this->expression->EvalString(compiler).c_str()));
            break;
        case Symbol::SymbolExpressionType:
            ret.append(Format("%s(%s)", this->name.c_str(), this->expression->EvalString(compiler).c_str()));
            break;
        }
    }
    return ret;
}

} // namespace AnyFX
