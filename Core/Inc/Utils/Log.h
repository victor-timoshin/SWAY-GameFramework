#ifndef LOG_H
#define LOG_H

#include "../../../SDK/Core/Utils/LogBase.h"
#include "../../../SDK/Core/Utils/StreamBase.h"
#include <stdio.h>

namespace Core
{
	namespace Utils
	{
		class Log: public ILogBase
		{
		public:
			/** Constructor. */
			Log(const char* fileName);

			/** Destructor. */
			virtual ~Log();

			virtual void Write(LOGGER_LEVEL type, const char* format, ...);

		private:
			IStreamBase* stream;
		};
	}
}

#endif // LOG_H