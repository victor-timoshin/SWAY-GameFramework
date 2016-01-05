#ifndef AUDIODESCRIPTION_H
#define AUDIODESCRIPTION_H

#include "../Platform.h"
#include "BufferFormat.h"

namespace Sapi
{
	typedef struct AudioDescription
	{
		void* data;
		BUFFER_FORMAT format;
		UInt size;
		UInt frequency;
	} AUDIO_DESCRIPTION, *AUDIO_DESCRIPTION_PTR;
}

#endif // AUDIODESCRIPTION_H