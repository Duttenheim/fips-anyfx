grammar AnyFX;

options 
{
	language=Cpp;
	backtracking = true;
}


// Lexer API hooks
@lexer::apifuncs
{

}


@lexer::members
{
	#include <iostream>

	void ParseLineDirective(const std::string& str)
	{

	}
	misc::Interval interval;
	std::string currentFile;
	int currentLine = 0;
}

@lexer::header
{
	#include <string>
	#include <vector>
	extern std::vector<std::string> uncaughtPreprocessorDirectives;
	#include "AnyFXToken.h"
}

@lexer::definitions
{
	std::vector<std::string> uncaughtPreprocessorDirectives;
}

// parser API hooks
@parser::apifuncs
{

}

@parser::members
{
	// setup function which binds the compiler state to the current AST node
	void SetupFile(AnyFX::Compileable* comp, antlr4::TokenStream* stream)
	{
		::AnyFXToken* token = (::AnyFXToken*)stream->LT(-1);

		UpdateLine(stream, -1);

		// assume the previous token is the latest file
		auto tu2 = this->lines[this->currentLine];
		comp->SetLine(lineOffset);
		comp->SetPosition(token->getCharPositionInLine());
		comp->SetFile(std::get<4>(tu2));
	}

	// update and get current line
	void UpdateLine(antlr4::TokenStream* stream, int index = -1)
	{
		::AnyFXToken* token = (::AnyFXToken*)stream->LT(index);

		// find the next parsed row which comes after the token
		int loop = this->currentLine;
		int tokenLine = token->getLine();
		while (loop < this->lines.size() - 1)
		{
			auto temp = this->lines[loop];
			if (std::get<1>(temp) > tokenLine)
			{
				loop--;
				break;
			}
			loop++;
		}

		this->currentLine = loop;
		auto tu2 = this->lines[this->currentLine];
		this->lineOffset = std::get<0>(tu2) + tokenLine;
	}

	int currentLine = 0;
	int lineOffset = 0;
	std::vector<std::tuple<int, size_t, size_t, size_t, std::string>> lines;
}

// parser includes
@parser::header
{	

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>
extern std::vector<std::string> uncaughtPreprocessorDirectives;

#include "AnyFXToken.h"
#include "../../code/qualifierexpression.h"
#include "../../code/compileable.h"
#include "../../code/effect.h"
#include "../../code/header.h"
#include "../../code/datatype.h"
#include "../../code/parameter.h"
#include "../../code/annotation.h"
#include "../../code/programrow.h"
#include "../../code/program.h"
#include "../../code/samplertexturelist.h"
#include "../../code/samplerrow.h"
#include "../../code/sampler.h"
#include "../../code/structure.h"
#include "../../code/constant.h"
#include "../../code/blendstaterow.h"
#include "../../code/renderstaterow.h"
#include "../../code/renderstate.h"
#include "../../code/function.h"
#include "../../code/valuelist.h"
#include "../../code/functionattribute.h"
#include "../../code/variable.h"
#include "../../code/varblock.h"
#include "../../code/varbuffer.h"
#include "../../code/subroutine.h"
#include "../../code/preprocessor.h"
#include "../../code/expressions/expression.h"
#include "../../code/expressions/binaryexpression.h"
#include "../../code/expressions/unaryexpression.h"
#include "../../code/expressions/intexpression.h"
#include "../../code/expressions/boolexpression.h"
#include "../../code/expressions/floatexpression.h"
using namespace AnyFX;

}

string	returns [ std::string val ]
	:	QO (data = ~QO { $val.append($data.text); })* QO 
	|	Q (data = ~Q { $val.append($data.text); })* Q
	;
		
boolean returns [ bool val ]
	@init
	{
		$val = false;
	}
	:	'true' { $val = true; }
	|	'false' { $val = false; }
	;

// preprocess
preprocess
	@init
	{
		Token* start = nullptr;
	}
	: 
	(
		{ start = _input->LT(1); } '#line' line = INTEGERLITERAL path = string { lines.push_back(std::make_tuple(atoi($line.text.c_str()) - (int)start->getLine() - 1, _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), $path.text)); }
		| .
	)*?
	EOF
	;
	
// main entry point
entry		returns [ Effect returnEffect ]
	:	effect 
	{ 
		$effect.eff.SetPreprocessorPassthrough(uncaughtPreprocessorDirectives);
		uncaughtPreprocessorDirectives.clear();
		$returnEffect = $effect.eff; 
	} EOF
	;
	
// entry point for effect, call this function to begin parsing
effect	returns [ Effect eff ]
	:  
		(
			constant { $eff.AddConstant($constant.cons);}
			| variable { $eff.AddVariable($variable.var); } 
			| renderState { $eff.AddRenderState($renderState.state); }
			| function { $eff.AddFunction($function.func); }
			| program { $eff.AddProgram($program.prog); }
			| structure { $eff.AddStructure($structure.struc); }
			| varblock { $eff.AddVarBlock($varblock.block); }
			| varbuffer { $eff.AddVarBuffer($varbuffer.buffer); }
			| subroutine { $eff.AddSubroutine($subroutine.subrout); }
			| sampler { $eff.AddSampler($sampler.samp); }
		)*?
	;


