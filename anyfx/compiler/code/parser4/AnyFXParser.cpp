

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


#include "AnyFXListener.h"

#include "AnyFXParser.h"


using namespace antlrcpp;
using namespace antlr4;

AnyFXParser::AnyFXParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AnyFXParser::~AnyFXParser() {
  delete _interpreter;
}

std::string AnyFXParser::getGrammarFileName() const {
  return "AnyFX.g4";
}

const std::vector<std::string>& AnyFXParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AnyFXParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StringContext ------------------------------------------------------------------

AnyFXParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::StringContext::QO() {
  return getTokens(AnyFXParser::QO);
}

tree::TerminalNode* AnyFXParser::StringContext::QO(size_t i) {
  return getToken(AnyFXParser::QO, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::StringContext::Q() {
  return getTokens(AnyFXParser::Q);
}

tree::TerminalNode* AnyFXParser::StringContext::Q(size_t i) {
  return getToken(AnyFXParser::Q, i);
}


size_t AnyFXParser::StringContext::getRuleIndex() const {
  return AnyFXParser::RuleString;
}

void AnyFXParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void AnyFXParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}

AnyFXParser::StringContext* AnyFXParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 0, AnyFXParser::RuleString);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(102);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::QO: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        match(AnyFXParser::QO);
        setState(89);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__2)
          | (1ULL << AnyFXParser::T__3)
          | (1ULL << AnyFXParser::T__4)
          | (1ULL << AnyFXParser::T__5)
          | (1ULL << AnyFXParser::T__6)
          | (1ULL << AnyFXParser::T__7)
          | (1ULL << AnyFXParser::T__8)
          | (1ULL << AnyFXParser::T__9)
          | (1ULL << AnyFXParser::T__10)
          | (1ULL << AnyFXParser::T__11)
          | (1ULL << AnyFXParser::T__12)
          | (1ULL << AnyFXParser::T__13)
          | (1ULL << AnyFXParser::T__14)
          | (1ULL << AnyFXParser::T__15)
          | (1ULL << AnyFXParser::T__16)
          | (1ULL << AnyFXParser::T__17)
          | (1ULL << AnyFXParser::T__18)
          | (1ULL << AnyFXParser::T__19)
          | (1ULL << AnyFXParser::T__20)
          | (1ULL << AnyFXParser::T__21)
          | (1ULL << AnyFXParser::T__22)
          | (1ULL << AnyFXParser::T__23)
          | (1ULL << AnyFXParser::T__24)
          | (1ULL << AnyFXParser::T__25)
          | (1ULL << AnyFXParser::T__26)
          | (1ULL << AnyFXParser::T__27)
          | (1ULL << AnyFXParser::T__28)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::T__31)
          | (1ULL << AnyFXParser::T__32)
          | (1ULL << AnyFXParser::T__33)
          | (1ULL << AnyFXParser::T__34)
          | (1ULL << AnyFXParser::T__35)
          | (1ULL << AnyFXParser::T__36)
          | (1ULL << AnyFXParser::T__37)
          | (1ULL << AnyFXParser::T__38)
          | (1ULL << AnyFXParser::T__39)
          | (1ULL << AnyFXParser::T__40)
          | (1ULL << AnyFXParser::T__41)
          | (1ULL << AnyFXParser::T__42)
          | (1ULL << AnyFXParser::T__43)
          | (1ULL << AnyFXParser::T__44)
          | (1ULL << AnyFXParser::T__45)
          | (1ULL << AnyFXParser::T__46)
          | (1ULL << AnyFXParser::T__47)
          | (1ULL << AnyFXParser::T__48)
          | (1ULL << AnyFXParser::T__49)
          | (1ULL << AnyFXParser::T__50)
          | (1ULL << AnyFXParser::T__51)
          | (1ULL << AnyFXParser::T__52)
          | (1ULL << AnyFXParser::T__53)
          | (1ULL << AnyFXParser::T__54)
          | (1ULL << AnyFXParser::T__55)
          | (1ULL << AnyFXParser::T__56)
          | (1ULL << AnyFXParser::T__57)
          | (1ULL << AnyFXParser::T__58)
          | (1ULL << AnyFXParser::T__59)
          | (1ULL << AnyFXParser::T__60)
          | (1ULL << AnyFXParser::T__61)
          | (1ULL << AnyFXParser::T__62))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::T__63 - 64))
          | (1ULL << (AnyFXParser::T__64 - 64))
          | (1ULL << (AnyFXParser::T__65 - 64))
          | (1ULL << (AnyFXParser::T__66 - 64))
          | (1ULL << (AnyFXParser::T__67 - 64))
          | (1ULL << (AnyFXParser::T__68 - 64))
          | (1ULL << (AnyFXParser::T__69 - 64))
          | (1ULL << (AnyFXParser::T__70 - 64))
          | (1ULL << (AnyFXParser::T__71 - 64))
          | (1ULL << (AnyFXParser::T__72 - 64))
          | (1ULL << (AnyFXParser::T__73 - 64))
          | (1ULL << (AnyFXParser::T__74 - 64))
          | (1ULL << (AnyFXParser::SC - 64))
          | (1ULL << (AnyFXParser::CO - 64))
          | (1ULL << (AnyFXParser::COL - 64))
          | (1ULL << (AnyFXParser::LP - 64))
          | (1ULL << (AnyFXParser::RP - 64))
          | (1ULL << (AnyFXParser::LB - 64))
          | (1ULL << (AnyFXParser::RB - 64))
          | (1ULL << (AnyFXParser::LL - 64))
          | (1ULL << (AnyFXParser::RR - 64))
          | (1ULL << (AnyFXParser::DOT - 64))
          | (1ULL << (AnyFXParser::NOT - 64))
          | (1ULL << (AnyFXParser::EQ - 64))
          | (1ULL << (AnyFXParser::QU - 64))
          | (1ULL << (AnyFXParser::AND - 64))
          | (1ULL << (AnyFXParser::ANDSET - 64))
          | (1ULL << (AnyFXParser::OR - 64))
          | (1ULL << (AnyFXParser::ORSET - 64))
          | (1ULL << (AnyFXParser::XOR - 64))
          | (1ULL << (AnyFXParser::XORSET - 64))
          | (1ULL << (AnyFXParser::CONNJUGATE - 64))
          | (1ULL << (AnyFXParser::Q - 64))
          | (1ULL << (AnyFXParser::NU - 64))
          | (1ULL << (AnyFXParser::FORWARDSLASH - 64))
          | (1ULL << (AnyFXParser::LESS - 64))
          | (1ULL << (AnyFXParser::LESSEQ - 64))
          | (1ULL << (AnyFXParser::GREATER - 64))
          | (1ULL << (AnyFXParser::GREATEREQ - 64))
          | (1ULL << (AnyFXParser::LOGICEQ - 64))
          | (1ULL << (AnyFXParser::NOTEQ - 64))
          | (1ULL << (AnyFXParser::LOGICAND - 64))
          | (1ULL << (AnyFXParser::LOGICOR - 64))
          | (1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
          | (1ULL << (AnyFXParser::ADD_OP - 64))
          | (1ULL << (AnyFXParser::SUB_OP - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 64))
          | (1ULL << (AnyFXParser::COMMENT - 64))
          | (1ULL << (AnyFXParser::ML_COMMENT - 64))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 64))
          | (1ULL << (AnyFXParser::EXPONENT - 64))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 64))
          | (1ULL << (AnyFXParser::HEX - 64))
          | (1ULL << (AnyFXParser::IDENTIFIER - 64))
          | (1ULL << (AnyFXParser::WS - 64)))) != 0)) {
          setState(85);
          dynamic_cast<StringContext *>(_localctx)->data = _input->LT(1);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::QO)) {
            dynamic_cast<StringContext *>(_localctx)->data = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
           _localctx->val.append((dynamic_cast<StringContext *>(_localctx)->data != nullptr ? dynamic_cast<StringContext *>(_localctx)->data->getText() : "")); 
          setState(91);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(92);
        match(AnyFXParser::QO);
        break;
      }

      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 2);
        setState(93);
        match(AnyFXParser::Q);
        setState(98);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__2)
          | (1ULL << AnyFXParser::T__3)
          | (1ULL << AnyFXParser::T__4)
          | (1ULL << AnyFXParser::T__5)
          | (1ULL << AnyFXParser::T__6)
          | (1ULL << AnyFXParser::T__7)
          | (1ULL << AnyFXParser::T__8)
          | (1ULL << AnyFXParser::T__9)
          | (1ULL << AnyFXParser::T__10)
          | (1ULL << AnyFXParser::T__11)
          | (1ULL << AnyFXParser::T__12)
          | (1ULL << AnyFXParser::T__13)
          | (1ULL << AnyFXParser::T__14)
          | (1ULL << AnyFXParser::T__15)
          | (1ULL << AnyFXParser::T__16)
          | (1ULL << AnyFXParser::T__17)
          | (1ULL << AnyFXParser::T__18)
          | (1ULL << AnyFXParser::T__19)
          | (1ULL << AnyFXParser::T__20)
          | (1ULL << AnyFXParser::T__21)
          | (1ULL << AnyFXParser::T__22)
          | (1ULL << AnyFXParser::T__23)
          | (1ULL << AnyFXParser::T__24)
          | (1ULL << AnyFXParser::T__25)
          | (1ULL << AnyFXParser::T__26)
          | (1ULL << AnyFXParser::T__27)
          | (1ULL << AnyFXParser::T__28)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::T__31)
          | (1ULL << AnyFXParser::T__32)
          | (1ULL << AnyFXParser::T__33)
          | (1ULL << AnyFXParser::T__34)
          | (1ULL << AnyFXParser::T__35)
          | (1ULL << AnyFXParser::T__36)
          | (1ULL << AnyFXParser::T__37)
          | (1ULL << AnyFXParser::T__38)
          | (1ULL << AnyFXParser::T__39)
          | (1ULL << AnyFXParser::T__40)
          | (1ULL << AnyFXParser::T__41)
          | (1ULL << AnyFXParser::T__42)
          | (1ULL << AnyFXParser::T__43)
          | (1ULL << AnyFXParser::T__44)
          | (1ULL << AnyFXParser::T__45)
          | (1ULL << AnyFXParser::T__46)
          | (1ULL << AnyFXParser::T__47)
          | (1ULL << AnyFXParser::T__48)
          | (1ULL << AnyFXParser::T__49)
          | (1ULL << AnyFXParser::T__50)
          | (1ULL << AnyFXParser::T__51)
          | (1ULL << AnyFXParser::T__52)
          | (1ULL << AnyFXParser::T__53)
          | (1ULL << AnyFXParser::T__54)
          | (1ULL << AnyFXParser::T__55)
          | (1ULL << AnyFXParser::T__56)
          | (1ULL << AnyFXParser::T__57)
          | (1ULL << AnyFXParser::T__58)
          | (1ULL << AnyFXParser::T__59)
          | (1ULL << AnyFXParser::T__60)
          | (1ULL << AnyFXParser::T__61)
          | (1ULL << AnyFXParser::T__62))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::T__63 - 64))
          | (1ULL << (AnyFXParser::T__64 - 64))
          | (1ULL << (AnyFXParser::T__65 - 64))
          | (1ULL << (AnyFXParser::T__66 - 64))
          | (1ULL << (AnyFXParser::T__67 - 64))
          | (1ULL << (AnyFXParser::T__68 - 64))
          | (1ULL << (AnyFXParser::T__69 - 64))
          | (1ULL << (AnyFXParser::T__70 - 64))
          | (1ULL << (AnyFXParser::T__71 - 64))
          | (1ULL << (AnyFXParser::T__72 - 64))
          | (1ULL << (AnyFXParser::T__73 - 64))
          | (1ULL << (AnyFXParser::T__74 - 64))
          | (1ULL << (AnyFXParser::SC - 64))
          | (1ULL << (AnyFXParser::CO - 64))
          | (1ULL << (AnyFXParser::COL - 64))
          | (1ULL << (AnyFXParser::LP - 64))
          | (1ULL << (AnyFXParser::RP - 64))
          | (1ULL << (AnyFXParser::LB - 64))
          | (1ULL << (AnyFXParser::RB - 64))
          | (1ULL << (AnyFXParser::LL - 64))
          | (1ULL << (AnyFXParser::RR - 64))
          | (1ULL << (AnyFXParser::DOT - 64))
          | (1ULL << (AnyFXParser::NOT - 64))
          | (1ULL << (AnyFXParser::EQ - 64))
          | (1ULL << (AnyFXParser::QO - 64))
          | (1ULL << (AnyFXParser::QU - 64))
          | (1ULL << (AnyFXParser::AND - 64))
          | (1ULL << (AnyFXParser::ANDSET - 64))
          | (1ULL << (AnyFXParser::OR - 64))
          | (1ULL << (AnyFXParser::ORSET - 64))
          | (1ULL << (AnyFXParser::XOR - 64))
          | (1ULL << (AnyFXParser::XORSET - 64))
          | (1ULL << (AnyFXParser::CONNJUGATE - 64))
          | (1ULL << (AnyFXParser::NU - 64))
          | (1ULL << (AnyFXParser::FORWARDSLASH - 64))
          | (1ULL << (AnyFXParser::LESS - 64))
          | (1ULL << (AnyFXParser::LESSEQ - 64))
          | (1ULL << (AnyFXParser::GREATER - 64))
          | (1ULL << (AnyFXParser::GREATEREQ - 64))
          | (1ULL << (AnyFXParser::LOGICEQ - 64))
          | (1ULL << (AnyFXParser::NOTEQ - 64))
          | (1ULL << (AnyFXParser::LOGICAND - 64))
          | (1ULL << (AnyFXParser::LOGICOR - 64))
          | (1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
          | (1ULL << (AnyFXParser::ADD_OP - 64))
          | (1ULL << (AnyFXParser::SUB_OP - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 64))
          | (1ULL << (AnyFXParser::COMMENT - 64))
          | (1ULL << (AnyFXParser::ML_COMMENT - 64))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 64))
          | (1ULL << (AnyFXParser::EXPONENT - 64))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 64))
          | (1ULL << (AnyFXParser::HEX - 64))
          | (1ULL << (AnyFXParser::IDENTIFIER - 64))
          | (1ULL << (AnyFXParser::WS - 64)))) != 0)) {
          setState(94);
          dynamic_cast<StringContext *>(_localctx)->data = _input->LT(1);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::Q)) {
            dynamic_cast<StringContext *>(_localctx)->data = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
           _localctx->val.append((dynamic_cast<StringContext *>(_localctx)->data != nullptr ? dynamic_cast<StringContext *>(_localctx)->data->getText() : "")); 
          setState(100);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(101);
        match(AnyFXParser::Q);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

AnyFXParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::BooleanContext::getRuleIndex() const {
  return AnyFXParser::RuleBoolean;
}

void AnyFXParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void AnyFXParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}

AnyFXParser::BooleanContext* AnyFXParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 2, AnyFXParser::RuleBoolean);

          dynamic_cast<BooleanContext *>(_localctx)->val =  false;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        match(AnyFXParser::T__0);
         dynamic_cast<BooleanContext *>(_localctx)->val =  true; 
        break;
      }

      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(106);
        match(AnyFXParser::T__1);
         dynamic_cast<BooleanContext *>(_localctx)->val =  false; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreprocessContext ------------------------------------------------------------------

AnyFXParser::PreprocessContext::PreprocessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::PreprocessContext::EOF() {
  return getToken(AnyFXParser::EOF, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::PreprocessContext::INTEGERLITERAL() {
  return getTokens(AnyFXParser::INTEGERLITERAL);
}

tree::TerminalNode* AnyFXParser::PreprocessContext::INTEGERLITERAL(size_t i) {
  return getToken(AnyFXParser::INTEGERLITERAL, i);
}

std::vector<AnyFXParser::StringContext *> AnyFXParser::PreprocessContext::string() {
  return getRuleContexts<AnyFXParser::StringContext>();
}

AnyFXParser::StringContext* AnyFXParser::PreprocessContext::string(size_t i) {
  return getRuleContext<AnyFXParser::StringContext>(i);
}


size_t AnyFXParser::PreprocessContext::getRuleIndex() const {
  return AnyFXParser::RulePreprocess;
}

void AnyFXParser::PreprocessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPreprocess(this);
}

void AnyFXParser::PreprocessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPreprocess(this);
}

AnyFXParser::PreprocessContext* AnyFXParser::preprocess() {
  PreprocessContext *_localctx = _tracker.createInstance<PreprocessContext>(_ctx, getState());
  enterRule(_localctx, 4, AnyFXParser::RulePreprocess);

          Token* start = nullptr;
      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(119);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(117);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
           start = _input->LT(1); 
          setState(111);
          match(AnyFXParser::T__2);
          setState(112);
          dynamic_cast<PreprocessContext *>(_localctx)->line = match(AnyFXParser::INTEGERLITERAL);
          setState(113);
          dynamic_cast<PreprocessContext *>(_localctx)->path = string();
           lines.push_back(std::make_tuple(atoi((dynamic_cast<PreprocessContext *>(_localctx)->line != nullptr ? dynamic_cast<PreprocessContext *>(_localctx)->line->getText() : "").c_str()), _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), (dynamic_cast<PreprocessContext *>(_localctx)->path != nullptr ? _input->getText(dynamic_cast<PreprocessContext *>(_localctx)->path->start, dynamic_cast<PreprocessContext *>(_localctx)->path->stop) : nullptr))); 
          break;
        }

        case 2: {
          setState(116);
          matchWildcard();
          break;
        }

        } 
      }
      setState(121);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(122);
    match(AnyFXParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntryContext ------------------------------------------------------------------

AnyFXParser::EntryContext::EntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::EffectContext* AnyFXParser::EntryContext::effect() {
  return getRuleContext<AnyFXParser::EffectContext>(0);
}

tree::TerminalNode* AnyFXParser::EntryContext::EOF() {
  return getToken(AnyFXParser::EOF, 0);
}


size_t AnyFXParser::EntryContext::getRuleIndex() const {
  return AnyFXParser::RuleEntry;
}

void AnyFXParser::EntryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntry(this);
}

void AnyFXParser::EntryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntry(this);
}

AnyFXParser::EntryContext* AnyFXParser::entry() {
  EntryContext *_localctx = _tracker.createInstance<EntryContext>(_ctx, getState());
  enterRule(_localctx, 6, AnyFXParser::RuleEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    dynamic_cast<EntryContext *>(_localctx)->effectContext = effect();

            dynamic_cast<EntryContext *>(_localctx)->returnEffect =  dynamic_cast<EntryContext *>(_localctx)->effectContext->eff;
        
    setState(126);
    match(AnyFXParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EffectContext ------------------------------------------------------------------

AnyFXParser::EffectContext::EffectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::ConstantContext *> AnyFXParser::EffectContext::constant() {
  return getRuleContexts<AnyFXParser::ConstantContext>();
}

AnyFXParser::ConstantContext* AnyFXParser::EffectContext::constant(size_t i) {
  return getRuleContext<AnyFXParser::ConstantContext>(i);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::EffectContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::EffectContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

std::vector<AnyFXParser::RenderStateContext *> AnyFXParser::EffectContext::renderState() {
  return getRuleContexts<AnyFXParser::RenderStateContext>();
}

AnyFXParser::RenderStateContext* AnyFXParser::EffectContext::renderState(size_t i) {
  return getRuleContext<AnyFXParser::RenderStateContext>(i);
}

std::vector<AnyFXParser::FunctionContext *> AnyFXParser::EffectContext::function() {
  return getRuleContexts<AnyFXParser::FunctionContext>();
}

AnyFXParser::FunctionContext* AnyFXParser::EffectContext::function(size_t i) {
  return getRuleContext<AnyFXParser::FunctionContext>(i);
}

std::vector<AnyFXParser::ProgramContext *> AnyFXParser::EffectContext::program() {
  return getRuleContexts<AnyFXParser::ProgramContext>();
}

AnyFXParser::ProgramContext* AnyFXParser::EffectContext::program(size_t i) {
  return getRuleContext<AnyFXParser::ProgramContext>(i);
}

std::vector<AnyFXParser::StructureContext *> AnyFXParser::EffectContext::structure() {
  return getRuleContexts<AnyFXParser::StructureContext>();
}

AnyFXParser::StructureContext* AnyFXParser::EffectContext::structure(size_t i) {
  return getRuleContext<AnyFXParser::StructureContext>(i);
}

std::vector<AnyFXParser::VarblockContext *> AnyFXParser::EffectContext::varblock() {
  return getRuleContexts<AnyFXParser::VarblockContext>();
}

AnyFXParser::VarblockContext* AnyFXParser::EffectContext::varblock(size_t i) {
  return getRuleContext<AnyFXParser::VarblockContext>(i);
}

std::vector<AnyFXParser::VarbufferContext *> AnyFXParser::EffectContext::varbuffer() {
  return getRuleContexts<AnyFXParser::VarbufferContext>();
}

AnyFXParser::VarbufferContext* AnyFXParser::EffectContext::varbuffer(size_t i) {
  return getRuleContext<AnyFXParser::VarbufferContext>(i);
}

std::vector<AnyFXParser::SubroutineContext *> AnyFXParser::EffectContext::subroutine() {
  return getRuleContexts<AnyFXParser::SubroutineContext>();
}

AnyFXParser::SubroutineContext* AnyFXParser::EffectContext::subroutine(size_t i) {
  return getRuleContext<AnyFXParser::SubroutineContext>(i);
}

std::vector<AnyFXParser::SamplerContext *> AnyFXParser::EffectContext::sampler() {
  return getRuleContexts<AnyFXParser::SamplerContext>();
}

AnyFXParser::SamplerContext* AnyFXParser::EffectContext::sampler(size_t i) {
  return getRuleContext<AnyFXParser::SamplerContext>(i);
}


size_t AnyFXParser::EffectContext::getRuleIndex() const {
  return AnyFXParser::RuleEffect;
}

void AnyFXParser::EffectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEffect(this);
}

void AnyFXParser::EffectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEffect(this);
}

AnyFXParser::EffectContext* AnyFXParser::effect() {
  EffectContext *_localctx = _tracker.createInstance<EffectContext>(_ctx, getState());
  enterRule(_localctx, 8, AnyFXParser::RuleEffect);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(160);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(158);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(128);
          dynamic_cast<EffectContext *>(_localctx)->constantContext = constant();
           _localctx->eff.AddConstant(dynamic_cast<EffectContext *>(_localctx)->constantContext->cons);
          break;
        }

        case 2: {
          setState(131);
          dynamic_cast<EffectContext *>(_localctx)->variableContext = variable();
           _localctx->eff.AddVariable(dynamic_cast<EffectContext *>(_localctx)->variableContext->var); 
          break;
        }

        case 3: {
          setState(134);
          dynamic_cast<EffectContext *>(_localctx)->renderStateContext = renderState();
           _localctx->eff.AddRenderState(dynamic_cast<EffectContext *>(_localctx)->renderStateContext->state); 
          break;
        }

        case 4: {
          setState(137);
          dynamic_cast<EffectContext *>(_localctx)->functionContext = function();
           _localctx->eff.AddFunction(dynamic_cast<EffectContext *>(_localctx)->functionContext->func); 
          break;
        }

        case 5: {
          setState(140);
          dynamic_cast<EffectContext *>(_localctx)->programContext = program();
           _localctx->eff.AddProgram(dynamic_cast<EffectContext *>(_localctx)->programContext->prog); 
          break;
        }

        case 6: {
          setState(143);
          dynamic_cast<EffectContext *>(_localctx)->structureContext = structure();
           _localctx->eff.AddStructure(dynamic_cast<EffectContext *>(_localctx)->structureContext->struc); 
          break;
        }

        case 7: {
          setState(146);
          dynamic_cast<EffectContext *>(_localctx)->varblockContext = varblock();
           _localctx->eff.AddVarBlock(dynamic_cast<EffectContext *>(_localctx)->varblockContext->block); 
          break;
        }

        case 8: {
          setState(149);
          dynamic_cast<EffectContext *>(_localctx)->varbufferContext = varbuffer();
           _localctx->eff.AddVarBuffer(dynamic_cast<EffectContext *>(_localctx)->varbufferContext->buffer); 
          break;
        }

        case 9: {
          setState(152);
          dynamic_cast<EffectContext *>(_localctx)->subroutineContext = subroutine();
           _localctx->eff.AddSubroutine(dynamic_cast<EffectContext *>(_localctx)->subroutineContext->subrout); 
          break;
        }

        case 10: {
          setState(155);
          dynamic_cast<EffectContext *>(_localctx)->samplerContext = sampler();
           _localctx->eff.AddSampler(dynamic_cast<EffectContext *>(_localctx)->samplerContext->samp); 
          break;
        }

        } 
      }
      setState(162);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifierContext ------------------------------------------------------------------

AnyFXParser::QualifierContext::QualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::QualifierContext::getRuleIndex() const {
  return AnyFXParser::RuleQualifier;
}

void AnyFXParser::QualifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifier(this);
}

void AnyFXParser::QualifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifier(this);
}

AnyFXParser::QualifierContext* AnyFXParser::qualifier() {
  QualifierContext *_localctx = _tracker.createInstance<QualifierContext>(_ctx, getState());
  enterRule(_localctx, 10, AnyFXParser::RuleQualifier);

      Token* startToken = _input->LT(1);

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   _ctx->stop = _input->LT(-1);

        dynamic_cast<QualifierContext *>(_localctx)->str =  startToken->getText();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifierValuedContext ------------------------------------------------------------------

AnyFXParser::QualifierValuedContext::QualifierValuedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AnyFXParser::QualifierValuedContext::getRuleIndex() const {
  return AnyFXParser::RuleQualifierValued;
}

void AnyFXParser::QualifierValuedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifierValued(this);
}

