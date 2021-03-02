grammar AnyFX;

options {
    language = Cpp;
    backtracking = true;
}

// Lexer API hooks
@lexer::apifuncs {

}

@lexer::members {
#include <iostream>

misc::Interval interval;
std::string currentFile;
int currentLine = 0;
}

@lexer::header {
    #include <string>
    #include <vector>
    #include "anyfxtoken.h"
}

// parser API hooks
@parser::apifuncs {

}

@parser::members {
// setup function which binds the compiler state to the current AST node
void SetupFile(AnyFX::Compileable* comp, antlr4::TokenStream* stream, bool updateLine = true)
{
    if (this->lines.empty())
        return;
    ::AnyFXToken* token = (::AnyFXToken*)stream->LT(-1);

    if (updateLine)
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
          // look ahead, if the next line is beyond the token, abort
          if (std::get<1>(this->lines[loop + 1]) > tokenLine)
              break;
          else
              loop++;
      }

      auto line = this->lines[loop];
      this->currentLine = loop;

      // where the target compiler expects the output token to be and where we put it may differ
      // so we calculate a padding between the token and the #line directive output by the preprocessing stage (which includes the #line token line)
      int padding = (tokenLine - 1) - std::get<1>(line);
      this->lineOffset = std::get<0>(line) + padding;
}

int currentLine = 0;
int lineOffset = 0;
std::vector<std::tuple<int, int, int, int, std::string>> lines;
}

// parser includes
@parser::header {

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>

#include "anyfxtoken.h"
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
#include "../../code/expressions/symbolexpression.h"
using namespace AnyFX;

}

string
    returns[ std::string val ]:
    QO (data = ~QO { $val.append($data.text); })* QO
    | Q (data = ~Q { $val.append($data.text); })* Q;

boolean
    returns[ bool val ]
    @init {
        $val = false;
    }: 'true' { $val = true; } | 'false' { $val = false; };

// preprocess
preprocess
    @init {
        Token* start = nullptr;
    }:
    (
        { start = _input->LT(1); } '#line' line = INTEGERLITERAL path = string { lines.push_back(std::make_tuple(atoi($line.text.c_str()), _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), $path.text)); }
        | .
    )*? EOF;

// main entry point
entry
    returns[ Effect returnEffect ]:
    effect {
        $returnEffect = $effect.eff;
    } EOF;

// entry point for effect, call this function to begin parsing
effect
    returns[ Effect eff ]:
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
    )*?;

// add qualifiers here
qualifier
    returns[ std::string str ]
    @init {
    Token* startToken = _input->LT(1);
}
    @after {
    $str = startToken->getText();
}:
    'const'
    | 'shared'
    | 'push'

    // shader and function parameter qualifiers
    | 'flat'
    | 'noperspective'
    | 'no_perspective'
    | 'patch'
    | 'in'
    | 'out'
    | 'inout'
    | 'in_out'

    // compute qualifier
    | 'groupshared'
    | 'group_shared'

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
    | 'read_write';

qualifierValued
    returns[ std::string str ]
    @init {
    Token* startToken = _input->LT(1);
}
    @after {
    $str = startToken->getText();
}: 'group' | 'index' | 'binding';

// all types are declared in this expression here, we define all variable types from both HLSL and
// GLSL up to the latest release
type
    returns[ DataType ty ]:
    IDENTIFIER {
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
    };

// setup a special type of qualifier which is numbered
qualifierExpression
    returns[ QualifierExpression q ]:
    base = qualifierValued parantexpression { $q.name = $base.str; $q.expr = $parantexpression.tree; 
        };

// we can also define structs outside the function scopes
structure
    returns[ Structure struc ]:
    'struct' IDENTIFIER { SetupFile(&$struc, _input); } '{' (
        parameter ';' { $struc.AddParameter($parameter.param); }
    )* '}' ';' { $struc.SetName($IDENTIFIER.text);  };

