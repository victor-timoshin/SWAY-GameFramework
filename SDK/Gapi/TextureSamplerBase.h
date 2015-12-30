#ifndef TEXTURESAMPLERBASE_H
#define TEXTURESAMPLERBASE_H

#include "../../SDK/Platform.h"

namespace Gapi
{
	class ITextureBase;
	class ITextureSamplerBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ITextureSamplerBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ITextureSamplerBase(void) {}

		/// <summary>Устанавливает параметры фильтрации текстуры.</summary>
		virtual void SetFilterMode(ITextureBase* texture, TEXTURE_FILTER minFilter, TEXTURE_FILTER magFilter) = 0;

		/// <summary>Устанавливает параметры "оборачивание" текстуры.</summary>
		virtual void SetWrapMode(ITextureBase* texture, TEXTURE_WRAP wrapS, TEXTURE_WRAP wrapT, TEXTURE_WRAP wrapR) = 0;

		virtual void SetAnisotropicLevel(ITextureBase* texture, int level) = 0;

		/// <summary>Получает уровень анизотропной фильтрации.</summary>
		virtual int GetAnisotropicLevel(void) const = 0;

		/// <summary>Получает максимальный уровень анизотропной фильтрации.</summary>
		virtual int GetMaxAnisotropicLevel(void) const = 0;

		virtual void Apply(ITextureBase* texture) = 0;

		virtual bool IsValid(void) const = 0;
	};

	CORE_API ITextureSamplerBase* RegisterTextureSampler(void);
}

#endif // TEXTURESAMPLERBASE_H