void AnyFXParser::QualifierValuedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifierValued(this);
}

AnyFXParser::QualifierValuedContext* AnyFXParser::qualifierValued() {
  QualifierValuedContext *_localctx = _tracker.createInstance<QualifierValuedContext>(_ctx, getState());
  enterRule(_localctx, 12, AnyFXParser::RuleQualifierValued);

      Token* startToken = _input->LT(1);

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__60)
      | (1ULL << AnyFXParser::T__61)
      | (1ULL << AnyFXParser::T__62))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   _ctx->stop = _input->LT(-1);

        dynamic_cast<QualifierValuedContext *>(_localctx)->str =  startToken->getText();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AnyFXParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::TypeContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}


size_t AnyFXParser::TypeContext::getRuleIndex() const {
  return AnyFXParser::RuleType;
}

void AnyFXParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AnyFXParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AnyFXParser::TypeContext* AnyFXParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, AnyFXParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    dynamic_cast<TypeContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);

            std::string typeString((dynamic_cast<TypeContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<TypeContext *>(_localctx)->identifierToken->getText() : ""));
            if (typeString == "float") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Float); }
            else if (typeString == "int") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Integer); }
            else if (typeString == "bool") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Bool); }
            else if (typeString == "uint") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::UInteger); }
            else if (typeString == "short") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Short); }
            else if (typeString == "string") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::String); }
            else if (typeString == "void") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::Void); }
            else if (typeString == "textureHandle") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::TextureHandle); }
            else if (typeString == "imageHandle") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::ImageHandle); }
            else if (typeString == "samplerHandle") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::SamplerHandle); }
            else if (typeString == "inputAttachment") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachment); }
            else if (typeString == "inputAttachmentMS") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentMS); }
            else if (typeString == "inputAttachmentInteger") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentInteger); }
            else if (typeString == "inputAttachmentIntegerMS") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentIntegerMS); }
            else if (typeString == "inputAttachmentUInteger") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentUInteger); }
            else if (typeString == "inputAttachmentUIntegerMS") { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::InputAttachmentUIntegerMS); }

            // HLSL types
            else if (typeString == "float2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Float2); }
            else if (typeString == "float3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Float3); }
            else if (typeString == "float4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Float4); }
            else if (typeString == "int2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Integer2); }
            else if (typeString == "int3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Integer3); }
            else if (typeString == "int4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Integer4); }
            else if (typeString == "uint2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::UInteger2); }
            else if (typeString == "uint3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::UInteger3); }
            else if (typeString == "uint4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::UInteger4); }
            else if (typeString == "short2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Short2); }
            else if (typeString == "short3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Short3); }
            else if (typeString == "short4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Short4); }
            else if (typeString == "bool2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Bool2); }
            else if (typeString == "bool3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Bool3); }
            else if (typeString == "bool4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Bool4); }
            else if (typeString == "float2x2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix2x2); }
            else if (typeString == "float2x3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix2x3); }
            else if (typeString == "float2x4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix2x4); }
            else if (typeString == "float3x2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix3x2); }
            else if (typeString == "float3x3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix3x3); }
            else if (typeString == "float3x4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix3x4); }
            else if (typeString == "float4x2") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix4x2); }
            else if (typeString == "float4x3") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix4x3); }
            else if (typeString == "float4x4") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Matrix4x4); }
            else if (typeString == "Texture1D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler1D); }
            else if (typeString == "Texture1DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler1DArray); }
            else if (typeString == "Texture2D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2D); }
            else if (typeString == "Texture2DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2DArray); }
            else if (typeString == "Texture2DMS") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2DMS); }
            else if (typeString == "Texture2DMSArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler2DMSArray); }
            else if (typeString == "Texture3D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Sampler3D); }
            else if (typeString == "TextureCube") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::SamplerCube); }
            else if (typeString == "TextureCubeArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::SamplerCubeArray); }
            else if (typeString == "RWTexture1D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image1D); }
            else if (typeString == "RWTexture1DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image1DArray); }
            else if (typeString == "RWTexture2D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2D); }
            else if (typeString == "RWTexture2DArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2DArray); }
            else if (typeString == "RWTexture2DMS") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2DMS); }
            else if (typeString == "RWTexture2DMSArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image2DMSArray); }
            else if (typeString == "RWTexture3D") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::Image3D); }
            else if (typeString == "RWTextureCube") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::ImageCube); }
            else if (typeString == "RWTextureCubeArray") { _localctx->ty.SetStyle(DataType::HLSL); _localctx->ty.SetType(DataType::ImageCubeArray); }

            // GLSL types
            else if (typeString == "vec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Float2); }
            else if (typeString == "vec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Float3); }
            else if (typeString == "vec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Float4); }
            else if (typeString == "ivec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Integer2); }
            else if (typeString == "ivec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Integer3); }
            else if (typeString == "ivec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Integer4); }
            else if (typeString == "uvec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::UInteger2); }
            else if (typeString == "uvec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::UInteger3); }
            else if (typeString == "uvec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::UInteger4); }
            else if (typeString == "svec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Short2); }
            else if (typeString == "svec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Short3); }
            else if (typeString == "svec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Short4); }
            else if (typeString == "bvec2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Bool2); }
            else if (typeString == "bvec3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Bool3); }
            else if (typeString == "bvec4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Bool4); }
            else if (typeString == "mat2x2" || typeString == "mat2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix2x2); }
            else if (typeString == "mat2x3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix2x3); }
            else if (typeString == "mat2x4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix2x4); }
            else if (typeString == "mat3x2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix3x2); }
            else if (typeString == "mat3x3" || typeString == "mat3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix3x3); }
            else if (typeString == "mat3x4") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix3x4); }
            else if (typeString == "mat4x2") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix4x2); }
            else if (typeString == "mat4x3") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix4x3); }
            else if (typeString == "mat4x4" || typeString == "mat4" ) { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Matrix4x4); }
            else if (typeString == "sampler1D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler1D); }
            else if (typeString == "sampler1DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler1DArray); }
            else if (typeString == "sampler2D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2D); }
            else if (typeString == "sampler2DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2DArray); }
            else if (typeString == "sampler2DMS") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2DMS); }
            else if (typeString == "sampler2DMSArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler2DMSArray); }
            else if (typeString == "sampler3D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Sampler3D); }
            else if (typeString == "samplerCube") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::SamplerCube); }
            else if (typeString == "samplerCubeArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::SamplerCubeArray); }
            else if (typeString == "image1D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image1D); }
            else if (typeString == "image1DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image1DArray); }
            else if (typeString == "image2D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2D); }
            else if (typeString == "image2DArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2DArray); }
            else if (typeString == "image2DMS") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2DMS); }
            else if (typeString == "image2DMSArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image2DMSArray); }
            else if (typeString == "image3D") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Image3D); }
            else if (typeString == "imageCube") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::ImageCube); }
            else if (typeString == "imageCubeArray") { _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::ImageCubeArray); }
            else if (typeString == "texture1D") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture1D); }
            else if (typeString == "texture1DArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture1DArray); }
            else if (typeString == "texture2D") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2D); }
            else if (typeString == "texture2DArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2DArray); }
            else if (typeString == "texture2DMS") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2DMS); }
            else if (typeString == "texture2DMSArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture2DMSArray); }
            else if (typeString == "texture3D") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::Texture3D); }
            else if (typeString == "textureCube") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::TextureCube); }
            else if (typeString == "textureCubeArray") 	{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::TextureCubeArray); }
            else if (typeString == "atomic_uint") 		{ _localctx->ty.SetStyle(DataType::GLSL); _localctx->ty.SetType(DataType::AtomicCounter); }

            // user defined type detected
            else { _localctx->ty.SetStyle(DataType::Generic); _localctx->ty.SetType(DataType::UserType); _localctx->ty.SetName(typeString); }
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifierExpressionContext ------------------------------------------------------------------

AnyFXParser::QualifierExpressionContext::QualifierExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ParantexpressionContext* AnyFXParser::QualifierExpressionContext::parantexpression() {
  return getRuleContext<AnyFXParser::ParantexpressionContext>(0);
}

AnyFXParser::QualifierValuedContext* AnyFXParser::QualifierExpressionContext::qualifierValued() {
  return getRuleContext<AnyFXParser::QualifierValuedContext>(0);
}


size_t AnyFXParser::QualifierExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleQualifierExpression;
}

void AnyFXParser::QualifierExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifierExpression(this);
}

void AnyFXParser::QualifierExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifierExpression(this);
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::qualifierExpression() {
  QualifierExpressionContext *_localctx = _tracker.createInstance<QualifierExpressionContext>(_ctx, getState());
  enterRule(_localctx, 16, AnyFXParser::RuleQualifierExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    dynamic_cast<QualifierExpressionContext *>(_localctx)->base = qualifierValued();
    setState(171);
    dynamic_cast<QualifierExpressionContext *>(_localctx)->parantexpressionContext = parantexpression();
     _localctx->q.name = dynamic_cast<QualifierExpressionContext *>(_localctx)->base->str; _localctx->q.expr = dynamic_cast<QualifierExpressionContext *>(_localctx)->parantexpressionContext->tree; 
            
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructureContext ------------------------------------------------------------------

AnyFXParser::StructureContext::StructureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::StructureContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::ParameterContext *> AnyFXParser::StructureContext::parameter() {
  return getRuleContexts<AnyFXParser::ParameterContext>();
}

AnyFXParser::ParameterContext* AnyFXParser::StructureContext::parameter(size_t i) {
  return getRuleContext<AnyFXParser::ParameterContext>(i);
}


size_t AnyFXParser::StructureContext::getRuleIndex() const {
  return AnyFXParser::RuleStructure;
}

void AnyFXParser::StructureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructure(this);
}

void AnyFXParser::StructureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructure(this);
}

AnyFXParser::StructureContext* AnyFXParser::structure() {
  StructureContext *_localctx = _tracker.createInstance<StructureContext>(_ctx, getState());
  enterRule(_localctx, 18, AnyFXParser::RuleStructure);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(AnyFXParser::T__63);
    setState(175);
    dynamic_cast<StructureContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->struc, _input); 
    setState(177);
    match(AnyFXParser::LB);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59))) != 0) || _la == AnyFXParser::LL

    || _la == AnyFXParser::IDENTIFIER) {
      setState(178);
      dynamic_cast<StructureContext *>(_localctx)->parameterContext = parameter();
      setState(179);
      match(AnyFXParser::SC);
       _localctx->struc.AddParameter(dynamic_cast<StructureContext *>(_localctx)->parameterContext->param); 
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(187);
    match(AnyFXParser::RB);
    setState(188);
    match(AnyFXParser::SC);
     _localctx->struc.SetName((dynamic_cast<StructureContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<StructureContext *>(_localctx)->identifierToken->getText() : ""));  
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarblockContext ------------------------------------------------------------------

AnyFXParser::VarblockContext::VarblockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::VarblockContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::VarblockContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::VarblockContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::VarblockContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VarblockContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VarblockContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

AnyFXParser::AnnotationContext* AnyFXParser::VarblockContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::VarblockContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::VarblockContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

AnyFXParser::ExpressionContext* AnyFXParser::VarblockContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::VarblockContext::getRuleIndex() const {
  return AnyFXParser::RuleVarblock;
}

void AnyFXParser::VarblockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarblock(this);
}

void AnyFXParser::VarblockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarblock(this);
}

AnyFXParser::VarblockContext* AnyFXParser::varblock() {
  VarblockContext *_localctx = _tracker.createInstance<VarblockContext>(_ctx, getState());
  enterRule(_localctx, 20, AnyFXParser::RuleVarblock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59)
      | (1ULL << AnyFXParser::T__60)
      | (1ULL << AnyFXParser::T__61)
      | (1ULL << AnyFXParser::T__62))) != 0)) {
      setState(197);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AnyFXParser::T__3:
        case AnyFXParser::T__4:
        case AnyFXParser::T__5:
        case AnyFXParser::T__6:
        case AnyFXParser::T__7:
        case AnyFXParser::T__8:
        case AnyFXParser::T__9:
        case AnyFXParser::T__10:
        case AnyFXParser::T__11:
        case AnyFXParser::T__12:
        case AnyFXParser::T__13:
        case AnyFXParser::T__14:
        case AnyFXParser::T__15:
        case AnyFXParser::T__16:
        case AnyFXParser::T__17:
        case AnyFXParser::T__18:
        case AnyFXParser::T__19:
        case AnyFXParser::T__20:
        case AnyFXParser::T__21:
        case AnyFXParser::T__22:
        case AnyFXParser::T__23:
        case AnyFXParser::T__24:
        case AnyFXParser::T__25:
        case AnyFXParser::T__26:
        case AnyFXParser::T__27:
        case AnyFXParser::T__28:
        case AnyFXParser::T__29:
        case AnyFXParser::T__30:
        case AnyFXParser::T__31:
        case AnyFXParser::T__32:
        case AnyFXParser::T__33:
        case AnyFXParser::T__34:
        case AnyFXParser::T__35:
        case AnyFXParser::T__36:
        case AnyFXParser::T__37:
        case AnyFXParser::T__38:
        case AnyFXParser::T__39:
        case AnyFXParser::T__40:
        case AnyFXParser::T__41:
        case AnyFXParser::T__42:
        case AnyFXParser::T__43:
        case AnyFXParser::T__44:
        case AnyFXParser::T__45:
        case AnyFXParser::T__46:
        case AnyFXParser::T__47:
        case AnyFXParser::T__48:
        case AnyFXParser::T__49:
        case AnyFXParser::T__50:
        case AnyFXParser::T__51:
        case AnyFXParser::T__52:
        case AnyFXParser::T__53:
        case AnyFXParser::T__54:
        case AnyFXParser::T__55:
        case AnyFXParser::T__56:
        case AnyFXParser::T__57:
        case AnyFXParser::T__58:
        case AnyFXParser::T__59: {
          setState(191);
          dynamic_cast<VarblockContext *>(_localctx)->qualifierContext = qualifier();
           _localctx->block.AddQualifier(dynamic_cast<VarblockContext *>(_localctx)->qualifierContext->str); 
          break;
        }

        case AnyFXParser::T__60:
        case AnyFXParser::T__61:
        case AnyFXParser::T__62: {
          setState(194);
          dynamic_cast<VarblockContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->block.AddQualifierExpression(dynamic_cast<VarblockContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    setState(202);
    match(AnyFXParser::T__64);
    setState(203);
    dynamic_cast<VarblockContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->block, _input); _localctx->block.SetName((dynamic_cast<VarblockContext *>(_localctx)->name != nullptr ? dynamic_cast<VarblockContext *>(_localctx)->name->getText() : "")); 
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(205);
      dynamic_cast<VarblockContext *>(_localctx)->annotationContext = annotation();
       _localctx->block.SetAnnotation(dynamic_cast<VarblockContext *>(_localctx)->annotationContext->annot); 
    }
    setState(210);
    match(AnyFXParser::LB);
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59)
      | (1ULL << AnyFXParser::T__60)
      | (1ULL << AnyFXParser::T__61)
      | (1ULL << AnyFXParser::T__62))) != 0) || _la == AnyFXParser::IDENTIFIER) {
      setState(211);
      dynamic_cast<VarblockContext *>(_localctx)->variableContext = variable();
       _localctx->block.AddVariable(dynamic_cast<VarblockContext *>(_localctx)->variableContext->var); 
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(219);
    match(AnyFXParser::RB);
    setState(232);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(220);
      dynamic_cast<VarblockContext *>(_localctx)->varName = match(AnyFXParser::IDENTIFIER);
       _localctx->block.SetStructName((dynamic_cast<VarblockContext *>(_localctx)->varName != nullptr ? dynamic_cast<VarblockContext *>(_localctx)->varName->getText() : "")); 
      setState(230);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(222);
        match(AnyFXParser::LL);
        setState(223);
        match(AnyFXParser::RR);
         _localctx->block.SetArrayExpression(nullptr); 
        break;
      }

      case 2: {
        setState(225);
        match(AnyFXParser::LL);
        setState(226);
        dynamic_cast<VarblockContext *>(_localctx)->arraySize = expression();
        setState(227);
        match(AnyFXParser::RR);
         _localctx->block.SetArrayExpression(dynamic_cast<VarblockContext *>(_localctx)->arraySize->tree); 
        break;
      }

      }
    }
    setState(234);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarbufferContext ------------------------------------------------------------------

AnyFXParser::VarbufferContext::VarbufferContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::VarbufferContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::VarbufferContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::VarbufferContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VarbufferContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VarbufferContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

AnyFXParser::AnnotationContext* AnyFXParser::VarbufferContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::VariableContext *> AnyFXParser::VarbufferContext::variable() {
  return getRuleContexts<AnyFXParser::VariableContext>();
}

AnyFXParser::VariableContext* AnyFXParser::VarbufferContext::variable(size_t i) {
  return getRuleContext<AnyFXParser::VariableContext>(i);
}

AnyFXParser::ExpressionContext* AnyFXParser::VarbufferContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::VarbufferContext::getRuleIndex() const {
  return AnyFXParser::RuleVarbuffer;
}

void AnyFXParser::VarbufferContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarbuffer(this);
}

void AnyFXParser::VarbufferContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarbuffer(this);
}

AnyFXParser::VarbufferContext* AnyFXParser::varbuffer() {
  VarbufferContext *_localctx = _tracker.createInstance<VarbufferContext>(_ctx, getState());
  enterRule(_localctx, 22, AnyFXParser::RuleVarbuffer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59)
      | (1ULL << AnyFXParser::T__60)
      | (1ULL << AnyFXParser::T__61)
      | (1ULL << AnyFXParser::T__62))) != 0)) {
      setState(242);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AnyFXParser::T__3:
        case AnyFXParser::T__4:
        case AnyFXParser::T__5:
        case AnyFXParser::T__6:
        case AnyFXParser::T__7:
        case AnyFXParser::T__8:
        case AnyFXParser::T__9:
        case AnyFXParser::T__10:
        case AnyFXParser::T__11:
        case AnyFXParser::T__12:
        case AnyFXParser::T__13:
        case AnyFXParser::T__14:
        case AnyFXParser::T__15:
        case AnyFXParser::T__16:
        case AnyFXParser::T__17:
        case AnyFXParser::T__18:
        case AnyFXParser::T__19:
        case AnyFXParser::T__20:
        case AnyFXParser::T__21:
        case AnyFXParser::T__22:
        case AnyFXParser::T__23:
        case AnyFXParser::T__24:
        case AnyFXParser::T__25:
        case AnyFXParser::T__26:
        case AnyFXParser::T__27:
        case AnyFXParser::T__28:
        case AnyFXParser::T__29:
        case AnyFXParser::T__30:
        case AnyFXParser::T__31:
        case AnyFXParser::T__32:
        case AnyFXParser::T__33:
        case AnyFXParser::T__34:
        case AnyFXParser::T__35:
        case AnyFXParser::T__36:
        case AnyFXParser::T__37:
        case AnyFXParser::T__38:
        case AnyFXParser::T__39:
        case AnyFXParser::T__40:
        case AnyFXParser::T__41:
        case AnyFXParser::T__42:
        case AnyFXParser::T__43:
        case AnyFXParser::T__44:
        case AnyFXParser::T__45:
        case AnyFXParser::T__46:
        case AnyFXParser::T__47:
        case AnyFXParser::T__48:
        case AnyFXParser::T__49:
        case AnyFXParser::T__50:
        case AnyFXParser::T__51:
        case AnyFXParser::T__52:
        case AnyFXParser::T__53:
        case AnyFXParser::T__54:
        case AnyFXParser::T__55:
        case AnyFXParser::T__56:
        case AnyFXParser::T__57:
        case AnyFXParser::T__58:
        case AnyFXParser::T__59: {
          setState(236);
          dynamic_cast<VarbufferContext *>(_localctx)->qualifierContext = qualifier();
           _localctx->buffer.AddQualifier(dynamic_cast<VarbufferContext *>(_localctx)->qualifierContext->str); 
          break;
        }

        case AnyFXParser::T__60:
        case AnyFXParser::T__61:
        case AnyFXParser::T__62: {
          setState(239);
          dynamic_cast<VarbufferContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->buffer.AddQualifierExpression(dynamic_cast<VarbufferContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(246);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    setState(247);
    match(AnyFXParser::T__65);
    setState(248);
    dynamic_cast<VarbufferContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->buffer, _input); _localctx->buffer.SetName((dynamic_cast<VarbufferContext *>(_localctx)->name != nullptr ? dynamic_cast<VarbufferContext *>(_localctx)->name->getText() : "")); 
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(250);
      dynamic_cast<VarbufferContext *>(_localctx)->annotationContext = annotation();
       _localctx->buffer.SetAnnotation(dynamic_cast<VarbufferContext *>(_localctx)->annotationContext->annot); 
    }
    setState(255);
    match(AnyFXParser::LB);
    setState(261);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59)
      | (1ULL << AnyFXParser::T__60)
      | (1ULL << AnyFXParser::T__61)
      | (1ULL << AnyFXParser::T__62))) != 0) || _la == AnyFXParser::IDENTIFIER) {
      setState(256);
      dynamic_cast<VarbufferContext *>(_localctx)->variableContext = variable();
      _localctx->buffer.AddVariable(dynamic_cast<VarbufferContext *>(_localctx)->variableContext->var); 
      setState(263);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(264);
    match(AnyFXParser::RB);
    setState(277);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(265);
      dynamic_cast<VarbufferContext *>(_localctx)->varName = match(AnyFXParser::IDENTIFIER);
       _localctx->buffer.SetStructName((dynamic_cast<VarbufferContext *>(_localctx)->varName != nullptr ? dynamic_cast<VarbufferContext *>(_localctx)->varName->getText() : "")); 
      setState(275);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(267);
        match(AnyFXParser::LL);
        setState(268);
        match(AnyFXParser::RR);
         _localctx->buffer.SetArrayExpression(nullptr); 
        break;
      }

      case 2: {
        setState(270);
        match(AnyFXParser::LL);
        setState(271);
        dynamic_cast<VarbufferContext *>(_localctx)->arraySize = expression();
        setState(272);
        match(AnyFXParser::RR);
         _localctx->buffer.SetArrayExpression(dynamic_cast<VarbufferContext *>(_localctx)->arraySize->tree); 
        break;
      }

      }
    }
    setState(279);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubroutineContext ------------------------------------------------------------------

AnyFXParser::SubroutineContext::SubroutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ParameterListContext* AnyFXParser::SubroutineContext::parameterList() {
  return getRuleContext<AnyFXParser::ParameterListContext>(0);
}

AnyFXParser::TypeContext* AnyFXParser::SubroutineContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::FunctionContext* AnyFXParser::SubroutineContext::function() {
  return getRuleContext<AnyFXParser::FunctionContext>(0);
}


size_t AnyFXParser::SubroutineContext::getRuleIndex() const {
  return AnyFXParser::RuleSubroutine;
}

void AnyFXParser::SubroutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubroutine(this);
}

void AnyFXParser::SubroutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubroutine(this);
}

AnyFXParser::SubroutineContext* AnyFXParser::subroutine() {
  SubroutineContext *_localctx = _tracker.createInstance<SubroutineContext>(_ctx, getState());
  enterRule(_localctx, 24, AnyFXParser::RuleSubroutine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__66: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        match(AnyFXParser::T__66);
        setState(282);
        dynamic_cast<SubroutineContext *>(_localctx)->retval = type();
        setState(283);
        dynamic_cast<SubroutineContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
         SetupFile(&_localctx->subrout, _input); 
        setState(285);
        match(AnyFXParser::LP);
        setState(286);
        dynamic_cast<SubroutineContext *>(_localctx)->parameterListContext = parameterList();
        setState(287);
        match(AnyFXParser::RP);
        setState(288);
        match(AnyFXParser::SC);

                _localctx->subrout.SetSubroutineType(Subroutine::Signature);
                _localctx->subrout.SetName((dynamic_cast<SubroutineContext *>(_localctx)->name != nullptr ? dynamic_cast<SubroutineContext *>(_localctx)->name->getText() : ""));
                _localctx->subrout.SetParameters(dynamic_cast<SubroutineContext *>(_localctx)->parameterListContext->parameters);
                _localctx->subrout.SetReturnType(dynamic_cast<SubroutineContext *>(_localctx)->retval->ty);
            
        break;
      }

      case AnyFXParser::T__67: {
        enterOuterAlt(_localctx, 2);
        setState(291);
        match(AnyFXParser::T__67);
        setState(292);
        match(AnyFXParser::LP);
        setState(293);
        dynamic_cast<SubroutineContext *>(_localctx)->signature = match(AnyFXParser::IDENTIFIER);
        setState(294);
        match(AnyFXParser::RP);
         SetupFile(&_localctx->subrout, _input); 
        setState(296);
        dynamic_cast<SubroutineContext *>(_localctx)->functionContext = function();

                _localctx->subrout.SetName(dynamic_cast<SubroutineContext *>(_localctx)->functionContext->func.GetName());
                _localctx->subrout.SetSubroutineType(Subroutine::Implementation);
                _localctx->subrout.SetSignature((dynamic_cast<SubroutineContext *>(_localctx)->signature != nullptr ? dynamic_cast<SubroutineContext *>(_localctx)->signature->getText() : ""));
                _localctx->subrout.SetFunction(dynamic_cast<SubroutineContext *>(_localctx)->functionContext->func);
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueListContext ------------------------------------------------------------------

AnyFXParser::ValueListContext::ValueListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::ValueListContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::ValueListContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::ValueListContext::getRuleIndex() const {
  return AnyFXParser::RuleValueList;
}

void AnyFXParser::ValueListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueList(this);
}

void AnyFXParser::ValueListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueList(this);
}

