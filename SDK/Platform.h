#ifndef PLATFORM_H
#define PLATFORM_H

#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX

#include <windows.h>
#include <windowsx.h>

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
#include "Conversion.h"

//#include "Core/Utils/File.h"
#include "Core/Utils/FileType.h"
#include "Core/Utils/FileMode.h"
#include "Core/Utils/LogLeveL.h"

#include "Gapi/ClearFlag.h"
#include "Gapi/CullFormat.h"
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