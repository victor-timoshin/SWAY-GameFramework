#ifndef BUFFERFORMAT_H
#define BUFFERFORMAT_H

namespace Sapi
{
	typedef enum BufferFormat
	{
		Mono8    = 0x8830,
		Mono16   = 0xB0EA,
		Stereo8  = 0x9789,
		Stereo16 = 0x9751
	} BUFFER_FORMAT;
}

#endif // BUFFERFORMAT_H