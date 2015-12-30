#include "../Inc/Point.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Point::Point(void)
	{
		_x = _y = 0.0f;
	}

	/// <summary>Конструктор класса.</summary>
	Point::Point(float x, float y)
	{
		_x = x;
		_y = y;
	}

	/// <summary>Конструктор класса.</summary>
	Point::Point(const float* other)
	{
		_x = other[0];
		_y = other[1];
	}

	std::string Point::ToString(void) const
	{
		std::ostringstream stream;
		stream << "[" << _x << ", " << _y << "]";
		return stream.str();
	}
}