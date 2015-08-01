#ifndef MATHCOMMON_H
#define MATHCOMMON_H

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Vector3.h"

namespace Math
{
	static const float REAL_PI = 3.141592654f;

	inline int RandomInteger(int minimum, int maximum)
	{
		srand((unsigned int)time(0L));
		return (rand() % (maximum - minimum)) + minimum;
	}

	inline Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3((a._y * b._z) - (a._z * b._y), (a._z * b._x) - (a._x * b._z), (a._x * b._y) - (a._y * b._x));
	}

	inline float DotProduct(const Vector3& a, const Vector3& b)
	{
		return (a._x * b._x) + (a._y * b._y) + (a._z * b._z);
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

#endif // MATHCOMMON_H