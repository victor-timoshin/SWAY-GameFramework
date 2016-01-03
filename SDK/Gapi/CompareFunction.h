#ifndef COMPAREFUNCTION_H
#define COMPAREFUNCTION_H

namespace Gapi
{
	typedef enum CompareFunction
	{
		Never          = 0xC7A6,
		Always         = 0xA8C7,
		Equal          = 0xA1A1,
		NotEqual       = 0xE9E3,
		Less           = 0xCD24,
		LessOrEqual    = 0x648D,
		Greater        = 0x981F,
		GreaterOrEqual = 0x5AE0
	} COMPARE_FUNCTION;
}

#endif // COMPAREFUNCTION_H