#ifndef TIMEBASE_H
#define TIMEBASE_H

#include "../Platform.h"

namespace System
{
	class ITimerBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ITimerBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ITimerBase(void) {}

		/// <summary>Запускает таймер.</summary>
		virtual void Start(void) = 0;

		/// <summary>Останавливаем таймер.</summary>
		virtual void Stop(void) = 0;

		virtual void Reset(void) = 0;

		virtual LONGLONG GetInterval(void) = 0;

		virtual LARGE_INTEGER GetStartTime(void) = 0;

		virtual LARGE_INTEGER GetEndTime(void) = 0;

		virtual bool HasRunning(void) const = 0;
	};

	CORE_API ITimerBase* RegisterTimer(void);
}

#endif // TIMEBASE_H