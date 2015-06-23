#ifndef STREAM_FILE_H
#define STREAM_FILE_H

#include "../../../SDK/Core/Utils/StreamBase.h"

namespace Core
{
	namespace Utils
	{
		class StreamFile : public IStreamBase
		{
		public:
			/** Constructor. */
			StreamFile();

			/** Destructor. */
			virtual ~StreamFile();

			virtual void Open(const char* fileName, STREAM_MODE mode, bool binary);

			virtual void Close();

			virtual void Seek();

			virtual void Print(const char* str);

			virtual bool IsOpen() const;

			virtual FILE* GetFileHandle() const;

		private:
			FILE* file;
		};
	}
}

#endif // STREAM_FILE_H