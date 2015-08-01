#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include "../../SDK/Platform.h"

namespace Gapi
{
	class ITextureBase
	{
	public:
		/// <summary>����������� ������.</summary>
		ITextureBase(void) {}

		/// <summary>���������� ������.</summary>
		virtual ~ITextureBase(void) {}

		virtual void Create(int format, int width, int height, const void* data, int mipCount) = 0;

		virtual void Set(int slot) = 0;
	};
}

#endif // TEXTUREBASE_H