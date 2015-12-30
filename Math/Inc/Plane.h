#ifndef PLANE_H
#define PLANE_H

#include "Vector3.h"
#include "../../SDK/Platform.h"

namespace Math
{
	template<class T>
	class CORE_API TPlane
	{
	public:
		enum
		{
			POINT_ON_PLANE,
			POINT_BEHIND_PLANE,
			POINT_IN_FRONT_OF_PLANE
		};

		/// <summary>Конструктор класса.</summary>
		TPlane(void) {}

		/// <summary>Конструктор класса.</summary>
		TPlane(const TVector3<T>& normal, T distance)
		{
			_normal = normal;
			_distance = distance;
		}

		/// <summary>Конструктор класса.</summary>
		TPlane(T normalX, T normalY, T normalZ, T distance)
		{
			_normal = TVector3<T>(normalX, normalY, normalZ);
			_distance = distance;
		}

		/// <summary>Деструктор класса.</summary>
		~TPlane(void) {}

		void Normalize(void)
		{
			T magnitude = _normal.Length();

			_normal.Normalize();
			_distance /= magnitude;
		}

		T DistanceToPlane(const TVector3<T>& point) const
		{
			return DotProduct(_normal, point) + _distance;
		}

		int ClassifyPoint(const TVector3<T>& point) const
		{
			T distance = DistanceToPlane(point);
			if (distance < MATH_EPSILON)
				return POINT_BEHIND_PLANE;

			if (distance > MATH_EPSILON)
				return POINT_IN_FRONT_OF_PLANE;

			return POINT_ON_PLANE;
		}

		void SetNormal(const TVector3<T>& normal)
		{
			_normal = normal;
		}

		TVector3<T> GetNormal(void) const
		{
			return _normal;
		}

		void SetDistance(T distance)
		{
			_distance = distance;
		}

		T GetDistance(void) const
		{
			return _distance;
		}

	public:
		TVector3<T> _normal;
		T _distance;
	};

	typedef TPlane<float> PlaneF;
	typedef TPlane<double> PlaneD;
	typedef TPlane<int> PlaneI;
}

#endif // PLANE_H