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
Symbol::Location
SetupFile(bool updateLine = true)
{
    Symbol::Location location;
    if (this->lines.empty())
        return location;
    ::AnyFXToken* token = (::AnyFXToken*)_input->LT(-1);

    if (updateLine)
        UpdateLine(_input, -1);

    // assume the previous token is the latest file
    auto tu2 = this->lines[this->currentLine];
    location.file = std::get<4>(tu2);
    location.line = lineOffset;
    location.column = token->getCharPositionInLine();
    return location;
}

// update and get current line
void
UpdateLine(antlr4::TokenStream* stream, int index = -1)
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
#include "v3/ast/annotations.h"
#include "v3/ast/attributable.h"
#include "v3/ast/blendstate.h"
#include "v3/ast/compoundresource.h"
#include "v3/ast/effect.h"
#include "v3/ast/function.h"
#include "v3/ast/program.h"
#include "v3/ast/renderstate.h"
#include "v3/ast/state.h"
#include "v3/ast/structure.h"
#include "v3/ast/resource.h"
#include "v3/ast/symbol.h"
#include "v3/ast/typedresource.h"
#include "v3/ast/variable.h"
#include "expressions/expression.h"
#include "expressions/binaryexpression.h"
#include "expressions/unaryexpression.h"
#include "expressions/intexpression.h"
#include "expressions/boolexpression.h"
#include "expressions/floatexpression.h"
#include "expressions/stringexpression.h"
#include "expressions/symbolexpression.h"

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
    returns[ Effect* returnEffect ]:
    effect {
        $returnEffect = $effect.eff;
    } EOF;

// entry point for effect, call this function to begin parsing
effect
    returns[ Effect* eff ]
    @init
    {
        $eff = new Effect();
    }
    :
    (
        function                { $eff->symbols.push_back($function.sym); }    
        | variable              { $eff->symbols.push_back($variable.sym); }
        | compound_resource     { $eff->symbols.push_back($compound_resource.sym); }
        | structure             { $eff->symbols.push_back($structure.sym); }    
        | state                 { $eff->symbols.push_back($state.sym); }
        | program               { $eff->symbols.push_back($program.sym); }
    )*?;

// metarule for annotation - API layer data to be passed to program reading shader
annotations
    returns[ Annotations annot ]:
        '[' (name = IDENTIFIER '=' value = expression ';' { $annot.entries.push_back({$name.text, $value.tree}); }) (',' name2 = IDENTIFIER '=' value2 = expression ';' { $annot.entries.push_back({$name2.text, $value2.tree}); })* ']'
    ;
    
// metarule for attribute - compiler layer data to be passed to target language compiler
attribute
    returns[ Attribute attr ]: 
    name = IDENTIFIER '(' expression ')' { $attr.name = $name.text; $attr.expression = $expression.tree; } 
    | name = IDENTIFIER { $attr.name = $name.text; $attr.expression = nullptr; }
    ;

compound_resource
    returns[ CompoundResource* sym ]
    @init
    {
        $sym = new CompoundResource();
        Symbol::Location location;
        Annotations annot;
        std::vector<Attribute> attributes;
        std::vector<Variable*> variables;
        std::string instanceName;
        Expression* arraySizeExpression = nullptr;
        bool isArray = false;
    }:
    (attribute { attributes.push_back($attribute.attr); })*
    type = ('buffer'|'constant') name = IDENTIFIER { location = SetupFile(); } 
    (annotations { annot = $annotations.annot; })?

    // body
    '{'
        (variable { variables.push_back($variable.sym); })+
    '}'

    // tail, like } myStruct[];
    (
        instanceName = IDENTIFIER { instanceName = $instanceName.text; }
        ( '[' (expression { arraySizeExpression = $expression.tree; })? ']' { isArray = true; } )?
    )?
    ';'
    {
        $sym = new CompoundResource();
        $sym->location = location;
        $sym->name = $name.text; 
        $sym->type = $type.text;
        $sym->annotations = annot;
        $sym->variables = variables;
        $sym->instanceName = instanceName;
        $sym->arraySizeExpression = arraySizeExpression;
        $sym->isArray = isArray;
    }
    ;

variable
    returns[ Variable* sym ]
    @init
    {
        $sym = nullptr;
        Symbol::Location location;
        std::vector<Attribute> attributes;
        Annotations annot;
        Expression* arraySizeExpression = nullptr;
        bool isArray = false;
    }:
    (attribute { attributes.push_back($attribute.attr); })*
    type = IDENTIFIER name = IDENTIFIER { location = SetupFile(); } 
    (annotations { annot = $annotations.annot; })?
    ( '[' (expression { arraySizeExpression = $expression.tree; } )? ']' { isArray = true; } )?
    ';'
    { 
        $sym = new Variable(); 
        $sym->type = $type.text; 
        $sym->name = $name.text; 
        $sym->location = location; 
        $sym->annotations = annot; 
        $sym->arraySizeExpression = arraySizeExpression;
        $sym->isArray = isArray;
    }
    ;

