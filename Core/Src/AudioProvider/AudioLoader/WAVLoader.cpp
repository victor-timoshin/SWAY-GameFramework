#include "../../../../Core/Inc/AudioProvider/AudioLoader/WAVLoader.h"

#define ID_RIFF 0x46464952
#define ID_WAVE 0x45564157
#define ID_FORM 0x20746D66
#define ID_DATA 0x61746164

namespace Core
{
	namespace AudioProvider
	{
		namespace AudioLoader
		{
			/// <summary>Конструктор класса.</summary>
			WAVLoader::WAVLoader(void)
			{
			}

			/// <summary>Деструктор класса.</summary>
			WAVLoader::~WAVLoader(void)
			{
			}

			Sapi::AUDIO_DESCRIPTION_PTR WAVLoader::LoadFromStream(std::ifstream& source)
			{
				WAV_FILE_HEADER fileHeader;

				source.read((char*)&fileHeader, sizeof(WAV_FILE_HEADER));
				if (fileHeader.chunkID != ID_RIFF OR fileHeader.format != ID_WAVE OR 
					fileHeader.soundChunkID != ID_FORM OR fileHeader.dataChunkID != ID_DATA)
				{
					source.close();
					return nullptr;
				}

				if ((fileHeader.numChannels != 1 AND fileHeader.numChannels != 2) OR
					(fileHeader.bitsPerSample != 8 AND fileHeader.bitsPerSample != 16))
				{
					source.close();
					return nullptr;
				}

				UByte* byteData = (UByte*)malloc(fileHeader.dataChunkSize);
				source.read((char*)byteData, fileHeader.dataChunkSize);

				Sapi::AUDIO_DESCRIPTION_PTR textureDesc = nullptr;
				textureDesc = (Sapi::AUDIO_DESCRIPTION_PTR)malloc(sizeof(Sapi::AUDIO_DESCRIPTION));
				textureDesc->data = byteData;
				textureDesc->format = (fileHeader.numChannels == 1
					? (fileHeader.bitsPerSample == 8 ? Sapi::BUFFER_FORMAT::Mono8 : Sapi::BUFFER_FORMAT::Mono16)
					: (fileHeader.bitsPerSample == 8 ? Sapi::BUFFER_FORMAT::Stereo8 : Sapi::BUFFER_FORMAT::Stereo16));
				textureDesc->size = fileHeader.dataChunkSize;
				textureDesc->frequency = fileHeader.sampleRate;

				source.close();

				return textureDesc;
			}
		}
	}
}