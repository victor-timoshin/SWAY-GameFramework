#ifndef DEFINES_H
#define DEFINES_H

#ifdef BUILDING_CORE
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif

#define SAFE_RELEASE(x) if(x != NULL) { x->Release(); x = NULL; }
#define SAFE_DELETE(x) if(x != NULL) { delete x; x = NULL; }
#define SAFE_DELETE_ARRAY(x) if(x != NULL) { delete[] x; x = NULL; }

#endif // DEFINES_H