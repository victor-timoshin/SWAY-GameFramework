#ifndef BUFFERTYPE_H
#define BUFFERTYPE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	typedef enum ByfferType
	{
		Vertex = 0x2CA1,
		Index  = 0xE70D // Indexed arrays.
	} BUFFER_TYPE;
}

#endif // BUFFERTYPE_H