#ifndef MATERIALBASE_H
#define MATERIALBASE_H

#include "../../../SDK/Math/Vector4.h"
#include "../../../SDK/Platform.h"

namespace Render
{
	class IMaterialBase
	{
	public:
		/// <summary>����������� ������.</summary>
		IMaterialBase(void) {}

		/// <summary>���������� ������.</summary>
		virtual ~IMaterialBase(void) {}

		virtual bool Create(const char* vertexShader, const char* fragmentShader) = 0;

		virtual void Destroy(void) = 0;

		/// <summary>������������� �������� ��������� ����������� �����.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		virtual void SetAmbient(float red, float green, float blue) = 0;

		/// <summary>������������� �������� ���������� ��������� �����.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		/// <param name="alpha"></param>
		virtual void SetDiffuse(float red, float green, float blue, float alpha) = 0;

		/// <summary>������������� �������� ����������� ��������� �����.</summary>
		/// <param name="red"></param>
		/// <param name="green"></param>
		/// <param name="blue"></param>
		/// <param name="alpha"></param>
		virtual void SetSpecular(float red, float green, float blue, float alpha) = 0;

		/// <summary>������������� �������� ������</summary>
		/// <param name="value"></param>
		virtual void SetShininess(float value) = 0;

		virtual const char* GetName(void) const = 0;
	};
}

#endif // MATERIALBASE_H