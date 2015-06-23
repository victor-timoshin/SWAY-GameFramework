#ifndef OGL_DEVICE_H
#define OGL_DEVICE_H

#include "../../SDK/Gapi/DeviceBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class OGLDevice : public IDeviceBase
	{
	public:
		static unsigned char Get(PRIMITIVE_TYPE Type);
		static unsigned char primitiveType[];

		/** Constructor. */
		OGLDevice(Core::System::IWindowBase* window);

		/** Destructor. */
		virtual ~OGLDevice();

		virtual void Initialize();

		virtual void Clear(float red, float green, float blue, float alpha);

		virtual bool Swap();

		virtual void SetViewport(float width, float height);
	private:
		Core::System::LWINDOWDESC windowDesc;

#ifdef PLATFORM_WINDOWS
		HDC deviceContext;
		HGLRC renderContext;
#else
		XVisualInfo* visualInfo;
		GLXContext context;
#endif
	};
}

#endif