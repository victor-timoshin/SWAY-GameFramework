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

		virtual Math::Vector2 GetCursorPositionAbsolute(void);

		virtual Math::Vector2 GetCursorPositionRelative(void);

#pragma endregion

	private:
		HWND windowHandle;
		RAWMOUSE mouseDevice;

		long xPositionAbsolute;
		long yPositionAbsolute;

		long xPositionRelative;
		long yPositionRelative;

		long sensitivity;
	};
}

#endif // RAWMOUSE_H