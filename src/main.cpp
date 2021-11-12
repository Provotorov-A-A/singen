#include "opts.h"
#include "argparser.h"
#include "errcodes.h"
#include "values_gen.h"
#include "converter.h"
#include <boost/program_options.hpp	>

using namespace Error;
using namespace Options;

void PrintResultMessage(const ErrCode err)
{
	if (err != ErrCode::SUCCESS)
	{
		std::cout << error_msg[err] << std::endl;
	}
}

int main(int argc, char** argv)
{
	ErrCode ret_code = ErrCode::SUCCESS;
	GlobalOptions* options = nullptr;
	Argparser arg_parser;

	//-----------------------------------------
	options = arg_parser.Parse(argc, argv);
	if (nullptr == options)
	{
		return EXIT_FAILURE;
	}
	
	options->bitwidth = 16;
	options->range_start = 0;
	options->count = 512;
	options->step = (2*M_PI)/options->count;
	options->items_per_line = 8;
	options->number_format.base = Options::DEC;
	options->number_format.width = 6;
	options->number_format.showbase = false;
	options->number_format.fill =' ';
	options->number_format.showpositive = false;
	options->number_format.uppercase = true;
	options->number_format.precision = 3;
	
	// TODO: Option checker
	
	//-----------------------------------------
	// TODO: if help - print help

	//-----------------------------------------
	// Main functionality
	
	// Produce values 
	ValuesGenerator vg;
	std::vector<float>* values = vg.Generate(options->range_start, options->step, options->count);
	
	// Convert values to output format
	Converter converter;
	std::string* output_data = converter.Convert(values, options);
	std::cout << "---------------------" << std::endl;
	std::cout << *output_data;
	delete values;
	
	// // Perform output
	// OutputGenerator og;
	// og.Generate(output_data, options);
	
	delete output_data;
	delete options;
	return EXIT_SUCCESS;
}