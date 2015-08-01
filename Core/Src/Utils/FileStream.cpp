#include "../../../Core/Inc/Utils/FileStream.h"

namespace Core
{
	namespace Utils
	{
		/// <summary>Конструктор класса.</summary>
		FileStream::FileStream(void)
			: file(0), numBytes(0)
		{
		}

		/// <param name="filename">Имя файла.</param>
		void FileStream::Open(const char* filename, FILEMODES mode, bool binary)
		{
			switch (mode)
			{
			case FILEMODES::EFM_READ:
				fopen_s(&file, filename, binary ? "rb" : "rt");
				break;

			case FILEMODES::EFM_WRITE:
				fopen_s(&file, filename, binary ? "wb" : "wt");
				break;
			}

			fseek(file, 0L, SEEK_END);
			numBytes = (unsigned int)ftell(file);
			fseek(file, 0L, SEEK_SET);
		}

		void FileStream::Close(void)
		{
			if (file != 0)
				fclose(file);

			file = 0;
		}

		void FileStream::Print(const char* str)
		{
			if (file != 0 && str != 0)
				fprintf(file, str);
		}

		bool FileStream::IsOpen(void) const
		{
			return file != 0;
		}

		FILE* FileStream::GetFileHandle(void) const
		{
			return file;
		}

		UInt FileStream::GetFileLength(void) const
		{
			return numBytes;
		}
	}
}