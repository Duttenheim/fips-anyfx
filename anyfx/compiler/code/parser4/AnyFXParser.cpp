

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



// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.13.2


#include "AnyFXListener.h"

#include "AnyFXParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AnyFXParserStaticData final {
  AnyFXParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AnyFXParserStaticData(const AnyFXParserStaticData&) = delete;
  AnyFXParserStaticData(AnyFXParserStaticData&&) = delete;
  AnyFXParserStaticData& operator=(const AnyFXParserStaticData&) = delete;
  AnyFXParserStaticData& operator=(AnyFXParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag anyfxParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<AnyFXParserStaticData> anyfxParserStaticData = nullptr;

void anyfxParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (anyfxParserStaticData != nullptr) {
    return;
  }
#else
  assert(anyfxParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AnyFXParserStaticData>(
    std::vector<std::string>{
      "string", "boolean", "preprocess", "entry", "effect", "type", "qualifierExpression", 
      "structure", "varblock", "varbuffer", "subroutine", "valueList", "valueSingleList", 
      "variable", "parameter", "parameterList", "functionAttribute", "codeBlock", 
      "function", "blendStateRow", "renderStateRow", "renderState", "sampler", 
      "samplerTextureList", "samplerRow", "programRow", "annotation", "program", 
      "expression", "binaryexp7", "binaryexp6", "binaryexp5", "binaryexp4", 
      "binaryexp3", "binaryexp2", "binaryexp1", "binaryexpatom", "parantexpression"
    },
    std::vector<std::string>{
      "", "'true'", "'false'", "'#line'", "'struct'", "'constant'", "'rw_buffer'", 
      "'prototype'", "'subroutine'", "'feedback'", "'slot'", "'shader'", 
      "'render_state'", "'sampler_state'", "'RenderState'", "'program'", 
      "';'", "','", "':'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'.'", 
      "'!'", "'='", "'\"'", "'\\u003F'", "'&'", "'&='", "'|'", "'|='", "'^'", 
      "'^='", "'~'", "'''", "'#'", "'\\'", "'<'", "'<='", "'>'", "'>='", 
      "'=='", "'!='", "'&&'", "'||'", "'%'", "'_'", "'+'", "'-'", "'/'", 
      "'*'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "SC", 
      "CO", "COL", "LP", "RP", "LB", "RB", "LL", "RR", "DOT", "NOT", "EQ", 
      "QO", "QU", "AND", "ANDSET", "OR", "ORSET", "XOR", "XORSET", "CONNJUGATE", 
      "Q", "NU", "FORWARDSLASH", "LESS", "LESSEQ", "GREATER", "GREATEREQ", 
      "LOGICEQ", "NOTEQ", "LOGICAND", "LOGICOR", "MOD", "UNDERSC", "ADD_OP", 
      "SUB_OP", "DIV_OP", "MUL_OP", "INTEGERLITERAL", "COMMENT", "ML_COMMENT", 
      "FLOATLITERAL", "EXPONENT", "DOUBLELITERAL", "HEX", "IDENTIFIER", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,62,815,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,1,0,1,0,5,0,80,8,0,10,0,12,0,83,9,0,1,0,1,
  	0,1,0,1,0,5,0,89,8,0,10,0,12,0,92,9,0,1,0,3,0,95,8,0,1,1,1,1,1,1,1,1,
  	3,1,101,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,110,8,2,10,2,12,2,113,9,2,
  	1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,5,4,148,
  	8,4,10,4,12,4,151,9,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,
  	5,7,165,8,7,10,7,12,7,168,9,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,4,7,178,
  	8,7,11,7,12,7,179,1,7,1,7,3,7,184,8,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,
  	5,8,194,8,8,10,8,12,8,197,9,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,205,8,8,1,8,
  	1,8,1,8,1,8,5,8,211,8,8,10,8,12,8,214,9,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,3,8,227,8,8,3,8,229,8,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,5,
  	9,238,8,9,10,9,12,9,241,9,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,249,8,9,1,9,1,
  	9,1,9,1,9,4,9,255,8,9,11,9,12,9,256,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,3,9,270,8,9,3,9,272,8,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,292,8,10,1,
  	11,1,11,1,11,1,11,1,11,1,11,5,11,300,8,11,10,11,12,11,303,9,11,1,12,1,
  	12,1,12,1,13,1,13,1,13,1,13,1,13,5,13,313,8,13,10,13,12,13,316,9,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,5,13,338,8,13,10,13,12,13,341,9,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,4,13,359,8,13,11,13,12,13,360,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,391,8,13,10,13,12,13,394,9,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,3,13,412,8,13,1,13,1,13,1,13,3,13,417,8,13,1,13,1,13,1,14,1,14,
  	1,14,1,14,3,14,425,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,3,14,438,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,447,8,
  	14,1,14,1,14,5,14,451,8,14,10,14,12,14,454,9,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,3,14,463,8,14,1,14,1,14,3,14,467,8,14,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,5,15,476,8,15,10,15,12,15,479,9,15,3,15,481,8,15,1,15,
  	1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,496,
  	8,16,1,17,1,17,5,17,500,8,17,10,17,12,17,503,9,17,1,17,1,17,3,17,507,
  	8,17,1,18,1,18,1,18,5,18,512,8,18,10,18,12,18,515,9,18,1,18,1,18,3,18,
  	519,8,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	5,21,561,8,21,10,21,12,21,564,9,21,1,21,1,21,3,21,568,8,21,1,22,1,22,
  	1,22,1,22,1,22,5,22,575,8,22,10,22,12,22,578,9,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,5,22,590,8,22,10,22,12,22,593,9,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,603,8,22,10,22,12,22,606,9,22,
  	1,22,1,22,3,22,610,8,22,1,23,1,23,1,23,1,23,1,23,5,23,617,8,23,10,23,
  	12,23,620,9,23,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,24,1,24,3,24,641,8,24,1,25,1,25,1,25,
  	1,25,1,25,1,25,1,25,1,25,3,25,651,8,25,1,25,1,25,1,25,1,25,1,25,5,25,
  	658,8,25,10,25,12,25,661,9,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,25,
  	3,25,671,8,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,1,26,3,26,
  	683,8,26,1,26,1,26,1,26,5,26,688,8,26,10,26,12,26,691,9,26,1,26,1,26,
  	1,26,1,27,1,27,1,27,1,27,1,27,1,27,3,27,702,8,27,1,27,1,27,1,27,1,27,
  	1,27,5,27,709,8,27,10,27,12,27,712,9,27,1,27,1,27,1,27,1,28,1,28,1,28,
  	1,29,1,29,1,29,1,29,1,29,1,29,5,29,726,8,29,10,29,12,29,729,9,29,1,30,
  	1,30,1,30,1,30,1,30,1,30,5,30,737,8,30,10,30,12,30,740,9,30,1,31,1,31,
  	1,31,1,31,1,31,1,31,5,31,748,8,31,10,31,12,31,751,9,31,1,32,1,32,1,32,
  	1,32,1,32,1,32,5,32,759,8,32,10,32,12,32,762,9,32,1,33,1,33,1,33,1,33,
  	1,33,1,33,5,33,770,8,33,10,33,12,33,773,9,33,1,34,1,34,1,34,1,34,1,34,
  	1,34,5,34,781,8,34,10,34,12,34,784,9,34,1,35,3,35,787,8,35,1,35,1,35,
  	1,35,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,1,36,
  	1,36,1,36,1,36,3,36,808,8,36,1,37,1,37,1,37,1,37,1,37,1,37,2,111,149,
  	0,38,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,0,8,1,0,28,28,1,0,37,37,
  	1,0,21,22,1,0,44,45,1,0,40,43,1,0,50,51,1,0,52,53,2,0,26,26,51,51,870,
  	0,94,1,0,0,0,2,100,1,0,0,0,4,111,1,0,0,0,6,116,1,0,0,0,8,149,1,0,0,0,
  	10,152,1,0,0,0,12,155,1,0,0,0,14,166,1,0,0,0,16,195,1,0,0,0,18,239,1,
  	0,0,0,20,291,1,0,0,0,22,293,1,0,0,0,24,304,1,0,0,0,26,314,1,0,0,0,28,
  	424,1,0,0,0,30,468,1,0,0,0,32,495,1,0,0,0,34,506,1,0,0,0,36,513,1,0,0,
  	0,38,529,1,0,0,0,40,538,1,0,0,0,42,567,1,0,0,0,44,609,1,0,0,0,46,611,
  	1,0,0,0,48,640,1,0,0,0,50,670,1,0,0,0,52,672,1,0,0,0,54,695,1,0,0,0,56,
  	716,1,0,0,0,58,719,1,0,0,0,60,730,1,0,0,0,62,741,1,0,0,0,64,752,1,0,0,
  	0,66,763,1,0,0,0,68,774,1,0,0,0,70,786,1,0,0,0,72,807,1,0,0,0,74,809,
  	1,0,0,0,76,81,5,28,0,0,77,78,8,0,0,0,78,80,6,0,-1,0,79,77,1,0,0,0,80,
  	83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,83,81,1,0,0,0,84,
  	95,5,28,0,0,85,90,5,37,0,0,86,87,8,1,0,0,87,89,6,0,-1,0,88,86,1,0,0,0,
  	89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,93,1,0,0,0,92,90,1,0,0,0,
  	93,95,5,37,0,0,94,76,1,0,0,0,94,85,1,0,0,0,95,1,1,0,0,0,96,97,5,1,0,0,
  	97,101,6,1,-1,0,98,99,5,2,0,0,99,101,6,1,-1,0,100,96,1,0,0,0,100,98,1,
  	0,0,0,101,3,1,0,0,0,102,103,6,2,-1,0,103,104,5,3,0,0,104,105,5,54,0,0,
  	105,106,3,0,0,0,106,107,6,2,-1,0,107,110,1,0,0,0,108,110,9,0,0,0,109,
  	102,1,0,0,0,109,108,1,0,0,0,110,113,1,0,0,0,111,112,1,0,0,0,111,109,1,
  	0,0,0,112,114,1,0,0,0,113,111,1,0,0,0,114,115,5,0,0,1,115,5,1,0,0,0,116,
  	117,3,8,4,0,117,118,6,3,-1,0,118,119,5,0,0,1,119,7,1,0,0,0,120,121,3,
  	26,13,0,121,122,6,4,-1,0,122,148,1,0,0,0,123,124,3,42,21,0,124,125,6,
  	4,-1,0,125,148,1,0,0,0,126,127,3,36,18,0,127,128,6,4,-1,0,128,148,1,0,
  	0,0,129,130,3,54,27,0,130,131,6,4,-1,0,131,148,1,0,0,0,132,133,3,14,7,
  	0,133,134,6,4,-1,0,134,148,1,0,0,0,135,136,3,16,8,0,136,137,6,4,-1,0,
  	137,148,1,0,0,0,138,139,3,18,9,0,139,140,6,4,-1,0,140,148,1,0,0,0,141,
  	142,3,20,10,0,142,143,6,4,-1,0,143,148,1,0,0,0,144,145,3,44,22,0,145,
  	146,6,4,-1,0,146,148,1,0,0,0,147,120,1,0,0,0,147,123,1,0,0,0,147,126,
  	1,0,0,0,147,129,1,0,0,0,147,132,1,0,0,0,147,135,1,0,0,0,147,138,1,0,0,
  	0,147,141,1,0,0,0,147,144,1,0,0,0,148,151,1,0,0,0,149,150,1,0,0,0,149,
  	147,1,0,0,0,150,9,1,0,0,0,151,149,1,0,0,0,152,153,5,61,0,0,153,154,6,
  	5,-1,0,154,11,1,0,0,0,155,156,5,61,0,0,156,157,3,74,37,0,157,158,6,6,
  	-1,0,158,13,1,0,0,0,159,160,5,61,0,0,160,165,6,7,-1,0,161,162,3,12,6,
  	0,162,163,6,7,-1,0,163,165,1,0,0,0,164,159,1,0,0,0,164,161,1,0,0,0,165,
  	168,1,0,0,0,166,164,1,0,0,0,166,167,1,0,0,0,167,169,1,0,0,0,168,166,1,
  	0,0,0,169,170,5,4,0,0,170,171,5,61,0,0,171,183,6,7,-1,0,172,177,5,21,
  	0,0,173,174,3,28,14,0,174,175,5,16,0,0,175,176,6,7,-1,0,176,178,1,0,0,
  	0,177,173,1,0,0,0,178,179,1,0,0,0,179,177,1,0,0,0,179,180,1,0,0,0,180,
  	181,1,0,0,0,181,182,5,22,0,0,182,184,1,0,0,0,183,172,1,0,0,0,183,184,
  	1,0,0,0,184,185,1,0,0,0,185,186,5,16,0,0,186,187,6,7,-1,0,187,15,1,0,
  	0,0,188,189,5,61,0,0,189,194,6,8,-1,0,190,191,3,12,6,0,191,192,6,8,-1,
  	0,192,194,1,0,0,0,193,188,1,0,0,0,193,190,1,0,0,0,194,197,1,0,0,0,195,
  	193,1,0,0,0,195,196,1,0,0,0,196,198,1,0,0,0,197,195,1,0,0,0,198,199,5,
  	5,0,0,199,200,5,61,0,0,200,204,6,8,-1,0,201,202,3,52,26,0,202,203,6,8,
  	-1,0,203,205,1,0,0,0,204,201,1,0,0,0,204,205,1,0,0,0,205,206,1,0,0,0,
  	206,212,5,21,0,0,207,208,3,26,13,0,208,209,6,8,-1,0,209,211,1,0,0,0,210,
  	207,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,1,0,0,0,213,215,1,
  	0,0,0,214,212,1,0,0,0,215,228,5,22,0,0,216,217,5,61,0,0,217,226,6,8,-1,
  	0,218,219,5,23,0,0,219,220,5,24,0,0,220,227,6,8,-1,0,221,222,5,23,0,0,
  	222,223,3,56,28,0,223,224,5,24,0,0,224,225,6,8,-1,0,225,227,1,0,0,0,226,
  	218,1,0,0,0,226,221,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,0,228,216,1,
  	0,0,0,228,229,1,0,0,0,229,230,1,0,0,0,230,231,5,16,0,0,231,17,1,0,0,0,
  	232,233,5,61,0,0,233,238,6,9,-1,0,234,235,3,12,6,0,235,236,6,9,-1,0,236,
  	238,1,0,0,0,237,232,1,0,0,0,237,234,1,0,0,0,238,241,1,0,0,0,239,237,1,
  	0,0,0,239,240,1,0,0,0,240,242,1,0,0,0,241,239,1,0,0,0,242,243,5,6,0,0,
  	243,244,5,61,0,0,244,248,6,9,-1,0,245,246,3,52,26,0,246,247,6,9,-1,0,
  	247,249,1,0,0,0,248,245,1,0,0,0,248,249,1,0,0,0,249,250,1,0,0,0,250,254,
  	5,21,0,0,251,252,3,26,13,0,252,253,6,9,-1,0,253,255,1,0,0,0,254,251,1,
  	0,0,0,255,256,1,0,0,0,256,254,1,0,0,0,256,257,1,0,0,0,257,258,1,0,0,0,
  	258,271,5,22,0,0,259,260,5,61,0,0,260,269,6,9,-1,0,261,262,5,23,0,0,262,
  	263,5,24,0,0,263,270,6,9,-1,0,264,265,5,23,0,0,265,266,3,56,28,0,266,
  	267,5,24,0,0,267,268,6,9,-1,0,268,270,1,0,0,0,269,261,1,0,0,0,269,264,
  	1,0,0,0,269,270,1,0,0,0,270,272,1,0,0,0,271,259,1,0,0,0,271,272,1,0,0,
  	0,272,273,1,0,0,0,273,274,5,16,0,0,274,19,1,0,0,0,275,276,5,7,0,0,276,
  	277,3,10,5,0,277,278,5,61,0,0,278,279,6,10,-1,0,279,280,3,30,15,0,280,
  	281,5,16,0,0,281,282,6,10,-1,0,282,292,1,0,0,0,283,284,5,8,0,0,284,285,
  	5,19,0,0,285,286,5,61,0,0,286,287,5,20,0,0,287,288,6,10,-1,0,288,289,
  	3,36,18,0,289,290,6,10,-1,0,290,292,1,0,0,0,291,275,1,0,0,0,291,283,1,
  	0,0,0,292,21,1,0,0,0,293,294,3,56,28,0,294,301,6,11,-1,0,295,296,5,17,
  	0,0,296,297,3,56,28,0,297,298,6,11,-1,0,298,300,1,0,0,0,299,295,1,0,0,
  	0,300,303,1,0,0,0,301,299,1,0,0,0,301,302,1,0,0,0,302,23,1,0,0,0,303,
  	301,1,0,0,0,304,305,3,56,28,0,305,306,6,12,-1,0,306,25,1,0,0,0,307,308,
  	5,61,0,0,308,313,6,13,-1,0,309,310,3,12,6,0,310,311,6,13,-1,0,311,313,
  	1,0,0,0,312,307,1,0,0,0,312,309,1,0,0,0,313,316,1,0,0,0,314,312,1,0,0,
  	0,314,315,1,0,0,0,315,317,1,0,0,0,316,314,1,0,0,0,317,318,3,10,5,0,318,
  	319,5,61,0,0,319,411,6,13,-1,0,320,321,5,23,0,0,321,322,5,24,0,0,322,
  	323,5,27,0,0,323,324,6,13,-1,0,324,325,5,21,0,0,325,326,3,10,5,0,326,
  	327,5,19,0,0,327,328,3,22,11,0,328,329,5,20,0,0,329,339,6,13,-1,0,330,
  	331,5,17,0,0,331,332,3,10,5,0,332,333,5,19,0,0,333,334,3,22,11,0,334,
  	335,5,20,0,0,335,336,6,13,-1,0,336,338,1,0,0,0,337,330,1,0,0,0,338,341,
  	1,0,0,0,339,337,1,0,0,0,339,340,1,0,0,0,340,342,1,0,0,0,341,339,1,0,0,
  	0,342,343,5,22,0,0,343,412,1,0,0,0,344,345,5,23,0,0,345,346,5,24,0,0,
  	346,347,5,27,0,0,347,348,6,13,-1,0,348,349,5,21,0,0,349,350,3,22,11,0,
  	350,351,5,22,0,0,351,352,6,13,-1,0,352,412,1,0,0,0,353,354,5,23,0,0,354,
  	355,3,56,28,0,355,356,5,24,0,0,356,357,6,13,-1,0,357,359,1,0,0,0,358,
  	353,1,0,0,0,359,360,1,0,0,0,360,358,1,0,0,0,360,361,1,0,0,0,361,412,1,
  	0,0,0,362,363,5,23,0,0,363,364,3,56,28,0,364,365,5,24,0,0,365,366,6,13,
  	-1,0,366,367,5,27,0,0,367,368,5,21,0,0,368,369,3,22,11,0,369,370,5,22,
  	0,0,370,371,6,13,-1,0,371,412,1,0,0,0,372,373,5,23,0,0,373,374,3,56,28,
  	0,374,375,5,24,0,0,375,376,6,13,-1,0,376,377,5,27,0,0,377,378,5,21,0,
  	0,378,379,3,10,5,0,379,380,5,19,0,0,380,381,3,22,11,0,381,382,5,20,0,
  	0,382,392,6,13,-1,0,383,384,5,17,0,0,384,385,3,10,5,0,385,386,5,19,0,
  	0,386,387,3,22,11,0,387,388,5,20,0,0,388,389,6,13,-1,0,389,391,1,0,0,
  	0,390,383,1,0,0,0,391,394,1,0,0,0,392,390,1,0,0,0,392,393,1,0,0,0,393,
  	395,1,0,0,0,394,392,1,0,0,0,395,396,5,22,0,0,396,412,1,0,0,0,397,398,
  	5,23,0,0,398,399,5,24,0,0,399,412,6,13,-1,0,400,401,5,27,0,0,401,402,
  	3,10,5,0,402,403,5,19,0,0,403,404,3,22,11,0,404,405,5,20,0,0,405,406,
  	6,13,-1,0,406,412,1,0,0,0,407,408,5,27,0,0,408,409,3,24,12,0,409,410,
  	6,13,-1,0,410,412,1,0,0,0,411,320,1,0,0,0,411,344,1,0,0,0,411,358,1,0,
  	0,0,411,362,1,0,0,0,411,372,1,0,0,0,411,397,1,0,0,0,411,400,1,0,0,0,411,
  	407,1,0,0,0,411,412,1,0,0,0,412,416,1,0,0,0,413,414,3,52,26,0,414,415,
  	6,13,-1,0,415,417,1,0,0,0,416,413,1,0,0,0,416,417,1,0,0,0,417,418,1,0,
  	0,0,418,419,5,16,0,0,419,27,1,0,0,0,420,421,5,23,0,0,421,422,5,61,0,0,
  	422,423,5,24,0,0,423,425,6,14,-1,0,424,420,1,0,0,0,424,425,1,0,0,0,425,
  	437,1,0,0,0,426,427,5,23,0,0,427,428,5,9,0,0,428,429,5,27,0,0,429,430,
  	5,19,0,0,430,431,3,56,28,0,431,432,5,17,0,0,432,433,3,56,28,0,433,434,
  	5,20,0,0,434,435,5,24,0,0,435,436,6,14,-1,0,436,438,1,0,0,0,437,426,1,
  	0,0,0,437,438,1,0,0,0,438,446,1,0,0,0,439,440,5,23,0,0,440,441,5,10,0,
  	0,441,442,5,27,0,0,442,443,3,56,28,0,443,444,5,24,0,0,444,445,6,14,-1,
  	0,445,447,1,0,0,0,446,439,1,0,0,0,446,447,1,0,0,0,447,452,1,0,0,0,448,
  	449,5,61,0,0,449,451,6,14,-1,0,450,448,1,0,0,0,451,454,1,0,0,0,452,450,
  	1,0,0,0,452,453,1,0,0,0,453,455,1,0,0,0,454,452,1,0,0,0,455,456,3,10,
  	5,0,456,457,5,61,0,0,457,466,6,14,-1,0,458,462,5,23,0,0,459,460,3,56,
  	28,0,460,461,6,14,-1,0,461,463,1,0,0,0,462,459,1,0,0,0,462,463,1,0,0,
  	0,463,464,1,0,0,0,464,465,5,24,0,0,465,467,6,14,-1,0,466,458,1,0,0,0,
  	466,467,1,0,0,0,467,29,1,0,0,0,468,480,5,19,0,0,469,470,3,28,14,0,470,
  	477,6,15,-1,0,471,472,5,17,0,0,472,473,3,28,14,0,473,474,6,15,-1,0,474,
  	476,1,0,0,0,475,471,1,0,0,0,476,479,1,0,0,0,477,475,1,0,0,0,477,478,1,
  	0,0,0,478,481,1,0,0,0,479,477,1,0,0,0,480,469,1,0,0,0,480,481,1,0,0,0,
  	481,482,1,0,0,0,482,483,5,20,0,0,483,31,1,0,0,0,484,485,5,23,0,0,485,
  	486,5,61,0,0,486,487,5,24,0,0,487,488,5,27,0,0,488,489,3,56,28,0,489,
  	490,6,16,-1,0,490,496,1,0,0,0,491,492,5,23,0,0,492,493,5,61,0,0,493,494,
  	5,24,0,0,494,496,6,16,-1,0,495,484,1,0,0,0,495,491,1,0,0,0,496,33,1,0,
  	0,0,497,501,5,21,0,0,498,500,3,34,17,0,499,498,1,0,0,0,500,503,1,0,0,
  	0,501,499,1,0,0,0,501,502,1,0,0,0,502,504,1,0,0,0,503,501,1,0,0,0,504,
  	507,5,22,0,0,505,507,8,2,0,0,506,497,1,0,0,0,506,505,1,0,0,0,507,35,1,
  	0,0,0,508,509,3,32,16,0,509,510,6,18,-1,0,510,512,1,0,0,0,511,508,1,0,
  	0,0,512,515,1,0,0,0,513,511,1,0,0,0,513,514,1,0,0,0,514,518,1,0,0,0,515,
  	513,1,0,0,0,516,517,5,11,0,0,517,519,6,18,-1,0,518,516,1,0,0,0,518,519,
  	1,0,0,0,519,520,1,0,0,0,520,521,3,10,5,0,521,522,5,61,0,0,522,523,6,18,
  	-1,0,523,524,3,30,15,0,524,525,6,18,-1,0,525,526,3,34,17,0,526,527,6,
  	18,-1,0,527,528,6,18,-1,0,528,37,1,0,0,0,529,530,5,61,0,0,530,531,5,23,
  	0,0,531,532,3,56,28,0,532,533,5,24,0,0,533,534,5,27,0,0,534,535,3,56,
  	28,0,535,536,5,16,0,0,536,537,6,19,-1,0,537,39,1,0,0,0,538,539,5,61,0,
  	0,539,540,5,27,0,0,540,541,3,56,28,0,541,542,5,16,0,0,542,543,6,20,-1,
  	0,543,41,1,0,0,0,544,545,5,12,0,0,545,546,5,61,0,0,546,547,6,21,-1,0,
  	547,548,5,16,0,0,548,568,6,21,-1,0,549,550,5,12,0,0,550,551,5,61,0,0,
  	551,552,6,21,-1,0,552,553,5,21,0,0,553,562,6,21,-1,0,554,555,3,40,20,
  	0,555,556,6,21,-1,0,556,561,1,0,0,0,557,558,3,38,19,0,558,559,6,21,-1,
  	0,559,561,1,0,0,0,560,554,1,0,0,0,560,557,1,0,0,0,561,564,1,0,0,0,562,
  	560,1,0,0,0,562,563,1,0,0,0,563,565,1,0,0,0,564,562,1,0,0,0,565,566,5,
  	22,0,0,566,568,5,16,0,0,567,544,1,0,0,0,567,549,1,0,0,0,568,43,1,0,0,
  	0,569,570,5,61,0,0,570,575,6,22,-1,0,571,572,3,12,6,0,572,573,6,22,-1,
  	0,573,575,1,0,0,0,574,569,1,0,0,0,574,571,1,0,0,0,575,578,1,0,0,0,576,
  	574,1,0,0,0,576,577,1,0,0,0,577,579,1,0,0,0,578,576,1,0,0,0,579,580,5,
  	13,0,0,580,581,5,61,0,0,581,582,6,22,-1,0,582,583,5,16,0,0,583,610,6,
  	22,-1,0,584,585,5,61,0,0,585,590,6,22,-1,0,586,587,3,12,6,0,587,588,6,
  	22,-1,0,588,590,1,0,0,0,589,584,1,0,0,0,589,586,1,0,0,0,590,593,1,0,0,
  	0,591,589,1,0,0,0,591,592,1,0,0,0,592,594,1,0,0,0,593,591,1,0,0,0,594,
  	595,5,13,0,0,595,596,5,61,0,0,596,597,6,22,-1,0,597,598,6,22,-1,0,598,
  	604,5,21,0,0,599,600,3,48,24,0,600,601,6,22,-1,0,601,603,1,0,0,0,602,
  	599,1,0,0,0,603,606,1,0,0,0,604,602,1,0,0,0,604,605,1,0,0,0,605,607,1,
  	0,0,0,606,604,1,0,0,0,607,608,5,22,0,0,608,610,5,16,0,0,609,576,1,0,0,
  	0,609,591,1,0,0,0,610,45,1,0,0,0,611,612,5,61,0,0,612,618,6,23,-1,0,613,
  	614,5,17,0,0,614,615,5,61,0,0,615,617,6,23,-1,0,616,613,1,0,0,0,617,620,
  	1,0,0,0,618,616,1,0,0,0,618,619,1,0,0,0,619,47,1,0,0,0,620,618,1,0,0,
  	0,621,622,5,61,0,0,622,623,5,27,0,0,623,624,5,61,0,0,624,625,5,16,0,0,
  	625,641,6,24,-1,0,626,627,5,61,0,0,627,628,5,27,0,0,628,629,3,56,28,0,
  	629,630,5,16,0,0,630,631,6,24,-1,0,631,641,1,0,0,0,632,633,5,61,0,0,633,
  	634,5,27,0,0,634,635,5,21,0,0,635,636,3,46,23,0,636,637,5,22,0,0,637,
  	638,5,16,0,0,638,639,6,24,-1,0,639,641,1,0,0,0,640,621,1,0,0,0,640,626,
  	1,0,0,0,640,632,1,0,0,0,641,49,1,0,0,0,642,643,5,61,0,0,643,644,5,27,
  	0,0,644,645,5,61,0,0,645,650,5,19,0,0,646,647,5,61,0,0,647,648,5,27,0,
  	0,648,649,5,61,0,0,649,651,6,25,-1,0,650,646,1,0,0,0,650,651,1,0,0,0,
  	651,659,1,0,0,0,652,653,5,17,0,0,653,654,5,61,0,0,654,655,5,27,0,0,655,
  	656,5,61,0,0,656,658,6,25,-1,0,657,652,1,0,0,0,658,661,1,0,0,0,659,657,
  	1,0,0,0,659,660,1,0,0,0,660,662,1,0,0,0,661,659,1,0,0,0,662,663,5,20,
  	0,0,663,664,5,16,0,0,664,671,6,25,-1,0,665,666,5,14,0,0,666,667,5,27,
  	0,0,667,668,5,61,0,0,668,669,5,16,0,0,669,671,6,25,-1,0,670,642,1,0,0,
  	0,670,665,1,0,0,0,671,51,1,0,0,0,672,689,5,23,0,0,673,674,3,10,5,0,674,
  	675,5,61,0,0,675,682,5,27,0,0,676,677,3,0,0,0,677,678,6,26,-1,0,678,683,
  	1,0,0,0,679,680,3,56,28,0,680,681,6,26,-1,0,681,683,1,0,0,0,682,676,1,
  	0,0,0,682,679,1,0,0,0,683,684,1,0,0,0,684,685,5,16,0,0,685,686,6,26,-1,
  	0,686,688,1,0,0,0,687,673,1,0,0,0,688,691,1,0,0,0,689,687,1,0,0,0,689,
  	690,1,0,0,0,690,692,1,0,0,0,691,689,1,0,0,0,692,693,5,24,0,0,693,694,
  	6,26,-1,0,694,53,1,0,0,0,695,696,5,15,0,0,696,697,5,61,0,0,697,701,6,
  	27,-1,0,698,699,3,52,26,0,699,700,6,27,-1,0,700,702,1,0,0,0,701,698,1,
  	0,0,0,701,702,1,0,0,0,702,703,1,0,0,0,703,704,5,21,0,0,704,710,6,27,-1,
  	0,705,706,3,50,25,0,706,707,6,27,-1,0,707,709,1,0,0,0,708,705,1,0,0,0,
  	709,712,1,0,0,0,710,708,1,0,0,0,710,711,1,0,0,0,711,713,1,0,0,0,712,710,
  	1,0,0,0,713,714,5,22,0,0,714,715,5,16,0,0,715,55,1,0,0,0,716,717,3,58,
  	29,0,717,718,6,28,-1,0,718,57,1,0,0,0,719,720,3,60,30,0,720,727,6,29,
  	-1,0,721,722,5,47,0,0,722,723,3,60,30,0,723,724,6,29,-1,0,724,726,1,0,
  	0,0,725,721,1,0,0,0,726,729,1,0,0,0,727,725,1,0,0,0,727,728,1,0,0,0,728,
  	59,1,0,0,0,729,727,1,0,0,0,730,731,3,62,31,0,731,738,6,30,-1,0,732,733,
  	5,46,0,0,733,734,3,62,31,0,734,735,6,30,-1,0,735,737,1,0,0,0,736,732,
  	1,0,0,0,737,740,1,0,0,0,738,736,1,0,0,0,738,739,1,0,0,0,739,61,1,0,0,
  	0,740,738,1,0,0,0,741,742,3,64,32,0,742,749,6,31,-1,0,743,744,7,3,0,0,
  	744,745,3,64,32,0,745,746,6,31,-1,0,746,748,1,0,0,0,747,743,1,0,0,0,748,
  	751,1,0,0,0,749,747,1,0,0,0,749,750,1,0,0,0,750,63,1,0,0,0,751,749,1,
  	0,0,0,752,753,3,66,33,0,753,760,6,32,-1,0,754,755,7,4,0,0,755,756,3,66,
  	33,0,756,757,6,32,-1,0,757,759,1,0,0,0,758,754,1,0,0,0,759,762,1,0,0,
  	0,760,758,1,0,0,0,760,761,1,0,0,0,761,65,1,0,0,0,762,760,1,0,0,0,763,
  	764,3,68,34,0,764,771,6,33,-1,0,765,766,7,5,0,0,766,767,3,68,34,0,767,
  	768,6,33,-1,0,768,770,1,0,0,0,769,765,1,0,0,0,770,773,1,0,0,0,771,769,
  	1,0,0,0,771,772,1,0,0,0,772,67,1,0,0,0,773,771,1,0,0,0,774,775,3,70,35,
  	0,775,782,6,34,-1,0,776,777,7,6,0,0,777,778,3,70,35,0,778,779,6,34,-1,
  	0,779,781,1,0,0,0,780,776,1,0,0,0,781,784,1,0,0,0,782,780,1,0,0,0,782,
  	783,1,0,0,0,783,69,1,0,0,0,784,782,1,0,0,0,785,787,7,7,0,0,786,785,1,
  	0,0,0,786,787,1,0,0,0,787,788,1,0,0,0,788,789,3,72,36,0,789,790,6,35,
  	-1,0,790,71,1,0,0,0,791,792,5,54,0,0,792,808,6,36,-1,0,793,794,5,57,0,
  	0,794,808,6,36,-1,0,795,796,5,59,0,0,796,808,6,36,-1,0,797,798,5,60,0,
  	0,798,808,6,36,-1,0,799,800,5,61,0,0,800,808,6,36,-1,0,801,802,3,2,1,
  	0,802,803,6,36,-1,0,803,808,1,0,0,0,804,805,3,74,37,0,805,806,6,36,-1,
  	0,806,808,1,0,0,0,807,791,1,0,0,0,807,793,1,0,0,0,807,795,1,0,0,0,807,
  	797,1,0,0,0,807,799,1,0,0,0,807,801,1,0,0,0,807,804,1,0,0,0,808,73,1,
  	0,0,0,809,810,5,19,0,0,810,811,3,56,28,0,811,812,5,20,0,0,812,813,6,37,
  	-1,0,813,75,1,0,0,0,72,81,90,94,100,109,111,147,149,164,166,179,183,193,
  	195,204,212,226,228,237,239,248,256,269,271,291,301,312,314,339,360,392,
  	411,416,424,437,446,452,462,466,477,480,495,501,506,513,518,560,562,567,
  	574,576,589,591,604,609,618,640,650,659,670,682,689,701,710,727,738,749,
  	760,771,782,786,807
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  anyfxParserStaticData = std::move(staticData);
}

}

AnyFXParser::AnyFXParser(TokenStream *input) : AnyFXParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AnyFXParser::AnyFXParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AnyFXParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *anyfxParserStaticData->atn, anyfxParserStaticData->decisionToDFA, anyfxParserStaticData->sharedContextCache, options);
}

