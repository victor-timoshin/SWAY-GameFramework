#include "../../../Core/Inc/Utils/FileLogger.h"
#include "../../../Core/Inc/Utils/FileStream.h"

#include <stdarg.h>
#include <time.h>

namespace Utils
{
	/// <summary>Конструктор класса.</summary>
	/// <param name="filename">Имя файла.</param>
	FileLogger::FileLogger(const char* filename) : ILoggerBase(filename)
		, stream(NULL)
	{
		stream = new Core::Utils::FileStream();
		stream->Open(filename, Core::Utils::FILE_MODE::Write, false);
	}

	/// <summary>Деструктор класса.</summary>
	FileLogger::~FileLogger(void)
	{
		stream->Close();
	}

	void FileLogger::Write(Utils::LOG_LEVEL level, const char* format, ...)
	{
		if (stream->IsOpen())
		{
			FILE* file = stream->GetFileHandle();
			char bufferMessage[1024];

			char* priority;
			switch (level)
			{
			case LOG_LEVEL::Info:
				priority = "INF| ";
				break;

			case LOG_LEVEL::Debug:
				priority = "DBG| ";
				break;

			case LOG_LEVEL::Error:
				priority = "ERR| ";
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

	Utils::ILoggerBase* RegisterFileLogger(const char* filename)
	{
		return new FileLogger(filename);
	}
}