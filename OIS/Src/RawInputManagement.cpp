#include "../Inc/RawInputManagement.h"
#include "../Inc/RawKeyboard.h"
#include "../Inc/RawMouse.h"

namespace OIS
{
	/// <summary>Конструктор класса.</summary>
	RawInputManagement::RawInputManagement(void)
	{
		rawInputDevices.push_back(new RawKeyboard());
		rawInputDevices.push_back(new RawMouse());
	}

	int RawInputManagement::RegisterDevices(HWND handle)
	{
		UInt numDevices = rawInputDevices.size();
		PRAWINPUTDEVICE inputDevice = new RAWINPUTDEVICE[numDevices];

		for (UInt i = 0; i < rawInputDevices.size(); ++i)
		{
			rawInputDevices[i]->SetHandle(handle);

			inputDevice[i].usUsagePage = 0x01;
			inputDevice[i].usUsage = rawInputDevices[i]->GetUsage();
			inputDevice[i].dwFlags = RIDEV_INPUTSINK;
			inputDevice[i].hwndTarget = handle;
		}

		return RegisterRawInputDevices(inputDevice, numDevices, sizeof(RAWINPUTDEVICE));
	}

	int RawInputManagement::UnregisterDevices(void)
	{
		UInt numDevices = rawInputDevices.size();
		PRAWINPUTDEVICE inputDevice = new RAWINPUTDEVICE[numDevices];

		for (UInt i = 0; i < rawInputDevices.size(); ++i)
		{
			inputDevice[i].usUsagePage = 0x01;
			inputDevice[i].usUsage = rawInputDevices[i]->GetUsage();
			inputDevice[i].dwFlags = RIDEV_REMOVE;
			inputDevice[i].hwndTarget = 0L;
		}

		return RegisterRawInputDevices(inputDevice, numDevices, sizeof(RAWINPUTDEVICE));
	}

	bool RawInputManagement::HandleMessage(HDC deviceContext, LPARAM lParam)
	{
		UInt size = 0;
		GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, 0L, &size, sizeof(RAWINPUTHEADER));

		void* data = (void*)malloc(size);
		__try
		{
			GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, data, &size, sizeof(RAWINPUTHEADER));
			for (UInt i = 0; i < rawInputDevices.size(); ++i)
				rawInputDevices[i]->MessageProc(data, deviceContext, lParam);
		}
		__finally
		{
			free(data);
		}

		return true;
	}

	IKeyboard* RawInputManagement::GetKeyboard(void)
	{
		return static_cast<RawKeyboard*>(rawInputDevices[0]);
	}

	IMouse* RawInputManagement::GetMouse()
	{
		return static_cast<RawMouse*>(rawInputDevices[1]);
	}

	IInputBase* RegisterInputManagement(void)
	{
		return new RawInputManagement;
	}
}