#ifndef VECTOR4_H
#define VECTOR4_H

#include "MathCommon.h"

namespace Math
{
	class Vector4
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Vector4(void)
			: _x(0.0f), _y(0.0f), _z(0.0f), _w(0.0f) {}

		/// <summary>Конструктор класса.</summary>
		/// <param name="x">Координата по оси X.</param>
		/// <param name="y">Координата по оси Y.</param>
		/// <param name="z">Координата по оси Z.</param>
		/// <param name="w">Временной компонент.</param>
		Vector4(float x, float y, float z, float w)
			: _x(x), _y(y), _z(z), _w(w) {}

		/** Construct from a float array. */
		Vector4(const float* dataArray)
			: _x(dataArray[0]), _y(dataArray[1]), _z(dataArray[2]), _w(dataArray[3]) {}

		/** Return length. */
		float Length(void)
		{
			return sqrtf((_x * _x) + (_y * _y) + (_z * _z) + (_w * _w));
		}

		/** Return squared length. */
		float LengthSquared(void) const
		{
			return (_x * _x) + (_y * _y) + (_z * _z) + (_w * _w);
		}
	public:
		float _x; // X координата.
		float _y; // Y координата.
		float _z; // Z координата.
		float _w; // W координата.
	};
}

#endif // VECTOR4_H