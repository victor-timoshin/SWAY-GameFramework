#ifndef STREAM_BASE_H
#define STREAM_BASE_H

#include <stdio.h>

namespace Core
{
	namespace Utils
	{
		typedef enum StreamMode
		{
			Read = 0,
			Write = 1
		} STREAM_MODE;

		class IStreamBase
		{
		public:
			/** Constructor. */
			IStreamBase() {}

			/** Destructor. */
			virtual ~IStreamBase() {}

			virtual void Open(const char* fileName, STREAM_MODE mode, bool binary) = 0;

			virtual void Close() = 0;

			virtual void Seek() = 0;

			virtual void Print(const char* str) = 0;

			virtual bool IsOpen() const = 0;

			virtual FILE* GetFileHandle() const = 0;
		};
	}
}

#endif // STREAM_BASE_H