#ifndef _ERRCODES_H_
#define _ERRCODES_H_

#include <cstdlib>
#include <unordered_map>

namespace Error
{
	
enum class ErrCode: int
{
	SUCCESS = EXIT_SUCCESS,
	MALLOC = 1,
	BADARGS = 2,
	FILEOPS = 3,
	UNEXPECTED_EX = 4,
};

using ErrorMessageMap = std::unordered_map<ErrCode, string>;
ErrorMessageMap error_msg = 
{
	{ErrCode::MALLOC, "Memory allocation error"},
};

}; // namespace Error

#endif // _ERRCODES_H_