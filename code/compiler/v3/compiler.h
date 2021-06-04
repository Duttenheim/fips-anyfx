#pragma once
//------------------------------------------------------------------------------
/**
    Compiler frontend

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <utility>
#include "ast/symbol.h"
#include "ast/effect.h"
#include "validators/validator.h"
#include "generators/generator.h"
#include "binwriter.h"
#include "textwriter.h"
#include "serialize.h"
namespace AnyFX
{

struct Type;
struct Compiler
{
    enum class Language : uint8_t
    {
        GLSL,
        GLSL_SPIRV, // uses GLSL as intermediate to generate spirv
        HLSL,
        HLSL_SPIRV, // uses HLSL as intermediate to generate spirv
        SPIRV       // target is pure SPIRV
    };

    /// constructor
    Compiler();
    /// destructor
    ~Compiler();

    /// setup compiler with target language
    void Setup(const Compiler::Language& lang, const std::vector<std::string>& defines, unsigned int version);

    /// adds symbol to compiler context, allow duplicate if symbol type should support overloading
    bool AddSymbol(const std::string& name, Symbol* symbol, bool allowDuplicate = false);
    /// get symbol by name
    Symbol* GetSymbol(const std::string& name) const;
    /// get symbol by name as other type
    template <typename T> T* GetSymbol(const std::string& name) const;
    /// return iterator to first and last symbol matching name
    std::vector<Symbol*> GetSymbols(const std::string& name) const;
    

    struct Scope
    {
        enum class Type
        {
            Global,
            Local
        };
        Type type = Type::Local;
        std::vector<Symbol*> symbols;
        std::multimap<std::string, Symbol*> symbolLookup;
        Symbol* owningSymbol;
    };
    /// create new scope and push it to the stack
    void PushScope(Scope::Type type, Symbol* owner = nullptr);
    /// pop the scope
    void PopScope();
    /// current scope global
    bool IsScopeGlobal();
    /// get scope owner
    Symbol* GetScopeOwner();

    /// runs the validation and generation steps, returns true if successful, otherwise false and a list of error messages
    bool Compile(Effect* root, BinWriter& binaryWriter, TextWriter& headerWriter);

    /// produce error in compiler with explicit file, line and column
    void Error(const std::string& msg, const std::string& file, int line, int column);
    /// produce error in compiler from symbol
    void Error(const std::string& msg, const Symbol* sym);
    /// produce error in compiler with explicit file, line and column
    void Warning(const std::string& msg, const std::string& file, int line, int column);
    /// produce error in compiler from symbol
    void Warning(const std::string& msg, const Symbol* sym);
    /// produce an internal generator error
    void GeneratorError(const std::string& msg);

    /// helper for unrecognized type error
    void UnrecognizedTypeError(const std::string& type, Symbol* sym);

    /// output binary data
    void OutputBinary(Symbol* symbol, BinWriter& writer, Serialize::DynamicLengthBlob& dynamicDataBlob);

    std::vector<std::string> defines;
    std::vector<std::string> errors;
    std::vector<std::string> warnings;

    Validator* validator = nullptr;
    Generator* generator = nullptr;
    Generator* headerGenerator = nullptr;

    std::vector<Scope*> scopes;

    struct TypeScope
    {
        TypeScope(Compiler* compiler, Type* type)
        {
            this->compiler = compiler;
            this->oldType = this->compiler->typeScope;
            this->compiler->typeScope = type;
        }

        ~TypeScope()
        {
            this->compiler->typeScope = this->oldType;
        }

        Compiler* compiler;
        Type* oldType;
    };
    Type* typeScope;

    std::string debugPath;
    bool debugOutput;
};

//------------------------------------------------------------------------------
/**
*/
template <typename K> inline bool
set_contains(const std::set<K>& set, const K& key)
{
    return set.find(key) != set.end();
}

//------------------------------------------------------------------------------
/**
*/
template <typename K> inline bool
set_contains(const std::set<K>& set, const std::set<K>& otherSet)
{
    for (const K& key : otherSet)
        if (set.find(key) != set.end())
            return true;
    return false;
}

//------------------------------------------------------------------------------
/**
*/
template <typename K, typename T> inline bool
map_contains(const std::map<K, T>& map, const K& key)
{
    return map.find(key) != map.end();
}

//------------------------------------------------------------------------------
/**
*/
template <typename K, typename T> inline bool
map_contains(const std::unordered_map<K, T>& map, const K& key)
{
    return map.find(key) != map.end();
}

//------------------------------------------------------------------------------
/**
*/
template <typename T>
inline constexpr T min(T a, T b)
{
    return a < b ? a : b;
}

//------------------------------------------------------------------------------
/**
*/
template <typename T, typename T2>
inline constexpr T min(T a, T2 b)
{
    return a < b ? a : b;
}

//------------------------------------------------------------------------------
/**
*/
template <typename T>
inline T*
Compiler::GetSymbol(const std::string& name) const
{
    return static_cast<T*>(this->GetSymbol(name));
}

} // namespace AnyFX
