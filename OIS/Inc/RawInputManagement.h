#ifndef RAWINPUTMANAGEMENT_H
#define RAWINPUTMANAGEMENT_H

#include "RawInputDevice.h"
#include "../../SDK/OIS/Keyboard.h"
#include "../../SDK/OIS/Mouse.h"
#include "../../SDK/OIS/InputBase.h"
#include "../../SDK/OIS/InputBinding.h"
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

		void AddBinding(std::string name, const PINPUT_BINDING bind)
		{
			_bindings.insert(std::make_pair(name, bind));
		}

		void RemoveBinding(std::string name)
		{
			InputBindingMap::iterator it = _bindings.find(name);
			if (it != _bindings.end())
				_bindings.erase(it);
		}

	private:
		std::vector<IRawInputDevice*> rawInputDevices;

		typedef std::map<std::string, PINPUT_BINDING> InputBindingMap;
		InputBindingMap _bindings;
	};
}

#endif // RAWINPUTMANAGEMENT_H