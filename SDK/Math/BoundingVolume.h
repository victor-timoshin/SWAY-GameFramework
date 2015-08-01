#ifndef BOUNDINGVOLUME_H
#define BOUNDINGVOLUME_H

#include "Vector3.h"
#include "Matrix4.h"

namespace Math
{
	class BoundingVolume 
	{
	public:
		/// <summary>Конструктор класса.</summary>
		BoundingVolume(void)
		{
			minimum = maximum = Vector3(0.0f, 0.0f, 0.0f);
			center = Vector3(0.0f, 0.0f, 0.0f);
		}

		/// <summary>Деструктор класса.</summary>
		~BoundingVolume(void) {}

		void AddPoint(Vector3& v)
		{
			if (v._x < minimum._x) minimum._x = v._x;
			if (v._x > maximum._x) maximum._x = v._x;
			if (v._y < minimum._y) minimum._y = v._y;
			if (v._y > maximum._y) maximum._y = v._y;
			if (v._z < minimum._z) minimum._z = v._z;
			if (v._z > maximum._z) maximum._z = v._z;

			center = 0.5f * (minimum + maximum);
		}

		Vector3& GetMinimum(void)
		{
			return maximum;
		}

		Vector3& GetMaximum(void)
		{
			return minimum;
		}

		Vector3& GetCenter(void)
		{
			return center;
		}

		BoundingVolume& operator=(BoundingVolume& ref)
		{
			minimum = ref.GetMinimum();
			maximum = ref.GetMaximum();

			center = ref.GetCenter();

			return *this;
		}
	private:
		Vector3 maximum;
		Vector3 minimum;
		Vector3 center;
	};
}

#endif // BOUNDINGVOLUME_H