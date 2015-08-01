#ifndef MATERIAL_H
#define MATERIAL_H

#include "../../../SDK/Core/Render/MaterialBase.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/ShaderBase.h"
#include "../../../SDK/Gapi/TextureBase.h"
#include "../../../SDK/Platform.h"

#include <vector>

namespace Render
{
	class Material : public IMaterialBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="library">Хендл библиотеки.</param>
		/// <param name="device">Указатель на графический девайс.</param>
		Material(void* library, Gapi::IDeviceBase* device);

		/// <summary>Деструктор класса.</summary>
		virtual ~Material(void);

		virtual bool Create(const char* vertexShader, const char* fragmentShader);

		virtual void Destroy(void);

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

		virtual Gapi::ITextureBase* GetTexture(void);

		/// <summary>Получает имя материала.</summary>
		virtual const char* GetName(void) const;

	private:
		char* name; // Имя материала.
		Gapi::IDeviceBase* renderDevice;
		Gapi::IShaderBase* shader;
		Gapi::ITextureBase* texture;
	};
}

#endif // MATERIAL_H