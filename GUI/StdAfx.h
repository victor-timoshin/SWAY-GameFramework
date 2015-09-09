#ifndef STDAFX_H
#define STDAFX_H

#include "../SDK/Core/Utils/LoggerBase.h"
#include "../SDK/Platform.h"

#include <ft2build.h>

#include FT_FREETYPE_H
#include FT_GLYPH_H

#ifdef RELEASE
	#pragma comment (lib, "freetype26.lib")
#else
	#pragma comment (lib, "freetype26d.lib")
#endif

#define LOAD_EXTENSION(proc, name) \
	name = (proc)wglGetProcAddress(#name);

#endif