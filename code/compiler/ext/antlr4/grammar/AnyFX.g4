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
#include "ast/enumeration.h"
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
#include "ast/statements/expressionstatement.h"
#include "ast/statements/forstatement.h"
#include "ast/statements/ifstatement.h"
#include "ast/statements/returnstatement.h"
#include "ast/statements/scopestatement.h"
#include "ast/statements/statement.h"
#include "ast/statements/switchstatement.h"
#include "ast/statements/whilestatement.h"
#include "ast/expressions/accessexpression.h"
#include "ast/expressions/arrayindexexpression.h"
#include "ast/expressions/binaryexpression.h"
#include "ast/expressions/boolexpression.h"
#include "ast/expressions/callexpression.h"
#include "ast/expressions/commaexpression.h"
#include "ast/expressions/expression.h"
#include "ast/expressions/floatexpression.h"
#include "ast/expressions/initializerexpression.h"
#include "ast/expressions/intexpression.h"
#include "ast/expressions/stringexpression.h"
#include "ast/expressions/symbolexpression.h"
#include "ast/expressions/ternaryexpression.h"
#include "ast/expressions/uintexpression.h"
#include "ast/expressions/unaryexpression.h"
#include "util.h"

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
        | enumeration ';'           { $eff->symbols.push_back($enumeration.sym); }
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

typeDeclaration
    returns[ Type::FullType type ]
    @init
    {
        $type.name = "";
        Expression* arraySizeExpression = nullptr;
    }:
    IDENTIFIER { $type.name = $IDENTIFIER.text; } 
    ;

variable
    returns[ Variable* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Annotation> annotations;
        std::vector<Attribute> attributes;
        Expression* nameExpression = nullptr;
        Symbol::Location location;
    }:
    (annotation { annotations.push_back($annotation.annot); })*
    (attribute { attributes.push_back($attribute.attr); })*
    typeDeclaration { location = SetupFile(); } var0 = expression { nameExpression = $var0.tree; }
    {
        $sym = new Variable(); 
        $sym->type = $typeDeclaration.type; 
        $sym->location = location; 
        $sym->annotations = annotations; 
        $sym->attributes = attributes;
        $sym->nameExpression = nameExpression;
    }
    ;

structureDeclaration
    returns[ Structure* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Annotation> annotations;
        std::vector<Attribute> attributes;
    }:
    (annotation { annotations.push_back($annotation.annot); })*
    'struct' 
    (attribute { attributes.push_back($attribute.attr); })*
    name = IDENTIFIER 
    { 
        $sym = new Structure();
        $sym->name = $name.text; 
        $sym->annotations = annotations;
        $sym->attributes = attributes;
        $sym->location = SetupFile();
    }
    ;

