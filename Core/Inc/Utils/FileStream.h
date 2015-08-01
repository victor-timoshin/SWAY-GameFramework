#ifndef FILESTREAM_H
#define FILESTREAM_H

#include "../../../SDK/Core/Utils/StreamBase.h"

namespace Core
{
	namespace Utils
	{
		class FileStream : public IStreamBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			FileStream(void);

			/// <summary>Деструктор класса.</summary>
			virtual ~FileStream(void) { }

			virtual void Open(const char* filename, FILEMODES mode, bool binary);

			virtual void Close(void);

			virtual void Seek(void) { }

			virtual void Print(const char* str);

			virtual bool IsOpen(void) const;

			virtual FILE* GetFileHandle(void) const;

			virtual UInt GetFileLength(void) const;

		private:
			FILE* file;
			UInt numBytes;

			std::ifstream in;
			std::ofstream out;
		};
	}
}

#endif // FILESTREAM_H