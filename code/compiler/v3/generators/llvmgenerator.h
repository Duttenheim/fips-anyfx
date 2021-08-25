#pragma once
//------------------------------------------------------------------------------
/**
    Generates LLVM output from frontend

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "generator.h"
#include "llvm/IR/IRBuilder.h"

namespace AnyFX
{

class LLVMGenerator : public Generator
{

public:
    enum class Backend
    {
        SPIRV,
        AMDGPU
    };

    /// constructor
    LLVMGenerator(Backend backend);

    /// generate LLVM
    bool Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc) override;

    /// generate function
    void GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode);
    /// generate structure 
    void GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode);
    /// generate variable
    void GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument);

    Backend backend;
    llvm::Module* mod;
    llvm::LLVMContext ctx;
    llvm::IRBuilder<> builder;
};

} // namespace AnyFX