AnyFXParser::~AnyFXParser() {
  delete _interpreter;
}

const atn::ATN& AnyFXParser::getATN() const {
  return *anyfxParserStaticData->atn;
}

std::string AnyFXParser::getGrammarFileName() const {
  return "AnyFX.g4";
}

const std::vector<std::string>& AnyFXParser::getRuleNames() const {
  return anyfxParserStaticData->ruleNames;
}

const dfa::Vocabulary& AnyFXParser::getVocabulary() const {
  return anyfxParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AnyFXParser::getSerializedATN() const {
  return anyfxParserStaticData->serializedATN;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::QO: {
        enterOuterAlt(_localctx, 1);
        setState(76);
        match(AnyFXParser::QO);
        setState(81);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 9223372036586340350) != 0)) {
          setState(77);
          antlrcpp::downCast<StringContext *>(_localctx)->data = _input->LT(1);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::QO)) {
            antlrcpp::downCast<StringContext *>(_localctx)->data = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
           _localctx->val.append((antlrcpp::downCast<StringContext *>(_localctx)->data != nullptr ? antlrcpp::downCast<StringContext *>(_localctx)->data->getText() : "")); 
          setState(83);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(84);
        match(AnyFXParser::QO);
        break;
      }

      case AnyFXParser::Q: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        match(AnyFXParser::Q);
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 9223371899415822334) != 0)) {
          setState(86);
          antlrcpp::downCast<StringContext *>(_localctx)->data = _input->LT(1);
          _la = _input->LA(1);
          if (_la == 0 || _la == Token::EOF || (_la == AnyFXParser::Q)) {
            antlrcpp::downCast<StringContext *>(_localctx)->data = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
           _localctx->val.append((antlrcpp::downCast<StringContext *>(_localctx)->data != nullptr ? antlrcpp::downCast<StringContext *>(_localctx)->data->getText() : "")); 
          setState(92);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(93);
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

          antlrcpp::downCast<BooleanContext *>(_localctx)->val =  false;
      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(100);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(96);
        match(AnyFXParser::T__0);
         antlrcpp::downCast<BooleanContext *>(_localctx)->val =  true; 
        break;
      }

      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(98);
        match(AnyFXParser::T__1);
         antlrcpp::downCast<BooleanContext *>(_localctx)->val =  false; 
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
      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(109);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
           start = _input->LT(1); 
          setState(103);
          match(AnyFXParser::T__2);
          setState(104);
          antlrcpp::downCast<PreprocessContext *>(_localctx)->line = match(AnyFXParser::INTEGERLITERAL);
          setState(105);
          antlrcpp::downCast<PreprocessContext *>(_localctx)->path = string();
           lines.push_back(std::make_tuple(atoi((antlrcpp::downCast<PreprocessContext *>(_localctx)->line != nullptr ? antlrcpp::downCast<PreprocessContext *>(_localctx)->line->getText() : "").c_str()), _input->LT(-1)->getLine(), start->getStartIndex(), _input->LT(1)->getStartIndex(), (antlrcpp::downCast<PreprocessContext *>(_localctx)->path != nullptr ? _input->getText(antlrcpp::downCast<PreprocessContext *>(_localctx)->path->start, antlrcpp::downCast<PreprocessContext *>(_localctx)->path->stop) : nullptr))); 
          break;
        }

        case 2: {
          setState(108);
          matchWildcard();
          break;
        }

        default:
          break;
        } 
      }
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(114);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    antlrcpp::downCast<EntryContext *>(_localctx)->effectContext = effect();

            antlrcpp::downCast<EntryContext *>(_localctx)->returnEffect =  antlrcpp::downCast<EntryContext *>(_localctx)->effectContext->eff;
        
    setState(118);
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

          antlrcpp::downCast<EffectContext *>(_localctx)->eff =  alloc.Alloc<Effect>();
      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(147);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          setState(120);
          antlrcpp::downCast<EffectContext *>(_localctx)->variableContext = variable();
           _localctx->eff->AddVariable(antlrcpp::downCast<EffectContext *>(_localctx)->variableContext->var); 
          break;
        }

        case 2: {
          setState(123);
          antlrcpp::downCast<EffectContext *>(_localctx)->renderStateContext = renderState();
           _localctx->eff->AddRenderState(antlrcpp::downCast<EffectContext *>(_localctx)->renderStateContext->state); 
          break;
        }

        case 3: {
          setState(126);
          antlrcpp::downCast<EffectContext *>(_localctx)->functionContext = function();
           _localctx->eff->AddFunction(antlrcpp::downCast<EffectContext *>(_localctx)->functionContext->func); 
          break;
        }

        case 4: {
          setState(129);
          antlrcpp::downCast<EffectContext *>(_localctx)->programContext = program();
           _localctx->eff->AddProgram(antlrcpp::downCast<EffectContext *>(_localctx)->programContext->prog); 
          break;
        }

        case 5: {
          setState(132);
          antlrcpp::downCast<EffectContext *>(_localctx)->structureContext = structure();
           _localctx->eff->AddStructure(antlrcpp::downCast<EffectContext *>(_localctx)->structureContext->struc); 
          break;
        }

        case 6: {
          setState(135);
          antlrcpp::downCast<EffectContext *>(_localctx)->varblockContext = varblock();
           _localctx->eff->AddVarBlock(antlrcpp::downCast<EffectContext *>(_localctx)->varblockContext->block); 
          break;
        }

        case 7: {
          setState(138);
          antlrcpp::downCast<EffectContext *>(_localctx)->varbufferContext = varbuffer();
           _localctx->eff->AddVarBuffer(antlrcpp::downCast<EffectContext *>(_localctx)->varbufferContext->buffer); 
          break;
        }

        case 8: {
          setState(141);
          antlrcpp::downCast<EffectContext *>(_localctx)->subroutineContext = subroutine();
           _localctx->eff->AddSubroutine(antlrcpp::downCast<EffectContext *>(_localctx)->subroutineContext->subrout); 
          break;
        }

        case 9: {
          setState(144);
          antlrcpp::downCast<EffectContext *>(_localctx)->samplerContext = sampler();
           _localctx->eff->AddSampler(antlrcpp::downCast<EffectContext *>(_localctx)->samplerContext->samp); 
          break;
        }

        default:
          break;
        } 
      }
      setState(151);
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
  enterRule(_localctx, 10, AnyFXParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    antlrcpp::downCast<TypeContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);

            antlrcpp::downCast<TypeContext *>(_localctx)->ty =  DataType::FromString((antlrcpp::downCast<TypeContext *>(_localctx)->identifierToken != nullptr ? antlrcpp::downCast<TypeContext *>(_localctx)->identifierToken->getText() : ""));
        
   
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

