#ifndef TGALOADER_H
#define TGALOADER_H

#include "../../../../SDK/Gapi/TextureBase.h"
#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../SDK/Gapi/TextureFormat.h"
#include "../../../../Core/Inc/Utils/FileStream.h"
#include "../../../../SDK/Core/ImageProvider/ImageLoader/ImageLoaderBase.h"

#pragma pack(1)
typedef struct TGAHeader
{
	unsigned __int8  idLength;
	unsigned __int8  colorMap;
	unsigned __int8  dataType;
	unsigned __int8  colorMapInfo[5];
	unsigned __int16 xOrigin;
	unsigned __int16 yOrigin;
	unsigned __int16 width;
	unsigned __int16 height;
	unsigned __int8  bitPerPel;
	unsigned __int8  description;
} LTGAHEADER, *PTGAHEADER;
#pragma pack()

namespace Core
{
	namespace ImageProvider
	{
		namespace ImageLoader
		{
			class TGALoader : public IImageLoaderBase
			{
			public:
				/// <summary>Конструктор класса.</summary>
				TGALoader(void);

				/// <summary>Деструктор класса.</summary>
				virtual ~TGALoader(void);

				virtual Gapi::TEXTURE_DESCRIPTION_PTR LoadFromStream(std::ifstream& source);

				/// <summary>Загружает изображение из файла.</summary>
				/// <param name="path">Путь к файлу.</param>
				/// <returns>Структура описания изображения.</returns>
				Gapi::TEXTURE_DESCRIPTION_PTR LoadFromFile(const std::string& path);
			};
		}
	}
}

#endif // TGALOADER_H