#ifndef TEXTUREFILTER_H
#define TEXTUREFILTER_H

#include "../Platform.h"

namespace Gapi
{
	typedef enum class TextureFilter
	{
		Unknown                = 0x6D01,
		Nearest                = 0xB943,
		Nearest_Mipmap_Nearest = 0x7D02,
		Nearest_Mipmap_Linear  = 0x4C54,
		Linear                 = 0x5F33,
		Linear_Mipmap_Nearest  = 0xFAD8,
		Linear_Mipmap_Linear   = 0x96EE,
	} TEXTURE_FILTER;
}

#endif // TEXTUREFILTER_H