#include "../../GapiOpenGL/Inc/Texture.h"
#include "../../GapiOpenGL/Inc/Device.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

namespace Gapi
{
	UInt Texture::GetTextureFormat(Gapi::TEXTURE_FORMAT format)
	{
		switch (format)
		{
		case TEXTURE_FORMAT::ETF_R:     return GL_RED;
		case TEXTURE_FORMAT::ETF_RG:    return GL_RG;
		case TEXTURE_FORMAT::ETF_RGB:   return GL_RGB;
		case TEXTURE_FORMAT::ETF_RGBA:  return GL_RGBA;
		case TEXTURE_FORMAT::ETF_HDR:   return GL_RGBA32F;
		case TEXTURE_FORMAT::ETF_DEPTH: return GL_DEPTH_COMPONENT24;
		case TEXTURE_FORMAT::EFT_BGR:   return GL_BGR;
		case TEXTURE_FORMAT::EFT_BGRA:  return GL_BGRA;
		case TEXTURE_FORMAT::EFT_RGB8:  return GL_RGB8;
		case TEXTURE_FORMAT::EFT_RGBA8: return GL_RGBA8;
		default:
			break;
		}
	}

	UInt Texture::GetTextureTarget(Gapi::TEXTURE_TARGET target)
	{
		switch (target)
		{
		case TEXTURE_TARGET::Texture_2D:        return GL_TEXTURE_2D;
		case TEXTURE_TARGET::Texture_2D_Array:  return GL_TEXTURE_2D_ARRAY;
		case TEXTURE_TARGET::Texture_Rectangle: return GL_TEXTURE_RECTANGLE;
		case TEXTURE_TARGET::Texture_Cube_Map:  return GL_TEXTURE_CUBE_MAP;
		default:
			return static_cast<UInt>(TEXTURE_TARGET::Unknown);
		}
	}

	std::string Texture::GetTextureTargetToString(UInt target)
	{
		switch (target)
		{
			CASE_VALUE_TOSTRING(GL_TEXTURE_2D);
			CASE_VALUE_TOSTRING(GL_TEXTURE_2D_ARRAY);
			CASE_VALUE_TOSTRING(GL_TEXTURE_RECTANGLE);
			CASE_VALUE_TOSTRING(GL_TEXTURE_CUBE_MAP);
		default:
			return "Unknown texture target " + IntToStr(target);
		}
	}

	UInt Texture::GetMipmapHint(Gapi::MIPMAPHINT hint)
	{
		switch (hint)
		{
		case MIPMAPHINT::None:    return GL_DONT_CARE;
		case MIPMAPHINT::Fastest: return GL_FASTEST;
		case MIPMAPHINT::Nicest:  return GL_DONT_CARE;
		default:
			return static_cast<UInt>(MIPMAPHINT::None);
		}
	}

	/// <summary>Конструктор класса.</summary>
	Texture::Texture(void)
		: _textureID(0)
		, _mipmapped(false)
		, _compressed(false)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Texture::~Texture(void)
	{
		glDeleteTextures(1, &_textureID);
	}

	void Texture::Load(Gapi::PTEXTURE_DESCRIPTION textureDesc)
	{
		if (textureDesc->width == 0)
			return;

		if (textureDesc->height == 0)
			return;

		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		// Запрашиваем у OpenGL свободный индекс текстуры.
		glGenTextures(1, &_textureID);

		// Делаем текстуру активной.
		glBindTexture(textureTarget, _textureID);

		//bool generateMipmaps = false;
		//UInt minFilter = generateMipmaps
		//	? Texture::GetTextureFilter(TEXTURE_FILTER::Linear_Mipmap_Linear)
		//	: Texture::GetTextureFilter(TEXTURE_FILTER::Linear);

		//if (generateMipmaps)
		//	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
		//
		//// Устанавливаем параметры фильтрации текстуры - линейная фильтрация.
		//glTexParameteri(textureTarget, GL_TEXTURE_MIN_FILTER, minFilter);
		//glTexParameteri(textureTarget, GL_TEXTURE_MAG_FILTER, Texture::GetTextureFilter(TEXTURE_FILTER::Linear));

		//// Устанавливаем параметры "оборачиваниея" текстуры - отсутствие оборачивания.
		//glTexParameteri(textureTarget, GL_TEXTURE_WRAP_S, Texture::GetTextureWrap(TEXTURE_WRAP::Clamp));
		//glTexParameteri(textureTarget, GL_TEXTURE_WRAP_T, Texture::GetTextureWrap(TEXTURE_WRAP::Clamp));

		// Загружаем данные о цвете в текущую активную текстуру.
		glTexImage2D(textureTarget, 0, Texture::GetTextureFormat(textureDesc->internalFormat),
			textureDesc->width, textureDesc->height, 0, Texture::GetTextureFormat(textureDesc->format), GL_UNSIGNED_BYTE, textureDesc->pixels);
	
		//if (generateMipmaps)
		//	GenerateMipmaps(MIPMAPHINT::Nicest);

		//GetTextureTargetToString(textureTarget).c_str();
		//GetInternalFormatToString();
		//GetTypeToString();
	}

