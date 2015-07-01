#include "../../../Core/Inc/OIS/RawMouse.h"

#define RAW_MOUSE_USAGE 0x02

namespace OIS
{
	/* Constructor. */
	RawMouse::RawMouse(void)
	{
		xPositionAbsolute = yPositionAbsolute = 0;
		xPositionRelative = yPositionRelative = 0;

		sensitivity = 0.001f;
	}

#pragma region IRawInputDevice

	void RawMouse::MessageProc(void* data, HDC deviceContext, LPARAM lParam)
	{
		const RAWINPUT* const rawInput = static_cast<LPRAWINPUT>(data);
		if (rawInput->header.dwType == RIM_TYPEMOUSE)
		{
			mouseDevice = rawInput->data.mouse;

			if (xPositionRelative < 0)
				xPositionRelative = 0;

			if (yPositionRelative < 0)
				yPositionRelative = 0;

			if (xPositionRelative > GetDeviceCaps(deviceContext, HORZRES))
				xPositionRelative = GetDeviceCaps(deviceContext, HORZRES);

			if (yPositionRelative > GetDeviceCaps(deviceContext, VERTRES))
				yPositionRelative = GetDeviceCaps(deviceContext, VERTRES);
		}
	}

	UInt16 RawMouse::GetUsage()
	{
		return RAW_MOUSE_USAGE;
	}

#pragma endregion

#pragma region IMouse

#pragma endregion

	void RawMouse::SetCursorSensitivity(int value)
	{
		sensitivity = value;
	}

	Core::Math::Vector2 RawMouse::GetCursorPositionAbsolute()
	{
		xPositionAbsolute = mouseDevice.lLastX * sensitivity;
		yPositionAbsolute = mouseDevice.lLastY * sensitivity;

		return Core::Math::Vector2((float)xPositionAbsolute, (float)yPositionAbsolute);
	}

	Core::Math::Vector2 RawMouse::GetCursorPositionRelative()
	{
		xPositionRelative += mouseDevice.lLastX * sensitivity;
		yPositionRelative += mouseDevice.lLastY * sensitivity;

		return Core::Math::Vector2((float)xPositionRelative, (float)yPositionRelative);
	}
}