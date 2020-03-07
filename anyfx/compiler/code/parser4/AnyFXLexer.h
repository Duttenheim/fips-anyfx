
	#include <string>
	#include <vector>
	extern std::vector<std::string> uncaughtPreprocessorDirectives;
	#include "anyfxtoken.h"


// Generated from antlr4/grammar/AnyFX.g4 by ANTLR 4.7.1

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
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, T__67 = 68, 
    T__68 = 69, SC = 70, CO = 71, COL = 72, LP = 73, RP = 74, LB = 75, RB = 76, 
    LL = 77, RR = 78, DOT = 79, NOT = 80, EQ = 81, QO = 82, QU = 83, AND = 84, 
    OR = 85, Q = 86, NU = 87, FORWARDSLASH = 88, LESS = 89, LESSEQ = 90, 
    GREATER = 91, GREATEREQ = 92, LOGICEQ = 93, NOTEQ = 94, LOGICAND = 95, 
    LOGICOR = 96, MOD = 97, UNDERSC = 98, ADD_OP = 99, SUB_OP = 100, DIV_OP = 101, 
    MUL_OP = 102, INTEGERLITERAL = 103, COMMENT = 104, ML_COMMENT = 105, 
    FLOATLITERAL = 106, EXPONENT = 107, DOUBLELITERAL = 108, HEX = 109, 
    IDENTIFIER = 110, WS = 111
  };

  AnyFXLexer(antlr4::CharStream *input);
  ~AnyFXLexer();


  	#include <iostream>

  	void ParseLineDirective(const std::string& str)
  	{

  	}
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