// add qualifiers here
qualifier returns [ std::string str ]
@init
{
	Token* startToken = _input->LT(1);
}
@after
{
	$str = startToken->getText();
}
	: 'const'
	| 'shared'
	| 'push'
	
	// shader and function parameter qualifiers
	| 'flat'
	| 'noperspective'
	| 'patch'
	| 'in'
	| 'out'
	| 'inout'
	
	// compute qualifier
	| 'groupshared'
	
	// image types
	| 'rgba32f'
	| 'rgba16f'
	| 'rg32f'
	| 'rg16f'
	| 'r11g11b10f'
	| 'r32f'
	| 'r16f'
	| 'rgba16'
	| 'rgba8'
	| 'rgb10a2'
	| 'rg16'
	| 'rg8'
	| 'r16'
	| 'r8'
	| 'rgba16snorm'
	| 'rgba8snorm'
	| 'rg16snorm'
	| 'rg8snorm'
	| 'r16snorm'
	| 'r8snorm'
	| 'rgba32i'
	| 'rgba16i'
	| 'rgba8i'
	| 'rg32i'
	| 'rg16i'
	| 'rg8i'
	| 'r32i'
	| 'r16i'
	| 'r8i'	
	| 'rgba32ui'
	| 'rgba16ui'
	| 'rgba8ui'
	| 'rg32ui'
	| 'rg16ui'
	| 'rg8ui'
	| 'r32ui'
	| 'r16ui'
	| 'r8ui'
	
	// image access
	| 'read'
	| 'write'
	| 'readwrite'
	;
	
qualifierValued returns [ std::string str ]
@init
{
	Token* startToken = _input->LT(1);
}
@after
{
	$str = startToken->getText();
}
	: 'group'
	| 'index'
	;

