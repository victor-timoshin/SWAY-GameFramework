#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Core/Utils/LoggerBase.h"
#include "../SDK/Platform.h"

#include <gl/gl.h>
#include <gl/glu.h>

#include <sstream>
#include <algorithm>

//#define GL_GLEXT_PROTOTYPES
#include "../GapiOpenGL/Inc/GL/glext.h"

#pragma comment(lib, "Core_Win32_Debug")

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

#define LOAD_EXTENSION(proc, name) \
	name = (proc)wglGetProcAddress(#name);

//REPORT
//OPENGL_CHECKERROR
#define CHECK_GLERROR() { \
	GLenum error = glGetError(); \
	if (error != GL_NO_ERROR) { \
		while (error != GL_NO_ERROR) { \
			Utils::StreamLoggerWrite(Utils::LOGLEVELS::ELL_ERROR, "glError: %i - %s caught at %s:%u", (int)error, (char*)gluErrorString(error), __FILE__, __LINE__); \
			error = glGetError(); \
		} \
	} \
}

#endif