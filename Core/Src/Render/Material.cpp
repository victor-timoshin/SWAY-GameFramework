#include "../../../Core/Inc/Render/Material.h"
#include "../../../Core/Inc/ImageProvider/ImageLoader/PNGLoader.h"
#include "../../../Core/Inc/ImageProvider/ImageLoader/BMPLoader.h"
#include "../../../Core/Inc/ImageProvider/ImageLoader/TGALoader.h"

#include "../../../SDK//Core/Utils/File.h"

#define MAX_IMAGE_COUNT 2

namespace Core
{
	namespace Render
	{
		DEF_PROPERTY_STRING(Material, Name, _name)

		/// <summary>Конструктор класса.</summary>
		/// <param name="library">Хендл библиотеки.</param>
		/// <param name="device">Указатель на графический девайс.</param>
		Material::Material(void* library, Gapi::IDeviceBase* device)
			: _renderDevice(device)
			, _effect(nullptr)
			, _image(nullptr)
		{
			//_images.reserve(MAX_TEXTURE_COUNT);

			_supportedExtensionTextures.push_back("tga");
			_supportedExtensionTextures.push_back("bmp");
			_supportedExtensionTextures.push_back("png");

			_effect = new Effect(library, device);
			_image = new Image(library, device);
		}

		/// <summary>Деструктор класса.</summary>
		Material::~Material(void)
		{
			Destroy();
		}

		bool Material::Create(const char* vertexShader, const char* fragmentShader, const char* textureName)
		{
			_xmlDocument = new Xml::Document();

			AddTexture(textureName);
			AddShader(vertexShader, fragmentShader);

			return true;
		}

		void Material::Destroy(void)
		{
			SAFE_DELETE(_effect);
			SAFE_DELETE(_image);
		}

		void Material::Bind(void)
		{
			_effect->GetShader()->Bind();

			_image->GetTexture()->SetActive(0);
			_image->GetTexture()->Bind();
		}

		void Material::Unbind(void)
		{
			_image->GetTexture()->Unbind();

			_effect->GetShader()->Unbind();
		}

		/// <summary>Устанавливает свойства отражения окружающего цвета.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		void Material::SetAmbient(float red, float green, float blue)
		{
		}

		/// <summary>Устанавливает свойства диффузного отражения цвета.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		/// <param name="alpha"></param>
		void Material::SetDiffuse(float red, float green, float blue, float alpha)
		{
		}

		/// <summary>Устанавливает свойства зеркального отражения цвета.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		/// <param name="alpha"></param>
		void Material::SetSpecular(float red, float green, float blue, float alpha)
		{
		}

		/// <summary>Устанавливает свойства блеска.</summary>
		/// <param name="value"></param>
		void Material::SetShininess(float value)
		{
		}

		/// <summary>Получает указатель на шейдерную программу.</summary>
		Gapi::IShaderBase* Material::GetShader(void)
		{
			return _effect->GetShader();
		}

		void Material::AddTexture(std::string textureName)
		{
			Core::Utils::ToLowercase(textureName);

			std::string fileExtension = Core::Utils::GetFileExtension(textureName);
			if (fileExtension.compare("tga") == 0)
			{
				ImageProvider::ImageLoader::TGALoader tgaLoader;
				_image->GetTexture()->Load(tgaLoader.LoadFromFile(textureName));
			}
			else if (fileExtension.compare("bmp") == 0)
			{
				ImageProvider::ImageLoader::BMPLoader bmpLoader;
				_image->GetTexture()->Load(bmpLoader.LoadFromFile(textureName));
			}
			else if (fileExtension.compare("png") == 0)
			{
				ImageProvider::ImageLoader::PNGLoader pngLoader;
				_image->GetTexture()->Load(pngLoader.LoadFromFile(textureName));
			}
			else
			{
				_image->GetTexture()->CreateNullTexture(256, 256);
			}

			_image->Apply();
		}

		void Material::AddShader(const char* vertexShader, const char* fragmentShader)
		{
			if (_effect->GetShader()->Create())
			{
				std::vector<UInt> shaders;
				shaders.push_back(_effect->GetShader()->Compile(Gapi::SHADER_TYPE::Vertex, _effect->GetShader()->Load(vertexShader)));
				shaders.push_back(_effect->GetShader()->Compile(Gapi::SHADER_TYPE::Fragment, _effect->GetShader()->Load(fragmentShader)));

				_effect->GetShader()->Attach(shaders);
				_effect->GetShader()->Link();
				_effect->GetShader()->Validate();
			}
		}
	}
}