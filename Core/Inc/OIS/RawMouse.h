#ifndef RAW_MOUSE_H
#define RAW_MOUSE_H

#include "RawInputDevice.h"
#include "../../../SDK/Core/OIS/Mouse.h"
#include "../../StdAfx.h"

namespace OIS
{
	class RawMouse : public IRawInputDevice, public IMouse
	{
	public:
		/* Constructor. */
		RawMouse(void);

		/* Destructor. */
		virtual ~RawMouse(void) { }

#pragma region IRawInputDevice

		virtual void MessageProc(void* data, HDC deviceContext, LPARAM lParam);

		virtual UInt16 GetUsage();

#pragma endregion

#pragma region IMouse

#pragma endregion

		virtual void SetCursorPosition(UInt x, UInt y) {}

		virtual void SetCursorSensitivity(int value);

		virtual Core::Math::Vector2 GetCursorPositionAbsolute();

		virtual Core::Math::Vector2 GetCursorPositionRelative();

	private:
		RAWMOUSE mouseDevice;

		long xPositionAbsolute;
		long yPositionAbsolute;

		long xPositionRelative;
		long yPositionRelative;

		int sensitivity;
	};
}

#endif // RAW_MOUSE_H