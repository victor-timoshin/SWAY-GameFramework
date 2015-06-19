#ifndef RENDER_DEVICE_H
#define RENDER_DEVICE_H

#include "RenderDeviceBase.h"

namespace Gapi
{
	class RenderDevice : public IRenderDeviceBase
	{
	public:
		/** Constructor. */
		RenderDevice(IRenderContextBase* context);

		/** Destructor. */
		virtual ~RenderDevice();

		virtual void Initialize();

		virtual void Clear(float red, float green, float blue, float alpha);

		virtual bool Swap();

	private:
		HDC deviceContext;
		HGLRC renderContext;
		LWINDOWDESC windowDesc;
	};
}

#endif