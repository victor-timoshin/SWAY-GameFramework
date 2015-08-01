#ifndef STREAMLOGGER_H
#define STREAMLOGGER_H

#include "../../../SDK/Core/Utils/LoggerBase.h"
#include "../../../SDK/Core/Utils/StreamBase.h"
#include "../../../SDK/Core/Utils/Singleton.h"

#include <iostream>
#include <fstream>

namespace Utils
{
	class CORE_API StreamLogger : public Utils::ILoggerBase, public Utils::TSingleton<StreamLogger>
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="filename">Имя файла.</param>
		StreamLogger(const char* filename);

		/// <summary>Деструктор класса.</summary>
		virtual ~StreamLogger(void);

		virtual void Write(Utils::LOGLEVELS level, const char* format, ...);

	private:
		//std::ostream* stream;
	};
}

#define STREAMLOGGERDEBUG StreamLogger::GetInstancePtr()->Write

#endif // STREAMLOGGER_H