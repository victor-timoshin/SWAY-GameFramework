#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Core/Utils/LoggerBase.h"
#include "../SDK/Platform.h"

#include <ft2build.h>
#include <ftstroke.h>

#include FT_FREETYPE_H
#include FT_GLYPH_H

#ifdef RELEASE
	#pragma comment (lib, "freetype26.lib")
#else
	#pragma comment (lib, "freetype26d.lib")
#endif

#define LOAD_EXTENSION(proc, name) \
	name = (proc)wglGetProcAddress(#name);





#include "../SDK/Core/Scene/GeometryPacket.h"

#include "../SDK/Core/Utils/LoggerBase.h"
#include "../Math/Inc/Matrix4F.h"
#include "../Math/Inc/Rect.h"
#include "../Math/Inc/Size.h"
#include "../Math/Inc/Color.h"

#include <gl/gl.h>
#include <gl/glu.h>

#include "../GapiOpenGL/Inc/GL/glext.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

#pragma comment(lib, "Core_Win32_Debug")

#endif