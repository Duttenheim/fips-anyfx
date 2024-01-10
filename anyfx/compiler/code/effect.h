#pragma once
//------------------------------------------------------------------------------
/**
    @class Effect
    
    Main parser entry point, contains complete effect.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <vector>
#include <map>
#include "header.h"
#include "program.h"
#include "variable.h"
#include "renderstate.h"
#include "function.h"
#include "structure.h"
#include "varblock.h"
#include "varbuffer.h"
#include "subroutine.h"
#include "compileable.h"
#include "sampler.h"
#include "util/code/textwriter.h"
#include "allocator.h"
namespace AnyFX
{

class Effect : public Compileable
{
public:

    /// constructor
    Effect();
    /// destructor
    virtual ~Effect();

    /// sets the header object
    void SetHeader(const Header& header);
    /// gets the header object
    const Header& GetHeader() const;

    /// add program definition
    void AddProgram(Program* program);
    /// add variable definition
    void AddVariable(Variable* var);
    /// add render state
    void AddRenderState(RenderState* state);
    /// add function
    void AddFunction(Function* function);
    /// add structure
    void AddStructure(Structure* structure);
    /// add varblock
    void AddVarBlock(VarBlock* varBlock);
    /// add varbuffer
    void AddVarBuffer(VarBuffer* varBuffer);
    /// add subroutine
    void AddSubroutine(Subroutine* subroutine);
    /// add sampler
    void AddSampler(Sampler* sampler);

    /// sets up effect using given header
    void Setup();
    /// type check effect
    void TypeCheck(TypeChecker& typechecker);
    /// generates code
    void Generate(Generator& generator);
    /// compile effect
    void Compile(BinWriter& writer);
    /// generate header file
    void GenerateHeader(TextWriter& writer);

    /// set debug output
    void SetDebugOutputPath(const std::string& debugOutput);
    /// set name of effect
    void SetName(const std::string& name);
    /// set resource table name
    void SetResourceTableName(const unsigned slot, const std::string& name);

    /// round to pow 2
    static unsigned RoundToPow2(unsigned number, unsigned power);
    /// calculate offset of variable using shared/std140 declared in GLSL/SPIR-V
    static void GetAlignmentGLSL(const DataType& type, unsigned arraySize, unsigned& size, unsigned& alignment, const bool std140, const bool structMember, TypeChecker& typechecker);

private:
    Header header;
    std::string name;
    std::vector<Symbol*> symbols;
    std::vector<Symbol*> subroutinesToDelete;
    std::vector<Symbol*> functionsToDelete;

    std::map<std::string, Shader*> shaders;
    std::map<unsigned, std::string> resourceTableNames;

    RenderState* placeholderRenderState;
    VarBlock* placeholderVarBlock;

    Allocator alloc;

    std::string debugOutput;
}; 

//------------------------------------------------------------------------------
/**
*/
inline void 
Effect::SetHeader(const Header& header)
{
    this->header = header;
}

//------------------------------------------------------------------------------
/**
*/
inline const Header&
Effect::GetHeader() const
{
    return this->header;
}

//------------------------------------------------------------------------------
/**
*/
inline void
Effect::SetDebugOutputPath(const std::string& debugOutput)
{
    this->debugOutput = debugOutput;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
Effect::SetName(const std::string & name)
{
    this->name = name;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
Effect::SetResourceTableName(const unsigned slot, const std::string& name)
{
    this->resourceTableNames[slot] = name;
}

} // namespace AnyFX
//------------------------------------------------------------------------------