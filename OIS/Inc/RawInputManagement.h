#ifndef RAWINPUTMANAGEMENT_H
#define RAWINPUTMANAGEMENT_H

#include "RawInputDevice.h"
#include "../../SDK/OIS/Keyboard.h"
#include "../../SDK/OIS/Mouse.h"
#include "../../SDK/OIS/InputBase.h"
#include "../StdAfx.h"

#include <vector>

namespace OIS
{
	class RawInputManagement : public IInputBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		RawInputManagement(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~RawInputManagement(void) {}

		virtual int RegisterDevices(HWND handle);

		virtual int UnregisterDevices(void);

		virtual bool HandleMessage(HDC deviceContext, LPARAM lParam);

		virtual IKeyboard* GetKeyboard(void);

		virtual IMouse* GetMouse(void);

	private:
		std::vector<IRawInputDevice*> rawInputDevices;
	};
}

#endif // RAWINPUTMANAGEMENT_H