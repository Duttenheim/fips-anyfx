#pragma once
#include "antlr4-runtime.h"
#include "antlr4-common.h"
#include "CommonToken.h"

#include "TokenFactory.h"

using namespace antlr4;
class ANTLR4CPP_PUBLIC AnyFXToken : public CommonToken
{
public:

	AnyFXToken(size_t type) :
		CommonToken(type)
	{
	};

	AnyFXToken(std::pair<TokenSource*, CharStream*> source, size_t type, size_t channel, size_t start, size_t stop):
		CommonToken(source, type, channel, start, stop)
	{};

	AnyFXToken(size_t type, const std::string &text) :
		CommonToken(type, text)
	{};

	AnyFXToken(Token *oldToken) :
		CommonToken(oldToken)
	{
		file = ((AnyFXToken*)oldToken)->file;
	};

	std::string file;
};

class ANTLR4CPP_PUBLIC AnyFXTokenFactory : public TokenFactory<CommonToken>
{
public:


	/**
	 * Constructs a {@link CommonTokenFactory} with {@link #copyText} set to
	 * {@code false}.
	 *
	 * <p>
	 * The {@link #DEFAULT} instance should be used instead of calling this
	 * directly.</p>
	 */
	AnyFXTokenFactory();

	/**
	 * The default {@link AnyFXTokenFactory} instance.
	 *
	 * <p>
	 * This token factory does not explicitly copy token text when constructing
	 * tokens.</p>
	 */
    static TokenFactory<CommonToken>* DEFAULT;

	virtual std::unique_ptr<CommonToken> create(std::pair<TokenSource*, CharStream*> source, size_t type,
		const std::string &text, size_t channel, size_t start, size_t stop, size_t line, size_t charPositionInLine) override;

	virtual std::unique_ptr<CommonToken> create(size_t type, const std::string &text) override;
};
