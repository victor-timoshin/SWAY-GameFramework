#ifndef RENDER_DEVICE_H
#define RENDER_DEVICE_H

#include "../../SDK/Gapi/RenderDeviceBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	namespace OpenGL
	{
		class RenderDevice : public IRenderDeviceBase
		{
		public:
			static unsigned char Get(PRIMITIVE_TYPE Type);
			static unsigned char primitiveType[];

			/** Constructor. */
			RenderDevice(IWindowBase* window);

			/** Destructor. */
			virtual ~RenderDevice();

			virtual void Initialize();

			virtual void Clear(float red, float green, float blue, float alpha);

			virtual bool Swap();

			virtual void SetViewport(float width, float height);
		private:
			LWINDOWDESC windowDesc;

#ifdef PLATFORM_WINDOWS
			HDC deviceContext;
			HGLRC renderContext;
#else
			XVisualInfo* visualInfo;
			GLXContext context;
#endif
		};
	}
}

#endif