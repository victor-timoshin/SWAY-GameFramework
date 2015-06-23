#ifndef VECTOR2_H
#define VECTOR2_H

#include "MathCommon.h"

namespace Core
{
	namespace Math
	{
		class Vector2
		{
		public:
			/** Constructor. */
			Vector2()
				: _x(0.0f)
				, _y(0.0f)
			{
			}

			/** Construct from coordinates. */
			Vector2(float x, float y)
				: _x(x)
				, _y(y)
			{
			}

			/** Construct from a float array. */
			Vector2(const float* dataArray)
				: _x(dataArray[0])
				, _y(dataArray[1])
			{
			}

			/** Return length. */
			float Length() {
				return sqrtf((_x * _x) + (_y * _y));
			}

			/** Return squared length. */
			float LengthSquared() const {
				return (_x * _x) + (_y * _y);
			}

			/** Normalize to unit length. */
			void Normalize() {
				float lenSquared = LengthSquared();

				if (!Equals(lenSquared, 1.0f) && lenSquared > 0.0f)
				{
					float invLen = 1.0f / sqrtf(lenSquared);
					_x *= invLen;
					_y *= invLen;
				}
			}
		public:
			float _x; // X coordinate.
			float _y; // Y coordinate.
		};
	}
}

#endif // VECTOR2_H