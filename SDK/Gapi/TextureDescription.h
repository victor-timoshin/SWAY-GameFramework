#ifndef TEXTUREDESCRIPTION_H
#define TEXTUREDESCRIPTION_H

#include "../Platform.h"

namespace Gapi
{
	typedef struct TextureDescription
	{
		void* pixels;
		UInt width;
		UInt height;
		int pitch;
		int bpp; // bits per pixel.
		TEXTURE_FORMAT format;
		TEXTURE_FORMAT internalFormat;

		//int channels;
		//int bits;
	} TEXTURE_DESCRIPTION, *TEXTURE_DESCRIPTION_PTR;
}

#endif // TEXTUREDESCRIPTION_H