#ifndef SIZE_H
#define SIZE_H

#include "../../SDK/Platform.h"

namespace Math
{
	class Point;
	class Rect;
	class CORE_API Size
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Size(void);

		/// <summary>Конструктор класса.</summary>
		Size(float width, float height);

		Point ToPoint(void) const;

		Rect ToRect(void) const;

		float GetWidth(void) const;

		float GetHeight(void) const;

	private:
		float _width;
		float _height;
	};
}

#endif // SIZE_H