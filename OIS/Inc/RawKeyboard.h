#ifndef RAWKEYBOARD_H
#define RAWKEYBOARD_H

#include "RawInputDevice.h"
#include "../../SDK/OIS/Keyboard.h"
#include "../StdAfx.h"

namespace OIS
{
	class RawKeyboard : public IRawInputDevice, public IKeyboard
	{
	public:
		/// <summary>Конструктор класса.</summary>
		RawKeyboard(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~RawKeyboard(void) {}

#pragma region IRawInputDevice

		virtual void MessageProc(void* data, HDC deviceContext, LPARAM lParam);

		virtual void SetHandle(HWND handle);

		virtual UInt16 GetUsage(void);

#pragma endregion

#pragma region IKeyboard

		virtual bool KeyDown(const KEYCODE& key) const;

		virtual bool KeyUp(const KEYCODE& key) const;

#pragma endregion

	private:
		HWND windowHandle;
		RAWKEYBOARD keyboardDevice;
	};
}

#endif // RAWKEYBOARD_H