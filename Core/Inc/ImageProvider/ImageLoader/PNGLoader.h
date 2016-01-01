#ifndef PNGLOADER_H
#define PNGLOADER_H

#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../SDK/Core/ImageProvider/ImageLoader/ImageLoaderBase.h"
#include "../../../../SDK/Platform.h"

#include "../../../../Core/Inc/Utils/FileStream.h"

#include "../../../../External/Libpng/Inc/png.h"

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			class PNGLoader : public IImageLoaderBase
			{
			public:
				/// <summary>Конструктор класса.</summary>
				PNGLoader(void);

				/// <summary>Деструктор класса.</summary>
				virtual ~PNGLoader(void);

				/// <summary>Загружает данные.</summary>
				virtual Gapi::TEXTURE_DESCRIPTION_PTR LoadFromStream(std::ifstream& source);

				/// <summary>Загружает данные.</summary>
				Gapi::TEXTURE_DESCRIPTION_PTR LoadFromFile(const std::string& path);

			protected:
				static void Error(png_structp png, png_const_charp message);

				static void Warning(png_structp png, png_const_charp message);

				static void ReadData(png_structp png, png_bytep data, png_size_t length);

			private:
			};
		}
	}
}

#endif // PNGLOADER_H