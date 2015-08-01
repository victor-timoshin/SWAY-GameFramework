#include "../../../Core/Inc/Render/Material.h"

namespace Render
{
	/// <summary>����������� ������.</summary>
	/// <param name="library">����� ����������.</param>
	/// <param name="device">��������� �� ����������� ������.</param>
	Material::Material(void* library, Gapi::IDeviceBase* device)
		: renderDevice(device), shader(NULL), texture(NULL)
	{
		typedef Gapi::IShaderBase* IShaderCallback(void);
		shader = reinterpret_cast<IShaderCallback*>(GetProcAddress((HMODULE)library, "RegisterShaderProgram"))();
	}

	/// <summary>���������� ������.</summary>
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

	/// <summary>������������� �������� ��������� ����������� �����.</summary>
	/// <param name="red"></param>
	/// <param name="green"></param>
	/// <param name="blue"></param>
	void Material::SetAmbient(float red, float green, float blue)
	{

	}

	/// <summary>������������� �������� ���������� ��������� �����.</summary>
	/// <param name="red"></param>
	/// <param name="green"></param>
	/// <param name="blue"></param>
	/// <param name="alpha"></param>
	void Material::SetDiffuse(float red, float green, float blue, float alpha)
	{

	}

	/// <summary>������������� �������� ����������� ��������� �����.</summary>
	/// <param name="red"></param>
	/// <param name="green"></param>
	/// <param name="blue"></param>
	/// <param name="alpha"></param>
	void Material::SetSpecular(float red, float green, float blue, float alpha)
	{

	}

	/// <summary>������������� �������� ������.</summary>
	/// <param name="value"></param>
	void Material::SetShininess(float value)
	{

	}

	/// <summary>�������� ��������� �� ��������� ���������.</summary>
	Gapi::IShaderBase* Material::GetShader(void)
	{
		return shader;
	}

	/// <summary>�������� ��� ���������.</summary>
	const char* Material::GetName(void) const
	{
		return name;
	}

	Gapi::ITextureBase* Material::GetTexture(void)
	{
		return texture;
	}
}