structure
    returns[ Structure* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Variable*> variables;
        Symbol::Location location;
    }:
    'struct' name = IDENTIFIER { $sym = new Structure(); location = SetupFile(); }
    '{' 
        (variable { variables.push_back($variable.sym); })* 
    '}' ';' 
    { 
        $sym = new Structure(); 
        $sym->name = $name.text; 
        $sym->location = location; 
        $sym->variables = variables; 
    }
    ;

// metarule for the code content of a function
codeblock: '{' (codeblock)* '}' | ~('{' | '}');

function
    returns[ Function* sym ]
    @init
    {
        $sym = nullptr;
        Token* startToken = nullptr;
        Token* endToken = nullptr;
        Symbol::Location location;
        std::vector<Variable*> variables;
        std::vector<Attribute> attributes;
        std::string body;
    }:
    (attribute { attributes.push_back($attribute.attr); })*
    returnType = IDENTIFIER name = IDENTIFIER { location = SetupFile(); } '(' (arg0 = variable { variables.push_back($arg0.sym); } (',' argn = variable { variables.push_back($argn.sym); })*)? ')' 
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
        body = _input->getText(interval);

    } 
    { 
        $sym = new Function(); 
        $sym->returnType = $returnType.text; 
        $sym->name = $name.text; 
        $sym->location = location; 
        $sym->parameters = variables; 
        $sym->attributes = attributes; 
        $sym->code = body; 
    }
    ;

program
    returns[ Program* sym ]
    @init
    {
        $sym = nullptr;
        Symbol::Location location;
        std::vector<Program::SubroutineMapping> subroutines;
        std::vector<Program::Entry> entries;
        Annotations annot;
    }:
    'program' name = IDENTIFIER { location = SetupFile(); }
    (annotations { annot = $annotations.annot; })?
    '{'
        (id = IDENTIFIER '=' value = IDENTIFIER { subroutines.clear(); } 
        '(' 
            (func = IDENTIFIER '=' subroutine = IDENTIFIER  { subroutines.push_back({$func.text, $subroutine.text}); })* 
        ')' ';'
        { entries.push_back({$id.text, $value.text, subroutines}); }
        )*
    '}'
    ';'
    { 
        $sym = new Program();
        $sym->location = location;
        $sym->name = $name.text;
        $sym->annotations = annot;
        $sym->entries = entries;
    }
    ;

state
    returns[ State* sym ]
    @init
    {
        Expression* arrayExpression = nullptr;
        Symbol::Location location;
        std::vector<State::Entry> entries;
    }:
    (
        'blend_state' { $sym = new BlendState(); }
        | 'render_state' { $sym = new RenderState(); } 
    ) name = IDENTIFIER { location = SetupFile(); }
    '{'
        (id = IDENTIFIER { arrayExpression = nullptr; } ('[' index = expression { arrayExpression = $index.tree; } ']')? value = expression { entries.push_back({$id.text, $value.tree, arrayExpression}); }) ';'
    '}'
    ';'
    {
        $sym->name = $name.text;
        $sym->location = location;
        $sym->entries = entries;
    }
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
    e1 = binaryexp6 { $tree = $e1.tree;	$tree->location = SetupFile(); } 
    (
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

                        lhs->location = SetupFile();
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
    e1 = binaryexp5 { $tree = $e1.tree;	$tree->location = SetupFile(); } 
    (
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

                        lhs->location = SetupFile();
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
    e1 = binaryexp4 { $tree = $e1.tree;	$tree->location = SetupFile(); } 
    (
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

                        lhs->location = SetupFile();
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
    e1 = binaryexp3 { $tree = $e1.tree;	$tree->location = SetupFile(); } 
    (
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

                        lhs->location = SetupFile();
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
    e1 = binaryexp2 { $tree = $e1.tree; $tree->location = SetupFile(); } 
    (
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

                        lhs->location = SetupFile();
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
    e1 = binaryexp1 { $tree = $e1.tree; $tree->location = SetupFile(); }
    (
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

                        lhs->location = SetupFile();
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

                        rhs->location = SetupFile();
                        $tree = rhs;

                    };

// end of binary expansion, in the end, every expression can be expressed as either an ID or a new expression surrounded by paranthesis.
binaryexpatom
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    INTEGERLITERAL  { $tree = new IntExpression(atoi($INTEGERLITERAL.text.c_str())); $tree->location = SetupFile(); }
    | FLOATLITERAL  { $tree = new FloatExpression(atof($FLOATLITERAL.text.c_str())); $tree->location = SetupFile(); }
    | DOUBLELITERAL { $tree = new FloatExpression(atof($DOUBLELITERAL.text.c_str())); $tree->location = SetupFile(); }
    | HEX           { $tree = new IntExpression(strtoul($HEX.text.c_str(), nullptr, 16)); $tree->location = SetupFile(); }
    | string        { $tree = new StringExpression($string.val); $tree->location = SetupFile(); }
    | IDENTIFIER    { $tree = new SymbolExpression($IDENTIFIER.text); $tree->location = SetupFile(); }
    | boolean       { $tree = new BoolExpression($boolean.val); $tree->location = SetupFile(); }
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
