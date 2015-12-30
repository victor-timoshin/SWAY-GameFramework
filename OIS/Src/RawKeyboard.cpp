#include "../Inc/RawKeyboard.h"

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

	void RawKeyboard::SetHandle(HWND handle)
	{
		windowHandle = handle;
	}

	UInt16 RawKeyboard::GetUsage(void)
	{
		return RAW_KEYBOARD_USAGE;
	}

#pragma endregion

#pragma region IKeyboard

	bool RawKeyboard::HasKeyDown(const KEYCODE& key) const
	{
		return keyboardDevice.VKey == key && (keyboardDevice.Flags == RI_KEY_MAKE || keyboardDevice.Flags == RI_KEY_MAKE + RI_KEY_E0);
	}

	bool RawKeyboard::HasKeyDownStr(const std::string& key) const
	{
		return HasKeyDown(OIS::KeyCodeFromString(key));
	}

	bool RawKeyboard::HasKeyUp(const KEYCODE& key) const
	{
		return keyboardDevice.VKey == key && (keyboardDevice.Flags == RI_KEY_BREAK || keyboardDevice.Flags == RI_KEY_BREAK + RI_KEY_E0);
	}

#pragma endregion
}