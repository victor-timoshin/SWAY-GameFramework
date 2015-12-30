#include "../Inc/Rect.h"
#include "../Inc/Point.h"
#include "../Inc/Size.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Rect::Rect(void)
	{
		SetValue(0.0f, 0.0f, 0.0f, 0.0f);
	}

	/// <summary>Конструктор класса.</summary>
	Rect::Rect(float x, float y, float width, float height)
	{
		SetValue(x, y, width, height);
	}

	void Rect::SetValue(float x, float y, float width, float height)
	{
		_left = x;
		_top = y;
		_right = width;
		_bottom = height;
	}

	bool Rect::Intersect(const Rect& rect) const
	{
		return ((_left < rect._right) && (_right > rect._left) && (_bottom > rect._top) && (_top < rect._bottom));
	}

	Point Rect::GetPosition(void) const
	{
		return Point(_left, _top);
	}

	Size Rect::ToSize(void) const
	{
		return Size(GetWidth(), GetHeight());
	}

	void Rect::SetOffset(float x, float y)
	{
		_left += x;
		_top += y;
		_right += x;
		_bottom += y;
	}

	float Rect::GetLeft(void) const
	{
		return _left;
	}

	float Rect::GetTop(void) const
	{
		return _top;
	}

	float Rect::GetRight(void) const
	{
		return _left + _right;
	}

	float Rect::GetBottom(void) const
	{
		return _top + _bottom;
	}

	/// <summary>Получает ширину прямоугольной области.</summary>
	float Rect::GetWidth(void) const
	{
		return _right - _left;
	}

	/// <summary>Получает высоту прямоугольной области.</summary>
	float Rect::GetHeight(void) const
	{
		return _bottom - _top;
	}

	bool Rect::IsEmpty(void) const
	{
		return ((GetWidth() <= 0) || (GetHeight() <= 0));
	}

	bool Rect::IsValid(void) const
	{
		if ((_top > _bottom) || (_left > _right))
			return false;

		return true;
	}
}