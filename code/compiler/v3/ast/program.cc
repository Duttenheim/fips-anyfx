//------------------------------------------------------------------------------
//  @file program.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "program.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
Program::Program()
{
    this->symbolType = ProgramType;
    this->resolved = new Program::__Resolved();
    Program::__Resolved* progResolved = static_cast<Program::__Resolved*>(this->resolved);
    progResolved->usage.bits = 0x0;
}

const std::map<std::string, Program::__Resolved::ProgramEntryType> programEntryTypeLookup =
{
    { "VertexShader", Program::__Resolved::VertexShader }
    , { "HullShader", Program::__Resolved::HullShader }
    , { "TessellationControlShader", Program::__Resolved::HullShader }
    , { "DomainShader", Program::__Resolved::DomainShader }
    , { "TessellationEvaluationShader", Program::__Resolved::DomainShader }
    , { "GeometryShader", Program::__Resolved::GeometryShader }
    , { "PixelShader", Program::__Resolved::PixelShader }
    , { "ComputeShader", Program::__Resolved::ComputeShader }
    , { "RayGenerationShader", Program::__Resolved::RayGenerationShader }
    , { "RayMissShader", Program::__Resolved::RayMissShader }
    , { "RayHitShader", Program::__Resolved::RayHitShader }
    , { "RayClosestHitShader", Program::__Resolved::RayClosestHitShader }
    , { "RayAnyHitShader", Program::__Resolved::RayAnyHitShader }
    , { "RayIntersectionShader", Program::__Resolved::RayIntersectionShader }
    , { "RenderState", Program::__Resolved::RenderState }

};

//------------------------------------------------------------------------------
/**
*/
const Program::__Resolved::ProgramEntryType 
Program::__Resolved::StringToEntryType(const std::string& str)
{
    auto it = programEntryTypeLookup.find(str);
    if (it != programEntryTypeLookup.end())
        return it->second;
    else
        return Program::__Resolved::ProgramEntryType::InvalidProgramEntryType;

}

//------------------------------------------------------------------------------
/**
*/
const std::string&
Program::__Resolved::EntryTypeToString(const ProgramEntryType type)
{
    static std::string default = "";
    for (auto& it : programEntryTypeLookup)
    {
        if (it.second == type)
            return it.first;
    }
    return default;
}

} // namespace AnyFX
