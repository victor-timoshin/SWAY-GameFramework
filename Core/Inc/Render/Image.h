#ifndef IMAGE_H
#define IMAGE_H

#include "../../../Math/Inc/Rect.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/TextureBase.h"
#include "../../../SDK/Gapi/TextureSamplerBase.h"
#include "../../../SDK/Platform.h"

#include "../ImageProvider/ImageProviderFactory.h"
#include "../Resource/Resource.h"

namespace Core
{
	namespace Render
	{
		typedef struct ImageData
		{
			UInt width;
			UInt height;
			UByte* byteData;
		} IMAGE_DATA, *IMAGE_DATA_PTR;

		class Image : public Core::Resource::ResourceBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			Image(void);

			/// <summary>Конструктор класса.</summary>
			Image(void* library, Gapi::IDeviceBase* device);

			Image(IMAGE_DATA_PTR data);

			/// <summary>Деструктор класса.</summary>
			virtual ~Image(void);

			virtual void Load(ImageProvider::ImageProviderFactory* imageProvider, const std::string& name);

			virtual void Unload(void);

			virtual void Bind(UInt textureUnit);

			virtual void Unbind(void);

			virtual Gapi::ITextureBase* GetTexture(void);

			virtual Gapi::ITextureSamplerBase* GetTextureSampler(void);

			virtual bool HasLoaded(void) const;

			UInt GetWidth(void) const;
			UInt GetHeight(void) const;
			UInt GetSize(void) const;
			UInt GetPitch(void) const;

			Math::Color* GetData(void);
			const Math::Color* GetData(void) const;

			void SetPixel(const Math::Color& color, UInt row, UInt col);
			const Math::Color& GetPixel(UInt row, UInt col) const;
			const Math::Color& GetPixel(UInt index) const;

			void CopyData(UByte* data, bool includeAlpha) const;

		private:
			Gapi::IDeviceBase* _renderDevice;
			Gapi::ITextureBase* _texture;
			Gapi::ITextureSamplerBase* _textureSampler;

			UInt _width;
			UInt _height;
			UInt _pitch;
			Math::Color* _data;

			bool _isLoaded;
		};
	}
}

#endif // IMAGE_H