#ifndef TEXTUREWRAP_H
#define TEXTUREWRAP_H

#include "../Platform.h"

namespace Gapi
{
	typedef enum class TextureWrap
	{
		Unknown = 0xF7BE,
		Repeat  = 0x6EC0,
		Clamp   = 0xC50F
	} TEXTURE_WRAP;
}

#endif // TEXTUREWRAP_H