structure
    returns[ Structure* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<Variable*> variables;
        bool isArray = false;
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

enumeration
    returns[ Enumeration* sym ]
    @init
    {
        $sym = nullptr;
        std::vector<std::string> enumLabels;
        std::vector<Expression*> enumValues;
    }:
    'enum' name = IDENTIFIER
    '{'
        label = IDENTIFIER { Expression* expr = nullptr; } ('=' value = expression { expr = $value.tree; })?
        {
            enumLabels.push_back($label.text);
            enumValues.push_back(expr);
        }
    '}'
    {
        $sym = new Enumeration(enumLabels, enumValues);
        $sym->location = SetupFile();
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
    returnType = typeDeclaration name = IDENTIFIER { location = SetupFile(); } '(' (arg0 = variable { variables.push_back($arg0.sym); } (',' argn = variable { variables.push_back($argn.sym); })* )? ')' 
    {
        $sym = new Function(); 
        $sym->hasBody = false;
        $sym->location = location;
        $sym->returnType = $returnType.type; 
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

statement
    returns[ Statement* tree ]
    @init
    {
        $tree = nullptr;
    }:
    ifStatement               { $tree = $ifStatement.tree; }
    | scopeStatement            { $tree = $scopeStatement.tree; }
    | forStatement              { $tree = $forStatement.tree; }
    | whileStatement            { $tree = $whileStatement.tree; }
    | returnStatement           { $tree = $returnStatement.tree; }
    | continueStatement         { $tree = $continueStatement.tree; }
    | breakStatement            { $tree = $breakStatement.tree; }
    | expressionStatement ';'   { $tree = $expressionStatement.tree; }
    ;

// expression list as a statement, basically supposing the expression will have a side effect
expressionStatement
    returns[ Statement* tree ]
    @init 
    {
        $tree = nullptr;
    }: 
    expression
    {
        $tree = new ExpressionStatement($expression.tree);
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
        Symbol* declaration;
        Expression* conditionExpression = nullptr;
        Statement* loopStatement;
        Statement* contents = nullptr;
        Symbol::Location location;
    }:
    'for' { location = SetupFile(); }
    '(' 
        variable { declaration = $variable.sym; } ';'
        (condition = expression { conditionExpression = $condition.tree; })? ';' 
        expressionStatement { loopStatement = $expressionStatement.tree; }
    ')'
    content = statement { contents = $content.tree; }
    {
        $tree = new ForStatement(declaration, conditionExpression, loopStatement, contents);
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
    'for' { location = SetupFile(); } '(' iterator = IDENTIFIER ':' start = IDENTIFIER '..' end = IDENTIFIER ')'
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
    {
        $tree = new WhileStatement(conditionExpression, contents, isDoWhile);
        $tree->location = location;
    }
    | 'do' { location = SetupFile(); }
    content = statement { contents = $content.tree; isDoWhile = true; } 
    'while' '(' condition = expression { conditionExpression = $condition.tree; } ')' ';'
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
        statement { contents.push_back($statement.tree); }
        | variable ';' { contents.push_back($variable.sym); }
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
        $tree = new SwitchStatement(switchExpression, caseValues, caseStatements, defaultStatement);
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
    commaExpression { $tree = $commaExpression.tree; }
    ;

commaExpression
    returns[ Expression* tree ]
    @init
    {
        $tree = nullptr;
    }:
    e1 = assignmentExpression { $tree = $e1.tree; }
    (
        ',' e2 = assignmentExpression
        {
            CommaExpression* expr = new CommaExpression($tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// start of with ||
assignmentExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = logicalOrExpression { $tree = $e1.tree; } 
    (
        op = ('+=' | '-=' | '*=' | '/=' | '%=' | '<<=' | '>>=' | '&=' | '^=' | '|=' | '=') e2 = logicalOrExpression
        { 
            BinaryExpression* expr = new BinaryExpression(StringToFourCC($op.text), $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        } 
        | '?' ifBody = expression ':' elseBody = expression
        { 
            TernaryExpression* expr = new TernaryExpression($tree, $ifBody.tree, $elseBody.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// start of with ||
logicalOrExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = logicalAndExpression { $tree = $e1.tree; } 
    (
        ('||') e2 = logicalAndExpression
        {
            BinaryExpression* expr = new BinaryExpression('||', $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// then solve &&
logicalAndExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = orExpression { $tree = $e1.tree; } 
    (
        ('&&') e2 = orExpression
        {
            BinaryExpression* expr = new BinaryExpression('&&', $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// |
orExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = xorExpression { $tree = $e1.tree; } 
    (
        ('|') e2 = xorExpression
        {
            BinaryExpression* expr = new BinaryExpression('|', $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// ^
xorExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = andExpression { $tree = $e1.tree; } 
    (
        ('^') e2 = andExpression
        {
            BinaryExpression* expr = new BinaryExpression('^', $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// &
andExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = equivalencyExpression { $tree = $e1.tree;	} 
    (
        ('&') e2 = equivalencyExpression
        {
            BinaryExpression* expr = new BinaryExpression('&', $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// == and !=
equivalencyExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = relationalExpression { $tree = $e1.tree; } 
    (
        op = ('==' | '!=') e2 = relationalExpression
        {
            BinaryExpression* expr = new BinaryExpression(StringToFourCC($op.text), $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// <, >, <= and >=
relationalExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = shiftExpression { $tree = $e1.tree; } 
    (
        op = ('<' | '>' | '<=' | '>=') e2 = shiftExpression
        {
            BinaryExpression* expr = new BinaryExpression(StringToFourCC($op.text), $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// <<, >>
shiftExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = addSubtractExpression { $tree = $e1.tree; } 
    (
        op = ('<<' | '>>') e2 = addSubtractExpression 
        {
            BinaryExpression* expr = new BinaryExpression(StringToFourCC($op.text), $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// + and -
addSubtractExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = multiplyDivideExpression { $tree = $e1.tree; } 
    (
        op = ('+' | '-') e2 = multiplyDivideExpression 
        {
            BinaryExpression* expr = new BinaryExpression(StringToFourCC($op.text), $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// * and /
multiplyDivideExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    e1 = prefixExpression { $tree = $e1.tree; }
    (
        op = ('*' | '/' | '%') e2 = prefixExpression 
        {
            BinaryExpression* expr = new BinaryExpression(StringToFourCC($op.text), $tree, $e2.tree);
            expr->location = SetupFile();
            $tree = expr;
        }
    )*
    ;

// unary expressions. Create chain of unary expressions by removing one token from the left and create new unary expressions
prefixExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
        std::vector<uint32_t> ops;
        std::vector<Symbol::Location> locations;
    }:
    (op = ('-' | '+' | '!' | '~' | '++' | '--' | '*') { ops.push_back(StringToFourCC($op.text)); locations.push_back(SetupFile()); } )* e1 = suffixExpression 
    {
        $tree = $e1.tree;
        $tree->location = SetupFile();
        for (size_t i = 0; i < ops.size(); i++)
        {
            $tree = new UnaryExpression(ops[i], 0x0, $tree);
            $tree->location = locations[i];
        }
    }
    ;

// unary expressions. Create chain of unary expressions by removing one token from the left and create new unary expressions
suffixExpression
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;

        Symbol::Location location;
        std::vector<Expression*> args;
        Expression* arrayIndexExpr = nullptr;

        std::vector<uint32_t> ops;
        std::vector<Symbol::Location> locations;
    }:
    e1 = binaryexpatom (op = ('++' | '--') { ops.push_back(StringToFourCC($op.text)); locations.push_back(SetupFile()); } )* 
    {
        $tree = $e1.tree;
        $tree->location = SetupFile();
        for (size_t i = 0; i < ops.size(); i++)
        {
            $tree = new UnaryExpression(0x0, ops[i], $tree);
            $tree->location = locations[i];
        }

    }
    | e1 = binaryexpatom
    {
        $tree = $e1.tree;
    }
    (
        '(' { location = SetupFile(); } (arg0 = expression {args.push_back($arg0.tree); } (',' argn = expression { args.push_back($argn.tree); })* )? ')'
        {
            CallExpression* expr = new CallExpression($tree, args);
            expr->location = location;
            $tree = expr;
        }
        | '.' { location = SetupFile(); } e2 = expression
        {
            AccessExpression* expr = new AccessExpression($tree, $e2.tree, false);
            expr->location = location;
            $tree = expr;
        }
        | '->' { location = SetupFile(); } e2 = expression
        {
            AccessExpression* expr = new AccessExpression($tree, $e2.tree, true);
            expr->location = location;
            $tree = expr;
        }
        | '[' { location = SetupFile(); } (e2 = expression { arrayIndexExpr = $e2.tree; })? ']'
        {
            ArrayIndexExpression* expr = new ArrayIndexExpression($tree, arrayIndexExpr);
            expr->location = location;
            $tree = expr;
        }
    )*
    ;


// end of binary expansion, in the end, every expression can be expressed as either an ID or a new expression surrounded by paranthesis.
binaryexpatom
    returns[ Expression* tree ]
    @init 
    {
        $tree = nullptr;
    }:
    INTEGERLITERAL          { $tree = new IntExpression(atoi($INTEGERLITERAL.text.c_str())); $tree->location = SetupFile(); }
    | UINTEGERLITERAL       { $tree = new UIntExpression(strtoul($UINTEGERLITERAL.text.c_str(), nullptr, 10)); $tree->location = SetupFile(); }
    | FLOATLITERAL          { $tree = new FloatExpression(atof($FLOATLITERAL.text.c_str())); $tree->location = SetupFile(); }
    | DOUBLELITERAL         { $tree = new FloatExpression(atof($DOUBLELITERAL.text.c_str())); $tree->location = SetupFile(); }
    | HEX                   { $tree = new UIntExpression(strtoul($HEX.text.c_str(), nullptr, 16)); $tree->location = SetupFile(); }
    | string                { $tree = new StringExpression($string.val); $tree->location = SetupFile(); }
    | IDENTIFIER            { $tree = new SymbolExpression($IDENTIFIER.text); $tree->location = SetupFile(); }
    | boolean               { $tree = new BoolExpression($boolean.val); $tree->location = SetupFile(); }
    | initializerExpression { $tree = $initializerExpression.tree; }
    | '(' expression ')'    { $tree = $expression.tree; }
    ;

initializerExpression
    returns[ Expression* tree ]
    @init
    {
        $tree = nullptr;
        std::vector<Expression*> exprs;
    }:
    '{' ( arg0 = assignmentExpression { exprs.push_back($arg0.tree); } (',' argN = assignmentExpression { exprs.push_back($argN.tree); })* )? '}'
    {
        $tree = new InitializerExpression(exprs);
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

ARROW: '->';

fragment INTEGER: ('0' .. '9');

INTEGERLITERAL: INTEGER+;
UINTEGERLITERAL: INTEGER+ ('u' | 'U');

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
