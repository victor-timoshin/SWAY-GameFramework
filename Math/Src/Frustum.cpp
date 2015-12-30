#include "../Inc/Frustum.h"
#include "../Inc/MathCommon.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Frustum::Frustum(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Frustum::~Frustum(void)
	{
	}

	/// <summary>Проверяет нахождения бокса в пирамиде видимости.</summary>
	FRUSTUM_ASPECT Frustum::IsBoundingBoxInside(const BoundingBox& box) const
	{
		Vector3F point;

		Vector3F minPoint = box.GetMinPoint();
		Vector3F maxPoint = box.GetMaxPoint();

		for (int i = 0; i < MAX_NUM_FRUSTUM_PLANES; i++)
		{
			const Vec3F& normal = _planes[i].GetNormal();

			point.SetX(normal._x > 0 ? maxPoint.GetX() : minPoint.GetX());
			point.SetY(normal._y > 0 ? maxPoint.GetY() : minPoint.GetY());
			point.SetZ(normal._z > 0 ? maxPoint.GetZ() : minPoint.GetZ());

			if (_planes[i].ClassifyPoint(point) == PlaneF::POINT_BEHIND_PLANE)
				return FRUSTUM_ASPECT::Outside;
		}

		return FRUSTUM_ASPECT::Inside;
	}

	FRUSTUM_ASPECT Frustum::IsPointInside(const Vector3F& point) const
	{
		for (int i = 0; i < MAX_NUM_FRUSTUM_PLANES; i++)
		{
			if (_planes[i].ClassifyPoint(point) == PlaneF::POINT_BEHIND_PLANE)
				return FRUSTUM_ASPECT::Outside;
		}

		return FRUSTUM_ASPECT::Inside;
	}

	void Frustum::Construct(const Matrix4F& viewProjectionMatrix)
	{
		// Правая плоскость.
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Right)].SetDistance(viewProjectionMatrix.Get(3, 3) - viewProjectionMatrix.Get(3, 0));
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Right)].SetNormal(Vector3F(
			viewProjectionMatrix.Get(0, 3) - viewProjectionMatrix.Get(0, 0),
			viewProjectionMatrix.Get(1, 3) - viewProjectionMatrix.Get(1, 0),
			viewProjectionMatrix.Get(2, 3) - viewProjectionMatrix.Get(2, 0)));

		// Левая плоскость.
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Left)].SetDistance(viewProjectionMatrix.Get(3, 3) + viewProjectionMatrix.Get(3, 0));
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Left)].SetNormal(Vector3F(
			viewProjectionMatrix.Get(0, 3) + viewProjectionMatrix.Get(0, 0),
			viewProjectionMatrix.Get(1, 3) + viewProjectionMatrix.Get(1, 0),
			viewProjectionMatrix.Get(2, 3) + viewProjectionMatrix.Get(2, 0)));

		// Нижняя плоскость.
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Bottom)].SetDistance(viewProjectionMatrix.Get(3, 3) + viewProjectionMatrix.Get(3, 1));
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Bottom)].SetNormal(Vector3F(
			viewProjectionMatrix.Get(0, 3) + viewProjectionMatrix.Get(0, 1),
			viewProjectionMatrix.Get(1, 3) + viewProjectionMatrix.Get(1, 1),
			viewProjectionMatrix.Get(2, 3) + viewProjectionMatrix.Get(2, 1)));

		// Верхняя плоскость.
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Top)].SetDistance(viewProjectionMatrix.Get(3, 3) - viewProjectionMatrix.Get(3, 1));
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Top)].SetNormal(Vector3F(
			viewProjectionMatrix.Get(0, 3) - viewProjectionMatrix.Get(0, 1),
			viewProjectionMatrix.Get(1, 3) - viewProjectionMatrix.Get(1, 1),
			viewProjectionMatrix.Get(2, 3) - viewProjectionMatrix.Get(2, 1)));

		// Задняя плоскость.
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Far)].SetDistance(viewProjectionMatrix.Get(3, 3) - viewProjectionMatrix.Get(3, 2));
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Far)].SetNormal(Vector3F(
			viewProjectionMatrix.Get(0, 3) - viewProjectionMatrix.Get(0, 2),
			viewProjectionMatrix.Get(1, 3) - viewProjectionMatrix.Get(1, 2),
			viewProjectionMatrix.Get(2, 3) - viewProjectionMatrix.Get(2, 2)));

		// Передняя плоскость.
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Near)].SetDistance(viewProjectionMatrix.Get(3, 3) + viewProjectionMatrix.Get(3, 2));
		_planes[static_cast<UInt>(FRUSTUM_SIDE::Near)].SetNormal(Vector3F(
			viewProjectionMatrix.Get(0, 3) + viewProjectionMatrix.Get(0, 2),
			viewProjectionMatrix.Get(1, 3) + viewProjectionMatrix.Get(1, 2),
			viewProjectionMatrix.Get(2, 3) + viewProjectionMatrix.Get(2, 2)));

		for (int i = 0; i < MAX_NUM_FRUSTUM_PLANES; i++)
			_planes[i].Normalize();
	}

	const PlaneF& Frustum::GetRight(void) const
	{
		return _planes[static_cast<UInt>(FRUSTUM_SIDE::Right)];
	}

	const PlaneF& Frustum::GetLeft(void) const
	{
		return _planes[static_cast<UInt>(FRUSTUM_SIDE::Left)];
	}

	const PlaneF& Frustum::GetBottom(void) const
	{
		return _planes[static_cast<UInt>(FRUSTUM_SIDE::Bottom)];
	}

	const PlaneF& Frustum::GetTop(void) const
	{
		return _planes[static_cast<UInt>(FRUSTUM_SIDE::Top)];
	}

	const PlaneF& Frustum::GetNear(void) const
	{
		return _planes[static_cast<UInt>(FRUSTUM_SIDE::Near)];
	}

	const PlaneF& Frustum::GetFar(void) const
	{
		return _planes[static_cast<int>(FRUSTUM_SIDE::Far)];
	}
}