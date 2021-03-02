

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
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, T__67 = 68, 
    T__68 = 69, T__69 = 70, T__70 = 71, T__71 = 72, T__72 = 73, SC = 74, 
    CO = 75, COL = 76, LP = 77, RP = 78, LB = 79, RB = 80, LL = 81, RR = 82, 
    DOT = 83, NOT = 84, EQ = 85, QO = 86, QU = 87, AND = 88, ANDSET = 89, 
    OR = 90, ORSET = 91, XOR = 92, XORSET = 93, CONNJUGATE = 94, Q = 95, 
    NU = 96, FORWARDSLASH = 97, LESS = 98, LESSEQ = 99, GREATER = 100, GREATEREQ = 101, 
    LOGICEQ = 102, NOTEQ = 103, LOGICAND = 104, LOGICOR = 105, MOD = 106, 
    UNDERSC = 107, ADD_OP = 108, SUB_OP = 109, DIV_OP = 110, MUL_OP = 111, 
    INTEGERLITERAL = 112, COMMENT = 113, ML_COMMENT = 114, FLOATLITERAL = 115, 
    EXPONENT = 116, DOUBLELITERAL = 117, HEX = 118, IDENTIFIER = 119, WS = 120
  };

  enum {
    RuleString = 0, RuleBoolean = 1, RulePreprocess = 2, RuleEntry = 3, 
    RuleEffect = 4, RuleQualifier = 5, RuleQualifierValued = 6, RuleType = 7, 
    RuleQualifierExpression = 8, RuleStructure = 9, RuleVarblock = 10, RuleVarbuffer = 11, 
    RuleSubroutine = 12, RuleValueList = 13, RuleValueSingleList = 14, RuleVariable = 15, 
    RuleConstant = 16, RuleParameterAttribute = 17, RuleParameter = 18, 
    RuleParameterList = 19, RuleFunctionAttribute = 20, RuleCodeBlock = 21, 
    RuleFunction = 22, RuleBlendStateRow = 23, RuleRenderStateRow = 24, 
    RuleRenderState = 25, RuleSampler = 26, RuleSamplerTextureList = 27, 
    RuleSamplerRow = 28, RuleProgramRow = 29, RuleAnnotation = 30, RuleProgram = 31, 
    RuleExpression = 32, RuleBinaryexp7 = 33, RuleBinaryexp6 = 34, RuleBinaryexp5 = 35, 
    RuleBinaryexp4 = 36, RuleBinaryexp3 = 37, RuleBinaryexp2 = 38, RuleBinaryexp1 = 39, 
    RuleBinaryexpatom = 40, RuleParantexpression = 41
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


  class StringContext;
  class BooleanContext;
  class PreprocessContext;
  class EntryContext;
  class EffectContext;
  class QualifierContext;
  class QualifierValuedContext;
  class TypeContext;
  class QualifierExpressionContext;
  class StructureContext;
  class VarblockContext;
  class VarbufferContext;
  class SubroutineContext;
  class ValueListContext;
  class ValueSingleListContext;
  class VariableContext;
  class ConstantContext;
  class ParameterAttributeContext;
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
    Effect returnEffect;
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
    Effect eff;
    AnyFXParser::ConstantContext *constantContext = nullptr;;
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
    std::vector<ConstantContext *> constant();
    ConstantContext* constant(size_t i);
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

  class  QualifierContext : public antlr4::ParserRuleContext {
  public:
    std::string str;
    QualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QualifierContext* qualifier();

  class  QualifierValuedContext : public antlr4::ParserRuleContext {
  public:
    std::string str;
    QualifierValuedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QualifierValuedContext* qualifierValued();

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
    AnyFXParser::QualifierValuedContext *base = nullptr;;
    AnyFXParser::ParantexpressionContext *parantexpressionContext = nullptr;;
    QualifierExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParantexpressionContext *parantexpression();
    QualifierValuedContext *qualifierValued();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  QualifierExpressionContext* qualifierExpression();

  class  StructureContext : public antlr4::ParserRuleContext {
  public:
    Structure struc;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::ParameterContext *parameterContext = nullptr;;
    StructureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StructureContext* structure();

  class  VarblockContext : public antlr4::ParserRuleContext {
  public:
    VarBlock block;
    AnyFXParser::QualifierContext *qualifierContext = nullptr;;
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
    std::vector<QualifierContext *> qualifier();
    QualifierContext* qualifier(size_t i);
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
    VarBuffer buffer;
    AnyFXParser::QualifierContext *qualifierContext = nullptr;;
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
    std::vector<QualifierContext *> qualifier();
    QualifierContext* qualifier(size_t i);
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
    Subroutine subrout;
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
    Variable var;
    AnyFXParser::QualifierContext *qualifierContext = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    AnyFXParser::TypeContext *declType = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::TypeContext *fstType = nullptr;;
    AnyFXParser::ValueListContext *fstValue = nullptr;;
    AnyFXParser::TypeContext *cntType = nullptr;;
    AnyFXParser::ValueListContext *cntValue = nullptr;;
    AnyFXParser::ValueListContext *valList = nullptr;;
    AnyFXParser::ExpressionContext *asize0 = nullptr;;
    AnyFXParser::ExpressionContext *asize1 = nullptr;;
    AnyFXParser::ExpressionContext *asize2 = nullptr;;
    AnyFXParser::TypeContext *defType = nullptr;;
    AnyFXParser::ValueListContext *list2 = nullptr;;
    AnyFXParser::ValueSingleListContext *list3 = nullptr;;
    AnyFXParser::AnnotationContext *annotationContext = nullptr;;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<QualifierContext *> qualifier();
    QualifierContext* qualifier(size_t i);
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

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    Constant cons;
    AnyFXParser::TypeContext *declType = nullptr;;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::TypeContext *defType = nullptr;;
    AnyFXParser::ValueListContext *sinVal1 = nullptr;;
    AnyFXParser::ValueSingleListContext *sinVal2 = nullptr;;
    AnyFXParser::TypeContext *fstType = nullptr;;
    AnyFXParser::ValueListContext *fstValue = nullptr;;
    AnyFXParser::TypeContext *cntType = nullptr;;
    AnyFXParser::ValueListContext *cntValue = nullptr;;
    AnyFXParser::ValueListContext *valList = nullptr;;
    AnyFXParser::ExpressionContext *asize1 = nullptr;;
    AnyFXParser::ExpressionContext *asize2 = nullptr;;
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<ValueListContext *> valueList();
    ValueListContext* valueList(size_t i);
    ValueSingleListContext *valueSingleList();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConstantContext* constant();

  class  ParameterAttributeContext : public antlr4::ParserRuleContext {
  public:
    Parameter::Attribute attribute;
    antlr4::Token *identifierToken = nullptr;;
    ParameterAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterAttributeContext* parameterAttribute();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    Parameter param;
    antlr4::Token *attr = nullptr;;
    AnyFXParser::ExpressionContext *feedbackBuffer = nullptr;;
    AnyFXParser::ExpressionContext *feedbackOffset = nullptr;;
    AnyFXParser::ExpressionContext *slotExpression = nullptr;;
    AnyFXParser::QualifierContext *qualifierContext = nullptr;;
    AnyFXParser::TypeContext *typeContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::ExpressionContext *size = nullptr;;
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<QualifierContext *> qualifier();
    QualifierContext* qualifier(size_t i);
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
    Function func;
    AnyFXParser::FunctionAttributeContext *functionAttributeContext = nullptr;;
    AnyFXParser::TypeContext *typeContext = nullptr;;
    antlr4::Token *identifierToken = nullptr;;
    AnyFXParser::ParameterListContext *parameterListContext = nullptr;;
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    ParameterListContext *parameterList();
    CodeBlockContext *codeBlock();
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
    RenderState state;
    antlr4::Token *identifierToken = nullptr;;
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
    Sampler samp;
    AnyFXParser::QualifierContext *qualifierContext = nullptr;;
    AnyFXParser::QualifierExpressionContext *qualifierExpressionContext = nullptr;;
    antlr4::Token *name = nullptr;;
    AnyFXParser::SamplerRowContext *samplerRowContext = nullptr;;
    SamplerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<QualifierContext *> qualifier();
    QualifierContext* qualifier(size_t i);
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
    antlr4::Token *identifierToken = nullptr;;
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
    antlr4::Token *identifierToken = nullptr;;
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
    Program prog;
    antlr4::Token *identifierToken = nullptr;;
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

