#ifndef MUTEX_H
#define MUTEX_H

#include "../../../SDK/Platform.h"

namespace Core
{
	namespace System
	{
		class Mutex
		{
		public:
			/* Constructor. */
			Mutex(void);

			/* Destructor. */
			~Mutex(void);

			void Create(void);

			void Delete(void);

			void Lock(void);

			void Unlock(void);

			bool TryEnter(void);

		private:
			CRITICAL_SECTION criticalSection;
		};
	}
}

#endif // SX_MUTEX_H