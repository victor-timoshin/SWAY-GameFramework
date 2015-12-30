#ifndef MATHCOMMON_H
#define MATHCOMMON_H

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "Vector3.h"
#include "BoundingBox.h"
#include "Matrix4F.h"

#include "MathConstants.h"

namespace Math
{
	CORE_API int RandRangeI(int min, int max);

	CORE_API double Uniform(void);

	CORE_API Vector3F Cross(const Vector3F& a, const Vector3F& b);

	CORE_API float DotProduct(const Vector3F& a, const Vector3F& b);

	CORE_API float DegreesToRadians(float degrees);

	CORE_API float RadiansToDegrees(float radians);

	CORE_API int SnapToFloor(int input, int gap);

	CORE_API Vector3F ToDirection(const Vector3F& vector);

	CORE_API int MinI(int t1, int t2);

	CORE_API float MinF(float t1, float t2);

	template<typename T>
	T Min(T t1, T t2)
	{
		return (t1 < t2 ? t1 : t2);
	}

	CORE_API int MaxI(int t1, int t2);

	CORE_API float MaxF(float t1, float t2);

	template<typename T>
	T Max(T t1, T t2)
	{
		return (t1 < t2 ? t2 : t1);
	}
}

#endif // MATHCOMMON_H