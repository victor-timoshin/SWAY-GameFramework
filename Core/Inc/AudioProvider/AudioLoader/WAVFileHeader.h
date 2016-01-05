#ifndef WAVFILEHEADER_H
#define WAVFILEHEADER_H

#include "../../../../SDK/Platform.h"

namespace Core
{
	namespace AudioProvider
	{
		namespace AudioLoader
		{
			PACK(typedef struct WAVFileHeader
			{
				// RIFF header
				UInt chunkID;
				UInt chunkSize;
				UInt format;

				// Sound data format
				UInt soundChunkID;
				UInt soundChunkSize;
				UInt16 audioFormat;
				UInt16 numChannels;
				UInt sampleRate;
				UInt byteRate;
				UInt16 blockAlignment;
				UInt16 bitsPerSample;

				// Data subchunk
				UInt dataChunkID;
				UInt dataChunkSize;
			} WAV_FILE_HEADER, *WAV_FILE_HEADER_PTR);
		}
	}
}

#endif // WAVFILEHEADER_H