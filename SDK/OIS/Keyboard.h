#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "KeyCodes.h"
#include "../Platform.h"

namespace OIS
{
	class IKeyboard
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IKeyboard(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IKeyboard(void) {}

		virtual bool KeyDown(const KEYCODE& key) const = 0;

		virtual bool KeyUp(const KEYCODE& key) const = 0;
	};
}

#endif // KEYBOARD_H