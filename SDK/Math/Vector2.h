#ifndef VECTOR2_H
#define VECTOR2_H

#include "MathCommon.h"

namespace Math
{
	class Vector2
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Vector2(void)
			: _x(0.0f), _y(0.0f) {}

		/// <summary>Конструктор класса.</summary>
		/// <param name="x">Координата по оси X.</param>
		/// <param name="y">Координата по оси Y.</param>
		Vector2(float x, float y)
			: _x(x), _y(y) { }

		/** Construct from a float array. */
		Vector2(const float* dataArray)
			: _x(dataArray[0]), _y(dataArray[1]) {}

		/** Return length. */
		float Length(void)
		{
			return sqrtf((_x * _x) + (_y * _y));
		}

		/** Return squared length. */
		float LengthSquared(void) const
		{
			return (_x * _x) + (_y * _y);
		}

		/** Normalize to unit length. */
		void Normalize(void)
		{
			float lenSquared = LengthSquared();

			if (!Equals(lenSquared, 1.0f) && lenSquared > 0.0f)
			{
				float invLen = 1.0f / sqrtf(lenSquared);
				_x *= invLen;
				_y *= invLen;
			}
		}
	public:
		float _x; // X координата.
		float _y; // Y координата.
	};
}

#endif // VECTOR2_H