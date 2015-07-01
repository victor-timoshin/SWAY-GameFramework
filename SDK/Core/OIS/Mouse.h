#ifndef MOUSE_H
#define MOUSE_H

#include "../Math/Vector2.h"
#include "../../Platform.h"

namespace OIS
{
	class IMouse
	{
	public:
		/* Constructor. */
		IMouse(void) { }

		/* Destructor. */
		virtual ~IMouse(void) { }

		virtual void SetCursorPosition(UInt x, UInt y) = 0;

		virtual void SetCursorSensitivity(int value) = 0;

		virtual Core::Math::Vector2 GetCursorPositionAbsolute() = 0;

		virtual Core::Math::Vector2 GetCursorPositionRelative() = 0;
	};
}

#endif // MOUSE_H