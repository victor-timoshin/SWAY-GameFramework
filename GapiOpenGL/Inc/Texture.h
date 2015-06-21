#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../SDK/Gapi/TextureBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	namespace OpenGL
	{
		class Texture: public ITextureBase
		{
		public:
			/** Constructor. */
			Texture(IRenderDeviceBase* device);

			/** Destructor. */
			virtual ~Texture();

		private:
			UInt texture;
			UByte* pixels;
		};
	}
}

#endif