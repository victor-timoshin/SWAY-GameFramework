#include "../Inc/RawMouse.h"

#define RAW_MOUSE_USAGE 0x02

namespace OIS
{
	/// <summary>Конструктор класса.</summary>
	RawMouse::RawMouse(void)
	{
		_xPositionAbsolute = _yPositionAbsolute = 0;
		_xPositionRelative = _yPositionRelative = 0;

		_sensitivity = 0.001f;
	}

#pragma region IRawInputDevice

	void RawMouse::MessageProc(void* data, HDC deviceContext, LPARAM lParam)
	{
		const RAWINPUT* const rawInput = static_cast<LPRAWINPUT>(data);
		if (rawInput->header.dwType == RIM_TYPEMOUSE)
		{
			_mouseDevice = rawInput->data.mouse;

			if (_xPositionRelative < 0)
				_xPositionRelative = 0;

			if (_yPositionRelative < 0)
				_yPositionRelative = 0;

			if (_xPositionRelative > GetDeviceCaps(deviceContext, HORZRES))
				_xPositionRelative = GetDeviceCaps(deviceContext, HORZRES);

			if (_yPositionRelative > GetDeviceCaps(deviceContext, VERTRES))
				_yPositionRelative = GetDeviceCaps(deviceContext, VERTRES);
		}
	}

	void RawMouse::SetHandle(HWND handle)
	{
		_windowHandle = handle;
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
		if (ClientToScreen(_windowHandle, &point))
		{
			SetCursorPos(point.x, point.y);

			_mouseDevice.lLastX = 0;
			_mouseDevice.lLastY = 0;
		}
	}

	void RawMouse::SetCursorSensitivity(int value)
	{
		_sensitivity = value;
	}

	Math::Vec2F RawMouse::GetCursorPositionAbsolute(void)
	{
		_xPositionAbsolute = _mouseDevice.lLastX * _sensitivity;
		_yPositionAbsolute = _mouseDevice.lLastY * _sensitivity;

		return Math::Vec2F((float)_xPositionAbsolute, (float)_yPositionAbsolute);
	}

	Math::Vec2F RawMouse::GetCursorPositionRelative(void)
	{
		_xPositionRelative += _mouseDevice.lLastX * _sensitivity;
		_yPositionRelative += _mouseDevice.lLastY * _sensitivity;

		return Math::Vec2F((float)_xPositionRelative, (float)_yPositionRelative);
	}

	bool RawMouse::HasMouseLeftButtonDown(void) const
	{
		return (_mouseDevice.usButtonFlags & RI_MOUSE_LEFT_BUTTON_DOWN) > 0;
	}

	bool RawMouse::HasMouseLeftButtonUp(void) const
	{
		return (_mouseDevice.usButtonFlags & RI_MOUSE_LEFT_BUTTON_UP) > 0;
	}

	bool RawMouse::HasMouseMiddleButtonDown(void) const
	{
		return (_mouseDevice.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_DOWN) > 0;
	}

	bool RawMouse::HasMouseMiddleButtonUp(void) const
	{
		return (_mouseDevice.usButtonFlags & RI_MOUSE_MIDDLE_BUTTON_UP) > 0;
	}

	bool RawMouse::HasMouseRightButtonDown(void) const
	{
		return (_mouseDevice.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_DOWN) > 0;
	}

	bool RawMouse::HasMouseRightButtonUp(void) const
	{
		return (_mouseDevice.usButtonFlags & RI_MOUSE_RIGHT_BUTTON_UP) > 0;
	}

	short RawMouse::GetMouseWheel(void) const
	{
		return (short)_mouseDevice.usButtonData;
	}

#pragma endregion
}