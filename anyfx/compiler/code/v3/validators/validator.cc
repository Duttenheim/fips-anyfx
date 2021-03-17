//------------------------------------------------------------------------------
//  @file validator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "validator.h"
#include "ast/symbol.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::Validate(Compiler* compiler, const std::vector<Symbol*>& symbols)
{
    bool ret = true;
    for (Symbol* sym : symbols)
    {
        switch (sym->symbolType)
        {
        case Symbol::Type::BlendStateType:
            ret &= this->ValidateBlendState(compiler, sym);
            break;
        case Symbol::Type::CompoundResourceType:
            ret &= this->ValidateCompoundVariable(compiler, sym);
            break;
        case Symbol::Type::FunctionType:
            ret &= this->ValidateFunction(compiler, sym);
            break;
        case Symbol::Type::ProgramType:
            ret &= this->ValidateProgram(compiler, sym);
            break;
        case Symbol::Type::RenderStateType:
            ret &= this->ValidateRenderState(compiler, sym);
            break;
        case Symbol::Type::StructureType:
            ret &= this->ValidateStructure(compiler, sym);
            break;
        case Symbol::Type::VariableType:
            ret &= this->ValidateVariable(compiler, sym);
            break;
        }
    }
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateBlendState(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateCompoundVariable(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateFunction(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateProgram(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateRenderState(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateStructure(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateVariable(Compiler* compiler, Symbol* symbol)
{
    return false;
}

} // namespace AnyFX
