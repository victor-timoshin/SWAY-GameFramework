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
		/// <summary>����������� ������.</summary>
		/// <param name="library">����� ����������.</param>
		/// <param name="device">��������� �� ����������� ������.</param>
		Material(void* library, Gapi::IDeviceBase* device);

		/// <summary>���������� ������.</summary>
		virtual ~Material(void);

		virtual bool Create(const char* vertexShader, const char* fragmentShader);

		virtual void Destroy(void);

		/// <summary>������������� �������� ��������� ����������� �����.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		virtual void SetAmbient(float red, float green, float blue);

		/// <summary>������������� �������� ���������� ��������� �����.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		/// <param name="alpha"></param>
		virtual void SetDiffuse(float red, float green, float blue, float alpha);

		/// <summary>������������� �������� ����������� ��������� �����.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		/// <param name="alpha"></param>
		virtual void SetSpecular(float red, float green, float blue, float alpha);

		/// <summary>������������� �������� ������</summary>
		/// <param name="value"></param>
		virtual void SetShininess(float value);

		/// <summary>�������� ��������� �� ��������� ���������.</summary>
		virtual Gapi::IShaderBase* GetShader(void);

		virtual Gapi::ITextureBase* GetTexture(void);

		/// <summary>�������� ��� ���������.</summary>
		virtual const char* GetName(void) const;

	private:
		char* name; // ��� ���������.
		Gapi::IDeviceBase* renderDevice;
		Gapi::IShaderBase* shader;
		Gapi::ITextureBase* texture;
	};
}

#endif // MATERIAL_H