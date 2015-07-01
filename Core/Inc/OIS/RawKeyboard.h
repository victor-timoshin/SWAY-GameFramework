#ifndef RAW_KEYBOARD_H
#define RAW_KEYBOARD_H

#include "RawInputDevice.h"
#include "../../../SDK/Core/OIS/Keyboard.h"
#include "../../StdAfx.h"

namespace OIS
{
	class RawKeyboard : public IRawInputDevice, public IKeyboard
	{
	public:
		/* Constructor. */
		RawKeyboard(void) { }

		/* Destructor. */
		virtual ~RawKeyboard(void) { }

#pragma region IRawInputDevice

		virtual void MessageProc(void* data, HDC deviceContext, LPARAM lParam);

		virtual UInt16 GetUsage();

#pragma endregion

#pragma region IKeyboard

#pragma endregion

		virtual bool KeyDown(const KEYCODE& key) const;

		virtual bool KeyUp(const KEYCODE& key) const;

	private:
		RAWKEYBOARD keyboardDevice;
	};
}

#endif // RAW_KEYBOARD_H