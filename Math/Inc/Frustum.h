#ifndef FRUSTUM_H
#define FRUSTUM_H

#include "FrustumSide.h"
#include "FrustumAspect.h"
#include "BoundingBox.h"
#include "Matrix4F.h"
#include "Plane.h"

namespace Math
{
	class CORE_API Frustum
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Frustum(void);

		/// <summary>Деструктор класса.</summary>
		~Frustum(void);

		/// <summary>Проверяет нахождения бокса в пирамиде видимости.</summary>
		FRUSTUM_ASPECT IsBoundingBoxInside(const BoundingBox& box) const;

		FRUSTUM_ASPECT IsPointInside(const Vector3F& point) const;
		
		void Construct(const Matrix4F& viewProjectionMatrix);

		const PlaneF& GetRight(void) const;

		const PlaneF& GetLeft(void) const;

		const PlaneF& GetBottom(void) const;

		const PlaneF& GetTop(void) const;

		const PlaneF& GetNear(void) const;

		const PlaneF& GetFar(void) const;

	private:
		PlaneF _planes[MAX_NUM_FRUSTUM_PLANES];
	};
}

#endif // FRUSTUM_H