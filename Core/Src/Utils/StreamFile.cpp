#include "../../../Core/Inc/Utils/StreamFile.h"

namespace Core
{
	namespace Utils
	{
		/** Constructor. */
		StreamFile::StreamFile()
			: file(0) {}

		/** Destructor. */
		StreamFile::~StreamFile() {}

		void StreamFile::Open(const char* fileName, STREAM_MODE mode, bool binary)
		{
			switch (mode)
			{
			case STREAM_MODE::Read:
				fopen_s(&file, fileName, binary ? "rb" : "rt");
				break;

			case STREAM_MODE::Write:
				fopen_s(&file, fileName, binary ? "wb" : "wt");
				break;
			}
		}

		void StreamFile::Close()
		{
			if (file != 0)
				fclose(file);

			file = 0;
		}

		void StreamFile::Seek() {}

		void StreamFile::Print(const char* str)
		{
			if (file != 0 && str != 0)
				fprintf(file, str);
		}

		bool StreamFile::IsOpen() const
		{
			return file != 0;
		}

		FILE* StreamFile::GetFileHandle() const
		{
			return file;
		}
	}
}