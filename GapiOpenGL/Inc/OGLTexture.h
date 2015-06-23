#ifndef OGL_TEXTURE_H
#define OGL_TEXTURE_H

#include "../../SDK/Gapi/TextureBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class OGLTexture: public ITextureBase
	{
	public:
		/** Constructor. */
		OGLTexture(IDeviceBase* device);

		/** Destructor. */
		virtual ~OGLTexture();

	private:
		UInt texture;
		UByte* pixels;
	};
}

#endif // OGL_TEXTURE_H