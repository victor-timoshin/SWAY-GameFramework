#include "../Inc/Color.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Color::Color(void)
	{
		_r = _g = _b = _a = 1.0f;
	}

	/// <summary>Конструктор класса.</summary>
	Color::Color(const float r, const float g, const float b, const float a)
	{
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	/// <summary>Деструктор класса.</summary>
	Color::~Color(void)
	{
	}

	void Color::SetRedChannel(float channel)
	{
		_r = channel;
	}

	float Color::GetRedChannel(void) const
	{
		return _r;
	}

	void Color::SetGreenChannel(float channel)
	{
		_g = channel;
	}

	float Color::GetGreenChannel(void) const
	{
		return _g;
	}

	void Color::SetBlueChannel(float channel)
	{
		_b = channel;
	}

	float Color::GetBlueChannel(void) const
	{
		return _b;
	}

	void Color::SetAlphaChannel(float channel)
	{
		_a = channel;
	}

	float Color::GetAlphaChannel(void) const
	{
		return _a;
	}
}