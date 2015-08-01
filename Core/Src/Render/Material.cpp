#include "../../../Core/Inc/Render/Material.h"

namespace Render
{
	/// <summary>Конструктор класса.</summary>
	/// <param name="library">Хендл библиотеки.</param>
	/// <param name="device">Указатель на графический девайс.</param>
	Material::Material(void* library, Gapi::IDeviceBase* device)
		: renderDevice(device), shader(NULL), texture(NULL)
	{
		typedef Gapi::IShaderBase* IShaderCallback(void);
		shader = reinterpret_cast<IShaderCallback*>(GetProcAddress((HMODULE)library, "RegisterShaderProgram"))();
	}

	/// <summary>Деструктор класса.</summary>
	Material::~Material(void)
	{
		Destroy();
	}

	bool Material::Create(const char* vertexShader, const char* fragmentShader)
	{
		if (shader->Create())
		{
			std::vector<UInt> shaders;
			shaders.push_back(shader->Compile(Gapi::SHADERTYPES::EST_VERTEX, shader->Load(vertexShader).c_str()));
			shaders.push_back(shader->Compile(Gapi::SHADERTYPES::EST_FRAGMENT, shader->Load(fragmentShader).c_str()));

			shader->Attach(shaders);
			shader->Link();
			shader->Validate();

			return true;
		}

		return false;
	}

	void Material::Destroy(void)
	{
		SAFE_DELETE(shader);
		SAFE_DELETE(texture);
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
		return shader;
	}

	/// <summary>Получает имя материала.</summary>
	const char* Material::GetName(void) const
	{
		return name;
	}

	Gapi::ITextureBase* Material::GetTexture(void)
	{
		return texture;
	}
}