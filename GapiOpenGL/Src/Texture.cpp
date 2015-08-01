#include "../../GapiOpenGL/Inc/Texture.h"
#include "../../GapiOpenGL/Inc/Device.h"

namespace Gapi
{
	PFNGLACTIVETEXTUREPROC Texture::glActiveTextureARB = NULL;

	/// <summary>Конструктор класса.</summary>
	Texture::Texture(void)
		: textureID(0), pixels(NULL)
	{
		LOAD_EXTENSION(PFNGLACTIVETEXTUREPROC, glActiveTextureARB);
	}

	/// <summary>Деструктор класса.</summary>
	Texture::~Texture(void)
	{
		glDeleteTextures(1, &textureID);
	}

	void Texture::Create(int format, int width, int height, const void* data, int mipCount)
	{
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		pixels = (unsigned char*)malloc(width * height * 4/*RGBA*/);
	}

	void Texture::Set(int slot)
	{
		glActiveTextureARB(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, textureID);
	}
}