//------------------------------------------------------------------------------
//  textwriter.cc
//  (C) 2013 gscept
//------------------------------------------------------------------------------
#include "textwriter.h"
#include <assert.h>
#include <sstream>
#include <algorithm>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
TextWriter::TextWriter() :
	isOpen(false)
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
TextWriter::~TextWriter()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool
TextWriter::Open()
{
	assert(this->path.size() > 0);
	this->output.open(this->path.c_str(), std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
	this->isOpen = this->output.is_open();
	return this->isOpen;
}

//------------------------------------------------------------------------------
/**
*/
void 
TextWriter::Close()
{
	assert(this->isOpen);
	
	this->output.close();
	this->output.clear();
}

//------------------------------------------------------------------------------
/**
*/
void
TextWriter::WriteString(const std::string& s)
{
	// copy string
	std::string copy = s;

	// write string
	this->output.write(s.c_str(), s.length());
}

//------------------------------------------------------------------------------
/**
*/
void
TextWriter::WriteChar(char c)
{
	this->output.put(c);
}

} // namespace AnyFX