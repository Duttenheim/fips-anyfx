

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



// Generated from g:\anyfxv3\fips-anyfx\code\compiler\ext\antlr4\grammar\AnyFX.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  AnyFXParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, SC = 32, 
    CO = 33, COL = 34, LP = 35, RP = 36, LB = 37, RB = 38, LL = 39, RR = 40, 
    DOT = 41, NOT = 42, EQ = 43, QO = 44, QU = 45, AND = 46, ANDSET = 47, 
    OR = 48, ORSET = 49, XOR = 50, XORSET = 51, CONNJUGATE = 52, Q = 53, 
    NU = 54, FORWARDSLASH = 55, LESS = 56, LESSEQ = 57, GREATER = 58, GREATEREQ = 59, 
    LOGICEQ = 60, NOTEQ = 61, LOGICAND = 62, LOGICOR = 63, MOD = 64, UNDERSC = 65, 
    SOBAKA = 66, ADD_OP = 67, SUB_OP = 68, DIV_OP = 69, MUL_OP = 70, INTEGERLITERAL = 71, 
    COMMENT = 72, ML_COMMENT = 73, FLOATLITERAL = 74, EXPONENT = 75, DOUBLELITERAL = 76, 
    HEX = 77, IDENTIFIER = 78, WS = 79
  };

  enum {
    RuleString = 0, RuleBoolean = 1, RulePreprocess = 2, RuleEntry = 3, 
    RuleEffect = 4, RuleAlias = 5, RuleAnnotation = 6, RuleAttribute = 7, 
    RuleVariable = 8, RuleStructureDeclaration = 9, RuleStructure = 10, 
    RuleFunctionDeclaration = 11, RuleCodeblock = 12, RuleFunction = 13, 
    RuleProgram = 14, RuleState = 15, RuleDeclaration = 16, RuleStatement = 17, 
    RuleExpressionStatement = 18, RuleDeclarationStatement = 19, RuleIfStatement = 20, 
    RuleForStatement = 21, RuleForRangeStatement = 22, RuleWhileStatement = 23, 
    RuleScopeStatement = 24, RuleReturnStatement = 25, RuleContinueStatement = 26, 
    RuleSwitchStatement = 27, RuleBreakStatement = 28, RuleExpression = 29, 
    RuleBinaryexp12 = 30, RuleBinaryexp11 = 31, RuleBinaryexp10 = 32, RuleBinaryexp9 = 33, 
    RuleBinaryexp8 = 34, RuleBinaryexp7 = 35, RuleBinaryexp6 = 36, RuleBinaryexp5 = 37, 
    RuleBinaryexp4 = 38, RuleBinaryexp3 = 39, RuleBinaryexp2 = 40, RuleBinaryexp1 = 41, 
    RuleBinaryexp0 = 42, RuleBinaryexpatom = 43, RuleParantExpression = 44, 
    RuleCallExpression = 45, RuleAccessExpression = 46, RuleArrayIndexExpression = 47
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


  class StringContext;
  class BooleanContext;
  class PreprocessContext;
  class EntryContext;
  class EffectContext;
  class AliasContext;
  class AnnotationContext;
  class AttributeContext;
  class VariableContext;
  class StructureDeclarationContext;
  class StructureContext;
  class FunctionDeclarationContext;
  class CodeblockContext;
  class FunctionContext;
  class ProgramContext;
  class StateContext;
  class DeclarationContext;
  class StatementContext;
  class ExpressionStatementContext;
  class DeclarationStatementContext;
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
  class Binaryexp12Context;
  class Binaryexp11Context;
  class Binaryexp10Context;
  class Binaryexp9Context;
  class Binaryexp8Context;
  class Binaryexp7Context;
  class Binaryexp6Context;
  class Binaryexp5Context;
  class Binaryexp4Context;
  class Binaryexp3Context;
  class Binaryexp2Context;
  class Binaryexp1Context;
  class Binaryexp0Context;
  class BinaryexpatomContext;
  class ParantExpressionContext;
  class CallExpressionContext;
  class AccessExpressionContext;
  class ArrayIndexExpressionContext; 

  class  StringContext : public antlr4::ParserRuleContext {
  public:
    std::string val;
    antlr4::Token *data = nullptr;;
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> QO();
    antlr4::tree::TerminalNode* QO(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Q();
    antlr4::tree::TerminalNode* Q(size_t i);

   
  };

  StringContext* string();

  class  BooleanContext : public antlr4::ParserRuleContext {
  public:
    bool val;
    BooleanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
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
    AnyFXParser::StateContext *stateContext = nullptr;;
    AnyFXParser::ProgramContext *programContext = nullptr;;
    EffectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AliasContext *> alias();
    AliasContext* alias(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    std::vector<FunctionDeclarationContext *> functionDeclaration();
    FunctionDeclarationContext* functionDeclaration(size_t i);
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    std::vector<StructureContext *> structure();
    StructureContext* structure(size_t i);
    std::vector<StateContext *> state();
    StateContext* state(size_t i);
    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);

   
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

   
  };

  AliasContext* alias();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    Annotation annot;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *value = nullptr;;
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SOBAKA();
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();

   
  };

  AnnotationContext* annotation();

  class  AttributeContext : public antlr4::ParserRuleContext {
  public:
    Attribute attr;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *IDENTIFIER();

   
  };

  AttributeContext* attribute();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    Variable* sym;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    AnyFXParser::AttributeContext *attributeContext = nullptr;;
    antlr4::Token *type = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    antlr4::Token *initType0 = nullptr;;
    AnyFXParser::ExpressionContext *value0 = nullptr;;
    AnyFXParser::ExpressionContext *valuen = nullptr;;
    antlr4::Token *initType1 = nullptr;;
    AnyFXParser::ExpressionContext *value1 = nullptr;;
    AnyFXParser::ExpressionContext *value = nullptr;;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);
    antlr4::tree::TerminalNode *LL();
    antlr4::tree::TerminalNode *RR();
    antlr4::tree::TerminalNode *EQ();
    std::vector<antlr4::tree::TerminalNode *> LB();
    antlr4::tree::TerminalNode* LB(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LP();
    antlr4::tree::TerminalNode* LP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RP();
    antlr4::tree::TerminalNode* RP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RB();
    antlr4::tree::TerminalNode* RB(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CO();
    antlr4::tree::TerminalNode* CO(size_t i);

   
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
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *LL();
    antlr4::tree::TerminalNode *RR();
    ExpressionContext *expression();

   
  };

  StructureContext* structure();

  class  FunctionDeclarationContext : public antlr4::ParserRuleContext {
  public:
    Function* sym;
    AnyFXParser::AttributeContext *attributeContext = nullptr;;
    antlr4::Token *returnType = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::VariableContext *arg0 = nullptr;;
    AnyFXParser::VariableContext *argn = nullptr;;
    FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<AttributeContext *> attribute();
    AttributeContext* attribute(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CO();
    antlr4::tree::TerminalNode* CO(size_t i);

   
  };

  FunctionDeclarationContext* functionDeclaration();

  class  CodeblockContext : public antlr4::ParserRuleContext {
  public:
    CodeblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    std::vector<CodeblockContext *> codeblock();
    CodeblockContext* codeblock(size_t i);

   
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
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<AnnotationContext *> annotation();
    AnnotationContext* annotation(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

   
  };

  ProgramContext* program();

  class  StateContext : public antlr4::ParserRuleContext {
  public:
    State* sym;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *assign = nullptr;;
    StateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

   
  };

  StateContext* state();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    Symbol* sym;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();

   
  };

  DeclarationContext* declaration();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::DeclarationStatementContext *declarationStatementContext = nullptr;;
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
    DeclarationStatementContext *declarationStatement();
    antlr4::tree::TerminalNode *SC();
    IfStatementContext *ifStatement();
    ScopeStatementContext *scopeStatement();
    ForStatementContext *forStatement();
    WhileStatementContext *whileStatement();
    ReturnStatementContext *returnStatement();
    ContinueStatementContext *continueStatement();
    BreakStatementContext *breakStatement();
    ExpressionStatementContext *expressionStatement();

   
  };

  StatementContext* statement();

  class  ExpressionStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    ExpressionStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *SC();

   
  };

  ExpressionStatementContext* expressionStatement();

  class  DeclarationStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    antlr4::Token *qualifier = nullptr;;
    antlr4::Token *type = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *arraySize = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    DeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LL();
    antlr4::tree::TerminalNode* LL(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RR();
    antlr4::tree::TerminalNode* RR(size_t i);
    antlr4::tree::TerminalNode *EQ();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

   
  };

  DeclarationStatementContext* declarationStatement();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *condition = nullptr;;
    AnyFXParser::StatementContext *ifBody = nullptr;;
    AnyFXParser::StatementContext *elseBody = nullptr;;
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

   
  };

  IfStatementContext* ifStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::DeclarationContext *declare0 = nullptr;;
    AnyFXParser::DeclarationContext *declaren = nullptr;;
    AnyFXParser::ExpressionContext *condition = nullptr;;
    AnyFXParser::ExpressionContext *expression0 = nullptr;;
    AnyFXParser::ExpressionContext *expressionn = nullptr;;
    AnyFXParser::StatementContext *content = nullptr;;
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    std::vector<antlr4::tree::TerminalNode *> SC();
    antlr4::tree::TerminalNode* SC(size_t i);
    antlr4::tree::TerminalNode *RP();
    StatementContext *statement();
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CO();
    antlr4::tree::TerminalNode* CO(size_t i);

   
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
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *COL();
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);
    antlr4::tree::TerminalNode *RP();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    StatementContext *statement();

   
  };

  ForRangeStatementContext* forRangeStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *condition = nullptr;;
    AnyFXParser::StatementContext *content = nullptr;;
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    ExpressionContext *expression();
    StatementContext *statement();

   
  };

  WhileStatementContext* whileStatement();

  class  ScopeStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::StatementContext *content = nullptr;;
    AnyFXParser::DeclarationContext *declare = nullptr;;
    ScopeStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<DeclarationContext *> declaration();
    DeclarationContext* declaration(size_t i);

   
  };

  ScopeStatementContext* scopeStatement();

  class  ReturnStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    AnyFXParser::ExpressionContext *value = nullptr;;
    ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SC();
    ExpressionContext *expression();

   
  };

  ReturnStatementContext* returnStatement();

  class  ContinueStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    ContinueStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SC();

   
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
    antlr4::tree::TerminalNode *LP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RP();
    antlr4::tree::TerminalNode *LB();
    antlr4::tree::TerminalNode *RB();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

   
  };

  SwitchStatementContext* switchStatement();

  class  BreakStatementContext : public antlr4::ParserRuleContext {
  public:
    Statement* tree;
    BreakStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SC();

   
  };

  BreakStatementContext* breakStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp12Context *binaryexp12Context = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Binaryexp12Context *binaryexp12();

   
  };

  ExpressionContext* expression();

  class  Binaryexp12Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp11Context *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp11Context *e2 = nullptr;;
    AnyFXParser::ExpressionContext *ifBody = nullptr;;
    AnyFXParser::ExpressionContext *elseBody = nullptr;;
    Binaryexp12Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp11Context *> binaryexp11();
    Binaryexp11Context* binaryexp11(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QU();
    antlr4::tree::TerminalNode* QU(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COL();
    antlr4::tree::TerminalNode* COL(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ANDSET();
    antlr4::tree::TerminalNode* ANDSET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> XORSET();
    antlr4::tree::TerminalNode* XORSET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ORSET();
    antlr4::tree::TerminalNode* ORSET(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQ();
    antlr4::tree::TerminalNode* EQ(size_t i);

   
  };

  Binaryexp12Context* binaryexp12();

  class  Binaryexp11Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp10Context *e1 = nullptr;;
    AnyFXParser::Binaryexp10Context *e2 = nullptr;;
    Binaryexp11Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp10Context *> binaryexp10();
    Binaryexp10Context* binaryexp10(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOGICOR();
    antlr4::tree::TerminalNode* LOGICOR(size_t i);

   
  };

  Binaryexp11Context* binaryexp11();

  class  Binaryexp10Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp9Context *e1 = nullptr;;
    AnyFXParser::Binaryexp9Context *e2 = nullptr;;
    Binaryexp10Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp9Context *> binaryexp9();
    Binaryexp9Context* binaryexp9(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOGICAND();
    antlr4::tree::TerminalNode* LOGICAND(size_t i);

   
  };

  Binaryexp10Context* binaryexp10();

  class  Binaryexp9Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp8Context *e1 = nullptr;;
    AnyFXParser::Binaryexp8Context *e2 = nullptr;;
    Binaryexp9Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp8Context *> binaryexp8();
    Binaryexp8Context* binaryexp8(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

   
  };

  Binaryexp9Context* binaryexp9();

  class  Binaryexp8Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp7Context *e1 = nullptr;;
    AnyFXParser::Binaryexp7Context *e2 = nullptr;;
    Binaryexp8Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp7Context *> binaryexp7();
    Binaryexp7Context* binaryexp7(size_t i);
    std::vector<antlr4::tree::TerminalNode *> XOR();
    antlr4::tree::TerminalNode* XOR(size_t i);

   
  };

  Binaryexp8Context* binaryexp8();

  class  Binaryexp7Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp6Context *e1 = nullptr;;
    AnyFXParser::Binaryexp6Context *e2 = nullptr;;
    Binaryexp7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp6Context *> binaryexp6();
    Binaryexp6Context* binaryexp6(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

   
  };

  Binaryexp7Context* binaryexp7();

  class  Binaryexp6Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp5Context *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp5Context *e2 = nullptr;;
    Binaryexp6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp5Context *> binaryexp5();
    Binaryexp5Context* binaryexp5(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LOGICEQ();
    antlr4::tree::TerminalNode* LOGICEQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NOTEQ();
    antlr4::tree::TerminalNode* NOTEQ(size_t i);

   
  };

  Binaryexp6Context* binaryexp6();

  class  Binaryexp5Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp4Context *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp4Context *e2 = nullptr;;
    Binaryexp5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp4Context *> binaryexp4();
    Binaryexp4Context* binaryexp4(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESS();
    antlr4::tree::TerminalNode* LESS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER();
    antlr4::tree::TerminalNode* GREATER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESSEQ();
    antlr4::tree::TerminalNode* LESSEQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATEREQ();
    antlr4::tree::TerminalNode* GREATEREQ(size_t i);

   
  };

  Binaryexp5Context* binaryexp5();

  class  Binaryexp4Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp3Context *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp3Context *e2 = nullptr;;
    Binaryexp4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp3Context *> binaryexp3();
    Binaryexp3Context* binaryexp3(size_t i);

   
  };

  Binaryexp4Context* binaryexp4();

  class  Binaryexp3Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp2Context *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp2Context *e2 = nullptr;;
    Binaryexp3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp2Context *> binaryexp2();
    Binaryexp2Context* binaryexp2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ADD_OP();
    antlr4::tree::TerminalNode* ADD_OP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SUB_OP();
    antlr4::tree::TerminalNode* SUB_OP(size_t i);

   
  };

  Binaryexp3Context* binaryexp3();

  class  Binaryexp2Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp1Context *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp1Context *e2 = nullptr;;
    Binaryexp2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp1Context *> binaryexp1();
    Binaryexp1Context* binaryexp1(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MUL_OP();
    antlr4::tree::TerminalNode* MUL_OP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIV_OP();
    antlr4::tree::TerminalNode* DIV_OP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MOD();
    antlr4::tree::TerminalNode* MOD(size_t i);

   
  };

  Binaryexp2Context* binaryexp2();

  class  Binaryexp1Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    antlr4::Token *op = nullptr;;
    AnyFXParser::Binaryexp0Context *e1 = nullptr;;
    Binaryexp1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Binaryexp0Context *binaryexp0();
    antlr4::tree::TerminalNode *SUB_OP();
    antlr4::tree::TerminalNode *ADD_OP();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *CONNJUGATE();

   
  };

  Binaryexp1Context* binaryexp1();

  class  Binaryexp0Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::BinaryexpatomContext *e1 = nullptr;;
    antlr4::Token *op = nullptr;;
    AnyFXParser::CallExpressionContext *callExpressionContext = nullptr;;
    AnyFXParser::AccessExpressionContext *accessExpressionContext = nullptr;;
    AnyFXParser::ArrayIndexExpressionContext *arrayIndexExpressionContext = nullptr;;
    Binaryexp0Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BinaryexpatomContext *binaryexpatom();
    std::vector<CallExpressionContext *> callExpression();
    CallExpressionContext* callExpression(size_t i);
    std::vector<AccessExpressionContext *> accessExpression();
    AccessExpressionContext* accessExpression(size_t i);
    std::vector<ArrayIndexExpressionContext *> arrayIndexExpression();
    ArrayIndexExpressionContext* arrayIndexExpression(size_t i);

   
  };

  Binaryexp0Context* binaryexp0();

  class  BinaryexpatomContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    antlr4::Token *integerliteralToken = nullptr;;
    antlr4::Token *floatliteralToken = nullptr;;
    antlr4::Token *doubleliteralToken = nullptr;;
    antlr4::Token *hexToken = nullptr;;
    AnyFXParser::StringContext *stringContext = nullptr;;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::BooleanContext *booleanContext = nullptr;;
    AnyFXParser::ParantExpressionContext *parantExpressionContext = nullptr;;
    BinaryexpatomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGERLITERAL();
    antlr4::tree::TerminalNode *FLOATLITERAL();
    antlr4::tree::TerminalNode *DOUBLELITERAL();
    antlr4::tree::TerminalNode *HEX();
    StringContext *string();
    antlr4::tree::TerminalNode *IDENTIFIER();
    BooleanContext *boolean();
    ParantExpressionContext *parantExpression();

   
  };

  BinaryexpatomContext* binaryexpatom();

  class  ParantExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    ParantExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RP();

   
  };

  ParantExpressionContext* parantExpression();

  class  CallExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::ExpressionContext *arg0 = nullptr;;
    AnyFXParser::ExpressionContext *argn = nullptr;;
    CallExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LP();
    antlr4::tree::TerminalNode *RP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CO();
    antlr4::tree::TerminalNode* CO(size_t i);

   
  };

  CallExpressionContext* callExpression();

  class  AccessExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    AccessExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    ExpressionContext *expression();

   
  };

  AccessExpressionContext* accessExpression();

  class  ArrayIndexExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    ArrayIndexExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LL();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RR();

   
  };

  ArrayIndexExpressionContext* arrayIndexExpression();


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

