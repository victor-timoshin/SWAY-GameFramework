#ifndef LOGLEVEL_H
#define LOGLEVEL_H

namespace Utils
{
	typedef enum class LogLevel
	{
		Info  = 0x90E3,
		Debug = 0x07D9,
		Error = 0x254B
	} LOG_LEVEL;
}

#endif // LOGLEVEL_H