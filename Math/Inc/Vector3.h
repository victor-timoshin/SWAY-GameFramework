#ifndef VECTOR3_H
#define VECTOR3_H

#include "../../SDK/Platform.h"

#pragma warning(disable: 4251)

namespace Math
{
	template<typename T>
	struct TVector3
	{
		DECL_PROPERTY_INLINE(T, X, _x)
		DECL_PROPERTY_INLINE(T, Y, _y)
		DECL_PROPERTY_INLINE(T, Z, _z)

	public:
		/// <summary>Конструктор класса.</summary>
		TVector3(void)
		{
			Set(0.0f, 0.0f, 0.0f);
		}

		/// <summary>Конструктор класса.</summary>
		explicit TVector3(T x, T y, T z)
		{
			Set(x, y, z);
		}

		/// <summary>Конструктор класса.</summary>
		explicit TVector3(const T* other)
		{
			Set(other[0], other[1], other[2]);
		}

		/// <summary>Устанавливает новые значения.</summary>
		void Set(T x, T y, T z)
		{
			_x = x;
			_y = y;
			_z = z;
		}

		/// <summary>Возвращает квадрат длины данного вектора.</summary>
		T LengthSquared(void) const
		{
			return _x * _x + _y * _y + _z * _z;
		}

		/// <summary>Получает длину данного вектора.</summary>
		T Length(void)
		{
			return (T)sqrt(LengthSquared());
		}

		/// <summary>Нормализует данный вектор.</summary>
		TVector3<T> Normalize(void) const
		{
			T lenSquared = LengthSquared();
			if (lenSquared > 0.0f)
				return Multiply(1.0f / (T)sqrt(lenSquared));

			return TVector3<T>();
		}

		TVector3<T> Inverse(void) const
		{
			return TVector3<T>(-_x, -_y, -_z);
		}

		bool IsZero(void) const
		{
			return _x == 0.0f && _y == 0.0f && _z == 0.0f;
		}

		TVector3<T>& operator = (const TVector3<T>& vector)
		{
			_x = vector._x;
			_y = vector._y;
			_z = vector._z;

			return *this;
		}

		bool operator == (const TVector3<T>& vector) const
		{
			return Equals(vector);
		}

		bool operator != (const TVector3<T>& vector) const
		{
			return !Equals(vector);
		}

		/// <summary>Сравнивает два вектора на наличие равенства.</summary>
		bool Equals(const TVector3& vector) const
		{
			return (_x == vector._x && _y == vector._y && _z == vector._z);
		}

		TVector3<T>& operator += (const TVector3<T>& vector)
		{
			return *this = Add(vector);
		}

		TVector3<T> operator + (const TVector3<T>& vector) const
		{
			return Add(vector);
		}

		/// <summary>Складывает два вектора.</summary>
		TVector3<T> Add(const TVector3<T>& vector) const
		{
			return TVector3<T>(_x + vector._x, _y + vector._y, _z + vector._z);
		}

		TVector3<T> operator - () const
		{
			return TVector3<T>(-_x, -_y, -_z);
		}

		TVector3<T>& operator -= (const TVector3<T>& vector)
		{
			*this = Subtract(vector);
			return *this;
		}

		TVector3<T> operator - (const TVector3<T>& vector) const
		{
			return Subtract(vector);
		}

		/// <summary>Вычитает указанный вектор из другого заданного вектора.</summary>
		TVector3<T> Subtract(const TVector3<T>& vector) const
		{
			return TVector3<T>(_x - vector._x, _y - vector._y, _z - vector._z);
		}

		TVector3<T>& operator *= (const TVector3<T>& vector)
		{
			*this = Multiply(vector);
			return *this;
		}

		TVector3<T> operator * (const TVector3<T>& vector) const
		{
			return Multiply(vector);
		}

		/// <summary>Умножает данный вектор на другой указанный вектор.</summary>
		TVector3<T> Multiply(const TVector3<T>& vector) const
		{
			return TVector3<T>(_x * vector._x, _y * vector._y, _z * vector._z);
		}

