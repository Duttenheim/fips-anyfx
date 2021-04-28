//------------------------------------------------------------------------------
//  @file function.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "function.h"
#include "util.h"
#include "variable.h"
#include "type.h"
#include "compiler.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Function::Function()
{
    this->symbolType = FunctionType;
    this->resolved = new Function::__Resolved();
    this->hasBody = false;
    this->ast = nullptr;

    Function::__Resolved* typeResolved = static_cast<Function::__Resolved*>(this->resolved);
    typeResolved->computeShaderWorkGroupSize[0] = 1;
    typeResolved->computeShaderWorkGroupSize[1] = 1;
    typeResolved->computeShaderWorkGroupSize[2] = 1;
    typeResolved->earlyDepth = false;
    typeResolved->isShader = false;
    typeResolved->shaderUsage.bits = 0x0;
    typeResolved->invocations = Function::__Resolved::INVALID_SIZE;
    typeResolved->maxOutputVertices = Function::__Resolved::INVALID_SIZE;
    typeResolved->patchSize = Function::__Resolved::INVALID_SIZE;
    typeResolved->windingOrder = Function::__Resolved::InvalidWindingOrder;
    typeResolved->inputPrimitiveTopology = Function::__Resolved::InvalidPrimitiveTopology;
    typeResolved->outputPrimitiveTopology = Function::__Resolved::InvalidPrimitiveTopology;
    typeResolved->patchType = Function::__Resolved::InvalidPatchType;
    typeResolved->partitionMethod = Function::__Resolved::InvalidPartitionMethod;
    typeResolved->pixelOrigin = Function::__Resolved::Lower;
}

//------------------------------------------------------------------------------
/**
*/
Function::~Function()
{
    for (Variable* var : this->parameters)
        delete var;
}

//------------------------------------------------------------------------------
/**
*/
bool
Function::EndOfParse(Compiler* compiler)
{
    // setup our variables and attributes as sets
    std::string paramList;
    for (Variable* var : this->parameters)
    {
        // add comma if not first argument
        if (var != this->parameters.front())
            paramList.append(",");

        // finally add type
        paramList.append(var->type);
    }

    std::string attributeList;
    bool isPrototype = false;

    // make a set of all attributes
    for (const Attribute& attr : this->attributes)
    {
        const std::string& attrAsString = attr.ToString(compiler);
        attributeList.append(Format("%s ", attrAsString.c_str()));
        if (attr.name == "prototype")
            isPrototype = true;
    }

    // format function with all attributes and parameters
    std::string functionFormatted = Format("%s%s %s(%s)", attributeList.c_str(), this->returnType.c_str(), this->name.c_str(), paramList.c_str());
    this->signature = functionFormatted;

    // if prototype, add as an ordinary symbol
    if (isPrototype)
    {
        return compiler->AddSymbol(this->name, this, false);
    }
    else
    {
        // find functions with similar name
        std::pair<Compiler::SymbolIterator, Compiler::SymbolIterator> matchingFunctions = compiler->GetSymbols(this->name);
        for (auto it = matchingFunctions.first; it != matchingFunctions.second; it++)
        {
            Function* otherFunction = static_cast<Function*>(it->second);

            if (!this->IsCompatible(otherFunction, false))
                continue;

            // if all checks prove these functions are identical, throw error
            if (this->returnType != otherFunction->returnType)
                compiler->Error(Format("Function '%s' can not be overloaded because it only differs by return type when trying to overload previous definition at %s(%d)", functionFormatted.c_str(), otherFunction->location.file.c_str(), otherFunction->location.line), this);
            else
                compiler->Error(Format("Function '%s' redefinition, previous definition at %s(%d)", functionFormatted.c_str(), otherFunction->location.file.c_str(), otherFunction->location.line), this);

            return false;
        }
    }

    // if we didn't fault, add the symbol
    return compiler->AddSymbol(this->name, this, true);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Function::IsCompatible(Function* otherFunction, bool checkReturnType)
{
    // no match if return types differ
    if (checkReturnType)
    {
        if (otherFunction->returnType != this->returnType)
            return false;
    }

    // no match if amount of parameters differ
    if (otherFunction->parameters.size() != this->parameters.size())
        return false;

    // go through parameters
    for (size_t i = 0; i < this->parameters.size(); i++)
    {
        Variable* ourParameter = this->parameters[i];
        Variable* otherParameter = otherFunction->parameters[i];

        if (ourParameter->type != otherParameter->type)
            return false;
    }

    return true;
}

} // namespace AnyFX