AnyFXParser::ValueListContext* AnyFXParser::valueList() {
  ValueListContext *_localctx = _tracker.createInstance<ValueListContext>(_ctx, getState());
  enterRule(_localctx, 26, AnyFXParser::RuleValueList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    dynamic_cast<ValueListContext *>(_localctx)->first = expression();
     _localctx->valList.AddValue(dynamic_cast<ValueListContext *>(_localctx)->first->tree); 
    setState(309);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(303);
      match(AnyFXParser::CO);
      setState(304);
      dynamic_cast<ValueListContext *>(_localctx)->rest = expression();
       _localctx->valList.AddValue(dynamic_cast<ValueListContext *>(_localctx)->rest->tree); 
      setState(311);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueSingleListContext ------------------------------------------------------------------

AnyFXParser::ValueSingleListContext::ValueSingleListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ValueSingleListContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ValueSingleListContext::getRuleIndex() const {
  return AnyFXParser::RuleValueSingleList;
}

void AnyFXParser::ValueSingleListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueSingleList(this);
}

void AnyFXParser::ValueSingleListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueSingleList(this);
}

AnyFXParser::ValueSingleListContext* AnyFXParser::valueSingleList() {
  ValueSingleListContext *_localctx = _tracker.createInstance<ValueSingleListContext>(_ctx, getState());
  enterRule(_localctx, 28, AnyFXParser::RuleValueSingleList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    dynamic_cast<ValueSingleListContext *>(_localctx)->expressionContext = expression();
     _localctx->valList.AddValue(dynamic_cast<ValueSingleListContext *>(_localctx)->expressionContext->tree); 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

AnyFXParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::VariableContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::VariableContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

tree::TerminalNode* AnyFXParser::VariableContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::VariableContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::VariableContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VariableContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VariableContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

AnyFXParser::AnnotationContext* AnyFXParser::VariableContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::ValueListContext *> AnyFXParser::VariableContext::valueList() {
  return getRuleContexts<AnyFXParser::ValueListContext>();
}

AnyFXParser::ValueListContext* AnyFXParser::VariableContext::valueList(size_t i) {
  return getRuleContext<AnyFXParser::ValueListContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::VariableContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::VariableContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}

AnyFXParser::ValueSingleListContext* AnyFXParser::VariableContext::valueSingleList() {
  return getRuleContext<AnyFXParser::ValueSingleListContext>(0);
}


size_t AnyFXParser::VariableContext::getRuleIndex() const {
  return AnyFXParser::RuleVariable;
}

void AnyFXParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void AnyFXParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

AnyFXParser::VariableContext* AnyFXParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 30, AnyFXParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(323);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59)
      | (1ULL << AnyFXParser::T__60)
      | (1ULL << AnyFXParser::T__61)
      | (1ULL << AnyFXParser::T__62))) != 0)) {
      setState(321);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AnyFXParser::T__3:
        case AnyFXParser::T__4:
        case AnyFXParser::T__5:
        case AnyFXParser::T__6:
        case AnyFXParser::T__7:
        case AnyFXParser::T__8:
        case AnyFXParser::T__9:
        case AnyFXParser::T__10:
        case AnyFXParser::T__11:
        case AnyFXParser::T__12:
        case AnyFXParser::T__13:
        case AnyFXParser::T__14:
        case AnyFXParser::T__15:
        case AnyFXParser::T__16:
        case AnyFXParser::T__17:
        case AnyFXParser::T__18:
        case AnyFXParser::T__19:
        case AnyFXParser::T__20:
        case AnyFXParser::T__21:
        case AnyFXParser::T__22:
        case AnyFXParser::T__23:
        case AnyFXParser::T__24:
        case AnyFXParser::T__25:
        case AnyFXParser::T__26:
        case AnyFXParser::T__27:
        case AnyFXParser::T__28:
        case AnyFXParser::T__29:
        case AnyFXParser::T__30:
        case AnyFXParser::T__31:
        case AnyFXParser::T__32:
        case AnyFXParser::T__33:
        case AnyFXParser::T__34:
        case AnyFXParser::T__35:
        case AnyFXParser::T__36:
        case AnyFXParser::T__37:
        case AnyFXParser::T__38:
        case AnyFXParser::T__39:
        case AnyFXParser::T__40:
        case AnyFXParser::T__41:
        case AnyFXParser::T__42:
        case AnyFXParser::T__43:
        case AnyFXParser::T__44:
        case AnyFXParser::T__45:
        case AnyFXParser::T__46:
        case AnyFXParser::T__47:
        case AnyFXParser::T__48:
        case AnyFXParser::T__49:
        case AnyFXParser::T__50:
        case AnyFXParser::T__51:
        case AnyFXParser::T__52:
        case AnyFXParser::T__53:
        case AnyFXParser::T__54:
        case AnyFXParser::T__55:
        case AnyFXParser::T__56:
        case AnyFXParser::T__57:
        case AnyFXParser::T__58:
        case AnyFXParser::T__59: {
          setState(315);
          dynamic_cast<VariableContext *>(_localctx)->qualifierContext = qualifier();
           _localctx->var.AddQualifier(dynamic_cast<VariableContext *>(_localctx)->qualifierContext->str); 
          break;
        }

        case AnyFXParser::T__60:
        case AnyFXParser::T__61:
        case AnyFXParser::T__62: {
          setState(318);
          dynamic_cast<VariableContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->var.AddQualifierExpression(dynamic_cast<VariableContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(325);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(326);
    dynamic_cast<VariableContext *>(_localctx)->declType = type();
    setState(327);
    dynamic_cast<VariableContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     _localctx->var.SetDataType(dynamic_cast<VariableContext *>(_localctx)->declType->ty); _localctx->var.SetName((dynamic_cast<VariableContext *>(_localctx)->name != nullptr ? dynamic_cast<VariableContext *>(_localctx)->name->getText() : "")); SetupFile(&_localctx->var, _input); 
            
    setState(420);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      setState(329);
      match(AnyFXParser::LL);
      setState(330);
      match(AnyFXParser::RR);
      setState(331);
      match(AnyFXParser::EQ);
       _localctx->var.SetArrayType(Variable::TypedArray); 
      setState(333);
      match(AnyFXParser::LB);
      setState(334);
      dynamic_cast<VariableContext *>(_localctx)->fstType = type();
      setState(335);
      match(AnyFXParser::LP);
      setState(336);
      dynamic_cast<VariableContext *>(_localctx)->fstValue = valueList();
      setState(337);
      match(AnyFXParser::RP);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->fstType->ty, dynamic_cast<VariableContext *>(_localctx)->fstValue->valList); 
      setState(348);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(339);
        match(AnyFXParser::CO);
        setState(340);
        dynamic_cast<VariableContext *>(_localctx)->cntType = type();
        setState(341);
        match(AnyFXParser::LP);
        setState(342);
        dynamic_cast<VariableContext *>(_localctx)->cntValue = valueList();
        setState(343);
        match(AnyFXParser::RP);
         _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->cntType->ty, dynamic_cast<VariableContext *>(_localctx)->cntValue->valList); 
                        
        setState(350);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(351);
      match(AnyFXParser::RB);
      break;
    }

    case 2: {
      setState(353);
      match(AnyFXParser::LL);
      setState(354);
      match(AnyFXParser::RR);
      setState(355);
      match(AnyFXParser::EQ);
       _localctx->var.SetArrayType(Variable::SimpleArray); 
      setState(357);
      match(AnyFXParser::LB);
      setState(358);
      dynamic_cast<VariableContext *>(_localctx)->valList = valueList();
      setState(359);
      match(AnyFXParser::RB);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->valList->valList); 
                  
      break;
    }

    case 3: {
      setState(367); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(362);
                match(AnyFXParser::LL);
                setState(363);
                dynamic_cast<VariableContext *>(_localctx)->asize0 = expression();
                setState(364);
                match(AnyFXParser::RR);
                 _localctx->var.AddSizeExpression(dynamic_cast<VariableContext *>(_localctx)->asize0->tree); _localctx->var.SetArrayType(Variable::SimpleArray); 
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(369); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 4: {
      setState(371);
      match(AnyFXParser::LL);
      setState(372);
      dynamic_cast<VariableContext *>(_localctx)->asize1 = expression();
      setState(373);
      match(AnyFXParser::RR);
       _localctx->var.AddSizeExpression(dynamic_cast<VariableContext *>(_localctx)->asize1->tree); _localctx->var.SetArrayType(Variable::TypedArray); 
                  
      setState(375);
      match(AnyFXParser::LL);
      setState(376);
      match(AnyFXParser::LB);
      setState(377);
      dynamic_cast<VariableContext *>(_localctx)->fstType = type();
      setState(378);
      match(AnyFXParser::LP);
      setState(379);
      dynamic_cast<VariableContext *>(_localctx)->fstValue = valueList();
      setState(380);
      match(AnyFXParser::RP);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->fstType->ty, dynamic_cast<VariableContext *>(_localctx)->fstValue->valList); 
                  
      setState(391);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(382);
        match(AnyFXParser::CO);
        setState(383);
        dynamic_cast<VariableContext *>(_localctx)->cntType = type();
        setState(384);
        match(AnyFXParser::LP);
        setState(385);
        dynamic_cast<VariableContext *>(_localctx)->cntValue = valueList();
        setState(386);
        match(AnyFXParser::RP);
         _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->cntType->ty, dynamic_cast<VariableContext *>(_localctx)->cntValue->valList); 
                        
        setState(393);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(394);
      match(AnyFXParser::RB);
      break;
    }

    case 5: {
      setState(396);
      match(AnyFXParser::LL);
      setState(397);
      dynamic_cast<VariableContext *>(_localctx)->asize2 = expression();
      setState(398);
      match(AnyFXParser::RR);
       _localctx->var.AddSizeExpression(dynamic_cast<VariableContext *>(_localctx)->asize2->tree); _localctx->var.SetArrayType(Variable::SimpleArray); 
                  
      setState(400);
      match(AnyFXParser::EQ);
      setState(401);
      match(AnyFXParser::LB);
      setState(402);
      dynamic_cast<VariableContext *>(_localctx)->valList = valueList();
      setState(403);
      match(AnyFXParser::RB);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->valList->valList); 
      break;
    }

    case 6: {
      setState(406);
      match(AnyFXParser::LL);
      setState(407);
      match(AnyFXParser::RR);
       _localctx->var.SetArrayType(Variable::UnsizedArray); 
      break;
    }

    case 7: {
      setState(409);
      match(AnyFXParser::EQ);
      setState(410);
      dynamic_cast<VariableContext *>(_localctx)->defType = type();
      setState(411);
      match(AnyFXParser::LP);
      setState(412);
      dynamic_cast<VariableContext *>(_localctx)->list2 = valueList();
      setState(413);
      match(AnyFXParser::RP);
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->defType->ty, dynamic_cast<VariableContext *>(_localctx)->list2->valList); 
                  
      break;
    }

    case 8: {
      setState(416);
      match(AnyFXParser::EQ);
      setState(417);
      dynamic_cast<VariableContext *>(_localctx)->list3 = valueSingleList();
       _localctx->var.AddValue(dynamic_cast<VariableContext *>(_localctx)->list3->valList); 
      break;
    }

    }
    setState(425);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(422);
      dynamic_cast<VariableContext *>(_localctx)->annotationContext = annotation();
       _localctx->var.SetAnnotation(dynamic_cast<VariableContext *>(_localctx)->annotationContext->annot); 
    }
    setState(427);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

AnyFXParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::ConstantContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::ConstantContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::ConstantContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

std::vector<AnyFXParser::ValueListContext *> AnyFXParser::ConstantContext::valueList() {
  return getRuleContexts<AnyFXParser::ValueListContext>();
}

AnyFXParser::ValueListContext* AnyFXParser::ConstantContext::valueList(size_t i) {
  return getRuleContext<AnyFXParser::ValueListContext>(i);
}

AnyFXParser::ValueSingleListContext* AnyFXParser::ConstantContext::valueSingleList() {
  return getRuleContext<AnyFXParser::ValueSingleListContext>(0);
}

AnyFXParser::ExpressionContext* AnyFXParser::ConstantContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ConstantContext::getRuleIndex() const {
  return AnyFXParser::RuleConstant;
}

void AnyFXParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void AnyFXParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}

AnyFXParser::ConstantContext* AnyFXParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 32, AnyFXParser::RuleConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    match(AnyFXParser::T__3);
    setState(430);
    dynamic_cast<ConstantContext *>(_localctx)->declType = type();
    setState(431);
    dynamic_cast<ConstantContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     _localctx->cons.SetDataType(dynamic_cast<ConstantContext *>(_localctx)->declType->ty); _localctx->cons.SetName((dynamic_cast<ConstantContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ConstantContext *>(_localctx)->identifierToken->getText() : "")); SetupFile(&_localctx->cons, _input); 
            
    setState(518);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(433);
      match(AnyFXParser::EQ);
      setState(434);
      dynamic_cast<ConstantContext *>(_localctx)->defType = type();
      setState(435);
      match(AnyFXParser::LP);
      setState(436);
      dynamic_cast<ConstantContext *>(_localctx)->sinVal1 = valueList();
      setState(437);
      match(AnyFXParser::RP);
      setState(438);
      match(AnyFXParser::SC);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->defType->ty, dynamic_cast<ConstantContext *>(_localctx)->sinVal1->valList); 
                  
      break;
    }

    case 2: {
      setState(441);
      match(AnyFXParser::EQ);
      setState(442);
      dynamic_cast<ConstantContext *>(_localctx)->sinVal2 = valueSingleList();
      setState(443);
      match(AnyFXParser::SC);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->sinVal2->valList); 
      break;
    }

    case 3: {
      setState(446);
      match(AnyFXParser::LL);
      setState(447);
      match(AnyFXParser::RR);
      setState(448);
      match(AnyFXParser::EQ);
       _localctx->cons.SetArrayType(Constant::TypedArray); 
      setState(450);
      match(AnyFXParser::LB);
      setState(451);
      dynamic_cast<ConstantContext *>(_localctx)->fstType = type();
      setState(452);
      match(AnyFXParser::LP);
      setState(453);
      dynamic_cast<ConstantContext *>(_localctx)->fstValue = valueList();
      setState(454);
      match(AnyFXParser::RP);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->fstType->ty, dynamic_cast<ConstantContext *>(_localctx)->fstValue->valList); 
      setState(465);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(456);
        match(AnyFXParser::CO);
        setState(457);
        dynamic_cast<ConstantContext *>(_localctx)->cntType = type();
        setState(458);
        match(AnyFXParser::LP);
        setState(459);
        dynamic_cast<ConstantContext *>(_localctx)->cntValue = valueList();
        setState(460);
        match(AnyFXParser::RP);
         _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->cntType->ty, dynamic_cast<ConstantContext *>(_localctx)->cntValue->valList); 
                        
        setState(467);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(468);
      match(AnyFXParser::RB);
      setState(469);
      match(AnyFXParser::SC);
      break;
    }

    case 4: {
      setState(471);
      match(AnyFXParser::LL);
      setState(472);
      match(AnyFXParser::RR);
      setState(473);
      match(AnyFXParser::EQ);
       _localctx->cons.SetArrayType(Constant::SimpleArray); 
      setState(475);
      match(AnyFXParser::LB);
      setState(476);
      dynamic_cast<ConstantContext *>(_localctx)->valList = valueList();
      setState(477);
      match(AnyFXParser::RB);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->valList->valList); 
                  
      setState(479);
      match(AnyFXParser::SC);
      break;
    }

    case 5: {
      setState(481);
      match(AnyFXParser::LL);
      setState(482);
      dynamic_cast<ConstantContext *>(_localctx)->asize1 = expression();
      setState(483);
      match(AnyFXParser::RR);
       _localctx->cons.SetSizeExpression(dynamic_cast<ConstantContext *>(_localctx)->asize1->tree); _localctx->cons.SetArrayType(Constant::TypedArray); 
                  
      setState(485);
      match(AnyFXParser::EQ);
      setState(486);
      match(AnyFXParser::LB);
      setState(487);
      dynamic_cast<ConstantContext *>(_localctx)->fstType = type();
      setState(488);
      match(AnyFXParser::LP);
      setState(489);
      dynamic_cast<ConstantContext *>(_localctx)->fstValue = valueList();
      setState(490);
      match(AnyFXParser::RP);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->fstType->ty, dynamic_cast<ConstantContext *>(_localctx)->fstValue->valList); 
                  
      setState(501);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(492);
        match(AnyFXParser::CO);
        setState(493);
        dynamic_cast<ConstantContext *>(_localctx)->cntType = type();
        setState(494);
        match(AnyFXParser::LP);
        setState(495);
        dynamic_cast<ConstantContext *>(_localctx)->cntValue = valueList();
        setState(496);
        match(AnyFXParser::RP);
         _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->cntType->ty, dynamic_cast<ConstantContext *>(_localctx)->cntValue->valList); 
                        
        setState(503);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(504);
      match(AnyFXParser::RB);
      setState(505);
      match(AnyFXParser::SC);
      break;
    }

    case 6: {
      setState(507);
      match(AnyFXParser::LL);
      setState(508);
      dynamic_cast<ConstantContext *>(_localctx)->asize2 = expression();
      setState(509);
      match(AnyFXParser::RR);
       _localctx->cons.SetSizeExpression(dynamic_cast<ConstantContext *>(_localctx)->asize2->tree); _localctx->cons.SetArrayType(Constant::SimpleArray); 
                  
      setState(511);
      match(AnyFXParser::EQ);
      setState(512);
      match(AnyFXParser::LB);
      setState(513);
      dynamic_cast<ConstantContext *>(_localctx)->valList = valueList();
      setState(514);
      match(AnyFXParser::RB);
       _localctx->cons.AddValue(dynamic_cast<ConstantContext *>(_localctx)->valList->valList); 
      setState(516);
      match(AnyFXParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterAttributeContext ------------------------------------------------------------------

AnyFXParser::ParameterAttributeContext::ParameterAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::ParameterAttributeContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}


size_t AnyFXParser::ParameterAttributeContext::getRuleIndex() const {
  return AnyFXParser::RuleParameterAttribute;
}

void AnyFXParser::ParameterAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterAttribute(this);
}

void AnyFXParser::ParameterAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterAttribute(this);
}

AnyFXParser::ParameterAttributeContext* AnyFXParser::parameterAttribute() {
  ParameterAttributeContext *_localctx = _tracker.createInstance<ParameterAttributeContext>(_ctx, getState());
  enterRule(_localctx, 34, AnyFXParser::RuleParameterAttribute);

              dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::NoAttribute;
          

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(520);
    match(AnyFXParser::LL);
    setState(521);
    dynamic_cast<ParameterAttributeContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
    setState(522);
    match(AnyFXParser::RR);

                std::string identifierString((dynamic_cast<ParameterAttributeContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ParameterAttributeContext *>(_localctx)->identifierToken->getText() : ""));

                if (identifierString == "drawinstanceID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::DrawInstance; }
                else if (identifierString == "vertexID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Vertex; }
                else if (identifierString == "primitiveID") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Primitive; }
                else if (identifierString == "invocationID") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Invocation; }
                else if (identifierString == "viewportID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Viewport; }
                else if (identifierString == "rendertargetID") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Rendertarget; }
                else if (identifierString == "innertessellation") 				{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::InnerTessellation; }
                else if (identifierString == "outertessellation") 				{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::OuterTessellation; }
                else if (identifierString == "position") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Position; }
                else if (identifierString == "pointsize") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::PointSize; }
                else if (identifierString == "clipdistance") 					{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::ClipDistance; }
                else if (identifierString == "frontface") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::FrontFace; }
                else if (identifierString == "coordinate") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Coordinate; }
                else if (identifierString == "depth")							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Depth; }
                else if (identifierString == "color0") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color0; }
                else if (identifierString == "color1") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color1; }
                else if (identifierString == "color2") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color2; }
                else if (identifierString == "color3") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color3; }
                else if (identifierString == "color4") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color4; }
                else if (identifierString == "color5") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color5; }
                else if (identifierString == "color6") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color6; }
                else if (identifierString == "color7") 							{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::Color7; }
                else if (identifierString == "workgroupID")						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::WorkGroup; }
                else if (identifierString == "numgroups")						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::NumGroups; }
                else if (identifierString == "localID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::LocalID; }
                else if (identifierString == "localindex") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::LocalIndex; }
                else if (identifierString == "globalID") 						{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::GlobalID; }
                else 															{ dynamic_cast<ParameterAttributeContext *>(_localctx)->attribute =  Parameter::InvalidAttribute; }
            
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

AnyFXParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::TypeContext* AnyFXParser::ParameterContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ParameterContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::ParameterContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::ParameterContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::ParameterContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::ParameterContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::ParameterContext::getRuleIndex() const {
  return AnyFXParser::RuleParameter;
}

void AnyFXParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void AnyFXParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

AnyFXParser::ParameterContext* AnyFXParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 36, AnyFXParser::RuleParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(525);
      match(AnyFXParser::LL);
      setState(526);
      dynamic_cast<ParameterContext *>(_localctx)->attr = match(AnyFXParser::IDENTIFIER);
      setState(527);
      match(AnyFXParser::RR);

                  _localctx->param.SetAttribute((dynamic_cast<ParameterContext *>(_localctx)->attr != nullptr ? dynamic_cast<ParameterContext *>(_localctx)->attr->getText() : ""));
              
      break;
    }

    }
    setState(542);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(531);
      match(AnyFXParser::LL);
      setState(532);
      match(AnyFXParser::T__68);
      setState(533);
      match(AnyFXParser::EQ);
      setState(534);
      match(AnyFXParser::LP);
      setState(535);
      dynamic_cast<ParameterContext *>(_localctx)->feedbackBuffer = expression();
      setState(536);
      match(AnyFXParser::CO);
      setState(537);
      dynamic_cast<ParameterContext *>(_localctx)->feedbackOffset = expression();
      setState(538);
      match(AnyFXParser::RP);
      setState(539);
      match(AnyFXParser::RR);

                  _localctx->param.SetFeedbackBufferExpression(dynamic_cast<ParameterContext *>(_localctx)->feedbackBuffer->tree);
                  _localctx->param.SetFeedbackOffsetExpression(dynamic_cast<ParameterContext *>(_localctx)->feedbackOffset->tree);
              
      break;
    }

    }
    setState(551);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(544);
      match(AnyFXParser::LL);
      setState(545);
      match(AnyFXParser::T__69);
      setState(546);
      match(AnyFXParser::EQ);
      setState(547);
      dynamic_cast<ParameterContext *>(_localctx)->slotExpression = expression();
      setState(548);
      match(AnyFXParser::RR);

                  _localctx->param.SetSlotExpression(dynamic_cast<ParameterContext *>(_localctx)->slotExpression->tree);
              
    }
    setState(558);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59))) != 0)) {
      setState(553);
      dynamic_cast<ParameterContext *>(_localctx)->qualifierContext = qualifier();

                  _localctx->param.AddQualifier(dynamic_cast<ParameterContext *>(_localctx)->qualifierContext->str);
              
      setState(560);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(561);
    dynamic_cast<ParameterContext *>(_localctx)->typeContext = type();
    setState(562);
    dynamic_cast<ParameterContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     _localctx->param.SetDataType(dynamic_cast<ParameterContext *>(_localctx)->typeContext->ty); _localctx->param.SetName((dynamic_cast<ParameterContext *>(_localctx)->name != nullptr ? dynamic_cast<ParameterContext *>(_localctx)->name->getText() : "")); SetupFile(&_localctx->param, _input); 
            
    setState(572);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(564);
      match(AnyFXParser::LL);
      setState(568);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AnyFXParser::T__0

      || _la == AnyFXParser::T__1 || ((((_la - 79) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 79)) & ((1ULL << (AnyFXParser::LP - 79))
        | (1ULL << (AnyFXParser::NOT - 79))
        | (1ULL << (AnyFXParser::SUB_OP - 79))
        | (1ULL << (AnyFXParser::INTEGERLITERAL - 79))
        | (1ULL << (AnyFXParser::FLOATLITERAL - 79))
        | (1ULL << (AnyFXParser::DOUBLELITERAL - 79))
        | (1ULL << (AnyFXParser::HEX - 79))
        | (1ULL << (AnyFXParser::IDENTIFIER - 79)))) != 0)) {
        setState(565);
        dynamic_cast<ParameterContext *>(_localctx)->size = expression();
         _localctx->param.SetSizeExpression(dynamic_cast<ParameterContext *>(_localctx)->size->tree); 
      }
      setState(570);
      match(AnyFXParser::RR);
       _localctx->param.ForceArrayFlag(); 
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

AnyFXParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::ParameterContext *> AnyFXParser::ParameterListContext::parameter() {
  return getRuleContexts<AnyFXParser::ParameterContext>();
}

AnyFXParser::ParameterContext* AnyFXParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<AnyFXParser::ParameterContext>(i);
}


size_t AnyFXParser::ParameterListContext::getRuleIndex() const {
  return AnyFXParser::RuleParameterList;
}

void AnyFXParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void AnyFXParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}

