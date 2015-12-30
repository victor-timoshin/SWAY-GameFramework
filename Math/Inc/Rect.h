#ifndef RECT_H
#define RECT_H

#include "../../SDK/Platform.h"

namespace Math
{
	class Point;
	class Size;
	class CORE_API Rect
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Rect(void);

		/// <summary>Конструктор класса.</summary>
		Rect(float x, float y, float width, float height);

		void SetValue(float x, float y, float width, float height);

		bool Intersect(const Rect& rect) const;

		Point GetPosition(void) const;

		Size ToSize(void) const;

		void SetOffset(float x, float y);

		float GetLeft(void) const;

		float GetTop(void) const;

		float GetRight(void) const;

		float GetBottom(void) const;

		/// <summary>Получает ширину прямоугольной области.</summary>
		float GetWidth(void) const;

		/// <summary>Получает высоту прямоугольной области.</summary>
		float GetHeight(void) const;

		bool IsEmpty(void) const;

		bool IsValid(void) const;

	private:
		float _left;
		float _top;
		float _right;
		float _bottom;
	};
}

#endif // RECT_H