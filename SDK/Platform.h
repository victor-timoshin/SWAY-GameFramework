#ifndef PLATFORM_H
#define PLATFORM_H

#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#include <windowsx.h>

#include <stdlib.h>
#include <string>
#include <map>

#include <fstream>
#include <iostream>

#include "Defines.h"

#include "Core/Utils/FileModes.h"
#include "Core/Utils/LogLevels.h"

#include "Gapi/ClearFlags.h"
#include "Gapi/ShaderTypes.h"
#include "Gapi/BufferTypes.h"
#include "Gapi/VertexElementTypes.h"
#include "Gapi/VertexElementFormats.h"
#include "Gapi/PrimitiveTypes.h"

#include "Math/Color.h"

typedef unsigned int UInt;
typedef unsigned char UByte;
typedef unsigned short UInt16;
typedef unsigned long UInt32;
typedef unsigned long long UInt64;

#endif // PLATFORM_H