#ifndef RAY_H
#define RAY_H

#include "Vector3.h"
#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Ray
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Ray(const Vector3F origin, const Vector3F direction);

		Vector3F GetOrigin(void) const;

		Vector3F GetDirection(void) const;

		std::string ToString(void) const;

	private:
		Vector3F _origin;
		Vector3F _direction;
	};
}

#endif // RAY_H