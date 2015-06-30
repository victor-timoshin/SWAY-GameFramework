#ifndef INPUT_BASE_H
#define INPUT_BASE_H

#include "InputEventBase.h"
#include "../../Platform.h"

namespace OIS
{
	class IInputBase : public IInputEventBase
	{
	public:
		IInputBase() { }

		virtual ~IInputBase() { }

		virtual bool RegisterDevices(HWND handle) = 0;

		virtual bool UnregisterDevices() = 0;

		virtual bool HandleMessage(HDC deviceContext, LPARAM lParam) = 0;
	};

	CORE_API IInputBase* RegisterInputDevice();
}

#endif // INPUT_BASE_H