#ifndef VECTOR4_H
#define VECTOR4_H

#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Vector4
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Vector4(void);

		/// <summary>Конструктор класса.</summary>
		Vector4(float x, float y, float z, float w);

		/// <summary>Конструктор класса.</summary>
		Vector4(const float* other);


		/// <summary>Возвращает квадрат длины данного вектора.</summary>
		float LengthSquared(void) const;

		/// <summary>Получает длину данного вектора.</summary>
		float Length(void);

	public:
		float _x; // Компонент X вектора.
		float _y; // Компонент Y вектора.
		float _z; // Компонент Z вектора.
		float _w; // Компонент W вектора.
	};
}

#endif // VECTOR4_H