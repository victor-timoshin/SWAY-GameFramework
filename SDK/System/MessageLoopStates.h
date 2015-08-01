#ifndef MESSAGELOOPSTATES_H
#define MESSAGELOOPSTATES_H

namespace System
{
	typedef enum MessageLoopState
	{
		EMLS_RUN = 0xAE23,
		EMLS_END = 0x0A3C
	} MESSAGELOOPSTATE;
}

#endif // MESSAGELOOPSTATES_H