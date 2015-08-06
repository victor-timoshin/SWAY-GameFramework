#include "../Inc/Vector4.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Vector4::Vector4(void)
	{
		_x = _y = _z = _w = 0.0f;
	}

	/// <summary>Конструктор класса.</summary>
	Vector4::Vector4(float x, float y, float z, float w)
	{
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}

	/// <summary>Конструктор класса.</summary>
	Vector4::Vector4(const float* other)
	{
		_x = other[0];
		_y = other[1];
		_z = other[2];
		_w = other[3];
	}

	/// <summary>Возвращает квадрат длины данного вектора.</summary>
	float Vector4::LengthSquared(void) const
	{
		return _x * _x + _y * _y + _z * _z + _w * _w;
	}

	/// <summary>Получает длину данного вектора.</summary>
	float Vector4::Length(void)
	{
		return sqrtf(LengthSquared());
	}
}