// all types are declared in this expression
// here, we define all variable types from both HLSL and GLSL up to the latest release
type		returns [ DataType ty ]
	: IDENTIFIER
	{
		std::string typeString($IDENTIFIER.text);
		if (typeString == "float") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::Float); }
		else if (typeString == "int") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::Integer); }
		else if (typeString == "bool") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::Bool); }
		else if (typeString == "uint") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::UInteger); }
		else if (typeString == "short") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::Short); }
		else if (typeString == "string") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::String); }
		else if (typeString == "void") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::Void); }
		else if (typeString == "textureHandle") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::TextureHandle); }
		else if (typeString == "imageHandle") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::ImageHandle); }
		else if (typeString == "samplerHandle") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::SamplerHandle); }
		else if (typeString == "inputAttachment") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::InputAttachment); }
		else if (typeString == "inputAttachmentMS") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::InputAttachmentMS); }
		else if (typeString == "inputAttachmentInteger") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::InputAttachmentInteger); }
		else if (typeString == "inputAttachmentIntegerMS") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::InputAttachmentIntegerMS); }
		else if (typeString == "inputAttachmentUInteger") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::InputAttachmentUInteger); }
		else if (typeString == "inputAttachmentUIntegerMS") { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::InputAttachmentUIntegerMS); }		
		
		// HLSL types
		else if (typeString == "float2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Float2); }
		else if (typeString == "float3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Float3); }
		else if (typeString == "float4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Float4); }		
		else if (typeString == "int2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Integer2); }
		else if (typeString == "int3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Integer3); }
		else if (typeString == "int4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Integer4); }		
		else if (typeString == "uint2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::UInteger2); }
		else if (typeString == "uint3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::UInteger3); }
		else if (typeString == "uint4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::UInteger4); }
		else if (typeString == "short2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Short2); }
		else if (typeString == "short3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Short3); }
		else if (typeString == "short4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Short4); }
		else if (typeString == "bool2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Bool2); }
		else if (typeString == "bool3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Bool3); }
		else if (typeString == "bool4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Bool4); }
		else if (typeString == "float2x2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix2x2); }
		else if (typeString == "float2x3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix2x3); }
		else if (typeString == "float2x4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix2x4); }
		else if (typeString == "float3x2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix3x2); }
		else if (typeString == "float3x3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix3x3); }
		else if (typeString == "float3x4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix3x4); }
		else if (typeString == "float4x2") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix4x2); }
		else if (typeString == "float4x3") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix4x3); }
		else if (typeString == "float4x4") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Matrix4x4); }
		else if (typeString == "Texture1D") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler1D); }
		else if (typeString == "Texture1DArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler1DArray); }
		else if (typeString == "Texture2D") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler2D); }
		else if (typeString == "Texture2DArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler2DArray); }
		else if (typeString == "Texture2DMS") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler2DMS); }
		else if (typeString == "Texture2DMSArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler2DMSArray); }
		else if (typeString == "Texture3D") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Sampler3D); }
		else if (typeString == "TextureCube") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::SamplerCube); }
		else if (typeString == "TextureCubeArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::SamplerCubeArray); }
		else if (typeString == "RWTexture1D") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image1D); }
		else if (typeString == "RWTexture1DArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image1DArray); }
		else if (typeString == "RWTexture2D") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image2D); }
		else if (typeString == "RWTexture2DArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image2DArray); }
		else if (typeString == "RWTexture2DMS") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image2DMS); }
		else if (typeString == "RWTexture2DMSArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image2DMSArray); }
		else if (typeString == "RWTexture3D") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::Image3D); }
		else if (typeString == "RWTextureCube") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::ImageCube); }
		else if (typeString == "RWTextureCubeArray") { $ty.SetStyle(DataType::HLSL); $ty.SetType(DataType::ImageCubeArray); }
		
		// GLSL types
		else if (typeString == "vec2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Float2); }
		else if (typeString == "vec3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Float3); }
		else if (typeString == "vec4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Float4); }		
		else if (typeString == "ivec2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Integer2); }
		else if (typeString == "ivec3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Integer3); }
		else if (typeString == "ivec4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Integer4); }		
		else if (typeString == "uvec2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::UInteger2); }
		else if (typeString == "uvec3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::UInteger3); }
		else if (typeString == "uvec4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::UInteger4); }
		else if (typeString == "svec2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Short2); }
		else if (typeString == "svec3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Short3); }
		else if (typeString == "svec4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Short4); }
		else if (typeString == "bvec2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Bool2); }
		else if (typeString == "bvec3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Bool3); }
		else if (typeString == "bvec4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Bool4); }
		else if (typeString == "mat2x2" || typeString == "mat2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix2x2); }
		else if (typeString == "mat2x3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix2x3); }
		else if (typeString == "mat2x4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix2x4); }
		else if (typeString == "mat3x2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix3x2); }
		else if (typeString == "mat3x3" || typeString == "mat3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix3x3); }
		else if (typeString == "mat3x4") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix3x4); }
		else if (typeString == "mat4x2") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix4x2); }
		else if (typeString == "mat4x3") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix4x3); }
		else if (typeString == "mat4x4" || typeString == "mat4" ) { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Matrix4x4); }
		else if (typeString == "sampler1D") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler1D); }
		else if (typeString == "sampler1DArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler1DArray); }
		else if (typeString == "sampler2D") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler2D); }
		else if (typeString == "sampler2DArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler2DArray); }
		else if (typeString == "sampler2DMS") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler2DMS); }
		else if (typeString == "sampler2DMSArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler2DMSArray); }
		else if (typeString == "sampler3D") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Sampler3D); }
		else if (typeString == "samplerCube") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::SamplerCube); }
		else if (typeString == "samplerCubeArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::SamplerCubeArray); }
		else if (typeString == "image1D") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image1D); }
		else if (typeString == "image1DArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image1DArray); }
		else if (typeString == "image2D") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image2D); }
		else if (typeString == "image2DArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image2DArray); }
		else if (typeString == "image2DMS") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image2DMS); }
		else if (typeString == "image2DMSArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image2DMSArray); }
		else if (typeString == "image3D") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Image3D); }
		else if (typeString == "imageCube") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::ImageCube); }
		else if (typeString == "imageCubeArray") { $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::ImageCubeArray); }
		else if (typeString == "texture1D") 		{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture1D); }
		else if (typeString == "texture1DArray") 	{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture1DArray); }
		else if (typeString == "texture2D") 		{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture2D); }
		else if (typeString == "texture2DArray") 	{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture2DArray); }
		else if (typeString == "texture2DMS") 		{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture2DMS); }
		else if (typeString == "texture2DMSArray") 	{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture2DMSArray); }
		else if (typeString == "texture3D") 		{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::Texture3D); }
		else if (typeString == "textureCube") 		{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::TextureCube); }
		else if (typeString == "textureCubeArray") 	{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::TextureCubeArray); }
		else if (typeString == "atomic_uint") 		{ $ty.SetStyle(DataType::GLSL); $ty.SetType(DataType::AtomicCounter); }
		
		// user defined type detected
		else { $ty.SetStyle(DataType::Generic); $ty.SetType(DataType::UserType); $ty.SetName(typeString); }
	}
	;
	
// setup a special type of qualifier which is numbered
qualifierExpression returns [ QualifierExpression q ]
	: base = qualifierValued parantexpression { $q.name = $base.str; $q.expr = $parantexpression.tree; }
	;

// we can also define structs outside the function scopes
structure	returns [ Structure struc ]
	: 	'struct' IDENTIFIER { SetupFile(&$struc, _input); } LB ( parameter SC { $struc.AddParameter($parameter.param); } )* RB SC { $struc.SetName($IDENTIFIER.text);  }
	;

// a varblock denotes a block within which we can find variables, using this structure, we can feed variables in chunks instead of individually, which may improve performance
// this is equal to DirectX constant buffers or OpenGL uniform block
// since this is just a special way of denoting a structure, we give it some extra attributes such as shared, which means this will structure will go in a shared dictionary, and be EQUAL to every shader utilizing this block
varblock	returns [ VarBlock block ]
	: 
	(qualifier { $block.AddQualifier($qualifier.str); } | qualifierExpression { $block.AddQualifierExpression($qualifierExpression.q); })*
	'varblock' name = IDENTIFIER { SetupFile(&$block, _input); } 
	(annotation { $block.SetAnnotation($annotation.annot); })?
	LB ( variable { $block.AddVariable($variable.var); } )* RB SC { $block.SetName($name.text); }
	;
	
