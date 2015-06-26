#ifndef VECTOR3_H
#define VECTOR3_H

#include "MathCommon.h"

namespace Core
{
	namespace Math
	{
		class Vector3
		{
		public:
			/** Constructor. */
			Vector3()
				: _x(0.0f), _y(0.0f), _z(0.0f) {}

			/** Construct from coordinates. */
			Vector3(float x, float y, float z)
				: _x(x), _y(y), _z(z) {}

			/** Construct from a float array. */
			Vector3(const float* dataArray)
				: _x(dataArray[0]), _y(dataArray[1]), _z(dataArray[2]) {}

			/** Return length. */
			float Length()
			{
				return sqrtf((_x * _x) + (_y * _y) + (_z * _z));
			}

			/** Return squared length. */
			float LengthSquared() const
			{
				return (_x * _x) + (_y * _y) + (_z * _z);
			}

			/** Normalize to unit length. */
			void Normalize()
			{
				float lenSquared = LengthSquared();
				if (!Equals(lenSquared, 1.0f) && lenSquared > 0.0f)
				{
					float invLength = 1.0f / sqrtf(lenSquared);
					_x *= invLength;
					_y *= invLength;
					_z *= invLength;
				}
			}

			bool operator==(const Vector3& v) const
			{
				return (_x == v._x) && (_y == v._y) && (_z == v._z);
			}

			bool operator!=(const Vector3& v) const
			{
				return (_x != v._x) || (_y != v._y) || (_z != v._z);
			}

			Vector3& operator+=(const Vector3& v)
			{
				_x += v._x;
				_y += v._y;
				_z += v._z;

				return *this;
			}

			Vector3& operator-=(const Vector3& v)
			{
				_x -= v._x;
				_y -= v._y;
				_z -= v._z;

				return *this;
			}

			Vector3& operator*=(const float& s)
			{
				_x *= s;
				_y *= s;
				_z *= s;

				return *this;
			}

			Vector3& operator*=(const Vector3& v)
			{
				_x *= v._x;
				_y *= v._y;
				_z *= v._z;

				return	*this;
			}

			Vector3& operator/=(const Vector3& v)
			{
				_x /= v._x;
				_y /= v._y;
				_z /= v._z;

				return	*this;
			}

			Vector3& operator/=(const float& s)
			{
				float m = 1.0f / s;

				_x *= m;
				_y *= m;
				_z *= m;

				return	*this;
			}

		public:
			float _x; // X coordinate.
			float _y; // Y coordinate.
			float _z; // Z coordinate.
		};
	}
}

#endif // VECTOR3_H