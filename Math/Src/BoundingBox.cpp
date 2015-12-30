#include "../Inc/MathCommon.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	BoundingBox::BoundingBox(void)
	{
		Reset();
	}

	/// <summary>Конструктор класса.</summary>
	BoundingBox::BoundingBox(const Vector3F& min, const Vector3F& max)
	{
		Set(min, max);
	}

	/// <summary>Конструктор класса.</summary>
	BoundingBox::BoundingBox(const BoundingBox& copy)
	{
		Set(copy.GetMinPoint(), copy.GetMaxPoint());
	}

	/// <summary>Деструктор класса.</summary>
	BoundingBox::~BoundingBox(void)
	{
	}

	void BoundingBox::Set(const Vector3F& min, const Vector3F& max)
	{
		_minPoint = min;
		_maxPoint = max;
	}

	void BoundingBox::Reset(void)
	{
		_maxPoint.Set(-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max(), -std::numeric_limits<float>::max());
		_minPoint.Set( std::numeric_limits<float>::max(),  std::numeric_limits<float>::max(),  std::numeric_limits<float>::max());

		_first = true;
	}

	void BoundingBox::Include(const Vector3F& point)
	{
		Include(point.GetX(), point.GetY(), point.GetZ());
	}

	void BoundingBox::Include(float x, float y, float z)
	{
		if (_first)
		{
			_minPoint = Vec3F(x, y, z);
			_maxPoint = Vec3F(x, y, z);

			_first = false;

			return;
		}

		if (x < _minPoint.GetX()) _minPoint.SetX(x);
		if (y < _minPoint.GetY()) _minPoint.SetY(y);
		if (z < _minPoint.GetZ()) _minPoint.SetZ(z);

		if (x > _maxPoint.GetX()) _maxPoint.SetX(x);
		if (y > _maxPoint.GetY()) _maxPoint.SetY(y);
		if (z > _maxPoint.GetZ()) _maxPoint.SetZ(z);
	}

	void BoundingBox::Transform(const Matrix4F& transform)
	{
		const float tempMin[3] = { _minPoint._x, _minPoint._y, _minPoint._z };
		const float tempMax[3] = { _maxPoint._x, _maxPoint._y, _maxPoint._z };

		float newMin[3];
		float newMax[3];

		newMin[0] = newMax[0] = transform.Get(3, 0);
		newMin[1] = newMax[1] = transform.Get(3, 1);
		newMin[2] = newMax[2] = transform.Get(3, 2);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				float a = transform(i, j) * tempMin[j];
				float b = transform(i, j) * tempMax[j];
				if (a < b)
				{
					newMin[i] += a;
					newMax[i] += b;
				}
				else
				{
					newMin[i] += b;
					newMax[i] += a;
				}
			}
		}

		_minPoint._x = newMin[0];
		_minPoint._y = newMin[1];
		_minPoint._z = newMin[2];

		_maxPoint._x = newMax[0];
		_maxPoint._y = newMax[1];
		_maxPoint._z = newMax[2];
	}

	bool BoundingBox::IsIntersect(const BoundingBox& box) const
	{
		if (_maxPoint._x < box._minPoint._x || _minPoint._x > box._maxPoint._x)
			return false;
		if (_maxPoint._y < box._minPoint._y || _minPoint._y > box._maxPoint._y)
			return false;
		if (_maxPoint._z < box._minPoint._z || _minPoint._z > box._maxPoint._z)
			return false;

		return true;
	}

	void BoundingBox::GetCorners(Vector3F* dst) const
	{
		dst[0].Set(_maxPoint._x, _maxPoint._y, _maxPoint._z);
		dst[1].Set(_maxPoint._x, _maxPoint._y, _minPoint._z);
		dst[2].Set(_minPoint._x, _maxPoint._y, _minPoint._z);
		dst[3].Set(_minPoint._x, _maxPoint._y, _maxPoint._z);

		dst[4].Set(_maxPoint._x, _minPoint._y, _maxPoint._z);
		dst[5].Set(_maxPoint._x, _minPoint._y, _minPoint._z);
		dst[6].Set(_minPoint._x, _minPoint._y, _minPoint._z);
		dst[7].Set(_minPoint._x, _minPoint._y, _maxPoint._z);
	}

	Vec3F BoundingBox::GetCornerPoint(int index) const
	{
		switch (index)
		{
		default:
		case 0: return Vec3F(_maxPoint._x, _maxPoint._y, _maxPoint._z);
		case 1: return Vec3F(_maxPoint._x, _maxPoint._y, _minPoint._z);
		case 2: return Vec3F(_minPoint._x, _maxPoint._y, _minPoint._z);
		case 3: return Vec3F(_minPoint._x, _maxPoint._y, _maxPoint._z);

		case 4: return Vec3F(_maxPoint._x, _minPoint._y, _maxPoint._z);
		case 5: return Vec3F(_maxPoint._x, _minPoint._y, _minPoint._z);
		case 6: return Vec3F(_minPoint._x, _minPoint._y, _minPoint._z);
		case 7: return Vec3F(_minPoint._x, _minPoint._y, _maxPoint._z);
		}
	}

	Vector3F BoundingBox::GetMinPoint(void) const
	{
		return _minPoint;
	}

	Vector3F BoundingBox::GetMaxPoint(void) const
	{
		return _maxPoint;
	}

	float BoundingBox::GetWidth(void) const
	{
		return _maxPoint._x - _minPoint._x;
	}

	float BoundingBox::GetHeight(void) const
	{
		return _maxPoint._y - _minPoint._y;
	}

	float BoundingBox::GetDepth(void) const
	{
		return _maxPoint._z - _minPoint._z;
	}

	Vector3F BoundingBox::GetCenter(void) const
	{
		Vector3F center;
		center._x = 0.5f * (_minPoint._x + _maxPoint._x);
		center._y = 0.5f * (_minPoint._y + _maxPoint._y);
		center._z = 0.5f * (_minPoint._z + _maxPoint._z);

		return center;
	}

	float BoundingBox::GetVolume(void) const
	{
		const Vector3F extent = GetExtent();
		return extent._x * extent._y * extent._z;
	}

	float BoundingBox::GetArea(void) const
	{
		const Vector3F extent = GetExtent();
		return 2.0f * (extent._x * extent._y + extent._x * extent._z + extent._y * extent._z);
	}

	Vector3F BoundingBox::GetExtent(void) const
	{
		return _maxPoint - _minPoint;
	}

	bool BoundingBox::IsEmpty(void) const
	{
		return _maxPoint == _minPoint;
	}
}