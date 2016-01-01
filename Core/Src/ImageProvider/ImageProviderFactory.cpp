#include "../../../Core/Inc/ImageProvider/ImageProviderFactory.h"
#include "../../../Core/Inc/Utils/FileStream.h"
#include "../../../SDK/Core/Utils/File.h"

namespace Core
{
	namespace ImageProvider
	{
		/// <summary>Конструктор класса.</summary>
		ImageProviderFactory::ImageProviderFactory(void)
		{
			_supportedExtensions.push_back("tga");
			_supportedExtensions.push_back("bmp");
			_supportedExtensions.push_back("png");
		}

		/// <summary>Деструктор класса.</summary>
		ImageProviderFactory::~ImageProviderFactory(void)
		{
		}

		void ImageProviderFactory::Register(const std::string name, ImageLoader::IImageLoaderBase* loader)
		{
			_imageLoaders.insert(std::make_pair(name, loader));
		}

		void ImageProviderFactory::Unregister(const std::string& name)
		{
			_imageLoaders.erase(name);
		}

		Gapi::TEXTURE_DESCRIPTION_PTR ImageProviderFactory::Give(const std::string& name, const std::string& filename)
		{
			TImageLoaderMap::iterator i = _imageLoaders.find(name);
			if (i != _imageLoaders.end())
			{
				if (NOT Core::Utils::FileExists(filename))
					return nullptr;

				std::string fileExtension = Core::Utils::GetFileExtension(filename);
				for (const auto& ext : _supportedExtensions)
				{
					if (ext == fileExtension)
						continue;
				}

				Core::Utils::FileStream stream;
				if (NOT stream.OpenStream(filename, Core::Utils::FILE_TYPE::Binary))
					return nullptr;

				return i->second->LoadFromStream(stream.GetStream());
			}
		}
	}
}