tree::TerminalNode* AnyFXParser::QualifierExpressionContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
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
  enterRule(_localctx, 12, AnyFXParser::RuleQualifierExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    antlrcpp::downCast<QualifierExpressionContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
    setState(156);
    antlrcpp::downCast<QualifierExpressionContext *>(_localctx)->parantexpressionContext = parantexpression();
     _localctx->q.name = (antlrcpp::downCast<QualifierExpressionContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<QualifierExpressionContext *>(_localctx)->name->getText() : ""); _localctx->q.expr = antlrcpp::downCast<QualifierExpressionContext *>(_localctx)->parantexpressionContext->tree; 
            
   
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

std::vector<tree::TerminalNode *> AnyFXParser::StructureContext::SC() {
  return getTokens(AnyFXParser::SC);
}

tree::TerminalNode* AnyFXParser::StructureContext::SC(size_t i) {
  return getToken(AnyFXParser::SC, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::StructureContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::StructureContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::StructureContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::StructureContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

tree::TerminalNode* AnyFXParser::StructureContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::StructureContext::RB() {
  return getToken(AnyFXParser::RB, 0);
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
  enterRule(_localctx, 14, AnyFXParser::RuleStructure);

          antlrcpp::downCast<StructureContext *>(_localctx)->struc =  alloc.Alloc<Structure>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(164);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(159);
        antlrcpp::downCast<StructureContext *>(_localctx)->qual = match(AnyFXParser::IDENTIFIER);
         _localctx->struc->AddQualifier((antlrcpp::downCast<StructureContext *>(_localctx)->qual != nullptr ? antlrcpp::downCast<StructureContext *>(_localctx)->qual->getText() : "")); 
        break;
      }

      case 2: {
        setState(161);
        antlrcpp::downCast<StructureContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
         _localctx->struc->AddQualifierExpression(antlrcpp::downCast<StructureContext *>(_localctx)->qualifierExpressionContext->q); 
        break;
      }

      default:
        break;
      }
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    match(AnyFXParser::T__3);
    setState(170);
    antlrcpp::downCast<StructureContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(_localctx->struc, _input); 
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LB) {
      setState(172);
      match(AnyFXParser::LB);
      setState(177); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(173);
        antlrcpp::downCast<StructureContext *>(_localctx)->parameterContext = parameter();
        setState(174);
        match(AnyFXParser::SC);
         _localctx->struc->AddParameter(antlrcpp::downCast<StructureContext *>(_localctx)->parameterContext->param); 
        setState(179); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == AnyFXParser::LL

      || _la == AnyFXParser::IDENTIFIER);
      setState(181);
      match(AnyFXParser::RB);
    }
    setState(185);
    match(AnyFXParser::SC);
     _localctx->struc->SetName((antlrcpp::downCast<StructureContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<StructureContext *>(_localctx)->name->getText() : "")); 
   
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

