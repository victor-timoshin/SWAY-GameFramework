#ifndef VECTOR4_H
#define VECTOR4_H

#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Vector4
	{
	public:
		/// <summary>����������� ������.</summary>
		Vector4(void);

		/// <summary>����������� ������.</summary>
		Vector4(float x, float y, float z, float w);

		/// <summary>����������� ������.</summary>
		Vector4(const float* other);


		/// <summary>���������� ������� ����� ������� �������.</summary>
		float LengthSquared(void) const;

		/// <summary>�������� ����� ������� �������.</summary>
		float Length(void);

	public:
		float _x; // ��������� X �������.
		float _y; // ��������� Y �������.
		float _z; // ��������� Z �������.
		float _w; // ��������� W �������.
	};
}

#endif // VECTOR4_H