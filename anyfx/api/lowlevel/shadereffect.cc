//------------------------------------------------------------------------------
// shadereffect.cc
// (C) 2016 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "shadereffect.h"
#include <assert.h>
#include <limits.h>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ShaderEffect::ShaderEffect()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
ShaderEffect::~ShaderEffect()
{
	unsigned i;
	for (i = 0; i < this->programsByIndex.size(); i++) this->programsByIndex[i]->~ProgramBase();
	for (i = 0; i < this->shadersByIndex.size(); i++) this->shadersByIndex[i]->~ShaderBase();
	for (i = 0; i < this->variablesByIndex.size(); i++) this->variablesByIndex[i]->~VariableBase();
	for (i = 0; i < this->renderstatesByIndex.size(); i++) this->renderstatesByIndex[i]->~RenderStateBase();
	for (i = 0; i < this->subroutinesByIndex.size(); i++) this->subroutinesByIndex[i]->~SubroutineBase();
    for (i = 0; i < this->varblocksByIndex.size(); i++) this->varblocksByIndex[i]->~VarblockBase();
	for (i = 0; i < this->varbuffersByIndex.size(); i++) this->varbuffersByIndex[i]->~VarbufferBase();
	for (i = 0; i < this->samplersByIndex.size(); i++) this->samplersByIndex[i]->~SamplerBase();
}