AnyFXParser::ParameterListContext* AnyFXParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 38, AnyFXParser::RuleParameterList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(585);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
      | (1ULL << AnyFXParser::T__4)
      | (1ULL << AnyFXParser::T__5)
      | (1ULL << AnyFXParser::T__6)
      | (1ULL << AnyFXParser::T__7)
      | (1ULL << AnyFXParser::T__8)
      | (1ULL << AnyFXParser::T__9)
      | (1ULL << AnyFXParser::T__10)
      | (1ULL << AnyFXParser::T__11)
      | (1ULL << AnyFXParser::T__12)
      | (1ULL << AnyFXParser::T__13)
      | (1ULL << AnyFXParser::T__14)
      | (1ULL << AnyFXParser::T__15)
      | (1ULL << AnyFXParser::T__16)
      | (1ULL << AnyFXParser::T__17)
      | (1ULL << AnyFXParser::T__18)
      | (1ULL << AnyFXParser::T__19)
      | (1ULL << AnyFXParser::T__20)
      | (1ULL << AnyFXParser::T__21)
      | (1ULL << AnyFXParser::T__22)
      | (1ULL << AnyFXParser::T__23)
      | (1ULL << AnyFXParser::T__24)
      | (1ULL << AnyFXParser::T__25)
      | (1ULL << AnyFXParser::T__26)
      | (1ULL << AnyFXParser::T__27)
      | (1ULL << AnyFXParser::T__28)
      | (1ULL << AnyFXParser::T__29)
      | (1ULL << AnyFXParser::T__30)
      | (1ULL << AnyFXParser::T__31)
      | (1ULL << AnyFXParser::T__32)
      | (1ULL << AnyFXParser::T__33)
      | (1ULL << AnyFXParser::T__34)
      | (1ULL << AnyFXParser::T__35)
      | (1ULL << AnyFXParser::T__36)
      | (1ULL << AnyFXParser::T__37)
      | (1ULL << AnyFXParser::T__38)
      | (1ULL << AnyFXParser::T__39)
      | (1ULL << AnyFXParser::T__40)
      | (1ULL << AnyFXParser::T__41)
      | (1ULL << AnyFXParser::T__42)
      | (1ULL << AnyFXParser::T__43)
      | (1ULL << AnyFXParser::T__44)
      | (1ULL << AnyFXParser::T__45)
      | (1ULL << AnyFXParser::T__46)
      | (1ULL << AnyFXParser::T__47)
      | (1ULL << AnyFXParser::T__48)
      | (1ULL << AnyFXParser::T__49)
      | (1ULL << AnyFXParser::T__50)
      | (1ULL << AnyFXParser::T__51)
      | (1ULL << AnyFXParser::T__52)
      | (1ULL << AnyFXParser::T__53)
      | (1ULL << AnyFXParser::T__54)
      | (1ULL << AnyFXParser::T__55)
      | (1ULL << AnyFXParser::T__56)
      | (1ULL << AnyFXParser::T__57)
      | (1ULL << AnyFXParser::T__58)
      | (1ULL << AnyFXParser::T__59))) != 0) || _la == AnyFXParser::LL

    || _la == AnyFXParser::IDENTIFIER) {
      setState(574);
      dynamic_cast<ParameterListContext *>(_localctx)->firstParam = parameter();
       _localctx->parameters.push_back(dynamic_cast<ParameterListContext *>(_localctx)->firstParam->param); 
      setState(582);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(576);
        match(AnyFXParser::CO);
        setState(577);
        dynamic_cast<ParameterListContext *>(_localctx)->followParam = parameter();
         _localctx->parameters.push_back(dynamic_cast<ParameterListContext *>(_localctx)->followParam->param); 
        setState(584);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionAttributeContext ------------------------------------------------------------------

AnyFXParser::FunctionAttributeContext::FunctionAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::FunctionAttributeContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}


size_t AnyFXParser::FunctionAttributeContext::getRuleIndex() const {
  return AnyFXParser::RuleFunctionAttribute;
}

void AnyFXParser::FunctionAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionAttribute(this);
}

void AnyFXParser::FunctionAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionAttribute(this);
}

AnyFXParser::FunctionAttributeContext* AnyFXParser::functionAttribute() {
  FunctionAttributeContext *_localctx = _tracker.createInstance<FunctionAttributeContext>(_ctx, getState());
  enterRule(_localctx, 40, AnyFXParser::RuleFunctionAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(598);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(587);
      match(AnyFXParser::LL);
      setState(588);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(589);
      match(AnyFXParser::RR);
      setState(590);
      match(AnyFXParser::EQ);
      setState(591);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->expressionContext = expression();

              std::string identifierString((dynamic_cast<FunctionAttributeContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<FunctionAttributeContext *>(_localctx)->flag1->getText() : ""));

              _localctx->attribute.SetExpression(identifierString, dynamic_cast<FunctionAttributeContext *>(_localctx)->expressionContext->tree);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(594);
      match(AnyFXParser::LL);
      setState(595);
      dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3 = match(AnyFXParser::IDENTIFIER);
      setState(596);
      match(AnyFXParser::RR);

              std::string identifierString((dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3 != nullptr ? dynamic_cast<FunctionAttributeContext *>(_localctx)->flag3->getText() : ""));

              _localctx->attribute.SetBool(identifierString, true);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeBlockContext ------------------------------------------------------------------

AnyFXParser::CodeBlockContext::CodeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::CodeBlockContext *> AnyFXParser::CodeBlockContext::codeBlock() {
  return getRuleContexts<AnyFXParser::CodeBlockContext>();
}

AnyFXParser::CodeBlockContext* AnyFXParser::CodeBlockContext::codeBlock(size_t i) {
  return getRuleContext<AnyFXParser::CodeBlockContext>(i);
}


size_t AnyFXParser::CodeBlockContext::getRuleIndex() const {
  return AnyFXParser::RuleCodeBlock;
}

void AnyFXParser::CodeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCodeBlock(this);
}

void AnyFXParser::CodeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCodeBlock(this);
}

AnyFXParser::CodeBlockContext* AnyFXParser::codeBlock() {
  CodeBlockContext *_localctx = _tracker.createInstance<CodeBlockContext>(_ctx, getState());
  enterRule(_localctx, 42, AnyFXParser::RuleCodeBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(609);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::LB: {
        enterOuterAlt(_localctx, 1);
        setState(600);
        match(AnyFXParser::LB);
        setState(604);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AnyFXParser::T__0)
          | (1ULL << AnyFXParser::T__1)
          | (1ULL << AnyFXParser::T__2)
          | (1ULL << AnyFXParser::T__3)
          | (1ULL << AnyFXParser::T__4)
          | (1ULL << AnyFXParser::T__5)
          | (1ULL << AnyFXParser::T__6)
          | (1ULL << AnyFXParser::T__7)
          | (1ULL << AnyFXParser::T__8)
          | (1ULL << AnyFXParser::T__9)
          | (1ULL << AnyFXParser::T__10)
          | (1ULL << AnyFXParser::T__11)
          | (1ULL << AnyFXParser::T__12)
          | (1ULL << AnyFXParser::T__13)
          | (1ULL << AnyFXParser::T__14)
          | (1ULL << AnyFXParser::T__15)
          | (1ULL << AnyFXParser::T__16)
          | (1ULL << AnyFXParser::T__17)
          | (1ULL << AnyFXParser::T__18)
          | (1ULL << AnyFXParser::T__19)
          | (1ULL << AnyFXParser::T__20)
          | (1ULL << AnyFXParser::T__21)
          | (1ULL << AnyFXParser::T__22)
          | (1ULL << AnyFXParser::T__23)
          | (1ULL << AnyFXParser::T__24)
          | (1ULL << AnyFXParser::T__25)
          | (1ULL << AnyFXParser::T__26)
          | (1ULL << AnyFXParser::T__27)
          | (1ULL << AnyFXParser::T__28)
          | (1ULL << AnyFXParser::T__29)
          | (1ULL << AnyFXParser::T__30)
          | (1ULL << AnyFXParser::T__31)
          | (1ULL << AnyFXParser::T__32)
          | (1ULL << AnyFXParser::T__33)
          | (1ULL << AnyFXParser::T__34)
          | (1ULL << AnyFXParser::T__35)
          | (1ULL << AnyFXParser::T__36)
          | (1ULL << AnyFXParser::T__37)
          | (1ULL << AnyFXParser::T__38)
          | (1ULL << AnyFXParser::T__39)
          | (1ULL << AnyFXParser::T__40)
          | (1ULL << AnyFXParser::T__41)
          | (1ULL << AnyFXParser::T__42)
          | (1ULL << AnyFXParser::T__43)
          | (1ULL << AnyFXParser::T__44)
          | (1ULL << AnyFXParser::T__45)
          | (1ULL << AnyFXParser::T__46)
          | (1ULL << AnyFXParser::T__47)
          | (1ULL << AnyFXParser::T__48)
          | (1ULL << AnyFXParser::T__49)
          | (1ULL << AnyFXParser::T__50)
          | (1ULL << AnyFXParser::T__51)
          | (1ULL << AnyFXParser::T__52)
          | (1ULL << AnyFXParser::T__53)
          | (1ULL << AnyFXParser::T__54)
          | (1ULL << AnyFXParser::T__55)
          | (1ULL << AnyFXParser::T__56)
          | (1ULL << AnyFXParser::T__57)
          | (1ULL << AnyFXParser::T__58)
          | (1ULL << AnyFXParser::T__59)
          | (1ULL << AnyFXParser::T__60)
          | (1ULL << AnyFXParser::T__61)
          | (1ULL << AnyFXParser::T__62))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 64)) & ((1ULL << (AnyFXParser::T__63 - 64))
          | (1ULL << (AnyFXParser::T__64 - 64))
          | (1ULL << (AnyFXParser::T__65 - 64))
          | (1ULL << (AnyFXParser::T__66 - 64))
          | (1ULL << (AnyFXParser::T__67 - 64))
          | (1ULL << (AnyFXParser::T__68 - 64))
          | (1ULL << (AnyFXParser::T__69 - 64))
          | (1ULL << (AnyFXParser::T__70 - 64))
          | (1ULL << (AnyFXParser::T__71 - 64))
          | (1ULL << (AnyFXParser::T__72 - 64))
          | (1ULL << (AnyFXParser::T__73 - 64))
          | (1ULL << (AnyFXParser::T__74 - 64))
          | (1ULL << (AnyFXParser::SC - 64))
          | (1ULL << (AnyFXParser::CO - 64))
          | (1ULL << (AnyFXParser::COL - 64))
          | (1ULL << (AnyFXParser::LP - 64))
          | (1ULL << (AnyFXParser::RP - 64))
          | (1ULL << (AnyFXParser::LB - 64))
          | (1ULL << (AnyFXParser::LL - 64))
          | (1ULL << (AnyFXParser::RR - 64))
          | (1ULL << (AnyFXParser::DOT - 64))
          | (1ULL << (AnyFXParser::NOT - 64))
          | (1ULL << (AnyFXParser::EQ - 64))
          | (1ULL << (AnyFXParser::QO - 64))
          | (1ULL << (AnyFXParser::QU - 64))
          | (1ULL << (AnyFXParser::AND - 64))
          | (1ULL << (AnyFXParser::ANDSET - 64))
          | (1ULL << (AnyFXParser::OR - 64))
          | (1ULL << (AnyFXParser::ORSET - 64))
          | (1ULL << (AnyFXParser::XOR - 64))
          | (1ULL << (AnyFXParser::XORSET - 64))
          | (1ULL << (AnyFXParser::CONNJUGATE - 64))
          | (1ULL << (AnyFXParser::Q - 64))
          | (1ULL << (AnyFXParser::NU - 64))
          | (1ULL << (AnyFXParser::FORWARDSLASH - 64))
          | (1ULL << (AnyFXParser::LESS - 64))
          | (1ULL << (AnyFXParser::LESSEQ - 64))
          | (1ULL << (AnyFXParser::GREATER - 64))
          | (1ULL << (AnyFXParser::GREATEREQ - 64))
          | (1ULL << (AnyFXParser::LOGICEQ - 64))
          | (1ULL << (AnyFXParser::NOTEQ - 64))
          | (1ULL << (AnyFXParser::LOGICAND - 64))
          | (1ULL << (AnyFXParser::LOGICOR - 64))
          | (1ULL << (AnyFXParser::MOD - 64))
          | (1ULL << (AnyFXParser::UNDERSC - 64))
          | (1ULL << (AnyFXParser::ADD_OP - 64))
          | (1ULL << (AnyFXParser::SUB_OP - 64))
          | (1ULL << (AnyFXParser::DIV_OP - 64))
          | (1ULL << (AnyFXParser::MUL_OP - 64))
          | (1ULL << (AnyFXParser::INTEGERLITERAL - 64))
          | (1ULL << (AnyFXParser::COMMENT - 64))
          | (1ULL << (AnyFXParser::ML_COMMENT - 64))
          | (1ULL << (AnyFXParser::FLOATLITERAL - 64))
          | (1ULL << (AnyFXParser::EXPONENT - 64))
          | (1ULL << (AnyFXParser::DOUBLELITERAL - 64))
          | (1ULL << (AnyFXParser::HEX - 64))
          | (1ULL << (AnyFXParser::IDENTIFIER - 64))
          | (1ULL << (AnyFXParser::WS - 64)))) != 0)) {
          setState(601);
          codeBlock();
          setState(606);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(607);
        match(AnyFXParser::RB);
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1:
      case AnyFXParser::T__2:
      case AnyFXParser::T__3:
      case AnyFXParser::T__4:
      case AnyFXParser::T__5:
      case AnyFXParser::T__6:
      case AnyFXParser::T__7:
      case AnyFXParser::T__8:
      case AnyFXParser::T__9:
      case AnyFXParser::T__10:
      case AnyFXParser::T__11:
      case AnyFXParser::T__12:
      case AnyFXParser::T__13:
      case AnyFXParser::T__14:
      case AnyFXParser::T__15:
      case AnyFXParser::T__16:
      case AnyFXParser::T__17:
      case AnyFXParser::T__18:
      case AnyFXParser::T__19:
      case AnyFXParser::T__20:
      case AnyFXParser::T__21:
      case AnyFXParser::T__22:
      case AnyFXParser::T__23:
      case AnyFXParser::T__24:
      case AnyFXParser::T__25:
      case AnyFXParser::T__26:
      case AnyFXParser::T__27:
      case AnyFXParser::T__28:
      case AnyFXParser::T__29:
      case AnyFXParser::T__30:
      case AnyFXParser::T__31:
      case AnyFXParser::T__32:
      case AnyFXParser::T__33:
      case AnyFXParser::T__34:
      case AnyFXParser::T__35:
      case AnyFXParser::T__36:
      case AnyFXParser::T__37:
      case AnyFXParser::T__38:
      case AnyFXParser::T__39:
      case AnyFXParser::T__40:
      case AnyFXParser::T__41:
      case AnyFXParser::T__42:
      case AnyFXParser::T__43:
      case AnyFXParser::T__44:
      case AnyFXParser::T__45:
      case AnyFXParser::T__46:
      case AnyFXParser::T__47:
      case AnyFXParser::T__48:
      case AnyFXParser::T__49:
      case AnyFXParser::T__50:
      case AnyFXParser::T__51:
      case AnyFXParser::T__52:
      case AnyFXParser::T__53:
      case AnyFXParser::T__54:
      case AnyFXParser::T__55:
      case AnyFXParser::T__56:
      case AnyFXParser::T__57:
      case AnyFXParser::T__58:
      case AnyFXParser::T__59:
      case AnyFXParser::T__60:
      case AnyFXParser::T__61:
      case AnyFXParser::T__62:
      case AnyFXParser::T__63:
      case AnyFXParser::T__64:
      case AnyFXParser::T__65:
      case AnyFXParser::T__66:
      case AnyFXParser::T__67:
      case AnyFXParser::T__68:
      case AnyFXParser::T__69:
      case AnyFXParser::T__70:
      case AnyFXParser::T__71:
      case AnyFXParser::T__72:
      case AnyFXParser::T__73:
      case AnyFXParser::T__74:
      case AnyFXParser::SC:
      case AnyFXParser::CO:
      case AnyFXParser::COL:
      case AnyFXParser::LP:
      case AnyFXParser::RP:
      case AnyFXParser::LL:
      case AnyFXParser::RR:
      case AnyFXParser::DOT:
      case AnyFXParser::NOT:
      case AnyFXParser::EQ:
      case AnyFXParser::QO:
      case AnyFXParser::QU:
      case AnyFXParser::AND:
      case AnyFXParser::ANDSET:
      case AnyFXParser::OR:
      case AnyFXParser::ORSET:
      case AnyFXParser::XOR:
      case AnyFXParser::XORSET:
      case AnyFXParser::CONNJUGATE:
      case AnyFXParser::Q:
      case AnyFXParser::NU:
      case AnyFXParser::FORWARDSLASH:
      case AnyFXParser::LESS:
      case AnyFXParser::LESSEQ:
      case AnyFXParser::GREATER:
      case AnyFXParser::GREATEREQ:
      case AnyFXParser::LOGICEQ:
      case AnyFXParser::NOTEQ:
      case AnyFXParser::LOGICAND:
      case AnyFXParser::LOGICOR:
      case AnyFXParser::MOD:
      case AnyFXParser::UNDERSC:
      case AnyFXParser::ADD_OP:
      case AnyFXParser::SUB_OP:
      case AnyFXParser::DIV_OP:
      case AnyFXParser::MUL_OP:
      case AnyFXParser::INTEGERLITERAL:
      case AnyFXParser::COMMENT:
      case AnyFXParser::ML_COMMENT:
      case AnyFXParser::FLOATLITERAL:
      case AnyFXParser::EXPONENT:
      case AnyFXParser::DOUBLELITERAL:
      case AnyFXParser::HEX:
      case AnyFXParser::IDENTIFIER:
      case AnyFXParser::WS: {
        enterOuterAlt(_localctx, 2);
        setState(608);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::LB

        || _la == AnyFXParser::RB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AnyFXParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::TypeContext* AnyFXParser::FunctionContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

tree::TerminalNode* AnyFXParser::FunctionContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::ParameterListContext* AnyFXParser::FunctionContext::parameterList() {
  return getRuleContext<AnyFXParser::ParameterListContext>(0);
}

AnyFXParser::CodeBlockContext* AnyFXParser::FunctionContext::codeBlock() {
  return getRuleContext<AnyFXParser::CodeBlockContext>(0);
}

std::vector<AnyFXParser::FunctionAttributeContext *> AnyFXParser::FunctionContext::functionAttribute() {
  return getRuleContexts<AnyFXParser::FunctionAttributeContext>();
}

AnyFXParser::FunctionAttributeContext* AnyFXParser::FunctionContext::functionAttribute(size_t i) {
  return getRuleContext<AnyFXParser::FunctionAttributeContext>(i);
}


size_t AnyFXParser::FunctionContext::getRuleIndex() const {
  return AnyFXParser::RuleFunction;
}

void AnyFXParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AnyFXParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AnyFXParser::FunctionContext* AnyFXParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 44, AnyFXParser::RuleFunction);

              Token* startToken = nullptr;
              Token* endToken = nullptr;
          
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(616);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LL) {
      setState(611);
      dynamic_cast<FunctionContext *>(_localctx)->functionAttributeContext = functionAttribute();
       _localctx->func.ConsumeAttribute(dynamic_cast<FunctionContext *>(_localctx)->functionAttributeContext->attribute); 
      setState(618);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(621);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::T__70) {
      setState(619);
      match(AnyFXParser::T__70);
       _localctx->func.SetShader(true); 
    }
    setState(623);
    dynamic_cast<FunctionContext *>(_localctx)->typeContext = type();
    setState(624);
    dynamic_cast<FunctionContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     UpdateLine(_input, -2); _localctx->func.SetFunctionLine(this->lineOffset); SetupFile(&_localctx->func, _input, false);  
    setState(626);
    match(AnyFXParser::LP);
    setState(627);
    dynamic_cast<FunctionContext *>(_localctx)->parameterListContext = parameterList();
    setState(628);
    match(AnyFXParser::RP);

                // the code block will be after the next right bracket
                startToken = _input->LT(2);

                UpdateLine(_input, 2);
                _localctx->func.SetCodeLine(this->lineOffset);
            
    setState(630);
    codeBlock();

                // save last token
                endToken = _input->LT(-2);

                // get all text inbetween the two tokens
                antlr4::misc::Interval interval;
                interval.a = startToken->getTokenIndex();
                interval.b = endToken->getTokenIndex();
                std::string code = _input->getText(interval);

                // get all text inbetween the two tokens
                if (code.length() > 0) 
                    _localctx->func.SetCode(code);
            
     _localctx->func.SetName((dynamic_cast<FunctionContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<FunctionContext *>(_localctx)->identifierToken->getText() : "")); _localctx->func.SetReturnType(dynamic_cast<FunctionContext *>(_localctx)->typeContext->ty); _localctx->func.SetParameters(dynamic_cast<FunctionContext *>(_localctx)->parameterListContext->parameters); 
            
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlendStateRowContext ------------------------------------------------------------------

AnyFXParser::BlendStateRowContext::BlendStateRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::BlendStateRowContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::BlendStateRowContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::BlendStateRowContext::getRuleIndex() const {
  return AnyFXParser::RuleBlendStateRow;
}

void AnyFXParser::BlendStateRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlendStateRow(this);
}

void AnyFXParser::BlendStateRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlendStateRow(this);
}

AnyFXParser::BlendStateRowContext* AnyFXParser::blendStateRow() {
  BlendStateRowContext *_localctx = _tracker.createInstance<BlendStateRowContext>(_ctx, getState());
  enterRule(_localctx, 46, AnyFXParser::RuleBlendStateRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(634);
    dynamic_cast<BlendStateRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
    setState(635);
    match(AnyFXParser::LL);
    setState(636);
    dynamic_cast<BlendStateRowContext *>(_localctx)->index2 = expression();
    setState(637);
    match(AnyFXParser::RR);
    setState(638);
    match(AnyFXParser::EQ);
    setState(639);
    dynamic_cast<BlendStateRowContext *>(_localctx)->value = expression();
    setState(640);
    match(AnyFXParser::SC);

            std::string flag((dynamic_cast<BlendStateRowContext *>(_localctx)->flag2 != nullptr ? dynamic_cast<BlendStateRowContext *>(_localctx)->flag2->getText() : ""));
            _localctx->row.SetExpression(dynamic_cast<BlendStateRowContext *>(_localctx)->index2->tree, flag, dynamic_cast<BlendStateRowContext *>(_localctx)->value->tree);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RenderStateRowContext ------------------------------------------------------------------

AnyFXParser::RenderStateRowContext::RenderStateRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::RenderStateRowContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::RenderStateRowContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}


size_t AnyFXParser::RenderStateRowContext::getRuleIndex() const {
  return AnyFXParser::RuleRenderStateRow;
}

void AnyFXParser::RenderStateRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenderStateRow(this);
}

void AnyFXParser::RenderStateRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenderStateRow(this);
}

AnyFXParser::RenderStateRowContext* AnyFXParser::renderStateRow() {
  RenderStateRowContext *_localctx = _tracker.createInstance<RenderStateRowContext>(_ctx, getState());
  enterRule(_localctx, 48, AnyFXParser::RuleRenderStateRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(643);
    dynamic_cast<RenderStateRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
    setState(644);
    match(AnyFXParser::EQ);
    setState(645);
    dynamic_cast<RenderStateRowContext *>(_localctx)->expressionContext = expression();
    setState(646);
    match(AnyFXParser::SC);

            std::string flag((dynamic_cast<RenderStateRowContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<RenderStateRowContext *>(_localctx)->flag1->getText() : ""));
            _localctx->row.SetExpression(flag, dynamic_cast<RenderStateRowContext *>(_localctx)->expressionContext->tree);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RenderStateContext ------------------------------------------------------------------

AnyFXParser::RenderStateContext::RenderStateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::RenderStateContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::RenderStateRowContext *> AnyFXParser::RenderStateContext::renderStateRow() {
  return getRuleContexts<AnyFXParser::RenderStateRowContext>();
}

AnyFXParser::RenderStateRowContext* AnyFXParser::RenderStateContext::renderStateRow(size_t i) {
  return getRuleContext<AnyFXParser::RenderStateRowContext>(i);
}

std::vector<AnyFXParser::BlendStateRowContext *> AnyFXParser::RenderStateContext::blendStateRow() {
  return getRuleContexts<AnyFXParser::BlendStateRowContext>();
}

AnyFXParser::BlendStateRowContext* AnyFXParser::RenderStateContext::blendStateRow(size_t i) {
  return getRuleContext<AnyFXParser::BlendStateRowContext>(i);
}


size_t AnyFXParser::RenderStateContext::getRuleIndex() const {
  return AnyFXParser::RuleRenderState;
}

void AnyFXParser::RenderStateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenderState(this);
}

void AnyFXParser::RenderStateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenderState(this);
}

