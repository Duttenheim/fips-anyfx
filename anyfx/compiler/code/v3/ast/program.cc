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
}

const std::map<std::string, Program::__Resolved::ProgramEntryType> programEntryTypeLookup =
{
    { "VertexShader", Program::__Resolved::VertexShader }
    , { "HullShader", Program::__Resolved::HullShader }
    , { "DomainShader", Program::__Resolved::DomainShader }
    , { "GeometryShader", Program::__Resolved::GeometryShader }
    , { "PixelShader", Program::__Resolved::PixelShader }
    , { "ComputeShader", Program::__Resolved::ComputeShader }
    , { "RayMissShader", Program::__Resolved::RayMissShader }
    , { "RayHitShader", Program::__Resolved::RayHitShader }
    , { "RayAnyHitShader", Program::__Resolved::RayAnyHitShader }
    , { "RayIntersectionShader", Program::__Resolved::RayIntersectionShader }
    , { "BlendState", Program::__Resolved::BlendState }
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
        return Program::__Resolved::ProgramEntryType::InvalidEntryType;

}

} // namespace AnyFX
