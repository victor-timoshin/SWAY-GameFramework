#include "../../../Core/Inc/OIS/InputDevice.h"

namespace OIS
{
	InputDevice::InputDevice()
	{
		xPositionAbsolute = yPositionAbsolute = 0;
		xPositionRelative = yPositionRelative = 0;

		sensitivity = 1;
	}

	InputDevice::~InputDevice()
	{
	}

	bool InputDevice::RegisterDevices(HWND handle)
	{
		RAWINPUTDEVICE inputDevice[3];
		inputDevice[0].usUsagePage = 0x01;
		inputDevice[0].usUsage = 0x06; /* keyboard */
		inputDevice[0].dwFlags = RIDEV_INPUTSINK;
		inputDevice[0].hwndTarget = handle;

		inputDevice[1].usUsagePage = 0x01;
		inputDevice[1].usUsage = 0x02; /* mouse */
		inputDevice[1].dwFlags = RIDEV_INPUTSINK;
		inputDevice[1].hwndTarget = handle;

		inputDevice[2].usUsagePage = 0x01;
		inputDevice[2].usUsage = 0x05; /* gamepad */
		inputDevice[2].dwFlags = RIDEV_INPUTSINK;
		inputDevice[2].hwndTarget = handle;

		if (RegisterRawInputDevices(inputDevice, 3, sizeof(RAWINPUTDEVICE)) == FALSE)
			return false;

		return true;
	}

	bool InputDevice::UnregisterDevices()
	{
		RAWINPUTDEVICE inputDevice[3];
		inputDevice[0].usUsagePage = 0x01;
		inputDevice[0].usUsage = 0x06; /* keyboard */
		inputDevice[0].dwFlags = RIDEV_REMOVE;
		inputDevice[0].hwndTarget = 0L;

		inputDevice[1].usUsagePage = 0x01;
		inputDevice[1].usUsage = 0x02; /* mouse */
		inputDevice[1].dwFlags = RIDEV_REMOVE;
		inputDevice[1].hwndTarget = 0L;

		inputDevice[2].usUsagePage = 0x01;
		inputDevice[2].usUsage = 0x05; /* gamepad */
		inputDevice[2].dwFlags = RIDEV_REMOVE;
		inputDevice[2].hwndTarget = 0L;

		if (RegisterRawInputDevices(inputDevice, 3, sizeof(RAWINPUTDEVICE)) == FALSE)
			return false;

		return true;
	}

	bool InputDevice::HandleMessage(HDC deviceContext, LPARAM lParam)
	{
		unsigned int size = 0;
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, 0L, &size, sizeof(RAWINPUTHEADER));

		void* data = (void*)malloc(size);
		__try
		{
			GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, data, &size, sizeof(RAWINPUTHEADER));
			const RAWINPUT* const rawInput = static_cast<LPRAWINPUT>(data);

			switch (rawInput->header.dwType)
			{
			case RIM_TYPEKEYBOARD:
				rawKeyboard = rawInput->data.keyboard;
				break;

			case RIM_TYPEMOUSE:
				rawMouse = rawInput->data.mouse;

				if(xPositionRelative < 0) xPositionRelative = 0;
				if(yPositionRelative < 0) yPositionRelative = 0;

				if (xPositionRelative > GetDeviceCaps(deviceContext, HORZRES)) xPositionRelative = GetDeviceCaps(deviceContext, HORZRES);
				if (yPositionRelative > GetDeviceCaps(deviceContext, VERTRES)) yPositionRelative = GetDeviceCaps(deviceContext, VERTRES);
				break;

			case RIM_TYPEHID:
				break;
			};
		}
		__finally
		{
			free(data);
		}

		return true;
	}

	bool InputDevice::KeyDown(const unsigned short& key) const
	{
		return rawKeyboard.VKey == key && (rawKeyboard.Flags == RI_KEY_MAKE || rawKeyboard.Flags == RI_KEY_MAKE + RI_KEY_E0);
	}

	bool InputDevice::KeyUp(const unsigned short& key) const
	{
		return rawKeyboard.VKey == key && (rawKeyboard.Flags == RI_KEY_BREAK || rawKeyboard.Flags == RI_KEY_BREAK + RI_KEY_E0);
	}

	void InputDevice::SetCursorPosition(unsigned int x, unsigned int y)
	{
	}

	void InputDevice::SetCursorSensitivity(int value)
	{
		sensitivity = value;
	}

	Core::Math::Vector2 InputDevice::GetCursorPositionAbsolute()
	{
		xPositionAbsolute = rawMouse.lLastX * sensitivity;
		yPositionAbsolute = rawMouse.lLastY * sensitivity;

		return Core::Math::Vector2((float)xPositionAbsolute, (float)yPositionAbsolute);
	}

	Core::Math::Vector2 InputDevice::GetCursorPositionRelative()
	{
		xPositionRelative += rawMouse.lLastX * sensitivity;
		yPositionRelative += rawMouse.lLastY * sensitivity;

		return Core::Math::Vector2((float)xPositionRelative, (float)yPositionRelative);
	}

	IInputBase* RegisterInputDevice() {
		return new InputDevice;
	}
}