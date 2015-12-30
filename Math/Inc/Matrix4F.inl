#include "Matrix4F.h"

namespace Math
{
	inline const Matrix4F Matrix4F::operator+(const Matrix4F& matrix) const
	{
		Matrix4F result(*this);
		result.Add(matrix);
		return result;
	}

	inline Matrix4F& Matrix4F::operator+=(const Matrix4F& matrix)
	{
		Add(matrix);
		return *this;
	}

	inline const Matrix4F Matrix4F::operator-(const Matrix4F& matrix) const
	{
		Matrix4F result(*this);
		result.Subtract(matrix);
		return result;
	}

	inline Matrix4F& Matrix4F::operator-=(const Matrix4F& matrix)
	{
		Subtract(matrix);
		return *this;
	}

	inline const Matrix4F Matrix4F::operator-() const
	{
		Matrix4F result(*this);
		result.Negate();
		return result;
	}

	inline const Matrix4F Matrix4F::operator*(const Matrix4F& matrix) const
	{
		Matrix4F result(*this);
		result.Multiply(matrix);
		return result;
	}

	inline Matrix4F& Matrix4F::operator*=(const Matrix4F& matrix)
	{
		Multiply(matrix);
		return *this;
	}

	inline float& Matrix4F::operator()(int row, int column)
	{
		return _values[row * 4 + column];
	}

	inline float Matrix4F::operator()(int row, int column) const
	{
		return Get(row, column);
	}

	inline Matrix4F::operator const Matrix4F& () const
	{
		return *static_cast<const Matrix4F*>(this);
	}

	inline Matrix4F::operator Matrix4F& ()
	{
		return *static_cast<Matrix4F*>(this);
	}
}