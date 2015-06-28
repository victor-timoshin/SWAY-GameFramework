#ifndef DEVICE_BASE_H
#define DEVICE_BASE_H

#include "../../SDK/Core/System/WindowBase.h"
#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IDeviceBase
	{
	public:
		/** Constructor. */
		IDeviceBase(Core::System::IWindowBase* window) {}

		/** Destructor. */
		virtual ~IDeviceBase() {}

		virtual void Initialize() = 0;

		virtual void Clear(float red, float green, float blue, float alpha) = 0;

		virtual bool Swap() = 0;

		virtual void SetViewport(UInt width, UInt height) = 0;
	};

	CORE_API IDeviceBase* RegisterDevice(Core::System::IWindowBase* window);
}

#endif // DEVICE_BASE_H