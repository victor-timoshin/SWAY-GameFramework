#ifndef BMPLOADER_H
#define BMPLOADER_H

#include "../../../../SDK/Gapi/TextureBase.h"
#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../Core/Inc/Utils/FileStream.h"
#include "../../../../SDK/Core/ImageProvider/ImageLoader/ImageLoaderBase.h"

#pragma pack(push, 1)

typedef struct BitmapFileHeader
{
	UInt16 type; // file type should be "BM" for bitmap
	UInt32 size; // total file size
	UInt32 reserved;
	UInt32 offset; // offset to image data
} LBITMAP_FILE_HEADER, *PBITMAP_FILE_HEADER;

typedef struct BitmapInfoHeader
{
	UInt32 size; // header size, in bytes
	UInt32 width; // width, in pixels
	UInt32 height; // height, in pixels
	UInt16 planes;
	UInt16 bitsPerPixel; // number of bits per pixel
	UInt32 compression; // compression type
	UInt32 sizeImage;
	UInt32 xPixelsPerMeter; // horizontal resolution
	UInt32 yPixelsPerMeter; // vertical resolution
	UInt32 clrUsed; // number of colors used
	UInt32 clrsImp; // number of colors required
} LBITMAP_INFO_HEADER, *PBITMAP_INFO_HEADER;

typedef struct BitmapColor
{
	UInt32 clr1;
	UInt32 clr2;
} LBITMAP_COLOR, *PBITMAP_COLOR;

#pragma pack(pop)

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			class BMPLoader : public IImageLoaderBase
			{
			public:
				/// <summary>Конструктор класса.</summary>
				BMPLoader(void);

				/// <summary>Деструктор класса.</summary>
				virtual ~BMPLoader(void);

				virtual Gapi::TEXTURE_DESCRIPTION_PTR LoadFromStream(std::ifstream& source);

				Gapi::TEXTURE_DESCRIPTION_PTR LoadFromFile(const std::string& path);
			};
		}
	}
}

#endif // BMPLOADER_H