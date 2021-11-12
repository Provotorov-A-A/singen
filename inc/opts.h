#ifndef _OPTS_H_
#define _OPTS_H_

#include <string>
#include <iostream>
#include <iomanip>

namespace Options
{
	typedef enum
	{
		DEC,
		HEX,
		BIN
	} NumberBase;
	
	struct NumberFormat
	{
		NumberBase base;
		unsigned int width;
		bool showbase;
		char fill;
		bool showpositive;
		bool uppercase;
		unsigned int precision;
		
		NumberFormat() : base(NumberBase::DEC), showbase(false), fill('0'), showpositive(false), uppercase(true){}
	};
	
	typedef enum
	{
		OutputDestination_STDOUT,
		OutputDestination_FILE,
	} OutputDestination;
	
	using GlobalOptions = class
	{
		public:
			unsigned int bitwidth;
			float step;
			float range_start;
			float range_end;
			unsigned int count;
			NumberFormat number_format;
			OutputDestination destination;
			std::string filename;
			unsigned int items_per_line;
			void Print()
			{
				std::cout << "bitwidth = " << bitwidth << std::endl;
				std::cout << "range_start = " << range_start << std::endl;
				std::cout << "step = " << step << std::endl;
				std::cout << "count = " << count << std::endl;
			}
			
	};
} // namespace Options

#endif // _OPTS_H_