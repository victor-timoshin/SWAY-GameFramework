#include "../Inc/MathCommon.h"

namespace Math
{
	int RandRangeI(int min, int max)
	{
		srand((unsigned int)time(nullptr));
		return (rand() % (max - min)) + min;
	}

	double Uniform(void)
	{
		return (rand() / (float)0x7fff) - 0.5;
	}

	Vector3F Cross(const Vector3F& a, const Vector3F& b)
	{
		return Vector3F((a._y * b._z) - (a._z * b._y), (a._z * b._x) - (a._x * b._z), (a._x * b._y) - (a._y * b._x));
	}

	float DotProduct(const Vector3F& a, const Vector3F& b)
	{
		return (a._x * b._x) + (a._y * b._y) + (a._z * b._z);
	}

	float Length(const Vector3F& v)
	{
		return sqrtf(v._x * v._x + v._y * v._y + v._z * v._z);
	}

	float DegreesToRadians(float degrees)
	{
		return (degrees * MATH_REAL_PI) / 180.0f;
	}

	float RadiansToDegrees(float radians)
	{
		return (radians * 180.0f) / MATH_REAL_PI;
	}

	int SnapToFloor(int input, int gap)
	{
		if (gap == 0)
			return input;

		input = gap * static_cast<int>(floor(input / gap));
		return input;
	}

	Vector3F ToDirection(const Vector3F& vector)
	{
		Matrix4F matrix;
		matrix.Rotate(vector);

		Vector3F direction = matrix.Transform(Vector3F(0.0f, 0.0f, -1.0f));
		return direction;
	}

	int MinI(int t1, int t2)
	{
		return (t1 < t2 ? t1 : t2);
	}

	float MinF(float t1, float t2)
	{
		return (t1 < t2 ? t1 : t2);
	}

	int MaxI(int t1, int t2)
	{
		return (t1 < t2 ? t2 : t1);
	}

	float MaxF(float t1, float t2)
	{
		return (t1 < t2 ? t2 : t1);
	}
}