#ifndef IMAGEPROVIDERFACTORY_H
#define IMAGEPROVIDERFACTORY_H

#include "../../../SDK/Core/ImageProvider/ImageLoader/ImageLoaderBase.h"
#include "../../../SDK/Platform.h"

namespace Core
{
	namespace ImageProvider
	{
		class ImageProviderFactory
		{
		public:
			/// <summary>Конструктор класса.</summary>
			ImageProviderFactory(void);

			/// <summary>Деструктор класса.</summary>
			virtual ~ImageProviderFactory(void);

			void Register(const std::string name, ImageLoader::IImageLoaderBase* loader);

			void Unregister(const std::string& name);

			Gapi::TEXTURE_DESCRIPTION_PTR Give(const std::string& name, const std::string& filename);

		private:
			typedef std::map<std::string, ImageLoader::IImageLoaderBase*> TImageLoaderMap;
			TImageLoaderMap _imageLoaders;

			std::list<std::string> _supportedExtensions;
		};
	}
}

#endif // IMAGEPROVIDERFACTORY_H