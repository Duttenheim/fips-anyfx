//------------------------------------------------------------------------------
//  @file llvmgenerator.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "llvmgenerator.h"
#include "llvm/IR/IntrinsicsGPULang.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
LLVMGenerator::LLVMGenerator(Backend backend) :
    builder(ctx)
{
    this->mod = new llvm::Module("anyfx", this->ctx);
}

const std::map<std::string, uint64_t> intrinsicToLLVMId =
{
    { "mad", llvm::Intrinsic::GPULANGIntrinsics::gpulang_mul_add }
    , { "abs", llvm::Intrinsic::GPULANGIntrinsics::gpulang_abs }
};

//------------------------------------------------------------------------------
/**
*/
bool 
LLVMGenerator::Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc)
{
    llvm::Function* mad = llvm::Intrinsic::getDeclaration(this->mod, llvm::Intrinsic::GPULANGIntrinsics::gpulang_mul_add);
    return false;
}

//------------------------------------------------------------------------------
/**
*/
void 
LLVMGenerator::GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
LLVMGenerator::GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
LLVMGenerator::GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument)
{
}

} // namespace AnyFX
