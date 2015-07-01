#include "../../../Core/Inc/OIS/RawKeyboard.h"

#define RAW_KEYBOARD_USAGE 0x06

namespace OIS
{
#pragma region IRawInputDevice

	void RawKeyboard::MessageProc(void* data, HDC deviceContext, LPARAM lParam)
	{
		const RAWINPUT* const rawInput = static_cast<LPRAWINPUT>(data);

		if (rawInput->header.dwType == RIM_TYPEKEYBOARD)
			keyboardDevice = rawInput->data.keyboard;
	}

	UInt16 RawKeyboard::GetUsage()
	{
		return RAW_KEYBOARD_USAGE;
	}

#pragma endregion

#pragma region IKeyboard

#pragma endregion

	bool RawKeyboard::KeyDown(const KEYCODE& key) const
	{
		return keyboardDevice.VKey == key && (keyboardDevice.Flags == RI_KEY_MAKE || keyboardDevice.Flags == RI_KEY_MAKE + RI_KEY_E0);
	}

	bool RawKeyboard::KeyUp(const KEYCODE& key) const
	{
		return keyboardDevice.VKey == key && (keyboardDevice.Flags == RI_KEY_BREAK || keyboardDevice.Flags == RI_KEY_BREAK + RI_KEY_E0);
	}
}