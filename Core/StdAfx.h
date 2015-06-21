#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Platform.h"

#if defined(PLATFORM_WINDOWS)
	#include <windows.h>
	#include <time.h>
#elif defined(PLATFORM_LINUX)
	#include <stddef.h>
	#include <unistd.h>
	#include <sys/time.h>
	#include <sys/mman.h>
#endif

#endif