#include "../Inc/RawMouse.h"

#define RAW_MOUSE_USAGE 0x02

namespace OIS
{
	/// <summary>Конструктор класса.</summary>
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

	void RawMouse::SetHandle(HWND handle)
	{
		windowHandle = handle;
	}

	UInt16 RawMouse::GetUsage(void)
	{
		return RAW_MOUSE_USAGE;
	}

#pragma endregion

#pragma region IMouse

	void RawMouse::SetCursorPosition(UInt x, UInt y)
	{
		POINT point = { x, y };
		if (ClientToScreen(windowHandle, &point))
		{
			SetCursorPos(point.x, point.y);

			mouseDevice.lLastX = 0;
			mouseDevice.lLastY = 0;
		}
	}

	void RawMouse::SetCursorSensitivity(int value)
	{
		sensitivity = value;
	}

	Math::Vector2 RawMouse::GetCursorPositionAbsolute(void)
	{
		xPositionAbsolute = mouseDevice.lLastX * sensitivity;
		yPositionAbsolute = mouseDevice.lLastY * sensitivity;

		return Math::Vector2((float)xPositionAbsolute, (float)yPositionAbsolute);
	}

	Math::Vector2 RawMouse::GetCursorPositionRelative(void)
	{
		xPositionRelative += mouseDevice.lLastX * sensitivity;
		yPositionRelative += mouseDevice.lLastY * sensitivity;

		return Math::Vector2((float)xPositionRelative, (float)yPositionRelative);
	}

#pragma endregion
}