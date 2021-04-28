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

uint32_t
StringToFourCC(const std::string& str)
{
    uint32_t fourcc = 0;
    for (int i = 0, shift = 0; i < str.size(); i++)
    {
        fourcc |= uint32_t(str.c_str()[i]) << shift;
        shift += 8;
    }
    return fourcc;
}

int currentLine = 0;
int lineOffset = 0;
std::vector<std::tuple<int, size_t, size_t, size_t, std::string>> lines;
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
#include "ast/alias.h"
#include "ast/annotation.h"
#include "ast/effect.h"
#include "ast/function.h"
#include "ast/program.h"
#include "ast/renderstate.h"
#include "ast/samplerstate.h"
#include "ast/state.h"
#include "ast/structure.h"
#include "ast/symbol.h"
#include "ast/variable.h"
#include "ast/statements/breakstatement.h"
#include "ast/statements/continuestatement.h"
#include "ast/statements/declarationstatement.h"
#include "ast/statements/expressionstatement.h"
#include "ast/statements/forstatement.h"
#include "ast/statements/ifstatement.h"
#include "ast/statements/returnstatement.h"
#include "ast/statements/scopestatement.h"
#include "ast/statements/statement.h"
#include "ast/statements/switchstatement.h"
#include "ast/statements/whilestatement.h"
#include "ast/expressions/accessexpression.h"
#include "ast/expressions/accessexpression.h"
#include "ast/expressions/arrayindexexpression.h"
#include "ast/expressions/binaryexpression.h"
#include "ast/expressions/boolexpression.h"
#include "ast/expressions/callexpression.h"
#include "ast/expressions/expression.h"
#include "ast/expressions/floatexpression.h"
#include "ast/expressions/intexpression.h"
#include "ast/expressions/stringexpression.h"
#include "ast/expressions/symbolexpression.h"
#include "ast/expressions/ternaryexpression.h"
#include "ast/expressions/unaryexpression.h"

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
        alias ';'                   { $eff->symbols.push_back($alias.sym); }
        | functionDeclaration ';'   { $eff->symbols.push_back($functionDeclaration.sym); }    
        | function                  { $eff->symbols.push_back($function.sym); }    
        | variable ';'              { $eff->symbols.push_back($variable.sym); }
        | structure ';'             { $eff->symbols.push_back($structure.sym); }
        | state ';'                 { $eff->symbols.push_back($state.sym); }
        | program ';'               { $eff->symbols.push_back($program.sym); }
    )*?;

alias
    returns[ Alias* sym ]
    @init
    {
        $sym = nullptr;
        std::string name;
        std::string type;
    }
    : 'alias' name = IDENTIFIER 'as' type = IDENTIFIER { name = $name.text; type = $type.text; }
    {
        $sym = new Alias();
        $sym->name = name;
        $sym->type = type;
    }
    ;

// metarule for annotation - API layer data to be passed to program reading shader
annotation
    returns[ Annotation annot ]:
        ('@' (name = IDENTIFIER '(' value = expression ')' { $annot.name = $name.text; $annot.value = $value.tree; }))
    ;
    
// metarule for attribute - compiler layer data to be passed to target language compiler
attribute
    returns[ Attribute attr ]: 
    name = IDENTIFIER '(' expression ')' { $attr.name = $name.text; $attr.expression = $expression.tree; } 
    | name = IDENTIFIER { $attr.name = $name.text; $attr.expression = nullptr; }
    ;

