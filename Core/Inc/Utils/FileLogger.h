#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "../../../SDK/Core/Utils/LoggerBase.h"
#include "../../../SDK/Core/Utils/StreamBase.h"

namespace Utils
{
	class CORE_API FileLogger : public Utils::ILoggerBase
	{
	public:
		/// <summary>����������� ������.</summary>
		/// <param name="filename">��� �����.</param>
		FileLogger(const char* filename);

		/// <summary>���������� ������.</summary>
		virtual ~FileLogger(void);

		virtual void Write(Utils::LOG_LEVEL level, const char* format, ...);

	private:
		Core::Utils::IStreamBase* stream;
	};
}

#endif // FILELOGGER_H