AnyFXParser::RenderStateContext* AnyFXParser::renderState() {
  RenderStateContext *_localctx = _tracker.createInstance<RenderStateContext>(_ctx, getState());
  enterRule(_localctx, 50, AnyFXParser::RuleRenderState);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(672);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(649);
      match(AnyFXParser::T__71);
      setState(650);
      dynamic_cast<RenderStateContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->state, _input); 
      setState(652);
      match(AnyFXParser::SC);
       _localctx->state.SetName((dynamic_cast<RenderStateContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<RenderStateContext *>(_localctx)->identifierToken->getText() : "")); 
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(654);
      match(AnyFXParser::T__71);
      setState(655);
      dynamic_cast<RenderStateContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->state, _input); 
      setState(657);
      match(AnyFXParser::LB);
       _localctx->state.SetName((dynamic_cast<RenderStateContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<RenderStateContext *>(_localctx)->identifierToken->getText() : "")); 
              
      setState(667);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(665);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
        case 1: {
          setState(659);
          dynamic_cast<RenderStateContext *>(_localctx)->renderStateRowContext = renderStateRow();
           _localctx->state.ConsumeRenderRow(dynamic_cast<RenderStateContext *>(_localctx)->renderStateRowContext->row); 
          break;
        }

        case 2: {
          setState(662);
          dynamic_cast<RenderStateContext *>(_localctx)->blendStateRowContext = blendStateRow();
           _localctx->state.ConsumeBlendRow(dynamic_cast<RenderStateContext *>(_localctx)->blendStateRowContext->row); 
          break;
        }

        }
        setState(669);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(670);
      match(AnyFXParser::RB);
      setState(671);
      match(AnyFXParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SamplerContext ------------------------------------------------------------------

AnyFXParser::SamplerContext::SamplerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::SamplerContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

std::vector<AnyFXParser::QualifierContext *> AnyFXParser::SamplerContext::qualifier() {
  return getRuleContexts<AnyFXParser::QualifierContext>();
}

AnyFXParser::QualifierContext* AnyFXParser::SamplerContext::qualifier(size_t i) {
  return getRuleContext<AnyFXParser::QualifierContext>(i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::SamplerContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::SamplerContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

std::vector<AnyFXParser::SamplerRowContext *> AnyFXParser::SamplerContext::samplerRow() {
  return getRuleContexts<AnyFXParser::SamplerRowContext>();
}

AnyFXParser::SamplerRowContext* AnyFXParser::SamplerContext::samplerRow(size_t i) {
  return getRuleContext<AnyFXParser::SamplerRowContext>(i);
}


size_t AnyFXParser::SamplerContext::getRuleIndex() const {
  return AnyFXParser::RuleSampler;
}

void AnyFXParser::SamplerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSampler(this);
}

void AnyFXParser::SamplerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSampler(this);
}

AnyFXParser::SamplerContext* AnyFXParser::sampler() {
  SamplerContext *_localctx = _tracker.createInstance<SamplerContext>(_ctx, getState());
  enterRule(_localctx, 52, AnyFXParser::RuleSampler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(716);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(682);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
        | (1ULL << AnyFXParser::T__4)
        | (1ULL << AnyFXParser::T__5)
        | (1ULL << AnyFXParser::T__6)
        | (1ULL << AnyFXParser::T__7)
        | (1ULL << AnyFXParser::T__8)
        | (1ULL << AnyFXParser::T__9)
        | (1ULL << AnyFXParser::T__10)
        | (1ULL << AnyFXParser::T__11)
        | (1ULL << AnyFXParser::T__12)
        | (1ULL << AnyFXParser::T__13)
        | (1ULL << AnyFXParser::T__14)
        | (1ULL << AnyFXParser::T__15)
        | (1ULL << AnyFXParser::T__16)
        | (1ULL << AnyFXParser::T__17)
        | (1ULL << AnyFXParser::T__18)
        | (1ULL << AnyFXParser::T__19)
        | (1ULL << AnyFXParser::T__20)
        | (1ULL << AnyFXParser::T__21)
        | (1ULL << AnyFXParser::T__22)
        | (1ULL << AnyFXParser::T__23)
        | (1ULL << AnyFXParser::T__24)
        | (1ULL << AnyFXParser::T__25)
        | (1ULL << AnyFXParser::T__26)
        | (1ULL << AnyFXParser::T__27)
        | (1ULL << AnyFXParser::T__28)
        | (1ULL << AnyFXParser::T__29)
        | (1ULL << AnyFXParser::T__30)
        | (1ULL << AnyFXParser::T__31)
        | (1ULL << AnyFXParser::T__32)
        | (1ULL << AnyFXParser::T__33)
        | (1ULL << AnyFXParser::T__34)
        | (1ULL << AnyFXParser::T__35)
        | (1ULL << AnyFXParser::T__36)
        | (1ULL << AnyFXParser::T__37)
        | (1ULL << AnyFXParser::T__38)
        | (1ULL << AnyFXParser::T__39)
        | (1ULL << AnyFXParser::T__40)
        | (1ULL << AnyFXParser::T__41)
        | (1ULL << AnyFXParser::T__42)
        | (1ULL << AnyFXParser::T__43)
        | (1ULL << AnyFXParser::T__44)
        | (1ULL << AnyFXParser::T__45)
        | (1ULL << AnyFXParser::T__46)
        | (1ULL << AnyFXParser::T__47)
        | (1ULL << AnyFXParser::T__48)
        | (1ULL << AnyFXParser::T__49)
        | (1ULL << AnyFXParser::T__50)
        | (1ULL << AnyFXParser::T__51)
        | (1ULL << AnyFXParser::T__52)
        | (1ULL << AnyFXParser::T__53)
        | (1ULL << AnyFXParser::T__54)
        | (1ULL << AnyFXParser::T__55)
        | (1ULL << AnyFXParser::T__56)
        | (1ULL << AnyFXParser::T__57)
        | (1ULL << AnyFXParser::T__58)
        | (1ULL << AnyFXParser::T__59)
        | (1ULL << AnyFXParser::T__60)
        | (1ULL << AnyFXParser::T__61)
        | (1ULL << AnyFXParser::T__62))) != 0)) {
        setState(680);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case AnyFXParser::T__3:
          case AnyFXParser::T__4:
          case AnyFXParser::T__5:
          case AnyFXParser::T__6:
          case AnyFXParser::T__7:
          case AnyFXParser::T__8:
          case AnyFXParser::T__9:
          case AnyFXParser::T__10:
          case AnyFXParser::T__11:
          case AnyFXParser::T__12:
          case AnyFXParser::T__13:
          case AnyFXParser::T__14:
          case AnyFXParser::T__15:
          case AnyFXParser::T__16:
          case AnyFXParser::T__17:
          case AnyFXParser::T__18:
          case AnyFXParser::T__19:
          case AnyFXParser::T__20:
          case AnyFXParser::T__21:
          case AnyFXParser::T__22:
          case AnyFXParser::T__23:
          case AnyFXParser::T__24:
          case AnyFXParser::T__25:
          case AnyFXParser::T__26:
          case AnyFXParser::T__27:
          case AnyFXParser::T__28:
          case AnyFXParser::T__29:
          case AnyFXParser::T__30:
          case AnyFXParser::T__31:
          case AnyFXParser::T__32:
          case AnyFXParser::T__33:
          case AnyFXParser::T__34:
          case AnyFXParser::T__35:
          case AnyFXParser::T__36:
          case AnyFXParser::T__37:
          case AnyFXParser::T__38:
          case AnyFXParser::T__39:
          case AnyFXParser::T__40:
          case AnyFXParser::T__41:
          case AnyFXParser::T__42:
          case AnyFXParser::T__43:
          case AnyFXParser::T__44:
          case AnyFXParser::T__45:
          case AnyFXParser::T__46:
          case AnyFXParser::T__47:
          case AnyFXParser::T__48:
          case AnyFXParser::T__49:
          case AnyFXParser::T__50:
          case AnyFXParser::T__51:
          case AnyFXParser::T__52:
          case AnyFXParser::T__53:
          case AnyFXParser::T__54:
          case AnyFXParser::T__55:
          case AnyFXParser::T__56:
          case AnyFXParser::T__57:
          case AnyFXParser::T__58:
          case AnyFXParser::T__59: {
            setState(674);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierContext = qualifier();
             _localctx->samp.AddQualifier(dynamic_cast<SamplerContext *>(_localctx)->qualifierContext->str); 
            break;
          }

          case AnyFXParser::T__60:
          case AnyFXParser::T__61:
          case AnyFXParser::T__62: {
            setState(677);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
             _localctx->samp.AddQualifierExpression(dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext->q); 
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(684);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(685);
      match(AnyFXParser::T__72);
      setState(686);
      dynamic_cast<SamplerContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->samp, _input); 
      setState(688);
      match(AnyFXParser::SC);
       _localctx->samp.SetName((dynamic_cast<SamplerContext *>(_localctx)->name != nullptr ? dynamic_cast<SamplerContext *>(_localctx)->name->getText() : "")); 
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(698);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AnyFXParser::T__3)
        | (1ULL << AnyFXParser::T__4)
        | (1ULL << AnyFXParser::T__5)
        | (1ULL << AnyFXParser::T__6)
        | (1ULL << AnyFXParser::T__7)
        | (1ULL << AnyFXParser::T__8)
        | (1ULL << AnyFXParser::T__9)
        | (1ULL << AnyFXParser::T__10)
        | (1ULL << AnyFXParser::T__11)
        | (1ULL << AnyFXParser::T__12)
        | (1ULL << AnyFXParser::T__13)
        | (1ULL << AnyFXParser::T__14)
        | (1ULL << AnyFXParser::T__15)
        | (1ULL << AnyFXParser::T__16)
        | (1ULL << AnyFXParser::T__17)
        | (1ULL << AnyFXParser::T__18)
        | (1ULL << AnyFXParser::T__19)
        | (1ULL << AnyFXParser::T__20)
        | (1ULL << AnyFXParser::T__21)
        | (1ULL << AnyFXParser::T__22)
        | (1ULL << AnyFXParser::T__23)
        | (1ULL << AnyFXParser::T__24)
        | (1ULL << AnyFXParser::T__25)
        | (1ULL << AnyFXParser::T__26)
        | (1ULL << AnyFXParser::T__27)
        | (1ULL << AnyFXParser::T__28)
        | (1ULL << AnyFXParser::T__29)
        | (1ULL << AnyFXParser::T__30)
        | (1ULL << AnyFXParser::T__31)
        | (1ULL << AnyFXParser::T__32)
        | (1ULL << AnyFXParser::T__33)
        | (1ULL << AnyFXParser::T__34)
        | (1ULL << AnyFXParser::T__35)
        | (1ULL << AnyFXParser::T__36)
        | (1ULL << AnyFXParser::T__37)
        | (1ULL << AnyFXParser::T__38)
        | (1ULL << AnyFXParser::T__39)
        | (1ULL << AnyFXParser::T__40)
        | (1ULL << AnyFXParser::T__41)
        | (1ULL << AnyFXParser::T__42)
        | (1ULL << AnyFXParser::T__43)
        | (1ULL << AnyFXParser::T__44)
        | (1ULL << AnyFXParser::T__45)
        | (1ULL << AnyFXParser::T__46)
        | (1ULL << AnyFXParser::T__47)
        | (1ULL << AnyFXParser::T__48)
        | (1ULL << AnyFXParser::T__49)
        | (1ULL << AnyFXParser::T__50)
        | (1ULL << AnyFXParser::T__51)
        | (1ULL << AnyFXParser::T__52)
        | (1ULL << AnyFXParser::T__53)
        | (1ULL << AnyFXParser::T__54)
        | (1ULL << AnyFXParser::T__55)
        | (1ULL << AnyFXParser::T__56)
        | (1ULL << AnyFXParser::T__57)
        | (1ULL << AnyFXParser::T__58)
        | (1ULL << AnyFXParser::T__59)
        | (1ULL << AnyFXParser::T__60)
        | (1ULL << AnyFXParser::T__61)
        | (1ULL << AnyFXParser::T__62))) != 0)) {
        setState(696);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case AnyFXParser::T__3:
          case AnyFXParser::T__4:
          case AnyFXParser::T__5:
          case AnyFXParser::T__6:
          case AnyFXParser::T__7:
          case AnyFXParser::T__8:
          case AnyFXParser::T__9:
          case AnyFXParser::T__10:
          case AnyFXParser::T__11:
          case AnyFXParser::T__12:
          case AnyFXParser::T__13:
          case AnyFXParser::T__14:
          case AnyFXParser::T__15:
          case AnyFXParser::T__16:
          case AnyFXParser::T__17:
          case AnyFXParser::T__18:
          case AnyFXParser::T__19:
          case AnyFXParser::T__20:
          case AnyFXParser::T__21:
          case AnyFXParser::T__22:
          case AnyFXParser::T__23:
          case AnyFXParser::T__24:
          case AnyFXParser::T__25:
          case AnyFXParser::T__26:
          case AnyFXParser::T__27:
          case AnyFXParser::T__28:
          case AnyFXParser::T__29:
          case AnyFXParser::T__30:
          case AnyFXParser::T__31:
          case AnyFXParser::T__32:
          case AnyFXParser::T__33:
          case AnyFXParser::T__34:
          case AnyFXParser::T__35:
          case AnyFXParser::T__36:
          case AnyFXParser::T__37:
          case AnyFXParser::T__38:
          case AnyFXParser::T__39:
          case AnyFXParser::T__40:
          case AnyFXParser::T__41:
          case AnyFXParser::T__42:
          case AnyFXParser::T__43:
          case AnyFXParser::T__44:
          case AnyFXParser::T__45:
          case AnyFXParser::T__46:
          case AnyFXParser::T__47:
          case AnyFXParser::T__48:
          case AnyFXParser::T__49:
          case AnyFXParser::T__50:
          case AnyFXParser::T__51:
          case AnyFXParser::T__52:
          case AnyFXParser::T__53:
          case AnyFXParser::T__54:
          case AnyFXParser::T__55:
          case AnyFXParser::T__56:
          case AnyFXParser::T__57:
          case AnyFXParser::T__58:
          case AnyFXParser::T__59: {
            setState(690);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierContext = qualifier();
             _localctx->samp.AddQualifier(dynamic_cast<SamplerContext *>(_localctx)->qualifierContext->str); 
            break;
          }

          case AnyFXParser::T__60:
          case AnyFXParser::T__61:
          case AnyFXParser::T__62: {
            setState(693);
            dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
             _localctx->samp.AddQualifierExpression(dynamic_cast<SamplerContext *>(_localctx)->qualifierExpressionContext->q); 
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(700);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(701);
      match(AnyFXParser::T__72);
      setState(702);
      dynamic_cast<SamplerContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(&_localctx->samp, _input); 
       _localctx->samp.SetName((dynamic_cast<SamplerContext *>(_localctx)->name != nullptr ? dynamic_cast<SamplerContext *>(_localctx)->name->getText() : "")); 
              
      setState(705);
      match(AnyFXParser::LB);
      setState(711);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(706);
        dynamic_cast<SamplerContext *>(_localctx)->samplerRowContext = samplerRow();
         _localctx->samp.ConsumeRow(dynamic_cast<SamplerContext *>(_localctx)->samplerRowContext->row); 
        setState(713);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(714);
      match(AnyFXParser::RB);
      setState(715);
      match(AnyFXParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SamplerTextureListContext ------------------------------------------------------------------

AnyFXParser::SamplerTextureListContext::SamplerTextureListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::SamplerTextureListContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::SamplerTextureListContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}


size_t AnyFXParser::SamplerTextureListContext::getRuleIndex() const {
  return AnyFXParser::RuleSamplerTextureList;
}

void AnyFXParser::SamplerTextureListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSamplerTextureList(this);
}

void AnyFXParser::SamplerTextureListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSamplerTextureList(this);
}

AnyFXParser::SamplerTextureListContext* AnyFXParser::samplerTextureList() {
  SamplerTextureListContext *_localctx = _tracker.createInstance<SamplerTextureListContext>(_ctx, getState());
  enterRule(_localctx, 54, AnyFXParser::RuleSamplerTextureList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(718);
    dynamic_cast<SamplerTextureListContext *>(_localctx)->firstItem = match(AnyFXParser::IDENTIFIER);
     _localctx->list.AddTexture((dynamic_cast<SamplerTextureListContext *>(_localctx)->firstItem != nullptr ? dynamic_cast<SamplerTextureListContext *>(_localctx)->firstItem->getText() : "")); 
    setState(725);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(720);
      match(AnyFXParser::CO);
      setState(721);
      dynamic_cast<SamplerTextureListContext *>(_localctx)->nextItem = match(AnyFXParser::IDENTIFIER);
       _localctx->list.AddTexture((dynamic_cast<SamplerTextureListContext *>(_localctx)->nextItem != nullptr ? dynamic_cast<SamplerTextureListContext *>(_localctx)->nextItem->getText() : "")); 
      setState(727);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SamplerRowContext ------------------------------------------------------------------

AnyFXParser::SamplerRowContext::SamplerRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::SamplerRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

AnyFXParser::ExpressionContext* AnyFXParser::SamplerRowContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

AnyFXParser::SamplerTextureListContext* AnyFXParser::SamplerRowContext::samplerTextureList() {
  return getRuleContext<AnyFXParser::SamplerTextureListContext>(0);
}


size_t AnyFXParser::SamplerRowContext::getRuleIndex() const {
  return AnyFXParser::RuleSamplerRow;
}

void AnyFXParser::SamplerRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSamplerRow(this);
}

void AnyFXParser::SamplerRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSamplerRow(this);
}

AnyFXParser::SamplerRowContext* AnyFXParser::samplerRow() {
  SamplerRowContext *_localctx = _tracker.createInstance<SamplerRowContext>(_ctx, getState());
  enterRule(_localctx, 56, AnyFXParser::RuleSamplerRow);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(747);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(728);
      dynamic_cast<SamplerRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(729);
      match(AnyFXParser::EQ);
      setState(730);
      dynamic_cast<SamplerRowContext *>(_localctx)->samplerMode = match(AnyFXParser::IDENTIFIER);
      setState(731);
      match(AnyFXParser::SC);

              std::string flag((dynamic_cast<SamplerRowContext *>(_localctx)->flag1 != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->flag1->getText() : ""));
              _localctx->row.SetString(flag, (dynamic_cast<SamplerRowContext *>(_localctx)->samplerMode != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->samplerMode->getText() : ""));
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(733);
      dynamic_cast<SamplerRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
      setState(734);
      match(AnyFXParser::EQ);
      setState(735);
      dynamic_cast<SamplerRowContext *>(_localctx)->expressionContext = expression();
      setState(736);
      match(AnyFXParser::SC);

              std::string flag((dynamic_cast<SamplerRowContext *>(_localctx)->flag2 != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->flag2->getText() : ""));
              _localctx->row.SetExpression(flag, dynamic_cast<SamplerRowContext *>(_localctx)->expressionContext->tree);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(739);
      dynamic_cast<SamplerRowContext *>(_localctx)->flag4 = match(AnyFXParser::IDENTIFIER);
      setState(740);
      match(AnyFXParser::EQ);
      setState(741);
      match(AnyFXParser::LB);
      setState(742);
      dynamic_cast<SamplerRowContext *>(_localctx)->samplerTextureListContext = samplerTextureList();
      setState(743);
      match(AnyFXParser::RB);
      setState(744);
      match(AnyFXParser::SC);

              std::string flag((dynamic_cast<SamplerRowContext *>(_localctx)->flag4 != nullptr ? dynamic_cast<SamplerRowContext *>(_localctx)->flag4->getText() : ""));

              if (flag == "Samplers") _localctx->row.SetTextures(dynamic_cast<SamplerRowContext *>(_localctx)->samplerTextureListContext->list);
              else					_localctx->row.SetString(flag, "Incorrectly formatted texture list");
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramRowContext ------------------------------------------------------------------

AnyFXParser::ProgramRowContext::ProgramRowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}


size_t AnyFXParser::ProgramRowContext::getRuleIndex() const {
  return AnyFXParser::RuleProgramRow;
}

void AnyFXParser::ProgramRowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgramRow(this);
}

void AnyFXParser::ProgramRowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgramRow(this);
}

AnyFXParser::ProgramRowContext* AnyFXParser::programRow() {
  ProgramRowContext *_localctx = _tracker.createInstance<ProgramRowContext>(_ctx, getState());
  enterRule(_localctx, 58, AnyFXParser::RuleProgramRow);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(777);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(749);
        dynamic_cast<ProgramRowContext *>(_localctx)->shader = match(AnyFXParser::IDENTIFIER);
        setState(750);
        match(AnyFXParser::EQ);
        setState(751);
        dynamic_cast<ProgramRowContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
        setState(752);
        match(AnyFXParser::LP);
        setState(757);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == AnyFXParser::IDENTIFIER) {
          setState(753);
          dynamic_cast<ProgramRowContext *>(_localctx)->var = match(AnyFXParser::IDENTIFIER);
          setState(754);
          match(AnyFXParser::EQ);
          setState(755);
          dynamic_cast<ProgramRowContext *>(_localctx)->implementation = match(AnyFXParser::IDENTIFIER);
           _localctx->row.SetSubroutineMapping((dynamic_cast<ProgramRowContext *>(_localctx)->var != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->var->getText() : ""), (dynamic_cast<ProgramRowContext *>(_localctx)->implementation != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->implementation->getText() : "")); 
                      
        }
        setState(766);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AnyFXParser::CO) {
          setState(759);
          match(AnyFXParser::CO);
          setState(760);
          dynamic_cast<ProgramRowContext *>(_localctx)->var2 = match(AnyFXParser::IDENTIFIER);
          setState(761);
          match(AnyFXParser::EQ);
          setState(762);
          dynamic_cast<ProgramRowContext *>(_localctx)->implementation2 = match(AnyFXParser::IDENTIFIER);
           _localctx->row.SetSubroutineMapping((dynamic_cast<ProgramRowContext *>(_localctx)->var2 != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->var2->getText() : ""), (dynamic_cast<ProgramRowContext *>(_localctx)->implementation2 != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->implementation2->getText() : "")); 
                      
          setState(768);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(769);
        match(AnyFXParser::RP);
        setState(770);
        match(AnyFXParser::SC);

                std::string shaderString((dynamic_cast<ProgramRowContext *>(_localctx)->shader != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->shader->getText() : ""));
                _localctx->row.SetString(shaderString, (dynamic_cast<ProgramRowContext *>(_localctx)->name != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->name->getText() : ""));
            
        break;
      }

      case AnyFXParser::T__73: {
        enterOuterAlt(_localctx, 2);
        setState(772);
        match(AnyFXParser::T__73);
        setState(773);
        match(AnyFXParser::EQ);
        setState(774);
        dynamic_cast<ProgramRowContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
        setState(775);
        match(AnyFXParser::SC);

                _localctx->row.SetString("RenderState", (dynamic_cast<ProgramRowContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ProgramRowContext *>(_localctx)->identifierToken->getText() : ""));
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AnnotationContext ------------------------------------------------------------------

AnyFXParser::AnnotationContext::AnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::AnnotationContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::AnnotationContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::StringContext *> AnyFXParser::AnnotationContext::string() {
  return getRuleContexts<AnyFXParser::StringContext>();
}

AnyFXParser::StringContext* AnyFXParser::AnnotationContext::string(size_t i) {
  return getRuleContext<AnyFXParser::StringContext>(i);
}

std::vector<AnyFXParser::ExpressionContext *> AnyFXParser::AnnotationContext::expression() {
  return getRuleContexts<AnyFXParser::ExpressionContext>();
}

AnyFXParser::ExpressionContext* AnyFXParser::AnnotationContext::expression(size_t i) {
  return getRuleContext<AnyFXParser::ExpressionContext>(i);
}


size_t AnyFXParser::AnnotationContext::getRuleIndex() const {
  return AnyFXParser::RuleAnnotation;
}

void AnyFXParser::AnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnnotation(this);
}

void AnyFXParser::AnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnnotation(this);
}

AnyFXParser::AnnotationContext* AnyFXParser::annotation() {
  AnnotationContext *_localctx = _tracker.createInstance<AnnotationContext>(_ctx, getState());
  enterRule(_localctx, 60, AnyFXParser::RuleAnnotation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(779);
    match(AnyFXParser::LL);
    setState(796);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(780);
      dynamic_cast<AnnotationContext *>(_localctx)->typeContext = type();
      setState(781);
      dynamic_cast<AnnotationContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
      setState(782);
      match(AnyFXParser::EQ);
      setState(789);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AnyFXParser::QO:
        case AnyFXParser::Q: {
          setState(783);
          dynamic_cast<AnnotationContext *>(_localctx)->stringContext = string();
           _localctx->annot.AddString(dynamic_cast<AnnotationContext *>(_localctx)->stringContext->val); 
          break;
        }

        case AnyFXParser::T__0:
        case AnyFXParser::T__1:
        case AnyFXParser::LP:
        case AnyFXParser::NOT:
        case AnyFXParser::SUB_OP:
        case AnyFXParser::INTEGERLITERAL:
        case AnyFXParser::FLOATLITERAL:
        case AnyFXParser::DOUBLELITERAL:
        case AnyFXParser::HEX:
        case AnyFXParser::IDENTIFIER: {
          setState(786);
          dynamic_cast<AnnotationContext *>(_localctx)->expressionContext = expression();
           _localctx->annot.AddExpression(dynamic_cast<AnnotationContext *>(_localctx)->expressionContext->tree); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(791);
      match(AnyFXParser::SC);
       _localctx->annot.AddType(dynamic_cast<AnnotationContext *>(_localctx)->typeContext->ty); _localctx->annot.AddName((dynamic_cast<AnnotationContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<AnnotationContext *>(_localctx)->identifierToken->getText() : ""));  
      setState(798);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(799);
    match(AnyFXParser::RR);
     SetupFile(&_localctx->annot, _input); 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

AnyFXParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::ProgramContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::AnnotationContext* AnyFXParser::ProgramContext::annotation() {
  return getRuleContext<AnyFXParser::AnnotationContext>(0);
}

std::vector<AnyFXParser::ProgramRowContext *> AnyFXParser::ProgramContext::programRow() {
  return getRuleContexts<AnyFXParser::ProgramRowContext>();
}

AnyFXParser::ProgramRowContext* AnyFXParser::ProgramContext::programRow(size_t i) {
  return getRuleContext<AnyFXParser::ProgramRowContext>(i);
}


size_t AnyFXParser::ProgramContext::getRuleIndex() const {
  return AnyFXParser::RuleProgram;
}

void AnyFXParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AnyFXParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AnyFXParser::ProgramContext* AnyFXParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 62, AnyFXParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(802);
    match(AnyFXParser::T__74);
    setState(803);
    dynamic_cast<ProgramContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
     SetupFile(&_localctx->prog, _input); 
    setState(808);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(805);
      dynamic_cast<ProgramContext *>(_localctx)->annotationContext = annotation();
       _localctx->prog.SetAnnotation(dynamic_cast<ProgramContext *>(_localctx)->annotationContext->annot); 
    }
    setState(810);
    match(AnyFXParser::LB);
     _localctx->prog.SetName((dynamic_cast<ProgramContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<ProgramContext *>(_localctx)->identifierToken->getText() : ""));  
    setState(817);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::T__73

    || _la == AnyFXParser::IDENTIFIER) {
      setState(812);
      dynamic_cast<ProgramContext *>(_localctx)->programRowContext = programRow();
       _localctx->prog.ConsumeRow(dynamic_cast<ProgramContext *>(_localctx)->programRowContext->row); 
      setState(819);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(820);
    match(AnyFXParser::RB);
    setState(821);
    match(AnyFXParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

AnyFXParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::Binaryexp7Context* AnyFXParser::ExpressionContext::binaryexp7() {
  return getRuleContext<AnyFXParser::Binaryexp7Context>(0);
}


size_t AnyFXParser::ExpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleExpression;
}

void AnyFXParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void AnyFXParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

AnyFXParser::ExpressionContext* AnyFXParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 64, AnyFXParser::RuleExpression);

                          dynamic_cast<ExpressionContext *>(_localctx)->tree =  nullptr;
                      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(823);
    dynamic_cast<ExpressionContext *>(_localctx)->binaryexp7Context = binaryexp7();
     dynamic_cast<ExpressionContext *>(_localctx)->tree =  dynamic_cast<ExpressionContext *>(_localctx)->binaryexp7Context->tree; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp7Context ------------------------------------------------------------------

AnyFXParser::Binaryexp7Context::Binaryexp7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp6Context *> AnyFXParser::Binaryexp7Context::binaryexp6() {
  return getRuleContexts<AnyFXParser::Binaryexp6Context>();
}

AnyFXParser::Binaryexp6Context* AnyFXParser::Binaryexp7Context::binaryexp6(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp6Context>(i);
}


size_t AnyFXParser::Binaryexp7Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp7;
}

