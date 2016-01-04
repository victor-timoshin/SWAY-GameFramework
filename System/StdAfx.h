#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Platform.h"

#ifdef PLATFORM_WINDOW
	#include <time.h>
#elif PLATFORM_LINUX
	#include <sys/time.h>
	#include <sys/mman.h>
#endif

#pragma comment(lib, "OIS_Win32_Debug")

#endif // STDAFX_H