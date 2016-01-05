#include "../Inc/RawKeyboard.h"
//#include "../../SDK/Core/Utils/File.h"

#define RAW_KEYBOARD_USAGE 0x06

namespace OIS
{
	static const KEY_MAPPING KeyMappingList[] =
	{
		{ "a",               KEY_CODE::EKC_A },
		{ "b",               KEY_CODE::EKC_B },
		{ "c",               KEY_CODE::EKC_C },
		{ "d",               KEY_CODE::EKC_D },
		{ "e",               KEY_CODE::EKC_E },
		{ "f",               KEY_CODE::EKC_F },
		{ "g",               KEY_CODE::EKC_G },
		{ "h",               KEY_CODE::EKC_H },
		{ "i",               KEY_CODE::EKC_I },
		{ "j",               KEY_CODE::EKC_J },
		{ "k",               KEY_CODE::EKC_K },
		{ "l",               KEY_CODE::EKC_L },
		{ "m",               KEY_CODE::EKC_M },
		{ "n",               KEY_CODE::EKC_N },
		{ "o",               KEY_CODE::EKC_O },
		{ "p",               KEY_CODE::EKC_P },
		{ "q",               KEY_CODE::EKC_Q },
		{ "r",               KEY_CODE::EKC_R },
		{ "s",               KEY_CODE::EKC_S },
		{ "t",               KEY_CODE::EKC_T },
		{ "u",               KEY_CODE::EKC_U },
		{ "v",               KEY_CODE::EKC_V },
		{ "w",               KEY_CODE::EKC_W },
		{ "x",               KEY_CODE::EKC_X },
		{ "y",               KEY_CODE::EKC_Y },
		{ "z",               KEY_CODE::EKC_Z },
		{ "f1",              KEY_CODE::EKC_F1 },
		{ "f2",              KEY_CODE::EKC_F2 },
		{ "f3",              KEY_CODE::EKC_F3 },
		{ "f4",              KEY_CODE::EKC_F4 },
		{ "f5",              KEY_CODE::EKC_F5 },
		{ "f6",              KEY_CODE::EKC_F6 },
		{ "f7",              KEY_CODE::EKC_F7 },
		{ "f8",              KEY_CODE::EKC_F8 },
		{ "f9",              KEY_CODE::EKC_F9 },
		{ "f10",             KEY_CODE::EKC_F10 },
		{ "f11",             KEY_CODE::EKC_F11 },
		{ "f12",             KEY_CODE::EKC_F12 },
		{ "backspace",       KEY_CODE::EKC_BACKSPACE },
		{ "tab",             KEY_CODE::EKC_TAB },
		{ "enter",           KEY_CODE::EKC_ENTER },
		{ "capslock",        KEY_CODE::EKC_CAPSLOCK },
		{ "escape",          KEY_CODE::EKC_ESCAPE },
		{ "space",           KEY_CODE::EKC_SPACE },
		{ "app",             KEY_CODE::EKC_APP },
		{ "semicolon",       KEY_CODE::EKC_SEMICOLON },
		{ "add",             KEY_CODE::EKC_ADD },
		{ "comma",           KEY_CODE::EKC_COMMA },
		{ "subtract",        KEY_CODE::EKC_SUBTRACT },
		{ "period",          KEY_CODE::EKC_PERIOD },
		{ "fwdslash",        KEY_CODE::EKC_FWDSLASH },
		{ "tilde",           KEY_CODE::EKC_TILDE },
		{ "lbracket",        KEY_CODE::EKC_LBRACKET },
		{ "backslash",       KEY_CODE::EKC_BACKSLASH },
		{ "rbracket",        KEY_CODE::EKC_RBRACKET },
		{ "apostrophe",      KEY_CODE::EKC_APOSTROPHE },
		{ "shift",           KEY_CODE::EKC_SHIFT },
		{ "ctrl",            KEY_CODE::EKC_CTRL },
		{ "lwin",            KEY_CODE::EKC_LWIN },
		{ "rwin",            KEY_CODE::EKC_RWIN },
		{ "lalt",            KEY_CODE::EKC_LALT },
		{ "ralt",            KEY_CODE::EKC_RALT },
		{ "insert",          KEY_CODE::EKC_INSERT },
		{ "delete",          KEY_CODE::EKC_DELETE },
		{ "home",            KEY_CODE::EKC_HOME },
		{ "end",             KEY_CODE::EKC_END },
		{ "pageup",          KEY_CODE::EKC_PAGEUP },
		{ "pagedown",        KEY_CODE::EKC_PAGEDOWN },
		{ "up",              KEY_CODE::EKC_UP },
		{ "down",            KEY_CODE::EKC_DOWN },
		{ "right",           KEY_CODE::EKC_RIGHT },
		{ "left",            KEY_CODE::EKC_LEFT },
		{ "numlock",         KEY_CODE::EKC_NUMLOCK },
		{ "numpad_divide",   KEY_CODE::EKC_NUMPAD_DIVIDE },
		{ "numpad_multiply", KEY_CODE::EKC_NUMPAD_MULTIPLY },
		{ "numpad_subtract", KEY_CODE::EKC_NUMPAD_SUBTRACT },
		{ "numpad_add",      KEY_CODE::EKC_NUMPAD_ADD },
		{ "numpad_decimal",  KEY_CODE::EKC_NUMPAD_DECIMAL },
		{ "numpad_0",        KEY_CODE::EKC_NUMPAD_0 },
		{ "numpad_1",        KEY_CODE::EKC_NUMPAD_1 },
		{ "numpad_2",        KEY_CODE::EKC_NUMPAD_2 },
		{ "numpad_3",        KEY_CODE::EKC_NUMPAD_3 },
		{ "numpad_4",        KEY_CODE::EKC_NUMPAD_4 },
		{ "numpad_5",        KEY_CODE::EKC_NUMPAD_5 },
		{ "numpad_6",        KEY_CODE::EKC_NUMPAD_6 },
		{ "numpad_7",        KEY_CODE::EKC_NUMPAD_7 },
		{ "numpad_8",        KEY_CODE::EKC_NUMPAD_8 },
		{ "numpad_9",        KEY_CODE::EKC_NUMPAD_9 }
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