	void Texture::CreateNullTexture(int width, int height)
	{
		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		int pitch = ((width * 32 + 31) & ~31) >> 3;
		std::vector<UByte> pixels(pitch * height, 255);

		glGenTextures(1, &_textureID);
		glBindTexture(textureTarget, _textureID);

		glTexImage2D(textureTarget, 0, GL_RGBA8, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, &pixels[0]);
	}

	void Texture::CreateFromMemory(const void* data, int width, int height, TEXTURE_FORMAT format)
	{
		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		glGenTextures(1, &_textureID);
		glBindTexture(textureTarget, _textureID);

		switch (format)
		{
		case ETF_R:
			glTexImage2D(textureTarget, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_RG:
			glTexImage2D(textureTarget, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_RGB:
			glTexImage2D(textureTarget, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_RGBA:
			glTexImage2D(textureTarget, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_HDR:
			glTexImage2D(textureTarget, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, data);
			break;

		case ETF_DEPTH:
			glTexImage2D(textureTarget, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, data);
			break;

		default: break;
		};
	}

	void Texture::Upload(int level, int xOffset, int yOffset, int width, int height, TEXTURE_FORMAT format, const void* pixels)
	{
		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		glBindTexture(textureTarget, _textureID);
		glTexSubImage2D(textureTarget, level, xOffset, yOffset, width, height, Texture::GetTextureFormat(format), GL_UNSIGNED_BYTE, pixels);
	}

	void Texture::GenerateMipmaps(Gapi::MIPMAPHINT hint)
	{
		if (!_mipmapped)
		{
			UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

			glBindTexture(textureTarget, _textureID);
			glHint(GL_GENERATE_MIPMAP_HINT, Texture::GetMipmapHint(hint));
			GL_ARB_FramebufferObject::GenerateMipmap(textureTarget, SOURCE_LOCATION);

			_mipmapped = true;
		}
	}

	void Texture::SetMipmapRange(int minLevel, int maxLevel)
	{
		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		glBindTexture(textureTarget, _textureID);
		glTexParameteri(textureTarget, GL_TEXTURE_BASE_LEVEL, minLevel);
		glTexParameteri(textureTarget, GL_TEXTURE_MAX_LEVEL, maxLevel);
	}

	bool Texture::HasMipmapped(void) const
	{
		return _mipmapped;
	}

	void Texture::SetActive(int slot)
	{
		GL_ARB_Multitexture::ActiveTexture(GL_TEXTURE0_ARB + slot, SOURCE_LOCATION);
	}

	void Texture::Bind(void)
	{
		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		glEnable(textureTarget);
		glBindTexture(textureTarget, _textureID);
	}

	void Texture::Unbind(void)
	{
		UInt textureTarget = Texture::GetTextureTarget(TEXTURE_TARGET::Texture_2D);

		glBindTexture(textureTarget, 0);
		glDisable(textureTarget);
	}

	void Texture::SetUnpackAlignement(UInt param)
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, param);
	}

	/// <summary>Получает уникальный идентификатор.</summary>
	UInt Texture::GetID(void) const
	{
		return _textureID;
	}

	/// <summary>Получает ширину текстуры.</summary>
	UInt Texture::GetWidth(void) const
	{
		return 0;
	}

	/// <summary>Получает высоту текстуры.</summary>
	UInt Texture::GetHeight(void) const
	{
		return 0;
	}

	bool Texture::IsValid(void) const
	{
		return _textureID > 0;
	}

	ITextureBase* RegisterTexture(void)
	{
		return new Texture();
	}
}