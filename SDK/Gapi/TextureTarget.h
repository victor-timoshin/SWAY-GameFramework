#ifndef TEXTURETARGET_H
#define TEXTURETARGET_H

#include "../Platform.h"

namespace Gapi
{
	typedef enum class TextureTarget
	{
		Unknown           = 0x0DE1,
		Texture_2D        = 0xF2DF, // Двухмерная текстура.
		Texture_2D_Array  = 0x347E,
		Texture_Rectangle = 0xA15A,
		Texture_Cube_Map  = 0x4E2D // Кубическая текстура.
	} TEXTURE_TARGET;
}

#endif // TEXTURETARGET_H