tree::TerminalNode* AnyFXParser::VarblockContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::VarblockContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

tree::TerminalNode* AnyFXParser::VarblockContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::VarblockContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::VarblockContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
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

tree::TerminalNode* AnyFXParser::VarblockContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::VarblockContext::RR() {
  return getToken(AnyFXParser::RR, 0);
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
  enterRule(_localctx, 16, AnyFXParser::RuleVarblock);

          antlrcpp::downCast<VarblockContext *>(_localctx)->block =  alloc.Alloc<VarBlock>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(193);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(188);
        antlrcpp::downCast<VarblockContext *>(_localctx)->qual = match(AnyFXParser::IDENTIFIER);
         _localctx->block->AddQualifier((antlrcpp::downCast<VarblockContext *>(_localctx)->qual != nullptr ? antlrcpp::downCast<VarblockContext *>(_localctx)->qual->getText() : "")); 
        break;
      }

      case 2: {
        setState(190);
        antlrcpp::downCast<VarblockContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
         _localctx->block->AddQualifierExpression(antlrcpp::downCast<VarblockContext *>(_localctx)->qualifierExpressionContext->q); 
        break;
      }

      default:
        break;
      }
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    setState(198);
    match(AnyFXParser::T__4);
    setState(199);
    antlrcpp::downCast<VarblockContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(_localctx->block, _input); _localctx->block->SetName((antlrcpp::downCast<VarblockContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<VarblockContext *>(_localctx)->name->getText() : "")); 
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(201);
      antlrcpp::downCast<VarblockContext *>(_localctx)->annotationContext = annotation();
       _localctx->block->SetAnnotation(antlrcpp::downCast<VarblockContext *>(_localctx)->annotationContext->annot); 
    }
    setState(206);
    match(AnyFXParser::LB);
    setState(212);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(207);
      antlrcpp::downCast<VarblockContext *>(_localctx)->variableContext = variable();
       _localctx->block->AddVariable(antlrcpp::downCast<VarblockContext *>(_localctx)->variableContext->var); 
      setState(214);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(215);
    match(AnyFXParser::RB);
    setState(228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(216);
      antlrcpp::downCast<VarblockContext *>(_localctx)->varName = match(AnyFXParser::IDENTIFIER);
       _localctx->block->SetStructName((antlrcpp::downCast<VarblockContext *>(_localctx)->varName != nullptr ? antlrcpp::downCast<VarblockContext *>(_localctx)->varName->getText() : "")); 
      setState(226);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(218);
        match(AnyFXParser::LL);
        setState(219);
        match(AnyFXParser::RR);
         _localctx->block->SetArrayExpression(nullptr); 
        break;
      }

      case 2: {
        setState(221);
        match(AnyFXParser::LL);
        setState(222);
        antlrcpp::downCast<VarblockContext *>(_localctx)->arraySize = expression();
        setState(223);
        match(AnyFXParser::RR);
         _localctx->block->SetArrayExpression(antlrcpp::downCast<VarblockContext *>(_localctx)->arraySize->tree); 
        break;
      }

      default:
        break;
      }
    }
    setState(230);
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

tree::TerminalNode* AnyFXParser::VarbufferContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::VarbufferContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
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

tree::TerminalNode* AnyFXParser::VarbufferContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::VarbufferContext::RR() {
  return getToken(AnyFXParser::RR, 0);
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
  enterRule(_localctx, 18, AnyFXParser::RuleVarbuffer);

          antlrcpp::downCast<VarbufferContext *>(_localctx)->buffer =  alloc.Alloc<VarBuffer>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(237);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
      case 1: {
        setState(232);
        antlrcpp::downCast<VarbufferContext *>(_localctx)->qual = match(AnyFXParser::IDENTIFIER);
         _localctx->buffer->AddQualifier((antlrcpp::downCast<VarbufferContext *>(_localctx)->qual != nullptr ? antlrcpp::downCast<VarbufferContext *>(_localctx)->qual->getText() : "")); 
        break;
      }

      case 2: {
        setState(234);
        antlrcpp::downCast<VarbufferContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
         _localctx->buffer->AddQualifierExpression(antlrcpp::downCast<VarbufferContext *>(_localctx)->qualifierExpressionContext->q); 
        break;
      }

      default:
        break;
      }
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }

    setState(242);
    match(AnyFXParser::T__5);
    setState(243);
    antlrcpp::downCast<VarbufferContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(_localctx->buffer, _input); _localctx->buffer->SetName((antlrcpp::downCast<VarbufferContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<VarbufferContext *>(_localctx)->name->getText() : "")); 
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(245);
      antlrcpp::downCast<VarbufferContext *>(_localctx)->annotationContext = annotation();
       _localctx->buffer->SetAnnotation(antlrcpp::downCast<VarbufferContext *>(_localctx)->annotationContext->annot); 
    }
    setState(250);
    match(AnyFXParser::LB);
    setState(254); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(251);
      antlrcpp::downCast<VarbufferContext *>(_localctx)->variableContext = variable();
      _localctx->buffer->AddVariable(antlrcpp::downCast<VarbufferContext *>(_localctx)->variableContext->var); 
      setState(256); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AnyFXParser::IDENTIFIER);
    setState(258);
    match(AnyFXParser::RB);
    setState(271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::IDENTIFIER) {
      setState(259);
      antlrcpp::downCast<VarbufferContext *>(_localctx)->varName = match(AnyFXParser::IDENTIFIER);
       _localctx->buffer->SetStructName((antlrcpp::downCast<VarbufferContext *>(_localctx)->varName != nullptr ? antlrcpp::downCast<VarbufferContext *>(_localctx)->varName->getText() : "")); 
      setState(269);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(261);
        match(AnyFXParser::LL);
        setState(262);
        match(AnyFXParser::RR);
         _localctx->buffer->SetArrayExpression(nullptr); 
        break;
      }

      case 2: {
        setState(264);
        match(AnyFXParser::LL);
        setState(265);
        antlrcpp::downCast<VarbufferContext *>(_localctx)->arraySize = expression();
        setState(266);
        match(AnyFXParser::RR);
         _localctx->buffer->SetArrayExpression(antlrcpp::downCast<VarbufferContext *>(_localctx)->arraySize->tree); 
        break;
      }

      default:
        break;
      }
    }
    setState(273);
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

tree::TerminalNode* AnyFXParser::SubroutineContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

