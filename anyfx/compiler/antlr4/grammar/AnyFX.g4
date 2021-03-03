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
#include "../../code/v3/compileable.h"
#include "../../code/v3/effect.h"
#include "../../code/v3/function.h"
#include "../../code/v3/variable.h"
#include "../../code/v3/resource.h"
#include "../../code/v3/state.h"
#include "../../code/v3/program.h"
#include "../../code/v3/compoundresource.h"
#include "../../code/v3/typedresource.h"
#include "../../code/v3/attribute.h"
#include "../../code/v3/annotations.h"
#include "../../code/v3/blendstate.h"
#include "../../code/v3/renderstate.h"
using namespace AnyFX;

}

string
    returns[ std::string val ]:
    '"' (data = ~'"' { $val.append($data.text); })* '"'
    | '\'' (data = ~'\'' { $val.append($data.text); })* '\'';

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
        function { eff.AddSymbol($function.sym); }    
        | variable { eff.AddSymbol($variable.sym); }
        | resource { eff.AddSymbol($resource.sym); }
        | structure { eff.AddSymbol($structure.sym); }    
        | state { eff.AddSymbol($state.sym); }
        | program { eff.AddSymbol($program.sym); }
    )*?;

annotations
    returns[ Annotations annot ]:
        '[' (name = IDENTIFIER '=' value = IDENTIFIER { $annot.entries.push_back(std::make_pair($name.text, $value.text)); }) (',' name2 = IDENTIFIER '=' value2 = IDENTIFIER { $annot.entries.push_back(std::make_pair($name2.text, $value2.text)); })* ']'
    ;

compound_resource
    returns[ Symbol* sym ]
    @init
    {
        $sym = new CompoundResource();
    }:
    (qualifier = IDENTIFIER { $sym->qualifiers.push_back($qualifier.text); })*
    type = ('buffer'|'constants') name = IDENTIFIER

    // body
    '{'
        (variable { $sym->variables.push_back($variable.sym); })+
    '}'

    // tail, like } myStruct[];
    (
        instanceName = IDENTIFIER { $sym->instanceName = $instanceName.text; }
        ( '[' (expression { $sym->arraySizeExpression = $expression.tree; })? ']' { $sym->isArray = true; } )?
    )?
    ';'
    ;

typed_resource
    returns[ Symbol* sym ]
    @init
    {
        $sym = new TypedResource();
    }:
    (qualifier = IDENTIFIER { $sym->qualifiers.push_back($qualifier.text); })*
    (type = 
        ('sampler'
        |'image'('2D'|'2DMS'|'3D'|'Cube'|'2DArray'|'3DArray'|'CubeArray')
        |'texture'('2D'|'2DMS'|'3D'|'Cube'|'2DArray'|'3DArray'|'CubeArray')
        )
    ) name = IDENTIFIER

    // array
    ( '[' (expression { $sym->arraySizeExpression = $expression.expr; } )? ']' { $sym->isArray = true;} )?
    ';'
    ;

resource
    returns[ Symbol* sym ]:
    (
        compound_resource
        | typed_resource
    )+
    ;

variable
    returns[ Symbol* sym ]
    @init
    {
        $sym = new Variable();
    }:
    (qualifier = IDENTIFIER { $sym->qualifiers.push_back($qualifier.text); } )* 
    type = IDENTIFIER name = IDENTIFIER { $sym->type = $type.text; $sym->name = $name.text } 
    ';'
    ;

structure
    returns[ Symbol* sym ]
    @init
    {
        $sym = new Struct();
    }:
    'struct' IDENTIFIER 
    '{' 
        (variable { $sym->variables.push_back($variable.sym); })* 
    '}' ';' { $sym->name = $IDENTIFIER.text }
    ;

// metarule for the code content of a function
codeblock: '{' (codeblock)* '}' | ~('{' | '}');

// metarule for attribute
attribute
    returns[ Attribute attr ]: 
    '@' name = IDENTIFIER '=' expression { attr.name = $name.text; attr.expression = $expression.expr; } 
    | '@' name = IDENTIFIER { attr.name = $name.text; attr.expression = nullptr; }
    ;

function
    returns[ Symbol* sym ]
    @init
    {
        $sym = new Function();
        Token* startToken = nullptr;
        Token* endToken = nullptr;
    }:
    (attribute { $sym->attributes.push_back($attributes.attr); })*
    returnType = IDENTIFIER name = IDENTIFIER '(' (variable { $sym->parameters.push_back($variable.sym); })* ')' 
    {
        startToken = _input->LT(2);

    }
    codeblock
    {
        endToken = _input->LT(-2);

        // extract code from between tokens
        antlr4::misc::Interval interval;
        interval.a = startToken->getTokenIndex();
        interval.b = endToken->getTokenIndex();
        std::string code = _input->getText(interval);

        $sym->code = code;
    } { $sym->returnType = $returnType.text; $sym->name = $name.text; }
    ;

program
    returns[ Symbol* sym ]
    @init
    {
        $sym = new Program();
        std::vector<std::pair<std::string, std::string>> subroutines;
    }:
    'program' name = IDENTIFIER
    '{'
        (entry = IDENTIFIER '=' value = IDENTIFIER { $subroutines.clear(); } 
        '(' 
            (func = IDENTIFIER '=' subroutine = IDENTIFIER  { $subroutines.push_back(std::make_pair($func.text, $subroutine.text)); })* 
        ')' ';'
        { $sym->entries.push_back(std::make_tuple($entry.text, $value.text, subroutines)); })*
    '}'
    ';'
    ;

state
    returns[ Symbol* sym ]
    @init
    {
        Expression* arrayExpression = nullptr;
    }:
    (
        'blend_state' { $sym = new BlendState(); }
        | 'render_state' { $sym = new RenderState(); }
    ) name = IDENTIFIER 
    '{'
        (entry = IDENTIFIER { arrayExpression = nullptr; } ('[' index = expression { $arrayExpression = $index.tree; } ']')? value = expression { $sym->entries.push_back(std::make_tuple($entry.text, $value.tree, $arrayExpression)); }) ';'
    '}'
    ';'
    ;


// an expression in AnyFX is a constant time expression which can be evaluated during compile time
expression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }: 
    binaryexp7 { $tree = $binaryexp7.tree; };

// start of with ||
binaryexp7
    returns[ Expression* tree ]
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
    @init 
    {
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
SOBAKA: '@';

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
