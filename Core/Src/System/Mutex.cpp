#include "../../../Core/Inc/System/Mutex.h"

namespace Core
{
	namespace System
	{
		/* Constructor. */
		Mutex::Mutex(void)
		{
			memset((void*)&criticalSection, 0, sizeof criticalSection);
		}

		/* Destructor. */
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