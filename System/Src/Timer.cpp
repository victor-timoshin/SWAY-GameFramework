#include "../Inc/Timer.h"

namespace System
{
	/// <summary>Конструктор класса.</summary>
	Timer::Timer(void)
	{
		// Извлекаем частоту счетчика производительности
		QueryPerformanceFrequency(&_frequency);
		_isRunning = false;
	}

	/// <summary>Деструктор класса.</summary>
	Timer::~Timer(void)
	{
	}

	/// <summary>Запускает таймер.</summary>
	void Timer::Start(void)
	{
		// Извлекаем текущее значение счетчика производительности
		QueryPerformanceCounter(&_startTime);
		_isRunning = true;
	}

	/// <summary>Останавливаем таймер.</summary>
	void Timer::Stop(void)
	{
		QueryPerformanceCounter(&_endTime);
		_isRunning = false;
	}

	void Timer::Reset(void)
	{
		QueryPerformanceCounter(&_endTime);
		_isRunning = false;

		memset(&_startTime, 0, sizeof(LARGE_INTEGER));
		memset(&_endTime, 0, sizeof(LARGE_INTEGER));
	}

	LONGLONG Timer::GetInterval(void)
	{
		if (HasRunning())
		{
			LARGE_INTEGER Temp;
			QueryPerformanceCounter(&Temp);
			return (Temp.QuadPart - _startTime.QuadPart) * 1000 / _frequency.QuadPart;
		}

		return (_endTime.QuadPart - _startTime.QuadPart) * 1000 / _frequency.QuadPart;
	}

	LARGE_INTEGER Timer::GetStartTime(void)
	{
		return _startTime;
	}

	LARGE_INTEGER Timer::GetEndTime(void)
	{
		return _endTime;
	}

	bool Timer::HasRunning(void) const
	{
		return _isRunning;
	}

	ITimerBase* RegisterTimer(void)
	{
		return new Timer();
	}
}