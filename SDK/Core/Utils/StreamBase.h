#ifndef STREAMBASE_H
#define STREAMBASE_H

#include "../../Platform.h"
#include <stdio.h>

namespace Core
{
	namespace Utils
	{
		typedef enum StreamMode {
			Text   = 0,
			Binary = 1
		} STREAM_MODE;

		class IStreamBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			IStreamBase(void) {}

			/// <summary>Деструктор класса.</summary>
			virtual ~IStreamBase(void) {}

			/// <param name="filename">Имя файла.</param>
			virtual void Open(const char* filename, FILE_MODE mode, bool binary) = 0;

			virtual bool OpenStream(const std::string& filename, STREAM_MODE mode) = 0;

			virtual void CloseStream(void) = 0;

			virtual bool IsOpenStream(void) = 0;

			virtual std::ifstream& GetStream(void) = 0;

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