variable
    returns[ Variable* sym ]
    @init
    {
        $sym = nullptr;
        Symbol::Location location;
        std::vector<Annotation> annotations;
        std::vector<Attribute> attributes;
        std::vector<std::vector<Expression*>> initializers;
        std::vector<std::string> initializerTypes;
        Expression* arraySizeExpression = nullptr;
        bool isArray = false;
    }:
    (annotation { annotations.push_back($annotation.annot); })*
    (attribute { attributes.push_back($attribute.attr); })*
    type = IDENTIFIER name = IDENTIFIER { location = SetupFile(); } 
    
    // array related stuff
    ( 
        '[' (expression { arraySizeExpression = $expression.tree; } )? ']' { isArray = true; } 
    )?

    // initializer stuff
    ( 
         
        // first method, array initialization array is { TYPE(VALUE), TYPE(VALUE) }
        ( '=' '{' 
            // type
            initType0 = IDENTIFIER 
            { 
                initializerTypes.push_back($initType0.text); 
                std::vector<Expression*> values0;
            } 
            // first value
            '(' 
                (
                    value0 = expression { values0.push_back($value0.tree); }
                    (','
                        valuen = expression { values0.push_back($valuen.tree); }
                    )*
                )
            ')' 
            {
                initializers.push_back(values0);
            }
            // rest of values
            (',' 
                initType1 = IDENTIFIER 
                { 
                    initializerTypes.push_back($initType1.text);
                    std::vector<Expression*> values1;
                } 
                '(' 
                    (
                        value1 = expression { values1.push_back($value1.tree); }
                        (','
                            valuen = expression { values1.push_back($valuen.tree); }
                        )*
                    )
                ')'
                {
                    initializers.push_back(values1);
                }
            )*
            '}'
        )
        | 
        // second method, initialization type is inferred, array is: { {0.5f, 0.5f} -> implicitly vec2  }
        ( '=' '{'
            // type
            { 
                initializerTypes.push_back(""); 
                std::vector<Expression*> values0;
            } 
            // first value
            '{' 
                (value0 = expression { values0.push_back($value0.tree); })+ 
            '}' 
            {
                initializers.push_back(values0);
            }
            // rest of values
            (',' 
                { 
                    initializerTypes.push_back("");
                    std::vector<Expression*> values1;
                } 
                '{' 
                    (value1 = expression { values1.push_back($value1.tree); })+
                '}'
                {
                    initializers.push_back(values1);
                }
            )*
            '}'
        )    
        |
        // single value initialization
        (
            '=' value = expression { std::vector<Expression*> expressions { $value.tree }; initializers.push_back(expressions); initializerTypes.push_back(""); }
        )
    )?
    { 
        $sym = new Variable(); 
        $sym->type = $type.text; 
        $sym->name = $name.text; 
        $sym->location = location; 
        $sym->annotations = annotations; 
        $sym->initializers = initializers;
        $sym->initializerTypes = initializerTypes;
        $sym->attributes = attributes;
        $sym->arraySizeExpression = arraySizeExpression;
        $sym->isArray = isArray;
    }
    ;

structureDeclaration
    returns[ Structure* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Annotation> annotations;
        std::vector<Attribute> attributes;
        Symbol::Location location;
    }:
    (annotation { annotations.push_back($annotation.annot); })*
    'struct' 
    (attribute { attributes.push_back($attribute.attr); })*
    name = IDENTIFIER 
    { 
        $sym = new Structure(); location = SetupFile(); 
        $sym->name = $name.text; 
        $sym->annotations = annotations;
        $sym->attributes = attributes;
        $sym->location = location; 
    }
    ;

structure
    returns[ Structure* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Variable*> variables;
        bool isArray;
        Expression* arraySizeExpression = nullptr;
        std::string instanceName;
    }:
    structureDeclaration { $sym = $structureDeclaration.sym; }
    '{' 
        (variable { variables.push_back($variable.sym); } ';')* 
    '}' 
    // tail, like } myStruct[];
    (
        instanceName = IDENTIFIER { instanceName = $instanceName.text; }
        ( '[' (expression { arraySizeExpression = $expression.tree; })? ']' { isArray = true; } )?
    )?
    { 
        $sym->members = variables; 
        $sym->instanceName = instanceName;
        $sym->isArray = isArray;
        $sym->arraySizeExpression = arraySizeExpression;
    }
    ;

functionDeclaration
    returns[ Function* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Variable*> variables;
        std::vector<Attribute> attributes;
        Symbol::Location location;
    }:
    (attribute { attributes.push_back($attribute.attr); })*
    returnType = IDENTIFIER name = IDENTIFIER { location = SetupFile(); } '(' (arg0 = variable { variables.push_back($arg0.sym); } (',' argn = variable { variables.push_back($argn.sym); })* )? ')' 
    {
        $sym = new Function(); 
        $sym->hasBody = false;
        $sym->location = location;
        $sym->returnType = $returnType.text; 
        $sym->name = $name.text; 
        $sym->parameters = variables; 
        $sym->attributes = attributes; 
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
    }:
    functionDeclaration { $sym = $functionDeclaration.sym; }
    {
        startToken = _input->LT(2);
    }
    scopeStatement
    {
        endToken = _input->LT(-2);

        // extract code from between tokens
        antlr4::misc::Interval interval;
        interval.a = startToken->getTokenIndex();
        interval.b = endToken->getTokenIndex();
        $sym->body = _input->getText(interval);
        $sym->hasBody = true;
        $sym->ast = $scopeStatement.tree;
    } 
    ;

