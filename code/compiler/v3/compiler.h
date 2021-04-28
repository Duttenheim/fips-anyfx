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

    /// setup compiler with target language
    void Setup(const Compiler::Language& lang, const std::vector<std::string>& defines, unsigned int version);

    /// adds symbol to compiler context, allow duplicate if symbol type should support overloading
    bool AddSymbol(const std::string& name, Symbol* symbol, bool allowDuplicate = false);
    /// get symbol by name
    Symbol* GetSymbol(const std::string& name) const;
    /// return iterator to first and last symbol matching name
    typedef std::multimap<std::string, Symbol*>::const_iterator SymbolIterator;
    std::pair<SymbolIterator, SymbolIterator> GetSymbols(const std::string& name) const;

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

    /// output binary data
    void OutputBinary(Symbol* symbol, BinWriter& writer, Serialize::DynamicLengthBlob& dynamicDataBlob);

    std::vector<Symbol*> symbols;
    std::multimap<std::string, Symbol*> symbolLookup;
    std::vector<std::string> defines;
    std::vector<std::string> errors;
    std::vector<std::string> warnings;

    Validator* validator = nullptr;
    Generator* generator = nullptr;
    Generator* headerGenerator = nullptr;

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
inline constexpr T max(T a, T b)
{
    return a > b ? a : b;
}

//------------------------------------------------------------------------------
/**
*/
template <typename T, typename T2>
inline constexpr T max(T a, T2 b)
{
    return a > b ? a : b;
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


} // namespace AnyFX
