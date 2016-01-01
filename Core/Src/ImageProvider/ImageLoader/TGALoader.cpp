#include "../../../../Core/Inc/ImageProvider/ImageLoader/TGALoader.h"

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			/// <summary>Конструктор класса.</summary>
			TGALoader::TGALoader(void)
			{
			}

			/// <summary>Деструктор класса.</summary>
			TGALoader::~TGALoader(void)
			{
			}

			Gapi::TEXTURE_DESCRIPTION_PTR TGALoader::LoadFromStream(std::ifstream& source)
			{
				const std::istream::off_type TGA_IMAGEIDLENGTH_OFFSET = 0;
				const std::istream::off_type TGA_COLORMAPTYPE_OFFSET = 1;
				const std::istream::off_type TGA_IMAGETYPE_OFFSET = 2;
				const std::istream::off_type TGA_COLORMAPLENGTH_OFFSET = 5;
				const std::istream::off_type TGA_COLORMAPENTRYSIZE_OFFSET = 7;
				const std::istream::off_type TGA_IMAGEWIDTH_OFFSET = 12;
				const std::istream::off_type TGA_IMAGEHEIGHT_OFFSET = 14;
				const std::istream::off_type TGA_IMAGEBITDEPTH_OFFSET = 16;
				const std::istream::off_type TGA_IMAGEID_OFFSET = 18;

				//PTGAHEADER header;
				//uint8_t* buffer;
				//uint32_t size;
				//UInt format, internalFormat;

				UByte idLength;
				source.read(reinterpret_cast<char*>(&idLength), 1);

				UByte colorMapType;
				source.read(reinterpret_cast<char*>(&colorMapType), 1);

				UByte type;
				source.read(reinterpret_cast<char*>(&type), 1);

				UInt16 colorMapLength;
				UInt16 colorMapEntrySize;

				source.seekg(TGA_COLORMAPLENGTH_OFFSET, std::ios::beg);
				source.read(reinterpret_cast<char*>(&colorMapLength), 2);
				source.read(reinterpret_cast<char*>(&colorMapEntrySize), 2);

				UInt16 imageWidth;
				UInt16 imageHeight;
				UByte imageBitDepth;

				source.seekg(TGA_IMAGEWIDTH_OFFSET, std::ios::beg);
				source.read(reinterpret_cast<char*>(&imageWidth), 2);
				source.read(reinterpret_cast<char*>(&imageHeight), 2);
				source.read(reinterpret_cast<char*>(&imageBitDepth), 1);

				source.seekg(TGA_IMAGEID_OFFSET + idLength + (colorMapLength * (colorMapEntrySize >> 3)), std::ios::beg);

				// Вычисляем необходимое количество памяти.
				UInt32 imageSize = imageWidth * imageHeight * (imageBitDepth >> 3);

				// Выделяем память под текстуру.
				UByte* textureData = new UByte[imageSize];

				source.read(reinterpret_cast<char*>(textureData), imageSize);


				//source.seekg(0, std::ios::beg);
				//source.read(reinterpret_cast<char*>(&header), sizeof(LTGAHEADER));

				//std::cerr
				//	<< "TGA: " << (int)header->idLength
				//	<< ", " << (int)header->dataType
				//	<< ", " << (int)header->bitPerPel
				//	<< ", " << (int)header->colorMap
				//	<< ", " << header->width
				//	<< ", " << header->height
				//	<< ", " << header->description
				//	<< std::endl;

				//if (header->dataType == 2) {
				//LoadUncompressedTexture
				//}
				//else {
				//LoadCompressedTexture
				//}

				// Если размер файла заведомо меньше заголовка TGA.
				//if (size <= sizeof(LTGAHEADER))
				//{
				//	delete[] buffer;
				//	return;
				//}

				// Проверяем формат TGA-файла - несжатое RGB или RGBA изображение.
				//if (header->dataType != 2 || (header->bitPerPel != 24 && header->bitPerPel != 32))
				//{
				//	delete[] buffer;
				//	return;
				//}

				//source.seekg(sizeof(header) + header->idLength);

				//int pos = source.tellg();
				//source.seekg(0, std::ios::end);
				//size = (int)source.tellg() - pos;
				//buffer = new uint8_t[size];

				//source.read((char*)buffer, size);

				Gapi::TEXTURE_DESCRIPTION_PTR textureDesc;
				textureDesc = (Gapi::TEXTURE_DESCRIPTION_PTR)malloc(sizeof(Gapi::TEXTURE_DESCRIPTION));
				textureDesc->pixels = textureData;
				textureDesc->width = (int)imageWidth;
				textureDesc->height = (int)imageHeight;
				textureDesc->pitch = 0;
				textureDesc->bpp = 0;
				// Получаем формат текстуры.
				textureDesc->format = (imageBitDepth == 24 ? Gapi::TEXTURE_FORMAT::EFT_BGR : Gapi::TEXTURE_FORMAT::EFT_BGRA);
				textureDesc->internalFormat = (textureDesc->format == Gapi::TEXTURE_FORMAT::EFT_BGR ? Gapi::TEXTURE_FORMAT::EFT_RGB8 : Gapi::TEXTURE_FORMAT::EFT_RGBA8);

				// Освобождаем память.  
				//if (textureData)
				//	delete[] textureData;

				return textureDesc;
			}

			/// <summary>Загружает изображение из файла.</summary>
			/// <param name="path">Путь к файлу.</param>
			/// <returns>Структура описания изображения.</returns>
			Gapi::TEXTURE_DESCRIPTION_PTR TGALoader::LoadFromFile(const std::string& path)
			{
				Core::Utils::FileStream stream;
				if (!stream.OpenStream(path, Core::Utils::FILE_TYPE::Binary))
					return nullptr;

				return LoadFromStream(stream.GetStream());
			}
		}
	}
}