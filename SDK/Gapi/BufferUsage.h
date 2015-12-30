#ifndef BUFFERUSAGE_H
#define BUFFERUSAGE_H

namespace Gapi
{
	typedef enum class BufferUsage {
		Static  = 0xA0E7,
		Dynamic = 0xF1D8,
		Stream  = 0x7F94
	} BUFFER_USAGE;
}

#endif // BUFFERUSAGE_H