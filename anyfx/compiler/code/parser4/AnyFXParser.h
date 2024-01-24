

// include std container
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <stack>
#include <tuple>

#include "anyfxtoken.h"
#include "qualifierexpression.h"
#include "compileable.h"
#include "effect.h"
#include "header.h"
#include "datatype.h"
#include "parameter.h"
#include "annotation.h"
#include "programrow.h"
#include "program.h"
#include "samplertexturelist.h"
#include "samplerrow.h"
#include "sampler.h"
#include "structure.h"
#include "blendstaterow.h"
#include "renderstaterow.h"
#include "renderstate.h"
#include "function.h"
#include "valuelist.h"
#include "functionattribute.h"
#include "variable.h"
#include "varblock.h"
#include "varbuffer.h"
#include "subroutine.h"
#include "preprocessor.h"
#include "expressions/expression.h"
#include "expressions/binaryexpression.h"
#include "expressions/unaryexpression.h"
#include "expressions/intexpression.h"
#include "expressions/boolexpression.h"
#include "expressions/floatexpression.h"
#include "expressions/symbolexpression.h"
#include "allocator.h"
using namespace AnyFX;



// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AnyFXParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, SC = 16, CO = 17, COL = 18, LP = 19, RP = 20, LB = 21, RB = 22, 
    LL = 23, RR = 24, DOT = 25, NOT = 26, EQ = 27, QO = 28, QU = 29, AND = 30, 
    ANDSET = 31, OR = 32, ORSET = 33, XOR = 34, XORSET = 35, CONNJUGATE = 36, 
    Q = 37, NU = 38, FORWARDSLASH = 39, LESS = 40, LESSEQ = 41, GREATER = 42, 
    GREATEREQ = 43, LOGICEQ = 44, NOTEQ = 45, LOGICAND = 46, LOGICOR = 47, 
    MOD = 48, UNDERSC = 49, ADD_OP = 50, SUB_OP = 51, DIV_OP = 52, MUL_OP = 53, 
    INTEGERLITERAL = 54, COMMENT = 55, ML_COMMENT = 56, FLOATLITERAL = 57, 
    EXPONENT = 58, DOUBLELITERAL = 59, HEX = 60, IDENTIFIER = 61, WS = 62
  };

  enum {
    RuleString = 0, RuleBoolean = 1, RulePreprocess = 2, RuleEntry = 3, 
    RuleEffect = 4, RuleType = 5, RuleQualifierExpression = 6, RuleStructure = 7, 
    RuleVarblock = 8, RuleVarbuffer = 9, RuleSubroutine = 10, RuleValueList = 11, 
    RuleValueSingleList = 12, RuleVariable = 13, RuleParameter = 14, RuleParameterList = 15, 
    RuleFunctionAttribute = 16, RuleCodeBlock = 17, RuleFunction = 18, RuleBlendStateRow = 19, 
    RuleRenderStateRow = 20, RuleRenderState = 21, RuleSampler = 22, RuleSamplerTextureList = 23, 
    RuleSamplerRow = 24, RuleProgramRow = 25, RuleAnnotation = 26, RuleProgram = 27, 
    RuleExpression = 28, RuleBinaryexp7 = 29, RuleBinaryexp6 = 30, RuleBinaryexp5 = 31, 
    RuleBinaryexp4 = 32, RuleBinaryexp3 = 33, RuleBinaryexp2 = 34, RuleBinaryexp1 = 35, 
    RuleBinaryexpatom = 36, RuleParantexpression = 37
  };

  AnyFXParser(antlr4::TokenStream *input);
  ~AnyFXParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


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

  Allocator alloc;


  class StringContext;
  class BooleanContext;
  class PreprocessContext;
  class EntryContext;
  class EffectContext;
  class TypeContext;
  class QualifierExpressionContext;
  class StructureContext;
  class VarblockContext;
  class VarbufferContext;
  class SubroutineContext;
  class ValueListContext;
  class ValueSingleListContext;
  class VariableContext;
  class ParameterContext;
  class ParameterListContext;
  class FunctionAttributeContext;
  class CodeBlockContext;
  class FunctionContext;
  class BlendStateRowContext;
  class RenderStateRowContext;
  class RenderStateContext;
  class SamplerContext;
  class SamplerTextureListContext;
  class SamplerRowContext;
  class ProgramRowContext;
  class AnnotationContext;
  class ProgramContext;
  class ExpressionContext;
  class Binaryexp7Context;
  class Binaryexp6Context;
  class Binaryexp5Context;
  class Binaryexp4Context;
  class Binaryexp3Context;
  class Binaryexp2Context;
  class Binaryexp1Context;
  class BinaryexpatomContext;
  class ParantexpressionContext; 

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
    AnyFXParser::VariableContext *variableContext = nullptr;;
    AnyFXParser::RenderStateContext *renderStateContext = nullptr;;
    AnyFXParser::FunctionContext *functionContext = nullptr;;
    AnyFXParser::ProgramContext *programContext = nullptr;;
    AnyFXParser::StructureContext *structureContext = nullptr;;
    AnyFXParser::VarblockContext *varblockContext = nullptr;;
    AnyFXParser::VarbufferContext *varbufferContext = nullptr;;
    AnyFXParser::SubroutineContext *subroutineContext = nullptr;;
    AnyFXParser::SamplerContext *samplerContext = nullptr;;
    EffectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    std::vector<RenderStateContext *> renderState();
    RenderStateContext* renderState(size_t i);
    std::vector<FunctionContext *> function();
    FunctionContext* function(size_t i);
    std::vector<ProgramContext *> program();
    ProgramContext* program(size_t i);
    std::vector<StructureContext *> structure();
    StructureContext* structure(size_t i);
    std::vector<VarblockContext *> varblock();
    VarblockContext* varblock(size_t i);
    std::vector<VarbufferContext *> varbuffer();
    VarbufferContext* varbuffer(size_t i);
    std::vector<SubroutineContext *> subroutine();
    SubroutineContext* subroutine(size_t i);
    std::vector<SamplerContext *> sampler();
    SamplerContext* sampler(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EffectContext* effect();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    DataType ty;
    antlr4::Token *identifierToken = nullptr;;
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  QualifierExpressionContext : public antlr4::ParserRuleContext {
  public:
    QualifierExpression q;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ParantexpressionContext *parantexpressionContext = nullptr;;
    QualifierExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParantexpressionContext *parantexpression();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QualifierExpressionContext* qualifierExpression();

  class  StructureContext : public antlr4::ParserRuleContext {
  public:
    Structure* struc;
    antlr4::Token *qual = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ParameterContext *parameterContext = nullptr;;
    StructureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<QualifierExpressionContext *> qualifierExpression();
    QualifierExpressionContext* qualifierExpression(size_t i);
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructureContext* structure();

  class  VarblockContext : public antlr4::ParserRuleContext {
  public:
    VarBlock* block;
    antlr4::Token *qual = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    antlr4::Token *varName = nullptr;;
    AnyFXParser::ExpressionContext *arraySize = nullptr;;
    VarblockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<QualifierExpressionContext *> qualifierExpression();
    QualifierExpressionContext* qualifierExpression(size_t i);
    AnnotationContext *annotation();
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarblockContext* varblock();

  class  VarbufferContext : public antlr4::ParserRuleContext {
  public:
    VarBuffer* buffer;
    antlr4::Token *qual = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    AnyFXParser::VariableContext *variableContext = nullptr;;
    antlr4::Token *varName = nullptr;;
    AnyFXParser::ExpressionContext *arraySize = nullptr;;
    VarbufferContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<QualifierExpressionContext *> qualifierExpression();
    QualifierExpressionContext* qualifierExpression(size_t i);
    AnnotationContext *annotation();
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VarbufferContext* varbuffer();

  class  SubroutineContext : public antlr4::ParserRuleContext {
  public:
    Subroutine* subrout;
    AnyFXParser::TypeContext *retval = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ParameterListContext *parameterListContext = nullptr;;
    antlr4::Token *signature = nullptr;;
    AnyFXParser::FunctionContext *functionContext = nullptr;;
    SubroutineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterListContext *parameterList();
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    FunctionContext *function();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubroutineContext* subroutine();

  class  ValueListContext : public antlr4::ParserRuleContext {
  public:
    ValueList valList;
    AnyFXParser::ExpressionContext *first = nullptr;;
    AnyFXParser::ExpressionContext *rest = nullptr;;
    ValueListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ValueListContext* valueList();

  class  ValueSingleListContext : public antlr4::ParserRuleContext {
  public:
    ValueList valList;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    ValueSingleListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ValueSingleListContext* valueSingleList();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    Variable* var;
    antlr4::Token *qual = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    AnyFXParser::TypeContext *declType = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::TypeContext *fstType = nullptr;;
    AnyFXParser::ValueListContext *fstValue = nullptr;;
    AnyFXParser::TypeContext *cntType = nullptr;;
    AnyFXParser::ValueListContext *cntValue = nullptr;;
    AnyFXParser::ValueListContext *valList = nullptr;;
    AnyFXParser::ExpressionContext *asize0 = nullptr;;
    AnyFXParser::ExpressionContext *asize2 = nullptr;;
    AnyFXParser::TypeContext *defType = nullptr;;
    AnyFXParser::ValueListContext *list2 = nullptr;;
    AnyFXParser::ValueSingleListContext *list3 = nullptr;;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<QualifierExpressionContext *> qualifierExpression();
    QualifierExpressionContext* qualifierExpression(size_t i);
    AnnotationContext *annotation();
    std::vector<ValueListContext *> valueList();
    ValueListContext* valueList(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    ValueSingleListContext *valueSingleList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    Parameter param;
    antlr4::Token *attr = nullptr;;
    AnyFXParser::ExpressionContext *feedbackBuffer = nullptr;;
    AnyFXParser::ExpressionContext *feedbackOffset = nullptr;;
    AnyFXParser::ExpressionContext *slotExpression = nullptr;;
    antlr4::Token *qualifier = nullptr;;
    AnyFXParser::TypeContext *typeContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *size = nullptr;;
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterContext* parameter();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    std::vector<Parameter> parameters;
    AnyFXParser::ParameterContext *firstParam = nullptr;;
    AnyFXParser::ParameterContext *followParam = nullptr;;
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterListContext* parameterList();

  class  FunctionAttributeContext : public antlr4::ParserRuleContext {
  public:
    FunctionAttribute attribute;
    antlr4::Token *flag1 = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    antlr4::Token *flag3 = nullptr;;
    FunctionAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionAttributeContext* functionAttribute();

  class  CodeBlockContext : public antlr4::ParserRuleContext {
  public:
    CodeBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CodeBlockContext *> codeBlock();
    CodeBlockContext* codeBlock(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CodeBlockContext* codeBlock();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    Function* func;
    AnyFXParser::FunctionAttributeContext *functionAttributeContext = nullptr;;
    AnyFXParser::TypeContext *typeContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ParameterListContext *parameterListContext = nullptr;;
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    ParameterListContext *parameterList();
    CodeBlockContext *codeBlock();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<FunctionAttributeContext *> functionAttribute();
    FunctionAttributeContext* functionAttribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FunctionContext* function();

  class  BlendStateRowContext : public antlr4::ParserRuleContext {
  public:
    BlendStateRow row;
    antlr4::Token *flag2 = nullptr;;
    AnyFXParser::ExpressionContext *index2 = nullptr;;
    AnyFXParser::ExpressionContext *value = nullptr;;
    BlendStateRowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlendStateRowContext* blendStateRow();

  class  RenderStateRowContext : public antlr4::ParserRuleContext {
  public:
    RenderStateRow row;
    antlr4::Token *flag1 = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    RenderStateRowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RenderStateRowContext* renderStateRow();

  class  RenderStateContext : public antlr4::ParserRuleContext {
  public:
    RenderState* state;
    antlr4::Token *name = nullptr;;
    AnyFXParser::RenderStateRowContext *renderStateRowContext = nullptr;;
    AnyFXParser::BlendStateRowContext *blendStateRowContext = nullptr;;
    RenderStateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<RenderStateRowContext *> renderStateRow();
    RenderStateRowContext* renderStateRow(size_t i);
    std::vector<BlendStateRowContext *> blendStateRow();
    BlendStateRowContext* blendStateRow(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RenderStateContext* renderState();

  class  SamplerContext : public antlr4::ParserRuleContext {
  public:
    Sampler* samp;
    antlr4::Token *qual = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::SamplerRowContext *samplerRowContext = nullptr;;
    SamplerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<QualifierExpressionContext *> qualifierExpression();
    QualifierExpressionContext* qualifierExpression(size_t i);
    std::vector<SamplerRowContext *> samplerRow();
    SamplerRowContext* samplerRow(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SamplerContext* sampler();

  class  SamplerTextureListContext : public antlr4::ParserRuleContext {
  public:
    SamplerTextureList list;
    antlr4::Token *firstItem = nullptr;;
    antlr4::Token *nextItem = nullptr;;
    SamplerTextureListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SamplerTextureListContext* samplerTextureList();

  class  SamplerRowContext : public antlr4::ParserRuleContext {
  public:
    SamplerRow row;
    antlr4::Token *flag1 = nullptr;;
    antlr4::Token *samplerMode = nullptr;;
    antlr4::Token *flag2 = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    antlr4::Token *flag4 = nullptr;;
    AnyFXParser::SamplerTextureListContext *samplerTextureListContext = nullptr;;
    SamplerRowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    ExpressionContext *expression();
    SamplerTextureListContext *samplerTextureList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SamplerRowContext* samplerRow();

  class  ProgramRowContext : public antlr4::ParserRuleContext {
  public:
    ProgramRow row;
    antlr4::Token *shader = nullptr;;
    antlr4::Token *name = nullptr;;
    antlr4::Token *var = nullptr;;
    antlr4::Token *implementation = nullptr;;
    antlr4::Token *var2 = nullptr;;
    antlr4::Token *implementation2 = nullptr;;
    ProgramRowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramRowContext* programRow();

  class  AnnotationContext : public antlr4::ParserRuleContext {
  public:
    Annotation annot;
    AnyFXParser::TypeContext *typeContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::StringContext *stringContext = nullptr;;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    AnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<StringContext *> string();
    StringContext* string(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AnnotationContext* annotation();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    Program* prog;
    antlr4::Token *name = nullptr;;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    AnyFXParser::ProgramRowContext *programRowContext = nullptr;;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    AnnotationContext *annotation();
    std::vector<ProgramRowContext *> programRow();
    ProgramRowContext* programRow(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp7Context *binaryexp7Context = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Binaryexp7Context *binaryexp7();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Binaryexp7Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp6Context *e1 = nullptr;;
    AnyFXParser::Binaryexp6Context *e2 = nullptr;;
    Binaryexp7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp6Context *> binaryexp6();
    Binaryexp6Context* binaryexp6(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binaryexp7Context* binaryexp7();

  class  Binaryexp6Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::Binaryexp5Context *e1 = nullptr;;
    AnyFXParser::Binaryexp5Context *e2 = nullptr;;
    Binaryexp6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Binaryexp5Context *> binaryexp5();
    Binaryexp5Context* binaryexp5(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binaryexp2Context* binaryexp2();

  class  Binaryexp1Context : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    antlr4::Token *op = nullptr;;
    AnyFXParser::BinaryexpatomContext *e1 = nullptr;;
    Binaryexp1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BinaryexpatomContext *binaryexpatom();
    antlr4::tree::TerminalNode *SUB_OP();
    antlr4::tree::TerminalNode *NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Binaryexp1Context* binaryexp1();

  class  BinaryexpatomContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    antlr4::Token *integerliteralToken = nullptr;;
    antlr4::Token *floatliteralToken = nullptr;;
    antlr4::Token *doubleliteralToken = nullptr;;
    antlr4::Token *hexToken = nullptr;;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::BooleanContext *booleanContext = nullptr;;
    AnyFXParser::ParantexpressionContext *parantexpressionContext = nullptr;;
    BinaryexpatomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGERLITERAL();
    antlr4::tree::TerminalNode *FLOATLITERAL();
    antlr4::tree::TerminalNode *DOUBLELITERAL();
    antlr4::tree::TerminalNode *HEX();
    antlr4::tree::TerminalNode *IDENTIFIER();
    BooleanContext *boolean();
    ParantexpressionContext *parantexpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BinaryexpatomContext* binaryexpatom();

  class  ParantexpressionContext : public antlr4::ParserRuleContext {
  public:
    Expression* tree;
    AnyFXParser::ExpressionContext *expressionContext = nullptr;;
    ParantexpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParantexpressionContext* parantexpression();


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

