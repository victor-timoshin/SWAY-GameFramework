#ifndef RAWINPUTDEVICE_H
#define RAWINPUTDEVICE_H

#include "../StdAfx.h"

namespace OIS
{
	class IRawInputDevice
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IRawInputDevice(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IRawInputDevice(void) {}

		virtual void MessageProc(void* data, HDC deviceContext, LPARAM lParam) = 0;

		virtual void SetHandle(HWND handle) = 0;

		virtual UInt16 GetUsage(void) = 0;
	};
}

#endif // RAWINPUTDEVICE_H