AnyFXParser::TypeContext* AnyFXParser::SubroutineContext::type() {
  return getRuleContext<AnyFXParser::TypeContext>(0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

tree::TerminalNode* AnyFXParser::SubroutineContext::RP() {
  return getToken(AnyFXParser::RP, 0);
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
  enterRule(_localctx, 20, AnyFXParser::RuleSubroutine);

          antlrcpp::downCast<SubroutineContext *>(_localctx)->subrout =  alloc.Alloc<Subroutine>();
      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(275);
        match(AnyFXParser::T__6);
        setState(276);
        antlrcpp::downCast<SubroutineContext *>(_localctx)->retval = type();
        setState(277);
        antlrcpp::downCast<SubroutineContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
         SetupFile(_localctx->subrout, _input); 
        setState(279);
        antlrcpp::downCast<SubroutineContext *>(_localctx)->parameterListContext = parameterList();
        setState(280);
        match(AnyFXParser::SC);

                _localctx->subrout->SetSubroutineType(Subroutine::Signature);
                _localctx->subrout->SetName((antlrcpp::downCast<SubroutineContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<SubroutineContext *>(_localctx)->name->getText() : ""));
                _localctx->subrout->SetParameters(antlrcpp::downCast<SubroutineContext *>(_localctx)->parameterListContext->parameters);
                _localctx->subrout->SetReturnType(antlrcpp::downCast<SubroutineContext *>(_localctx)->retval->ty);
            
        break;
      }

      case AnyFXParser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(283);
        match(AnyFXParser::T__7);
        setState(284);
        match(AnyFXParser::LP);
        setState(285);
        antlrcpp::downCast<SubroutineContext *>(_localctx)->signature = match(AnyFXParser::IDENTIFIER);
        setState(286);
        match(AnyFXParser::RP);
         SetupFile(_localctx->subrout, _input); 
        setState(288);
        antlrcpp::downCast<SubroutineContext *>(_localctx)->functionContext = function();

                _localctx->subrout->SetName(antlrcpp::downCast<SubroutineContext *>(_localctx)->functionContext->func->GetName());
                _localctx->subrout->SetSubroutineType(Subroutine::Implementation);
                _localctx->subrout->SetSignature((antlrcpp::downCast<SubroutineContext *>(_localctx)->signature != nullptr ? antlrcpp::downCast<SubroutineContext *>(_localctx)->signature->getText() : ""));
                _localctx->subrout->SetFunction(antlrcpp::downCast<SubroutineContext *>(_localctx)->functionContext->func);
            
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

std::vector<tree::TerminalNode *> AnyFXParser::ValueListContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ValueListContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
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
  enterRule(_localctx, 22, AnyFXParser::RuleValueList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    antlrcpp::downCast<ValueListContext *>(_localctx)->first = expression();
     _localctx->valList.AddValue(antlrcpp::downCast<ValueListContext *>(_localctx)->first->tree); 
    setState(301);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(295);
      match(AnyFXParser::CO);
      setState(296);
      antlrcpp::downCast<ValueListContext *>(_localctx)->rest = expression();
       _localctx->valList.AddValue(antlrcpp::downCast<ValueListContext *>(_localctx)->rest->tree); 
      setState(303);
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
  enterRule(_localctx, 24, AnyFXParser::RuleValueSingleList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    antlrcpp::downCast<ValueSingleListContext *>(_localctx)->expressionContext = expression();
     _localctx->valList.AddValue(antlrcpp::downCast<ValueSingleListContext *>(_localctx)->expressionContext->tree); 
   
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

tree::TerminalNode* AnyFXParser::VariableContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::VariableContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::VariableContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::VariableContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::VariableContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::VariableContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::LL() {
  return getTokens(AnyFXParser::LL);
}

tree::TerminalNode* AnyFXParser::VariableContext::LL(size_t i) {
  return getToken(AnyFXParser::LL, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::RR() {
  return getTokens(AnyFXParser::RR);
}

tree::TerminalNode* AnyFXParser::VariableContext::RR(size_t i) {
  return getToken(AnyFXParser::RR, i);
}

tree::TerminalNode* AnyFXParser::VariableContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

tree::TerminalNode* AnyFXParser::VariableContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::LP() {
  return getTokens(AnyFXParser::LP);
}

tree::TerminalNode* AnyFXParser::VariableContext::LP(size_t i) {
  return getToken(AnyFXParser::LP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::RP() {
  return getTokens(AnyFXParser::RP);
}

tree::TerminalNode* AnyFXParser::VariableContext::RP(size_t i) {
  return getToken(AnyFXParser::RP, i);
}

tree::TerminalNode* AnyFXParser::VariableContext::RB() {
  return getToken(AnyFXParser::RB, 0);
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

std::vector<tree::TerminalNode *> AnyFXParser::VariableContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::VariableContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
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
  enterRule(_localctx, 26, AnyFXParser::RuleVariable);

          antlrcpp::downCast<VariableContext *>(_localctx)->var =  alloc.Alloc<Variable>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(314);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(312);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(307);
          antlrcpp::downCast<VariableContext *>(_localctx)->qual = match(AnyFXParser::IDENTIFIER);
           _localctx->var->AddQualifier((antlrcpp::downCast<VariableContext *>(_localctx)->qual != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->qual->getText() : "")); 
          break;
        }

        case 2: {
          setState(309);
          antlrcpp::downCast<VariableContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->var->AddQualifierExpression(antlrcpp::downCast<VariableContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

        default:
          break;
        } 
      }
      setState(316);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
    setState(317);
    antlrcpp::downCast<VariableContext *>(_localctx)->declType = type();
    setState(318);
    antlrcpp::downCast<VariableContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     _localctx->var->SetDataType(antlrcpp::downCast<VariableContext *>(_localctx)->declType->ty); _localctx->var->SetName((antlrcpp::downCast<VariableContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<VariableContext *>(_localctx)->name->getText() : "")); SetupFile(_localctx->var, _input); 
            
    setState(411);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(320);
      match(AnyFXParser::LL);
      setState(321);
      match(AnyFXParser::RR);
      setState(322);
      match(AnyFXParser::EQ);
       _localctx->var->SetArrayType(Variable::TypedArray); 
      setState(324);
      match(AnyFXParser::LB);
      setState(325);
      antlrcpp::downCast<VariableContext *>(_localctx)->fstType = type();
      setState(326);
      match(AnyFXParser::LP);
      setState(327);
      antlrcpp::downCast<VariableContext *>(_localctx)->fstValue = valueList();
      setState(328);
      match(AnyFXParser::RP);
       _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->fstType->ty, antlrcpp::downCast<VariableContext *>(_localctx)->fstValue->valList); 
      setState(339);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(330);
        match(AnyFXParser::CO);
        setState(331);
        antlrcpp::downCast<VariableContext *>(_localctx)->cntType = type();
        setState(332);
        match(AnyFXParser::LP);
        setState(333);
        antlrcpp::downCast<VariableContext *>(_localctx)->cntValue = valueList();
        setState(334);
        match(AnyFXParser::RP);
         _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->cntType->ty, antlrcpp::downCast<VariableContext *>(_localctx)->cntValue->valList); 
        setState(341);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(342);
      match(AnyFXParser::RB);
      break;
    }

    case 2: {
      setState(344);
      match(AnyFXParser::LL);
      setState(345);
      match(AnyFXParser::RR);
      setState(346);
      match(AnyFXParser::EQ);
       _localctx->var->SetArrayType(Variable::SimpleArray); 
      setState(348);
      match(AnyFXParser::LB);
      setState(349);
      antlrcpp::downCast<VariableContext *>(_localctx)->valList = valueList();
      setState(350);
      match(AnyFXParser::RB);
       _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->valList->valList); 
      break;
    }

    case 3: {
      setState(358); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(353);
                match(AnyFXParser::LL);
                setState(354);
                antlrcpp::downCast<VariableContext *>(_localctx)->asize0 = expression();
                setState(355);
                match(AnyFXParser::RR);
                 _localctx->var->AddSizeExpression(antlrcpp::downCast<VariableContext *>(_localctx)->asize0->tree); _localctx->var->SetArrayType(Variable::SimpleArray); 
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(360); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 4: {
      setState(362);
      match(AnyFXParser::LL);
      setState(363);
      antlrcpp::downCast<VariableContext *>(_localctx)->asize2 = expression();
      setState(364);
      match(AnyFXParser::RR);
       _localctx->var->AddSizeExpression(antlrcpp::downCast<VariableContext *>(_localctx)->asize2->tree); _localctx->var->SetArrayType(Variable::SimpleArray); 
      setState(366);
      match(AnyFXParser::EQ);
      setState(367);
      match(AnyFXParser::LB);
      setState(368);
      antlrcpp::downCast<VariableContext *>(_localctx)->valList = valueList();
      setState(369);
      match(AnyFXParser::RB);
       _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->valList->valList); 
      break;
    }

    case 5: {
      setState(372);
      match(AnyFXParser::LL);
      setState(373);
      antlrcpp::downCast<VariableContext *>(_localctx)->asize2 = expression();
      setState(374);
      match(AnyFXParser::RR);
       _localctx->var->AddSizeExpression(antlrcpp::downCast<VariableContext *>(_localctx)->asize2->tree); _localctx->var->SetArrayType(Variable::TypedArray); 
      setState(376);
      match(AnyFXParser::EQ);
      setState(377);
      match(AnyFXParser::LB);
      setState(378);
      antlrcpp::downCast<VariableContext *>(_localctx)->fstType = type();
      setState(379);
      match(AnyFXParser::LP);
      setState(380);
      antlrcpp::downCast<VariableContext *>(_localctx)->fstValue = valueList();
      setState(381);
      match(AnyFXParser::RP);
       _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->fstType->ty, antlrcpp::downCast<VariableContext *>(_localctx)->fstValue->valList); 
      setState(392);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(383);
        match(AnyFXParser::CO);
        setState(384);
        antlrcpp::downCast<VariableContext *>(_localctx)->cntType = type();
        setState(385);
        match(AnyFXParser::LP);
        setState(386);
        antlrcpp::downCast<VariableContext *>(_localctx)->cntValue = valueList();
        setState(387);
        match(AnyFXParser::RP);
         _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->cntType->ty, antlrcpp::downCast<VariableContext *>(_localctx)->cntValue->valList); 
        setState(394);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(395);
      match(AnyFXParser::RB);
      break;
    }

    case 6: {
      setState(397);
      match(AnyFXParser::LL);
      setState(398);
      match(AnyFXParser::RR);
       _localctx->var->SetArrayType(Variable::UnsizedArray); 
      break;
    }

    case 7: {
      setState(400);
      match(AnyFXParser::EQ);
      setState(401);
      antlrcpp::downCast<VariableContext *>(_localctx)->defType = type();
      setState(402);
      match(AnyFXParser::LP);
      setState(403);
      antlrcpp::downCast<VariableContext *>(_localctx)->list2 = valueList();
      setState(404);
      match(AnyFXParser::RP);
       _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->defType->ty, antlrcpp::downCast<VariableContext *>(_localctx)->list2->valList); 
      break;
    }

    case 8: {
      setState(407);
      match(AnyFXParser::EQ);
      setState(408);
      antlrcpp::downCast<VariableContext *>(_localctx)->list3 = valueSingleList();
       _localctx->var->AddValue(antlrcpp::downCast<VariableContext *>(_localctx)->list3->valList); 
      break;
    }

    default:
      break;
    }
    setState(416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(413);
      antlrcpp::downCast<VariableContext *>(_localctx)->annotationContext = annotation();
       _localctx->var->SetAnnotation(antlrcpp::downCast<VariableContext *>(_localctx)->annotationContext->annot); 
    }
    setState(418);
    match(AnyFXParser::SC);
   
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

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::LL() {
  return getTokens(AnyFXParser::LL);
}

tree::TerminalNode* AnyFXParser::ParameterContext::LL(size_t i) {
  return getToken(AnyFXParser::LL, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::RR() {
  return getTokens(AnyFXParser::RR);
}

tree::TerminalNode* AnyFXParser::ParameterContext::RR(size_t i) {
  return getToken(AnyFXParser::RR, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterContext::EQ() {
  return getTokens(AnyFXParser::EQ);
}

tree::TerminalNode* AnyFXParser::ParameterContext::EQ(size_t i) {
  return getToken(AnyFXParser::EQ, i);
}

tree::TerminalNode* AnyFXParser::ParameterContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

tree::TerminalNode* AnyFXParser::ParameterContext::CO() {
  return getToken(AnyFXParser::CO, 0);
}

tree::TerminalNode* AnyFXParser::ParameterContext::RP() {
  return getToken(AnyFXParser::RP, 0);
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
  enterRule(_localctx, 28, AnyFXParser::RuleParameter);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(424);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(420);
      match(AnyFXParser::LL);
      setState(421);
      antlrcpp::downCast<ParameterContext *>(_localctx)->attr = match(AnyFXParser::IDENTIFIER);
      setState(422);
      match(AnyFXParser::RR);

                  _localctx->param.SetAttribute((antlrcpp::downCast<ParameterContext *>(_localctx)->attr != nullptr ? antlrcpp::downCast<ParameterContext *>(_localctx)->attr->getText() : ""));
              
      break;
    }

    default:
      break;
    }
    setState(437);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(426);
      match(AnyFXParser::LL);
      setState(427);
      match(AnyFXParser::T__8);
      setState(428);
      match(AnyFXParser::EQ);
      setState(429);
      match(AnyFXParser::LP);
      setState(430);
      antlrcpp::downCast<ParameterContext *>(_localctx)->feedbackBuffer = expression();
      setState(431);
      match(AnyFXParser::CO);
      setState(432);
      antlrcpp::downCast<ParameterContext *>(_localctx)->feedbackOffset = expression();
      setState(433);
      match(AnyFXParser::RP);
      setState(434);
      match(AnyFXParser::RR);

                  _localctx->param.SetFeedbackBufferExpression(antlrcpp::downCast<ParameterContext *>(_localctx)->feedbackBuffer->tree);
                  _localctx->param.SetFeedbackOffsetExpression(antlrcpp::downCast<ParameterContext *>(_localctx)->feedbackOffset->tree);
              
      break;
    }

    default:
      break;
    }
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(439);
      match(AnyFXParser::LL);
      setState(440);
      match(AnyFXParser::T__9);
      setState(441);
      match(AnyFXParser::EQ);
      setState(442);
      antlrcpp::downCast<ParameterContext *>(_localctx)->slotExpression = expression();
      setState(443);
      match(AnyFXParser::RR);

                  _localctx->param.SetSlotExpression(antlrcpp::downCast<ParameterContext *>(_localctx)->slotExpression->tree);
              
    }
    setState(452);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(448);
        antlrcpp::downCast<ParameterContext *>(_localctx)->qualifier = match(AnyFXParser::IDENTIFIER);

                    _localctx->param.AddQualifier((antlrcpp::downCast<ParameterContext *>(_localctx)->qualifier != nullptr ? antlrcpp::downCast<ParameterContext *>(_localctx)->qualifier->getText() : ""));
                 
      }
      setState(454);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
    setState(455);
    antlrcpp::downCast<ParameterContext *>(_localctx)->typeContext = type();
    setState(456);
    antlrcpp::downCast<ParameterContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     _localctx->param.SetDataType(antlrcpp::downCast<ParameterContext *>(_localctx)->typeContext->ty); _localctx->param.SetName((antlrcpp::downCast<ParameterContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<ParameterContext *>(_localctx)->name->getText() : "")); SetupFile(&_localctx->param, _input); 
    setState(466);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(458);
      match(AnyFXParser::LL);
      setState(462);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4199606652590620678) != 0)) {
        setState(459);
        antlrcpp::downCast<ParameterContext *>(_localctx)->size = expression();
         _localctx->param.SetSizeExpression(antlrcpp::downCast<ParameterContext *>(_localctx)->size->tree); 
      }
      setState(464);
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

