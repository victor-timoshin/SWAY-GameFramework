#ifndef VECTOR4_H
#define VECTOR4_H

#include "MathCommon.h"

namespace Core
{
	namespace Math
	{
		class Vector4
		{
		public:
			/** Constructor. */
			Vector4()
				: _x(0.0f), _y(0.0f), _z(0.0f), _w(0.0f) {}

			/** Construct from coordinates. */
			Vector4(float x, float y, float z, float w)
				: _x(x), _y(y), _z(z), _w(w) {}

			/** Construct from a float array. */
			Vector4(const float* dataArray)
				: _x(dataArray[0]), _y(dataArray[1]), _z(dataArray[2]), _w(dataArray[3]) {}

			/** Return length. */
			float Length()
			{
				return sqrtf((_x * _x) + (_y * _y) + (_z * _z) + (_w * _w));
			}

			/** Return squared length. */
			float LengthSquared() const
			{
				return (_x * _x) + (_y * _y) + (_z * _z) + (_w * _w);
			}
		public:
			float _x; // X coordinate.
			float _y; // Y coordinate.
			float _z; // Z coordinate.
			float _w; // W coordinate.
		};
	}
}

#endif // VECTOR4_H