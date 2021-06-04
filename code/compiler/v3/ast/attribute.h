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
struct Expression;
struct Attribute
{
    std::string name;
    Expression* expression;

    /// converts attribute to string
    bool ToString(Compiler* compiler, std::string& out) const;
};

//------------------------------------------------------------------------------
/**
*/
inline bool
Attribute::ToString(Compiler* compiler, std::string& out) const
{
    bool ret = true;
    if (this->expression == nullptr)
        out.append(Format("%s", this->name.c_str()));
    else
    {
        switch (this->expression->symbolType)
        {
        case Symbol::FloatExpressionType:
        {
            float f;
            ret &= this->expression->EvalFloat(compiler, f);
            out.append(Format("%s(%f)", this->name.c_str(), f));
            break;
        }
        case Symbol::UIntExpressionType:
        {
            unsigned i;
            ret &= this->expression->EvalUInt(compiler, i);
            out.append(Format("%s(%d)", this->name.c_str(), i));
            break;
        }
        case Symbol::IntExpressionType:
        {
            int i;
            ret &= this->expression->EvalInt(compiler, i);
            out.append(Format("%s(%d)", this->name.c_str(), i));
            break;
        }
        case Symbol::BoolExpressionType:
        {
            bool b;
            ret &= this->expression->EvalBool(compiler, b);
            out.append(Format("%s(%d)", this->name.c_str(), b));
            break;
        }
        case Symbol::StringExpressionType:
        {
            std::string str = this->expression->EvalString(compiler);
            out.append(Format("%s(%s)", this->name.c_str(), str.c_str()));
            break;
        }
        case Symbol::SymbolExpressionType:
        {
            std::string str;
            ret &= this->expression->EvalSymbol(compiler, str);
            out.append(Format("%s(%s)", this->name.c_str(), str.c_str()));
            break;
        }
        }
    }
    return ret;
}

} // namespace AnyFX