// a varblock denotes a block within which we can find variables, using this structure, we can feed
// variables in chunks instead of individually, which may improve performance this is equal to
// DirectX constant buffers or OpenGL uniform block since this is just a special way of denoting a
// structure, we give it some extra attributes such as shared, which means this will structure will
// go in a shared dictionary, and be EQUAL to every shader utilizing this block
varblock
    returns[ VarBlock block ]:
    (
        qualifier { $block.AddQualifier($qualifier.str); }
        | qualifierExpression { $block.AddQualifierExpression($qualifierExpression.q); }
    )* ('constant') name = IDENTIFIER { SetupFile(&$block, _input); $block.SetName($name.text); } (
        annotation { $block.SetAnnotation($annotation.annot); }
    )? '{' (variable { $block.AddVariable($variable.var); })* '}' 
    (varName = IDENTIFIER { $block.SetStructName($varName.text); } 
        ('['']' { $block.SetArrayExpression(nullptr); } | 
        '[' arraySize = expression ']' { $block.SetArrayExpression($arraySize.tree); })?
    )? 
     ';';

// a varbuffer denotes a data type which has a dynamic size. varbuffers are much like varblocks, but
// they support for having its last member as an unsized array, and can support writing to the
// buffer in OpenGL this is known as a shader storage block.
varbuffer
    returns[ VarBuffer buffer ]:
    (
        qualifier { $buffer.AddQualifier($qualifier.str); }
        | qualifierExpression { $buffer.AddQualifierExpression($qualifierExpression.q); }
    )* 
    ('rw_buffer') name = IDENTIFIER { SetupFile(&$buffer, _input); $buffer.SetName($name.text); }
    (
        annotation { $buffer.SetAnnotation($annotation.annot); }
    )? 
    '{' (variable {$buffer.AddVariable($variable.var); })* '}' 
    (varName = IDENTIFIER { $buffer.SetStructName($varName.text); } 
        ('['']' { $buffer.SetArrayExpression(nullptr); } | 
        '[' arraySize = expression ']' { $buffer.SetArrayExpression($arraySize.tree); })?
    )? 
    ';';

// a subroutine denotes a function which can be dynamically switched without switching shader
// states. there are two implementations of a subroutine, the first being the subroutine variable
// which is a 'variable' which corresponds to a function. then there is the other which is an
// implementation based on an interface.
subroutine
    returns[ Subroutine subrout ]:
    'prototype' retval = type name = IDENTIFIER { SetupFile(&$subrout, _input); } '(' parameterList
        ')' ';' {
        $subrout.SetSubroutineType(Subroutine::Signature);
        $subrout.SetName($name.text);
        $subrout.SetParameters($parameterList.parameters);
        $subrout.SetReturnType($retval.ty);
    }
    | 'subroutine' '(' signature = IDENTIFIER ')' { SetupFile(&$subrout, _input); } function {
        $subrout.SetName($function.func.GetName());
        $subrout.SetSubroutineType(Subroutine::Implementation);
        $subrout.SetSignature($signature.text);
        $subrout.SetFunction($function.func);
    };

// values can be initialized with literal values by using the default constructor
valueList
    returns[ ValueList valList ]:
    first = expression { $valList.AddValue($first.tree); } (
        ',' rest = expression { $valList.AddValue($rest.tree); }
    )*;

// values can also be initialized with a single value, this is basically a valueList but with just a single value
valueSingleList
    returns[ ValueList valList ]:
    expression { $valList.AddValue($expression.tree); };

// variable is type, name and semicolon
variable
    returns[ Variable var ]:
    (
        qualifier { $var.AddQualifier($qualifier.str); }
        | qualifierExpression { $var.AddQualifierExpression($qualifierExpression.q); }
    )* declType = type name = IDENTIFIER { $var.SetDataType($declType.ty); $var.SetName($name.text); SetupFile(&$var, _input); 
        } (
        // array initializer which assumes the size of the value list
        '[' ']' '=' { $var.SetArrayType(Variable::TypedArray); } '{' fstType = type '(' fstValue =
            valueList ')' { $var.AddValue($fstType.ty, $fstValue.valList); } (
            ',' cntType = type '(' cntValue = valueList ')' { $var.AddValue($cntType.ty, $cntValue.valList); 
                }
        )* '}'
        | '[' ']' '=' { $var.SetArrayType(Variable::SimpleArray); } '{' valList = valueList '}' { $var.AddValue($valList.valList); 
            }
        // array variable
        | (
            '[' asize0 = expression ']' { $var.AddSizeExpression($asize0.tree); $var.SetArrayType(Variable::SimpleArray); }
        )+
        // array initializer for vector types
        | '[' asize1 = expression ']' { $var.AddSizeExpression($asize1.tree); $var.SetArrayType(Variable::TypedArray); 
            } '[' '{' fstType = type '(' fstValue = valueList ')' { $var.AddValue($fstType.ty, $fstValue.valList); 
            } (
            ',' cntType = type '(' cntValue = valueList ')' { $var.AddValue($cntType.ty, $cntValue.valList); 
                }
        )* '}'
        | '[' asize2 = expression ']' { $var.AddSizeExpression($asize2.tree); $var.SetArrayType(Variable::SimpleArray); 
            } '=' '{' valList = valueList '}' { $var.AddValue($valList.valList); }
        // unsized array type, only usable for varbuffers
        | '[' ']' { $var.SetArrayType(Variable::UnsizedArray); }
        // explicit variable initialization
        | '=' defType = type '(' list2 = valueList ')' { $var.AddValue($defType.ty, $list2.valList); 
            }
        // implicit variable initialization, only viable for generic values
        | '=' list3 = valueSingleList { $var.AddValue($list3.valList); }
    )? (annotation { $var.SetAnnotation($annotation.annot); })? ';';