// a varbuffer denotes a data type which has a dynamic size.
// varbuffers are much like varblocks, but they support for having its members in forms of unsized arrays.
// in OpenGL this is known as a shader storage block.
varbuffer	returns [ VarBuffer buffer ]
	:
	(qualifier { $buffer.AddQualifier($qualifier.str); } | qualifierExpression { $buffer.AddQualifierExpression($qualifierExpression.q); })*
	'varbuffer' name = IDENTIFIER { SetupFile(&$buffer, _input); }
	(annotation { $buffer.SetAnnotation($annotation.annot); })?
	LB ( variable {$buffer.AddVariable($variable.var); } )* RB SC { $buffer.SetName($name.text); }
	;
	
// a subroutine denotes a function which can be dynamically switched without switching shader states.
// there are two implementations of a subroutine, the first being the subroutine variable which is a 'variable' which corresponds to a function.
// then there is the other which is an implementation based on an interface.
subroutine	returns [ Subroutine subrout ]
	:
	'prototype' retval = type name = IDENTIFIER { SetupFile(&$subrout, _input); } LP parameterList RP SC
	{
		$subrout.SetSubroutineType(Subroutine::Signature); 
		$subrout.SetName($name.text);
		$subrout.SetParameters($parameterList.parameters);
		$subrout.SetReturnType($retval.ty);		
	}
	| 'subroutine' LP signature = IDENTIFIER RP { SetupFile(&$subrout, _input); } function
	{
		$subrout.SetName($function.func.GetName());
		$subrout.SetSubroutineType(Subroutine::Implementation); 
		$subrout.SetSignature($signature.text);
		$subrout.SetFunction($function.func);
	}
	;

// values can be initialized with literal values by using the default constructor
valueList	returns [ ValueList valList ]
	:
	first = expression { $valList.AddValue($first.tree); } ( CO rest = expression { $valList.AddValue($rest.tree); } )*
	;
		
// values can also be initialized with a single value, this is basically a valueList but with just a single value
valueSingleList	returns [ ValueList valList ]
	:
	expression { $valList.AddValue($expression.tree); }
	;
	

// variable is type, name and semicolon
variable	returns [ Variable var ]
	:	
		(qualifier { $var.AddQualifier($qualifier.str); } | qualifierExpression { $var.AddQualifierExpression($qualifierExpression.q); })*
		declType = type name = IDENTIFIER { $var.SetDataType($declType.ty); $var.SetName($name.text); SetupFile(&$var, _input); }
		( 	
			LL RR EQ 	{ $var.SetArrayType(Variable::TypedArray); }		LB fstType = type LP fstValue = valueList RP { $var.AddValue($fstType.ty, $fstValue.valList); }  // array initializer which assumes the size of the value list
														  ( CO cntType = type LP cntValue = valueList RP { $var.AddValue($cntType.ty, $cntValue.valList); } )* RB 
			| LL RR EQ  { $var.SetArrayType(Variable::SimpleArray); }		LB valList = valueList RB { $var.AddValue($valList.valList); }
			| LL asize0 = expression RR 					{ $var.SetSizeExpression($asize0.tree); } 								// array variable
			| LL asize1 = expression RR 					{ $var.SetSizeExpression($asize1.tree); $var.SetArrayType(Variable::TypedArray); } EQ LB fstType = type LP fstValue = valueList RP { $var.AddValue($fstType.ty, $fstValue.valList); } (CO cntType = type LP cntValue = valueList RP { $var.AddValue($cntType.ty, $cntValue.valList); } )* RB				// array initializer for vector types
			| LL asize2 = expression RR 					{ $var.SetSizeExpression($asize2.tree); $var.SetArrayType(Variable::SimpleArray); } EQ LB valList = valueList RB { $var.AddValue($valList.valList); } 				
			| LL RR											{ $var.SetArrayType(Variable::UnsizedArray); } 						// unsized array type, only usable for varbuffers
			| EQ defType = type LP list2 = valueList RP 	{ $var.AddValue($defType.ty, $list2.valList); } 					// explicit variable initialization
			| EQ list3 = valueSingleList					{ $var.AddValue($list3.valList); }									// implicit variable initialization, only viable for generic values
		)?	
		
		(annotation { $var.SetAnnotation($annotation.annot); })?
		SC
	;
	
// constant value
constant	returns [ Constant cons ]
	: 'const' declType = type IDENTIFIER { $cons.SetDataType($declType.ty); $cons.SetName($IDENTIFIER.text); SetupFile(&$cons, _input); }
	(
		EQ defType = type LP sinVal1 = valueList RP SC		{ $cons.AddValue($defType.ty, $sinVal1.valList); }			// explicit variable initialization
		| EQ sinVal2 = valueSingleList SC					{ $cons.AddValue($sinVal2.valList); }							// implicit constant initialization, only viable for generic values
		| LL RR EQ 											{ $cons.SetArrayType(Constant::TypedArray); }	LB fstType = type LP fstValue = valueList RP { $cons.AddValue($fstType.ty, $fstValue.valList); }  // array initializer which assumes the size of the value list
																						  ( CO cntType = type LP cntValue = valueList RP { $cons.AddValue($cntType.ty, $cntValue.valList); } )* RB SC
		| LL RR EQ  										{ $cons.SetArrayType(Constant::SimpleArray); }		LB valList = valueList RB { $cons.AddValue($valList.valList); } SC
		| LL asize1 = expression RR 						{ $cons.SetSizeExpression($asize1.tree); $cons.SetArrayType(Constant::TypedArray); } EQ LB fstType = type LP fstValue = valueList RP { $cons.AddValue($fstType.ty, $fstValue.valList); } (CO cntType = type LP cntValue = valueList RP { $cons.AddValue($cntType.ty, $cntValue.valList); } )* RB SC				// array initializer for vector types
		| LL asize2 = expression RR 						{ $cons.SetSizeExpression($asize2.tree); $cons.SetArrayType(Constant::SimpleArray); } EQ LB valList = valueList RB { $cons.AddValue($valList.valList); } SC 																																									// simple array initializer
	)
	;

