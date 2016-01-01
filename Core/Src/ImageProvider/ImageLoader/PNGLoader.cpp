#include "../../../../Core/Inc/ImageProvider/ImageLoader/PNGLoader.h"
#include "../../../../SDK/Core/Utils/File.h"

#define PNG_SIGNATURE_SIZE 8 // Длина сигнатуры.

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			/// <summary></summary>
			void PNGLoader::Error(png_structp png, png_const_charp message)
			{
				//TODO
			}

			/// <summary></summary>
			void PNGLoader::Warning(png_structp png, png_const_charp message)
			{
				//TODO
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

			/// <summary>Загружает данные.</summary>
			Gapi::TEXTURE_DESCRIPTION_PTR PNGLoader::LoadFromStream(std::ifstream& source)
			{
				png_byte signature[PNG_SIGNATURE_SIZE] = { 0 }; // Массив под сигнатуру.
				int isSignatureValid = 0; // Результат проверки сигнатуры.

				// Считываем сигнатуру (первые PNG_SIGNATURE_SIZE байт).
				source.read((char*)signature, PNG_SIGNATURE_SIZE);

				// Проверяем на соответствие считанной нами сигнатуры с сигнатурой PNG-формата.
				isSignatureValid = png_sig_cmp(signature, 0, PNG_SIGNATURE_SIZE);
				if (isSignatureValid != 0)
				{
					source.close();
					return nullptr;
				}

				png_structp png;
				// Выделяем память и инициализируем структуру для работы с файлом.
				png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, PNGLoader::Error, PNGLoader::Warning);
				if (NOT png)
				{
					source.close();
					return nullptr;
				}

				png_infop info, endInfo;

				// Выделяем память и инициализируем структуру с информацией о файле.
				info = png_create_info_struct(png);
				if (NOT info)
				{
					png_destroy_read_struct(&png, (png_infopp)nullptr, (png_infopp)nullptr);
					source.close();
					return nullptr;
				}

				// Выделяем память и инициализируем структуру с информацией о файле.
				endInfo = png_create_info_struct(png);
				if (NOT endInfo)
				{
					png_destroy_read_struct(&png, &info, (png_infopp)nullptr);
					source.close();
					return nullptr;
				}

				// Устанавливаем механизм обработки ошибок.
				if (setjmp(png_jmpbuf(png)))
				{
					png_destroy_read_struct(&png, &info, &endInfo);
					source.close();
					return nullptr;
				}

				png_set_read_fn(png, (png_voidp)&source, PNGLoader::ReadData); // Устанавливаем собственную функцию чтения данных. 
				png_set_sig_bytes(png, PNG_SIGNATURE_SIZE); // Сообщаем Libpng, что мы уже прочитали PNG_SIGNATURE_SIZE байт, когда проверяли сигнатуру.
				png_read_info(png, info); // Читаем информацию о данных изображения.

				UInt width = png_get_image_width(png, info); // Ширина изображения в пикселях.
				UInt height = png_get_image_height(png, info); // Высота изображения в пикселях.

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

				png_get_IHDR(png, info, &width, &height, &bitDepth, &colorType, &interlaceMethod, &compressionMethod, &filterMethod); // Получаем информацию о png.
				png_read_update_info(png, info); // Обновляем информацию структуры png.

				// Получаем кол-во байтов необходимых для вмещения преобразованного ряда.
				int rowBytes = png_get_rowbytes(png, info);

				// Выделяем память под изображения.
				png_byte* imageData = new png_byte[rowBytes * height];
				if (NOT imageData)
				{
					png_destroy_read_struct(&png, &info, &endInfo);
					source.close();
					return nullptr;
				}

				// Выделяем память под указатели на каждую строку.
				png_bytep* rowPointers = new png_bytep[height];
				if (NOT rowPointers)
				{
					png_destroy_read_struct(&png, &info, &endInfo);
					SAFE_DELETE_ARRAY(imageData);
					source.close();
					return nullptr;
				}

				for (UInt i = 0; i < height; ++i)
					rowPointers[height - 1 - i] = imageData + i * rowBytes;

				png_read_image(png, rowPointers); // Читаем изображение.
				png_read_end(png, endInfo);

				Gapi::TEXTURE_DESCRIPTION_PTR textureDesc = nullptr;
				textureDesc = (Gapi::TEXTURE_DESCRIPTION_PTR)malloc(sizeof(Gapi::TEXTURE_DESCRIPTION));
				textureDesc->pixels = imageData;
				textureDesc->width = width;
				textureDesc->height = height;
				textureDesc->internalFormat = Gapi::TEXTURE_FORMAT::ETF_RGBA;
				textureDesc->format = Gapi::TEXTURE_FORMAT::EFT_BGRA;

				png_destroy_read_struct(&png, &info, &endInfo);  // Освобождаем память выделенную для библиотеки Libpng.
				SAFE_DELETE_ARRAY(rowPointers); // Освобождаем память от указателей на строки.
				source.close();

				return textureDesc;
			}

			/// <summary>Загружает данные.</summary>
			Gapi::TEXTURE_DESCRIPTION_PTR PNGLoader::LoadFromFile(const std::string& path)
			{
				if (NOT Core::Utils::FileExists(path))
					return nullptr;

				Core::Utils::FileStream stream;
				if (NOT stream.OpenStream(path, Core::Utils::FILE_TYPE::Binary))
					return nullptr;

				return LoadFromStream(stream.GetStream());
			}
		}
	}
}