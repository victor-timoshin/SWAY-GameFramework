#ifndef MATH_COMMON_H
#define MATH_COMMON_H

#include <math.h>

namespace Core
{
	namespace Math
	{
		static const float REAL_PI = 3.141592654f;
		static const float EPSILON = 0.000001f;

		/** Check whether two floating point values are equal within accuracy. */
		inline bool Equals(float lhs, float rhs) { return lhs + EPSILON >= rhs && lhs - EPSILON <= rhs; }
	}
}

#endif // MATH_COMMON_H