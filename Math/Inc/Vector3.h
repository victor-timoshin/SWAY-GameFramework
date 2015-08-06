#ifndef VECTOR3_H
#define VECTOR3_H

#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Vector3
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Vector3(void);

		/// <summary>Конструктор класса.</summary>
		Vector3(float x, float y, float z);

		/// <summary>Конструктор класса.</summary>
		Vector3(const float* other);

		/// <summary>Возвращает квадрат длины данного вектора.</summary>
		float LengthSquared(void) const;

		/// <summary>Получает длину данного вектора.</summary>
		float Length(void);

		/// <summary>Нормализует данный вектор.</summary>
		Vector3 Normalize(void) const;

		Vector3 Inverse(void) const;

		bool Vector3::operator == (const Vector3& v) const;

		bool Vector3::operator != (const Vector3& v) const;

		/// <summary>Сравнивает два вектора на наличие равенства.</summary>
		bool Vector3::Equals(const Vector3& v) const;

		Vector3& Vector3::operator += (const Vector3& v);

		Vector3 Vector3::operator + (const Vector3& v) const;

		/// <summary>Складывает два вектора.</summary>
		Vector3 Add(const Vector3& v) const;

		Vector3& operator -= (const Vector3& v);

		Vector3 operator - (const Vector3& v) const;

		/// <summary>Вычитает указанный вектор из другого заданного вектора.</summary>
		Vector3 Subtract(const Vector3& v) const;

		Vector3& operator *= (const Vector3& v);

		Vector3 operator * (const Vector3& v) const;

		/// <summary>Умножает данный вектор на другой указанный вектор.</summary>
		Vector3 Multiply(const Vector3& v) const;

		Vector3& operator *= (float scalar);

		Vector3 operator * (float scalar) const;

		/// <summary>Умножает указанный скаляр на данный вектор.</summary>
		Vector3 Multiply(float scalar) const;

		Vector3& operator /= (const Vector3& v);

		Vector3 operator / (const Vector3& v) const;

		/// <summary>Делит указанный вектор на заданный скаляр.</summary>
		Vector3 Divide(const Vector3& v) const;

		Vector3& operator /= (float scalar);

		Vector3 operator / (float scalar) const;

		/// <summary>Делит указанный вектор на заданный скаляр.</summary>
		Vector3 Divide(float scalar) const;

	public:
		float _x; // Компонент X вектора.
		float _y; // Компонент Y вектора.
		float _z; // Компонент Z вектора.
	};
}

#endif // VECTOR3_H