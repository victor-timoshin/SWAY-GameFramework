#ifndef INPUTBINDING_H
#define INPUTBINDING_H

#include "KeyCode.h"
#include "../Platform.h"

namespace OIS
{
	typedef void(*InputBindingFn)(const void*);

	typedef struct InputBinding
	{
		KEY_CODE keyCode;
		UInt modifiers;
		UInt flags;
		InputBindingFn fn;
		const void* userData;
	} INPUT_BINDING, *INPUT_BINDING_PTR;
}

#endif // INPUTBINDING_H