#ifndef IMAGELOADERBASE_H
#define IMAGELOADERBASE_H

#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../SDK/Core/Utils/LoggerBase.h"
#include "../../../../SDK/Platform.h"

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			class IImageLoaderBase
			{
			public:
				/// <summary>Конструктор класса.</summary>
				IImageLoaderBase(void) {}

				/// <summary>Деструктор класса.</summary>
				virtual ~IImageLoaderBase(void) {}

				virtual Gapi::TEXTURE_DESCRIPTION_PTR LoadFromStream(std::ifstream& source) = 0;
			};
		}
	}
}

#endif // IMAGELOADERBASE_H