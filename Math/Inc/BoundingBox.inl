#include "BoundingBox.h"

namespace Math
{
	inline bool BoundingBox::operator==(const BoundingBox& other)
	{
		return (_minPoint == other.GetMinPoint() && _maxPoint == other.GetMaxPoint());
	}

	inline bool BoundingBox::operator!=(const BoundingBox& other)
	{
		return (_minPoint != other.GetMinPoint() && _maxPoint != other.GetMaxPoint());
	}

	inline BoundingBox& BoundingBox::operator=(BoundingBox& box)
	{
		if (this == &box)
			return *this;

		_minPoint = box.GetMinPoint();
		_maxPoint = box.GetMaxPoint();

		return *this;
	}
}