#include "../../../Core/Inc/System/Mutex.h"

namespace Core
{
	namespace System
	{
		/// <summary>Конструктор класса.</summary>
		Mutex::Mutex(void)
		{
			memset((void*)&criticalSection, 0, sizeof criticalSection);
		}

		/// <summary>Деструктор класса.</summary>
		Mutex::~Mutex(void)
		{
			Delete();
		}

		void Mutex::Create(void)
		{
			InitializeCriticalSection(&criticalSection);
		}

		void Mutex::Delete(void)
		{
			DeleteCriticalSection(&criticalSection);
		}

		void Mutex::Lock(void)
		{
			EnterCriticalSection(&criticalSection);
		}

		void Mutex::Unlock(void)
		{
			LeaveCriticalSection(&criticalSection);
		}

		bool Mutex::TryEnter(void)
		{
			return TryEnterCriticalSection(&criticalSection) == TRUE;
		}
	}
}