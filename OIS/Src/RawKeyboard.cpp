#include "../Inc/RawKeyboard.h"
//#include "../../SDK/Core/Utils/File.h"

#define RAW_KEYBOARD_USAGE 0x06

namespace OIS
{
	static const KEY_MAPPING KeyMappingList[] =
	{
		{ "a",               KEY_CODE::KeyCode_A },
		{ "b",               KEY_CODE::KeyCode_B },
		{ "c",               KEY_CODE::KeyCode_C },
		{ "d",               KEY_CODE::KeyCode_D },
		{ "e",               KEY_CODE::KeyCode_E },
		{ "f",               KEY_CODE::KeyCode_F },
		{ "g",               KEY_CODE::KeyCode_G },
		{ "h",               KEY_CODE::KeyCode_H },
		{ "i",               KEY_CODE::KeyCode_I },
		{ "j",               KEY_CODE::KeyCode_J },
		{ "k",               KEY_CODE::KeyCode_K },
		{ "l",               KEY_CODE::KeyCode_L },
		{ "m",               KEY_CODE::KeyCode_M },
		{ "n",               KEY_CODE::KeyCode_N },
		{ "o",               KEY_CODE::KeyCode_O },
		{ "p",               KEY_CODE::KeyCode_P },
		{ "q",               KEY_CODE::KeyCode_Q },
		{ "r",               KEY_CODE::KeyCode_R },
		{ "s",               KEY_CODE::KeyCode_S },
		{ "t",               KEY_CODE::KeyCode_T },
		{ "u",               KEY_CODE::KeyCode_U },
		{ "v",               KEY_CODE::KeyCode_V },
		{ "w",               KEY_CODE::KeyCode_W },
		{ "x",               KEY_CODE::KeyCode_X },
		{ "y",               KEY_CODE::KeyCode_Y },
		{ "z",               KEY_CODE::KeyCode_Z },
		{ "f1",              KEY_CODE::KeyCode_F1 },
		{ "f2",              KEY_CODE::KeyCode_F2 },
		{ "f3",              KEY_CODE::KeyCode_F3 },
		{ "f4",              KEY_CODE::KeyCode_F4 },
		{ "f5",              KEY_CODE::KeyCode_F5 },
		{ "f6",              KEY_CODE::KeyCode_F6 },
		{ "f7",              KEY_CODE::KeyCode_F7 },
		{ "f8",              KEY_CODE::KeyCode_F8 },
		{ "f9",              KEY_CODE::KeyCode_F9 },
		{ "f10",             KEY_CODE::KeyCode_F10 },
		{ "f11",             KEY_CODE::KeyCode_F11 },
		{ "f12",             KEY_CODE::KeyCode_F12 },
		{ "backspace",       KEY_CODE::KeyCode_Backspace },
		{ "tab",             KEY_CODE::KeyCode_Tab },
		{ "enter",           KEY_CODE::KeyCode_Enter },
		{ "capslock",        KEY_CODE::KeyCode_CapsLock },
		{ "escape",          KEY_CODE::KeyCode_Escape },
		{ "space",           KEY_CODE::KeyCode_Space },
		{ "app",             KEY_CODE::KeyCode_App },
		{ "semicolon",       KEY_CODE::KeyCode_Semicolon },
		{ "add",             KEY_CODE::KeyCode_Add },
		{ "comma",           KEY_CODE::KeyCode_Comma },
		{ "subtract",        KEY_CODE::KeyCode_Subtract },
		{ "period",          KEY_CODE::KeyCode_Period },
		{ "fwdslash",        KEY_CODE::KeyCode_Slash },
		{ "tilde",           KEY_CODE::KeyCode_Tilde },
		{ "lbracket",        KEY_CODE::KeyCode_LeftBracket },
		{ "backslash",       KEY_CODE::KeyCode_Backslash },
		{ "rbracket",        KEY_CODE::KeyCode_RightBracket },
		{ "apostrophe",      KEY_CODE::KeyCode_Apostrophe },
		{ "shift",           KEY_CODE::KeyCode_Shift },
		{ "ctrl",            KEY_CODE::KeyCode_Ctrl },
		{ "lwin",            KEY_CODE::KeyCode_LeftWin },
		{ "rwin",            KEY_CODE::KeyCode_RightWin },
		{ "lalt",            KEY_CODE::KeyCode_LeftAlt },
		{ "ralt",            KEY_CODE::KeyCode_RightAlt },
		{ "insert",          KEY_CODE::KeyCode_Insert },
		{ "delete",          KEY_CODE::KeyCode_Delete },
		{ "home",            KEY_CODE::KeyCode_Home },
		{ "end",             KEY_CODE::KeyCode_End },
		{ "pageup",          KEY_CODE::KeyCode_PageUp },
		{ "pagedown",        KEY_CODE::KeyCode_PageDown },
		{ "up",              KEY_CODE::KeyCode_Up },
		{ "down",            KEY_CODE::KeyCode_Down },
		{ "right",           KEY_CODE::KeyCode_Right },
		{ "left",            KEY_CODE::KeyCode_Left },
		{ "numlock",         KEY_CODE::KeyCode_NumLock },
		{ "numpad_divide",   KEY_CODE::KeyCode_NumPad_Divide },
		{ "numpad_multiply", KEY_CODE::KeyCode_NumPad_Multiply },
		{ "numpad_subtract", KEY_CODE::KeyCode_NumPad_Subtract },
		{ "numpad_add",      KEY_CODE::KeyCode_NumPad_Add },
		{ "numpad_decimal",  KEY_CODE::KeyCode_NumPad_Decimal },
		{ "numpad_0",        KEY_CODE::KeyCode_NumPad_0 },
		{ "numpad_1",        KEY_CODE::KeyCode_NumPad_1 },
		{ "numpad_2",        KEY_CODE::KeyCode_NumPad_2 },
		{ "numpad_3",        KEY_CODE::KeyCode_NumPad_3 },
		{ "numpad_4",        KEY_CODE::KeyCode_NumPad_4 },
		{ "numpad_5",        KEY_CODE::KeyCode_NumPad_5 },
		{ "numpad_6",        KEY_CODE::KeyCode_NumPad_6 },
		{ "numpad_7",        KEY_CODE::KeyCode_NumPad_7 },
		{ "numpad_8",        KEY_CODE::KeyCode_NumPad_8 },
		{ "numpad_9",        KEY_CODE::KeyCode_NumPad_9 }
	};

