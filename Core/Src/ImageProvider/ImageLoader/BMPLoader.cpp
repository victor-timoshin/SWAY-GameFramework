#include "../../../../Core/Inc/ImageProvider/ImageLoader/BMPLoader.h"

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
				LBITMAP_FILE_HEADER fileHeader;
				LBITMAP_INFO_HEADER infoHeader;
				LBITMAP_COLOR col;

				source.read((char*)&fileHeader, sizeof(LBITMAP_FILE_HEADER));

				int size = (fileHeader.size - fileHeader.offset);
				char* image = new char[size];

				//if file type = "BM"
				//read rest of file
				if (fileHeader.type == 19778)
				{
					source.read((char*)&infoHeader, sizeof(LBITMAP_INFO_HEADER));
					source.read((char*)&col, sizeof(LBITMAP_COLOR));
					source.read(image, size);
					//source.close();
				}
				else
					std::cout << "ERROR: FILE NOT BITMAP" << std::endl;

				Gapi::TEXTURE_DESCRIPTION_PTR textureDesc = (Gapi::TEXTURE_DESCRIPTION_PTR)malloc(sizeof(Gapi::TEXTURE_DESCRIPTION));
				textureDesc->pixels = image;
				textureDesc->width = (int)256;
				textureDesc->height = (int)256;
				textureDesc->pitch = 0;
				textureDesc->bpp = 0;
				textureDesc->format = Gapi::TEXTURE_FORMAT::EFT_BGR;
				textureDesc->internalFormat = Gapi::TEXTURE_FORMAT::EFT_RGB8;

				return textureDesc;
			}

			/// <summary>Загружает данные.</summary>
			Gapi::TEXTURE_DESCRIPTION_PTR BMPLoader::LoadFromFile(const std::string& path)
			{
				Core::Utils::FileStream stream;
				if (!stream.OpenStream(path, Core::Utils::FILE_TYPE::Binary))
					return nullptr;

				return LoadFromStream(stream.GetStream());
			}
		}
	}
}