// parameter modifiers denotes variables with special use, such as vertex position output, instance id _input etc
parameterAttribute	returns [ Parameter::Attribute attribute ]
		@init
		{
			$attribute = Parameter::NoAttribute;
		}
		: LL IDENTIFIER RR
		{
			std::string identifierString($IDENTIFIER.text);
			
			if (identifierString == "drawinstanceID") 						{ $attribute = Parameter::DrawInstance; }
			else if (identifierString == "vertexID") 						{ $attribute = Parameter::Vertex; }
			else if (identifierString == "primitiveID") 					{ $attribute = Parameter::Primitive; }
			else if (identifierString == "invocationID") 					{ $attribute = Parameter::Invocation; }
			else if (identifierString == "viewportID") 						{ $attribute = Parameter::Viewport; }
			else if (identifierString == "rendertargetID") 					{ $attribute = Parameter::Rendertarget; }
			else if (identifierString == "innertessellation") 				{ $attribute = Parameter::InnerTessellation; }
			else if (identifierString == "outertessellation") 				{ $attribute = Parameter::OuterTessellation; }
			else if (identifierString == "position") 						{ $attribute = Parameter::Position; }
			else if (identifierString == "pointsize") 						{ $attribute = Parameter::PointSize; }
			else if (identifierString == "clipdistance") 					{ $attribute = Parameter::ClipDistance; }
			else if (identifierString == "frontface") 						{ $attribute = Parameter::FrontFace; }
			else if (identifierString == "coordinate") 						{ $attribute = Parameter::Coordinate; }
			else if (identifierString == "depth")							{ $attribute = Parameter::Depth; }
			else if (identifierString == "color0") 							{ $attribute = Parameter::Color0; }
			else if (identifierString == "color1") 							{ $attribute = Parameter::Color1; }
			else if (identifierString == "color2") 							{ $attribute = Parameter::Color2; }
			else if (identifierString == "color3") 							{ $attribute = Parameter::Color3; }
			else if (identifierString == "color4") 							{ $attribute = Parameter::Color4; }
			else if (identifierString == "color5") 							{ $attribute = Parameter::Color5; }
			else if (identifierString == "color6") 							{ $attribute = Parameter::Color6; }
			else if (identifierString == "color7") 							{ $attribute = Parameter::Color7; }
			else if (identifierString == "workgroupID")						{ $attribute = Parameter::WorkGroup; }
			else if (identifierString == "numgroups")						{ $attribute = Parameter::NumGroups; }
			else if (identifierString == "localID") 						{ $attribute = Parameter::LocalID; }
			else if (identifierString == "localindex") 						{ $attribute = Parameter::LocalIndex; }
			else if (identifierString == "globalID") 						{ $attribute = Parameter::GlobalID; }
			else 															{ $attribute = Parameter::InvalidAttribute; }
		}
		;

// defines a parameter, parameters have in/out/inout qualifiers which are used in shaders to denote how a variable should be handled
// default IO for a parameter is _input (as a normal function parameter in C)
parameter	returns [ Parameter param ]
	: 
	(LL attr = IDENTIFIER RR 
		{ 
			$param.SetAttribute($attr.text); 
		} 
	)?
	(LL 'feedback' EQ LP feedbackBuffer = expression CO feedbackOffset = expression RP RR
		{
			$param.SetFeedbackBufferExpression($feedbackBuffer.tree);
			$param.SetFeedbackOffsetExpression($feedbackOffset.tree);
		}
	)?
	(LL 'slot' EQ slotExpression = expression RR
		{
			$param.SetSlotExpression($slotExpression.tree);
		}
	)?
	(qualifier 
		{ 
			$param.AddQualifier($qualifier.str); 
		} 
	)* 
	type name = IDENTIFIER 
	{ $param.SetDataType($type.ty); $param.SetName($name.text); SetupFile(&$param, _input); }	
	( LL (size = expression { $param.SetSizeExpression($size.tree); } )? RR { $param.ForceArrayFlag(); } )?
	;
	
// parameters can either be in or out
parameterList	returns [ std::vector<Parameter> parameters ]
	: 	(firstParam = parameter { $parameters.push_back($firstParam.param); } (CO followParam = parameter { $parameters.push_back($followParam.param); } )* )? 
	;
	
