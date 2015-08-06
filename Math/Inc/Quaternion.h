#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"
#include "Matrix4.h"
#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Quaternion
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Quaternion(void);

		/// <summary>Конструктор класса.</summary>
		Quaternion(const Quaternion& other);

		/// <summary>Конструктор класса.</summary>
		Quaternion(const float* other);

		/// <summary>Конструктор класса.</summary>
		Quaternion(float x, float y, float z, float w);

		void Identity(void);

		/// <summary>Возвращает квадрат длины данного кватерниона.</summary>
		float LengthSquared(void) const;

		/// <summary>Получает длину данного кватерниона.</summary>
		float Length(void);

		/// <summary>Нормализует данный кватернион.</summary>
		Quaternion Normalize(void) const;

		void FromAxisAngle(Vector3 axis, float angle);

		void ToRotationMatrix(Matrix4& m) const;

		void FromRotationMatrix(Matrix4& m);

		bool operator == (const Quaternion& v) const;

		bool operator != (const Quaternion& v) const;

		/// <summary>Сравнивает два кватерниона на наличие равенства.</summary>
		bool Equals(const Quaternion& v) const;

		Quaternion& operator *= (const Quaternion& q);

		Quaternion operator * (const Quaternion& q) const;

		/// <summary>Умножает указанный кватернион на данный кватернион.</summary>
		Quaternion Multiply(const Quaternion& q) const;

		Quaternion& operator *= (float scalar);

		Quaternion operator * (float scalar) const;

		/// <summary>Умножает указанный скаляр на данный кватернион.</summary>
		Quaternion Multiply(const float scalar) const;

	public:
		float _x;
		float _y;
		float _z;
		float _w;
	};
}

#endif // QUATERNION_H