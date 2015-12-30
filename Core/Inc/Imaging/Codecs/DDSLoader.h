#ifndef DDSLOADER_H
#define DDSLOADER_H

#include "../../../../SDK/Gapi/TextureBase.h"
#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Core/Imaging/LoaderBase.h"

namespace Imaging
{
	static const size_t DDS_PF_FOURCC = 0x4;

	static const UInt DXT1_MAGIC_NUMBER = 0x31545844;
	static const UInt DXT2_MAGIC_NUMBER = 0x32545844;
	static const UInt DXT3_MAGIC_NUMBER = 0x33545844;
	static const UInt DXT4_MAGIC_NUMBER = 0x34545844;
	static const UInt DXT5_MAGIC_NUMBER = 0x35545844;

	typedef struct DDSPixelFormat
	{
		UInt dwSize;
		UInt dwFlags;
		UInt dwFourCC;
		UInt dwRGBBitCount;
		UInt dwRBitMask;
		UInt dwGBitMask;
		UInt dwBBitMask;
		UInt dwABitMask;
	} DDS_PIXELFORMAT;

	typedef struct DDSHeader
	{
		UInt dwSize;
		UInt dwFlags;
		UInt dwHeight;
		UInt dwWidth;
		UInt dwPitchOrLinearSize;
		UInt dwDepth;
		UInt dwMipMapCount;
		UInt dwReserved1[11];
		DDS_PIXELFORMAT pixelFormat;
		UInt dwCaps;
		UInt dwCaps2;
		UInt dwCaps3;
		UInt dwCaps4;
		UInt dwReserved2;
	} DDS_HEADER;

	class DDSLoader// : public Imaging::ILoaderBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		DDSLoader(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~DDSLoader(void);

		virtual void LoadFromStream(std::istream& source);
	};
}

#endif // DDSLOADER_H