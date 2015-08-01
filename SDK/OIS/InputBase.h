#ifndef INPUTBASE_H
#define INPUTBASE_H

#include "Keyboard.h"
#include "Mouse.h"
#include "../Platform.h"

namespace OIS
{
	class IInputBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IInputBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IInputBase(void) {}

		virtual int RegisterDevices(HWND handle) = 0;

		virtual int UnregisterDevices(void) = 0;

		virtual bool HandleMessage(HDC deviceContext, LPARAM lParam) = 0;

		virtual IKeyboard* GetKeyboard(void) = 0;

		virtual IMouse* GetMouse(void) = 0;
	};

	CORE_API IInputBase* RegisterInputManagement(void);
}

#endif // INPUTBASE_H