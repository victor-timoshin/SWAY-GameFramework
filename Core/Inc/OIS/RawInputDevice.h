#ifndef RAW_INPUT_DEVICE_H
#define RAW_INPUT_DEVICE_H

#include "../../StdAfx.h"

namespace OIS
{
	class IRawInputDevice
	{
	public:
		/* Constructor. */
		IRawInputDevice() { }

		/* Destructor. */
		virtual ~IRawInputDevice() { }

		virtual void MessageProc(void* data, HDC deviceContext, LPARAM lParam) = 0;

		virtual UInt16 GetUsage() = 0;
	};
}

#endif // RAW_INPUT_DEVICE_H