// constant value
constant
    returns[ Constant cons ]:
    'const' declType = type IDENTIFIER { $cons.SetDataType($declType.ty); $cons.SetName($IDENTIFIER.text); SetupFile(&$cons, _input); 
        } (
        // explicit variable initialization
        '=' defType = type '(' sinVal1 = valueList ')' ';' { $cons.AddValue($defType.ty, $sinVal1.valList); 
            }
        // implicit constant initialization, only viable for generic values
        | '=' sinVal2 = valueSingleList ';' { $cons.AddValue($sinVal2.valList); }
        // array initializer which assumes the size of the value list
        | '[' ']' '=' { $cons.SetArrayType(Constant::TypedArray); } '{' fstType = type '(' fstValue
            = valueList ')' { $cons.AddValue($fstType.ty, $fstValue.valList); } (
            ',' cntType = type '(' cntValue = valueList ')' { $cons.AddValue($cntType.ty, $cntValue.valList); 
                }
        )* '}' ';'
        | '[' ']' '=' { $cons.SetArrayType(Constant::SimpleArray); } '{' valList = valueList '}' { $cons.AddValue($valList.valList); 
            } ';'
        // array initializer for vector types
        | '[' asize1 = expression ']' { $cons.SetSizeExpression($asize1.tree); $cons.SetArrayType(Constant::TypedArray); 
            } '=' '{' fstType = type '(' fstValue = valueList ')' { $cons.AddValue($fstType.ty, $fstValue.valList); 
            } (
            ',' cntType = type '(' cntValue = valueList ')' { $cons.AddValue($cntType.ty, $cntValue.valList); 
                }
        )* '}' ';'
        // simple array initializer
        | '[' asize2 = expression ']' { $cons.SetSizeExpression($asize2.tree); $cons.SetArrayType(Constant::SimpleArray); 
            } '=' '{' valList = valueList '}' { $cons.AddValue($valList.valList); } ';'
    );

// parameter modifiers denotes variables with special use, such as vertex position output, instance id _input etc
parameterAttribute
    returns[ Parameter::Attribute attribute ]
    @init {
            $attribute = Parameter::NoAttribute;
        }:
    '[' IDENTIFIER ']' {
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
        };

// defines a parameter, parameters have in/out/inout qualifiers which are used in shaders to denote
// how a variable should be handled default IO for a parameter is _input (as a normal function
// parameter in C)
parameter
    returns[ Parameter param ]:
    (
        '[' attr = IDENTIFIER ']' {
            $param.SetAttribute($attr.text);
        }
    )? (
        '[' 'feedback' '=' '(' feedbackBuffer = expression ',' feedbackOffset = expression ')' ']' {
            $param.SetFeedbackBufferExpression($feedbackBuffer.tree);
            $param.SetFeedbackOffsetExpression($feedbackOffset.tree);
        }
    )? (
        '[' 'slot' '=' slotExpression = expression ']' {
            $param.SetSlotExpression($slotExpression.tree);
        }
    )? (
        qualifier {
            $param.AddQualifier($qualifier.str);
        }
    )* type name = IDENTIFIER { $param.SetDataType($type.ty); $param.SetName($name.text); SetupFile(&$param, _input); 
        } (
        '[' (
            size = expression { $param.SetSizeExpression($size.tree); }
        )? ']' { $param.ForceArrayFlag(); }
    )?;

