#ifndef VECTOR2_H
#define VECTOR2_H

#include "../../SDK/Platform.h"

namespace Math
{
	template<class T>
	class CORE_API TVector2
	{
	public:
		/// <summary>Конструктор класса.</summary>
		TVector2(void)
		{
			Set(0.0f, 0.0f);
		}

		/// <summary>Конструктор класса.</summary>
		TVector2(T x, T y)
		{
			Set(x, y);
		}

		/// <summary>Конструктор класса.</summary>
		TVector2(const T* other)
		{
			Set(other[0], other[1]);
		}

		/// <summary>Устанавливает новые значения.</summary>
		void Set(T x, T y)
		{
			_x = x;
			_y = y;
		}

		void SetX(T x) { _x = x; }
		void SetY(T y) { _y = y; }

		T GetX(void) const { return _x; }
		T GetY(void) const { return _y; }

		/// <summary>Возвращает квадрат длины данного вектора.</summary>
		float LengthSquared(void) const
		{
			return _x * _x + _y * _y;
		}

		/// <summary>Получает длину данного вектора.</summary>
		float Length(void)
		{

		}

	public:
		T _x; // Компонент X вектора.
		T _y; // Компонент Y вектора.
	};

	typedef TVector2<float> Vec2F;
	typedef TVector2<float> Vector2F;

	typedef TVector2<double> Vec2D;
	typedef TVector2<double> Vector2D;

	typedef TVector2<int> Vec2I;
	typedef TVector2<int> Vector2I;
}

#define VEC2F_ZERO Math::Vector2F(0.0f, 0.0f)

#endif // VECTOR2_H