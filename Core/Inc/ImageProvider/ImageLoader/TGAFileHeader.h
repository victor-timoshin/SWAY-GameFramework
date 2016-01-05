#ifndef TGAFILEHEADER_H
#define TGAFILEHEADER_H

#include "../../../../SDK/Platform.h"

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			PACK(typedef struct TGAHeader
			{
				UByte idLength;
				UByte colorMapType;
				UByte imageType;
				UInt16 colorMapOrigin;
				UInt16 colorMapLength;
				UByte colorMapDepth;
				UInt16 imageOriginX;
				UInt16 imageOriginY;
				UInt16 imageWidth;
				UInt16 imageHeight;
				UByte bitPerPixel;
				UByte descriptor;
			} TGA_FILE_HEADER, *TGA_FILE_HEADER_PTR);
		}
	}
}

#endif // TGAFILEHEADER_H