// parameters can either be in or out
parameterList
    returns[ std::vector<Parameter> parameters ]: (
        firstParam = parameter { $parameters.push_back($firstParam.param); } (
            ',' followParam = parameter { $parameters.push_back($followParam.param); }
        )*
    )?;

// function attributes are used for tessellation, geometry and compute shading
functionAttribute
    returns[ FunctionAttribute attribute ]:
    '[' flag1 = IDENTIFIER ']' '=' expression {
        std::string identifierString($flag1.text);

        $attribute.SetExpression(identifierString, $expression.tree);
    }
    | '[' flag3 = IDENTIFIER ']' {
        std::string identifierString($flag3.text);

        $attribute.SetBool(identifierString, true);
    };

// a code block denotes a series of scopes with contents. we don't need to get any data here, since
// we will fetch it from our surrounding function
codeBlock: '{' (codeBlock)* '}' | ~('{' | '}');

// function is denoted by shader type, function name, parameter list, then code block
function
    returns[ Function func ]
    @init {
            Token* startToken = nullptr;
            Token* endToken = nullptr;
        }: (
        functionAttribute { $func.ConsumeAttribute($functionAttribute.attribute); }
    )* ('shader' { $func.SetShader(true); })? type IDENTIFIER { UpdateLine(_input, -2); $func.SetFunctionLine(this->lineOffset); SetupFile(&$func, _input, false);  } '('
        parameterList ')' {
            // the code block will be after the next right bracket
            startToken = _input->LT(2);

            UpdateLine(_input, 2);
            $func.SetCodeLine(this->lineOffset);
        } codeBlock {
            // save last token
            endToken = _input->LT(-2);

            // get all text inbetween the two tokens
            antlr4::misc::Interval interval;
            interval.a = startToken->getTokenIndex();
            interval.b = endToken->getTokenIndex();
            std::string code = _input->getText(interval);

            // get all text inbetween the two tokens
            if (code.length() > 0) 
                $func.SetCode(code);
        } { $func.SetName($IDENTIFIER.text); $func.SetReturnType($type.ty); $func.SetParameters($parameterList.parameters); 
        };

blendStateRow
    returns[ BlendStateRow row ]:
    flag2 = IDENTIFIER '[' index2 = expression ']' '=' value = expression ';' {
        std::string flag($flag2.text);
        $row.SetExpression($index2.tree, flag, $value.tree);
    };

renderStateRow
    returns[ RenderStateRow row ]:
    flag1 = IDENTIFIER '=' expression ';' {
        std::string flag($flag1.text);
        $row.SetExpression(flag, $expression.tree);
    };

// draw state, contains a series of draw flags
renderState
    returns[ RenderState state ]: ('render_state') IDENTIFIER { SetupFile(&$state, _input); } ';' { $state.SetName($IDENTIFIER.text); 
        }
    | ('render_state') IDENTIFIER { SetupFile(&$state, _input); } '{' { $state.SetName($IDENTIFIER.text); 
        } (
        renderStateRow { $state.ConsumeRenderRow($renderStateRow.row); }
        | blendStateRow { $state.ConsumeBlendRow($blendStateRow.row); }
    )* '}' ';';

// a sampler explains how to sample textures
sampler
    returns[ Sampler samp ]: (
        qualifier { $samp.AddQualifier($qualifier.str); }
        | qualifierExpression { $samp.AddQualifierExpression($qualifierExpression.q); }
    )* ('sampler_state') name = IDENTIFIER { SetupFile(&$samp, _input); } ';' { $samp.SetName($name.text); 
        }
    | (
        qualifier { $samp.AddQualifier($qualifier.str); }
        | qualifierExpression { $samp.AddQualifierExpression($qualifierExpression.q); }
    )* ('sampler_state') name = IDENTIFIER { SetupFile(&$samp, _input); } { $samp.SetName($name.text); 
        } '{' (samplerRow { $samp.ConsumeRow($samplerRow.row); })* '}' ';';

// a sampler texture list defines a list of textures to which a sampler is to be attached
samplerTextureList
    returns[ SamplerTextureList list ]:
    firstItem = IDENTIFIER { $list.AddTexture($firstItem.text); } (
        ',' nextItem = IDENTIFIER { $list.AddTexture($nextItem.text); }
    )*;

