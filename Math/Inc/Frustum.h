#ifndef FRUSTUM_H
#define FRUSTUM_H

#include "BoundingVolume.h"
#include "Matrix4.h"

namespace Math
{
	typedef struct PlaneDataDesc
	{
		float _a;
		float _b;
		float _c;
		float _d;
	} LPLANEDATA_DESC, PPLANEDATA_DESC;

	class CORE_API Frustum
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Frustum(void);

		/// <summary>Деструктор класса.</summary>
		~Frustum(void);

		bool ContainsBoundingVolume(Math::BoundingVolume& box, Math::Vector3& position);

		void Generate(const Math::Matrix4& viewMatrix, const Math::Matrix4& projectionMatrix);

	protected:
		void NormalizePlane(LPLANEDATA_DESC& plane);

	private:
		LPLANEDATA_DESC planes[6];
	};
}

#endif // FRUSTUM_H