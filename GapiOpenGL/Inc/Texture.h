#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../SDK/Gapi/TextureBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class Texture : public ITextureBase
	{
	public:
		static PFNGLACTIVETEXTUREPROC glActiveTextureARB;

		/// <summary>Конструктор класса.</summary>
		Texture(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Texture(void);

		virtual void Create(int format, int width, int height, const void* data, int mipCount);

		virtual void Set(int slot);

	private:
		UInt textureID;
		UByte* pixels;
	};
}

#endif // TEXTURE_H