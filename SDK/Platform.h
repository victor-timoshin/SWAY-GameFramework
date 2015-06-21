#ifndef PLATFORM_H
#define PLATFORM_H

/** ONLY WINDOWS
*/

#if defined(WIN32) || defined(WIN64)
	#define PLATFORM_WINDOWS

	#ifdef BUILDING_CORE
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_API __declspec(dllimport)
	#endif

	#include <windows.h>
	#include <windowsx.h>
#elif defined(__linux__) /* POSIX */
	#define PLATFORM_LINUX

	#ifdef __cplusplus
		#define CORE_API extern "C"
	#else
		#define CORE_API extern
	#endif

	#include <stdlib.h>
	#include <dirent.h>
	#include <dlfcn.h>

	#include <GL/glx.h>
	#include <GL/gl.h>

	#include <X11/X.h>
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#endif

#include <stdlib.h>
#include <string>
#include <map>

typedef unsigned int UInt;
typedef unsigned char UByte;
typedef unsigned short UInt16;
typedef unsigned long UInt32;

typedef long int RESULT;
#define RESULT_SUCCEEDED(x) (((RESULT)(x)) >= 0)
#define RESULT_FAILED(x) (((RESULT)(x)) < 0)

#define CHECK_ERROR(x) if(FAILED(x)) { return false; }

#define SAFE_RELEASE(x) if(x != 0L) { x->Release(); x = 0L; }
#define SAFE_DELETE(x) if(x != 0L) { delete x; x = 0L; }
#define SAFE_DELETE_ARRAY(x) if(x != 0L) { delete[] x; x = 0L; }

#endif