#ifndef KEYCODE_H
#define KEYCODE_H

#include <string>
#include <map>
#include <algorithm> // std::transform

namespace OIS
{
	typedef enum KeyCode
	{
		Unknown = 0,

		KeyCode_0 = 48,
		KeyCode_1 = 49,
		KeyCode_2 = 50,
		KeyCode_3 = 51,
		KeyCode_4 = 52,
		KeyCode_5 = 53,
		KeyCode_6 = 54,
		KeyCode_7 = 55,
		KeyCode_8 = 56,
		KeyCode_9 = 57,

		KeyCode_A = 65,
		KeyCode_B = 66,
		KeyCode_C = 67,
		KeyCode_D = 68,
		KeyCode_E = 69,
		KeyCode_F = 70,
		KeyCode_G = 71,
		KeyCode_H = 72,
		KeyCode_I = 73,
		KeyCode_J = 74,
		KeyCode_K = 75,
		KeyCode_L = 76,
		KeyCode_M = 77,
		KeyCode_N = 78,
		KeyCode_O = 79,
		KeyCode_P = 80,
		KeyCode_Q = 81,
		KeyCode_R = 82,
		KeyCode_S = 83,
		KeyCode_T = 84,
		KeyCode_U = 85,
		KeyCode_V = 86,
		KeyCode_W = 87,
		KeyCode_X = 88,
		KeyCode_Y = 89,
		KeyCode_Z = 90,

		KeyCode_F1 = 112,
		KeyCode_F2 = 113,
		KeyCode_F3 = 114,
		KeyCode_F4 = 115,
		KeyCode_F5 = 116,
		KeyCode_F6 = 117,
		KeyCode_F7 = 118,
		KeyCode_F8 = 119,
		KeyCode_F9 = 120,
		KeyCode_F10 = 121,
		KeyCode_F11 = 122,
		KeyCode_F12 = 123,

		KeyCode_Backspace = 8,
		KeyCode_Tab = 9,
		KeyCode_Enter = 13,
		KeyCode_CapsLock = 20,
		KeyCode_Escape = 27,
		KeyCode_Space = 32,
		KeyCode_App = 93,
		KeyCode_Semicolon = 186,
		KeyCode_Add = 187,
		KeyCode_Comma = 188,
		KeyCode_Subtract = 189,
		KeyCode_Period = 190,
		KeyCode_Slash = 191,
		KeyCode_Tilde = 192,
		KeyCode_LeftBracket = 219,
		KeyCode_Backslash = 220,
		KeyCode_RightBracket = 221,
		KeyCode_Apostrophe = 222,

		KeyCode_Shift = 16,
		KeyCode_Ctrl = 17,
		KeyCode_LeftWin = 91,
		KeyCode_RightWin = 92,
		KeyCode_LeftAlt = 164,
		KeyCode_RightAlt = 165,

		KeyCode_Insert = 45,
		KeyCode_Delete = 46,
		KeyCode_Home = 36,
		KeyCode_End = 35,
		KeyCode_PageUp = 33,
		KeyCode_PageDown = 34,

		KeyCode_Up = 38,
		KeyCode_Down = 40,
		KeyCode_Right = 39,
		KeyCode_Left = 37,

		KeyCode_NumLock = 144,
		KeyCode_NumPad_Divide = 111,
		KeyCode_NumPad_Multiply = 106,
		KeyCode_NumPad_Subtract = 109,
		KeyCode_NumPad_Add = 107,
		KeyCode_NumPad_Decimal = 110,
		KeyCode_NumPad_0 = 96,
		KeyCode_NumPad_1 = 97,
		KeyCode_NumPad_2 = 98,
		KeyCode_NumPad_3 = 99,
		KeyCode_NumPad_4 = 100,
		KeyCode_NumPad_5 = 101,
		KeyCode_NumPad_6 = 102,
		KeyCode_NumPad_7 = 103,
		KeyCode_NumPad_8 = 104,
		KeyCode_NumPad_9 = 105,
	} KEY_CODE;

	static KEY_CODE GetKeycodeByName(std::string name);
	static const char* GetNameByKeycode(KEY_CODE keycode);
}

#endif // KEYCODE_H