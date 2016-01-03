#ifndef TGALOADER_H
#define TGALOADER_H

#include "../../../../SDK/Gapi/TextureBase.h"
#include "../../../../SDK/Platform.h"
#include "../../../../SDK/Gapi/TextureDescription.h"
#include "../../../../SDK/Gapi/TextureFormat.h"
#include "../../../../Core/Inc/Utils/FileStream.h"
#include "../../../../SDK/Core/ImageProvider/ImageLoader/ImageLoaderBase.h"

#include "TGAFileHeader.h"

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
			};
		}
	}
}

#endif // TGALOADER_H