void AnyFXParser::Binaryexp7Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp7(this);
}

void AnyFXParser::Binaryexp7Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp7(this);
}

AnyFXParser::Binaryexp7Context* AnyFXParser::binaryexp7() {
  Binaryexp7Context *_localctx = _tracker.createInstance<Binaryexp7Context>(_ctx, getState());
  enterRule(_localctx, 66, AnyFXParser::RuleBinaryexp7);

                          Expression* prev = nullptr;
                          dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(826);
    dynamic_cast<Binaryexp7Context *>(_localctx)->e1 = binaryexp6();
     dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(834);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICOR) {
      setState(828);
      match(AnyFXParser::LOGICOR);
      setState(829);
      dynamic_cast<Binaryexp7Context *>(_localctx)->e2 = binaryexp6();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression("||", prev, dynamic_cast<Binaryexp7Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression("||", dynamic_cast<Binaryexp7Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp7Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              dynamic_cast<Binaryexp7Context *>(_localctx)->tree =  lhs;
                          
      setState(836);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp6Context ------------------------------------------------------------------

AnyFXParser::Binaryexp6Context::Binaryexp6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp5Context *> AnyFXParser::Binaryexp6Context::binaryexp5() {
  return getRuleContexts<AnyFXParser::Binaryexp5Context>();
}

AnyFXParser::Binaryexp5Context* AnyFXParser::Binaryexp6Context::binaryexp5(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp5Context>(i);
}


size_t AnyFXParser::Binaryexp6Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp6;
}

void AnyFXParser::Binaryexp6Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp6(this);
}

void AnyFXParser::Binaryexp6Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp6(this);
}

AnyFXParser::Binaryexp6Context* AnyFXParser::binaryexp6() {
  Binaryexp6Context *_localctx = _tracker.createInstance<Binaryexp6Context>(_ctx, getState());
  enterRule(_localctx, 68, AnyFXParser::RuleBinaryexp6);

                          Expression* prev = nullptr;
                          dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(837);
    dynamic_cast<Binaryexp6Context *>(_localctx)->e1 = binaryexp5();
     dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(845);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICAND) {
      setState(839);
      match(AnyFXParser::LOGICAND);
      setState(840);
      dynamic_cast<Binaryexp6Context *>(_localctx)->e2 = binaryexp5();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression("&&", prev, dynamic_cast<Binaryexp6Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression("&&", dynamic_cast<Binaryexp6Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp6Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              dynamic_cast<Binaryexp6Context *>(_localctx)->tree =  lhs;
                          
      setState(847);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp5Context ------------------------------------------------------------------

AnyFXParser::Binaryexp5Context::Binaryexp5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp4Context *> AnyFXParser::Binaryexp5Context::binaryexp4() {
  return getRuleContexts<AnyFXParser::Binaryexp4Context>();
}

AnyFXParser::Binaryexp4Context* AnyFXParser::Binaryexp5Context::binaryexp4(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp4Context>(i);
}


size_t AnyFXParser::Binaryexp5Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp5;
}

void AnyFXParser::Binaryexp5Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp5(this);
}

void AnyFXParser::Binaryexp5Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp5(this);
}

AnyFXParser::Binaryexp5Context* AnyFXParser::binaryexp5() {
  Binaryexp5Context *_localctx = _tracker.createInstance<Binaryexp5Context>(_ctx, getState());
  enterRule(_localctx, 70, AnyFXParser::RuleBinaryexp5);

                          Expression* prev = nullptr;
                          dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(848);
    dynamic_cast<Binaryexp5Context *>(_localctx)->e1 = binaryexp4();
     dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(856);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICEQ

    || _la == AnyFXParser::NOTEQ) {
      setState(850);
      dynamic_cast<Binaryexp5Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::LOGICEQ

      || _la == AnyFXParser::NOTEQ)) {
        dynamic_cast<Binaryexp5Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(851);
      dynamic_cast<Binaryexp5Context *>(_localctx)->e2 = binaryexp4();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp5Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp5Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp5Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp5Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp5Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp5Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp5Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              dynamic_cast<Binaryexp5Context *>(_localctx)->tree =  lhs;
                          
      setState(858);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp4Context ------------------------------------------------------------------

AnyFXParser::Binaryexp4Context::Binaryexp4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp3Context *> AnyFXParser::Binaryexp4Context::binaryexp3() {
  return getRuleContexts<AnyFXParser::Binaryexp3Context>();
}

AnyFXParser::Binaryexp3Context* AnyFXParser::Binaryexp4Context::binaryexp3(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp3Context>(i);
}


size_t AnyFXParser::Binaryexp4Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp4;
}

void AnyFXParser::Binaryexp4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp4(this);
}

void AnyFXParser::Binaryexp4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp4(this);
}

AnyFXParser::Binaryexp4Context* AnyFXParser::binaryexp4() {
  Binaryexp4Context *_localctx = _tracker.createInstance<Binaryexp4Context>(_ctx, getState());
  enterRule(_localctx, 72, AnyFXParser::RuleBinaryexp4);

                          Expression* prev = nullptr;
                          dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(859);
    dynamic_cast<Binaryexp4Context *>(_localctx)->e1 = binaryexp3();
     dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(867);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & ((1ULL << (AnyFXParser::LESS - 100))
      | (1ULL << (AnyFXParser::LESSEQ - 100))
      | (1ULL << (AnyFXParser::GREATER - 100))
      | (1ULL << (AnyFXParser::GREATEREQ - 100)))) != 0)) {
      setState(861);
      dynamic_cast<Binaryexp4Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 100) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 100)) & ((1ULL << (AnyFXParser::LESS - 100))
        | (1ULL << (AnyFXParser::LESSEQ - 100))
        | (1ULL << (AnyFXParser::GREATER - 100))
        | (1ULL << (AnyFXParser::GREATEREQ - 100)))) != 0))) {
        dynamic_cast<Binaryexp4Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(862);
      dynamic_cast<Binaryexp4Context *>(_localctx)->e2 = binaryexp3();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp4Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp4Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp4Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp4Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp4Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp4Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp4Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              dynamic_cast<Binaryexp4Context *>(_localctx)->tree =  lhs;
                          
      setState(869);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp3Context ------------------------------------------------------------------

AnyFXParser::Binaryexp3Context::Binaryexp3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp2Context *> AnyFXParser::Binaryexp3Context::binaryexp2() {
  return getRuleContexts<AnyFXParser::Binaryexp2Context>();
}

AnyFXParser::Binaryexp2Context* AnyFXParser::Binaryexp3Context::binaryexp2(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp2Context>(i);
}


size_t AnyFXParser::Binaryexp3Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp3;
}

void AnyFXParser::Binaryexp3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp3(this);
}

void AnyFXParser::Binaryexp3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp3(this);
}

