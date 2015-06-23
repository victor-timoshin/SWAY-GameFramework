#include "../../GapiOpenGL/Inc/OGLTexture.h"
#include "../../GapiOpenGL/Inc/OGLDevice.h"

namespace Gapi
{
	/** Constructor. */
	OGLTexture::OGLTexture(IDeviceBase* device) : ITextureBase(device)
		, texture(0)
		, pixels(0L)
	{
	}

	/** Destructor. */
	OGLTexture::~OGLTexture()
	{
		glDeleteTextures(1, &texture);
	}
}