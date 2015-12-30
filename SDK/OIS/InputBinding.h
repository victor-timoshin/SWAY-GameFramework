#ifndef INPUTBINDING_H
#define INPUTBINDING_H

#include "KeyCodes.h"
#include "../Platform.h"

namespace OIS
{
	typedef void(*InputBindingFn)(const void*);

	typedef struct InputBinding
	{
		KeyCode key;
		UInt modifiers;
		UInt flags;
		InputBindingFn fn;
		const void* userData;
	} LINPUT_BINDING, *PINPUT_BINDING;
}

#endif // INPUTBINDING_H