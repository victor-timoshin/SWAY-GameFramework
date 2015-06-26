#ifndef OGL_DEVICE_H
#define OGL_DEVICE_H

#include "../../SDK/Gapi/DeviceBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class OGLDevice : public IDeviceBase
	{
	public:
		static UByte Get(PRIMITIVE_TYPE type);

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

		HDC deviceContext;
		HGLRC renderContext;
	};
}

#endif // OGL_DEVICE_H