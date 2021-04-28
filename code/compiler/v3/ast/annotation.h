#pragma once
//------------------------------------------------------------------------------
/**
    Annotations contains a list of key-value pairs used to pass metadata from 
    source file to reflection, which distinguishes them from attributes which
    are used by the compiler to understand how to transform the code

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <string>
#include "symbol.h"
#include "binwriter.h"
#include "expressions/expression.h"
namespace AnyFX 
{

struct Compiler;
struct Annotation
{
    std::string name;
    Expression* value;

    /// write to binary
    void Emit(Compiler* compiler, BinWriter* writer);
};

//------------------------------------------------------------------------------
/**
*/
inline void 
Annotation::Emit(Compiler* compiler, BinWriter* writer)
{
    writer->WriteString(this->name);
    writer->WriteInt(value->symbolType);
    switch (value->symbolType)
    {
    case Symbol::StringExpressionType:
        writer->WriteString(value->EvalString(compiler));
        break;  
    case Symbol::IntExpressionType:
        writer->WriteInt(value->EvalInt(compiler));
        break;
    case Symbol::FloatExpressionType:
        writer->WriteFloat(value->EvalFloat(compiler));
        break;
    case Symbol::BoolExpressionType:
        writer->WriteBool(value->EvalBool(compiler));
        break;
    }
}

} // namespace AnyFX
