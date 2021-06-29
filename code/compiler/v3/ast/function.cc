//------------------------------------------------------------------------------
//  @file function.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "function.h"
#include "util.h"
#include "variable.h"
#include "types/type.h"
#include "compiler.h"

#define __BEGIN_INTRINSICS__ std::map<std::string, Symbol*> functions; Function* newFunction = nullptr;
#define __MAKE_INTRINSIC(funName, retType) newFunction = new Function(); newFunction->name = #funName; newFunction->returnType = { #retType };
#define __ADD_PARAM(paramName, paramType) Variable* var = new Variable(); var->type = { #paramType }; var->name = #paramName; newFunction->parameters.push_back(var);
#define __ADD_LOOKUP(name) functions[#name] = newFunction;
#define __END_LOOKUP__ return functions;

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
std::map<std::string, Symbol*> 
Function::SetupIntrinsics()
{
    __BEGIN_INTRINSICS__


    __END_LOOKUP__
}

//------------------------------------------------------------------------------
/**
*/
Symbol*
Function::MatchOverload(Compiler* compiler, const std::vector<Symbol*>& functions, const std::vector<Type::FullType>& args, bool allowImplicitConversion)
{
    Symbol* ret = nullptr;
    for (Symbol* sym : functions)
    {
        // presume nothing
        if (sym->symbolType != SymbolType::FunctionType)
            continue;

        Function* fun = static_cast<Function*>(sym);
        if (fun->parameters.size() != args.size())
            continue;

        ret = sym;
        for (size_t i = 0; i < args.size() && ret != nullptr; i++)
        {
            if (args[i] != fun->parameters[i]->type)
            {
                if (allowImplicitConversion)
                {
                    // types don't match, check if there is a constructor for this argument which matches the input argument
                    Type* argType = compiler->GetSymbol<Type>(fun->parameters[i]->type.name);
                    std::vector<Symbol*> conversionMethods = argType->GetSymbols(argType->name);

                    ret = nullptr;
                    for (size_t j = 0; j < conversionMethods.size(); j++)
                    {
                        Function* conv = static_cast<Function*>(conversionMethods[j]);
                        if (conv->symbolType != SymbolType::FunctionType)
                            continue;

                        if (conv->parameters.size() != 1)
                            continue;

                        if (conv->parameters[0]->type == args[i])
                        {
                            // okay, conversion found so move to next argument in outer loop
                            ret = sym;
                            break;
                        }
                    }
                }
                else
                {
                    ret = nullptr;
                }
            }
        }

        // if ret kept itself from being unset, return it as it's a match
        if (ret != nullptr)
            return ret;
    }
    return ret;
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
