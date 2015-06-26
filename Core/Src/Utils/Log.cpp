#include "../../../Core/Inc/Utils/Log.h"
#include "../../../Core/Inc/Utils/StreamFile.h"

#include <stdarg.h>
#include <time.h>

namespace Core
{
	namespace Utils
	{
		/** Constructor. */
		Log::Log(const char* fileName) : ILogBase(fileName)
			, stream(0L)
		{
			stream = new StreamFile();
			stream->Open(fileName, STREAM_MODE::Write, false);
		}

		/** Destructor. */
		Log::~Log()
		{
			stream->Close();
		}

		void Log::Write(LOGGER_LEVEL type, const char* format, ...)
		{
			if (stream->IsOpen())
			{
				FILE* file = stream->GetFileHandle();
				char bufferMessage[1024];

				char* priority;
				switch (type)
				{
				case LOGGER_LEVEL::Critical:
					priority = "CRITICAL| ";
					break;
				case LOGGER_LEVEL::Error:
					priority = "ERROR| ";
					break;
				case LOGGER_LEVEL::Info:
					priority = "INFO| ";
					break;
				case LOGGER_LEVEL::Debug:
					priority = "DEBUG| ";
					break;
				}

				va_list args;
				va_start(args, format);
					vsprintf_s(bufferMessage, format, args);
				va_end(args);

				//time_t now = time(0L);
				//struct tm localTime;
				//char str[12];

				//localtime_s(&localTime, &now);
				//strftime(str, sizeof str, "%H:%M:%S", &localTime);
				//fprintf(file, "%s|", str);

				fprintf(file, "%s%s\n", priority, bufferMessage);
			}
		}

		ILogBase* RegisterLogger(const char* fileName)
		{
			return new Log(fileName);
		}
	}
}