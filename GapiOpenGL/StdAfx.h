#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Platform.h"

#include <gl/gl.h>
#include <gl/glu.h>

#ifdef PLATFORM_WINDOWS
	#include <sstream>
	#include <algorithm>

	//#define GL_GLEXT_PROTOTYPES
	#include "../GapiOpenGL/Inc/GL/glext.h"

	#pragma comment (lib, "opengl32.lib")
	#pragma comment (lib, "glu32.lib")
#endif

#ifdef PLATFORM_ANDROID
	#include "../GapiOpenGL/Inc/GLES2/gl2.h"
	#include "../GapiOpenGL/Inc/GLES2/gl2ext.h"
#endif

#ifdef PLATFORM_WINDOWS
	#define LOAD_EXTENSION(proc, name) \
		name = (proc)wglGetProcAddress(#name);
#else
#define LOAD_EXTENSION(proc, name) \
		name = (void*)glXGetProcAddressARB((const UByte*)name);
#endif

#endif