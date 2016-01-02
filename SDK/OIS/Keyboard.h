#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Keycode.h"
#include "KeyMapping.h"
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

		virtual bool HasKeyDown(const KEY_CODE& keyCode) const = 0;
		
		virtual bool HasKeyDownStr(const std::string& key) const = 0;

		virtual bool HasKeyUp(const KEY_CODE& keyCode) const = 0;
	};
}

#endif // KEYBOARD_H