#include "../Inc/MathCommon.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Matrix4F::Matrix4F(void)
	{
		SetIdentity();
	}

	/// <summary>Конструктор класса.</summary>
	/// <param name="m00">Component in column 0, row 0 position (index 0).</param>
	/// <param name="m01">Component in column 0, row 1 position (index 1).</param>
	/// <param name="m02">Component in column 0, row 2 position (index 2).</param>
	/// <param name="m03">Component in column 0, row 3 position (index 3).</param>
	/// <param name="m10">Component in column 1, row 0 position (index 4).</param>
	/// <param name="m11">Component in column 1, row 1 position (index 5).</param>
	/// <param name="m12">Component in column 1, row 2 position (index 6).</param>
	/// <param name="m13">Component in column 1, row 3 position (index 7).</param>
	/// <param name="m20">Component in column 2, row 0 position (index 8).</param>
	/// <param name="m21">Component in column 2, row 1 position (index 9).</param>
	/// <param name="m22">Component in column 2, row 2 position (index 10).</param>
	/// <param name="m23">Component in column 2, row 3 position (index 11).</param>
	/// <param name="m30">Component in column 3, row 0 position (index 12).</param>
	/// <param name="m31">Component in column 3, row 1 position (index 13).</param>
	/// <param name="m32">Component in column 3, row 2 position (index 14).</param>
	/// <param name="m33">Component in column 3, row 3 position (index 15).</param>
	Matrix4F::Matrix4F(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
	{
		Set(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33);
	}

	/// <summary>Устанавливает значения матрицы.</summary>
	/// <param name="m00">Component in column 0, row 0 position (index 0).</param>
	/// <param name="m01">Component in column 0, row 1 position (index 1).</param>
	/// <param name="m02">Component in column 0, row 2 position (index 2).</param>
	/// <param name="m03">Component in column 0, row 3 position (index 3).</param>
	/// <param name="m10">Component in column 1, row 0 position (index 4).</param>
	/// <param name="m11">Component in column 1, row 1 position (index 5).</param>
	/// <param name="m12">Component in column 1, row 2 position (index 6).</param>
	/// <param name="m13">Component in column 1, row 3 position (index 7).</param>
	/// <param name="m20">Component in column 2, row 0 position (index 8).</param>
	/// <param name="m21">Component in column 2, row 1 position (index 9).</param>
	/// <param name="m22">Component in column 2, row 2 position (index 10).</param>
	/// <param name="m23">Component in column 2, row 3 position (index 11).</param>
	/// <param name="m30">Component in column 3, row 0 position (index 12).</param>
	/// <param name="m31">Component in column 3, row 1 position (index 13).</param>
	/// <param name="m32">Component in column 3, row 2 position (index 14).</param>
	/// <param name="m33">Component in column 3, row 3 position (index 15).</param>
	void Matrix4F::Set(
		float m00, float m01, float m02, float m03, 
		float m10, float m11, float m12, float m13, 
		float m20, float m21, float m22, float m23, 
		float m30, float m31, float m32, float m33)
	{
		_values[0]  = m00; _values[1]  = m10; _values[2]  = m20; _values[3]  = m30;
		_values[4]  = m01; _values[5]  = m11; _values[6]  = m21; _values[7]  = m31;
		_values[8]  = m02; _values[9]  = m12; _values[10] = m22; _values[11] = m32;
		_values[12] = m03; _values[13] = m13; _values[14] = m23; _values[15] = m33;
	}

	/// <summary>Устанавливает значения матрицы.</summary>
	void Matrix4F::Set(const float* matrix)
	{
		memcpy(_values, matrix, MATRIX_SIZE);
	}

	/// <summary>Устанавливает значения матрицы.</summary>
	void Matrix4F::Set(const Matrix4F& matrix)
	{
		memcpy(_values, matrix._values, MATRIX_SIZE);
	}

	void Matrix4F::Set(int row, int col, float value)
	{
		operator()(row, col) = value;
	}

	float Matrix4F::Get(int row, int col) const
	{
		return _values[row * 4 + col];
	}

	bool Matrix4F::Invert(Matrix4F* dst) const
	{
		float a0 = _values[0] * _values[5] - _values[1] * _values[4];
		float a1 = _values[0] * _values[6] - _values[2] * _values[4];
		float a2 = _values[0] * _values[7] - _values[3] * _values[4];
		float a3 = _values[1] * _values[6] - _values[2] * _values[5];
		float a4 = _values[1] * _values[7] - _values[3] * _values[5];
		float a5 = _values[2] * _values[7] - _values[3] * _values[6];
		float b0 = _values[8] * _values[13] - _values[9] * _values[12];
		float b1 = _values[8] * _values[14] - _values[10] * _values[12];
		float b2 = _values[8] * _values[15] - _values[11] * _values[12];
		float b3 = _values[9] * _values[14] - _values[10] * _values[13];
		float b4 = _values[9] * _values[15] - _values[11] * _values[13];
		float b5 = _values[10] * _values[15] - _values[11] * _values[14];

		float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

		if (fabs(det) <= MATH_TOLERANCE)
			return false;

		Matrix4F inverse;
		inverse.Set(0, 0, _values[5] * b5 - _values[6] * b4 + _values[7] * b3);
		inverse.Set(0, 1, -_values[1] * b5 + _values[2] * b4 - _values[3] * b3);
		inverse.Set(0, 2, _values[13] * a5 - _values[14] * a4 + _values[15] * a3);
		inverse.Set(0, 3, -_values[9] * a5 + _values[10] * a4 - _values[11] * a3);

		inverse.Set(1, 0, -_values[4] * b5 + _values[6] * b2 - _values[7] * b1);
		inverse.Set(1, 1, _values[0] * b5 - _values[2] * b2 + _values[3] * b1);
		inverse.Set(1, 2, -_values[12] * a5 + _values[14] * a2 - _values[15] * a1);
		inverse.Set(1, 3, _values[8] * a5 - _values[10] * a2 + _values[11] * a1);

		inverse.Set(2, 0, _values[4] * b4 - _values[5] * b2 + _values[7] * b0);
		inverse.Set(2, 1, -_values[0] * b4 + _values[1] * b2 - _values[3] * b0);
		inverse.Set(2, 2, _values[12] * a4 - _values[13] * a2 + _values[15] * a0);
		inverse.Set(2, 3, -_values[8] * a4 + _values[9] * a2 - _values[11] * a0);

		inverse.Set(3, 0, -_values[4] * b3 + _values[5] * b1 - _values[6] * b0);
		inverse.Set(3, 1, _values[0] * b3 - _values[1] * b1 + _values[2] * b0);
		inverse.Set(3, 2, -_values[12] * a3 + _values[13] * a1 - _values[14] * a0);
		inverse.Set(3, 3, _values[8] * a3 - _values[9] * a1 + _values[10] * a0);

		Multiply(inverse, 1.0f / det, dst);

		return true;
	}

	/// <summary>Приводит к единичной матрице.</summary>
	void Matrix4F::SetIdentity(void)
	{
		Set(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	}

	bool Matrix4F::IsIdentity(void) const
	{
		return memcmp(_values, MATRIX_IDENTITY, MATRIX_SIZE) == 0;
	}

	void Matrix4F::SetZero(void)
	{
		Set(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	}

	bool Matrix4F::Compare(const Matrix4F& m1, const Matrix4F& m2)
	{
		for (int i = 0; i < 16; i++)
		{
			if (m1._values[i] != m2._values[i])
				return false;
		}

		return true;
	}

	void Matrix4F::Perspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane)
	{
		//float height = 1.0f / tanf((fieldOfView * (MATH_REAL_PI / 180.0f)) * 0.5f);
		//float width = height / aspectRatio;

		//_values[0] = 2.0f * nearPlane / height;
		//_values[5] = 2.0f * nearPlane / width;
		//_values[10] = farPlane / (nearPlane - farPlane);
		//_values[11] = -1.0f;
		//_values[14] = nearPlane * farPlane / (nearPlane - farPlane);

		_values[0] = (float)(1 / tan(fieldOfView / 2)) / aspectRatio;
		_values[5] = (float)(1 / tan(fieldOfView / 2));
		_values[10] = (nearPlane + farPlane) / (nearPlane - farPlane);
		_values[11] = -1;
		_values[14] = (2 * nearPlane * farPlane) / (nearPlane - farPlane);
		_values[15] = 0;
	}

	void Matrix4F::Orthographic(float width, float height, float nearPlane, float farPlane)
	{
		float halfWidth = width / 2.0f;
		float halfHeight = height / 2.0f;

		OrthographicOffCenter(-halfWidth, -halfWidth, halfHeight, halfHeight, nearPlane, farPlane);
	}

	void Matrix4F::OrthographicOffCenter(float left, float top, float right, float bottom, float nearPlane, float farPlane)
	{
		_values[0] = 2.0f / (right - left);
		_values[5] = 2.0f / (top - bottom);
		_values[10] = -2.0f / (farPlane - nearPlane);
		_values[12] = -(right + left) / (right - left);
		_values[13] = -(top + bottom) / (top - bottom);
		_values[14] = -(farPlane + nearPlane) / (farPlane - nearPlane);
	}

	Vector3F Matrix4F::Transform(const Vector3F& vector) const
	{
		Vector3F dest;
		dest.SetX(_values[0] * vector._x + _values[4] * vector._y + _values[8] * vector._z);
		dest.SetY(_values[1] * vector._x + _values[5] * vector._y + _values[9] * vector._z);
		dest.SetZ(_values[2] * vector._x + _values[6] * vector._y + _values[10] * vector._z);

		return dest;
	}

	void Matrix4F::Rotate(float x, float y, float z, float angle)
	{
		float c = cos(angle);
		float s = sin(angle);
		float ic = 1 - c;

		float f0  = _values[0] * ((x * x * ic) + c) + _values[4] * ((x * y * ic) + (z * s)) + _values[8]  * ((x * z * ic) - (y * s));
		float f1  = _values[1] * ((x * x * ic) + c) + _values[5] * ((x * y * ic) + (z * s)) + _values[9]  * ((x * z * ic) - (y * s));
		float f2  = _values[2] * ((x * x * ic) + c) + _values[6] * ((x * y * ic) + (z * s)) + _values[10] * ((x * z * ic) - (y * s));
		float f3  = _values[3] * ((x * x * ic) + c) + _values[7] * ((x * y * ic) + (z * s)) + _values[11] * ((x * z * ic) - (y * s));

		float f4  = _values[0] * ((x * y * ic) - (z * s)) + _values[4] * ((y * y * ic) + c) + _values[8]  * ((y * z * ic) + (x * s));
		float f5  = _values[1] * ((x * y * ic) - (z * s)) + _values[5] * ((y * y * ic) + c) + _values[9]  * ((y * z * ic) + (x * s));
		float f6  = _values[2] * ((x * y * ic) - (z * s)) + _values[6] * ((y * y * ic) + c) + _values[10] * ((y * z * ic) + (x * s));
		float f7  = _values[3] * ((x * y * ic) - (z * s)) + _values[7] * ((y * y * ic) + c) + _values[11] * ((y * z * ic) + (x * s));

		float f8  = _values[0] * ((x * z * ic) + (y * s)) + _values[4] * ((y * z * ic) - (x * s)) + _values[8]  * ((z * z * ic) + c);
		float f9  = _values[1] * ((x * z * ic) + (y * s)) + _values[5] * ((y * z * ic) - (x * s)) + _values[9]  * ((z * z * ic) + c);
		float f10 = _values[2] * ((x * z * ic) + (y * s)) + _values[6] * ((y * z * ic) - (x * s)) + _values[10] * ((z * z * ic) + c);
		float f11 = _values[3] * ((x * z * ic) + (y * s)) + _values[7] * ((y * z * ic) - (x * s)) + _values[11] * ((z * z * ic) + c);

		_values[0] = f0; _values[1] = f1; _values[2]  = f2;  _values[3]  = f3;
		_values[4] = f4; _values[5] = f5; _values[6]  = f6;  _values[7]  = f7;
		_values[8] = f8; _values[9] = f9; _values[10] = f10; _values[11] = f11;
	}

	void Matrix4F::Rotate(const Vector3F& euler)
	{
		Rotate(0, 1, 0, euler.GetY());
		Rotate(1, 0, 0, euler.GetX());
		//Rotate(0, 0, 1, euler.GetZ());
	}

	void Matrix4F::Subtract(const Matrix4F& m)
	{
		Subtract(*this, m, this);
	}

	void Matrix4F::Subtract(const Matrix4F& m1, const Matrix4F& m2, Matrix4F* dst)
	{
		dst->Set(0, 0, m1._values[0] - m2._values[0]);
		dst->Set(0, 1, m1._values[1] - m2._values[1]);
		dst->Set(0, 2, m1._values[2] - m2._values[2]);
		dst->Set(0, 3, m1._values[3] - m2._values[3]);

		dst->Set(1, 0, m1._values[4] - m2._values[4]);
		dst->Set(1, 1, m1._values[5] - m2._values[5]);
		dst->Set(1, 2, m1._values[6] - m2._values[6]);
		dst->Set(1, 3, m1._values[7] - m2._values[7]);

		dst->Set(2, 0, m1._values[8] - m2._values[8]);
		dst->Set(2, 1, m1._values[9] - m2._values[9]);
		dst->Set(2, 2, m1._values[10] - m2._values[10]);
		dst->Set(2, 3, m1._values[11] - m2._values[11]);

		dst->Set(3, 0, m1._values[12] - m2._values[12]);
		dst->Set(3, 1, m1._values[13] - m2._values[13]);
		dst->Set(3, 2, m1._values[14] - m2._values[14]);
		dst->Set(3, 3, m1._values[15] - m2._values[15]);
	}

	void Matrix4F::Add(float scalar)
	{
		Add(*this, scalar, this);
	}

	void Matrix4F::Add(const Matrix4F& m, float scalar, Matrix4F* dst)
	{
		dst->Set(0, 0, m._values[0] + scalar);
		dst->Set(0, 1, m._values[1] + scalar);
		dst->Set(0, 2, m._values[2] + scalar);
		dst->Set(0, 3, m._values[3] + scalar);

		dst->Set(1, 0, m._values[4] + scalar);
		dst->Set(1, 1, m._values[5] + scalar);
		dst->Set(1, 2, m._values[6] + scalar);
		dst->Set(1, 3, m._values[7] + scalar);

		dst->Set(2, 0, m._values[8] + scalar);
		dst->Set(2, 1, m._values[9] + scalar);
		dst->Set(2, 2, m._values[10] + scalar);
		dst->Set(2, 3, m._values[11] + scalar);

		dst->Set(3, 0, m._values[12] + scalar);
		dst->Set(3, 1, m._values[13] + scalar);
		dst->Set(3, 2, m._values[14] + scalar);
		dst->Set(3, 3, m._values[15] + scalar);
	}

	void Matrix4F::Add(const Matrix4F& m)
	{
		Add(*this, m, this);
	}

	void Matrix4F::Add(const Matrix4F& m1, const Matrix4F& m2, Matrix4F* dst)
	{
		dst->Set(0, 0, m1._values[0] + m2._values[0]);
		dst->Set(0, 1, m1._values[1] + m2._values[1]);
		dst->Set(0, 2, m1._values[2] + m2._values[2]);
		dst->Set(0, 3, m1._values[3] + m2._values[3]);

		dst->Set(1, 0, m1._values[4] + m2._values[4]);
		dst->Set(1, 1, m1._values[5] + m2._values[5]);
		dst->Set(1, 2, m1._values[6] + m2._values[6]);
		dst->Set(1, 3, m1._values[7] + m2._values[7]);
		
		dst->Set(2, 0, m1._values[8] + m2._values[8]);
		dst->Set(2, 1, m1._values[9] + m2._values[9]);
		dst->Set(2, 2, m1._values[10] + m2._values[10]);
		dst->Set(2, 3, m1._values[11] + m2._values[11]);
		
		dst->Set(3, 0, m1._values[12] + m2._values[12]);
		dst->Set(3, 1, m1._values[13] + m2._values[13]);
		dst->Set(3, 2, m1._values[14] + m2._values[14]);
		dst->Set(3, 3, m1._values[15] + m2._values[15]);
	}

	void Matrix4F::Negate(void)
	{
		Negate(this);
	}

	void Matrix4F::Negate(Matrix4F* dst) const
	{
		dst->_values[0] = -_values[0];
		dst->_values[1] = -_values[1];
		dst->_values[2] = -_values[2];
		dst->_values[3] = -_values[3];
		dst->_values[4] = -_values[4];
		dst->_values[5] = -_values[5];
		dst->_values[6] = -_values[6];
		dst->_values[7] = -_values[7];
		dst->_values[8] = -_values[8];
		dst->_values[9] = -_values[9];
		dst->_values[10] = -_values[10];
		dst->_values[11] = -_values[11];
		dst->_values[12] = -_values[12];
		dst->_values[13] = -_values[13];
		dst->_values[14] = -_values[14];
		dst->_values[15] = -_values[15];
	}

	void Matrix4F::Multiply(float scalar)
	{
		Multiply(*this, scalar, this);
	}

	void Matrix4F::Multiply(const Matrix4F& m, float scalar, Matrix4F* dst)
	{
		dst->Set(0, 0, m._values[0] * scalar);
		dst->Set(0, 1, m._values[1] * scalar);
		dst->Set(0, 2, m._values[2] * scalar);
		dst->Set(0, 3, m._values[3] * scalar);

		dst->Set(1, 0, m._values[4] * scalar);
		dst->Set(1, 1, m._values[5] * scalar);
		dst->Set(1, 2, m._values[6] * scalar);
		dst->Set(1, 3, m._values[7] * scalar);
		
		dst->Set(2, 0, m._values[8] * scalar);
		dst->Set(2, 1, m._values[9] * scalar);
		dst->Set(2, 2, m._values[10] * scalar);
		dst->Set(2, 3, m._values[11] * scalar);
		
		dst->Set(3, 0, m._values[12] * scalar);
		dst->Set(3, 1, m._values[13] * scalar);
		dst->Set(3, 2, m._values[14] * scalar);
		dst->Set(3, 3, m._values[15] * scalar);
	}

	void Matrix4F::Multiply(const Matrix4F& m)
	{
		Multiply(*this, m, this);
	}

	void Matrix4F::Multiply(const Matrix4F& m1, const Matrix4F& m2, Matrix4F* dst)
	{
		float product[16];

		product[0] = m1._values[0] * m2._values[0] + m1._values[4] * m2._values[1] + m1._values[8] * m2._values[2] + m1._values[12] * m2._values[3];
		product[1] = m1._values[1] * m2._values[0] + m1._values[5] * m2._values[1] + m1._values[9] * m2._values[2] + m1._values[13] * m2._values[3];
		product[2] = m1._values[2] * m2._values[0] + m1._values[6] * m2._values[1] + m1._values[10] * m2._values[2] + m1._values[14] * m2._values[3];
		product[3] = m1._values[3] * m2._values[0] + m1._values[7] * m2._values[1] + m1._values[11] * m2._values[2] + m1._values[15] * m2._values[3];

		product[4] = m1._values[0] * m2._values[4] + m1._values[4] * m2._values[5] + m1._values[8] * m2._values[6] + m1._values[12] * m2._values[7];
		product[5] = m1._values[1] * m2._values[4] + m1._values[5] * m2._values[5] + m1._values[9] * m2._values[6] + m1._values[13] * m2._values[7];
		product[6] = m1._values[2] * m2._values[4] + m1._values[6] * m2._values[5] + m1._values[10] * m2._values[6] + m1._values[14] * m2._values[7];
		product[7] = m1._values[3] * m2._values[4] + m1._values[7] * m2._values[5] + m1._values[11] * m2._values[6] + m1._values[15] * m2._values[7];

		product[8] = m1._values[0] * m2._values[8] + m1._values[4] * m2._values[9] + m1._values[8] * m2._values[10] + m1._values[12] * m2._values[11];
		product[9] = m1._values[1] * m2._values[8] + m1._values[5] * m2._values[9] + m1._values[9] * m2._values[10] + m1._values[13] * m2._values[11];
		product[10] = m1._values[2] * m2._values[8] + m1._values[6] * m2._values[9] + m1._values[10] * m2._values[10] + m1._values[14] * m2._values[11];
		product[11] = m1._values[3] * m2._values[8] + m1._values[7] * m2._values[9] + m1._values[11] * m2._values[10] + m1._values[15] * m2._values[11];

		product[12] = m1._values[0] * m2._values[12] + m1._values[4] * m2._values[13] + m1._values[8] * m2._values[14] + m1._values[12] * m2._values[15];
		product[13] = m1._values[1] * m2._values[12] + m1._values[5] * m2._values[13] + m1._values[9] * m2._values[14] + m1._values[13] * m2._values[15];
		product[14] = m1._values[2] * m2._values[12] + m1._values[6] * m2._values[13] + m1._values[10] * m2._values[14] + m1._values[14] * m2._values[15];
		product[15] = m1._values[3] * m2._values[12] + m1._values[7] * m2._values[13] + m1._values[11] * m2._values[14] + m1._values[15] * m2._values[15];

		memcpy(dst->_values, product, MATRIX_SIZE);
	}
}