#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Platform.h"

#include <gl/gl.h>
#include <gl/glu.h>

#include <sstream>
#include <algorithm>

//#define GL_GLEXT_PROTOTYPES
#include "../GapiOpenGL/Inc/GL/glext.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

#define LOAD_EXTENSION(proc, name) \
	name = (proc)wglGetProcAddress(#name);

#endif