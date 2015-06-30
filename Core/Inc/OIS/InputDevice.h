#ifndef INPUT_DEVICE_H
#define INPUT_DEVICE_H

#include "../../../SDK/Core/OIS/InputBase.h"
#include "../../StdAfx.h"

namespace OIS
{
	class InputDevice : public IInputBase
	{
	public:
		InputDevice();

		virtual ~InputDevice();

		virtual bool RegisterDevices(HWND handle);

		virtual bool UnregisterDevices();

		virtual bool HandleMessage(HDC deviceContext, LPARAM lParam);

		virtual bool KeyDown(const unsigned short& key) const;

		virtual bool KeyUp(const unsigned short& key) const;

		virtual void SetCursorPosition(unsigned int x, unsigned int y);

		virtual void SetCursorSensitivity(int value);

		virtual Core::Math::Vector2 GetCursorPositionAbsolute();

		virtual Core::Math::Vector2 GetCursorPositionRelative();

	private:
		RAWKEYBOARD rawKeyboard;
		RAWMOUSE rawMouse;
		RAWHID rawGamepad;

		long xPositionAbsolute;
		long yPositionAbsolute;

		long xPositionRelative;
		long yPositionRelative;

		int sensitivity;
	};
}

#endif // INPUT_DEVICE_H