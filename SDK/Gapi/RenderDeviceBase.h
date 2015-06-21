#ifndef RENDER_DEVICE_BASE_H
#define RENDER_DEVICE_BASE_H

#include "../../SDK/System/WindowBase.h"
#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IRenderDeviceBase
	{
	public:
		/** Constructor. */
		IRenderDeviceBase(IWindowBase* window) {}

		/** Destructor. */
		virtual ~IRenderDeviceBase() {}

		virtual void Initialize() = 0;

		virtual void Clear(float red, float green, float blue, float alpha) = 0;

		virtual bool Swap() = 0;

		virtual void SetViewport(float width, float height) = 0;
	};

	CORE_API IRenderDeviceBase* RegisterRenderDevice(IWindowBase* window);
}

#endif