	static KEY_CODE GetKeycodeByName(std::string charCode)
	{
		//Core::Utils::CompareCaseInsensitive(keyMapping.charCode, charCode);

		for (const KEY_MAPPING& keyMapping : KeyMappingList)
		{
			if (charCode.compare(keyMapping.charCode) == 0)
				return keyMapping.keyCode;
		}

		return KEY_CODE::Unknown;
	}

	static const char* GetNameByKeycode(KEY_CODE keyCode)
	{
		for (const KEY_MAPPING& keyMapping : KeyMappingList)
		{
			if (keyCode == keyMapping.keyCode)
				return keyMapping.charCode;
		}

		return nullptr;
	}

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

	bool RawKeyboard::HasKeyDown(const KEY_CODE& keyCode) const
	{
		return keyboardDevice.VKey == keyCode && (keyboardDevice.Flags == RI_KEY_MAKE || keyboardDevice.Flags == RI_KEY_MAKE + RI_KEY_E0);
	}

	bool RawKeyboard::HasKeyDownStr(const std::string& charCode) const
	{
		return HasKeyDown(GetKeycodeByName(charCode));
	}

	bool RawKeyboard::HasKeyUp(const KEY_CODE& keyCode) const
	{
		return keyboardDevice.VKey == keyCode && (keyboardDevice.Flags == RI_KEY_BREAK || keyboardDevice.Flags == RI_KEY_BREAK + RI_KEY_E0);
	}

#pragma endregion
}