samplerRow
    returns[ SamplerRow row ]:
    flag1 = IDENTIFIER '=' samplerMode = IDENTIFIER ';' {
        std::string flag($flag1.text);
        $row.SetString(flag, $samplerMode.text);
    }
    | flag2 = IDENTIFIER '=' expression ';' {
        std::string flag($flag2.text);
        $row.SetExpression(flag, $expression.tree);
    }
    | flag4 = IDENTIFIER '=' '{' samplerTextureList '}' ';' {
        std::string flag($flag4.text);

        if (flag == "Samplers") $row.SetTextures($samplerTextureList.list);
        else					$row.SetString(flag, "Incorrectly formatted texture list");
    };

// program block, must have a vertex shader and pixel shader, the four other shaders are optional
programRow
    returns[ ProgramRow row ]:
    shader = IDENTIFIER '=' name = IDENTIFIER '(' (
        var = IDENTIFIER '=' implementation = IDENTIFIER { $row.SetSubroutineMapping($var.text, $implementation.text); 
            }
    )? (
        ',' var2 = IDENTIFIER '=' implementation2 = IDENTIFIER { $row.SetSubroutineMapping($var2.text, $implementation2.text); 
            }
    )* ')' ';' {
        std::string shaderString($shader.text);
        $row.SetString(shaderString, $name.text);
    }
    | 'RenderState' '=' IDENTIFIER ';' {
        $row.SetString("RenderState", $IDENTIFIER.text);
    };

// annotations can be any user-specific data which can be read
annotation
    returns[ Annotation annot ]:
    '[' (
        type IDENTIFIER '=' (
            string { $annot.AddString($string.val); }
            | expression { $annot.AddExpression($expression.tree); }
        ) ';' { $annot.AddType($type.ty); $annot.AddName($IDENTIFIER.text);  }
    )* ']' { SetupFile(&$annot, _input); };

// a program is a complete pipeline
program
    returns[ Program prog ]:
    'program' IDENTIFIER { SetupFile(&$prog, _input); } (
        annotation { $prog.SetAnnotation($annotation.annot); }
    )? '{' { $prog.SetName($IDENTIFIER.text);  } (
        programRow { $prog.ConsumeRow($programRow.row); }
    )* '}' ';';

// an expression in AnyFX is a constant time expression which can be evaluated during compile time
expression
    returns[ Expression* tree ]
    @init {
                        $tree = nullptr;
                    }: binaryexp7 { $tree = $binaryexp7.tree; };

