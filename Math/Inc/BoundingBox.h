#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include "Vector3.h"
#include "../../SDK/Platform.h"

#include <list>

namespace Math
{
	class Matrix4F;
	class CORE_API BoundingBox
	{
	public:
		/// <summary>Конструктор класса.</summary>
		BoundingBox(void);

		/// <summary>Конструктор класса.</summary>
		BoundingBox(const Vector3F& min, const Vector3F& max);

		/// <summary>Конструктор класса.</summary>
		BoundingBox(const BoundingBox& copy);

		/// <summary>Деструктор класса.</summary>
		~BoundingBox(void);

		void Set(const Vector3F& min, const Vector3F& max);

		void Reset(void);

		void Include(const Vector3F& point);

		void Include(float x, float y, float z);

		void Transform(const Matrix4F& matrix);

		bool IsIntersect(const BoundingBox& box) const;

		void GetCorners(Vector3F* dst) const;

		Vec3F GetCornerPoint(int index) const;

		Vector3F GetMinPoint(void) const;

		Vector3F GetMaxPoint(void) const;

		Vector3F GetCenter(void) const;

		float GetVolume(void) const;

		float GetArea(void) const;

		Vector3F GetExtent(void) const;

		float GetWidth(void) const;

		float GetHeight(void) const;

		float GetDepth(void) const;

		bool IsEmpty(void) const;

		bool operator==(const BoundingBox& other);

		bool operator!=(const BoundingBox& other);

		BoundingBox& operator=(BoundingBox& box);

	public:
		Vector3F _maxPoint; // Максимальная точка.
		Vector3F _minPoint; // Минимальная точка.

		bool _first;
	};
}

#include "BoundingBox.inl"

#endif // BOUNDINGBOX_H