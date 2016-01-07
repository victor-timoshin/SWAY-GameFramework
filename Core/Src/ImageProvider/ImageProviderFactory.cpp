#include "../../../Core/Inc/ImageProvider/ImageProviderFactory.h"
#include "../../../Core/Inc/Utils/FileStream.h"
#include "../../../SDK/Core/Utils/File.h"

#include "../../../Core/Inc/ImageProvider/ImageLoader/TGALoader.h"
#include "../../../Core/Inc/ImageProvider/ImageLoader/BMPLoader.h"
#include "../../../Core/Inc/ImageProvider/ImageLoader/PNGLoader.h"

namespace Core
{
	namespace ImageProvider
	{
		/// <summary>Конструктор класса.</summary>
		ImageProviderFactory::ImageProviderFactory(void)
		{
			Register("tga", new ImageLoader::TGALoader);
			Register("bmp", new ImageLoader::BMPLoader);
			Register("png", new ImageLoader::PNGLoader);
		}

		/// <summary>Деструктор класса.</summary>
		ImageProviderFactory::~ImageProviderFactory(void)
		{
			_imageLoaders.clear();
		}

		void ImageProviderFactory::Register(const std::string name, ImageLoader::IImageLoaderBase* loader)
		{
			_imageLoaders.insert(std::make_pair(name, loader));
		}

		void ImageProviderFactory::Unregister(const std::string& name)
		{
			_imageLoaders.erase(name);
		}

		Gapi::TEXTURE_DESCRIPTION_PTR ImageProviderFactory::Give(const std::string& filename)
		{
			TImageLoaderMap::iterator i = _imageLoaders.find(Core::Utils::GetFileExtension(filename));
			if (i != _imageLoaders.end())
			{
				if (NOT Core::Utils::FileExists(filename))
					return nullptr;

				Core::Utils::FileStream stream;
				if (NOT stream.OpenStream(filename, Core::Utils::FILE_TYPE::Binary))
					return nullptr;

				return i->second->LoadFromStream(stream.GetStream());
			}

			return nullptr;
		}
	}
}