#ifndef INPUT_BASE_H
#define INPUT_BASE_H

#include "Keyboard.h"
#include "Mouse.h"
#include "../../Platform.h"

namespace OIS
{
	class IInputBase
	{
	public:
		/* Constructor. */
		IInputBase() { }

		/* Destructor. */
		virtual ~IInputBase() { }

		virtual int RegisterDevices(HWND handle) = 0;

		virtual int UnregisterDevices() = 0;

		virtual bool HandleMessage(HDC deviceContext, LPARAM lParam) = 0;

		virtual IKeyboard* GetKeyboard() = 0;

		virtual IMouse* GetMouse() = 0;
	};

	CORE_API IInputBase* RegisterInputManagement();
}

#endif // INPUT_BASE_H