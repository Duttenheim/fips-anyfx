//------------------------------------------------------------------------------
//  symbol.cc
//  (C) 2013 gscept
//------------------------------------------------------------------------------
#include "symbol.h"
#include "util.h"
#include "compiler.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Symbol::Symbol() :
    symbolType(InvalidType)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Symbol::~Symbol()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
std::string
Symbol::GetLocation() const
{
    std::string result = Format("%d:%d in file %s", this->location.line, this->location.column, this->location.file.c_str());
    return result;
}

//------------------------------------------------------------------------------
/**
*/
bool
Symbol::EndOfParse(Compiler* compiler)
{
    return compiler->AddSymbol(this->name, this);
}

//------------------------------------------------------------------------------
/**
*/
const std::string 
Symbol::TypeToString() const
{
    switch (this->symbolType)
    {
    case ProgramType:
        return "program";
    case RenderStateType:
        return "render_state";
    case SamplerStateType:
        return "sampler_state";
    case VariableType:
        return "variable";
    case SubroutineType:
        return "subroutine";
    case FunctionType:
        return "function";
    case StructureType:
        return "struct";
    case FloatExpressionType:
        return "float";
    case IntExpressionType:
        return "int";
    case BoolExpressionType:
        return "bool";
    }
    return "";
}

} // namespace AnyFX