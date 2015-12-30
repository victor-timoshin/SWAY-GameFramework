#ifndef TIMER_H
#define TIMER_H

#include "../../SDK/System/TimerBase.h"
#include "../StdAfx.h"

namespace System
{
	class Timer : public ITimerBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Timer(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Timer(void);

		/// <summary>Запускает таймер.</summary>
		virtual void Start(void);

		/// <summary>Останавливаем таймер.</summary>
		virtual void Stop(void);

		virtual void Reset(void);

		virtual LONGLONG GetInterval(void);

		virtual LARGE_INTEGER GetStartTime(void);

		virtual LARGE_INTEGER GetEndTime(void);

		virtual bool HasRunning(void) const;

	private:
		LARGE_INTEGER _frequency;
		LARGE_INTEGER _startTime;
		LARGE_INTEGER _endTime;

		bool _isRunning;
	};
}

#endif // TIMER_H