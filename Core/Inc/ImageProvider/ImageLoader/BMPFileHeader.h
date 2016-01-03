#ifndef BMPFILEHEADER_H
#define BMPFILEHEADER_H

#include "../../../../SDK/Platform.h"
namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
#pragma pack(push, 1)

			typedef struct BMPFileHeader
			{
				UInt16 type; // Тип файла ("BM" для растрового изображения).
				UInt32 size; // Размер файла в байтах.
				UInt32 reserved;
				UInt32 offset;
			} BMP_FILE_HEADER, *BMP_FILE_HEADER_PTR;

			typedef struct BMPInfoHeader
			{
				UInt32 size; // Размер заголовка в байтах.
				UInt32 width; // Ширина изображения в пикселях.
				UInt32 height; // Высота изображения в пикселях.
				UInt16 planes;
				UInt16 bitCount; // Количество бит на пиксель.
				UInt32 compression; // Тип сжатия.
				UInt32 imageSize; // Размер изображения в байтах.
				UInt32 xPixelsPerMeter;
				UInt32 yPixelsPerMeter;
				UInt32 colorUsed;
				UInt32 colorImportant;
			} BMP_INFO_HEADER, *BMP_INFO_HEADER_PTR;

			typedef struct BMPColor
			{
				UInt32 color1;
				UInt32 color2;
			} BMP_COLOR, *BMP_COLOR_PTR;

#pragma pack(pop)
		}
	}
}

#endif // BMPFILEHEADER_H