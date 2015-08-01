#ifndef LOGGERBASE_H
#define LOGGERBASE_H

#include "../../../SDK/Core/Utils/Singleton.h"
#include "../../Platform.h"

#define LOG_DEBUG ILoggerBase::GetInstancePtr()->Write

namespace Utils
{
	class ILoggerBase : public Utils::TSingleton<ILoggerBase>
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="filename">Имя файла.</param>
		ILoggerBase(const char* filename) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ILoggerBase(void) {}

		virtual void Write(LOGLEVELS level, const char* format, ...) = 0;
	};

	CORE_API ILoggerBase* RegisterFileLogger(const char* fileName);
	CORE_API ILoggerBase* RegisterStreamLogger(const char* fileName);

	CORE_API void StreamLoggerWrite(LOGLEVELS level, const char* format, ...);
}

#endif // LOGGERBASE_H