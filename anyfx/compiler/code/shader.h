
#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::Shader
    
    A shader represents a composed target-language representation of a function.

    Its main responsibilities is to format a given function, 
    variable list and external functions, 
    into something a target language shader compiler can understand.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <string>
#include "function.h"
#include "variable.h"
#include "header.h"
#include "symbol.h"
#include "glslang/Public/ShaderLang.h"


namespace AnyFX
{
class Variable;
class Structure;
class VarBlock;
class Function;
class Constant;
class VarBuffer;
class Subroutine;
class Sampler;
class Shader : public Symbol
{
public:
    
    /// constructor
    Shader();
    /// destructor
    virtual ~Shader();

    /// Destroy
    void Destroy() override;

    /// sets the shader type
    void SetType(const unsigned type);
    /// gets the shader type
    unsigned GetType() const;
    /// sets the function object which this shader will use as its main entry point
    void SetFunction(Function* func);
    /// gets the function
    Function* GetFunction() const;
    /// sets shader name
    void SetName(const std::string& name);
    /// gets shader name
    const std::string& GetName() const;

    /// returns formatted code, is only viable after compilation is done
    const std::string& GetCompiledCode() const;

    /// set subroutine mappings
    void SetSubroutineMappings(const std::map<std::string, std::string>& subroutineMappings);

    /// type check shader
    void TypeCheck(TypeChecker& typechecker);
    /// compile shader
    void Compile(BinWriter& writer);

    /// sets up shader
    void Setup();
    /// generates code for shader
    void Generate(Generator& generator, const std::vector<Symbol*>& symbols);

    /// static function which resets all bindings
    static void ResetBindings();

    // each binding index is a slot for a descriptor set in Vulkan, or is statically assigned in other languages
    /*
        0: varblocks
        1: varbuffers
        2: samplers (texture-sampler combos)
        3: images (read-write textures)
        4: sampler objects
    */
    static unsigned long long bindingIndices[8]; 

    static unsigned long long ConsumeNewBinding(unsigned group);
    static void SetBinding(unsigned group, unsigned binding);
private:
    friend class Program;

#pragma region GLSL
    std::string GenerateGLSL(AnyFX::Generator* generator, int major, int minor);

    // sub generation functions
    std::string GenerateGLSL4(AnyFX::Generator* generator);
    std::string GenerateGLSL3(AnyFX::Generator* generator);
#pragma endregion

#pragma region HLSL
    std::string GenerateHLSL(AnyFX::Generator* generator, int major, int minor);
    std::string GenerateHLSL5(AnyFX::Generator* generator);
    std::string GenerateHLSL4(AnyFX::Generator* generator);
#pragma endregion

    std::string GenerateSPIRV(AnyFX::Generator* generator, int major, int minor);
    std::string GenerateMetal(AnyFX::Generator* generator, int major, int minor);

#pragma region OpenGL
    /// compiles the generated code to check for validation in GLSL
    void CompileGLSL(const std::string& code, Generator* generator);
    /// compiles the generated code to check for validation in GLSL
    void CompileSPIRV(const std::string& code, Generator* generator);

    /// generates GLSL4 target code
    void GenerateGLSL4(Generator& generator);
    /// generates GLSL3 target code
    void GenerateGLSL3(Generator& generator);

#pragma endregion

#pragma region DirectX
    /// generates HLSL5 target code
    void GenerateHLSL5(Generator& generator);
    /// generates HLSL4 target code
    void GenerateHLSL4(Generator& generator);
    /// generates HLSL3 target code
    void GenerateHLSL3(Generator& generator);
#pragma endregion

    Function* func;
    unsigned shaderType;
    std::string name;
    std::string formattedCode;
    unsigned codeOffset;

    glslang::TShader* glslShader;
    void* hlslShader;
    char* binary;
    unsigned binarySize;
    bool binaryValid;

    std::string preamble;
    std::map<int, std::pair<std::string, std::string> > indexToFileMap;
    std::map<std::string, std::string> subroutineMappings;

}; 

//------------------------------------------------------------------------------
/**
*/
inline void
Shader::SetFunction(Function* func)
{
    this->func = new Function();
    *this->func = *func;
}

//------------------------------------------------------------------------------
/**
*/
inline Function* 
Shader::GetFunction() const
{
    return this->func;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
Shader::SetName(const std::string& name)
{
    this->name = name;
    this->func->SetName(name);
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string& 
Shader::GetName() const
{
    return this->name;
}

//------------------------------------------------------------------------------
/**
*/
inline const std::string&
Shader::GetCompiledCode() const
{
    return this->formattedCode;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
Shader::SetType( const unsigned type )
{
    this->shaderType = type;
}

//------------------------------------------------------------------------------
/**
*/
inline unsigned 
Shader::GetType() const
{
    return this->shaderType;
}

//------------------------------------------------------------------------------
/**
*/
inline void
Shader::SetSubroutineMappings(const std::map<std::string, std::string>& subroutineMappings)
{
    this->subroutineMappings = subroutineMappings;
}

//------------------------------------------------------------------------------
/**
*/
inline void
Shader::ResetBindings()
{
    // Reset all bindings to 1's, when a binding is consumed, its bit gets flipped
    memset(Shader::bindingIndices, 0xFF, sizeof(Shader::bindingIndices));
}

//------------------------------------------------------------------------------
/**
*/
inline unsigned long long 
Shader::ConsumeNewBinding(unsigned group)
{
    unsigned long long binding = FirstOne(Shader::bindingIndices[group]);
    SetBinding(group, binding);
    return binding;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
Shader::SetBinding(unsigned group, unsigned binding)
{
    Shader::bindingIndices[group] &= ~(1 << binding);
}

} // namespace AnyFX
//------------------------------------------------------------------------------
