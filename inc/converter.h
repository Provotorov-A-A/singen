#ifndef _CONVERTER_H_
#define _CONVERTER_H_

#include "opts.h"

#include <istream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

#define INTERNAL_STORAGE_TYPE_BITWIDTH				64


#if ( INTERNAL_STORAGE_TYPE_BITWIDTH > 128 )		
	#error "INTERNAL_STORAGE_TYPE_BITWIDTH is too big"
#elif ( INTERNAL_STORAGE_TYPE_BITWIDTH > 64 )		
	#define INTERNAL_STORAGE_TYPE 					int128_t
#elif ( INTERNAL_STORAGE_TYPE_BITWIDTH > 32 )		
	#define INTERNAL_STORAGE_TYPE 					int64_t
#elif ( INTERNAL_STORAGE_TYPE_BITWIDTH > 16 )		
	#define INTERNAL_STORAGE_TYPE 					int32_t
#elif ( INTERNAL_STORAGE_TYPE_BITWIDTH > 8 )		
	#define INTERNAL_STORAGE_TYPE 					int16_t
#else
	#define INTERNAL_STORAGE_TYPE 					int8_t
#endif

class Converter
{
public:
	Converter(){}
	~Converter(){}
	
	std::string* Convert(const std::vector<float>* values, const Options::GlobalOptions* options)
	{
		unsigned int base = pow(2, options->bitwidth-1);
		std::ostringstream os;
		for (unsigned int i = 0; i < values->size(); ++i)
		{
			float v = values->at(i);
			
			INTERNAL_STORAGE_TYPE intVal = lround(v*base);
			bool is_neg = (intVal < 0);
			INTERNAL_STORAGE_TYPE result = intVal;
			if (Options::NumberBase::HEX == options->number_format.base)
			{
				if (is_neg)
				{
					result &= LowBitsMask<INTERNAL_STORAGE_TYPE>(options->bitwidth);
				}
			}
			
			FormatStream(os, options->number_format);	
			os << result;
			
			if (i != (values->size()-1) )
			{
				os << ", ";
			}
			if ((options->items_per_line-1) == (i%options->items_per_line))
			{
				os << std::endl;
			}
		}
		std::string* ret = new std::string();
		*ret = os.str();
		return ret;
	}
	
private:
	template <typename ResultType>
	ResultType LowBitsMask(unsigned int bits) const
	{
		ResultType mask = 0;
		for (unsigned int i = 0; i < bits; ++i)
		{
			mask = (mask << 1) | 0x1;;
		}
		return mask;
	}
	
	void FormatStream(std::ostringstream& os, const Options::NumberFormat& format)
	{
		os.setf(std::ios_base::right, 	std::ios_base::adjustfield);
		if (Options::NumberBase::HEX == format.base)
		{
			os.setf(std::ios_base::hex, 	std::ios_base::basefield);
			if (format.showbase) 		os.setf(std::ios_base::showbase); 		else os.unsetf(std::ios_base::showbase);
			if (format.uppercase) 		os.setf(std::ios_base::uppercase); 		else os.unsetf(std::ios_base::uppercase);
			os.fill(format.fill);
			os.width(format.width);
		}
		else if (Options::NumberBase::DEC == format.base)
		{
			os.setf(std::ios_base::dec,	std::ios_base::basefield);
			if (format.showpositive) 	os.setf(std::ios_base::showpos); 		else os.unsetf(std::ios_base::showpos);
			os.fill(format.fill);
			os.width(format.width);
		}
	}
};

#endif // _CONVERTER_H_