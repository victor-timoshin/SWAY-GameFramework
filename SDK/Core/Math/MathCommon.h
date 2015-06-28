#ifndef MATH_COMMON_H
#define MATH_COMMON_H

#include "Vector3.h"

#include <stdlib.h>
#include <time.h>
#include <math.h>

namespace Core
{
	namespace Math
	{
		static const float REAL_PI = 3.141592654f;
		static const float EPSILON = 0.000001f;

		inline bool Equals(float lhs, float rhs)
		{
			return lhs + EPSILON >= rhs && lhs - EPSILON <= rhs;
		}

		inline int RandomInteger(int minimum, int maximum)
		{
			srand((unsigned int)time(0L));
			return (rand() % (maximum - minimum)) + minimum;
		}

		inline Vector3 Cross(const Vector3& A, const Vector3& B)
		{
			return Vector3((A._y * B._z) - (A._z * B._y), (A._z * B._x) - (A._x * B._z), (A._x * B._y) - (A._y * B._x));
		}

		inline float DotProduct(const Vector3& A, const Vector3& B)
		{
			return (A._x * B._x) + (A._y * B._y) + (A._z * B._z);
		}

		inline float Length(const Vector3& v)
		{
			return sqrtf(v._x * v._x + v._y * v._y + v._z * v._z);
		}

		inline float DegreesToRadians(float degrees)
		{
			return (degrees * REAL_PI) / 180.0f;
		}

		inline float RadiansToDegrees(float radians)
		{
			return (radians * 180.0f) / REAL_PI;
		}
	}
}

#endif // MATH_COMMON_H