#ifndef _VALUES_H_
#define _VALUES_H_

#include <istream>
#include <string>
#include <vector>


class ValuesGenerator
{
public:
	ValuesGenerator() {}
	~ValuesGenerator() {}
	
	std::vector<float>* Generate(const float start_from, const float step, const unsigned int count)
	{
		std::vector<float>* ret = new std::vector<float>;
		for (int i = 0; i < count; ++i)
		{
			float arg = (start_from + (i*step));
			float f = sin(arg);
			ret->push_back(f);
		}
		return ret;
	}
	
};

#endif // _VALUES_H_