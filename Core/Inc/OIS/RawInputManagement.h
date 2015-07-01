#ifndef RAW_INPUT_MANAGEMENT_H
#define RAW_INPUT_MANAGEMENT_H

#include "RawInputDevice.h"
#include "../../../SDK/Core/OIS/Keyboard.h"
#include "../../../SDK/Core/OIS/Mouse.h"

#include "../../../SDK/Core/OIS/InputBase.h"
#include "../../StdAfx.h"

#include <vector>

namespace OIS
{
	class RawInputManagement : public IInputBase
	{
	public:
		/** Constructor. */
		RawInputManagement(void);

		/** Destructor. */
		virtual ~RawInputManagement(void) { }

		virtual int RegisterDevices(HWND handle);

		virtual int UnregisterDevices();

		virtual bool HandleMessage(HDC deviceContext, LPARAM lParam);

		virtual IKeyboard* GetKeyboard();

		virtual IMouse* GetMouse();

	private:
		std::vector<IRawInputDevice*> rawInputDevices;
	};
}

#endif // RAW_INPUT_MANAGEMENT_H