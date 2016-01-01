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
			virtual ~FileStream(void);

			/// <summary>Открытие файла.</summary>
			/// <param name="filename">Имя файла.</param>
			/// <param name="mode">Режим открытия.</param>
			virtual void Open(const char* filename, FILE_MODE mode, bool binary);

			/// <summary>Открытие файла.</summary>
			/// <param name="filename">Имя файла.</param>
			/// <param name="type">Тип файла.</param>
			virtual bool OpenStream(const std::string& filename, FILE_TYPE type);

			virtual void CloseStream(void);

			virtual bool IsOpenStream(void);

			virtual std::ifstream& GetStream(void);

			virtual void Close(void);

			virtual void Seek(void) { }

			virtual void Print(const char* str);

			virtual bool IsOpen(void) const;

			virtual FILE* GetFileHandle(void) const;

			virtual UInt GetFileLength(void) const;

			std::string GetFilename(void) const;

		private:
			FILE* file;
			UInt numBytes;

			std::ifstream in; // Объект класса для чтения из файла.
			std::ofstream out;

			std::string _filename;
		};
	}
}

#endif // FILESTREAM_H