tree::TerminalNode* AnyFXParser::ParameterListContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

tree::TerminalNode* AnyFXParser::ParameterListContext::RP() {
  return getToken(AnyFXParser::RP, 0);
}

std::vector<AnyFXParser::ParameterContext *> AnyFXParser::ParameterListContext::parameter() {
  return getRuleContexts<AnyFXParser::ParameterContext>();
}

AnyFXParser::ParameterContext* AnyFXParser::ParameterListContext::parameter(size_t i) {
  return getRuleContext<AnyFXParser::ParameterContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ParameterListContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ParameterListContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
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
  enterRule(_localctx, 30, AnyFXParser::RuleParameterList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    match(AnyFXParser::LP);
    setState(480);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL

    || _la == AnyFXParser::IDENTIFIER) {
      setState(469);
      antlrcpp::downCast<ParameterListContext *>(_localctx)->firstParam = parameter();
       _localctx->parameters.push_back(antlrcpp::downCast<ParameterListContext *>(_localctx)->firstParam->param); 
      setState(477);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::CO) {
        setState(471);
        match(AnyFXParser::CO);
        setState(472);
        antlrcpp::downCast<ParameterListContext *>(_localctx)->followParam = parameter();
         _localctx->parameters.push_back(antlrcpp::downCast<ParameterListContext *>(_localctx)->followParam->param); 
        setState(479);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(482);
    match(AnyFXParser::RP);
   
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

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

tree::TerminalNode* AnyFXParser::FunctionAttributeContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
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
  enterRule(_localctx, 32, AnyFXParser::RuleFunctionAttribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(495);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(484);
      match(AnyFXParser::LL);
      setState(485);
      antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(486);
      match(AnyFXParser::RR);
      setState(487);
      match(AnyFXParser::EQ);
      setState(488);
      antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->expressionContext = expression();

              std::string identifierString((antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->flag1 != nullptr ? antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->flag1->getText() : ""));

              _localctx->attribute.SetExpression(identifierString, antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->expressionContext->tree);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(491);
      match(AnyFXParser::LL);
      setState(492);
      antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->flag3 = match(AnyFXParser::IDENTIFIER);
      setState(493);
      match(AnyFXParser::RR);

              std::string identifierString((antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->flag3 != nullptr ? antlrcpp::downCast<FunctionAttributeContext *>(_localctx)->flag3->getText() : ""));

              _localctx->attribute.SetBool(identifierString, true);
          
      break;
    }

    default:
      break;
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

tree::TerminalNode* AnyFXParser::CodeBlockContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::CodeBlockContext::RB() {
  return getToken(AnyFXParser::RB, 0);
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
  enterRule(_localctx, 34, AnyFXParser::RuleCodeBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(506);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::LB: {
        enterOuterAlt(_localctx, 1);
        setState(497);
        match(AnyFXParser::LB);
        setState(501);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 9223372036850581502) != 0)) {
          setState(498);
          codeBlock();
          setState(503);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(504);
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
        setState(505);
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

AnyFXParser::ParameterListContext* AnyFXParser::FunctionContext::parameterList() {
  return getRuleContext<AnyFXParser::ParameterListContext>(0);
}

AnyFXParser::CodeBlockContext* AnyFXParser::FunctionContext::codeBlock() {
  return getRuleContext<AnyFXParser::CodeBlockContext>(0);
}

tree::TerminalNode* AnyFXParser::FunctionContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
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
  enterRule(_localctx, 36, AnyFXParser::RuleFunction);

              antlrcpp::downCast<FunctionContext *>(_localctx)->func =  alloc.Alloc<Function>();
              Token* startToken = nullptr;
              Token* endToken = nullptr;
          
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(513);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LL) {
      setState(508);
      antlrcpp::downCast<FunctionContext *>(_localctx)->functionAttributeContext = functionAttribute();
       _localctx->func->ConsumeAttribute(antlrcpp::downCast<FunctionContext *>(_localctx)->functionAttributeContext->attribute); 
      setState(515);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(518);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::T__10) {
      setState(516);
      match(AnyFXParser::T__10);
       _localctx->func->SetShader(true); 
    }
    setState(520);
    antlrcpp::downCast<FunctionContext *>(_localctx)->typeContext = type();
    setState(521);
    antlrcpp::downCast<FunctionContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     UpdateLine(_input, -2); _localctx->func->SetFunctionLine(this->lineOffset); SetupFile(_localctx->func, _input, false);  
    setState(523);
    antlrcpp::downCast<FunctionContext *>(_localctx)->parameterListContext = parameterList();

                // the code block will be after the next right bracket
                startToken = _input->LT(2);

                UpdateLine(_input, 2);
                _localctx->func->SetCodeLine(this->lineOffset);
            
    setState(525);
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
                    _localctx->func->SetCode(code);
            
     
                _localctx->func->SetName((antlrcpp::downCast<FunctionContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<FunctionContext *>(_localctx)->name->getText() : "")); _localctx->func->SetReturnType(antlrcpp::downCast<FunctionContext *>(_localctx)->typeContext->ty); _localctx->func->SetParameters(antlrcpp::downCast<FunctionContext *>(_localctx)->parameterListContext->parameters); 
            
   
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

tree::TerminalNode* AnyFXParser::BlendStateRowContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

tree::TerminalNode* AnyFXParser::BlendStateRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
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
  enterRule(_localctx, 38, AnyFXParser::RuleBlendStateRow);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(529);
    antlrcpp::downCast<BlendStateRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
    setState(530);
    match(AnyFXParser::LL);
    setState(531);
    antlrcpp::downCast<BlendStateRowContext *>(_localctx)->index2 = expression();
    setState(532);
    match(AnyFXParser::RR);
    setState(533);
    match(AnyFXParser::EQ);
    setState(534);
    antlrcpp::downCast<BlendStateRowContext *>(_localctx)->value = expression();
    setState(535);
    match(AnyFXParser::SC);

            std::string flag((antlrcpp::downCast<BlendStateRowContext *>(_localctx)->flag2 != nullptr ? antlrcpp::downCast<BlendStateRowContext *>(_localctx)->flag2->getText() : ""));
            _localctx->row.SetExpression(antlrcpp::downCast<BlendStateRowContext *>(_localctx)->index2->tree, flag, antlrcpp::downCast<BlendStateRowContext *>(_localctx)->value->tree);
        
   
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

tree::TerminalNode* AnyFXParser::RenderStateRowContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::RenderStateRowContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::RenderStateRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
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
  enterRule(_localctx, 40, AnyFXParser::RuleRenderStateRow);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(538);
    antlrcpp::downCast<RenderStateRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
    setState(539);
    match(AnyFXParser::EQ);
    setState(540);
    antlrcpp::downCast<RenderStateRowContext *>(_localctx)->expressionContext = expression();
    setState(541);
    match(AnyFXParser::SC);

            std::string flag((antlrcpp::downCast<RenderStateRowContext *>(_localctx)->flag1 != nullptr ? antlrcpp::downCast<RenderStateRowContext *>(_localctx)->flag1->getText() : ""));
            _localctx->row.SetExpression(flag, antlrcpp::downCast<RenderStateRowContext *>(_localctx)->expressionContext->tree);
        
   
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

tree::TerminalNode* AnyFXParser::RenderStateContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

tree::TerminalNode* AnyFXParser::RenderStateContext::IDENTIFIER() {
  return getToken(AnyFXParser::IDENTIFIER, 0);
}

tree::TerminalNode* AnyFXParser::RenderStateContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::RenderStateContext::RB() {
  return getToken(AnyFXParser::RB, 0);
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
  enterRule(_localctx, 42, AnyFXParser::RuleRenderState);

          antlrcpp::downCast<RenderStateContext *>(_localctx)->state =  alloc.Alloc<RenderState>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(567);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(544);
      match(AnyFXParser::T__11);
      setState(545);
      antlrcpp::downCast<RenderStateContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(_localctx->state, _input); 
      setState(547);
      match(AnyFXParser::SC);
       _localctx->state->SetName((antlrcpp::downCast<RenderStateContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<RenderStateContext *>(_localctx)->name->getText() : "")); 
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(549);
      match(AnyFXParser::T__11);
      setState(550);
      antlrcpp::downCast<RenderStateContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(_localctx->state, _input); 
      setState(552);
      match(AnyFXParser::LB);
       _localctx->state->SetName((antlrcpp::downCast<RenderStateContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<RenderStateContext *>(_localctx)->name->getText() : "")); 
              
      setState(562);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(560);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
        case 1: {
          setState(554);
          antlrcpp::downCast<RenderStateContext *>(_localctx)->renderStateRowContext = renderStateRow();
           _localctx->state->ConsumeRenderRow(antlrcpp::downCast<RenderStateContext *>(_localctx)->renderStateRowContext->row); 
          break;
        }

        case 2: {
          setState(557);
          antlrcpp::downCast<RenderStateContext *>(_localctx)->blendStateRowContext = blendStateRow();
           _localctx->state->ConsumeBlendRow(antlrcpp::downCast<RenderStateContext *>(_localctx)->blendStateRowContext->row); 
          break;
        }

        default:
          break;
        }
        setState(564);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(565);
      match(AnyFXParser::RB);
      setState(566);
      match(AnyFXParser::SC);
      break;
    }

    default:
      break;
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

tree::TerminalNode* AnyFXParser::SamplerContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::SamplerContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::SamplerContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<AnyFXParser::QualifierExpressionContext *> AnyFXParser::SamplerContext::qualifierExpression() {
  return getRuleContexts<AnyFXParser::QualifierExpressionContext>();
}

AnyFXParser::QualifierExpressionContext* AnyFXParser::SamplerContext::qualifierExpression(size_t i) {
  return getRuleContext<AnyFXParser::QualifierExpressionContext>(i);
}

tree::TerminalNode* AnyFXParser::SamplerContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::SamplerContext::RB() {
  return getToken(AnyFXParser::RB, 0);
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
  enterRule(_localctx, 44, AnyFXParser::RuleSampler);

          antlrcpp::downCast<SamplerContext *>(_localctx)->samp =  alloc.Alloc<Sampler>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(609);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(576);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(574);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
        case 1: {
          setState(569);
          antlrcpp::downCast<SamplerContext *>(_localctx)->qual = match(AnyFXParser::IDENTIFIER);
           _localctx->samp->AddQualifier((antlrcpp::downCast<SamplerContext *>(_localctx)->qual != nullptr ? antlrcpp::downCast<SamplerContext *>(_localctx)->qual->getText() : "")); 
          break;
        }

        case 2: {
          setState(571);
          antlrcpp::downCast<SamplerContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->samp->AddQualifierExpression(antlrcpp::downCast<SamplerContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

        default:
          break;
        }
        setState(578);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(579);
      match(AnyFXParser::T__12);
      setState(580);
      antlrcpp::downCast<SamplerContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(_localctx->samp, _input); 
      setState(582);
      match(AnyFXParser::SC);
       _localctx->samp->SetName((antlrcpp::downCast<SamplerContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<SamplerContext *>(_localctx)->name->getText() : "")); 
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(591);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(589);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
        case 1: {
          setState(584);
          antlrcpp::downCast<SamplerContext *>(_localctx)->qual = match(AnyFXParser::IDENTIFIER);
           _localctx->samp->AddQualifier((antlrcpp::downCast<SamplerContext *>(_localctx)->qual != nullptr ? antlrcpp::downCast<SamplerContext *>(_localctx)->qual->getText() : "")); 
          break;
        }

        case 2: {
          setState(586);
          antlrcpp::downCast<SamplerContext *>(_localctx)->qualifierExpressionContext = qualifierExpression();
           _localctx->samp->AddQualifierExpression(antlrcpp::downCast<SamplerContext *>(_localctx)->qualifierExpressionContext->q); 
          break;
        }

        default:
          break;
        }
        setState(593);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }

      setState(594);
      match(AnyFXParser::T__12);
      setState(595);
      antlrcpp::downCast<SamplerContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
       SetupFile(_localctx->samp, _input); 
       _localctx->samp->SetName((antlrcpp::downCast<SamplerContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<SamplerContext *>(_localctx)->name->getText() : "")); 
              
      setState(598);
      match(AnyFXParser::LB);
      setState(604);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AnyFXParser::IDENTIFIER) {
        setState(599);
        antlrcpp::downCast<SamplerContext *>(_localctx)->samplerRowContext = samplerRow();
         _localctx->samp->ConsumeRow(antlrcpp::downCast<SamplerContext *>(_localctx)->samplerRowContext->row); 
        setState(606);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(607);
      match(AnyFXParser::RB);
      setState(608);
      match(AnyFXParser::SC);
      break;
    }

    default:
      break;
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

