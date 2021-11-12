#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <string>
#include <iostream>
#include <exception>

#include "opts.h"

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
	Argparser() { std::cout << __func__ << std::endl; }
	~Argparser() { std::cout << __func__ << std::endl; }
	Options::GlobalOptions* Parse(int argc, char** argv) 
	{
		std::cout << __func__ << std::endl;
		throw ArgparserException("Invalid argument in position 1");
		
		return new Options::GlobalOptions();
	}
	
private:
	
};

#endif // _ARGPARSER_H_