// function attributes are used for tessellation, geometry and compute shading
functionAttribute	returns [ FunctionAttribute attribute ]
	: LL flag1 = IDENTIFIER RR EQ expression
	{
		std::string identifierString($flag1.text);
		
		$attribute.SetExpression(identifierString, $expression.tree);
	}
	| LL flag3 = IDENTIFIER RR EQ data = IDENTIFIER
	{
		std::string identifierString($flag3.text);
		std::string dataString($data.text);
		
		$attribute.SetString(identifierString, dataString);		
	}
	| LL flag3 = IDENTIFIER RR
	{
		std::string identifierString($flag3.text);
		
		$attribute.SetBool(identifierString, true);
	}
	;
	
// a code block denotes a series of scopes with contents.
// we don't need to get any data here, since we will fetch it from our surrounding function
codeBlock
	:	LB (codeBlock)* RB
	|	~(LB|RB)
	;
	
// function is denoted by shader type, function name, parameter list, then code block
function	returns [ Function func ]
		@init
		{
			Token* lineToken = nullptr;
			Token* functionToken = nullptr;
			Token* startToken = nullptr;
			Token* endToken = nullptr;
		}
		: (functionAttribute { $func.ConsumeAttribute($functionAttribute.attribute); } )* 
		('shader' { $func.SetShader(true); })?
		type IDENTIFIER { SetupFile(&$func, _input); functionToken = _input->LT(-2); } LP parameterList RP
		{
			// the code block will beafter the next LB
			startToken = _input->LT(2);
			
			UpdateLine(_input, -2);
			$func.SetFunctionLine(this->lineOffset);
			UpdateLine(_input, 2);
			$func.SetCodeLine(this->lineOffset);
		}
		codeBlock
		{ 
			// save last token
			endToken = _input->LT(-2);			
			
			// get all text inbetween the two tokens
			antlr4::misc::Interval interval;
			interval.a = startToken->getTokenIndex();
			interval.b = endToken->getTokenIndex();
			std::string code = _input->getText(interval);

			// get all text inbetween the two tokens
			if (code.length() > 0) $func.SetCode(code);
		}
		{ $func.SetName($IDENTIFIER.text); $func.SetReturnType($type.ty); $func.SetParameters($parameterList.parameters); } 
		;

blendStateRow	returns [ BlendStateRow row ]
	: flag1 = IDENTIFIER LL index1 = expression RR EQ blendFlag = IDENTIFIER SC
	{
		std::string flag($flag1.text);		
		$row.SetString($index1.tree, flag, $blendFlag.text);
	}
	| flag2 = IDENTIFIER LL index2 = expression RR EQ value = expression SC
	{
		std::string flag($flag2.text);		
		$row.SetExpression($index2.tree, flag, $value.tree);
	}
	;

renderStateRow	returns [ RenderStateRow row ]
	: flag1 = IDENTIFIER EQ expression SC
	{
		std::string flag($flag1.text);
		$row.SetExpression(flag, $expression.tree);
	}
	| flag2 = IDENTIFIER EQ renderStateSetting = IDENTIFIER SC
	{
		std::string flag($flag2.text);
		$row.SetString(flag, $renderStateSetting.text);		
	}
	;

// draw state, contains a series of draw flags
renderState	returns [ RenderState state ]
	: 	'state' IDENTIFIER  { SetupFile(&$state, _input); } SC		{ $state.SetName($IDENTIFIER.text); }
	| 	'state' IDENTIFIER  { SetupFile(&$state, _input); } LB 		{ $state.SetName($IDENTIFIER.text); }
	( 
	  renderStateRow { $state.ConsumeRenderRow($renderStateRow.row); } 
	| blendStateRow  { $state.ConsumeBlendRow($blendStateRow.row); }	
	)* 
	RB SC
	;
		

// a sampler explains how to sample textures
sampler		returns [ Sampler samp ]
	:	(qualifier { $samp.AddQualifier($qualifier.str); } | qualifierExpression { $samp.AddQualifierExpression($qualifierExpression.q); } )*
		'samplerstate' name = IDENTIFIER { SetupFile(&$samp, _input); } SC					{ $samp.SetName($name.text); }
	|	(qualifier { $samp.AddQualifier($qualifier.str); } | qualifierExpression { $samp.AddQualifierExpression($qualifierExpression.q); }  )*
		'samplerstate' name = IDENTIFIER { SetupFile(&$samp, _input); }						{ $samp.SetName($name.text); }
		LB ( samplerRow { $samp.ConsumeRow($samplerRow.row); } )* RB SC
	;
	
// a sampler texture list defines a list of textures to which a sampler is to be attached
samplerTextureList	returns [ SamplerTextureList list ]
	:	firstItem = IDENTIFIER { $list.AddTexture($firstItem.text); } (CO nextItem = IDENTIFIER { $list.AddTexture($nextItem.text); })*
	;
	
samplerRow	returns [ SamplerRow row ]
	: flag1 = IDENTIFIER EQ samplerMode = IDENTIFIER SC
	{
		std::string flag($flag1.text);
		$row.SetString(flag, $samplerMode.text);
	}
	| flag2 = IDENTIFIER EQ expression SC
	{
		std::string flag($flag2.text);
		$row.SetExpression(flag, $expression.tree);
	}
	| flag4 = IDENTIFIER EQ LB samplerTextureList RB SC
	{
		std::string flag($flag4.text);
		
		if (flag == "Samplers") $row.SetTextures($samplerTextureList.list);
		else					$row.SetString(flag, "Incorrectly formatted texture list"); 
	}
	| flag5 = IDENTIFIER EQ LB red = expression CO green = expression CO blue = expression CO alpha = expression RB SC
	{
		std::string flag($flag5.text);
		$row.SetFloat4(flag, $red.tree, $green.tree, $blue.tree, $alpha.tree);
	}
	;
	
