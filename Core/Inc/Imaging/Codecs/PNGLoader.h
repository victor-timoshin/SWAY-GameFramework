#ifndef PNGLOADER_H
#define PNGLOADER_H

#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../SDK/Platform.h"
#include "../../../../External/Libpng/Inc/png.h"
#include "../../../../Core/Inc/Utils/FileStream.h"
#include "../../../../SDK/Core/Imaging/LoaderBase.h"

#define PNG_SIG_BYTES 8

namespace Imaging
{
	class PNGLoader : public Imaging::ILoaderBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		PNGLoader(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~PNGLoader(void);

		Gapi::PTEXTURE_DESCRIPTION loadTexture(std::istream& source);

		/// <summary>Загружает данные.</summary>
		virtual Gapi::PTEXTURE_DESCRIPTION LoadFromStream(std::istream& source);

		/// <summary>Загружает данные.</summary>
		Gapi::PTEXTURE_DESCRIPTION LoadFromFile(const std::string& path);

	protected:
		static void Error(png_structp png, png_const_charp message);

		static void Warning(png_structp png, png_const_charp message);

		static void ReadData(png_structp png, png_bytep data, png_size_t length);

	private:
	};
}

#endif // PNGLOADER_H