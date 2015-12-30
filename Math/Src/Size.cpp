#include "../Inc/Size.h"
#include "../Inc/Point.h"
#include "../Inc/Rect.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Size::Size(void)
	{
	}

	/// <summary>Конструктор класса.</summary>
	Size::Size(float width, float height)
	{
		_width = width;
		_height = height;
	}

	Point Size::ToPoint(void) const
	{
		return Point(_width, _height);
	}

	Rect Size::ToRect(void) const
	{
		return Rect(0, 0, _width, _height);
	}

	float Size::GetWidth(void) const
	{
		return _width;
	}

	float Size::GetHeight(void) const
	{
		return _height;
	}
}