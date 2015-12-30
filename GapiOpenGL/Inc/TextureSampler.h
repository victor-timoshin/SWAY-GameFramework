#ifndef TEXTURESAMPLER_H
#define TEXTURESAMPLER_H

#include "../../SDK/Gapi/TextureSamplerBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class TextureSampler : public ITextureSamplerBase
	{
	public:
		static UInt GetTextureFilter(Gapi::TEXTURE_FILTER filter);
		static UInt GetTextureWrap(Gapi::TEXTURE_WRAP wrap);

		/// <summary>Конструктор класса.</summary>
		TextureSampler(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~TextureSampler(void);

		virtual void SetFilterMode(ITextureBase* texture, TEXTURE_FILTER minFilter, TEXTURE_FILTER magFilter);

		virtual TEXTURE_FILTER GetMinificationFilterMode(void) const;

		virtual TEXTURE_FILTER GetMagnificationFilterMode(void) const;

		virtual void SetWrapMode(ITextureBase* texture, TEXTURE_WRAP wrapS, TEXTURE_WRAP wrapT, TEXTURE_WRAP wrapR);

		virtual void SetAnisotropicLevel(ITextureBase* texture, int level);

		/// <summary>Получает уровень анизотропной фильтрации.</summary>
		virtual int GetAnisotropicLevel(void) const;

		/// <summary>Получает максимальный уровень анизотропной фильтрации.</summary>
		virtual int GetMaxAnisotropicLevel(void) const;

		virtual void Apply(ITextureBase* texture);

		virtual bool IsValid(void) const;

	private:
		TEXTURE_FILTER _minFilter;
		TEXTURE_FILTER _magFilter;

		TEXTURE_WRAP _wrapS;
		TEXTURE_WRAP _wrapT;
		TEXTURE_WRAP _wrapR;

		int _anisotropicLevel; // Уровень анизотропной фильтрации.
		bool _anisotropicFilterSupported;

		bool _mipmapped;
	};
}

#endif // TEXTURESAMPLER_H