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

		EKC_0 = 48,
		EKC_1 = 49,
		EKC_2 = 50,
		EKC_3 = 51,
		EKC_4 = 52,
		EKC_5 = 53,
		EKC_6 = 54,
		EKC_7 = 55,
		EKC_8 = 56,
		EKC_9 = 57,

		EKC_A = 65,
		EKC_B = 66,
		EKC_C = 67,
		EKC_D = 68,
		EKC_E = 69,
		EKC_F = 70,
		EKC_G = 71,
		EKC_H = 72,
		EKC_I = 73,
		EKC_J = 74,
		EKC_K = 75,
		EKC_L = 76,
		EKC_M = 77,
		EKC_N = 78,
		EKC_O = 79,
		EKC_P = 80,
		EKC_Q = 81,
		EKC_R = 82,
		EKC_S = 83,
		EKC_T = 84,
		EKC_U = 85,
		EKC_V = 86,
		EKC_W = 87,
		EKC_X = 88,
		EKC_Y = 89,
		EKC_Z = 90,

		EKC_F1 = 112,
		EKC_F2 = 113,
		EKC_F3 = 114,
		EKC_F4 = 115,
		EKC_F5 = 116,
		EKC_F6 = 117,
		EKC_F7 = 118,
		EKC_F8 = 119,
		EKC_F9 = 120,
		EKC_F10 = 121,
		EKC_F11 = 122,
		EKC_F12 = 123,

		EKC_BACKSPACE = 8,
		EKC_TAB = 9,
		EKC_ENTER = 13,
		EKC_CAPSLOCK = 20,
		EKC_ESCAPE = 27,
		EKC_SPACE = 32,
		EKC_APP = 93,
		EKC_SEMICOLON = 186,
		EKC_ADD = 187,
		EKC_COMMA = 188,
		EKC_SUBTRACT = 189,
		EKC_PERIOD = 190,
		EKC_FWDSLASH = 191,
		EKC_TILDE = 192,
		EKC_LBRACKET = 219,
		EKC_BACKSLASH = 220,
		EKC_RBRACKET = 221,
		EKC_APOSTROPHE = 222,

		EKC_SHIFT = 16,
		EKC_CTRL = 17,
		EKC_LWIN = 91,
		EKC_RWIN = 92,
		EKC_LALT = 164,
		EKC_RALT = 165,

		EKC_INSERT = 45,
		EKC_DELETE = 46,
		EKC_HOME = 36,
		EKC_END = 35,
		EKC_PAGEUP = 33,
		EKC_PAGEDOWN = 34,

		EKC_UP = 38,
		EKC_DOWN = 40,
		EKC_RIGHT = 39,
		EKC_LEFT = 37,

		EKC_NUMLOCK = 144,
		EKC_NUMPAD_DIVIDE = 111,
		EKC_NUMPAD_MULTIPLY = 106,
		EKC_NUMPAD_SUBTRACT = 109,
		EKC_NUMPAD_ADD = 107,
		EKC_NUMPAD_DECIMAL = 110,
		EKC_NUMPAD_0 = 96,
		EKC_NUMPAD_1 = 97,
		EKC_NUMPAD_2 = 98,
		EKC_NUMPAD_3 = 99,
		EKC_NUMPAD_4 = 100,
		EKC_NUMPAD_5 = 101,
		EKC_NUMPAD_6 = 102,
		EKC_NUMPAD_7 = 103,
		EKC_NUMPAD_8 = 104,
		EKC_NUMPAD_9 = 105,
	} KEY_CODE;

	static KEY_CODE GetKeycodeByName(std::string name);
	static const char* GetNameByKeycode(KEY_CODE keycode);
}

#endif // KEYCODE_H