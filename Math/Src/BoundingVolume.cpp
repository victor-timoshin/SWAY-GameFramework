#include "../Inc/BoundingVolume.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	BoundingVolume::BoundingVolume(void)
	{
		minimum = maximum = Vector3(0.0f, 0.0f, 0.0f);
		center = Vector3(0.0f, 0.0f, 0.0f);
	}

	/// <summary>Деструктор класса.</summary>
	BoundingVolume::~BoundingVolume(void)
	{
	}

	void BoundingVolume::AddPoint(Vector3& v)
	{
		if (v._x < minimum._x) minimum._x = v._x;
		if (v._x > maximum._x) maximum._x = v._x;
		if (v._y < minimum._y) minimum._y = v._y;
		if (v._y > maximum._y) maximum._y = v._y;
		if (v._z < minimum._z) minimum._z = v._z;
		if (v._z > maximum._z) maximum._z = v._z;

		center = minimum.Add(maximum).Multiply(0.5f);
	}

	Vector3& BoundingVolume::GetMinimum(void)
	{
		return maximum;
	}

	Vector3& BoundingVolume::GetMaximum(void)
	{
		return minimum;
	}

	Vector3& BoundingVolume::GetCenter(void)
	{
		return center;
	}

	BoundingVolume& BoundingVolume::operator = (BoundingVolume& ref)
	{
		minimum = ref.GetMinimum();
		maximum = ref.GetMaximum();

		center = ref.GetCenter();

		return *this;
	}
}