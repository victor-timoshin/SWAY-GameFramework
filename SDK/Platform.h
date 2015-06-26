#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef BUILDING_CORE
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif

#include <windows.h>
#include <windowsx.h>

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

#endif // PLATFORM_H