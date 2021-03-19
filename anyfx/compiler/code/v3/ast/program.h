#pragma once
//------------------------------------------------------------------------------
/**
    AST for Program

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <vector>
#include <unordered_map>
#include <string>
#include "annotations.h"
#include "symbol.h"
namespace AnyFX
{

struct Program : public Symbol
{
    /// constructor
    Program();

    struct SubroutineMapping
    {
        std::string name;
        std::string value;
    };
    struct Entry
    {
        std::string name;
        std::string value;
        std::vector<SubroutineMapping> subroutines;
    };
    std::vector<Entry> entries;
    Annotations annotations;

    struct __Resolved : public Symbol::__Resolved
    {
        enum ProgramEntryType
        {
            InvalidEntryType,
            VertexShader,
            HullShader,
            DomainShader,
            GeometryShader,
            PixelShader,
            ComputeShader,
            RayMissShader,
            RayHitShader,
            RayAnyHitShader,
            RayIntersectionShader,
            BlendState,
            RenderState
        };

        /// convert from string to program entry type
        static const ProgramEntryType StringToEntryType(const std::string& str);

        std::unordered_map<ProgramEntryType, Symbol*> programMappings;
    };

};

extern const std::map<std::string, Program::__Resolved::ProgramEntryType> programEntryTypeLookup;

} // namespace AnyFX
