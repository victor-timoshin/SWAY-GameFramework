#ifndef POINT_H
#define POINT_H

#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Point
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Point(void);

		/// <summary>Конструктор класса.</summary>
		Point(float x, float y);

		/// <summary>Конструктор класса.</summary>
		Point(const float* other);

		std::string ToString(void) const;

	public:
		float _x; // Координата точки по оси X.
		float _y; // Координата точки по оси Y.
	};
}

#endif // POINT_H