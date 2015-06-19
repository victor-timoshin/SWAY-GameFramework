#ifndef STDAFX_H
#define STDAFX_H

#include <Windows.h>

#include <gl/gl.h>
#include <gl/glu.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

typedef unsigned int UInt32;

#ifdef BUILDING_CORE
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif

typedef long int RESULT;
#define SUCCEEDED(x) (((RESULT)(x)) >= 0)
#define FAILED(x) (((RESULT)(x)) < 0)

#define CHECK_ERROR(x) if(FAILED(x)) { return false; }

#define SAFE_RELEASE(x) if(x != 0L) { x->Release(); x = 0L; }
#define SAFE_DELETE(x) if(x != 0L) { delete x; x = 0L; }
#define SAFE_DELETE_ARRAY(x) if(x != 0L) { delete[] x; x = 0L; }

#endif