#ifndef TEXTUREFORMATS_H
#define TEXTUREFORMATS_H

namespace Gapi
{
	typedef enum TextureFormats
	{
		ETF_R     = 0xEAE9,
		ETF_RG    = 0x579C,
		ETF_RGB   = 0x8956,
		ETF_RGBA  = 0x6445,
		ETF_HDR   = 0xEFB1,
		ETF_DEPTH = 0xB0FC
	} TEXTURE_FORMATS;
}

#endif // TEXTUREFORMATS_H