#include "../../GapiOpenGL/Inc/Texture.h"
#include "../../GapiOpenGL/Inc/RenderDevice.h"

namespace Gapi
{
	namespace OpenGL
	{
		/** Constructor. */
		Texture::Texture(IRenderDeviceBase* device) : ITextureBase(device)
			, texture(0)
			, pixels(0L)
		{
		}

		/** Destructor. */
		Texture::~Texture()
		{
			glDeleteTextures(1, &texture);
		}
	}
}