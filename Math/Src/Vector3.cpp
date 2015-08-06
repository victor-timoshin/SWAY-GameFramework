#include "../Inc/Vector3.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Vector3::Vector3(void)
	{
		_x = _y = _z = 0.0f;
	}

	/// <summary>Конструктор класса.</summary>
	Vector3::Vector3(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	/// <summary>Конструктор класса.</summary>
	Vector3::Vector3(const float* other)
	{
		_x = other[0];
		_y = other[1];
		_z = other[2];
	}

	/// <summary>Возвращает квадрат длины данного вектора.</summary>
	float Vector3::LengthSquared(void) const
	{
		return _x * _x + _y * _y + _z * _z;
	}

	/// <summary>Получает длину данного вектора.</summary>
	float Vector3::Length(void)
	{
		return sqrtf(LengthSquared());
	}

	/// <summary>Нормализует данный вектор.</summary>
	Vector3 Vector3::Normalize(void) const
	{
		float lenSquared = LengthSquared();
		if (lenSquared > 0.0f)
			return Multiply(1.0f / sqrt(lenSquared));

		return Vector3();
	}

	Vector3 Vector3::Inverse(void) const
	{
		return Vector3(-_x, -_y, -_z);
	}

	bool Vector3::operator == (const Vector3& v) const
	{
		return Equals(v);
	}

	bool Vector3::operator != (const Vector3& v) const
	{
		return !Equals(v);
	}

	/// <summary>Сравнивает два вектора на наличие равенства.</summary>
	bool Vector3::Equals(const Vector3& v) const
	{
		return (_x == v._x && _y == v._y && _z == v._z);
	}

	Vector3& Vector3::operator += (const Vector3& v)
	{
		return *this = Add(v);
	}

	Vector3 Vector3::operator + (const Vector3& v) const
	{
		return Add(v);
	}

	/// <summary>Складывает два вектора.</summary>
	Vector3 Vector3::Add(const Vector3& v) const
	{
		return Vector3(_x + v._x, _y + v._y, _z + v._z);
	}

	Vector3& Vector3::operator -= (const Vector3& v)
	{
		*this = Subtract(v);
		return *this;
	}

	Vector3 Vector3::operator - (const Vector3& v) const
	{
		return Subtract(v);
	}

	/// <summary>Вычитает указанный вектор из другого заданного вектора.</summary>
	Vector3 Vector3::Subtract(const Vector3& v) const
	{
		return Vector3(_x - v._x, _y - v._y, _z - v._z);
	}

	Vector3& Vector3::operator *= (const Vector3& v)
	{
		*this = Multiply(v);
		return *this;
	}

	Vector3 Vector3::operator * (const Vector3& v) const
	{
		return Multiply(v);
	}

	/// <summary>Умножает данный вектор на другой указанный вектор.</summary>
	Vector3 Vector3::Multiply(const Vector3& v) const
	{
		return Vector3(_x * v._x, _y * v._y, _z * v._z);
	}

	Vector3& Vector3::operator *= (float scalar)
	{
		*this = Multiply(scalar);
		return *this;
	}

	Vector3 Vector3::operator * (float scalar) const
	{
		return Multiply(scalar);
	}

	/// <summary>Умножает указанный скаляр на данный вектор.</summary>
	Vector3 Vector3::Multiply(float scalar) const
	{
		return Vector3(_x * scalar, _y * scalar, _z * scalar);
	}

	Vector3& Vector3::operator /= (const Vector3& v)
	{
		*this = Divide(v);
		return *this;
	}

	Vector3 Vector3::operator / (const Vector3& v) const
	{
		return Divide(v);
	}

	/// <summary>Делит указанный вектор на заданный вектор.</summary>
	Vector3 Vector3::Divide(const Vector3& v) const
	{
		return Vector3(_x / v._x, _y / v._y, _z / v._z);
	}

	Vector3& Vector3::operator /= (float scalar)
	{
		*this = Divide(scalar);
		return *this;
	}

	Vector3 Vector3::operator / (float scalar) const
	{
		return Divide(scalar);
	}

	/// <summary>Делит указанный вектор на заданный скаляр.</summary>
	Vector3 Vector3::Divide(float scalar) const
	{
		return Multiply(1.0f / scalar);
	}
}