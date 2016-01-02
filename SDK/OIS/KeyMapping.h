#ifndef KEYMAPPING_H
#define KEYMAPPING_H

#include "KeyCode.h"

namespace OIS
{
	typedef struct KeyMapping
	{
		const char* charCode;
		KEY_CODE keyCode;
	} KEY_MAPPING, *KEY_MAPPING_PTR;
}

#endif // KEYMAPPING_H