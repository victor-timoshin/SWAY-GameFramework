#ifndef TEXTUREFORMAT_H
#define TEXTUREFORMAT_H

namespace Gapi
{
	typedef enum TextureFormat
	{
		ETF_R     = 0xEAE9,
		ETF_RG    = 0x579C,
		ETF_RGB   = 0x8956,
		ETF_RGBA  = 0x6445,
		ETF_HDR   = 0xEFB1,
		ETF_DEPTH = 0xB0FC,

		EFT_BGR   = 0x91D6,
		EFT_BGRA  = 0x5B8E,
		EFT_RGB8  = 0x92AE,
		EFT_RGBA8 = 0x184D
	} TEXTURE_FORMAT;
}

#endif // TEXTUREFORMAT_H