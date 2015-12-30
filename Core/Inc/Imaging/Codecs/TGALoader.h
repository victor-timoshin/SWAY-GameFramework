#ifndef TGALOADER_H
#define TGALOADER_H

#include "../../../../SDK/Gapi/TextureBase.h"
#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../SDK/Gapi/TextureFormat.h"
#include "../../../../Core/Inc/Utils/FileStream.h"
#include "../../../../SDK/Core/Imaging/LoaderBase.h"

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

namespace Imaging
{
	class TGALoader : public Imaging::ILoaderBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		TGALoader(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~TGALoader(void);

		virtual Gapi::PTEXTURE_DESCRIPTION LoadFromStream(std::istream& source);

		/// <summary>Загружает изображение из файла.</summary>
		/// <param name="path">Путь к файлу.</param>
		/// <returns>Структура описания изображения.</returns>
		Gapi::PTEXTURE_DESCRIPTION LoadFromFile(const std::string& path);
	};
}

#endif // TGALOADER_H