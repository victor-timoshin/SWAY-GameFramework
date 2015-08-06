#include "../Inc/MathCommon.h"

namespace Math
{
	int RandomInteger(int minimum, int maximum)
	{
		srand((unsigned int)time(nullptr));
		return (rand() % (maximum - minimum)) + minimum;
	}

	double Uniform(void)
	{
		return (rand() / (float)0x7fff) - 0.5;
	}

	Vector3 Cross(const Vector3& a, const Vector3& b)
	{
		return Vector3((a._y * b._z) - (a._z * b._y), (a._z * b._x) - (a._x * b._z), (a._x * b._y) - (a._y * b._x));
	}

	float DotProduct(const Vector3& a, const Vector3& b)
	{
		return (a._x * b._x) + (a._y * b._y) + (a._z * b._z);
	}

	float Length(const Vector3& v)
	{
		return sqrtf(v._x * v._x + v._y * v._y + v._z * v._z);
	}

	float DegreesToRadians(float degrees)
	{
		return (degrees * REAL_PI) / 180.0f;
	}

	float RadiansToDegrees(float radians)
	{
		return (radians * 180.0f) / REAL_PI;
	}
}