#ifndef BOUNDINGVOLUME_H
#define BOUNDINGVOLUME_H

#include "Vector3.h"
#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API BoundingVolume
	{
	public:
		/// <summary>Конструктор класса.</summary>
		BoundingVolume(void);

		/// <summary>Деструктор класса.</summary>
		~BoundingVolume(void);

		void AddPoint(Vector3& v);

		Vector3& GetMinimum(void);

		Vector3& GetMaximum(void);

		Vector3& GetCenter(void);

		BoundingVolume& operator=(BoundingVolume& ref);

	public:
		Vector3 maximum;
		Vector3 minimum;
		Vector3 center;
	};
}

#endif // BOUNDINGVOLUME_H