		TVector3<T>& operator *= (float num)
		{
			_x *= num;
			_y *= num;
			_z *= num;

			return *this;
		}

		/// <summary>Умножает указанный скаляр на данный вектор.</summary>
		TVector3<T> Multiply(T scalar) const
		{
			return TVector3<T>(_x * scalar, _y * scalar, _z * scalar);
		}

		TVector3<T>& operator /= (const TVector3<T>& vector)
		{
			*this = Divide(vector);
			return *this;
		}

		TVector3<T>& operator /= (T num)
		{
			*this = Divide(num);
			return *this;
		}

		TVector3<T> operator / (const TVector3<T>& vector) const
		{
			return Divide(vector);
		}

		/// <summary>Делит указанный вектор на заданный скаляр.</summary>
		const TVector3<T>& Divide(const TVector3<T>& vector)
		{
			return TVector3<T>(_x /= vector._x, _y /= vector._y, _z /= vector._z);
		}

		std::string ToString(void) const
		{
			std::ostringstream stream;
			stream << "[" << _x << ", " << _y << ", " << _z << "]";
			return stream.str();
		}

		friend TVector3<T> operator + (const TVector3<T>& vector, float num) { return TVector3<T>(vector._x + num, vector._y + num, vector._z + num); }
		friend TVector3<T> operator + (float num, const TVector3<T>& vector) { return TVector3<T>(num + vector._x, num + vector._y, num + vector._z); }

		friend TVector3<T> operator - (const TVector3<T>& vector, float num) { return TVector3<T>(vector._x - num, vector._y - num, vector._z - num); }
		friend TVector3<T> operator - (float num, const TVector3<T>& vector) { return TVector3<T>(num - vector._x, num - vector._y, num - vector._z); }

		friend TVector3<T> operator * (const TVector3<T>& vector, float num) { return TVector3<T>(vector._x * num, vector._y * num, vector._z * num); }
		friend TVector3<T> operator * (float num, const TVector3<T>& vector) { return TVector3<T>(num * vector._x, num * vector._y, num * vector._z); }

		friend TVector3<T> operator / (const TVector3<T>& vector, float num) { return TVector3<T>(vector._x / num, vector._y / num, vector._z / num); }
		friend TVector3<T> operator / (float num, const TVector3<T>& vector) { return TVector3<T>(num / vector._x, num / vector._y, num / vector._z); }
	};

	CORE_API typedef TVector3<float> Vec3F;
	CORE_API typedef TVector3<float> Vector3F;

	CORE_API typedef TVector3<double> Vec3D;
	CORE_API typedef TVector3<double> Vector3D;

	CORE_API typedef TVector3<int> Vec3I;
	CORE_API typedef TVector3<int> Vector3I;
}

#define VEC3F_ZERO    Math::Vector3F(0.0f, 0.0f, 0.0f)
#define VEC3F_ONE     Math::Vector3F(1.0f, 1.0f, 1.0f)

#define VEC3F_UNIT_X  Math::Vector3F(1.0f, 0.0f, 0.0f)
#define VEC3F_UNIT_Y  Math::Vector3F(0.0f, 1.0f, 0.0f)
#define VEC3F_UNIT_Z  Math::Vector3F(0.0f, 0.0f, 1.0f)

#define VEC3F_LEFT    Math::Vector3F(-1.0f, 0.0f, 0.0f);
#define VEC3F_RIGHT   Math::Vector3F(1.0f, 0.0f, 0.0f);
#define VEC3F_UP      Math::Vector3F(0.0f, 1.0f, 0.0f);
#define VEC3F_DOWN    Math::Vector3F(0.0f, -1.0f, 0.0f);
#define VEC3F_FORWARD Math::Vector3F(0.0f, 0.0f, 1.0f);
#define VEC3F_BACK    Math::Vector3F(0.0f, 0.0f, -1.0f);

#endif // VECTOR3_H