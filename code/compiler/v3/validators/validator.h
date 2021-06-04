#pragma once
//------------------------------------------------------------------------------
/**
    The validator performs type checking and other validation.
    It provides a set of function pointers for validation, which the implementations bind

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "ast/symbol.h"
#include <set>
#include <map>
#include <vector>
namespace AnyFX
{

struct Compiler;
struct Expression;
struct Statement;
struct Validator
{
    /// constructor
    Validator();

    /// resolve
    bool Resolve(Compiler* compiler, const std::vector<Symbol*>& symbols);

    /// resolve alias
    bool ResolveAlias(Compiler* compiler, Symbol* symbol);
    /// resolve type
    bool ResolveType(Compiler* compiler, Symbol* symbol);
    /// resolve blend state
    bool ResolveSamplerState(Compiler* compiler, Symbol* symbol);
    /// resolve function
    bool ResolveFunction(Compiler* compiler, Symbol* symbol);
    /// resolve program
    bool ResolveProgram(Compiler* compiler, Symbol* symbol);
    /// resolve render state
    bool ResolveRenderState(Compiler* compiler, Symbol* symbol);
    /// resolve structure 
    bool ResolveStructure(Compiler* compiler, Symbol* symbol);
    /// resolve variable
    bool ResolveVariable(Compiler* compiler, Symbol* symbol);

    /// validate function
    bool ValidateFunction(Compiler* compiler, Symbol* symbol);
    /// validate program
    bool ValidateProgram(Compiler* compiler, Symbol* symbol);

    /// validate statement
    bool ValidateStatement(Compiler* compiler, Statement* statement);
    /// validate break statement
    bool ValidateBreakStatement(Compiler* compiler, Statement* statement);
    /// validate continue statement
    bool ValidateContinueStatement(Compiler* compiler, Statement* statement);
    /// validate expression statement
    bool ValidateExpressionStatement(Compiler* compiler, Statement* statement);
    /// validate for statement
    bool ValidateForStatement(Compiler* compiler, Statement* statement);
    /// validate if statement
    bool ValidateIfStatement(Compiler* compiler, Statement* statement);
    /// validate return statement
    bool ValidateReturnStatement(Compiler* compiler, Statement* statement);
    /// validate scope statement
    bool ValidateScopeStatement(Compiler* compiler, Statement* statement);
    /// validate swithc statement
    bool ValidateSwitchStatement(Compiler* compiler, Statement* statement);
    /// validate while statement
    bool ValidateWhileStatement(Compiler* compiler, Statement* statement);

    /// validate expression
    bool ValidateExpression(Compiler* compiler, Expression* expression);
    /// validate access expression
    bool ValidateAccessExpression(Compiler* compiler, Expression* expression);
    /// validate array index expression
    bool ValidateArrayIndexExpression(Compiler* compiler, Expression* expression);
    /// validate comma expression
    bool ValidateCommaExpression(Compiler* compiler, Expression* expression);
    /// validate binary expression
    bool ValidateBinaryExpression(Compiler* compiler, Expression* expression);
    /// validate call expression
    bool ValidateCallExpression(Compiler* compiler, Expression* expression);
    /// validate initializer expression
    bool ValidateInitializerExpression(Compiler* compiler, Expression* expression);
    /// validate symbol expression
    bool ValidateSymbolExpression(Compiler* compiler, Expression* expression);
    /// validate ternary expression
    bool ValidateTernaryExpression(Compiler* compiler, Expression* expression);
    /// validate unary expression
    bool ValidateUnaryExpression(Compiler* compiler, Expression* expression);

    std::set<std::string> allowedReadWriteTextureAttributes;
    std::set<std::string> allowedTextureAttributes;
    std::set<std::string> allowedSampledTextureAttributes;
    std::set<std::string> allowedSamplerAttributes;
    std::set<std::string> allowedScalarAttributes;
    std::set<std::string> allowedPointerAttributes;

    std::set<std::string> allowedSamplerStateAttributes;
    std::set<std::string> allowedConstantBufferAttributes;
    std::set<std::string> allowedStorageBufferAttributes;

    std::set<std::string> allowedFunctionAttributes;

    std::set<std::string> allowedParameterAttributes;

    std::set<std::string> allowedStructureAttributes;

    enum ResourceIndexingMode
    {
        ResourceIndexingByType,    // resource indexing is by type, so each constant buffer, storage buffer, texture and sampler have their own set of indexes
        ResourceIndexingByGroup    // resource indexing is by group, so each resource in a group get an incremental index
    };
    ResourceIndexingMode resourceIndexingMode;
    std::map<uint32_t, uint32_t> resourceIndexCounter;
    uint8_t defaultGroup;


    uint32_t inParameterIndexCounter;
    uint32_t outParameterIndexCounter;
};

} // namespace AnyFX
