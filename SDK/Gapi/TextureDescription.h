#ifndef TEXTUREDESCRIPTION_H
#define TEXTUREDESCRIPTION_H

#include "../Platform.h"

namespace Gapi
{
	typedef struct TextureDescription
	{
		void* pixels;
		int width;
		int height;
		int pitch;
		int bpp; // bits per pixel.
		TEXTURE_FORMAT format;
		TEXTURE_FORMAT internalFormat;

		//int channels;
		//int bits;
	} LTEXTURE_DESCRIPTION, *PTEXTURE_DESCRIPTION;
}

#endif // TEXTUREDESCRIPTION_H