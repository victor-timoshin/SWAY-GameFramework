#ifndef MATERIAL_H
#define MATERIAL_H

#include "../../../SDK/Core/Render/MaterialBase.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/ShaderBase.h"
#include "../../../SDK/Gapi/TextureBase.h"
#include "../../../SDK/Gapi/TextureSamplerBase.h"
#include "../ImageProvider/ImageProviderFactory.h"
#include "../../../Math/Inc/Matrix4F.h"

#include "Effect.h"
#include "Image.h"

#include "../Xml/Document.h"

#include "../../../SDK/Platform.h"

#include <vector>
#include <list>

#include <functional> // std::function

namespace Core
{
	namespace Render
	{
		class Material : public IMaterialBase
		{
			DECL_PROPERTY_VIRTUAL_STRING(Name, _name) // Имя материала.

		public:
			/// <summary>Конструктор класса.</summary>
			/// <param name="library">Хендл библиотеки.</param>
			/// <param name="device">Указатель на графический девайс.</param>
			Material(void* library, Gapi::IDeviceBase* device);

			/// <summary>Деструктор класса.</summary>
			virtual ~Material(void);

			virtual bool Create(const char* vertexShader, const char* fragmentShader, ImageProvider::ImageProviderFactory* imageProvider, std::string textureName);

			virtual void Destroy(void);

			virtual void Bind(void);

			virtual void Unbind(void);

			/// <summary>Устанавливает свойства отражения окружающего цвета.</summary>
			/// <param name="red"></param>
			/// <param name="green"></param>
			/// <param name="blue"></param>
			virtual void SetAmbient(float red, float green, float blue);

			/// <summary>Устанавливает свойства диффузного отражения цвета.</summary>
			/// <param name="red"></param>
			/// <param name="green"></param>
			/// <param name="blue"></param>
			/// <param name="alpha"></param>
			virtual void SetDiffuse(float red, float green, float blue, float alpha);

			/// <summary>Устанавливает свойства зеркального отражения цвета.</summary>
			/// <param name="red"></param>
			/// <param name="green"></param>
			/// <param name="blue"></param>
			/// <param name="alpha"></param>
			virtual void SetSpecular(float red, float green, float blue, float alpha);

			/// <summary>Устанавливает свойства блеска</summary>
			/// <param name="value"></param>
			virtual void SetShininess(float value);

			/// <summary>Получает указатель на шейдерную программу.</summary>
			virtual Gapi::IShaderBase* GetShader(void);

		private:
			Gapi::IDeviceBase* _renderDevice;

			Effect* _effect;
			//std::vector<Image*> _images;
			Image* _image;

			Xml::Document* _xmlDocument;
		};
	}
}

#endif // MATERIAL_H