#ifndef VECTOR2_H
#define VECTOR2_H

#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Vector2
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Vector2(void);

		/// <summary>Конструктор класса.</summary>
		Vector2(float x, float y);

		/// <summary>Конструктор класса.</summary>
		Vector2(const float* other);

		/// <summary>Возвращает квадрат длины данного вектора.</summary>
		float LengthSquared(void) const;

		/// <summary>Получает длину данного вектора.</summary>
		float Length(void);

	public:
		float _x; // Компонент X вектора.
		float _y; // Компонент Y вектора.
	};
}

#endif // VECTOR2_H