std::vector<tree::TerminalNode *> AnyFXParser::SamplerTextureListContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::SamplerTextureListContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
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
  enterRule(_localctx, 46, AnyFXParser::RuleSamplerTextureList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(611);
    antlrcpp::downCast<SamplerTextureListContext *>(_localctx)->firstItem = match(AnyFXParser::IDENTIFIER);
     _localctx->list.AddTexture((antlrcpp::downCast<SamplerTextureListContext *>(_localctx)->firstItem != nullptr ? antlrcpp::downCast<SamplerTextureListContext *>(_localctx)->firstItem->getText() : "")); 
    setState(618);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::CO) {
      setState(613);
      match(AnyFXParser::CO);
      setState(614);
      antlrcpp::downCast<SamplerTextureListContext *>(_localctx)->nextItem = match(AnyFXParser::IDENTIFIER);
       _localctx->list.AddTexture((antlrcpp::downCast<SamplerTextureListContext *>(_localctx)->nextItem != nullptr ? antlrcpp::downCast<SamplerTextureListContext *>(_localctx)->nextItem->getText() : "")); 
      setState(620);
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

tree::TerminalNode* AnyFXParser::SamplerRowContext::EQ() {
  return getToken(AnyFXParser::EQ, 0);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
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

tree::TerminalNode* AnyFXParser::SamplerRowContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

AnyFXParser::SamplerTextureListContext* AnyFXParser::SamplerRowContext::samplerTextureList() {
  return getRuleContext<AnyFXParser::SamplerTextureListContext>(0);
}

tree::TerminalNode* AnyFXParser::SamplerRowContext::RB() {
  return getToken(AnyFXParser::RB, 0);
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
  enterRule(_localctx, 48, AnyFXParser::RuleSamplerRow);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(640);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(621);
      antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag1 = match(AnyFXParser::IDENTIFIER);
      setState(622);
      match(AnyFXParser::EQ);
      setState(623);
      antlrcpp::downCast<SamplerRowContext *>(_localctx)->samplerMode = match(AnyFXParser::IDENTIFIER);
      setState(624);
      match(AnyFXParser::SC);

              std::string flag((antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag1 != nullptr ? antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag1->getText() : ""));
              _localctx->row.SetString(flag, (antlrcpp::downCast<SamplerRowContext *>(_localctx)->samplerMode != nullptr ? antlrcpp::downCast<SamplerRowContext *>(_localctx)->samplerMode->getText() : ""));
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(626);
      antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag2 = match(AnyFXParser::IDENTIFIER);
      setState(627);
      match(AnyFXParser::EQ);
      setState(628);
      antlrcpp::downCast<SamplerRowContext *>(_localctx)->expressionContext = expression();
      setState(629);
      match(AnyFXParser::SC);

              std::string flag((antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag2 != nullptr ? antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag2->getText() : ""));
              _localctx->row.SetExpression(flag, antlrcpp::downCast<SamplerRowContext *>(_localctx)->expressionContext->tree);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(632);
      antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag4 = match(AnyFXParser::IDENTIFIER);
      setState(633);
      match(AnyFXParser::EQ);
      setState(634);
      match(AnyFXParser::LB);
      setState(635);
      antlrcpp::downCast<SamplerRowContext *>(_localctx)->samplerTextureListContext = samplerTextureList();
      setState(636);
      match(AnyFXParser::RB);
      setState(637);
      match(AnyFXParser::SC);

              std::string flag((antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag4 != nullptr ? antlrcpp::downCast<SamplerRowContext *>(_localctx)->flag4->getText() : ""));

              if (flag == "Samplers") _localctx->row.SetTextures(antlrcpp::downCast<SamplerRowContext *>(_localctx)->samplerTextureListContext->list);
              else					_localctx->row.SetString(flag, "Incorrectly formatted texture list");
          
      break;
    }

    default:
      break;
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

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::EQ() {
  return getTokens(AnyFXParser::EQ);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::EQ(size_t i) {
  return getToken(AnyFXParser::EQ, i);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::RP() {
  return getToken(AnyFXParser::RP, 0);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::SC() {
  return getToken(AnyFXParser::SC, 0);
}

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::IDENTIFIER() {
  return getTokens(AnyFXParser::IDENTIFIER);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::IDENTIFIER(size_t i) {
  return getToken(AnyFXParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::ProgramRowContext::CO() {
  return getTokens(AnyFXParser::CO);
}

tree::TerminalNode* AnyFXParser::ProgramRowContext::CO(size_t i) {
  return getToken(AnyFXParser::CO, i);
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
  enterRule(_localctx, 50, AnyFXParser::RuleProgramRow);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(670);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(642);
        antlrcpp::downCast<ProgramRowContext *>(_localctx)->shader = match(AnyFXParser::IDENTIFIER);
        setState(643);
        match(AnyFXParser::EQ);
        setState(644);
        antlrcpp::downCast<ProgramRowContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
        setState(645);
        match(AnyFXParser::LP);
        setState(650);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == AnyFXParser::IDENTIFIER) {
          setState(646);
          antlrcpp::downCast<ProgramRowContext *>(_localctx)->var = match(AnyFXParser::IDENTIFIER);
          setState(647);
          match(AnyFXParser::EQ);
          setState(648);
          antlrcpp::downCast<ProgramRowContext *>(_localctx)->implementation = match(AnyFXParser::IDENTIFIER);
           _localctx->row.SetSubroutineMapping((antlrcpp::downCast<ProgramRowContext *>(_localctx)->var != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->var->getText() : ""), (antlrcpp::downCast<ProgramRowContext *>(_localctx)->implementation != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->implementation->getText() : "")); 
                      
        }
        setState(659);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AnyFXParser::CO) {
          setState(652);
          match(AnyFXParser::CO);
          setState(653);
          antlrcpp::downCast<ProgramRowContext *>(_localctx)->var2 = match(AnyFXParser::IDENTIFIER);
          setState(654);
          match(AnyFXParser::EQ);
          setState(655);
          antlrcpp::downCast<ProgramRowContext *>(_localctx)->implementation2 = match(AnyFXParser::IDENTIFIER);
           _localctx->row.SetSubroutineMapping((antlrcpp::downCast<ProgramRowContext *>(_localctx)->var2 != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->var2->getText() : ""), (antlrcpp::downCast<ProgramRowContext *>(_localctx)->implementation2 != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->implementation2->getText() : "")); 
                      
          setState(661);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(662);
        match(AnyFXParser::RP);
        setState(663);
        match(AnyFXParser::SC);

                std::string shaderString((antlrcpp::downCast<ProgramRowContext *>(_localctx)->shader != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->shader->getText() : ""));
                _localctx->row.SetString(shaderString, (antlrcpp::downCast<ProgramRowContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->name->getText() : ""));
            
        break;
      }

      case AnyFXParser::T__13: {
        enterOuterAlt(_localctx, 2);
        setState(665);
        match(AnyFXParser::T__13);
        setState(666);
        match(AnyFXParser::EQ);
        setState(667);
        antlrcpp::downCast<ProgramRowContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
        setState(668);
        match(AnyFXParser::SC);

                _localctx->row.SetString("RenderState", (antlrcpp::downCast<ProgramRowContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<ProgramRowContext *>(_localctx)->name->getText() : ""));
            
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

tree::TerminalNode* AnyFXParser::AnnotationContext::LL() {
  return getToken(AnyFXParser::LL, 0);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::RR() {
  return getToken(AnyFXParser::RR, 0);
}

std::vector<AnyFXParser::TypeContext *> AnyFXParser::AnnotationContext::type() {
  return getRuleContexts<AnyFXParser::TypeContext>();
}

AnyFXParser::TypeContext* AnyFXParser::AnnotationContext::type(size_t i) {
  return getRuleContext<AnyFXParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationContext::EQ() {
  return getTokens(AnyFXParser::EQ);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::EQ(size_t i) {
  return getToken(AnyFXParser::EQ, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::AnnotationContext::SC() {
  return getTokens(AnyFXParser::SC);
}

tree::TerminalNode* AnyFXParser::AnnotationContext::SC(size_t i) {
  return getToken(AnyFXParser::SC, i);
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
  enterRule(_localctx, 52, AnyFXParser::RuleAnnotation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(672);
    match(AnyFXParser::LL);
    setState(689);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::IDENTIFIER) {
      setState(673);
      antlrcpp::downCast<AnnotationContext *>(_localctx)->typeContext = type();
      setState(674);
      antlrcpp::downCast<AnnotationContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
      setState(675);
      match(AnyFXParser::EQ);
      setState(682);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AnyFXParser::QO:
        case AnyFXParser::Q: {
          setState(676);
          antlrcpp::downCast<AnnotationContext *>(_localctx)->stringContext = string();
           _localctx->annot.AddString(antlrcpp::downCast<AnnotationContext *>(_localctx)->stringContext->val); 
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
          setState(679);
          antlrcpp::downCast<AnnotationContext *>(_localctx)->expressionContext = expression();
           _localctx->annot.AddExpression(antlrcpp::downCast<AnnotationContext *>(_localctx)->expressionContext->tree); 
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(684);
      match(AnyFXParser::SC);
       _localctx->annot.AddType(antlrcpp::downCast<AnnotationContext *>(_localctx)->typeContext->ty); _localctx->annot.AddName((antlrcpp::downCast<AnnotationContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<AnnotationContext *>(_localctx)->name->getText() : ""));  
      setState(691);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(692);
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

tree::TerminalNode* AnyFXParser::ProgramContext::LB() {
  return getToken(AnyFXParser::LB, 0);
}

tree::TerminalNode* AnyFXParser::ProgramContext::RB() {
  return getToken(AnyFXParser::RB, 0);
}

tree::TerminalNode* AnyFXParser::ProgramContext::SC() {
  return getToken(AnyFXParser::SC, 0);
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
  enterRule(_localctx, 54, AnyFXParser::RuleProgram);

          antlrcpp::downCast<ProgramContext *>(_localctx)->prog =  alloc.Alloc<Program>();
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    match(AnyFXParser::T__14);
    setState(696);
    antlrcpp::downCast<ProgramContext *>(_localctx)->name = match(AnyFXParser::IDENTIFIER);
     SetupFile(_localctx->prog, _input); 
    setState(701);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::LL) {
      setState(698);
      antlrcpp::downCast<ProgramContext *>(_localctx)->annotationContext = annotation();
       _localctx->prog->SetAnnotation(antlrcpp::downCast<ProgramContext *>(_localctx)->annotationContext->annot); 
    }
    setState(703);
    match(AnyFXParser::LB);
     _localctx->prog->SetName((antlrcpp::downCast<ProgramContext *>(_localctx)->name != nullptr ? antlrcpp::downCast<ProgramContext *>(_localctx)->name->getText() : ""));  
    setState(710);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::T__13

    || _la == AnyFXParser::IDENTIFIER) {
      setState(705);
      antlrcpp::downCast<ProgramContext *>(_localctx)->programRowContext = programRow();
       _localctx->prog->ConsumeRow(antlrcpp::downCast<ProgramContext *>(_localctx)->programRowContext->row); 
      setState(712);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(713);
    match(AnyFXParser::RB);
    setState(714);
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
  enterRule(_localctx, 56, AnyFXParser::RuleExpression);

                          antlrcpp::downCast<ExpressionContext *>(_localctx)->tree =  nullptr;
                      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(716);
    antlrcpp::downCast<ExpressionContext *>(_localctx)->binaryexp7Context = binaryexp7();
     antlrcpp::downCast<ExpressionContext *>(_localctx)->tree =  antlrcpp::downCast<ExpressionContext *>(_localctx)->binaryexp7Context->tree; 
   
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp7Context::LOGICOR() {
  return getTokens(AnyFXParser::LOGICOR);
}

tree::TerminalNode* AnyFXParser::Binaryexp7Context::LOGICOR(size_t i) {
  return getToken(AnyFXParser::LOGICOR, i);
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
  enterRule(_localctx, 58, AnyFXParser::RuleBinaryexp7);

                          Expression* prev = nullptr;
                          antlrcpp::downCast<Binaryexp7Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(719);
    antlrcpp::downCast<Binaryexp7Context *>(_localctx)->e1 = binaryexp6();
     antlrcpp::downCast<Binaryexp7Context *>(_localctx)->tree =  antlrcpp::downCast<Binaryexp7Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(727);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICOR) {
      setState(721);
      match(AnyFXParser::LOGICOR);
      setState(722);
      antlrcpp::downCast<Binaryexp7Context *>(_localctx)->e2 = binaryexp6();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = alloc.Alloc<BinaryExpression>("||", prev, antlrcpp::downCast<Binaryexp7Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = alloc.Alloc<BinaryExpression>("||", antlrcpp::downCast<Binaryexp7Context *>(_localctx)->e1->tree, antlrcpp::downCast<Binaryexp7Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              antlrcpp::downCast<Binaryexp7Context *>(_localctx)->tree =  lhs;
                          
      setState(729);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp6Context::LOGICAND() {
  return getTokens(AnyFXParser::LOGICAND);
}

tree::TerminalNode* AnyFXParser::Binaryexp6Context::LOGICAND(size_t i) {
  return getToken(AnyFXParser::LOGICAND, i);
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
  enterRule(_localctx, 60, AnyFXParser::RuleBinaryexp6);

                          Expression* prev = nullptr;
                          antlrcpp::downCast<Binaryexp6Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(730);
    antlrcpp::downCast<Binaryexp6Context *>(_localctx)->e1 = binaryexp5();
     antlrcpp::downCast<Binaryexp6Context *>(_localctx)->tree =  antlrcpp::downCast<Binaryexp6Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(738);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICAND) {
      setState(732);
      match(AnyFXParser::LOGICAND);
      setState(733);
      antlrcpp::downCast<Binaryexp6Context *>(_localctx)->e2 = binaryexp5();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = alloc.Alloc<BinaryExpression>("&&", prev, antlrcpp::downCast<Binaryexp6Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = alloc.Alloc<BinaryExpression>("&&", antlrcpp::downCast<Binaryexp6Context *>(_localctx)->e1->tree, antlrcpp::downCast<Binaryexp6Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              antlrcpp::downCast<Binaryexp6Context *>(_localctx)->tree =  lhs;
                          
      setState(740);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp5Context::LOGICEQ() {
  return getTokens(AnyFXParser::LOGICEQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp5Context::LOGICEQ(size_t i) {
  return getToken(AnyFXParser::LOGICEQ, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp5Context::NOTEQ() {
  return getTokens(AnyFXParser::NOTEQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp5Context::NOTEQ(size_t i) {
  return getToken(AnyFXParser::NOTEQ, i);
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
  enterRule(_localctx, 62, AnyFXParser::RuleBinaryexp5);

                          Expression* prev = nullptr;
                          antlrcpp::downCast<Binaryexp5Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(741);
    antlrcpp::downCast<Binaryexp5Context *>(_localctx)->e1 = binaryexp4();
     antlrcpp::downCast<Binaryexp5Context *>(_localctx)->tree =  antlrcpp::downCast<Binaryexp5Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(749);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::LOGICEQ

    || _la == AnyFXParser::NOTEQ) {
      setState(743);
      antlrcpp::downCast<Binaryexp5Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::LOGICEQ

      || _la == AnyFXParser::NOTEQ)) {
        antlrcpp::downCast<Binaryexp5Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(744);
      antlrcpp::downCast<Binaryexp5Context *>(_localctx)->e2 = binaryexp4();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp5Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp5Context *>(_localctx)->op->getText() : ""), prev, antlrcpp::downCast<Binaryexp5Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp5Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp5Context *>(_localctx)->op->getText() : ""), antlrcpp::downCast<Binaryexp5Context *>(_localctx)->e1->tree, antlrcpp::downCast<Binaryexp5Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              antlrcpp::downCast<Binaryexp5Context *>(_localctx)->tree =  lhs;
                          
      setState(751);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::LESS() {
  return getTokens(AnyFXParser::LESS);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::LESS(size_t i) {
  return getToken(AnyFXParser::LESS, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::GREATER() {
  return getTokens(AnyFXParser::GREATER);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::GREATER(size_t i) {
  return getToken(AnyFXParser::GREATER, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::LESSEQ() {
  return getTokens(AnyFXParser::LESSEQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::LESSEQ(size_t i) {
  return getToken(AnyFXParser::LESSEQ, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp4Context::GREATEREQ() {
  return getTokens(AnyFXParser::GREATEREQ);
}

tree::TerminalNode* AnyFXParser::Binaryexp4Context::GREATEREQ(size_t i) {
  return getToken(AnyFXParser::GREATEREQ, i);
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
  enterRule(_localctx, 64, AnyFXParser::RuleBinaryexp4);

                          Expression* prev = nullptr;
                          antlrcpp::downCast<Binaryexp4Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(752);
    antlrcpp::downCast<Binaryexp4Context *>(_localctx)->e1 = binaryexp3();
     antlrcpp::downCast<Binaryexp4Context *>(_localctx)->tree =  antlrcpp::downCast<Binaryexp4Context *>(_localctx)->e1->tree;	_localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(760);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16492674416640) != 0)) {
      setState(754);
      antlrcpp::downCast<Binaryexp4Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 16492674416640) != 0))) {
        antlrcpp::downCast<Binaryexp4Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(755);
      antlrcpp::downCast<Binaryexp4Context *>(_localctx)->e2 = binaryexp3();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp4Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp4Context *>(_localctx)->op->getText() : ""), prev, antlrcpp::downCast<Binaryexp4Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp4Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp4Context *>(_localctx)->op->getText() : ""), antlrcpp::downCast<Binaryexp4Context *>(_localctx)->e1->tree, antlrcpp::downCast<Binaryexp4Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              antlrcpp::downCast<Binaryexp4Context *>(_localctx)->tree =  lhs;
                          
      setState(762);
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

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp3Context::ADD_OP() {
  return getTokens(AnyFXParser::ADD_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp3Context::ADD_OP(size_t i) {
  return getToken(AnyFXParser::ADD_OP, i);
}

std::vector<tree::TerminalNode *> AnyFXParser::Binaryexp3Context::SUB_OP() {
  return getTokens(AnyFXParser::SUB_OP);
}

tree::TerminalNode* AnyFXParser::Binaryexp3Context::SUB_OP(size_t i) {
  return getToken(AnyFXParser::SUB_OP, i);
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
  enterRule(_localctx, 66, AnyFXParser::RuleBinaryexp3);

                          Expression* prev = nullptr;
                          antlrcpp::downCast<Binaryexp3Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(763);
    antlrcpp::downCast<Binaryexp3Context *>(_localctx)->e1 = binaryexp2();
     antlrcpp::downCast<Binaryexp3Context *>(_localctx)->tree =  antlrcpp::downCast<Binaryexp3Context *>(_localctx)->e1->tree; _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(771);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::ADD_OP

    || _la == AnyFXParser::SUB_OP) {
      setState(765);
      antlrcpp::downCast<Binaryexp3Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::ADD_OP

      || _la == AnyFXParser::SUB_OP)) {
        antlrcpp::downCast<Binaryexp3Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(766);
      antlrcpp::downCast<Binaryexp3Context *>(_localctx)->e2 = binaryexp2();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp3Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp3Context *>(_localctx)->op->getText() : ""), prev, antlrcpp::downCast<Binaryexp3Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp3Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp3Context *>(_localctx)->op->getText() : ""), antlrcpp::downCast<Binaryexp3Context *>(_localctx)->e1->tree, antlrcpp::downCast<Binaryexp3Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              antlrcpp::downCast<Binaryexp3Context *>(_localctx)->tree =  lhs;
                          
      setState(773);
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
  enterRule(_localctx, 68, AnyFXParser::RuleBinaryexp2);

                          Expression* prev = nullptr;
                          antlrcpp::downCast<Binaryexp2Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(774);
    antlrcpp::downCast<Binaryexp2Context *>(_localctx)->e1 = binaryexp1();
     antlrcpp::downCast<Binaryexp2Context *>(_localctx)->tree =  antlrcpp::downCast<Binaryexp2Context *>(_localctx)->e1->tree; _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
            
    setState(782);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AnyFXParser::DIV_OP

    || _la == AnyFXParser::MUL_OP) {
      setState(776);
      antlrcpp::downCast<Binaryexp2Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::DIV_OP

      || _la == AnyFXParser::MUL_OP)) {
        antlrcpp::downCast<Binaryexp2Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(777);
      antlrcpp::downCast<Binaryexp2Context *>(_localctx)->e2 = binaryexp1();

                              Expression* lhs = nullptr;

                              if (prev)
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp2Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp2Context *>(_localctx)->op->getText() : ""), prev, antlrcpp::downCast<Binaryexp2Context *>(_localctx)->e2->tree);
                              }
                              else
                              {
                                  lhs = alloc.Alloc<BinaryExpression>((antlrcpp::downCast<Binaryexp2Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp2Context *>(_localctx)->op->getText() : ""), antlrcpp::downCast<Binaryexp2Context *>(_localctx)->e1->tree, antlrcpp::downCast<Binaryexp2Context *>(_localctx)->e2->tree);
                              }

                              SetupFile(lhs, _input);
                              prev = lhs;
                              antlrcpp::downCast<Binaryexp2Context *>(_localctx)->tree =  lhs;
                          
      setState(784);
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
  enterRule(_localctx, 70, AnyFXParser::RuleBinaryexp1);

                          char operat = 0;
                          antlrcpp::downCast<Binaryexp1Context *>(_localctx)->tree =  nullptr;
                      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(786);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AnyFXParser::NOT

    || _la == AnyFXParser::SUB_OP) {
      setState(785);
      antlrcpp::downCast<Binaryexp1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == AnyFXParser::NOT

      || _la == AnyFXParser::SUB_OP)) {
        antlrcpp::downCast<Binaryexp1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(788);
    antlrcpp::downCast<Binaryexp1Context *>(_localctx)->e1 = binaryexpatom();

                            Expression* rhs = antlrcpp::downCast<Binaryexp1Context *>(_localctx)->e1->tree;

                            if (antlrcpp::downCast<Binaryexp1Context *>(_localctx)->op != 0)
                            {
                                operat = (antlrcpp::downCast<Binaryexp1Context *>(_localctx)->op != nullptr ? antlrcpp::downCast<Binaryexp1Context *>(_localctx)->op->getText() : "").c_str()[0];
                                rhs = alloc.Alloc<UnaryExpression>(operat, rhs);
                            }

                            SetupFile(rhs, _input);
                            antlrcpp::downCast<Binaryexp1Context *>(_localctx)->tree =  rhs;

                        
   
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
  enterRule(_localctx, 72, AnyFXParser::RuleBinaryexpatom);

                          antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  nullptr;
                      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(807);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AnyFXParser::INTEGERLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(791);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->integerliteralToken = match(AnyFXParser::INTEGERLITERAL);
         antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  alloc.Alloc<IntExpression>(atoi((antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->integerliteralToken != nullptr ? antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->integerliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
                
        break;
      }

      case AnyFXParser::FLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(793);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->floatliteralToken = match(AnyFXParser::FLOATLITERAL);
         antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  alloc.Alloc<FloatExpression>(atof((antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->floatliteralToken != nullptr ? antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->floatliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine()); 
                
        break;
      }

      case AnyFXParser::DOUBLELITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(795);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->doubleliteralToken = match(AnyFXParser::DOUBLELITERAL);
         antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  alloc.Alloc<FloatExpression>(atof((antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->doubleliteralToken != nullptr ? antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->doubleliteralToken->getText() : "").c_str())); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
                
        break;
      }

      case AnyFXParser::HEX: {
        enterOuterAlt(_localctx, 4);
        setState(797);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->hexToken = match(AnyFXParser::HEX);
         antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  alloc.Alloc<IntExpression>(strtoul((antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->hexToken != nullptr ? antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->hexToken->getText() : "").c_str(), nullptr, 16)); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
                
        break;
      }

      case AnyFXParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 5);
        setState(799);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->identifierToken = match(AnyFXParser::IDENTIFIER);
         antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  alloc.Alloc<SymbolExpression>((antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->identifierToken != nullptr ? antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->identifierToken->getText() : "")); _localctx->tree->SetLine(_input->LT(1)->getLine()); _localctx->tree->SetPosition(_input->LT(1)->getCharPositionInLine());
                
        break;
      }

      case AnyFXParser::T__0:
      case AnyFXParser::T__1: {
        enterOuterAlt(_localctx, 6);
        setState(801);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->booleanContext = boolean();

                                antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  alloc.Alloc<BoolExpression>(antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->booleanContext->val);
                                SetupFile(_localctx->tree, _input);
                            
        break;
      }

      case AnyFXParser::LP: {
        enterOuterAlt(_localctx, 7);
        setState(804);
        antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->parantexpressionContext = parantexpression();
         antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->tree =  antlrcpp::downCast<BinaryexpatomContext *>(_localctx)->parantexpressionContext->tree; 
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

tree::TerminalNode* AnyFXParser::ParantexpressionContext::LP() {
  return getToken(AnyFXParser::LP, 0);
}

AnyFXParser::ExpressionContext* AnyFXParser::ParantexpressionContext::expression() {
  return getRuleContext<AnyFXParser::ExpressionContext>(0);
}

tree::TerminalNode* AnyFXParser::ParantexpressionContext::RP() {
  return getToken(AnyFXParser::RP, 0);
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
  enterRule(_localctx, 74, AnyFXParser::RuleParantexpression);

                          antlrcpp::downCast<ParantexpressionContext *>(_localctx)->tree =  nullptr;
                      

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(809);
    match(AnyFXParser::LP);
    setState(810);
    antlrcpp::downCast<ParantexpressionContext *>(_localctx)->expressionContext = expression();
    setState(811);
    match(AnyFXParser::RP);
     antlrcpp::downCast<ParantexpressionContext *>(_localctx)->tree =  antlrcpp::downCast<ParantexpressionContext *>(_localctx)->expressionContext->tree; 
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void AnyFXParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  anyfxParserInitialize();
#else
  ::antlr4::internal::call_once(anyfxParserOnceFlag, anyfxParserInitialize);
#endif
}
