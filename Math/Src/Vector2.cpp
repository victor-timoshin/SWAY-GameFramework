#include "../Inc/Vector2.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Vector2::Vector2(void)
	{
		_x = _y = 0.0f;
	}

	/// <summary>Конструктор класса.</summary>
	Vector2::Vector2(float x, float y)
	{
		_x = x;
		_y = y;
	}

	/// <summary>Конструктор класса.</summary>
	Vector2::Vector2(const float* other)
	{
		_x = other[0];
		_y = other[1];
	}

	/// <summary>Возвращает квадрат длины данного вектора.</summary>
	float Vector2::LengthSquared(void) const
	{
		return _x * _x + _y * _y;
	}

	/// <summary>Получает длину данного вектора.</summary>
	float Vector2::Length(void)
	{
		return sqrtf(LengthSquared());
	}
}