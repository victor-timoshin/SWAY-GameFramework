#ifndef STREAMBASE_H
#define STREAMBASE_H

#include "../../Platform.h"
#include <stdio.h>

namespace Core
{
	namespace Utils
	{
		class IStreamBase
		{
		public:
			/// <summary>����������� ������.</summary>
			IStreamBase(void) {}

			/// <summary>���������� ������.</summary>
			virtual ~IStreamBase(void) {}

			/// <param name="filename">��� �����.</param>
			virtual void Open(const char* filename, FILEMODES mode, bool binary) = 0;

			virtual void Close(void) = 0;

			virtual void Seek(void) = 0;

			virtual void Print(const char* str) = 0;

			virtual bool IsOpen(void) const = 0;

			virtual FILE* GetFileHandle(void) const = 0;

			virtual UInt GetFileLength(void) const = 0;
		};
	}
}

#endif // STREAMBASE_H