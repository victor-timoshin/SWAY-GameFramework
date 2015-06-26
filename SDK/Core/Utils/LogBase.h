#ifndef LOG_BASE_H
#define LOG_BASE_H

#include "../../Platform.h"

namespace Core
{
	namespace Utils
	{
		typedef enum LoggerLevel
		{
			Critical = 0x07D9,
			Error = 0x254B,
			Info = 0x90E3,
			Debug = 0xDE67
		} LOGGER_LEVEL;

		class ILogBase
		{
		public:
			/** Constructor. */
			ILogBase(const char* fileName) {}

			/** Destructor. */
			virtual ~ILogBase() {}

			virtual void Write(LOGGER_LEVEL type, const char* format, ...) = 0;
		};

		CORE_API ILogBase* RegisterLogger(const char* fileName);
	}
}

#endif // LOG_BASE_H