//------------------------------------------------------------------------------
/**
*/
Allocator& 
ShaderEffect::GetAlloc()
{
    return this->alloc;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumPrograms() const
{
	return this->programs.size();
}

//------------------------------------------------------------------------------
/**
*/
ProgramBase*
ShaderEffect::GetProgram(const unsigned i) const
{
	return this->programsByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
ProgramBase*
ShaderEffect::GetProgram(const std::string& name) const
{
	const auto it = this->programs.find(name);
	assert(it != this->programs.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<ProgramBase*>&
ShaderEffect::GetPrograms() const
{
	return this->programsByIndex;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasProgram(const std::string& name) const
{
	return this->programs.find(name) != this->programs.end();
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumShaders() const
{
	return this->shaders.size();
}

//------------------------------------------------------------------------------
/**
*/
ShaderBase*
ShaderEffect::GetShader(const unsigned i) const
{
	return this->shadersByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
ShaderBase*
ShaderEffect::GetShader(const std::string& name) const
{
	const auto it = this->shaders.find(name);
	assert(it != this->shaders.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<ShaderBase*>&
ShaderEffect::GetShaders() const
{
	return this->shadersByIndex;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasShader(const std::string& name) const
{
	return this->shaders.find(name) != this->shaders.end();
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumRenderStates() const
{
	return this->renderstates.size();
}

//------------------------------------------------------------------------------
/**
*/
RenderStateBase*
ShaderEffect::GetRenderState(const unsigned i) const
{
	return this->renderstatesByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
RenderStateBase*
ShaderEffect::GetRenderState(const std::string& name) const
{
	const auto it = this->renderstates.find(name);
	assert(it != this->renderstates.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<RenderStateBase*>&
ShaderEffect::GetRenderStates() const
{
	return this->renderstatesByIndex;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasRenderState(const std::string& name) const
{
	return this->renderstates.find(name) != this->renderstates.end();
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumVariables() const
{
	return this->variables.size();
}

//------------------------------------------------------------------------------
/**
*/
VariableBase*
ShaderEffect::GetVariable(const unsigned i) const
{
	return this->variablesByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
VariableBase*
ShaderEffect::GetVariable(const std::string& name) const
{
	const auto it = this->variables.find(name);
	assert(it != this->variables.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<VariableBase*>&
ShaderEffect::GetVariables() const
{
	return this->variablesByIndex;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<VariableBase*>&
ShaderEffect::GetVariables(const unsigned group) const
{
	const auto it = this->variablesByGroup.find(group);
	assert(it != this->variablesByGroup.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasVariable(const std::string& name) const
{
	return this->variables.find(name) != this->variables.end();
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasVariables(const unsigned group) const
{
	const auto it = this->variablesByGroup.find(group);
	return it != this->variablesByGroup.end();
}

//------------------------------------------------------------------------------
/**
*/
const unsigned 
ShaderEffect::FindVariable(const std::string& name) const
{
	const auto it = this->variables.find(name);
	if (it == this->variables.end())	return UINT_MAX;
	else								return std::distance(this->variables.begin(), it);
}

//------------------------------------------------------------------------------
/**
*/
VariableBase*
ShaderEffect::GetVariableFromMap(const unsigned idx) const
{
	auto it = this->variables.begin();
	std::advance(it, idx);
	return (*it).second;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumVarblocks() const
{
	return this->varblocks.size();
}

//------------------------------------------------------------------------------
/**
*/
VarblockBase*
ShaderEffect::GetVarblock(const unsigned i) const
{
	return this->varblocksByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
VarblockBase*
ShaderEffect::GetVarblock(const std::string& name) const
{
	const auto it = this->varblocks.find(name);
	assert(it != this->varblocks.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<VarblockBase*>&
ShaderEffect::GetVarblocks() const
{
	return this->varblocksByIndex;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<VarblockBase*>&
ShaderEffect::GetVarblocks(const unsigned group) const
{
	const auto it = this->varblocksByGroup.find(group);
	assert(it != this->varblocksByGroup.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasVarblock(const std::string& name) const
{
	return this->varblocks.find(name) != this->varblocks.end();
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasVarblocks(const unsigned group) const
{
	const auto it = this->varblocksByGroup.find(group);
	return it != this->varblocksByGroup.end();
}

//------------------------------------------------------------------------------
/**
*/
const unsigned
ShaderEffect::FindVarblock(const std::string& name) const
{
	const auto it = this->varblocks.find(name);
	if (it == this->varblocks.end())	return UINT_MAX;
	else								return std::distance(this->varblocks.begin(), it);
}

//------------------------------------------------------------------------------
/**
*/
VarblockBase* 
ShaderEffect::GetVarblockFromMap(const unsigned idx) const
{
	auto it = this->varblocks.begin();
	std::advance(it, idx);
	return (*it).second;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumVarbuffers() const
{
	return this->varbuffers.size();
}

//------------------------------------------------------------------------------
/**
*/
VarbufferBase*
ShaderEffect::GetVarbuffer(const unsigned i) const
{
	return this->varbuffersByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
VarbufferBase*
ShaderEffect::GetVarbuffer(const std::string& name) const
{
	const auto it = this->varbuffers.find(name);
	assert(it != this->varbuffers.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<VarbufferBase*>&
ShaderEffect::GetVarbuffers() const
{
	return this->varbuffersByIndex;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<VarbufferBase*>&
ShaderEffect::GetVarbuffers(const unsigned group) const
{
	const auto it = this->varbuffersByGroup.find(group);
	assert(it != this->varbuffersByGroup.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasVarbuffer(const std::string& name) const
{
	return this->varbuffers.find(name) != this->varbuffers.end();
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasVarbuffers(const unsigned group) const
{
	const auto it = this->varbuffersByGroup.find(group);
	return it != this->varbuffersByGroup.end();
}

//------------------------------------------------------------------------------
/**
*/
const unsigned
ShaderEffect::FindVarbuffer(const std::string& name) const
{
	const auto it = this->varbuffers.find(name);
	if (it == this->varbuffers.end())	return UINT_MAX;
	else								return std::distance(this->varbuffers.begin(), it);
}

//------------------------------------------------------------------------------
/**
*/
VarbufferBase*
ShaderEffect::GetVarbufferFromMap(const unsigned idx) const
{
	auto it = this->varbuffers.begin();
	std::advance(it, idx);
	return (*it).second;
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumSubroutines() const
{
	return this->subroutines.size();
}

//------------------------------------------------------------------------------
/**
*/
SubroutineBase*
ShaderEffect::GetSubroutineByName(const unsigned i) const
{
	return this->subroutinesByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
SubroutineBase*
ShaderEffect::GetSubroutineByName(const std::string& name) const
{
	const auto it = this->subroutines.find(name);
	assert(it != this->subroutines.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<SubroutineBase*>&
ShaderEffect::GetSubroutines() const
{
	return this->subroutinesByIndex;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasSubroutine(const std::string& name) const
{
	return this->subroutines.find(name) != this->subroutines.end();
}

//------------------------------------------------------------------------------
/**
*/
unsigned
ShaderEffect::GetNumSamplers() const
{
	return this->samplers.size();
}

//------------------------------------------------------------------------------
/**
*/
SamplerBase*
ShaderEffect::GetSampler(const unsigned i) const
{
	return this->samplersByIndex[i];
}

//------------------------------------------------------------------------------
/**
*/
SamplerBase*
ShaderEffect::GetSampler(const std::string& name) const
{
	const auto it = this->samplers.find(name);
	assert(it != this->samplers.end());
	return it->second;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<SamplerBase*>&
ShaderEffect::GetSamplers() const
{
	return this->samplersByIndex;
}

//------------------------------------------------------------------------------
/**
*/
bool
ShaderEffect::HasSampler(const std::string& name) const
{
	return this->samplers.find(name) != this->samplers.end();
}

} // namespace AnyFX