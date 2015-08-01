#ifndef MOUSE_H
#define MOUSE_H

#include "../Math/Vector2.h"
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

		virtual Math::Vector2 GetCursorPositionAbsolute(void) = 0;

		virtual Math::Vector2 GetCursorPositionRelative(void) = 0;
	};
}

#endif // MOUSE_H