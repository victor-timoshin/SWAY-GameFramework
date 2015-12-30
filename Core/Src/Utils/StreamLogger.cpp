#include "../../../Core/Inc/Utils/StreamLogger.h"

namespace Utils
{
	/// <summary>Конструктор класса.</summary>
	/// <param name="filename">Имя файла.</param>
	StreamLogger::StreamLogger(const char* filename) : ILoggerBase(filename)
		//, stream(0)
	{
		//stream = std::cout;
		//stream = new std::ofstream(filename);
	}

	/// <summary>Деструктор класса.</summary>
	StreamLogger::~StreamLogger(void)
	{
		//SAFE_DELETE(stream);
	}

	void StreamLogger::Write(Utils::LOG_LEVEL level, const char* format, ...)
	{
		char bufferMessage[1024];

		std::ofstream myfile("log_file.txt", std::ios_base::out | std::ios_base::app);

		va_list args;
		va_start(args, format);
		vsprintf_s(bufferMessage, format, args);
		va_end(args);

		myfile << bufferMessage << "\n";
		myfile.close();
	}

	Utils::ILoggerBase* RegisterStreamLogger(const char* fileName)
	{
		return new StreamLogger(fileName);
	}

	void StreamLoggerWrite(LOG_LEVEL level, const char* format, ...)
	{
		char bufferMessage[5024];

		std::ofstream myfile("log_file.txt", std::ios_base::out | std::ios_base::app);

		va_list args;
		va_start(args, format);
		vsprintf_s(bufferMessage, format, args);
		va_end(args);

		myfile << bufferMessage << "\n";
		myfile.close();
	}
}