#ifndef TEXTUREBASE_H
#define TEXTUREBASE_H

#include "../../SDK/Gapi/TextureDescription.h"
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

		virtual void Load(Gapi::TEXTURE_DESCRIPTION_PTR textureDesc) = 0;

		virtual void CreateNullTexture(int width, int height) = 0;

		virtual void CreateFromMemory(const void* data, int width, int height, TEXTURE_FORMAT format) = 0;

		virtual void Upload(int level, int xOffset, int yOffset, int width, int height, TEXTURE_FORMAT format, const void* pixels) = 0;

		virtual void GenerateMipmaps(Gapi::MIPMAPHINT hint) = 0;

		virtual void SetMipmapRange(int minLevel, int maxLevel) = 0;

		virtual bool HasMipmapped(void) const = 0;

		virtual void SetActive(int slot) = 0;

		virtual void Bind(void) = 0;

		virtual void Unbind(void) = 0;

		virtual void SetUnpackAlignement(UInt param) = 0;

		/// <summary>Получает уникальный идентификатор.</summary>
		virtual UInt GetID(void) const = 0;

		/// <summary>Получает ширину текстуры.</summary>
		virtual UInt GetWidth(void) const = 0;

		/// <summary>Получает высоту текстуры.</summary>
		virtual UInt GetHeight(void) const = 0;
	};

	CORE_API ITextureBase* RegisterTexture(void);
}

#endif // TEXTUREBASE_H