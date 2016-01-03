#include "../../../Core/Inc/Render/Image.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		Image::Image(void)
			: _texture(nullptr)
			, _textureSampler(nullptr)
			, _isLoaded(false)
		{
		}

		/// <summary>Конструктор класса.</summary>
		Image::Image(void* library, Gapi::IDeviceBase* device)
			: _renderDevice(device)
			, _texture(nullptr)
			, _textureSampler(nullptr)
			, _isLoaded(false)
		{
			typedef Gapi::ITextureBase* ITextureCallback(void);
			_texture = reinterpret_cast<ITextureCallback*>(GetProcAddress((HMODULE)library, "RegisterTexture"))();

			typedef Gapi::ITextureSamplerBase* ITextureSamplerCallback(void);
			_textureSampler = reinterpret_cast<ITextureSamplerCallback*>(GetProcAddress((HMODULE)library, "RegisterTextureSampler"))();
		}

		/// <summary>Конструктор класса.</summary>
		Image::Image(IMAGE_DATA_PTR data)
			: _width(data->width)
			, _height(data->height)
			, _pitch(data->width)
			, _data(nullptr)
		{
			_data = (Math::Color*)_aligned_malloc(sizeof(Math::Color) * _height * _pitch, 16);

			//RGBA
			for (UInt i = 0; i < _width * _height; i++)
			{
				_data[i].SetR(data->byteData[i * 4 + 0] / 255.0f);
				_data[i].SetG(data->byteData[i * 4 + 1] / 255.0f);
				_data[i].SetB(data->byteData[i * 4 + 2] / 255.0f);
				_data[i].SetA(data->byteData[i * 4 + 3] / 255.0f);
			}

			//BGRA
			//for (UInt i = 0; i < _width * _height; i++)
			//{
			//	_data[i].SetB(data->byteData[i * 4 + 0] / 255.0f);
			//	_data[i].SetG(data->byteData[i * 4 + 1] / 255.0f);
			//	_data[i].SetR(data->byteData[i * 4 + 2] / 255.0f);
			//	_data[i].SetA(data->byteData[i * 4 + 3] / 255.0f);
			//}
		}

		/// <summary>Деструктор класса.</summary>
		Image::~Image(void)
		{
			SAFE_DELETE(_textureSampler);
			SAFE_DELETE(_texture);

			if (_data)
				_aligned_free(_data);
		}

		void Image::Load(ImageProvider::ImageProviderFactory* imageProvider, const std::string& name)
		{
			if (_isLoaded)
				return;

			Gapi::TEXTURE_DESCRIPTION_PTR textureDesc = imageProvider->Give(name);
			if (NOT textureDesc)
				return;

			_texture->Load(textureDesc);

			_textureSampler->SetAnisotropicLevel(_texture, 0); // Устанавливаем уровень анизотропной фильтрации.
			_textureSampler->SetWrapMode(_texture, Gapi::TEXTURE_WRAP::Repeat, Gapi::TEXTURE_WRAP::Repeat, Gapi::TEXTURE_WRAP::Repeat);
			_textureSampler->SetFilterMode(_texture, Gapi::TEXTURE_FILTER::Nearest, Gapi::TEXTURE_FILTER::Nearest);

			_isLoaded = true;
		}

		void Image::Unload(void)
		{
			if (NOT _isLoaded)
				return;

			SAFE_DELETE(_textureSampler);
			SAFE_DELETE(_texture);

			_isLoaded = false;
		}

		void Image::Bind(UInt textureUnit)
		{
			if (NOT _isLoaded)
				return;

			_texture->SetActive(textureUnit);
			_texture->Bind();
		}

		void Image::Unbind(void)
		{
			if (NOT _isLoaded)
				return;

			_texture->Unbind();
		}

		Gapi::ITextureBase* Image::GetTexture(void)
		{
			return _texture;
		}

		Gapi::ITextureSamplerBase* Image::GetTextureSampler(void)
		{
			return _textureSampler;
		}

		bool Image::HasLoaded(void) const
		{
			return _isLoaded;
		}

		UInt Image::GetWidth(void) const
		{
			return _width;
		}

		UInt Image::GetHeight(void) const
		{
			return _height;
		}

		UInt Image::GetSize(void) const
		{
			return _width * _height;
		}

		UInt Image::GetPitch(void) const
		{
			return _pitch;
		}

		Math::Color* Image::GetData(void)
		{
			return _data;
		}

		const Math::Color* Image::GetData(void) const
		{
			return _data;
		}

		void Image::SetPixel(const Math::Color& color, UInt row, UInt col)
		{
			_data[row * _pitch + col] = color;
		}

		const Math::Color& Image::GetPixel(UInt row, UInt col) const
		{
			return _data[row * _pitch + col];
		}

		const Math::Color& Image::GetPixel(UInt index) const
		{
			return _data[index];
		}

		void Image::CopyData(UByte* data, bool includeAlpha) const
		{
			//RGBA
			for (UInt row = 0, index = 0; row < _height; row++)
			{
				for (UInt col = 0; col < _width; col++)
				{
					data[index++] = (UByte)(_data[row * _pitch + col].GetR() * 255);
					data[index++] = (UByte)(_data[row * _pitch + col].GetG() * 255);
					data[index++] = (UByte)(_data[row * _pitch + col].GetB() * 255);

					if (includeAlpha)
						data[index++] = (UByte)(_data[row * _pitch + col].GetA() * 255);
				}
			}

			//BGRA
			//for (UInt row = 0, index = 0; row < _height; row++) {
			//	for (UInt col = 0; col < _width; col++) {
			//		data[index++] = (UByte)(_data[row * _pitch + col].GetB() * 255);
			//		data[index++] = (UByte)(_data[row * _pitch + col].GetG() * 255);
			//		data[index++] = (UByte)(_data[row * _pitch + col].GetR() * 255);

			//		if (includeAlpha)
			//			data[index++] = (UByte)(_data[row * _pitch + col].GetA() * 255);
			//	}
			//}
		}
	}
}