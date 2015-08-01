#ifndef BUFFERTYPES_H
#define BUFFERTYPES_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	typedef enum ByfferTypes
	{
		EBT_VERTEX = 0x2CA1,
		EBT_INDEX = 0xE70D // Indexed arrays.
	} BUFFERTYPES;
}

#endif // BUFFERTYPES_H