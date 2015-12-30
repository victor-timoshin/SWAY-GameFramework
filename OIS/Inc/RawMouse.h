#ifndef RAWMOUSE_H
#define RAWMOUSE_H

#include "RawInputDevice.h"
#include "../../SDK/OIS/Mouse.h"
#include "../StdAfx.h"

namespace OIS
{
	class RawMouse : public IRawInputDevice, public IMouse
	{
	public:
		/// <summary>Конструктор класса.</summary>
		RawMouse(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~RawMouse(void) {}

#pragma region IRawInputDevice

		virtual void MessageProc(void* data, HDC deviceContext, LPARAM lParam);

		virtual UInt16 GetUsage(void);

		virtual void SetHandle(HWND handle);

#pragma endregion

#pragma region IMouse

		virtual void SetCursorPosition(UInt x, UInt y);

		virtual void SetCursorSensitivity(int value);

		virtual Math::Vec2F GetCursorPositionAbsolute(void);

		virtual Math::Vec2F GetCursorPositionRelative(void);

		virtual bool HasMouseLeftButtonDown(void) const;

		virtual bool HasMouseLeftButtonUp(void) const;

		virtual bool HasMouseMiddleButtonDown(void) const;

		virtual bool HasMouseMiddleButtonUp(void) const;

		virtual bool HasMouseRightButtonDown(void) const;

		virtual bool HasMouseRightButtonUp(void) const;

		virtual short GetMouseWheel(void) const;

#pragma endregion

	private:
		HWND _windowHandle;
		RAWMOUSE _mouseDevice;

		long _xPositionAbsolute;
		long _yPositionAbsolute;

		long _xPositionRelative;
		long _yPositionRelative;

		long _sensitivity;
	};
}

#endif // RAWMOUSE_H