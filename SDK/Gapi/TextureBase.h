#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include "../../SDK/Platform.h"

namespace Gapi
{
	class ITextureBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ITextureBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ITextureBase(void) {}

		virtual void CreateFromMemory(const void* data, int width, int height, TEXTURE_FORMATS format) = 0;

		virtual void Create(int format, int width, int height, const void* data, int mipCount) = 0;

		virtual void SetActive(int slot) = 0;

		virtual void Bind(void) = 0;

		virtual void Unbind(void) = 0;

		virtual void SetPixelStore(UInt param) = 0;

		virtual UInt GetID(void) const = 0;
	};

	CORE_API ITextureBase* RegisterTexture(void);
}

#endif // TEXTUREBASE_H