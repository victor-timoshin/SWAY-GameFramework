#include "../Inc/Color.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Color::Color(void)
	{
		Set(1.0f);
	}

	/// <summary>Конструктор класса.</summary>
	Color::Color(const float rgba)
	{
		Set(rgba);
	}

	/// <summary>Конструктор класса.</summary>
	Color::Color(const float r, const float g, const float b, const float a)
	{
		Set(r, g, b, a);
	}

	void Color::Set(float r, float g, float b, float a)
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	void Color::Set(float rgba)
	{
		_r = rgba;
		_g = rgba;
		_b = rgba;
		_a = rgba;
	}

	Vector4 Color::ToVector4(void) const
	{
		return Vector4(_r, _g, _b, _a);
	}
}