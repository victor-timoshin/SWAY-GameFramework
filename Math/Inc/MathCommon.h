#ifndef MATHCOMMON_H
#define MATHCOMMON_H

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Vector3.h"

namespace Math
{
	static const float REAL_PI = 3.141592654f;

	int CORE_API RandomInteger(int minimum, int maximum);

	double CORE_API Uniform(void);

	Vector3 CORE_API Cross(const Vector3& a, const Vector3& b);

	float CORE_API DotProduct(const Vector3& a, const Vector3& b);

	float CORE_API DegreesToRadians(float degrees);

	float CORE_API RadiansToDegrees(float radians);
}

#endif // MATHCOMMON_H