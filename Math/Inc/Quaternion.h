#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"
#include "Matrix4F.h"
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

		void FromAxisAngle(TVector3<float> axis, float angle);

		void ToRotationMatrix(Matrix4F& m) const;

		void FromRotationMatrix(Matrix4F& m);

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

		Vector3F operator * (const Vector3F& vector) const;

		/// <summary>Умножает указанный скаляр на данный кватернион.</summary>
		Quaternion Multiply(const float scalar) const;

		Vector3F GetForward(void) const;

		Vector3F GetUp(void) const;

		Vector3F GetRight(void) const;

	public:
		float _x;
		float _y;
		float _z;
		float _w;
	};
}

#define QUATERNION_IDENTITY Math::Quaternion(0.0f, 0.0f, 0.0f, 1.0f)

#endif // QUATERNION_H