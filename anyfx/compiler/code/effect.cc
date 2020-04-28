//------------------------------------------------------------------------------
//  effect.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "./effect.h"
#include <assert.h>
#include "constant.h"
#include "generator.h"
#include <algorithm>

#define VERSION_MAJOR 2
#define VERSION_MINOR 1

#define ROUND_TO_POW(n, p) ((n + p - 1) & ~(p - 1))

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Effect::Effect()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
Effect::~Effect()
{
	unsigned i;
	for (i = 0; i < programs.size(); i++)
	{
		this->programs[i].Destroy();
	}

	for (i = 0; i < variables.size(); i++)
	{
		this->variables[i].Destroy();
	}

	for (i = 0; i < constants.size(); i++)
	{
		this->constants[i].Destroy();
	}

	for (i = 0; i < renderStates.size(); i++)
	{
		this->renderStates[i].Destroy();
	}

	for (i = 0; i < functions.size(); i++)
	{
		this->functions[i].Destroy();
	}

	for (i = 0; i < structures.size(); i++)
	{
		this->structures[i].Destroy();
	}

	for (i = 0; i < varBlocks.size(); i++)
	{
		this->varBlocks[i].Destroy();
	}

	for (i = 0; i < this->varBuffers.size(); i++)
	{
		this->varBuffers[i].Destroy();
	}

	for (i = 0; i < this->subroutines.size(); i++)
	{
		this->subroutines[i].Destroy();
	}

	for (i = 0; i < this->samplers.size(); i++)
	{
		this->samplers[i].Destroy();
	}

	// delete shaders
	std::map<std::string, Shader*>::iterator it;
	for (it = this->shaders.begin(); it != this->shaders.end(); it++)
	{
		delete it->second;
	}
	this->shaders.clear();
	this->programs.clear();
	this->variables.clear();
	this->constants.clear();
	this->renderStates.clear();
	this->functions.clear();
	this->structures.clear();
	this->varBlocks.clear();
	this->varBuffers.clear();
	this->subroutines.clear();
	this->samplers.clear();
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddProgram(const Program& program)
{
	this->programs.push_back(program);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddVariable(const Variable& var)
{
	this->variables.push_back(var);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddConstant(const Constant& constant)
{
	this->constants.push_back(constant);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddRenderState(const RenderState& state)
{
	this->renderStates.push_back(state);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddFunction(const Function& function)
{
	this->functions.push_back(function);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddStructure(const Structure& structure)
{
	this->structures.push_back(structure);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddVarBlock(const VarBlock& varBlock)
{
	this->varBlocks.push_back(varBlock);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddVarBuffer(const VarBuffer& varBuffer)
{
    this->varBuffers.push_back(varBuffer);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddSubroutine(const Subroutine& subroutine)
{
    this->subroutines.push_back(subroutine);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddSampler(const Sampler& sampler)
{
	this->samplers.push_back(sampler);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::SetPreprocessorPassthrough(const std::vector<std::string>& pps)
{
	this->passthroughPPs = pps;
}

//------------------------------------------------------------------------------
/**
*/
void 
Effect::Setup()
{
	assert(this->header.GetType() != Header::InvalidType);

	// reset static states
	Shader::ResetBindings();

	// build shaders, this will make sure we have all the shader programs we need, although they are not complete yet
	unsigned i;
	for (i = 0; i < this->programs.size(); i++)
	{
		this->programs[i].BuildShaders(this->header, this->functions, this->shaders);
	}

	// now, remove all functions which are not bound as shaders
	for (i = 0; i < this->functions.size(); i++)
	{
		// get function
		const Function& func = this->functions[i];

		if (func.IsShader())
		{
			this->functions.erase(this->functions.begin() + i);
			i--;
		}
	}

	// create a placeholder render state, which will be used for programs where no render state is explicitly assigned
	this->placeholderRenderState.SetName("PlaceholderState");
    this->placeholderRenderState.SetReserved(true);
    this->renderStates.insert(this->renderStates.begin(), this->placeholderRenderState);

	if (header.GetFlags() & Header::PutGlobalVariablesInBlock)
	{
		this->placeholderVarBlock.SetName("GlobalBlock");
		this->placeholderVarBlock.SetReserved(true);
		this->placeholderVarBlock.AddQualifier("shared");

		for (i = 0; i < this->variables.size(); i++)
		{
			AnyFX::Variable& var = this->variables[i];
			var.Preprocess();
			if (var.GetDataType().GetType() < DataType::Sampler1D && var.IsUniform())
			{
				this->placeholderVarBlock.AddVariable(var);
				this->variables.erase(this->variables.begin() + i);
				i--;
			}
		}

		// sort variables, since we can't handle the alignment manually here
		this->placeholderVarBlock.SortVariables();
		this->varBlocks.insert(this->varBlocks.begin(), this->placeholderVarBlock);
	}
	else
	{
		for (i = 0; i < this->variables.size(); i++)
		{
			AnyFX::Variable& var = this->variables[i];
			var.Preprocess();
		}
	}

	// if header has default group number, use it
	const std::string& defaultSet = this->header.GetValue("/DEFAULTSET");
	unsigned defaultSetIdx = 0;
	if (defaultSet != "/DEFAULTSET")
	{
		defaultSetIdx = std::stoi(defaultSet);
	}
    
	// sort all variables in varblocks
	for (i = 0; i < this->varBlocks.size(); i++)
	{
		this->varBlocks[i].group = defaultSetIdx;
	}

	for (i = 0; i < this->variables.size(); i++)
	{
		this->variables[i].group = defaultSetIdx;
	}

	for (i = 0; i < this->samplers.size(); i++)
	{
		this->samplers[i].group = defaultSetIdx;
	}

	for (i = 0; i < this->varBuffers.size(); i++)
	{
		this->varBuffers[i].group = defaultSetIdx;
	}

	// now, finalize all shaders, this adds all structures, varblocks and functions into all shaders, making sure they compile properly
	// we let the target compiler optimize unnecessary variables and functions away
	std::map<std::string, Shader*>::iterator it;
	for (it = this->shaders.begin(); it != this->shaders.end(); it++)
	{
		Shader* shader = it->second;
		shader->Setup();
	}
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::TypeCheck(TypeChecker& typechecker)
{
	this->header.TypeCheck(typechecker);

	// typecheck all shaders
	std::map<std::string, Shader*>::iterator it;
	for (it = this->shaders.begin(); it != this->shaders.end(); it++)
	{
		Shader* shader = it->second;
		shader->TypeCheck(typechecker);
	}

	unsigned i;
    unsigned j = 0;

	for (i = 0; i < this->constants.size(); i++)
	{
		this->constants[i].TypeCheck(typechecker);
	}

	for (i = 0; i < this->structures.size(); i++)
	{
		this->structures[i].TypeCheck(typechecker);
	}

    for (i = 0; i < this->subroutines.size(); i++)
    {
        this->subroutines[i].TypeCheck(typechecker);
        this->subroutines[i].UpdateCode(this->header, j++);
    }

    // go through subroutines a second time to check for variables which may have been removed due to optimization
    for (i = 0; i < this->subroutines.size(); i++)
    {
        this->subroutines[i].CheckForOptimization(typechecker);
    }

	for (i = 0; i < this->variables.size(); i++)
	{
		this->variables[i].TypeCheck(typechecker);
	}

	for (i = 0; i < this->samplers.size(); i++)
	{
		this->samplers[i].TypeCheck(typechecker);
	}

	for (i = 0; i < this->renderStates.size(); i++)
	{
		this->renderStates[i].TypeCheck(typechecker);
	}

	for (i = 0; i < this->functions.size(); i++)
	{
		this->functions[i].TypeCheck(typechecker);
		this->functions[i].Restore(this->header, j++);
	}

	for (i = 0; i < this->varBlocks.size(); i++)
	{
		//this->varBlocks[i].SortVariables();
		this->varBlocks[i].TypeCheck(typechecker);
	}

    for (i = 0; i < this->varBuffers.size(); i++)
    {
        this->varBuffers[i].TypeCheck(typechecker);
    }

	for (i = 0; i < this->programs.size(); i++)
	{
		this->programs[i].TypeCheck(typechecker);
	}

	// remove variables used as subroutines
	for (i = 0; i < this->variables.size(); i++)
	{
		if (this->header.GetFlags() & Header::NoSubroutines && this->variables[i].IsSubroutine())
		{
			this->variables.erase(this->variables.begin() + i);
			i--;
		}
	}
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::Generate(Generator& generator)
{
	// typecheck all shaders
	std::map<std::string, Shader*>::iterator it;
	unsigned i = 0;
	for (it = this->shaders.begin(); it != this->shaders.end(); it++)
	{
		Shader* shader = it->second;

		// generate code for shaders
		shader->Generate(generator, this->variables, this->structures, this->constants, this->varBlocks, this->varBuffers, this->samplers, this->subroutines, this->functions, this->passthroughPPs);

		// output generated code if we flag it
		if (this->header.GetFlags() & Header::OutputGeneratedShaders)
		{
			BinWriter out;
			out.SetPath(AnyFX::Format("%s_%d%s", this->debugOutput.c_str(), i++, "_debug.txt"));
			out.Open();
			const std::string compiled = shader->GetCompiledCode();
			out.WriteBytes(compiled.c_str(), compiled.length());
			out.Close();
		}
	}

	if (generator.GetStatus() == Generator::Success) for (i = 0; i < this->programs.size(); i++)
	{
		Program& prog = this->programs[i];
		prog.Generate(generator);

		if (this->header.GetFlags() & Header::OutputGeneratedShaders)
		{
			unsigned j;
			for (j = 0; j < ProgramRow::NumProgramRows - 1; j++)
			{
				BinWriter out;
				out.SetPath(AnyFX::Format("%s_%s_%d%s", this->debugOutput.c_str(), prog.GetName().c_str(), j, "_debug.bin"));
				out.Open();
				const std::vector<unsigned> bin = prog.GetBinary(j); 
				prog.WriteBinary(bin, out);
				out.Close();
			}
		}
	}
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::Compile(BinWriter& writer)
{
	assert(this->header.GetType() != Header::InvalidType);

	// write magic number
	writer.WriteInt('ANFX');
	writer.WriteInt(VERSION_MAJOR);
	writer.WriteInt(VERSION_MINOR);

	// write header, vital!
	this->header.Compile(writer);

	unsigned i;
	
	// write FourCC code for shaders
	writer.WriteInt('SHAD');

	// write amount of shaders
	writer.WriteInt(this->shaders.size());

	// compile all shaders
	std::map<std::string, Shader*>::iterator it;
	for (it = this->shaders.begin(); it != this->shaders.end(); it++)
	{
		Shader* shader = it->second;

		// then compile
		shader->Compile(writer);
	}

	// write FourCC code for render states
	writer.WriteInt('RENS');

	// write amount of render states
	writer.WriteInt(this->renderStates.size());

	// compile render states for runtime
	for (i = 0; i < this->renderStates.size(); i++)
	{
		this->renderStates[i].Compile(writer);
	}

    // write FourCC code for subroutines
    writer.WriteInt('SUBR');

    // write amount of subroutines
    writer.WriteInt(this->subroutines.size());

    // compile subroutines for runtime
    for (i = 0; i < this->subroutines.size(); i++)
    {
        this->subroutines[i].Compile(writer);
    }

	// write FourCC code for programs
	writer.WriteInt('PROG');

	// write amount of programs
	writer.WriteInt(this->programs.size());

	// compile programs for runtime
	for (i = 0; i < this->programs.size(); i++)
	{
		this->programs[i].Compile(writer);
	}

	// write FourCC code for variables
	writer.WriteInt('VARI');

	// write amount of variables
	writer.WriteInt(this->variables.size());

	// compile variables for runtime
	for (i = 0; i < this->variables.size(); i++)
	{
		this->variables[i].Compile(writer);
	}

	// write FourCC code for samplers
	writer.WriteInt('SAMP');

	// write amount of samplers
	writer.WriteInt(this->samplers.size());

	for (i = 0; i < this->samplers.size(); i++)
	{
		this->samplers[i].Compile(writer);
	}

	// write FourCC code for varblocks
	writer.WriteInt('VARB');

	// write amount of varblocks
	writer.WriteInt(this->varBlocks.size());

	// compile varblocks for runtime
	for (i = 0; i < this->varBlocks.size(); i++)
	{
		this->varBlocks[i].Compile(writer);
	}

    // write FourCC code for varbuffers
    writer.WriteInt('VRBF');

    // write amount of varbuffers
    writer.WriteInt(this->varBuffers.size());

    // compile varbuffers for runtime
    for (i = 0; i < this->varBuffers.size(); i++)
    {
        this->varBuffers[i].Compile(writer);
    }
}

//------------------------------------------------------------------------------
/**
*/
void 
Effect::GenerateHeader(TextWriter& writer)
{
	
	std::string output = AnyFX::Format("#pragma once\n\
//------------------------------------------------------------------------------\n\
/** \n	Generated from shader '%s' \n\n\
	DO NOT MODIFY HERE!!! \n \
*/\
\n\nnamespace %s\n{\n\n", 
		this->file.c_str(), this->name.c_str());
	writer.WriteString(output);

	unsigned i;

	// compile constants for include header
	for (i = 0; i < this->constants.size(); i++)
	{
		writer.WriteString(this->constants[i].Format(this->header));
	}

	// compile structs for include header
	for (i = 0; i < this->structures.size(); i++)
	{
		writer.WriteString(this->structures[i].Format(this->header));
	}

	// compile varblocks for include header
	for (i = 0; i < this->varBlocks.size(); i++)
	{
		writer.WriteString(this->varBlocks[i].Format(this->header));
	}

	// compile varbuffers for include header
    for (i = 0; i < this->varBuffers.size(); i++)
    {
		writer.WriteString(this->varBuffers[i].Format(this->header));
    }

	writer.WriteString("}");
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
Effect::RoundToPow2(unsigned number, unsigned power)
{
	return number = (number + power - 1) & ~(power - 1);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::GetAlignmentGLSL(const DataType& type, unsigned arraySize, unsigned& size, unsigned& alignment, const bool std140, const bool structMember, TypeChecker& typechecker)
{
	DataType::Dimensions dims = DataType::ToDimensions(type);
	unsigned byteSize = DataType::ToByteSize(DataType::ToPrimitiveType(type));
	const unsigned vec4alignment = 16;
	unsigned elementAlignment = 0;

	/*
	1.  If the member is a scalar consuming N basic machine units, the base alignment is N.
	2.  If the member is a two- or four-component vector with components consuming N basic machine units, the base alignment is 2N or 4N, respectively.
	3.  If the member is a three-component vector with components consuming N basic machine units, the base alignment is 4N.
	4.  If the member is an array of scalars or vectors, the base alignment and array stride are set to match the base alignment of a single array element, 
		according to rules (1), (2), and (3), and rounded up to the base alignment of a vec4. The array may have padding at the end; 
		the base offset of the member following the array is rounded up to the next multiple of the base alignment.
	5.  If the member is a column-major matrix with C columns and R rows, the matrix is stored identically to an array of C column vectors with R 
		components each, according to rule (4).
	6.  If the member is an array of S column-major matrices with C columns and R rows, the matrix is stored identically to a row of 
		S×C column vectors with R components each, according to rule (4).
	7.  If the member is a row-major matrix with C columns and R rows, the matrix is stored identically to an array of R row vectors with C components each, 
		according to rule (4).
	8.  If the member is an array of S row-major matrices with C columns and R rows, the matrix is stored identically to a row of S×R row vectors with C 
		components each, according to rule (4).
	9.  If the member is a structure, the base alignment of the structure is N, where N is the largest base alignment value of any of its members, 
		and rounded up to the base alignment of a vec4. The individual members of this sub-structure are then assigned offsets by applying this set of 
		rules recursively, where the base offset of the first member of the sub-structure is equal to the aligned offset of the structure. 
		The structure may have padding at the end; the base offset of the member following the sub-structure is 
		rounded up to the next multiple of the base alignment of the structure.
	10. If the member is an array of S structures, the S elements of the array are laid out in order, according to rule

	For std430, rounding up to vec4 in rule 4 and 9 is not relevant
	*/

	// calculate alignment per element
	switch (dims.x)
	{
	case 0:		// this happens if we have structs
		break;
	case 1:
		alignment = byteSize;
		size = byteSize;
		break;
	case 2:
		alignment = byteSize * 2;
		size = byteSize * 2;
		break;
	case 3:
		alignment = byteSize * 4;
		size = byteSize * 3;
		break;
	case 4:
		alignment = byteSize * 4;
		size = byteSize * 4;
		break;
	default:
		// should never happen
		alignment = byteSize;
		size = byteSize;
		break;
	}

	if (arraySize > 1) // if array
	{
		Effect::GetAlignmentGLSL(type, 1, size, alignment, std140, structMember, typechecker);
		if (std140)
			alignment = std::max(vec4alignment, alignment);
		size *= arraySize;
	}
	else if (type.GetType() == DataType::UserType)  // if structure
	{
		Structure* structure = dynamic_cast<Structure*>(typechecker.GetSymbol(type.GetName()));
		if (!structure)
		{
			size = 0;
			alignment = vec4alignment;
		}
		else
		{
			size = structure->alignedSize;
			alignment = structure->alignment;
		}
	}
	else if (dims.y > 1) // if matrix
	{
		if (std140)
			alignment = std::max(vec4alignment, alignment);
		size = RoundToPow2(size, alignment);
		size *= dims.y;
	}
}

} // namespace AnyFX