// program block, must have a vertex shader and pixel shader, the four other shaders are optional
programRow	returns [ ProgramRow row ]
	: shader = IDENTIFIER EQ name = IDENTIFIER 
	LP 
	(var = IDENTIFIER EQ implementation = IDENTIFIER 
	{ $row.SetSubroutineMapping($var.text, $implementation.text); } 
	)? 
	(CO var2 = IDENTIFIER EQ implementation2 = IDENTIFIER 
	{ $row.SetSubroutineMapping($var2.text, $implementation2.text); } 
	)*
	RP
	SC
	{
		std::string shaderString($shader.text);
		$row.SetString(shaderString, $name.text);
	}
	| 'RenderState' EQ IDENTIFIER SC
	{
		$row.SetString("RenderState", $IDENTIFIER.text);
	}
	| 'CompileFlags' EQ string SC
	{
		$row.SetString("CompileFlags", $string.val.c_str());		
	}
	;

// annotations can be any user-specific data which can be read
annotation	returns [ Annotation annot ]
	: 	
	LL	
	(type IDENTIFIER EQ 
		( string { $annot.AddString($string.val); } | expression { $annot.AddExpression($expression.tree); }
		) SC { $annot.AddType($type.ty); $annot.AddName($IDENTIFIER.text);  }
	)* 
	RR { SetupFile(&$annot, _input); }
	;
	
// a program is a complete pipeline
program		returns [ Program prog ]
	: 	'program' IDENTIFIER { SetupFile(&$prog, _input); }
		(annotation { $prog.SetAnnotation($annotation.annot); })? LB 
		{ $prog.SetName($IDENTIFIER.text);  }
		(programRow { $prog.ConsumeRow($programRow.row); })* RB SC 
	;

// an expression in AnyFX is a constant time expression which can be evaluated during compile time
expression	returns [ Expression* tree ]
					@init
					{
						$tree = nullptr;
					}
	:	binaryexp7 { $tree = $binaryexp7.tree; }
	;
	
// start of with ||
binaryexp7	returns [ Expression* tree ]
					@init
					{
						Expression* prev = nullptr;
						$tree = nullptr;
					}
					:
					e1 = binaryexp6 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); } ( ( LOGICOR ) e2 = binaryexp6
					{ 
						Expression* lhs = nullptr;
												
						if (prev)
						{
							lhs = new BinaryExpression("||", prev, $e2.tree); 
						}
						else
						{
							lhs = new BinaryExpression("||", $e1.tree, $e2.tree); 
						}
						
						SetupFile(lhs, _input);
						prev = lhs;
						$tree = lhs;
					}
					)*
					;	
					
// then solve &&	
binaryexp6			returns [ Expression* tree ]
					@init
					{
						Expression* prev = nullptr;
						$tree = nullptr;
					}
					:
					e1 = binaryexp5 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); } ( ( LOGICAND ) e2 = binaryexp5
					{ 
						Expression* lhs = nullptr;
												
						if (prev)
						{
							lhs = new BinaryExpression("&&", prev, $e2.tree); 
						}
						else
						{
							lhs = new BinaryExpression("&&", $e1.tree, $e2.tree); 
						}
						
						SetupFile(lhs, _input);
						prev = lhs;
						$tree = lhs;
					}
					)*
					;
					
//  == and !=										
binaryexp5			returns [ Expression* tree ]
					@init
					{
						Expression* prev = nullptr;
						$tree = nullptr;
					}
					: 
					e1 = binaryexp4 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); } ( op = ( LOGICEQ | NOTEQ ) e2 = binaryexp4
					{ 
						Expression* lhs = nullptr;
												
						if (prev)
						{
							lhs = new BinaryExpression($op.text, prev, $e2.tree); 
						}
						else
						{
							lhs = new BinaryExpression($op.text, $e1.tree, $e2.tree); 
						}
						
						SetupFile(lhs, _input);
						prev = lhs;
						$tree = lhs;
					}
					)*
					;
					
// <, >, <= and >=			
binaryexp4			returns [ Expression* tree ]
					@init
					{
						Expression* prev = nullptr;
						$tree = nullptr;
					}
					:
					e1 = binaryexp3 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); } ( op = ( LESS | GREATER | LESSEQ | GREATEREQ ) e2 = binaryexp3
					{ 
						Expression* lhs = nullptr;
												
						if (prev)
						{
							lhs = new BinaryExpression($op.text, prev, $e2.tree); 
						}
						else
						{
							lhs = new BinaryExpression($op.text, $e1.tree, $e2.tree); 
						}
						
						SetupFile(lhs, _input);
						prev = lhs;
						$tree = lhs;
					}
					)*
					;
					
