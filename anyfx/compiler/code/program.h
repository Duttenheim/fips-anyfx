#pragma once
//------------------------------------------------------------------------------
/**
    @class Program
    
    A program denotes a complete set of shaders, render states and defines.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <string>
#include <vector>
#include <map>
#include "symbol.h"
#include "renderstate.h"
#include "programrow.h"
#include "annotation.h"
#include "shader.h"
namespace AnyFX
{

class Program : public Symbol
{
public:
    /// constructor
    Program();
    /// destructor
    virtual ~Program();

    /// set annotation
    void SetAnnotation(const Annotation& annotation);
    /// consumes a single program row
    void ConsumeRow(const ProgramRow& row);

    /// type checks function linkage
    void TypeCheck(TypeChecker& typechecker);
    /// generate program
    void Generate(Generator& generator);
    /// compiles program
    void Compile(BinWriter& writer);
    /// get binary representation for shader
    const std::vector<unsigned>& GetBinary(unsigned shader);

private:
    friend class Effect;

    /// constructs a shader function using the given functions
    void BuildShaders(
        const Header& header
        , Allocator& alloc
        , unsigned& programIndex
        , const std::vector<Function*>& functions
        , std::vector<Symbol*>& symbols
        , std::map<std::string, Shader*>& shaders);
    /// writes binary to file
    void WriteBinary(const std::vector<unsigned>& binary, BinWriter& writer);

#pragma region OpenGL
    /// generates GLSL4 target code
    void LinkGLSL4(Generator& generator, Shader* const* shaders, unsigned numShaders);
    /// generates GLSL3 target code
    void LinkGLSL3(Generator& generator, Shader* const* shaders, unsigned numShaders);

    /// output AnyFX formatted GLSL problem using the Khronos syntax
    void GLSLProblemKhronos(Generator& generator, std::stringstream& stream);
#pragma endregion

#pragma region Vulkan
    /// Link with SPIRV
    void LinkSPIRV(Generator& generator, Shader* const* shaders, unsigned numShaders);
#pragma endregion

#pragma region DirectX
    /// generates HLSL5 target code
    void LinkHLSL5(Generator& generator, Shader* const* shaders, unsigned numShaders);
    /// generates HLSL4 target code
    void LinkHLSL4(Generator& generator, Shader* const* shaders, unsigned numShaders);
    /// generates HLSL3 target code
    void LinkHLSL3(Generator& generator, Shader* const* shaders, unsigned numShaders);
#pragma endregion

    std::vector<std::string> invalidFlags;
    std::vector<std::string> slotNames;
    bool slotMask[ProgramRow::NumProgramRows];
    std::map<std::string, std::string> slotSubroutineMappings[ProgramRow::NumProgramRows-1];
    Shader* shaders[ProgramRow::NumProgramRows-1];
    std::vector<unsigned> binary[ProgramRow::NumProgramRows-1];
    unsigned patchSize;

    std::vector<std::string> activeUniforms;
    std::vector<std::string> activeUniformBlocks;
    std::map<std::string, unsigned> uniformBufferOffsets;
    std::map<std::string, unsigned> storageBufferOffsets;

    bool hasAnnotation;
    Annotation annotation;
}; 


//------------------------------------------------------------------------------
/**
*/
inline void 
Program::SetAnnotation( const Annotation& annotation )
{
    this->annotation = annotation;
    this->hasAnnotation = true;
}

} // namespace AnyFX
//------------------------------------------------------------------------------