program
    returns[ Program* sym ]
    @init
    {
        $sym = nullptr;
        Symbol::Location location;
        std::vector<Program::SubroutineMapping> subroutines;
        std::vector<Expression*> entries;
        std::vector<Annotation> annotations;
    }:
    (annotation { annotations.push_back($annotation.annot); })*
    'program' name = IDENTIFIER { location = SetupFile(); }
    '{'
        ( assignment = expression { entries.push_back($assignment.tree); } ';' )*
    '}'
    { 
        $sym = new Program();
        $sym->location = location;
        $sym->name = $name.text;
        $sym->annotations = annotations;
        $sym->entries = entries;
    }
    ;

state
    returns[ State* sym ]
    @init
    {
        Expression* arrayExpression = nullptr;
        Symbol::Location location;
        std::vector<Expression*> entries;
    }:
    (
        'sampler_state' { $sym = new SamplerState(); }
        | 'render_state' { $sym = new RenderState(); } 
    ) name = IDENTIFIER { location = SetupFile(); }
    '{'
        (assign = expression { entries.push_back($assign.tree); } ';' )*
    '}'
    {
        $sym->name = $name.text;
        $sym->location = location;
        $sym->entries = entries;
    }
    ;

declaration
    returns[ Symbol* sym ]:
    variable    { $sym = $variable.sym; }
    ;

statement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
    }:
    declarationStatement ';'    { $tree = $declarationStatement.tree; }
    | ifStatement               { $tree = $ifStatement.tree; }
    | scopeStatement            { $tree = $scopeStatement.tree; }
    | forStatement              { $tree = $forStatement.tree; }
    | whileStatement            { $tree = $whileStatement.tree; }
    | returnStatement           { $tree = $returnStatement.tree; }
    | continueStatement         { $tree = $continueStatement.tree; }
    | breakStatement            { $tree = $breakStatement.tree; }
    | expressionStatement       { $tree = $expressionStatement.tree; }
    | ';'                       // empty statement
    ;

// expression as a statement, basically supposing the expression will have a side effect
expressionStatement
    returns[ Statement* tree ]
    @init 
    {
        $tree = nullptr;
    }: 
    expression ';'
    {
        $tree = new ExpressionStatement($expression.tree);
        $tree->location = SetupFile();
    }
    ;

declarationStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        std::vector<std::string> qualifiers;
        std::vector<Expression*> arrayExpressions;
        Expression* initializer = nullptr;
    }:
    (qualifier = IDENTIFIER { qualifiers.push_back($qualifier.text); })
    type = IDENTIFIER name = IDENTIFIER ('[' arraySize = expression ']' { arrayExpressions.push_back($arraySize.tree); })*
    ('=' expression { initializer = $expression.tree; } )?
    {
        $tree = new DeclarationStatement($type.text, $name.text, qualifiers, initializer);
        $tree->location = SetupFile();
    }
    ;

ifStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        Expression* condition = nullptr;
        Statement* ifBody = nullptr;
        Statement* elseBody = nullptr;
        Symbol::Location location;
    }:
    'if' { location = SetupFile(); } '(' condition = expression { condition = $condition.tree; } ')' 
    ifBody = statement { ifBody = $ifBody.tree; }
    
    ('else' elseBody = statement { elseBody = $elseBody.tree; })?
    {
        $tree = new IfStatement(condition, ifBody, elseBody);
        $tree->location = location;
    }
    ;

forStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        std::vector<Symbol*> declarations;
        Expression* conditionExpression = nullptr;
        std::vector<Expression*> expressions;
        Statement* contents = nullptr;
        Symbol::Location location;
    }:
    'for' { location = SetupFile(); }
    '(' 
        (declare0 = declaration { declarations.push_back($declare0.sym); } (',' declaren = declaration { declarations.push_back($declaren.sym); })* )? ';' 
        (condition = expression { conditionExpression = $condition.tree; })? ';' 
        (expression0 = expression { expressions.push_back($expression0.tree); } (',' expressionn = expression { expressions.push_back($expressionn.tree); })* )?
    ')'
    content = statement { contents = $content.tree; }
    {
        $tree = new ForStatement(declarations, conditionExpression, expressions, contents);
        $tree->location = location;
    }
    ;

forRangeStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        Statement* contents = nullptr;
        Symbol::Location location;
    }:
    'for' { location = SetupFile(); } '(' iterator = IDENTIFIER ':' start = IDENTIFIER '.' '.' end = IDENTIFIER ')'
    content = statement { contents = $content.tree; }
    {

    }
    ;

whileStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        Expression* conditionExpression = nullptr;
        Statement* contents = nullptr;
        bool isDoWhile = false;
        Symbol::Location location;
    }:
    'while' { location = SetupFile(); } '(' condition = expression { conditionExpression = $condition.tree; } ')'
    content = statement { contents = $content.tree; }
    | 'do' { location = SetupFile(); }
    content = statement { contents = $content.tree; isDoWhile = true; } 
    'while' '(' condition = expression { conditionExpression = $condition.tree; } ')'
    {
        $tree = new WhileStatement(conditionExpression, contents, isDoWhile);
        $tree->location = location;
    }
    ;

scopeStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        std::vector<Symbol*> contents;
        Symbol::Location location;
    }:
    '{' { location = SetupFile(); }
    (
        content = statement { contents.push_back($content.tree); }
        | declare = declaration { contents.push_back($declare.sym); }
    )* 
    '}'
    {
        $tree = new ScopeStatement(contents);
        $tree->location = location;
    }
    ;

returnStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        Expression* returnValue = nullptr;
        Symbol::Location location;
    }:
    'return' { location = SetupFile(); } (value = expression { returnValue = $value.tree; })? ';'
    {
        $tree = new ReturnStatement(returnValue);
    }
    ;

continueStatement
    returns[ Statement* tree ]
    @init 
    {
        $tree = nullptr;
        Symbol::Location location;
    }: 
    'continue' { location = SetupFile(); } ';' 
    {
        $tree = new ContinueStatement();
    }
    ;

switchStatement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
        Expression* switchExpression;
        std::vector<std::string> caseValues;
        std::vector<Statement*> caseStatements;
        Symbol::Location location;
        Statement* defaultStatement = nullptr;
    }:
    'switch' { location = SetupFile(); } '(' expression ')' { switchExpression = $expression.tree; }
    '{'
        (
            'case' IDENTIFIER ':'
            statement
            { 
                caseValues.push_back($IDENTIFIER.text); 
                caseStatements.push_back($statement.tree);
            }
        )*
        (
            'default' ':'
            statement
            {
                defaultStatement = $statement.tree;
            }
        )?
    '}'
    {
        $tree = new SwitchStatement(switchExpression, caseValues, caseStatements);
    }
    ;

breakStatement
    returns[ Statement* tree ]
    @init 
    {
        $tree = nullptr;
        Symbol::Location location;
    }: 
    'break' ';'
    {
        $tree = new BreakStatement();
    }
    ;

// an expression is any symbol that can evaluate to a certain value or type
expression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }: 
    binaryexp12 { $tree = $binaryexp12.tree; }
    ;

