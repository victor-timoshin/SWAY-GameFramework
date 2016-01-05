#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(_WIN32) || defined(__WIN32__) || defined(__WINDOWS__) || defined(WIN32)
	#define PLATFORM_WINDOW

	#define WIN32_LEAN_AND_MEAN 1
	#define NOMINMAX

	#ifdef BUILDING_CORE
		#define CORE_API __declspec(dllexport)
	#else
		#define CORE_API __declspec(dllimport)
	#endif

	#include <windows.h>
	#include <windowsx.h>
#elif defined(__linux__)
	#define PLATFORM_LINUX
	#define PLATFORM_UNIX

	#ifdef __cplusplus
		#define CORE_API extern "C"
	#else
		#define CORE_API extern
	#endif

	#include <stdlib.h>
	#include <dirent.h>
	#include <dlfcn.h>
	#include <stddef.h>
	#include <unistd.h>

	#include <X11/X.h>
	#include <X11/Xlib.h>
	#include <X11/Xutil.h>
#elif defined(__APPLE__)
	#define PLATFORM_UNIX

	#if TARGET_OS_IPHONE
		#define PLATFORM_IPHONE
	#elif TARGET_IPHONE_SIMULATOR
		#define PLATFORM_IPHONE_SIMULATOR
	#elif TARGET_OS_MAC
		#define PLATFORM_MAC_OS_X
		#define PLATFORM_OSX
		#define PLATFORM_UNIX
	#endif
#elif defined(__ANDROID__)
	#define PLATFORM_ANDROID
#else
	#error "platform not supported"
#endif

#include <stdlib.h>
#include <string> // std::string
#include <locale> // std::locale, std::toupper
#include <vector>
#include <map>
#include <list>
#include <set>

#include <memory> // std::shared_ptr, std::unique_ptr

#include <fstream>
#include <iostream> // std::cout, std::ios
#include <sstream> // std::ostringstream

#include <math.h>

typedef unsigned int UInt; // 32-битное число без знака.
typedef unsigned char UByte;
typedef unsigned short UInt16; // 16-битное число без знака.
typedef unsigned long UInt32;
typedef unsigned long long UInt64;

#include "Defines.h"

//#include "Core/Utils/File.h"
#include "Core/Utils/FileType.h"
#include "Core/Utils/FileMode.h"
#include "Core/Utils/LogLeveL.h"

#include "Gapi/ClearFlag.h"
#include "Gapi/FeatureType.h"
#include "Gapi/CullFace.h"
#include "Gapi/FrontFace.h"
#include "Gapi/BlendFunction.h"
#include "Gapi/CompareFunction.h"
#include "Gapi/StencilOperation.h"
#include "Gapi/ShaderType.h"
#include "Gapi/BufferType.h"
#include "Gapi/BufferUsage.h"
#include "Gapi/VertexElementType.h"
#include "Gapi/VertexElementFormat.h"
#include "Gapi/PrimitiveType.h"
#include "Gapi/TextureFormat.h"
#include "Gapi/TextureFilter.h"
#include "Gapi/TextureWrap.h"

#endif // PLATFORM_H