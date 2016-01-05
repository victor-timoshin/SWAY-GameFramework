#ifndef WAVLOADER_H
#define WAVLOADER_H

#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Sapi/AudioDescription.h"

#include "WAVFileHeader.h"

namespace Core
{
	namespace AudioProvider
	{
		namespace AudioLoader
		{
			class WAVLoader
			{
			public:
				/// <summary>Конструктор класса.</summary>
				WAVLoader(void);

				/// <summary>Деструктор класса.</summary>
				virtual ~WAVLoader(void);

				virtual Sapi::AUDIO_DESCRIPTION_PTR LoadFromStream(std::ifstream& source);
			};
		}
	}
}

#endif // WAVLOADER_H