// start of with ||
binaryexp12
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp11 { $tree = $e1.tree; } 
    (
        op = ('+=' | '-=' | '*=' | '/=' | '%=' | '<<=' | '>>=' | '&=' | '^=' | '|=' | '=') { ops.push_back(StringToFourCC($op.text)); } e2 = binaryexp11 { exprs.push_back($e2.tree); }
        | '?' ifBody = expression ':' elseBody = expression
        { 
            exprs.push_back(new TernaryExpression($ifBody.tree, $elseBody.tree));
            ops.push_back(StringToFourCC("?:"));
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// start of with ||
binaryexp11
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp10 { $tree = $e1.tree; } 
    (
        ('||') e2 = binaryexp10
        {
            ops.push_back(StringToFourCC("||"));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// then solve &&
binaryexp10
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp9 { $tree = $e1.tree; } 
    (
        ('&&') e2 = binaryexp9
        {
            ops.push_back(StringToFourCC("&&"));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// |
binaryexp9
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp8 { $tree = $e1.tree; } 
    (
        ('|') e2 = binaryexp8
        {
            ops.push_back(StringToFourCC("|"));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// ^
binaryexp8
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp7 { $tree = $e1.tree; } 
    (
        ('^') e2 = binaryexp7
        {
            ops.push_back(StringToFourCC("^"));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// &
binaryexp7
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp6 { $tree = $e1.tree;	} 
    (
        ('&') e2 = binaryexp6
        {
            ops.push_back(StringToFourCC("&"));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// == and !=
binaryexp6
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp5 { $tree = $e1.tree; } 
    (
        op = ('==' | '!=') e2 = binaryexp5
        {
            ops.push_back(StringToFourCC($op.text));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// <, >, <= and >=
binaryexp5
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp4 { $tree = $e1.tree;	} 
    (
        op = ('<' | '>' | '<=' | '>=') e2 = binaryexp4
        {
            ops.push_back(StringToFourCC($op.text));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// <<, >>
binaryexp4
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp3 { $tree = $e1.tree;	} 
    (
        op = ('<<' | '>>') e2 = binaryexp3 
        {
            ops.push_back(StringToFourCC($op.text));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// + and -
binaryexp3
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp2 { $tree = $e1.tree; } 
    (
        op = ('+' | '-') e2 = binaryexp2 
        {
            ops.push_back(StringToFourCC($op.text));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// * and /
binaryexp2
    returns[ Expression* tree ]
    @init 
    {
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
        $tree = nullptr;
    }:
    e1 = binaryexp1 { $tree = $e1.tree; }
    (
        op = ('*' | '/' | '%') e2 = binaryexp1 
        {
            ops.push_back(StringToFourCC($op.text));
            exprs.push_back($e2.tree);
        }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// unary expressions. Create chain of unary expressions by removing one token from the left and create new unary expressions
binaryexp1
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    (op = ('-' | '+' | '!' | '~' | '++' | '--'))? e1 = binaryexp0 
    {
        $tree = $e1.tree;
        if ($op != nullptr)
        {
            uint32_t op = StringToFourCC($op.text);
            $tree = new UnaryExpression(op, 0x0, $e1.tree);
        }

        $tree->location = SetupFile();
    }
    ;

// unary expressions. Create chain of unary expressions by removing one token from the left and create new unary expressions
binaryexp0
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
        std::vector<Expression*> exprs;
        std::vector<uint32_t> ops;
    }:
    e1 = binaryexpatom (op = ('++' | '--'))? 
    {
        $tree = $e1.tree;
        if ($op != nullptr)
        {
            uint32_t op = StringToFourCC($op.text);
            $tree = new UnaryExpression(0x0, op, $e1.tree);
        }

        $tree->location = SetupFile();
    }
    | e1 = binaryexpatom 
    (
        callExpression { ops.push_back(StringToFourCC("()")); exprs.push_back($callExpression.tree); } 
        | accessExpression { ops.push_back(StringToFourCC(".")); exprs.push_back($accessExpression.tree); } 
        | arrayIndexExpression { ops.push_back(StringToFourCC("[]")); exprs.push_back($arrayIndexExpression.tree); }
    )*
    {
        Expression* lhs = $e1.tree;
        
        int i;
        for ( i = 0; i < exprs.size(); i++)
        {
            lhs = new BinaryExpression(ops[i], lhs, exprs[i]); 
        }

        $tree = lhs;
        $tree->location = SetupFile();
    }
    ;

// end of binary expansion, in the end, every expression can be expressed as either an ID or a new expression surrounded by paranthesis.
binaryexpatom
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    INTEGERLITERAL          { $tree = new IntExpression(atoi($INTEGERLITERAL.text.c_str())); $tree->location = SetupFile(); }
    | FLOATLITERAL          { $tree = new FloatExpression(atof($FLOATLITERAL.text.c_str())); $tree->location = SetupFile(); }
    | DOUBLELITERAL         { $tree = new FloatExpression(atof($DOUBLELITERAL.text.c_str())); $tree->location = SetupFile(); }
    | HEX                   { $tree = new IntExpression(strtoul($HEX.text.c_str(), nullptr, 16)); $tree->location = SetupFile(); }
    | string                { $tree = new StringExpression($string.val); $tree->location = SetupFile(); }
    | IDENTIFIER            { $tree = new SymbolExpression($IDENTIFIER.text); $tree->location = SetupFile(); }
    | boolean               { $tree = new BoolExpression($boolean.val); $tree->location = SetupFile(); }
    | parantExpression      { $tree = $parantExpression.tree; }
    ;

// expands an expression surrounded by paranthesis
parantExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }: '(' expression ')' { $tree = $expression.tree; };

callExpression
    returns[ Expression* tree ]
    @init
    {
        $tree = nullptr;
        std::vector<Expression*> args;
        Symbol::Location location;
    }:
    '(' { location = SetupFile(); }  (arg0 = expression {args.push_back($arg0.tree); } (',' argn = expression { args.push_back($argn.tree); })* )? ')'
    {
        $tree = new CallExpression(args);
        $tree->location = SetupFile();
    }
    ;

accessExpression
    returns[ Expression* tree ]
    @init
    {
        $tree = nullptr;
        Symbol::Location location;
    }:
    '.' expression
    {
        $tree = new AccessExpression($expression.tree);
        $tree->location = SetupFile();
    }
    ;

arrayIndexExpression
    returns[ Expression* tree ]
    @init
    {
        $tree = nullptr;
        Symbol::Location location;
    }:
    '[' expression { location = SetupFile(); } ']'  
    {
        $tree = new ArrayIndexExpression($expression.tree);
        $tree->location = SetupFile();
    }
    ;

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
