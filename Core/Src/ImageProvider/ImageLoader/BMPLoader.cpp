#include "../../../../Core/Inc/ImageProvider/ImageLoader/BMPLoader.h"

#define BITMAP_ID 0x4D42

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			/// <summary>Конструктор класса.</summary>
			BMPLoader::BMPLoader(void)
			{
			}

			/// <summary>Деструктор класса.</summary>
			BMPLoader::~BMPLoader(void)
			{
			}

			Gapi::TEXTURE_DESCRIPTION_PTR BMPLoader::LoadFromStream(std::ifstream& source)
			{
				BMP_FILE_HEADER fileHeader;
				source.read((char*)&fileHeader, sizeof(BMP_FILE_HEADER));

				if (fileHeader.type != BITMAP_ID OR fileHeader.offset != 54)
				{
					source.close();
					return nullptr;
				}

				BMP_INFO_HEADER infoHeader;
				source.read((char*)&infoHeader, sizeof(BMP_INFO_HEADER));

				if (infoHeader.size != 40 OR infoHeader.bitCount != 24 OR infoHeader.compression != 0)
				{
					source.close();
					return nullptr;
				}

				BMP_COLOR color;
				source.read((char*)&color, sizeof(BMP_COLOR));

				// Выделяем памяти под данные растрового изображения.
				UByte* tempData = (UByte*)malloc(infoHeader.imageSize);
				if (NOT tempData)
				{
					free(tempData);
					source.close();
					return nullptr;
				}

				// Читаем данные растрового изображения.
				source.read((char*)tempData, infoHeader.imageSize);

				//// Меняем местами красный и синий компоненты.
				//for (UInt i = 0; i < infoHeader.imageSize; i += 3)
				//{
				//	char tempColor = tempData[i];
				//	tempData[i] = tempData[i + 2];
				//	tempData[i + 2] = tempColor;
				//}

				Gapi::TEXTURE_DESCRIPTION_PTR textureDesc = (Gapi::TEXTURE_DESCRIPTION_PTR)malloc(sizeof(Gapi::TEXTURE_DESCRIPTION));
				textureDesc->pixels = tempData;
				textureDesc->width = infoHeader.width;
				textureDesc->height = infoHeader.height;
				textureDesc->pitch = 0;
				textureDesc->bpp = 0;
				textureDesc->format = Gapi::TEXTURE_FORMAT::EFT_BGR;
				textureDesc->internalFormat = Gapi::TEXTURE_FORMAT::EFT_RGB8;

				source.close();

				return textureDesc;
			}
		}
	}
}