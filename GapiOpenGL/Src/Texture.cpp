#include "../../GapiOpenGL/Inc/Texture.h"
#include "../../GapiOpenGL/Inc/Device.h"

namespace Gapi
{
	PFNGLACTIVETEXTUREPROC Texture::glActiveTextureARB = NULL;

	/// <summary>Конструктор класса.</summary>
	Texture::Texture(void)
		: textureID(0)
	{
		LOAD_EXTENSION(PFNGLACTIVETEXTUREPROC, glActiveTextureARB);
	}

	/// <summary>Деструктор класса.</summary>
	Texture::~Texture(void)
	{
		glDeleteTextures(1, &textureID);
	}

	void Texture::CreateFromMemory(const void* data, int width, int height, TEXTURE_FORMATS format)
	{
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		switch (format)
		{
		case ETF_R:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_RG:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_RGB:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_RGBA:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			break;

		case ETF_HDR:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_FLOAT, data);
			break;

		case ETF_DEPTH:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, data);
			break;

		default: break;
		};
	}

	void Texture::Create(int format, int width, int height, const void* data, int mipCount)
	{
	}

	void Texture::SetActive(int slot)
	{
		glActiveTextureARB(GL_TEXTURE0 + slot);
	}

	void Texture::Bind(void)
	{
		glBindTexture(GL_TEXTURE_2D, textureID);
	}

	void Texture::Unbind(void)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::SetPixelStore(UInt param)
	{
		glPixelStorei(GL_UNPACK_ALIGNMENT, param);
	}

	UInt Texture::GetID(void) const
	{
		return textureID;
	}

	ITextureBase* RegisterTexture(void)
	{
		return new Texture();
	}
}