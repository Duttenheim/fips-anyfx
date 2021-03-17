//------------------------------------------------------------------------------
//  symbol.cc
//  (C) 2013 gscept
//------------------------------------------------------------------------------
#include "symbol.h"
#include "util.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Symbol::Symbol() :
    reserved(false),
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
    std::string result = AnyFX::Format("%d:%d in file %s", this->location.line, this->location.column, this->location.file.c_str());
    return result;
}

//------------------------------------------------------------------------------
/**
*/
bool
Symbol::EndOfParse(Compiler* compiler)
{
    this->resolved->signature = this->name;
    return true;
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
        return "state";
    case SamplerType:
        return "sampler";
    case VariableType:
        return "variable";
    case CompoundResourceType:
        return "compound_resource";
    case TypedResourceType:
        return "typed_resource";
    case SubroutineType:
        return "subroutine";
    case FunctionType:
        return "function";
    case StructureType:
        return "struct";
    case FloatType:
        return "float";
    case IntType:
        return "int";
    case BoolType:
        return "bool";
    }
    return "";
}

} // namespace AnyFX