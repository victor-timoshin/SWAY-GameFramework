#include "../Inc/Ray.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Ray::Ray(const Vector3F origin, const Vector3F direction)
	{
		_origin = origin;
		_direction = direction;
	}

	Vector3F Ray::GetOrigin(void) const
	{
		return _origin;
	}

	Vector3F Ray::GetDirection(void) const
	{
		return _direction;
	}

	std::string Ray::ToString(void) const
	{
		std::ostringstream stream;
		stream << "Ray[origin=" << _origin.ToString() << ", direction=" << _direction.ToString() << "]";
		return stream.str();
	}
}