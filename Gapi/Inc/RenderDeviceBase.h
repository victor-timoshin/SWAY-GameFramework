#ifndef RENDER_DEVICE_BASE_H
#define RENDER_DEVICE_BASE_H

#include "StdAfx.h"
#include "RenderContextBase.h"

namespace Gapi
{
	class IRenderDeviceBase
	{
	public:
		/** Constructor. */
		IRenderDeviceBase(IRenderContextBase* context) {}

		/** Destructor. */
		virtual ~IRenderDeviceBase() {}

		virtual void Initialize() = 0;

		virtual void Clear(float red, float green, float blue, float alpha) = 0;

		virtual bool Swap() = 0;
	};

	CORE_API IRenderDeviceBase* RegisterRenderDevice(IRenderContextBase* context);
}

#endif