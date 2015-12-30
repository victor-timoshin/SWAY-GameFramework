#include "../../GapiOpenGL/Inc/TextureSampler.h"
#include "../../GapiOpenGL/Inc/Device.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

#include "../../GapiOpenGL/inc/Texture.h"

namespace Gapi
{
	UInt TextureSampler::GetTextureFilter(Gapi::TEXTURE_FILTER filter)
	{
		switch (filter)
		{
		case TEXTURE_FILTER::Nearest:                return GL_NEAREST;
		case TEXTURE_FILTER::Nearest_Mipmap_Nearest: return GL_NEAREST_MIPMAP_NEAREST;
		case TEXTURE_FILTER::Nearest_Mipmap_Linear:  return GL_NEAREST_MIPMAP_LINEAR;
		case TEXTURE_FILTER::Linear:                 return GL_LINEAR;
		case TEXTURE_FILTER::Linear_Mipmap_Nearest:  return GL_LINEAR_MIPMAP_NEAREST;
		case TEXTURE_FILTER::Linear_Mipmap_Linear:   return GL_LINEAR_MIPMAP_LINEAR;
		default:
			return static_cast<UInt>(TEXTURE_FILTER::Unknown);
		}
	}

	UInt TextureSampler::GetTextureWrap(Gapi::TEXTURE_WRAP wrap)
	{
		switch (wrap)
		{
		case TEXTURE_WRAP::Repeat: return GL_REPEAT;
		case TEXTURE_WRAP::Clamp:  return GL_CLAMP_TO_EDGE;
		default:
			return static_cast<UInt>(TEXTURE_WRAP::Unknown);
		}
	}

	/// <summary>Конструктор класса.</summary>
	TextureSampler::TextureSampler(void)
		: _anisotropicLevel(0)
		, _anisotropicFilterSupported(IsExtensionSupported((const char*)glGetString(GL_EXTENSIONS), "GL_EXT_texture_filter_anisotropic"))
		, _mipmapped(false)
	{
	}

	/// <summary>Деструктор класса.</summary>
	TextureSampler::~TextureSampler(void)
	{
	}

	/// <summary>Устанавливает параметры фильтрации текстуры.</summary>
	void TextureSampler::SetFilterMode(ITextureBase* texture, TEXTURE_FILTER minFilter, TEXTURE_FILTER magFilter)
	{
		_minFilter = minFilter;
		_magFilter = magFilter;

		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);
		UInt textureID = texture->GetID();

		if (_mipmapped)
			glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

		glBindTexture(textureTarget, textureID);
		glTexParameteri(textureTarget, GL_TEXTURE_MIN_FILTER, _mipmapped
			? TextureSampler::GetTextureFilter(TEXTURE_FILTER::Linear_Mipmap_Linear)
			: TextureSampler::GetTextureFilter(_minFilter));
		glTexParameteri(textureTarget, GL_TEXTURE_MAG_FILTER, TextureSampler::GetTextureFilter(TEXTURE_FILTER::Linear));
	}

	TEXTURE_FILTER TextureSampler::GetMinificationFilterMode(void) const
	{
		return _minFilter;
	}

	TEXTURE_FILTER TextureSampler::GetMagnificationFilterMode(void) const
	{
		return _magFilter;
	}

	/// <summary>Устанавливает параметры "оборачивание" текстуры.</summary>
	void TextureSampler::SetWrapMode(ITextureBase* texture, TEXTURE_WRAP wrapS, TEXTURE_WRAP wrapT, TEXTURE_WRAP wrapR)
	{
		_wrapS = wrapS;
		_wrapT = wrapT;
		_wrapR = wrapR;

		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);
		UInt textureID = texture->GetID();

		glBindTexture(textureTarget, textureID);
		glTexParameteri(textureTarget, GL_TEXTURE_WRAP_S, TextureSampler::GetTextureWrap(_wrapS));
		glTexParameteri(textureTarget, GL_TEXTURE_WRAP_T, TextureSampler::GetTextureWrap(_wrapT));
		glTexParameteri(textureTarget, GL_TEXTURE_WRAP_R, TextureSampler::GetTextureWrap(_wrapR));
	}

	void TextureSampler::SetAnisotropicLevel(ITextureBase* texture, int level)
	{
		int maxAnisotropicLevel = GetMaxAnisotropicLevel();
		if (level > maxAnisotropicLevel)
			level = maxAnisotropicLevel;

		_anisotropicLevel = level;

		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);
		UInt textureID = texture->GetID();

		if (_anisotropicFilterSupported)
		{
			int anisotropyLevel = (_anisotropicLevel == 0) ? 1 : _anisotropicLevel;

			glBindTexture(textureTarget, textureID);
			glTexParameteri(textureTarget, GL_TEXTURE_MAX_ANISOTROPY_EXT, anisotropyLevel);
		}
	}

	/// <summary>Получает уровень анизотропной фильтрации.</summary>
	int TextureSampler::GetAnisotropicLevel(void) const
	{
		return _anisotropicLevel;
	}

	/// <summary>Получает максимальный уровень анизотропной фильтрации.</summary>
	int TextureSampler::GetMaxAnisotropicLevel(void) const
	{
		int maxAnisotropy;
		glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);

		return maxAnisotropy;
	}

	void TextureSampler::Apply(ITextureBase* texture)
	{
		//UInt sampler;
		//GL_ARB_SamplerObjects::GenSamplers(1, &sampler, SOURCE_LOCATION);
		//GL_ARB_SamplerObjects::SamplerParameterI(sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST, SOURCE_LOCATION);
	}

	bool TextureSampler::IsValid(void) const
	{
		return true;
	}

	ITextureSamplerBase* RegisterTextureSampler(void)
	{
		return new TextureSampler();
	}
}