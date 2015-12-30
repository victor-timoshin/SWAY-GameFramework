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

		/// <summary>Деструктор класса.</summary>
		FileStream::~FileStream(void)
		{
		}

		/// <summary>Открытие файла.</summary>
		/// <param name="filename">Имя файла.</param>
		/// <param name="mode">Режим открытия.</param>
		void FileStream::Open(const char* filename, FILE_MODE mode, bool binary)
		{
			switch (mode)
			{
			case FILE_MODE::Read:
				fopen_s(&file, filename, binary ? "rb" : "rt");
				break;

			case FILE_MODE::Write:
				fopen_s(&file, filename, binary ? "wb" : "wt");
				break;
			}

			fseek(file, 0L, SEEK_END);
			numBytes = (unsigned int)ftell(file);
			fseek(file, 0L, SEEK_SET);
		}

		/// <summary>Открытие файла.</summary>
		/// <param name="filename">Имя файла.</param>
		/// <param name="mode">Режим открытия.</param>
		bool FileStream::OpenStream(const std::string& filename, STREAM_MODE mode)
		{
			//setlocale(LC_ALL, "rus");

			std::ios::openmode openMode = std::ios::in; // Открыть файл для чтения.
			if (mode == STREAM_MODE::Binary)
				openMode |= std::ios::binary; // Открытие файла в двоичном режиме.

			// Открываем файл для чтения.
			in.open(filename.c_str(), openMode);

			// Если во время открытия файла произошла ошибка.
			if (in.fail())
				return false;

			return true;
		}

		void FileStream::CloseStream(void)
		{
			in.close();
		}

		bool FileStream::IsOpenStream(void)
		{
			return in.is_open();
		}

		std::ifstream& FileStream::GetStream(void)
		{
			return in;
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