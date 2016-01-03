#ifndef BMPLOADER_H
#define BMPLOADER_H

#include "../../../../SDK/Gapi/TextureBase.h"
#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../Core/Inc/Utils/FileStream.h"
#include "../../../../SDK/Core/ImageProvider/ImageLoader/ImageLoaderBase.h"

#include "BMPFileHeader.h"

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			class BMPLoader : public IImageLoaderBase
			{
			public:
				/// <summary>Конструктор класса.</summary>
				BMPLoader(void);

				/// <summary>Деструктор класса.</summary>
				virtual ~BMPLoader(void);

				virtual Gapi::TEXTURE_DESCRIPTION_PTR LoadFromStream(std::ifstream& source);
			};
		}
	}
}

#endif // BMPLOADER_H