AnyFXParser::Binaryexp3Context* AnyFXParser::binaryexp3() {
  Binaryexp3Context *_localctx = _tracker.createInstance<Binaryexp3Context>(_ctx, getState());
  enterRule(_localctx, 74, AnyFXParser::RuleBinaryexp3);

                          Expression* prev = nullptr;
                          dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(870);
    dynamic_cast<Binaryexp3Context *>(_localctx)->e1 = binaryexp2();
     dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree; _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(878);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::ADD_OP

    || _la == AnyFXParser::SUB_OP) {
      setState(872);
      dynamic_cast<Binaryexp3Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::ADD_OP

      || _la == AnyFXParser::SUB_OP)) {
        dynamic_cast<Binaryexp3Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(873);
      dynamic_cast<Binaryexp3Context *>(_localctx)->e2 = binaryexp2();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp3Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp3Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp3Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp3Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp3Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp3Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp3Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              dynamic_cast<Binaryexp3Context *>(_localctx)->tree =  lhs;
                          
      setState(880);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp2Context ------------------------------------------------------------------

AnyFXParser::Binaryexp2Context::Binaryexp2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AnyFXParser::Binaryexp1Context *> AnyFXParser::Binaryexp2Context::binaryexp1() {
  return getRuleContexts<AnyFXParser::Binaryexp1Context>();
}

AnyFXParser::Binaryexp1Context* AnyFXParser::Binaryexp2Context::binaryexp1(size_t i) {
  return getRuleContext<AnyFXParser::Binaryexp1Context>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp2Context::MUL_OP() {
  return getTokens(AnyFXParser::MUL_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp2Context::MUL_OP(size_t i) {
  return getToken(AnyFXParser::MUL_OP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp2Context::DIV_OP() {
  return getTokens(AnyFXParser::DIV_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp2Context::DIV_OP(size_t i) {
  return getToken(AnyFXParser::DIV_OP, i);
}


size_t AnyFXParser::Binaryexp2Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp2;
}

void AnyFXParser::Binaryexp2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp2(this);
}

void AnyFXParser::Binaryexp2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp2(this);
}

AnyFXParser::Binaryexp2Context* AnyFXParser::binaryexp2() {
  Binaryexp2Context *_localctx = _tracker.createInstance<Binaryexp2Context>(_ctx, getState());
  enterRule(_localctx, 76, AnyFXParser::RuleBinaryexp2);

                          Expression* prev = nullptr;
                          dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(881);
    dynamic_cast<Binaryexp2Context *>(_localctx)->e1 = binaryexp1();
     dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree; _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(889);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::DIV_OP

    || _la == AnyFXParser::MUL_OP) {
      setState(883);
      dynamic_cast<Binaryexp2Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::DIV_OP

      || _la == AnyFXParser::MUL_OP)) {
        dynamic_cast<Binaryexp2Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(884);
      dynamic_cast<Binaryexp2Context *>(_localctx)->e2 = binaryexp1();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp2Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp2Context *>(_localctx)->op->getText() : ""), prev, dynamic_cast<Binaryexp2Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = new BinaryExpression((dynamic_cast<Binaryexp2Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp2Context *>(_localctx)->op->getText() : ""), dynamic_cast<Binaryexp2Context *>(_localctx)->e1->tree, dynamic_cast<Binaryexp2Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              dynamic_cast<Binaryexp2Context *>(_localctx)->tree =  lhs;
                          
      setState(891);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binaryexp1Context ------------------------------------------------------------------

AnyFXParser::Binaryexp1Context::Binaryexp1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::BinaryexpatomContext* AnyFXParser::Binaryexp1Context::binaryexpatom() {
  return getRuleContext<AnyFXParser::BinaryexpatomContext>(0);
}

tree::TerminalNode* AnyFXParser::Binaryexp1Context::SUB_OP() {
  return getToken(AnyFXParser::SUB_OP, 0);
}

tree::TerminalNode* AnyFXParser::Binaryexp1Context::NOT() {
  return getToken(AnyFXParser::NOT, 0);
}


size_t AnyFXParser::Binaryexp1Context::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexp1;
}

void AnyFXParser::Binaryexp1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexp1(this);
}

void AnyFXParser::Binaryexp1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexp1(this);
}

AnyFXParser::Binaryexp1Context* AnyFXParser::binaryexp1() {
  Binaryexp1Context *_localctx = _tracker.createInstance<Binaryexp1Context>(_ctx, getState());
  enterRule(_localctx, 78, AnyFXParser::RuleBinaryexp1);

                          char operat = 0;
                          dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(893);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::NOT

    || _la == AnyFXParser::SUB_OP) {
      setState(892);
      dynamic_cast<Binaryexp1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::NOT

      || _la == AnyFXParser::SUB_OP)) {
        dynamic_cast<Binaryexp1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(895);
    dynamic_cast<Binaryexp1Context *>(_localctx)->e1 = binaryexpatom();

                            Expression* rhs = dynamic_cast<Binaryexp1Context *>(_localctx)->e1->tree;

                            if (dynamic_cast<Binaryexp1Context *>(_localctx)->op != 0)
                            {
                                operat = (dynamic_cast<Binaryexp1Context *>(_localctx)->op != nullptr ? dynamic_cast<Binaryexp1Context *>(_localctx)->op->getText() : "").c_str()[0];
                                rhs = new UnaryExpression(operat, rhs);
                            }

                            SetupFile(rhs, _input);
                            dynamic_cast<Binaryexp1Context *>(_localctx)->tree =  rhs;

                        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryexpatomContext ------------------------------------------------------------------

AnyFXParser::BinaryexpatomContext::BinaryexpatomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::INTEGERLITERAL() {
  return getToken(AnyFXParser::INTEGERLITERAL, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::FLOATLITERAL() {
  return getToken(AnyFXParser::FLOATLITERAL, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::DOUBLELITERAL() {
  return getToken(AnyFXParser::DOUBLELITERAL, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::HEX() {
  return getToken(AnyFXParser::HEX, 0);
}

tree::TerminalNode* AnyFXParser::BinaryexpatomContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

AnyFXParser::BooleanContext* AnyFXParser::BinaryexpatomContext::boolean() {
  return getRuleContext<AnyFXParser::BooleanContext>(0);
}

AnyFXParser::ParantexpressionContext* AnyFXParser::BinaryexpatomContext::parantexpression() {
  return getRuleContext<AnyFXParser::ParantexpressionContext>(0);
}


size_t AnyFXParser::BinaryexpatomContext::getRuleIndex() const {
  return AnyFXParser::RuleBinaryexpatom;
}

void AnyFXParser::BinaryexpatomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryexpatom(this);
}

void AnyFXParser::BinaryexpatomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryexpatom(this);
}

AnyFXParser::BinaryexpatomContext* AnyFXParser::binaryexpatom() {
  BinaryexpatomContext *_localctx = _tracker.createInstance<BinaryexpatomContext>(_ctx, getState());
  enterRule(_localctx, 80, AnyFXParser::RuleBinaryexpatom);

                          dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  nullptr;
                      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(914);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::INTEGERLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(898);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken = match(AnyFXParser::INTEGERLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(atoi((dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->integerliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
                
        break;
      }

      case AnyFXParser::FLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(900);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken = match(AnyFXParser::FLOATLITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->floatliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
                
        break;
      }

      case AnyFXParser::DOUBLELITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(902);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken = match(AnyFXParser::DOUBLELITERAL);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new FloatExpression(atof((dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->doubleliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
                
        break;
      }

      case AnyFXParser::HEX: {
        enterOuterAlt(_localctx, 4);
        setState(904);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken = match(AnyFXParser::HEX);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new IntExpression(strtoul((dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->hexToken->getText() : "").c_str(), nullptr, 16)); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
                
        break;
      }

      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 5);
        setState(906);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new SymbolExpression((dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken != nullptr ? dynamic_cast<BinaryexpatomContext *>(_localctx)->identifierToken->getText() : "")); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
                
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(908);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext = boolean();

                                dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  new BoolExpression(dynamic_cast<BinaryexpatomContext *>(_localctx)->booleanContext->val);
                                SetupFile(_localctx->tree, _input);
                            
        break;
      }

      case AnyFXParser::LP: {
        enterOuterAlt(_localctx, 7);
        setState(911);
        dynamic_cast<BinaryexpatomContext *>(_localctx)->parantexpressionContext = parantexpression();
         dynamic_cast<BinaryexpatomContext *>(_localctx)->tree =  dynamic_cast<BinaryexpatomContext *>(_localctx)->parantexpressionContext->tree; 
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParantexpressionContext ------------------------------------------------------------------

AnyFXParser::ParantexpressionContext::ParantexpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AnyFXParser::ExpressionContext* AnyFXParser::ParantexpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}


size_t AnyFXParser::ParantexpressionContext::getRuleIndex() const {
  return AnyFXParser::RuleParantexpression;
}

void AnyFXParser::ParantexpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantexpression(this);
}

void AnyFXParser::ParantexpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AnyFXListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantexpression(this);
}

AnyFXParser::ParantexpressionContext* AnyFXParser::parantexpression() {
  ParantexpressionContext *_localctx = _tracker.createInstance<ParantexpressionContext>(_ctx, getState());
  enterRule(_localctx, 82, AnyFXParser::RuleParantexpression);

                          dynamic_cast<ParantexpressionContext *>(_localctx)->tree =  nullptr;
                      

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(916);
    match(AnyFXParser::LP);
    setState(917);
    dynamic_cast<ParantexpressionContext *>(_localctx)->expressionContext = expression();
    setState(918);
    match(AnyFXParser::RP);
     dynamic_cast<ParantexpressionContext *>(_localctx)->tree =  dynamic_cast<ParantexpressionContext *>(_localctx)->expressionContext->tree; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> AnyFXParser::_decisionToDFA;
atn::PredictionContextCache AnyFXParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AnyFXParser::_atn;
std::vector<uint16_t> AnyFXParser::_serializedATN;

std::vector<std::string> AnyFXParser::_ruleNames = {
  "string", "boolean", "preprocess", "entry", "effect", "qualifier", "qualifierValued", 
  "type", "qualifierExpression", "structure", "varblock", "varbuffer", "subroutine", 
  "valueList", "valueSingleList", "variable", "constant", "parameterAttribute", 
  "parameter", "parameterList", "functionAttribute", "codeBlock", "function", 
  "blendStateRow", "renderStateRow", "renderState", "sampler", "samplerTextureList", 
  "samplerRow", "programRow", "annotation", "program", "expression", "binaryexp7", 
  "binaryexp6", "binaryexp5", "binaryexp4", "binaryexp3", "binaryexp2", 
  "binaryexp1", "binaryexpatom", "parantexpression"
};

std::vector<std::string> AnyFXParser::_literalNames = {
  "", "'true'", "'false'", "'#line'", "'const'", "'shared'", "'push'", "'flat'", 
  "'noperspective'", "'no_perspective'", "'patch'", "'in'", "'out'", "'inout'", 
  "'in_out'", "'groupshared'", "'group_shared'", "'rgba32f'", "'rgba16f'", 
  "'rg32f'", "'rg16f'", "'r11g11b10f'", "'r32f'", "'r16f'", "'rgba16'", 
  "'rgba8'", "'rgb10a2'", "'rg16'", "'rg8'", "'r16'", "'r8'", "'rgba16snorm'", 
  "'rgba8snorm'", "'rg16snorm'", "'rg8snorm'", "'r16snorm'", "'r8snorm'", 
  "'rgba32i'", "'rgba16i'", "'rgba8i'", "'rg32i'", "'rg16i'", "'rg8i'", 
  "'r32i'", "'r16i'", "'r8i'", "'rgba32ui'", "'rgba16ui'", "'rgba8ui'", 
  "'rg32ui'", "'rg16ui'", "'rg8ui'", "'r32ui'", "'r16ui'", "'r8ui'", "'read'", 
  "'write'", "'readwrite'", "'read_write'", "'atomic'", "'volatile'", "'group'", 
  "'index'", "'binding'", "'struct'", "'constant'", "'rw_buffer'", "'prototype'", 
  "'subroutine'", "'feedback'", "'slot'", "'shader'", "'render_state'", 
  "'sampler_state'", "'RenderState'", "'program'", "';'", "','", "':'", 
  "'('", "')'", "'{'", "'}'", "'['", "']'", "'.'", "'!'", "'='", "'\"'", 
  "'?'", "'&'", "'&='", "'|'", "'|='", "'^'", "'^='", "'~'", "'''", "'#'", 
  "'\\'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'&&'", "'||'", 
  "'%'", "'_'", "'+'", "'-'", "'/'", "'*'"
};

std::vector<std::string> AnyFXParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "SC", "CO", "COL", "LP", "RP", "LB", "RB", "LL", "RR", 
  "DOT", "NOT", "EQ", "QO", "QU", "AND", "ANDSET", "OR", "ORSET", "XOR", 
  "XORSET", "CONNJUGATE", "Q", "NU", "FORWARDSLASH", "LESS", "LESSEQ", "GREATER", 
  "GREATEREQ", "LOGICEQ", "NOTEQ", "LOGICAND", "LOGICOR", "MOD", "UNDERSC", 
  "ADD_OP", "SUB_OP", "DIV_OP", "MUL_OP", "INTEGERLITERAL", "COMMENT", "ML_COMMENT", 
  "FLOATLITERAL", "EXPONENT", "DOUBLELITERAL", "HEX", "IDENTIFIER", "WS"
};

dfa::Vocabulary AnyFXParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AnyFXParser::_tokenNames;

AnyFXParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x7c, 0x39c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x5a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x5d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x63, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x66, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x69, 
    0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x6f, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x78, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x7b, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x7, 0x6, 0xa1, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa4, 0xb, 0x6, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xb9, 0xa, 0xb, 
    0xc, 0xb, 0xe, 0xb, 0xbc, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0xc8, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xcb, 0xb, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd3, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xd9, 0xa, 0xc, 0xc, 
    0xc, 0xe, 0xc, 0xdc, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0xe9, 0xa, 0xc, 0x5, 0xc, 0xeb, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0xf5, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xf8, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x100, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x106, 0xa, 0xd, 0xc, 0xd, 
    0xe, 0xd, 0x109, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x116, 0xa, 0xd, 0x5, 0xd, 0x118, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x12e, 0xa, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x136, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x139, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x7, 0x11, 0x144, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x147, 0xb, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x15d, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x160, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x6, 0x11, 0x172, 0xa, 0x11, 
    0xd, 0x11, 0xe, 0x11, 0x173, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0x188, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x18b, 
    0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x5, 0x11, 0x1a7, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0x1ac, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 
    0x12, 0x1d2, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1d5, 0xb, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x1f6, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x1f9, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 
    0x209, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x214, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x221, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x5, 0x14, 0x22a, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x7, 0x14, 0x22f, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x232, 
    0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x5, 0x14, 0x23b, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0x23f, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x247, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
    0x24a, 0xb, 0x15, 0x5, 0x15, 0x24c, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x259, 0xa, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x7, 0x17, 0x25d, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x260, 
    0xb, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x264, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x269, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0x26c, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x270, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x29c, 0xa, 0x1b, 0xc, 0x1b, 
    0xe, 0x1b, 0x29f, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x2a3, 
    0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x7, 0x1c, 0x2ab, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x2ae, 0xb, 
    0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x2bb, 
    0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x2be, 0xb, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 
    0x1c, 0x2c8, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x2cb, 0xb, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x2cf, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x2d6, 0xa, 0x1d, 0xc, 0x1d, 
    0xe, 0x1d, 0x2d9, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x2ee, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 
    0x1f, 0x2f8, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x7, 0x1f, 0x2ff, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x302, 
    0xb, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x30c, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x318, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x31d, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 
    0x320, 0xb, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x32b, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x332, 
    0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x335, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x343, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x346, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x34e, 0xa, 0x24, 0xc, 0x24, 
    0xe, 0x24, 0x351, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x359, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 
    0x35c, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x7, 0x26, 0x364, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x367, 
    0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x7, 0x27, 0x36f, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x372, 0xb, 
    0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x7, 0x28, 0x37a, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x37d, 0xb, 0x28, 
    0x3, 0x29, 0x5, 0x29, 0x380, 0xa, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x395, 0xa, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x4, 0x79, 0xa2, 
    0x2, 0x2c, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
    0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x2, 0xc, 0x3, 0x2, 0x5a, 
    0x5a, 0x3, 0x2, 0x63, 0x63, 0x3, 0x2, 0x6, 0x3e, 0x3, 0x2, 0x3f, 0x41, 
    0x3, 0x2, 0x53, 0x54, 0x3, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x66, 0x69, 0x3, 
    0x2, 0x70, 0x71, 0x3, 0x2, 0x72, 0x73, 0x4, 0x2, 0x58, 0x58, 0x71, 0x71, 
    0x2, 0x3d4, 0x2, 0x68, 0x3, 0x2, 0x2, 0x2, 0x4, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x79, 0x3, 0x2, 0x2, 0x2, 0x8, 0x7e, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x12, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x16, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x13a, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x145, 0x3, 0x2, 0x2, 0x2, 0x22, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x20a, 0x3, 0x2, 0x2, 0x2, 0x26, 0x213, 0x3, 0x2, 0x2, 0x2, 0x28, 0x24b, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x258, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x263, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x30, 0x27c, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x285, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2a2, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x2ce, 0x3, 0x2, 0x2, 0x2, 0x38, 0x2d0, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x30d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x324, 0x3, 0x2, 0x2, 0x2, 0x42, 0x339, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x46, 0x347, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x352, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x35d, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x368, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x373, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x394, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x396, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5b, 0x7, 0x5a, 0x2, 0x2, 0x57, 
    0x58, 0xa, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x8, 0x2, 0x1, 0x2, 0x59, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x69, 0x7, 0x5a, 0x2, 
    0x2, 0x5f, 0x64, 0x7, 0x63, 0x2, 0x2, 0x60, 0x61, 0xa, 0x3, 0x2, 0x2, 
    0x61, 0x63, 0x8, 0x2, 0x1, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x69, 0x7, 0x63, 0x2, 0x2, 0x68, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x69, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6b, 0x7, 0x3, 0x2, 0x2, 0x6b, 0x6f, 0x8, 0x3, 0x1, 0x2, 
    0x6c, 0x6d, 0x7, 0x4, 0x2, 0x2, 0x6d, 0x6f, 0x8, 0x3, 0x1, 0x2, 0x6e, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x8, 0x4, 0x1, 0x2, 0x71, 0x72, 0x7, 
    0x5, 0x2, 0x2, 0x72, 0x73, 0x7, 0x74, 0x2, 0x2, 0x73, 0x74, 0x5, 0x2, 
    0x2, 0x2, 0x74, 0x75, 0x8, 0x4, 0x1, 0x2, 0x75, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x78, 0xb, 0x2, 0x2, 0x2, 0x77, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 
    0x2, 0x2, 0x3, 0x7d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0xa, 
    0x6, 0x2, 0x7f, 0x80, 0x8, 0x5, 0x1, 0x2, 0x80, 0x81, 0x7, 0x2, 0x2, 
    0x3, 0x81, 0x9, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x5, 0x22, 0x12, 0x2, 
    0x83, 0x84, 0x8, 0x6, 0x1, 0x2, 0x84, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x5, 0x20, 0x11, 0x2, 0x86, 0x87, 0x8, 0x6, 0x1, 0x2, 0x87, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x34, 0x1b, 0x2, 0x89, 0x8a, 0x8, 
    0x6, 0x1, 0x2, 0x8a, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x2e, 
    0x18, 0x2, 0x8c, 0x8d, 0x8, 0x6, 0x1, 0x2, 0x8d, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8f, 0x5, 0x40, 0x21, 0x2, 0x8f, 0x90, 0x8, 0x6, 0x1, 0x2, 
    0x90, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x14, 0xb, 0x2, 0x92, 
    0x93, 0x8, 0x6, 0x1, 0x2, 0x93, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 
    0x5, 0x16, 0xc, 0x2, 0x95, 0x96, 0x8, 0x6, 0x1, 0x2, 0x96, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x98, 0x5, 0x18, 0xd, 0x2, 0x98, 0x99, 0x8, 0x6, 
    0x1, 0x2, 0x99, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x5, 0x1a, 0xe, 
    0x2, 0x9b, 0x9c, 0x8, 0x6, 0x1, 0x2, 0x9c, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x9e, 0x5, 0x36, 0x1c, 0x2, 0x9e, 0x9f, 0x8, 0x6, 0x1, 0x2, 0x9f, 
    0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x82, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x85, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0x88, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x94, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x9, 0x4, 0x2, 0x2, 0xa6, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa8, 0x9, 0x5, 0x2, 0x2, 0xa8, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xaa, 0x7, 0x7b, 0x2, 0x2, 0xaa, 0xab, 0x8, 0x9, 0x1, 
    0x2, 0xab, 0x11, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x5, 0xe, 0x8, 0x2, 
    0xad, 0xae, 0x5, 0x54, 0x2b, 0x2, 0xae, 0xaf, 0x8, 0xa, 0x1, 0x2, 0xaf, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x42, 0x2, 0x2, 0xb1, 0xb2, 
    0x7, 0x7b, 0x2, 0x2, 0xb2, 0xb3, 0x8, 0xb, 0x1, 0x2, 0xb3, 0xba, 0x7, 
    0x53, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x26, 0x14, 0x2, 0xb5, 0xb6, 0x7, 0x4e, 
    0x2, 0x2, 0xb6, 0xb7, 0x8, 0xb, 0x1, 0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x7, 0x54, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x4e, 0x2, 0x2, 0xbf, 0xc0, 0x8, 
    0xb, 0x1, 0x2, 0xc0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0xc, 
    0x7, 0x2, 0xc2, 0xc3, 0x8, 0xc, 0x1, 0x2, 0xc3, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xc5, 0x5, 0x12, 0xa, 0x2, 0xc5, 0xc6, 0x8, 0xc, 0x1, 0x2, 
    0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc4, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x43, 
    0x2, 0x2, 0xcd, 0xce, 0x7, 0x7b, 0x2, 0x2, 0xce, 0xd2, 0x8, 0xc, 0x1, 
    0x2, 0xcf, 0xd0, 0x5, 0x3e, 0x20, 0x2, 0xd0, 0xd1, 0x8, 0xc, 0x1, 0x2, 
    0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xda, 
    0x7, 0x53, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x20, 0x11, 0x2, 0xd6, 0xd7, 0x8, 
    0xc, 0x1, 0x2, 0xd7, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xea, 0x7, 0x54, 0x2, 0x2, 0xde, 
    0xdf, 0x7, 0x7b, 0x2, 0x2, 0xdf, 0xe8, 0x8, 0xc, 0x1, 0x2, 0xe0, 0xe1, 
    0x7, 0x55, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x56, 0x2, 0x2, 0xe2, 0xe9, 0x8, 
    0xc, 0x1, 0x2, 0xe3, 0xe4, 0x7, 0x55, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x42, 
    0x22, 0x2, 0xe5, 0xe6, 0x7, 0x56, 0x2, 0x2, 0xe6, 0xe7, 0x8, 0xc, 0x1, 
    0x2, 0xe7, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xe8, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xde, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x4e, 0x2, 0x2, 0xed, 0x17, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x5, 0xc, 
    0x7, 0x2, 0xef, 0xf0, 0x8, 0xd, 0x1, 0x2, 0xf0, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xf2, 0x5, 0x12, 0xa, 0x2, 0xf2, 0xf3, 0x8, 0xd, 0x1, 0x2, 
    0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x44, 
    0x2, 0x2, 0xfa, 0xfb, 0x7, 0x7b, 0x2, 0x2, 0xfb, 0xff, 0x8, 0xd, 0x1, 
    0x2, 0xfc, 0xfd, 0x5, 0x3e, 0x20, 0x2, 0xfd, 0xfe, 0x8, 0xd, 0x1, 0x2, 
    0xfe, 0x100, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xff, 
    0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x107, 0x7, 0x53, 0x2, 0x2, 0x102, 0x103, 0x5, 0x20, 0x11, 0x2, 0x103, 
    0x104, 0x8, 0xd, 0x1, 0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 0x105, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 0x3, 0x2, 0x2, 0x2, 0x107, 
    0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 0x108, 
    0x10a, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10a, 
    0x117, 0x7, 0x54, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x7b, 0x2, 0x2, 0x10c, 
    0x115, 0x8, 0xd, 0x1, 0x2, 0x10d, 0x10e, 0x7, 0x55, 0x2, 0x2, 0x10e, 
    0x10f, 0x7, 0x56, 0x2, 0x2, 0x10f, 0x116, 0x8, 0xd, 0x1, 0x2, 0x110, 
    0x111, 0x7, 0x55, 0x2, 0x2, 0x111, 0x112, 0x5, 0x42, 0x22, 0x2, 0x112, 
    0x113, 0x7, 0x56, 0x2, 0x2, 0x113, 0x114, 0x8, 0xd, 0x1, 0x2, 0x114, 
    0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x117, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 
    0x11a, 0x7, 0x4e, 0x2, 0x2, 0x11a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x11c, 0x7, 0x45, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x10, 0x9, 0x2, 0x11d, 
    0x11e, 0x7, 0x7b, 0x2, 0x2, 0x11e, 0x11f, 0x8, 0xe, 0x1, 0x2, 0x11f, 
    0x120, 0x7, 0x51, 0x2, 0x2, 0x120, 0x121, 0x5, 0x28, 0x15, 0x2, 0x121, 
    0x122, 0x7, 0x52, 0x2, 0x2, 0x122, 0x123, 0x7, 0x4e, 0x2, 0x2, 0x123, 
    0x124, 0x8, 0xe, 0x1, 0x2, 0x124, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x125, 
    0x126, 0x7, 0x46, 0x2, 0x2, 0x126, 0x127, 0x7, 0x51, 0x2, 0x2, 0x127, 
    0x128, 0x7, 0x7b, 0x2, 0x2, 0x128, 0x129, 0x7, 0x52, 0x2, 0x2, 0x129, 
    0x12a, 0x8, 0xe, 0x1, 0x2, 0x12a, 0x12b, 0x5, 0x2e, 0x18, 0x2, 0x12b, 
    0x12c, 0x8, 0xe, 0x1, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x125, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 0x5, 0x42, 0x22, 0x2, 0x130, 
    0x137, 0x8, 0xf, 0x1, 0x2, 0x131, 0x132, 0x7, 0x4f, 0x2, 0x2, 0x132, 
    0x133, 0x5, 0x42, 0x22, 0x2, 0x133, 0x134, 0x8, 0xf, 0x1, 0x2, 0x134, 
    0x136, 0x3, 0x2, 0x2, 0x2, 0x135, 0x131, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x137, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x5, 0x42, 0x22, 0x2, 0x13b, 0x13c, 
    0x8, 0x10, 0x1, 0x2, 0x13c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 
    0x5, 0xc, 0x7, 0x2, 0x13e, 0x13f, 0x8, 0x11, 0x1, 0x2, 0x13f, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x5, 0x12, 0xa, 0x2, 0x141, 0x142, 
    0x8, 0x11, 0x1, 0x2, 0x142, 0x144, 0x3, 0x2, 0x2, 0x2, 0x143, 0x13d, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x140, 0x3, 0x2, 0x2, 0x2, 0x144, 0x147, 
    0x3, 0x2, 0x2, 0x2, 0x145, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 
    0x3, 0x2, 0x2, 0x2, 0x146, 0x148, 0x3, 0x2, 0x2, 0x2, 0x147, 0x145, 
    0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x5, 0x10, 0x9, 0x2, 0x149, 0x14a, 
    0x7, 0x7b, 0x2, 0x2, 0x14a, 0x1a6, 0x8, 0x11, 0x1, 0x2, 0x14b, 0x14c, 
    0x7, 0x55, 0x2, 0x2, 0x14c, 0x14d, 0x7, 0x56, 0x2, 0x2, 0x14d, 0x14e, 
    0x7, 0x59, 0x2, 0x2, 0x14e, 0x14f, 0x8, 0x11, 0x1, 0x2, 0x14f, 0x150, 
    0x7, 0x53, 0x2, 0x2, 0x150, 0x151, 0x5, 0x10, 0x9, 0x2, 0x151, 0x152, 
    0x7, 0x51, 0x2, 0x2, 0x152, 0x153, 0x5, 0x1c, 0xf, 0x2, 0x153, 0x154, 
    0x7, 0x52, 0x2, 0x2, 0x154, 0x15e, 0x8, 0x11, 0x1, 0x2, 0x155, 0x156, 
    0x7, 0x4f, 0x2, 0x2, 0x156, 0x157, 0x5, 0x10, 0x9, 0x2, 0x157, 0x158, 
    0x7, 0x51, 0x2, 0x2, 0x158, 0x159, 0x5, 0x1c, 0xf, 0x2, 0x159, 0x15a, 
    0x7, 0x52, 0x2, 0x2, 0x15a, 0x15b, 0x8, 0x11, 0x1, 0x2, 0x15b, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x160, 
    0x3, 0x2, 0x2, 0x2, 0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x15f, 0x161, 0x3, 0x2, 0x2, 0x2, 0x160, 0x15e, 
    0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x54, 0x2, 0x2, 0x162, 0x1a7, 
    0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0x55, 0x2, 0x2, 0x164, 0x165, 
    0x7, 0x56, 0x2, 0x2, 0x165, 0x166, 0x7, 0x59, 0x2, 0x2, 0x166, 0x167, 
    0x8, 0x11, 0x1, 0x2, 0x167, 0x168, 0x7, 0x53, 0x2, 0x2, 0x168, 0x169, 
    0x5, 0x1c, 0xf, 0x2, 0x169, 0x16a, 0x7, 0x54, 0x2, 0x2, 0x16a, 0x16b, 
    0x8, 0x11, 0x1, 0x2, 0x16b, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 
    0x7, 0x55, 0x2, 0x2, 0x16d, 0x16e, 0x5, 0x42, 0x22, 0x2, 0x16e, 0x16f, 
    0x7, 0x56, 0x2, 0x2, 0x16f, 0x170, 0x8, 0x11, 0x1, 0x2, 0x170, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 
    0x3, 0x2, 0x2, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 
    0x7, 0x55, 0x2, 0x2, 0x176, 0x177, 0x5, 0x42, 0x22, 0x2, 0x177, 0x178, 
    0x7, 0x56, 0x2, 0x2, 0x178, 0x179, 0x8, 0x11, 0x1, 0x2, 0x179, 0x17a, 
    0x7, 0x55, 0x2, 0x2, 0x17a, 0x17b, 0x7, 0x53, 0x2, 0x2, 0x17b, 0x17c, 
    0x5, 0x10, 0x9, 0x2, 0x17c, 0x17d, 0x7, 0x51, 0x2, 0x2, 0x17d, 0x17e, 
    0x5, 0x1c, 0xf, 0x2, 0x17e, 0x17f, 0x7, 0x52, 0x2, 0x2, 0x17f, 0x189, 
    0x8, 0x11, 0x1, 0x2, 0x180, 0x181, 0x7, 0x4f, 0x2, 0x2, 0x181, 0x182, 
    0x5, 0x10, 0x9, 0x2, 0x182, 0x183, 0x7, 0x51, 0x2, 0x2, 0x183, 0x184, 
    0x5, 0x1c, 0xf, 0x2, 0x184, 0x185, 0x7, 0x52, 0x2, 0x2, 0x185, 0x186, 
    0x8, 0x11, 0x1, 0x2, 0x186, 0x188, 0x3, 0x2, 0x2, 0x2, 0x187, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x188, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x189, 0x187, 
    0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18c, 
    0x3, 0x2, 0x2, 0x2, 0x18b, 0x189, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 
    0x7, 0x54, 0x2, 0x2, 0x18d, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18f, 
    0x7, 0x55, 0x2, 0x2, 0x18f, 0x190, 0x5, 0x42, 0x22, 0x2, 0x190, 0x191, 
    0x7, 0x56, 0x2, 0x2, 0x191, 0x192, 0x8, 0x11, 0x1, 0x2, 0x192, 0x193, 
    0x7, 0x59, 0x2, 0x2, 0x193, 0x194, 0x7, 0x53, 0x2, 0x2, 0x194, 0x195, 
    0x5, 0x1c, 0xf, 0x2, 0x195, 0x196, 0x7, 0x54, 0x2, 0x2, 0x196, 0x197, 
    0x8, 0x11, 0x1, 0x2, 0x197, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 
    0x7, 0x55, 0x2, 0x2, 0x199, 0x19a, 0x7, 0x56, 0x2, 0x2, 0x19a, 0x1a7, 
    0x8, 0x11, 0x1, 0x2, 0x19b, 0x19c, 0x7, 0x59, 0x2, 0x2, 0x19c, 0x19d, 
    0x5, 0x10, 0x9, 0x2, 0x19d, 0x19e, 0x7, 0x51, 0x2, 0x2, 0x19e, 0x19f, 
    0x5, 0x1c, 0xf, 0x2, 0x19f, 0x1a0, 0x7, 0x52, 0x2, 0x2, 0x1a0, 0x1a1, 
    0x8, 0x11, 0x1, 0x2, 0x1a1, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 
    0x7, 0x59, 0x2, 0x2, 0x1a3, 0x1a4, 0x5, 0x1e, 0x10, 0x2, 0x1a4, 0x1a5, 
    0x8, 0x11, 0x1, 0x2, 0x1a5, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x14b, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x163, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x175, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x18e, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x198, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x19b, 
    0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 
    0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 
    0x5, 0x3e, 0x20, 0x2, 0x1a9, 0x1aa, 0x8, 0x11, 0x1, 0x2, 0x1aa, 0x1ac, 
    0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 
    0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 
    0x7, 0x4e, 0x2, 0x2, 0x1ae, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 
    0x7, 0x6, 0x2, 0x2, 0x1b0, 0x1b1, 0x5, 0x10, 0x9, 0x2, 0x1b1, 0x1b2, 
    0x7, 0x7b, 0x2, 0x2, 0x1b2, 0x208, 0x8, 0x12, 0x1, 0x2, 0x1b3, 0x1b4, 
    0x7, 0x59, 0x2, 0x2, 0x1b4, 0x1b5, 0x5, 0x10, 0x9, 0x2, 0x1b5, 0x1b6, 
    0x7, 0x51, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x1c, 0xf, 0x2, 0x1b7, 0x1b8, 
    0x7, 0x52, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x4e, 0x2, 0x2, 0x1b9, 0x1ba, 
    0x8, 0x12, 0x1, 0x2, 0x1ba, 0x209, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 
    0x7, 0x59, 0x2, 0x2, 0x1bc, 0x1bd, 0x5, 0x1e, 0x10, 0x2, 0x1bd, 0x1be, 
    0x7, 0x4e, 0x2, 0x2, 0x1be, 0x1bf, 0x8, 0x12, 0x1, 0x2, 0x1bf, 0x209, 
    0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 0x7, 0x55, 0x2, 0x2, 0x1c1, 0x1c2, 
    0x7, 0x56, 0x2, 0x2, 0x1c2, 0x1c3, 0x7, 0x59, 0x2, 0x2, 0x1c3, 0x1c4, 
    0x8, 0x12, 0x1, 0x2, 0x1c4, 0x1c5, 0x7, 0x53, 0x2, 0x2, 0x1c5, 0x1c6, 
    0x5, 0x10, 0x9, 0x2, 0x1c6, 0x1c7, 0x7, 0x51, 0x2, 0x2, 0x1c7, 0x1c8, 
    0x5, 0x1c, 0xf, 0x2, 0x1c8, 0x1c9, 0x7, 0x52, 0x2, 0x2, 0x1c9, 0x1d3, 
    0x8, 0x12, 0x1, 0x2, 0x1ca, 0x1cb, 0x7, 0x4f, 0x2, 0x2, 0x1cb, 0x1cc, 
    0x5, 0x10, 0x9, 0x2, 0x1cc, 0x1cd, 0x7, 0x51, 0x2, 0x2, 0x1cd, 0x1ce, 
    0x5, 0x1c, 0xf, 0x2, 0x1ce, 0x1cf, 0x7, 0x52, 0x2, 0x2, 0x1cf, 0x1d0, 
    0x8, 0x12, 0x1, 0x2, 0x1d0, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1d1, 0x1ca, 
    0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d1, 
    0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d6, 
    0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 
    0x7, 0x54, 0x2, 0x2, 0x1d7, 0x1d8, 0x7, 0x4e, 0x2, 0x2, 0x1d8, 0x209, 
    0x3, 0x2, 0x2, 0x2, 0x1d9, 0x1da, 0x7, 0x55, 0x2, 0x2, 0x1da, 0x1db, 
    0x7, 0x56, 0x2, 0x2, 0x1db, 0x1dc, 0x7, 0x59, 0x2, 0x2, 0x1dc, 0x1dd, 
    0x8, 0x12, 0x1, 0x2, 0x1dd, 0x1de, 0x7, 0x53, 0x2, 0x2, 0x1de, 0x1df, 
    0x5, 0x1c, 0xf, 0x2, 0x1df, 0x1e0, 0x7, 0x54, 0x2, 0x2, 0x1e0, 0x1e1, 
    0x8, 0x12, 0x1, 0x2, 0x1e1, 0x1e2, 0x7, 0x4e, 0x2, 0x2, 0x1e2, 0x209, 
    0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 0x7, 0x55, 0x2, 0x2, 0x1e4, 0x1e5, 
    0x5, 0x42, 0x22, 0x2, 0x1e5, 0x1e6, 0x7, 0x56, 0x2, 0x2, 0x1e6, 0x1e7, 
    0x8, 0x12, 0x1, 0x2, 0x1e7, 0x1e8, 0x7, 0x59, 0x2, 0x2, 0x1e8, 0x1e9, 
    0x7, 0x53, 0x2, 0x2, 0x1e9, 0x1ea, 0x5, 0x10, 0x9, 0x2, 0x1ea, 0x1eb, 
    0x7, 0x51, 0x2, 0x2, 0x1eb, 0x1ec, 0x5, 0x1c, 0xf, 0x2, 0x1ec, 0x1ed, 
    0x7, 0x52, 0x2, 0x2, 0x1ed, 0x1f7, 0x8, 0x12, 0x1, 0x2, 0x1ee, 0x1ef, 
    0x7, 0x4f, 0x2, 0x2, 0x1ef, 0x1f0, 0x5, 0x10, 0x9, 0x2, 0x1f0, 0x1f1, 
    0x7, 0x51, 0x2, 0x2, 0x1f1, 0x1f2, 0x5, 0x1c, 0xf, 0x2, 0x1f2, 0x1f3, 
    0x7, 0x52, 0x2, 0x2, 0x1f3, 0x1f4, 0x8, 0x12, 0x1, 0x2, 0x1f4, 0x1f6, 
    0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f9, 
    0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1f8, 
    0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1f7, 
    0x3, 0x2, 0x2, 0x2, 0x1fa, 0x1fb, 0x7, 0x54, 0x2, 0x2, 0x1fb, 0x1fc, 
    0x7, 0x4e, 0x2, 0x2, 0x1fc, 0x209, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 
    0x7, 0x55, 0x2, 0x2, 0x1fe, 0x1ff, 0x5, 0x42, 0x22, 0x2, 0x1ff, 0x200, 
    0x7, 0x56, 0x2, 0x2, 0x200, 0x201, 0x8, 0x12, 0x1, 0x2, 0x201, 0x202, 
    0x7, 0x59, 0x2, 0x2, 0x202, 0x203, 0x7, 0x53, 0x2, 0x2, 0x203, 0x204, 
    0x5, 0x1c, 0xf, 0x2, 0x204, 0x205, 0x7, 0x54, 0x2, 0x2, 0x205, 0x206, 
    0x8, 0x12, 0x1, 0x2, 0x206, 0x207, 0x7, 0x4e, 0x2, 0x2, 0x207, 0x209, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1bb, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1d9, 
    0x3, 0x2, 0x2, 0x2, 0x208, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x208, 0x1fd, 
    0x3, 0x2, 0x2, 0x2, 0x209, 0x23, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x7, 
    0x55, 0x2, 0x2, 0x20b, 0x20c, 0x7, 0x7b, 0x2, 0x2, 0x20c, 0x20d, 0x7, 
    0x56, 0x2, 0x2, 0x20d, 0x20e, 0x8, 0x13, 0x1, 0x2, 0x20e, 0x25, 0x3, 
    0x2, 0x2, 0x2, 0x20f, 0x210, 0x7, 0x55, 0x2, 0x2, 0x210, 0x211, 0x7, 
    0x7b, 0x2, 0x2, 0x211, 0x212, 0x7, 0x56, 0x2, 0x2, 0x212, 0x214, 0x8, 
    0x14, 0x1, 0x2, 0x213, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x3, 
    0x2, 0x2, 0x2, 0x214, 0x220, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x7, 
    0x55, 0x2, 0x2, 0x216, 0x217, 0x7, 0x47, 0x2, 0x2, 0x217, 0x218, 0x7, 
    0x59, 0x2, 0x2, 0x218, 0x219, 0x7, 0x51, 0x2, 0x2, 0x219, 0x21a, 0x5, 
    0x42, 0x22, 0x2, 0x21a, 0x21b, 0x7, 0x4f, 0x2, 0x2, 0x21b, 0x21c, 0x5, 
    0x42, 0x22, 0x2, 0x21c, 0x21d, 0x7, 0x52, 0x2, 0x2, 0x21d, 0x21e, 0x7, 
    0x56, 0x2, 0x2, 0x21e, 0x21f, 0x8, 0x14, 0x1, 0x2, 0x21f, 0x221, 0x3, 
    0x2, 0x2, 0x2, 0x220, 0x215, 0x3, 0x2, 0x2, 0x2, 0x220, 0x221, 0x3, 
    0x2, 0x2, 0x2, 0x221, 0x229, 0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x7, 
    0x55, 0x2, 0x2, 0x223, 0x224, 0x7, 0x48, 0x2, 0x2, 0x224, 0x225, 0x7, 
    0x59, 0x2, 0x2, 0x225, 0x226, 0x5, 0x42, 0x22, 0x2, 0x226, 0x227, 0x7, 
    0x56, 0x2, 0x2, 0x227, 0x228, 0x8, 0x14, 0x1, 0x2, 0x228, 0x22a, 0x3, 
    0x2, 0x2, 0x2, 0x229, 0x222, 0x3, 0x2, 0x2, 0x2, 0x229, 0x22a, 0x3, 
    0x2, 0x2, 0x2, 0x22a, 0x230, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x5, 
    0xc, 0x7, 0x2, 0x22c, 0x22d, 0x8, 0x14, 0x1, 0x2, 0x22d, 0x22f, 0x3, 
    0x2, 0x2, 0x2, 0x22e, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x232, 0x3, 
    0x2, 0x2, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 0x3, 
    0x2, 0x2, 0x2, 0x231, 0x233, 0x3, 0x2, 0x2, 0x2, 0x232, 0x230, 0x3, 
    0x2, 0x2, 0x2, 0x233, 0x234, 0x5, 0x10, 0x9, 0x2, 0x234, 0x235, 0x7, 
    0x7b, 0x2, 0x2, 0x235, 0x23e, 0x8, 0x14, 0x1, 0x2, 0x236, 0x23a, 0x7, 
    0x55, 0x2, 0x2, 0x237, 0x238, 0x5, 0x42, 0x22, 0x2, 0x238, 0x239, 0x8, 
    0x14, 0x1, 0x2, 0x239, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x237, 0x3, 
    0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x3, 
    0x2, 0x2, 0x2, 0x23c, 0x23d, 0x7, 0x56, 0x2, 0x2, 0x23d, 0x23f, 0x8, 
    0x14, 0x1, 0x2, 0x23e, 0x236, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 
    0x2, 0x2, 0x2, 0x23f, 0x27, 0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 0x5, 0x26, 
    0x14, 0x2, 0x241, 0x248, 0x8, 0x15, 0x1, 0x2, 0x242, 0x243, 0x7, 0x4f, 
    0x2, 0x2, 0x243, 0x244, 0x5, 0x26, 0x14, 0x2, 0x244, 0x245, 0x8, 0x15, 
    0x1, 0x2, 0x245, 0x247, 0x3, 0x2, 0x2, 0x2, 0x246, 0x242, 0x3, 0x2, 
    0x2, 0x2, 0x247, 0x24a, 0x3, 0x2, 0x2, 0x2, 0x248, 0x246, 0x3, 0x2, 
    0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24c, 0x3, 0x2, 
    0x2, 0x2, 0x24a, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x240, 0x3, 0x2, 
    0x2, 0x2, 0x24b, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0x24d, 0x24e, 0x7, 0x55, 0x2, 0x2, 0x24e, 0x24f, 0x7, 0x7b, 0x2, 
    0x2, 0x24f, 0x250, 0x7, 0x56, 0x2, 0x2, 0x250, 0x251, 0x7, 0x59, 0x2, 
    0x2, 0x251, 0x252, 0x5, 0x42, 0x22, 0x2, 0x252, 0x253, 0x8, 0x16, 0x1, 
    0x2, 0x253, 0x259, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x7, 0x55, 0x2, 
    0x2, 0x255, 0x256, 0x7, 0x7b, 0x2, 0x2, 0x256, 0x257, 0x7, 0x56, 0x2, 
    0x2, 0x257, 0x259, 0x8, 0x16, 0x1, 0x2, 0x258, 0x24d, 0x3, 0x2, 0x2, 
    0x2, 0x258, 0x254, 0x3, 0x2, 0x2, 0x2, 0x259, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x25a, 0x25e, 0x7, 0x53, 0x2, 0x2, 0x25b, 0x25d, 0x5, 0x2c, 0x17, 0x2, 
    0x25c, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x260, 0x3, 0x2, 0x2, 0x2, 
    0x25e, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x25f, 0x261, 0x3, 0x2, 0x2, 0x2, 0x260, 0x25e, 0x3, 0x2, 0x2, 0x2, 
    0x261, 0x264, 0x7, 0x54, 0x2, 0x2, 0x262, 0x264, 0xa, 0x6, 0x2, 0x2, 
    0x263, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x263, 0x262, 0x3, 0x2, 0x2, 0x2, 
    0x264, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x5, 0x2a, 0x16, 0x2, 
    0x266, 0x267, 0x8, 0x18, 0x1, 0x2, 0x267, 0x269, 0x3, 0x2, 0x2, 0x2, 
    0x268, 0x265, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26c, 0x3, 0x2, 0x2, 0x2, 
    0x26a, 0x268, 0x3, 0x2, 0x2, 0x2, 0x26a, 0x26b, 0x3, 0x2, 0x2, 0x2, 
    0x26b, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26a, 0x3, 0x2, 0x2, 0x2, 
    0x26d, 0x26e, 0x7, 0x49, 0x2, 0x2, 0x26e, 0x270, 0x8, 0x18, 0x1, 0x2, 
    0x26f, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x270, 0x3, 0x2, 0x2, 0x2, 
    0x270, 0x271, 0x3, 0x2, 0x2, 0x2, 0x271, 0x272, 0x5, 0x10, 0x9, 0x2, 
    0x272, 0x273, 0x7, 0x7b, 0x2, 0x2, 0x273, 0x274, 0x8, 0x18, 0x1, 0x2, 
    0x274, 0x275, 0x7, 0x51, 0x2, 0x2, 0x275, 0x276, 0x5, 0x28, 0x15, 0x2, 
    0x276, 0x277, 0x7, 0x52, 0x2, 0x2, 0x277, 0x278, 0x8, 0x18, 0x1, 0x2, 
    0x278, 0x279, 0x5, 0x2c, 0x17, 0x2, 0x279, 0x27a, 0x8, 0x18, 0x1, 0x2, 
    0x27a, 0x27b, 0x8, 0x18, 0x1, 0x2, 0x27b, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x27c, 0x27d, 0x7, 0x7b, 0x2, 0x2, 0x27d, 0x27e, 0x7, 0x55, 0x2, 0x2, 
    0x27e, 0x27f, 0x5, 0x42, 0x22, 0x2, 0x27f, 0x280, 0x7, 0x56, 0x2, 0x2, 
    0x280, 0x281, 0x7, 0x59, 0x2, 0x2, 0x281, 0x282, 0x5, 0x42, 0x22, 0x2, 
    0x282, 0x283, 0x7, 0x4e, 0x2, 0x2, 0x283, 0x284, 0x8, 0x19, 0x1, 0x2, 
    0x284, 0x31, 0x3, 0x2, 0x2, 0x2, 0x285, 0x286, 0x7, 0x7b, 0x2, 0x2, 
    0x286, 0x287, 0x7, 0x59, 0x2, 0x2, 0x287, 0x288, 0x5, 0x42, 0x22, 0x2, 
    0x288, 0x289, 0x7, 0x4e, 0x2, 0x2, 0x289, 0x28a, 0x8, 0x1a, 0x1, 0x2, 
    0x28a, 0x33, 0x3, 0x2, 0x2, 0x2, 0x28b, 0x28c, 0x7, 0x4a, 0x2, 0x2, 
    0x28c, 0x28d, 0x7, 0x7b, 0x2, 0x2, 0x28d, 0x28e, 0x8, 0x1b, 0x1, 0x2, 
    0x28e, 0x28f, 0x7, 0x4e, 0x2, 0x2, 0x28f, 0x2a3, 0x8, 0x1b, 0x1, 0x2, 
    0x290, 0x291, 0x7, 0x4a, 0x2, 0x2, 0x291, 0x292, 0x7, 0x7b, 0x2, 0x2, 
    0x292, 0x293, 0x8, 0x1b, 0x1, 0x2, 0x293, 0x294, 0x7, 0x53, 0x2, 0x2, 
    0x294, 0x29d, 0x8, 0x1b, 0x1, 0x2, 0x295, 0x296, 0x5, 0x32, 0x1a, 0x2, 
    0x296, 0x297, 0x8, 0x1b, 0x1, 0x2, 0x297, 0x29c, 0x3, 0x2, 0x2, 0x2, 
    0x298, 0x299, 0x5, 0x30, 0x19, 0x2, 0x299, 0x29a, 0x8, 0x1b, 0x1, 0x2, 
    0x29a, 0x29c, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x295, 0x3, 0x2, 0x2, 0x2, 
    0x29b, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29f, 0x3, 0x2, 0x2, 0x2, 
    0x29d, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x3, 0x2, 0x2, 0x2, 
    0x29e, 0x2a0, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x29d, 0x3, 0x2, 0x2, 0x2, 
    0x2a0, 0x2a1, 0x7, 0x54, 0x2, 0x2, 0x2a1, 0x2a3, 0x7, 0x4e, 0x2, 0x2, 
    0x2a2, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x290, 0x3, 0x2, 0x2, 0x2, 
    0x2a3, 0x35, 0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x5, 0xc, 0x7, 0x2, 0x2a5, 
    0x2a6, 0x8, 0x1c, 0x1, 0x2, 0x2a6, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
    0x2a8, 0x5, 0x12, 0xa, 0x2, 0x2a8, 0x2a9, 0x8, 0x1c, 0x1, 0x2, 0x2a9, 
    0x2ab, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2aa, 
    0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2ab, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2ac, 
    0x2aa, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2ad, 0x3, 0x2, 0x2, 0x2, 0x2ad, 
    0x2af, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2af, 
    0x2b0, 0x7, 0x4b, 0x2, 0x2, 0x2b0, 0x2b1, 0x7, 0x7b, 0x2, 0x2, 0x2b1, 
    0x2b2, 0x8, 0x1c, 0x1, 0x2, 0x2b2, 0x2b3, 0x7, 0x4e, 0x2, 0x2, 0x2b3, 
    0x2cf, 0x8, 0x1c, 0x1, 0x2, 0x2b4, 0x2b5, 0x5, 0xc, 0x7, 0x2, 0x2b5, 
    0x2b6, 0x8, 0x1c, 0x1, 0x2, 0x2b6, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2b7, 
    0x2b8, 0x5, 0x12, 0xa, 0x2, 0x2b8, 0x2b9, 0x8, 0x1c, 0x1, 0x2, 0x2b9, 
    0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2ba, 
    0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2bb, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2bc, 
    0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
    0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2bf, 
    0x2c0, 0x7, 0x4b, 0x2, 0x2, 0x2c0, 0x2c1, 0x7, 0x7b, 0x2, 0x2, 0x2c1, 
    0x2c2, 0x8, 0x1c, 0x1, 0x2, 0x2c2, 0x2c3, 0x8, 0x1c, 0x1, 0x2, 0x2c3, 
    0x2c9, 0x7, 0x53, 0x2, 0x2, 0x2c4, 0x2c5, 0x5, 0x3a, 0x1e, 0x2, 0x2c5, 
    0x2c6, 0x8, 0x1c, 0x1, 0x2, 0x2c6, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2c7, 
    0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c8, 0x2cb, 0x3, 0x2, 0x2, 0x2, 0x2c9, 
    0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2ca, 
    0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
    0x2cd, 0x7, 0x54, 0x2, 0x2, 0x2cd, 0x2cf, 0x7, 0x4e, 0x2, 0x2, 0x2ce, 
    0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2cf, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x7, 0x7b, 0x2, 0x2, 0x2d1, 
    0x2d7, 0x8, 0x1d, 0x1, 0x2, 0x2d2, 0x2d3, 0x7, 0x4f, 0x2, 0x2, 0x2d3, 
    0x2d4, 0x7, 0x7b, 0x2, 0x2, 0x2d4, 0x2d6, 0x8, 0x1d, 0x1, 0x2, 0x2d5, 
    0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d7, 
    0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2d8, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2db, 
    0x7, 0x7b, 0x2, 0x2, 0x2db, 0x2dc, 0x7, 0x59, 0x2, 0x2, 0x2dc, 0x2dd, 
    0x7, 0x7b, 0x2, 0x2, 0x2dd, 0x2de, 0x7, 0x4e, 0x2, 0x2, 0x2de, 0x2ee, 
    0x8, 0x1e, 0x1, 0x2, 0x2df, 0x2e0, 0x7, 0x7b, 0x2, 0x2, 0x2e0, 0x2e1, 
    0x7, 0x59, 0x2, 0x2, 0x2e1, 0x2e2, 0x5, 0x42, 0x22, 0x2, 0x2e2, 0x2e3, 
    0x7, 0x4e, 0x2, 0x2, 0x2e3, 0x2e4, 0x8, 0x1e, 0x1, 0x2, 0x2e4, 0x2ee, 
    0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 0x7, 0x7b, 0x2, 0x2, 0x2e6, 0x2e7, 
    0x7, 0x59, 0x2, 0x2, 0x2e7, 0x2e8, 0x7, 0x53, 0x2, 0x2, 0x2e8, 0x2e9, 
    0x5, 0x38, 0x1d, 0x2, 0x2e9, 0x2ea, 0x7, 0x54, 0x2, 0x2, 0x2ea, 0x2eb, 
    0x7, 0x4e, 0x2, 0x2, 0x2eb, 0x2ec, 0x8, 0x1e, 0x1, 0x2, 0x2ec, 0x2ee, 
    0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2df, 
    0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2ee, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x2ef, 0x2f0, 0x7, 0x7b, 0x2, 0x2, 0x2f0, 0x2f1, 0x7, 
    0x59, 0x2, 0x2, 0x2f1, 0x2f2, 0x7, 0x7b, 0x2, 0x2, 0x2f2, 0x2f7, 0x7, 
    0x51, 0x2, 0x2, 0x2f3, 0x2f4, 0x7, 0x7b, 0x2, 0x2, 0x2f4, 0x2f5, 0x7, 
    0x59, 0x2, 0x2, 0x2f5, 0x2f6, 0x7, 0x7b, 0x2, 0x2, 0x2f6, 0x2f8, 0x8, 
    0x1f, 0x1, 0x2, 0x2f7, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 
    0x2, 0x2, 0x2, 0x2f8, 0x300, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fa, 0x7, 
    0x4f, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x7b, 0x2, 0x2, 0x2fb, 0x2fc, 0x7, 
    0x59, 0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0x7b, 0x2, 0x2, 0x2fd, 0x2ff, 0x8, 
    0x1f, 0x1, 0x2, 0x2fe, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x302, 0x3, 
    0x2, 0x2, 0x2, 0x300, 0x2fe, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x3, 
    0x2, 0x2, 0x2, 0x301, 0x303, 0x3, 0x2, 0x2, 0x2, 0x302, 0x300, 0x3, 
    0x2, 0x2, 0x2, 0x303, 0x304, 0x7, 0x52, 0x2, 0x2, 0x304, 0x305, 0x7, 
    0x4e, 0x2, 0x2, 0x305, 0x30c, 0x8, 0x1f, 0x1, 0x2, 0x306, 0x307, 0x7, 
    0x4c, 0x2, 0x2, 0x307, 0x308, 0x7, 0x59, 0x2, 0x2, 0x308, 0x309, 0x7, 
    0x7b, 0x2, 0x2, 0x309, 0x30a, 0x7, 0x4e, 0x2, 0x2, 0x30a, 0x30c, 0x8, 
    0x1f, 0x1, 0x2, 0x30b, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x306, 0x3, 
    0x2, 0x2, 0x2, 0x30c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x31e, 0x7, 0x55, 
    0x2, 0x2, 0x30e, 0x30f, 0x5, 0x10, 0x9, 0x2, 0x30f, 0x310, 0x7, 0x7b, 
    0x2, 0x2, 0x310, 0x317, 0x7, 0x59, 0x2, 0x2, 0x311, 0x312, 0x5, 0x2, 
    0x2, 0x2, 0x312, 0x313, 0x8, 0x20, 0x1, 0x2, 0x313, 0x318, 0x3, 0x2, 
    0x2, 0x2, 0x314, 0x315, 0x5, 0x42, 0x22, 0x2, 0x315, 0x316, 0x8, 0x20, 
    0x1, 0x2, 0x316, 0x318, 0x3, 0x2, 0x2, 0x2, 0x317, 0x311, 0x3, 0x2, 
    0x2, 0x2, 0x317, 0x314, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 0x3, 0x2, 
    0x2, 0x2, 0x319, 0x31a, 0x7, 0x4e, 0x2, 0x2, 0x31a, 0x31b, 0x8, 0x20, 
    0x1, 0x2, 0x31b, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x30e, 0x3, 0x2, 
    0x2, 0x2, 0x31d, 0x320, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x31c, 0x3, 0x2, 
    0x2, 0x2, 0x31e, 0x31f, 0x3, 0x2, 0x2, 0x2, 0x31f, 0x321, 0x3, 0x2, 
    0x2, 0x2, 0x320, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x321, 0x322, 0x7, 0x56, 
    0x2, 0x2, 0x322, 0x323, 0x8, 0x20, 0x1, 0x2, 0x323, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x324, 0x325, 0x7, 0x4d, 0x2, 0x2, 0x325, 0x326, 0x7, 0x7b, 
    0x2, 0x2, 0x326, 0x32a, 0x8, 0x21, 0x1, 0x2, 0x327, 0x328, 0x5, 0x3e, 
    0x20, 0x2, 0x328, 0x329, 0x8, 0x21, 0x1, 0x2, 0x329, 0x32b, 0x3, 0x2, 
    0x2, 0x2, 0x32a, 0x327, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32b, 0x3, 0x2, 
    0x2, 0x2, 0x32b, 0x32c, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32d, 0x7, 0x53, 
    0x2, 0x2, 0x32d, 0x333, 0x8, 0x21, 0x1, 0x2, 0x32e, 0x32f, 0x5, 0x3c, 
    0x1f, 0x2, 0x32f, 0x330, 0x8, 0x21, 0x1, 0x2, 0x330, 0x332, 0x3, 0x2, 
    0x2, 0x2, 0x331, 0x32e, 0x3, 0x2, 0x2, 0x2, 0x332, 0x335, 0x3, 0x2, 
    0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x333, 0x334, 0x3, 0x2, 
    0x2, 0x2, 0x334, 0x336, 0x3, 0x2, 0x2, 0x2, 0x335, 0x333, 0x3, 0x2, 
    0x2, 0x2, 0x336, 0x337, 0x7, 0x54, 0x2, 0x2, 0x337, 0x338, 0x7, 0x4e, 
    0x2, 0x2, 0x338, 0x41, 0x3, 0x2, 0x2, 0x2, 0x339, 0x33a, 0x5, 0x44, 
    0x23, 0x2, 0x33a, 0x33b, 0x8, 0x22, 0x1, 0x2, 0x33b, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x33c, 0x33d, 0x5, 0x46, 0x24, 0x2, 0x33d, 0x344, 0x8, 0x23, 
    0x1, 0x2, 0x33e, 0x33f, 0x7, 0x6d, 0x2, 0x2, 0x33f, 0x340, 0x5, 0x46, 
    0x24, 0x2, 0x340, 0x341, 0x8, 0x23, 0x1, 0x2, 0x341, 0x343, 0x3, 0x2, 
    0x2, 0x2, 0x342, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x343, 0x346, 0x3, 0x2, 
    0x2, 0x2, 0x344, 0x342, 0x3, 0x2, 0x2, 0x2, 0x344, 0x345, 0x3, 0x2, 
    0x2, 0x2, 0x345, 0x45, 0x3, 0x2, 0x2, 0x2, 0x346, 0x344, 0x3, 0x2, 0x2, 
    0x2, 0x347, 0x348, 0x5, 0x48, 0x25, 0x2, 0x348, 0x34f, 0x8, 0x24, 0x1, 
    0x2, 0x349, 0x34a, 0x7, 0x6c, 0x2, 0x2, 0x34a, 0x34b, 0x5, 0x48, 0x25, 
    0x2, 0x34b, 0x34c, 0x8, 0x24, 0x1, 0x2, 0x34c, 0x34e, 0x3, 0x2, 0x2, 
    0x2, 0x34d, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x351, 0x3, 0x2, 0x2, 
    0x2, 0x34f, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34f, 0x350, 0x3, 0x2, 0x2, 
    0x2, 0x350, 0x47, 0x3, 0x2, 0x2, 0x2, 0x351, 0x34f, 0x3, 0x2, 0x2, 0x2, 
    0x352, 0x353, 0x5, 0x4a, 0x26, 0x2, 0x353, 0x35a, 0x8, 0x25, 0x1, 0x2, 
    0x354, 0x355, 0x9, 0x7, 0x2, 0x2, 0x355, 0x356, 0x5, 0x4a, 0x26, 0x2, 
    0x356, 0x357, 0x8, 0x25, 0x1, 0x2, 0x357, 0x359, 0x3, 0x2, 0x2, 0x2, 
    0x358, 0x354, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35c, 0x3, 0x2, 0x2, 0x2, 
    0x35a, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35a, 0x35b, 0x3, 0x2, 0x2, 0x2, 
    0x35b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35d, 
    0x35e, 0x5, 0x4c, 0x27, 0x2, 0x35e, 0x365, 0x8, 0x26, 0x1, 0x2, 0x35f, 
    0x360, 0x9, 0x8, 0x2, 0x2, 0x360, 0x361, 0x5, 0x4c, 0x27, 0x2, 0x361, 
    0x362, 0x8, 0x26, 0x1, 0x2, 0x362, 0x364, 0x3, 0x2, 0x2, 0x2, 0x363, 
    0x35f, 0x3, 0x2, 0x2, 0x2, 0x364, 0x367, 0x3, 0x2, 0x2, 0x2, 0x365, 
    0x363, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x367, 0x365, 0x3, 0x2, 0x2, 0x2, 0x368, 0x369, 
    0x5, 0x4e, 0x28, 0x2, 0x369, 0x370, 0x8, 0x27, 0x1, 0x2, 0x36a, 0x36b, 
    0x9, 0x9, 0x2, 0x2, 0x36b, 0x36c, 0x5, 0x4e, 0x28, 0x2, 0x36c, 0x36d, 
    0x8, 0x27, 0x1, 0x2, 0x36d, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36a, 
    0x3, 0x2, 0x2, 0x2, 0x36f, 0x372, 0x3, 0x2, 0x2, 0x2, 0x370, 0x36e, 
    0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x3, 0x2, 0x2, 0x2, 0x371, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x372, 0x370, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x5, 
    0x50, 0x29, 0x2, 0x374, 0x37b, 0x8, 0x28, 0x1, 0x2, 0x375, 0x376, 0x9, 
    0xa, 0x2, 0x2, 0x376, 0x377, 0x5, 0x50, 0x29, 0x2, 0x377, 0x378, 0x8, 
    0x28, 0x1, 0x2, 0x378, 0x37a, 0x3, 0x2, 0x2, 0x2, 0x379, 0x375, 0x3, 
    0x2, 0x2, 0x2, 0x37a, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x379, 0x3, 
    0x2, 0x2, 0x2, 0x37b, 0x37c, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x380, 0x9, 0xb, 
    0x2, 0x2, 0x37f, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x380, 0x3, 0x2, 
    0x2, 0x2, 0x380, 0x381, 0x3, 0x2, 0x2, 0x2, 0x381, 0x382, 0x5, 0x52, 
    0x2a, 0x2, 0x382, 0x383, 0x8, 0x29, 0x1, 0x2, 0x383, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x384, 0x385, 0x7, 0x74, 0x2, 0x2, 0x385, 0x395, 0x8, 0x2a, 
    0x1, 0x2, 0x386, 0x387, 0x7, 0x77, 0x2, 0x2, 0x387, 0x395, 0x8, 0x2a, 
    0x1, 0x2, 0x388, 0x389, 0x7, 0x79, 0x2, 0x2, 0x389, 0x395, 0x8, 0x2a, 
    0x1, 0x2, 0x38a, 0x38b, 0x7, 0x7a, 0x2, 0x2, 0x38b, 0x395, 0x8, 0x2a, 
    0x1, 0x2, 0x38c, 0x38d, 0x7, 0x7b, 0x2, 0x2, 0x38d, 0x395, 0x8, 0x2a, 
    0x1, 0x2, 0x38e, 0x38f, 0x5, 0x4, 0x3, 0x2, 0x38f, 0x390, 0x8, 0x2a, 
    0x1, 0x2, 0x390, 0x395, 0x3, 0x2, 0x2, 0x2, 0x391, 0x392, 0x5, 0x54, 
    0x2b, 0x2, 0x392, 0x393, 0x8, 0x2a, 0x1, 0x2, 0x393, 0x395, 0x3, 0x2, 
    0x2, 0x2, 0x394, 0x384, 0x3, 0x2, 0x2, 0x2, 0x394, 0x386, 0x3, 0x2, 
    0x2, 0x2, 0x394, 0x388, 0x3, 0x2, 0x2, 0x2, 0x394, 0x38a, 0x3, 0x2, 
    0x2, 0x2, 0x394, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x394, 0x38e, 0x3, 0x2, 
    0x2, 0x2, 0x394, 0x391, 0x3, 0x2, 0x2, 0x2, 0x395, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x396, 0x397, 0x7, 0x51, 0x2, 0x2, 0x397, 0x398, 0x5, 0x42, 0x22, 
    0x2, 0x398, 0x399, 0x7, 0x52, 0x2, 0x2, 0x399, 0x39a, 0x8, 0x2b, 0x1, 
    0x2, 0x39a, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x5b, 0x64, 0x68, 0x6e, 
    0x77, 0x79, 0xa0, 0xa2, 0xba, 0xc7, 0xc9, 0xd2, 0xda, 0xe8, 0xea, 0xf4, 
    0xf6, 0xff, 0x107, 0x115, 0x117, 0x12d, 0x137, 0x143, 0x145, 0x15e, 
    0x173, 0x189, 0x1a6, 0x1ab, 0x1d3, 0x1f7, 0x208, 0x213, 0x220, 0x229, 
    0x230, 0x23a, 0x23e, 0x248, 0x24b, 0x258, 0x25e, 0x263, 0x26a, 0x26f, 
    0x29b, 0x29d, 0x2a2, 0x2aa, 0x2ac, 0x2ba, 0x2bc, 0x2c9, 0x2ce, 0x2d7, 
    0x2ed, 0x2f7, 0x300, 0x30b, 0x317, 0x31e, 0x32a, 0x333, 0x344, 0x34f, 
    0x35a, 0x365, 0x370, 0x37b, 0x37f, 0x394, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AnyFXParser::Initializer AnyFXParser::_init;
