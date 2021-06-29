
    #include <string>
    #include <vector>
    #include "anyfxtoken.h"


// Generated from g:\anyfxv3\fips-anyfx\code\compiler\ext\antlr4\grammar\AnyFX.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  AnyFXLexer : public antlr4::Lexer {
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

  AnyFXLexer(antlr4::CharStream *input);
  ~AnyFXLexer();


  #include <iostream>

  misc::Interval interval;
  std::string currentFile;
  int currentLine = 0;

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

