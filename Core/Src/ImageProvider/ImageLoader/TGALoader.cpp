#include "../../../../Core/Inc/ImageProvider/ImageLoader/TGALoader.h"

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			const UByte UncompressedHeader[12] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			const UByte CompressedHeader[12] = { 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

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
				TGA_FILE_HEADER fileHeader;
				source.read((char*)&fileHeader, sizeof(TGA_FILE_HEADER));

				if (fileHeader.bitPerPixel == 24)
				{
					//format = GL_RGB;
					//internalFormat = GL_RGB;
				}
				else if (fileHeader.bitPerPixel == 32)
				{
					//format = GL_RGBA;
					//internalFormat = GL_RGBA;
				}
				else
				{
					source.close();
					return nullptr;
				}

				UInt bytePerPixel = fileHeader.bitPerPixel / 8;

				// Вычисляем необходимое количество памяти.
				UInt imageSize = fileHeader.imageWidth * fileHeader.imageHeight * bytePerPixel;

				// Выделяем памяти под данные изображения.
				UByte* tempData = (UByte*)malloc(imageSize);
				if (NOT tempData)
				{
					free(tempData);
					source.close();
					return nullptr;
				}

				source.read((char*)tempData, imageSize);

				for (UInt i = 0; i < imageSize; i += bytePerPixel)
				{
					//tempData[i] ^= tempData[i + 2] ^= tempData[i] ^= tempData[i + 2];

					char temp = tempData[i];
					tempData[i + 0] = tempData[i + 2];
					tempData[i + 2] = temp;
				}

				Gapi::TEXTURE_DESCRIPTION_PTR textureDesc = nullptr;
				textureDesc = (Gapi::TEXTURE_DESCRIPTION_PTR)malloc(sizeof(Gapi::TEXTURE_DESCRIPTION));
				textureDesc->pixels = tempData;
				textureDesc->width = (int)fileHeader.imageWidth;
				textureDesc->height = (int)fileHeader.imageHeight;
				textureDesc->pitch = 0;
				textureDesc->bpp = 0;
				textureDesc->format = (fileHeader.bitPerPixel == 24) ? Gapi::TEXTURE_FORMAT::EFT_BGR : Gapi::TEXTURE_FORMAT::EFT_BGRA;
				textureDesc->internalFormat = (textureDesc->format == Gapi::TEXTURE_FORMAT::EFT_BGR) ? Gapi::TEXTURE_FORMAT::EFT_RGB8 : Gapi::TEXTURE_FORMAT::EFT_RGBA8;

				source.close();

				return textureDesc;
			}
		}
	}
}