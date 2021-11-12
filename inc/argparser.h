#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <string>
#include <iostream>
#include <exception>

#include "opts.h"
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

class ArgparserException
{
public:
	ArgparserException(const string& msg) : m_msg(msg)
	{
		
	}
	
	string ToString() const
	{
		return m_msg;
	}
	
private:
	string m_msg;
};

class Argparser
{
public:
	Argparser() { }
	~Argparser() { }
	Options::GlobalOptions* Parse(int argc, char** argv) 
	{
		Options::GlobalOptions* opts = new Options::GlobalOptions();
		return opts;
	}
	
private:
	
};

#endif // _ARGPARSER_H_