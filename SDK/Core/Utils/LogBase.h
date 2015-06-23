#ifndef LOG_BASE_H
#define LOG_BASE_H

#include "../../Platform.h"

namespace Core
{
	namespace Utils
	{
		typedef enum LoggerLevel
		{
			Critical = 0,
			Error = 1,
			Info = 2,
			Debug = 3
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