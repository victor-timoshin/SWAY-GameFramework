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

		void SetX(float x) { _x = x; }
		void SetY(float y) { _y = y; }
		void SetZ(float z) { _z = z; }
		void SetW(float w) { _w = w; }

		float GetX(void) const { return _x; }
		float GetY(void) const { return _y; }
		float GetZ(void) const { return _z; }
		float GetW(void) const { return _w; }

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

#define VEC4F_ZERO Math::Vector4(0.0f, 0.0f, 0.0f, 0.0f)
#define VEC4F_ONE  Math::Vector4(1.0f, 1.0f, 1.0f, 1.0f)

#endif // VECTOR4_H