// + and -	
binaryexp3			returns [ Expression* tree ]
					@init
					{
						Expression* prev = nullptr;
						$tree = nullptr;
					}
					:					
					e1 = binaryexp2 { $tree = $e1.tree; $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); } ( op = ( ADD_OP | SUB_OP ) e2 = binaryexp2
					{ 
						Expression* lhs = nullptr;
												
						if (prev)
						{
							lhs = new BinaryExpression($op.text, prev, $e2.tree); 
						}
						else
						{
							lhs = new BinaryExpression($op.text, $e1.tree, $e2.tree); 
						}
						
						SetupFile(lhs, _input);
						prev = lhs;
						$tree = lhs;
					}
					)*
					;

// * and /
binaryexp2			returns [ Expression* tree ]
					@init
					{
						Expression* prev = nullptr;
						$tree = nullptr;
					}
					:
					e1 = binaryexp1 { $tree = $e1.tree; $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); } ( op = ( MUL_OP | DIV_OP ) e2 = binaryexp1
					{ 
						Expression* lhs = nullptr;
						
						if (prev)
						{
							lhs = new BinaryExpression($op.text, prev, $e2.tree); 
						}
						else
						{
							lhs = new BinaryExpression($op.text, $e1.tree, $e2.tree); 
						}
						
						SetupFile(lhs, _input);
						prev = lhs;
						$tree = lhs;
					}
					)*
					;
					
// unary expressions. Create chain of unary expressions by removing one token from the left and create new unary expressions
binaryexp1			returns [ Expression* tree ]
					@init
					{
						char operat = 0;
						$tree = nullptr;
					}
					:
					( op = (SUB_OP | NOT)  )? e1 = binaryexpatom
					{ 
						Expression* rhs = $e1.tree;
						
						if ($op != 0)
						{
							operat = $op.text.c_str()[0];
							rhs = new UnaryExpression(operat, rhs);
						}
						
						SetupFile(rhs, _input);
						$tree = rhs;					                                                
					
					}
					;

// end of binary expansion, in the end, every expression can be expressed as either an ID or a new expression surrounded by paranthesis.
binaryexpatom		returns [ Expression* tree ]
					@init
					{
						$tree = nullptr;
					}
					:
					INTEGERLITERAL  	{ $tree = new IntExpression(atoi($INTEGERLITERAL.text.c_str())); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); }
					| FLOATLITERAL  	{ $tree = new FloatExpression(atof($FLOATLITERAL.text.c_str())); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); }
					| DOUBLELITERAL		{ $tree = new FloatExpression(atof($DOUBLELITERAL.text.c_str())); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine());}
					| boolean  		
					{ 
						$tree = new BoolExpression($boolean.val);		
						SetupFile($tree, _input);
					}
					| parantexpression { $tree = $parantexpression.tree; }
					;
					
// expands an expression surrounded by paranthesis
parantexpression	returns [ Expression* tree ]
					@init
					{
						$tree = nullptr;
					}
					:
					LP expression RP { $tree = $expression.tree; }
					;



SC:				';';
CO: 			',';
COL: 			':';
LP: 			'(';
RP: 			')';
LB: 			'{';
RB: 			'}';
LL: 			'[';
RR: 			']';
DOT:			'.';
NOT:			'!';
EQ: 			'=';
QO: 			'"';
QU:				'?';
AND:			'&';
OR:				'|';
Q: 				'\'';
NU:				'#';
FORWARDSLASH: 	'\\';
LESS: 			'<';
LESSEQ:			'<=';
GREATER: 		'>';
GREATEREQ:		'>=';
LOGICEQ:		'==';
NOTEQ:			'!=';
LOGICAND:		'&&';
LOGICOR:		'||';
MOD:			'%';
UNDERSC:		'_';
	
ADD_OP:			'+';
SUB_OP:			'-';
DIV_OP:			'/';
MUL_OP:         '*';

fragment
INTEGER: ('0'..'9');



INTEGERLITERAL: INTEGER+;

// single line comment begins with // and ends with new line
COMMENT		: ('//' .*? '\n') -> channel(HIDDEN);

// multi line comment begins with /* and ends with */
ML_COMMENT	: '/*' .*? '*/' -> channel(HIDDEN);

FLOATLITERAL
	:	INTEGERLITERAL DOT INTEGER* EXPONENT? 'f'
	|	DOT INTEGER* EXPONENT? 'f'
	|	INTEGERLITERAL EXPONENT? 'f'
	;

EXPONENT: ('e'|'E') ('+'|'-')? INTEGERLITERAL;

DOUBLELITERAL 
	: 	INTEGERLITERAL DOT INTEGER* EXPONENT?
	|	DOT INTEGERLITERAL* EXPONENT?
	|	INTEGERLITERAL EXPONENT
	;

HEX
	: '0' 'x' ('0'..'9' | 'a'..'f')*
	;
	
// Any alphabetical character, both lower and upper case
fragment
ALPHABET	: ('A'..'Z'|'a'..'z');

// Identifier, must begin with alphabetical token, but can be followed by integer literal or underscore
IDENTIFIER			: (UNDERSC)* ALPHABET (ALPHABET|INTEGERLITERAL|UNDERSC)*;
			 	
WS	: ( '\t' | ' ' | '\r' | '\n' | '\u000C' )+  -> channel(HIDDEN);