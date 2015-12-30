#ifndef MOUSE_H
#define MOUSE_H

#include "../../Math/Inc/Vector2.h"
#include "../Platform.h"

namespace OIS
{
	class IMouse
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IMouse(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IMouse(void) {}

		virtual void SetCursorPosition(UInt x, UInt y) = 0;

		virtual void SetCursorSensitivity(int value) = 0;

		virtual Math::Vec2F GetCursorPositionAbsolute(void) = 0;

		virtual Math::Vec2F GetCursorPositionRelative(void) = 0;

		virtual bool HasMouseLeftButtonDown(void) const = 0;

		virtual bool HasMouseLeftButtonUp(void) const = 0;

		virtual bool HasMouseMiddleButtonDown(void) const = 0;

		virtual bool HasMouseMiddleButtonUp(void) const = 0;

		virtual bool HasMouseRightButtonDown(void) const = 0;

		virtual bool HasMouseRightButtonUp(void) const = 0;

		virtual short GetMouseWheel(void) const = 0;
	};
}

#endif // MOUSE_H