// start of with ||
binaryexp7
    returns[ Expression* tree ]
    @init {
                        Expression* prev = nullptr;
                        $tree = nullptr;
                    }:
    e1 = binaryexp6 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        } (
        ('||') e2 = binaryexp6 {
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
    )*;

// then solve &&
binaryexp6
    returns[ Expression* tree ]
    @init {
                        Expression* prev = nullptr;
                        $tree = nullptr;
                    }:
    e1 = binaryexp5 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        } (
        ('&&') e2 = binaryexp5 {
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
    )*;

//  == and !=
binaryexp5
    returns[ Expression* tree ]
    @init {
                        Expression* prev = nullptr;
                        $tree = nullptr;
                    }:
    e1 = binaryexp4 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        } (
        op = ('==' | '!=') e2 = binaryexp4 {
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
    )*;

// <, >, <= and >=
binaryexp4
    returns[ Expression* tree ]
    @init {
                        Expression* prev = nullptr;
                        $tree = nullptr;
                    }:
    e1 = binaryexp3 { $tree = $e1.tree;	$tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        } (
        op = ('<' | '>' | '<=' | '>=') e2 = binaryexp3 {
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
    )*;

// + and -
binaryexp3
    returns[ Expression* tree ]
    @init {
                        Expression* prev = nullptr;
                        $tree = nullptr;
                    }:
    e1 = binaryexp2 { $tree = $e1.tree; $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        } (
        op = ('+' | '-') e2 = binaryexp2 {
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
    )*;

// * and /
binaryexp2
    returns[ Expression* tree ]
    @init {
                        Expression* prev = nullptr;
                        $tree = nullptr;
                    }:
    e1 = binaryexp1 { $tree = $e1.tree; $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        } (
        op = (MUL_OP | DIV_OP) e2 = binaryexp1 {
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
    )*;

// unary expressions. Create chain of unary expressions by removing one token from the left and create new unary expressions
binaryexp1
    returns[ Expression* tree ]
    @init {
                        char operat = 0;
                        $tree = nullptr;
                    }:
    (op = (SUB_OP | NOT))? e1 = binaryexpatom {
                        Expression* rhs = $e1.tree;

                        if ($op != 0)
                        {
                            operat = $op.text.c_str()[0];
                            rhs = new UnaryExpression(operat, rhs);
                        }

                        SetupFile(rhs, _input);
                        $tree = rhs;

                    };

// end of binary expansion, in the end, every expression can be expressed as either an ID or a new expression surrounded by paranthesis.
binaryexpatom
    returns[ Expression* tree ]
    @init {
                        $tree = nullptr;
                    }:
    INTEGERLITERAL { $tree = new IntExpression(atoi($INTEGERLITERAL.text.c_str())); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        }
    | FLOATLITERAL { $tree = new FloatExpression(atof($FLOATLITERAL.text.c_str())); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
        }
    | DOUBLELITERAL { $tree = new FloatExpression(atof($DOUBLELITERAL.text.c_str())); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine());
        }
    | HEX { $tree = new IntExpression(strtoul($HEX.text.c_str(), nullptr, 16)); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine());
        }
    | IDENTIFIER { $tree = new SymbolExpression($IDENTIFIER.text); $tree->SetLine(_input->LT(1)->getLine()); $tree->SetPosition(_input->LT(1)->getCharPositionInLine());
        }
    | boolean {
                        $tree = new BoolExpression($boolean.val);
                        SetupFile($tree, _input);
                    }
    | parantexpression { $tree = $parantexpression.tree; };

// expands an expression surrounded by paranthesis
parantexpression
    returns[ Expression* tree ]
    @init {
                        $tree = nullptr;
                    }: '(' expression ')' { $tree = $expression.tree; };

SC: ';';
CO: ',';
COL: ':';
LP: '(';
RP: ')';
LB: '{';
RB: '}';
LL: '[';
RR: ']';
DOT: '.';
NOT: '!';
EQ: '=';
QO: '"';
QU: '?';
AND: '&';
ANDSET: '&=';
OR: '|';
ORSET: '|=';
XOR: '^';
XORSET: '^=';
CONNJUGATE: '~';
Q: '\'';
NU: '#';
FORWARDSLASH: '\\';
LESS: '<';
LESSEQ: '<=';
GREATER: '>';
GREATEREQ: '>=';
LOGICEQ: '==';
NOTEQ: '!=';
LOGICAND: '&&';
LOGICOR: '||';
MOD: '%';
UNDERSC: '_';

ADD_OP: '+';
SUB_OP: '-';
DIV_OP: '/';
MUL_OP: '*';

fragment INTEGER: ('0' ..'9');

INTEGERLITERAL: INTEGER+ ('u' | 'U')?;

// single line comment begins with // and ends with new line
COMMENT: ('//' .*? '\n') -> channel(HIDDEN);

// multi line comment begins with /* and ends with */
ML_COMMENT: '/*' .*? '*/' -> channel(HIDDEN);

FLOATLITERAL:
    INTEGER+ DOT INTEGER* EXPONENT? 'f'
    | DOT INTEGER* EXPONENT? 'f'
    | INTEGER+ EXPONENT? 'f';

EXPONENT: ('e' | 'E') ('+' | '-')? INTEGER+;

DOUBLELITERAL:
    INTEGER+ DOT INTEGER* EXPONENT?
    | DOT INTEGER EXPONENT?
    | INTEGER+ EXPONENT;

HEX: '0' 'x' ('0' ..'9' | 'a' ..'f')* ('u' | 'U')?;

// Any alphabetical character, both lower and upper case
fragment ALPHABET: ('A' ..'Z' | 'a' ..'z');

// Identifier, must begin with alphabetical token, but can be followed by integer literal or underscore
IDENTIFIER: ('_')* ALPHABET (ALPHABET | INTEGERLITERAL | '_')*;

WS: ( '\t' | ' ' | '\r' | '\n' | '\u000C')+ -> channel(HIDDEN);
