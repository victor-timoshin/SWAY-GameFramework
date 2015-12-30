#ifndef COMPRESSTYPE_H
#define COMPRESSTYPE_H

#include "../Platform.h"

namespace Gapi
{
	typedef enum class CompressType
	{
		None,
		DXT1,
		DXT3,
		DXT5
	} COMPRESS_TYPE;
}

#endif // COMPRESSTYPE_H