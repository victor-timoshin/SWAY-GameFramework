#ifndef WINDOWDESC_H
#define WINDOWDESC_H

#include "../Platform.h"

namespace System
{
	typedef struct WindowDesc
	{
		HWND handle;
		WNDPROC proc;
		WINDOWMODE mode;
		const char* title;
		UInt width;
		UInt height;
	} LWINDOWDESC, *PWINDOWDESC;
}

#endif // WINDOWDESC_H