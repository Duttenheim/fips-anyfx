

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



// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AnyFXParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, SC = 34, CO = 35, COL = 36, LP = 37, RP = 38, LB = 39, RB = 40, 
    LL = 41, RR = 42, DOT = 43, NOT = 44, EQ = 45, QO = 46, QU = 47, AND = 48, 
    ANDSET = 49, OR = 50, ORSET = 51, XOR = 52, XORSET = 53, CONNJUGATE = 54, 
    Q = 55, NU = 56, FORWARDSLASH = 57, LESS = 58, LESSEQ = 59, GREATER = 60, 
    GREATEREQ = 61, LOGICEQ = 62, NOTEQ = 63, LOGICAND = 64, LOGICOR = 65, 
    MOD = 66, UNDERSC = 67, SOBAKA = 68, ADD_OP = 69, SUB_OP = 70, DIV_OP = 71, 
    MUL_OP = 72, ARROW = 73, INTEGERLITERAL = 74, UINTEGERLITERAL = 75, 
    COMMENT = 76, ML_COMMENT = 77, FLOATLITERAL = 78, EXPONENT = 79, DOUBLELITERAL = 80, 
    HEX = 81, IDENTIFIER = 82, WS = 83
  };

  enum {
    RuleString = 0, RuleBoolean = 1, RulePreprocess = 2, RuleEntry = 3, 
    RuleEffect = 4, RuleAlias = 5, RuleAnnotation = 6, RuleAttribute = 7, 
    RuleTypeDeclaration = 8, RuleVariable = 9, RuleStructureDeclaration = 10, 
    RuleStructure = 11, RuleEnumeration = 12, RuleFunctionDeclaration = 13, 
    RuleCodeblock = 14, RuleFunction = 15, RuleProgram = 16, RuleState = 17, 
    RuleStatement = 18, RuleExpressionStatement = 19, RuleIfStatement = 20, 
    RuleForStatement = 21, RuleForRangeStatement = 22, RuleWhileStatement = 23, 
    RuleScopeStatement = 24, RuleReturnStatement = 25, RuleContinueStatement = 26, 
    RuleSwitchStatement = 27, RuleBreakStatement = 28, RuleExpression = 29, 
    RuleCommaExpression = 30, RuleAssignmentExpression = 31, RuleLogicalOrExpression = 32, 
    RuleLogicalAndExpression = 33, RuleOrExpression = 34, RuleXorExpression = 35, 
    RuleAndExpression = 36, RuleEquivalencyExpression = 37, RuleRelationalExpression = 38, 
    RuleShiftExpression = 39, RuleAddSubtractExpression = 40, RuleMultiplyDivideExpression = 41, 
    RulePrefixExpression = 42, RuleSuffixExpression = 43, RuleBinaryexpatom = 44, 
    RuleInitializerExpression = 45
  };

  AnyFXParser(antlr4::TokenStream *input);
  ~AnyFXParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;



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


  class StringContext;
  class BooleanContext;
  class PreprocessContext;
  class EntryContext;
  class EffectContext;
  class AliasContext;
  class AnnotationContext;
  class AttributeContext;
  class TypeDeclarationContext;
  class VariableContext;
  class StructureDeclarationContext;
  class StructureContext;
  class EnumerationContext;
  class FunctionDeclarationContext;
  class CodeblockContext;
  class FunctionContext;
  class ProgramContext;
  class StateContext;
  class StatementContext;
  class ExpressionStatementContext;
  class IfStatementContext;
  class ForStatementContext;
  class ForRangeStatementContext;
  class WhileStatementContext;
  class ScopeStatementContext;
  class ReturnStatementContext;
  class ContinueStatementContext;
  class SwitchStatementContext;
  class BreakStatementContext;
  class ExpressionContext;
  class CommaExpressionContext;
  class AssignmentExpressionContext;
  class LogicalOrExpressionContext;
  class LogicalAndExpressionContext;
  class OrExpressionContext;
  class XorExpressionContext;
  class AndExpressionContext;
  class EquivalencyExpressionContext;
  class RelationalExpressionContext;
  class ShiftExpressionContext;
  class AddSubtractExpressionContext;
  class MultiplyDivideExpressionContext;
  class PrefixExpressionContext;
  class SuffixExpressionContext;
  class BinaryexpatomContext;
  class InitializerExpressionContext; 

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    std::string val;
    antlr4::Token *data = nullptr;;
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringContext* string();

  class  BooleanContext : public antlr4::ParserRuleContext {
  public:
    bool val;
    BooleanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanContext* boolean();

  class  PreprocessContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *line = nullptr;;
    AnyFXParser::StringContext *path = nullptr;;
    PreprocessContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> INTEGERLITERAL();
    antlr4::tree::TerminalNode* INTEGERLITERAL(size_t i);
    std::vector<StringContext *> string();
    StringContext* string(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PreprocessContext* preprocess();

  class  EntryContext : public antlr4::ParserRuleContext {
  public:
    Effect* returnEffect;
    AnyFXParser::EffectContext *effectContext = nullptr;;
    EntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EffectContext *effect();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EntryContext* entry();

  class  EffectContext : public antlr4::ParserRuleContext {
  public:
    Effect* eff;
    AnyFXParser::AliasContext *aliasContext = nullptr;;
    AnyFXParser::FunctionDeclarationContext *functionDeclarationContext = nullptr;;
    AnyFXParser::FunctionContext *functionContext = nullptr;;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    AnyFXParser::StructureContext *structureContext = nullptr;;
    AnyFXParser::EnumerationContext *enumerationContext = nullptr;;
    AnyFXParser::StateContext *stateContext = nullptr;;
    AnyFXParser::ProgramContext *programContext = nullptr;;
    EffectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AliasContext *> alias();
    AliasContext* alias(size_t i);
    std::vector<FunctionDeclarationContext *> functionDeclaration();
    FunctionDeclarationContext* functionDeclaration(size_t i);
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    std::vector<StructureContext *> structure();
    StructureContext* structure(size_t i);
    std::vector<EnumerationContext *> enumeration();
    EnumerationContext* enumeration(size_t i);
    std::vector<StateContext *> state();
    StateContext* state(size_t i);
    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EffectContext* effect();

  class  AliasContext : public antlr4::ParserRuleContext {
  public:
    Alias* sym;
    antlr4::Token *name = nullptr;;
    antlr4::Token *type = nullptr;;
    AliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AliasContext* alias();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    Annotation annot;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *value = nullptr;;
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AnnotationContext* annotation();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    Attribute attr;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AttributeContext* attribute();

  class  TypeDeclarationContext : public antlr4::ParserRuleContext {
  public:
    Type::FullType type;
    antlr4::Token *identifierToken = nullptr;;
    TypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeDeclarationContext* typeDeclaration();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    Variable* sym;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    AnyFXParser::AttributeContext *attributeContext = nullptr;;
    AnyFXParser::TypeDeclarationContext *typeDeclarationContext = nullptr;;
    AnyFXParser::ExpressionContext *var0 = nullptr;;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeDeclarationContext *typeDeclaration();
    ExpressionContext *expression();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  StructureDeclarationContext : public antlr4::ParserRuleContext {
  public:
    Structure* sym;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    AnyFXParser::AttributeContext *attributeContext = nullptr;;
    antlr4::Token *name = nullptr;;
    StructureDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructureDeclarationContext* structureDeclaration();

  class  StructureContext : public antlr4::ParserRuleContext {
  public:
    Structure* sym;
    AnyFXParser::StructureDeclarationContext *structureDeclarationContext = nullptr;;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    antlr4::Token *instanceName = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    StructureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StructureDeclarationContext *structureDeclaration();
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructureContext* structure();

  class  EnumerationContext : public antlr4::ParserRuleContext {
  public:
    Enumeration* sym;
    antlr4::Token *name = nullptr;;
    antlr4::Token *label = nullptr;;
    AnyFXParser::ExpressionContext *value = nullptr;;
    EnumerationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EnumerationContext* enumeration();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    Function* sym;
    AnyFXParser::AttributeContext *attributeContext = nullptr;;
    AnyFXParser::TypeDeclarationContext *returnType = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::VariableContext *arg0 = nullptr;;
    AnyFXParser::VariableContext *argn = nullptr;;
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeDeclarationContext *typeDeclaration();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  CodeblockContext : public antlr4::ParserRuleContext {
  public:
    CodeblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CodeblockContext *> codeblock();
    CodeblockContext* codeblock(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CodeblockContext* codeblock();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    Function* sym;
    AnyFXParser::FunctionDeclarationContext *functionDeclarationContext = nullptr;;
    AnyFXParser::ScopeStatementContext *scopeStatementContext = nullptr;;
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDeclarationContext *functionDeclaration();
    ScopeStatementContext *scopeStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    Program* sym;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *assignment = nullptr;;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  StateContext : public antlr4::ParserRuleContext {
  public:
    State* sym;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *assign = nullptr;;
    StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StateContext* state();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::IfStatementContext *ifStatementContext = nullptr;;
    AnyFXParser::ScopeStatementContext *scopeStatementContext = nullptr;;
    AnyFXParser::ForStatementContext *forStatementContext = nullptr;;
    AnyFXParser::WhileStatementContext *whileStatementContext = nullptr;;
    AnyFXParser::ReturnStatementContext *returnStatementContext = nullptr;;
    AnyFXParser::ContinueStatementContext *continueStatementContext = nullptr;;
    AnyFXParser::BreakStatementContext *breakStatementContext = nullptr;;
    AnyFXParser::ExpressionStatementContext *expressionStatementContext = nullptr;;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStatementContext *ifStatement();
    ScopeStatementContext *scopeStatement();
    ForStatementContext *forStatement();
    WhileStatementContext *whileStatement();
    ReturnStatementContext *returnStatement();
    ContinueStatementContext *continueStatement();
    BreakStatementContext *breakStatement();
    ExpressionStatementContext *expressionStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionStatementContext* expressionStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *condition = nullptr;;
    AnyFXParser::StatementContext *ifBody = nullptr;;
    AnyFXParser::StatementContext *elseBody = nullptr;;
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStatementContext* ifStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    AnyFXParser::ExpressionContext *condition = nullptr;;
    AnyFXParser::ExpressionStatementContext *expressionStatementContext = nullptr;;
    AnyFXParser::StatementContext *content = nullptr;;
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    ExpressionStatementContext *expressionStatement();
    StatementContext *statement();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStatementContext* forStatement();

  class  ForRangeStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    antlr4::Token *iterator = nullptr;;
    antlr4::Token *start = nullptr;;
    antlr4::Token *end = nullptr;;
    AnyFXParser::StatementContext *content = nullptr;;
    ForRangeStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForRangeStatementContext* forRangeStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *condition = nullptr;;
    AnyFXParser::StatementContext *content = nullptr;;
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    StatementContext *statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WhileStatementContext* whileStatement();

  class  ScopeStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::StatementContext *statementContext = nullptr;;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    ScopeStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScopeStatementContext* scopeStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *value = nullptr;;
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnStatementContext* returnStatement();

  class  ContinueStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    ContinueStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ContinueStatementContext* continueStatement();

  class  SwitchStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::StatementContext *statementContext = nullptr;;
    SwitchStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SwitchStatementContext* switchStatement();

  class  BreakStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    BreakStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BreakStatementContext* breakStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::CommaExpressionContext *commaExpressionContext = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CommaExpressionContext *commaExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  CommaExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::AssignmentExpressionContext *e1 = nullptr;;
    AnyFXParser::AssignmentExpressionContext *e2 = nullptr;;
    CommaExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentExpressionContext *> assignmentExpression();
    AssignmentExpressionContext* assignmentExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CommaExpressionContext* commaExpression();

  class  AssignmentExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::LogicalOrExpressionContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::LogicalOrExpressionContext *e2 = nullptr;;
    AnyFXParser::ExpressionContext *ifBody = nullptr;;
    AnyFXParser::ExpressionContext *elseBody = nullptr;;
    AssignmentExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LogicalOrExpressionContext *> logicalOrExpression();
    LogicalOrExpressionContext* logicalOrExpression(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentExpressionContext* assignmentExpression();

  class  LogicalOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::LogicalAndExpressionContext *e1 = nullptr;;
    AnyFXParser::LogicalAndExpressionContext *e2 = nullptr;;
    LogicalOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LogicalAndExpressionContext *> logicalAndExpression();
    LogicalAndExpressionContext* logicalAndExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicalOrExpressionContext* logicalOrExpression();

  class  LogicalAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::OrExpressionContext *e1 = nullptr;;
    AnyFXParser::OrExpressionContext *e2 = nullptr;;
    LogicalAndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OrExpressionContext *> orExpression();
    OrExpressionContext* orExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicalAndExpressionContext* logicalAndExpression();

  class  OrExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::XorExpressionContext *e1 = nullptr;;
    AnyFXParser::XorExpressionContext *e2 = nullptr;;
    OrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<XorExpressionContext *> xorExpression();
    XorExpressionContext* xorExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OrExpressionContext* orExpression();

  class  XorExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::AndExpressionContext *e1 = nullptr;;
    AnyFXParser::AndExpressionContext *e2 = nullptr;;
    XorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndExpressionContext *> andExpression();
    AndExpressionContext* andExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  XorExpressionContext* xorExpression();

  class  AndExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::EquivalencyExpressionContext *e1 = nullptr;;
    AnyFXParser::EquivalencyExpressionContext *e2 = nullptr;;
    AndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EquivalencyExpressionContext *> equivalencyExpression();
    EquivalencyExpressionContext* equivalencyExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AndExpressionContext* andExpression();

  class  EquivalencyExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::RelationalExpressionContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::RelationalExpressionContext *e2 = nullptr;;
    EquivalencyExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RelationalExpressionContext *> relationalExpression();
    RelationalExpressionContext* relationalExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EquivalencyExpressionContext* equivalencyExpression();

  class  RelationalExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::ShiftExpressionContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::ShiftExpressionContext *e2 = nullptr;;
    RelationalExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ShiftExpressionContext *> shiftExpression();
    ShiftExpressionContext* shiftExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelationalExpressionContext* relationalExpression();

  class  ShiftExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::AddSubtractExpressionContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::AddSubtractExpressionContext *e2 = nullptr;;
    ShiftExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AddSubtractExpressionContext *> addSubtractExpression();
    AddSubtractExpressionContext* addSubtractExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ShiftExpressionContext* shiftExpression();

  class  AddSubtractExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::MultiplyDivideExpressionContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::MultiplyDivideExpressionContext *e2 = nullptr;;
    AddSubtractExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplyDivideExpressionContext *> multiplyDivideExpression();
    MultiplyDivideExpressionContext* multiplyDivideExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AddSubtractExpressionContext* addSubtractExpression();

  class  MultiplyDivideExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::PrefixExpressionContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::PrefixExpressionContext *e2 = nullptr;;
    MultiplyDivideExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PrefixExpressionContext *> prefixExpression();
    PrefixExpressionContext* prefixExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiplyDivideExpressionContext* multiplyDivideExpression();

  class  PrefixExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    antlr4::Token *op = nullptr;;
    AnyFXParser::SuffixExpressionContext *e1 = nullptr;;
    PrefixExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SuffixExpressionContext *suffixExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrefixExpressionContext* prefixExpression();

  class  SuffixExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::BinaryexpatomContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::ExpressionContext *arg0 = nullptr;;
    AnyFXParser::ExpressionContext *argn = nullptr;;
    AnyFXParser::ExpressionContext *e2 = nullptr;;
    SuffixExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BinaryexpatomContext *binaryexpatom();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SuffixExpressionContext* suffixExpression();

  class  BinaryexpatomContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    antlr4::Token *integerliteralToken = nullptr;;
    antlr4::Token *uintegerliteralToken = nullptr;;
    antlr4::Token *floatliteralToken = nullptr;;
    antlr4::Token *doubleliteralToken = nullptr;;
    antlr4::Token *hexToken = nullptr;;
    AnyFXParser::StringContext *stringContext = nullptr;;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::BooleanContext *booleanContext = nullptr;;
    AnyFXParser::InitializerExpressionContext *initializerExpressionContext = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    BinaryexpatomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGERLITERAL();
    antlr4::tree::TerminalNode *UINTEGERLITERAL();
    antlr4::tree::TerminalNode *FLOATLITERAL();
    antlr4::tree::TerminalNode *DOUBLELITERAL();
    antlr4::tree::TerminalNode *HEX();
    StringContext *string();
    antlr4::tree::TerminalNode *IDENTIFIER();
    BooleanContext *boolean();
    InitializerExpressionContext *initializerExpression();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinaryexpatomContext* binaryexpatom();

  class  InitializerExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::AssignmentExpressionContext *arg0 = nullptr;;
    AnyFXParser::AssignmentExpressionContext *argN = nullptr;;
    InitializerExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignmentExpressionContext *> assignmentExpression();
    AssignmentExpressionContext* assignmentExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InitializerExpressionContext* initializerExpression();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

