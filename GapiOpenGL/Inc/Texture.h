#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../SDK/Gapi/TextureBase.h"
#include "../../SDK/Gapi/TextureTarget.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class Texture : public ITextureBase
	{
	public:
		static UInt GetTextureFormat(Gapi::TEXTURE_FORMAT format);

		static UInt GetTextureTarget(Gapi::TEXTURE_TARGET target);
		static std::string GetTextureTargetToString(UInt target);

		static UInt GetMipmapHint(Gapi::MIPMAPHINT hint);

		/// <summary>Конструктор класса.</summary>
		Texture(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Texture(void);

		virtual void Load(Gapi::PTEXTURE_DESCRIPTION textureDesc);

		virtual void CreateNullTexture(int width, int height);

		virtual void CreateFromMemory(const void* data, int width, int height, TEXTURE_FORMAT format);

		virtual void Upload(int level, int xOffset, int yOffset, int width, int height, TEXTURE_FORMAT format, const void* pixels);

		virtual void GenerateMipmaps(Gapi::MIPMAPHINT hint);

		virtual void SetMipmapRange(int minLevel, int maxLevel);

		virtual bool HasMipmapped(void) const;

		virtual void SetActive(int slot);

		virtual void Bind(void);

		virtual void Unbind(void);

		virtual void SetUnpackAlignement(UInt param);

		/// <summary>Получает уникальный идентификатор.</summary>
		virtual UInt GetID(void) const;
		
		/// <summary>Получает ширину текстуры.</summary>
		virtual UInt GetWidth(void) const;

		/// <summary>Получает высоту текстуры.</summary>
		virtual UInt GetHeight(void) const;

		virtual bool IsValid(void) const;

	private:
		UInt _textureID;
		UByte* _pixels;

		bool _mipmapped;
		bool _compressed;
	};
}

#endif // TEXTURE_H