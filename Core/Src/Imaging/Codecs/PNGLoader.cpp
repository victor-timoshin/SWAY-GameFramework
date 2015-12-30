#include "../../../../Core/Inc/Imaging/Codecs/PNGLoader.h"

namespace Imaging
{
	/// <summary></summary>
	void PNGLoader::Error(png_structp png, png_const_charp message)
	{
		//message
	}

	/// <summary></summary>
	void PNGLoader::Warning(png_structp png, png_const_charp message)
	{
		//message
	}

	/// <summary>Чтения данных из потока.</summary>
	void PNGLoader::ReadData(png_structp png, png_bytep data, png_size_t length)
	{
		reinterpret_cast<std::istream*>(png_get_io_ptr(png))->read((char*)data, length);
	}

	/// <summary>Конструктор класса.</summary>
	PNGLoader::PNGLoader(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	PNGLoader::~PNGLoader(void)
	{
	}

	Gapi::PTEXTURE_DESCRIPTION PNGLoader::loadTexture(std::istream& source)
	{
		// header for testing if it is a png
		static const int PNGSIGSIZE = 8;

		png_byte pngsig[PNGSIGSIZE] = {};
		source.read((char*)pngsig, PNGSIGSIZE);

		if (png_sig_cmp(pngsig, 0, PNGSIGSIZE))
		{
			return NULL;
		}

		// test if png
		int is_png = !png_sig_cmp(pngsig, 0, PNGSIGSIZE);
		if (!is_png) {
			return 0;
		}

		// create png struct
		png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		if (!png_ptr) {
			return (0);
		}

		// create png info struct
		png_infop info_ptr = png_create_info_struct(png_ptr);
		if (!info_ptr) {
			png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
			return (0);
		}

		// create png info struct
		png_infop end_info = png_create_info_struct(png_ptr);
		if (!end_info) {
			png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
			return (0);
		}

		// png error stuff, not sure libpng man suggests this.
		if (setjmp(png_jmpbuf(png_ptr))) {
			png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
			return (0);
		}

		// init png reading
		png_set_read_fn(png_ptr, (png_voidp)&source, PNGLoader::ReadData);

		// let libpng know you already read the first 8 bytes
		png_set_sig_bytes(png_ptr, 8);

		// read all the info up to the image data
		png_read_info(png_ptr, info_ptr);

		// variables to pass to get info
		int bit_depth, color_type;
		png_uint_32 twidth, theight;

		// get info about png
		png_get_IHDR(png_ptr, info_ptr, &twidth, &theight, &bit_depth, &color_type, NULL, NULL, NULL);

		// update width and height based on png info
		int width = twidth;
		int height = theight;

		// Update the png info struct.
		png_read_update_info(png_ptr, info_ptr);

		// Row size in bytes.
		int rowbytes = png_get_rowbytes(png_ptr, info_ptr);

		// Allocate the image_data as a big block, to be given to opengl
		png_byte* image_data = new png_byte[rowbytes * height];
		if (!image_data) {
			// clean up memory and close stuff
			png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
			return 0;
		}

		// row_pointers is for pointing to image_data for reading the png with libpng
		png_bytep *row_pointers = new png_bytep[height];
		if (!row_pointers) {
			// clean up memory and close stuff
			png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
			delete[] image_data;
			return 0;
		}
		// set the individual row_pointers to point at the correct offsets of image_data
		for (int i = 0; i < height; ++i)
			row_pointers[height - 1 - i] = image_data + i * rowbytes;

		// read the png into image_data through row_pointers
		png_read_image(png_ptr, row_pointers);

		Gapi::PTEXTURE_DESCRIPTION image = (Gapi::PTEXTURE_DESCRIPTION)malloc(sizeof(Gapi::LTEXTURE_DESCRIPTION));
		image->pixels = image_data;
		image->width = (int)width;
		image->height = (int)height;

		png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
		delete[] image_data;
		delete[] row_pointers;

		return image;
	}

	/// <summary>Загружает данные.</summary>
	Gapi::PTEXTURE_DESCRIPTION PNGLoader::LoadFromStream(std::istream& source)
	{
		static const int SIGNATURE_SIZE = 8; // Длина сигнатуры.
		png_byte signature[SIGNATURE_SIZE] = { 0 }; // Массив под сигнатуру.

		// Считываем сигнатуру (первые SIGNATURE_SIZE байт).
		source.read((char*)signature, SIGNATURE_SIZE);

		int isSignatureValid = 0; // Результат проверки сигнатуры.
		// Проверяем на соответствие считанной нами сигнатуры с сигнатурой PNG-формата.
		isSignatureValid = png_sig_cmp(signature, 0, SIGNATURE_SIZE);
		if (isSignatureValid != 0)
		{
			return nullptr;
		}

		png_structp png;
		// Выделяем память и инициализируем структуру для работы с файлом.
		png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, PNGLoader::Error, PNGLoader::Warning);
		if (!png)
		{
			return nullptr;
		}

		png_infop info, endInfo;

		// Выделяем память и инициализируем структуру с информацией о файле.
		info = png_create_info_struct(png);
		if (!info)
		{
			png_destroy_read_struct(&png, (png_infopp)nullptr, (png_infopp)nullptr);
			return nullptr;
		}

		// Выделяем память и инициализируем структуру с информацией о файле.
		endInfo = png_create_info_struct(png);
		if (!endInfo)
		{
			png_destroy_read_struct(&png, &info, (png_infopp)nullptr);
			return nullptr;
		}

		// Устанавливаем механизм обработки ошибок.
		if (setjmp(png_jmpbuf(png)))
		{
			png_destroy_read_struct(&png, &info, &endInfo);
			return nullptr;
		}

		// Устанавливаем собственную функцию чтения данных. 
		png_set_read_fn(png, (png_voidp)&source, PNGLoader::ReadData);
		// Сообщаем Libpng, что мы уже прочитали SIGNATURE_SIZE байт, когда проверяли сигнатуру.
		png_set_sig_bytes(png, SIGNATURE_SIZE);
		// Читаем информацию о данных изображения.
		png_read_info(png, info);

		png_uint_32 width = png_get_image_width(png, info); // Ширина изображения в пикселях.
		png_uint_32 height = png_get_image_height(png, info); // Высота изображения в пикселях.

		int bitDepth = png_get_bit_depth(png, info); // Глубина цвета.
		int colorType = png_get_color_type(png, info);
		int interlaceMethod = png_get_interlace_type(png, info);
		int compressionMethod = png_get_compression_type(png, info);
		int filterMethod = png_get_filter_type(png, info);
		int channels = png_get_channels(png, info);

		if (colorType == PNG_COLOR_TYPE_PALETTE)
			png_set_palette_to_rgb(png);
		else if (colorType == PNG_COLOR_TYPE_GRAY || colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
			png_set_gray_to_rgb(png);

		// Получаем информацию о png.
		png_get_IHDR(png, info, &width, &height, &bitDepth, &colorType, &interlaceMethod, &compressionMethod, &filterMethod);
		// Обновляем информацию структуры png.
		png_read_update_info(png, info);

		// Получаем кол-во байтов необходимых для вмещения преобразованного ряда.
		int rowBytes = png_get_rowbytes(png, info);

		// Выделяем память под изображения.
		png_byte* imageData = new png_byte[rowBytes * height];
		if (!imageData)
		{
			png_destroy_read_struct(&png, &info, &endInfo);
			return 0;
		}

		// Выделяем память под указатели на каждую строку.
		png_bytep* rowPointers = new png_bytep[height];
		if (!rowPointers)
		{
			png_destroy_read_struct(&png, &info, &endInfo);
			delete[] imageData;
			return 0;
		}

		for (UInt i = 0; i < height; ++i)
			rowPointers[height - 1 - i] = imageData + i * rowBytes;

		// Читаем изображение.
		png_read_image(png, rowPointers);

		// Освобождаем память от указателей на строки.
		free(rowPointers);

		png_destroy_info_struct(png, &info);
		// Освобождаем память выделенную для библиотеки Libpng.
		png_destroy_read_struct(&png, 0, 0);

		Gapi::PTEXTURE_DESCRIPTION dataInfo = (Gapi::PTEXTURE_DESCRIPTION)malloc(sizeof(Gapi::LTEXTURE_DESCRIPTION));
		dataInfo->pixels = imageData;
		dataInfo->width = (int)width;
		dataInfo->height = (int)height;
		dataInfo->internalFormat = Gapi::TEXTURE_FORMAT::ETF_RGBA;
		dataInfo->format = Gapi::TEXTURE_FORMAT::EFT_BGRA;

		return dataInfo;
	}

	/// <summary>Загружает данные.</summary>
	Gapi::PTEXTURE_DESCRIPTION PNGLoader::LoadFromFile(const std::string& path)
	{
		Core::Utils::FileStream stream;
		if (!stream.OpenStream(path, Core::Utils::STREAM_MODE::Binary))
			return nullptr;

		return LoadFromStream(stream.GetStream());
	}
}