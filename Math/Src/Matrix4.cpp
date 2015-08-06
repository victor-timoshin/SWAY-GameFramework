#include "../Inc/Matrix4.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Matrix4::Matrix4(void)
	{
	}

	/// <summary>Конструктор класса.</summary>
	Matrix4::Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23,
		float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
	{
		matrix[0][0] = m11, matrix[0][1] = m12, matrix[0][2] = m13, matrix[0][3] = m14;
		matrix[1][0] = m21, matrix[1][1] = m22, matrix[1][2] = m23, matrix[1][3] = m24;
		matrix[2][0] = m31, matrix[2][1] = m32, matrix[2][2] = m33, matrix[2][3] = m34;
		matrix[3][0] = m41, matrix[3][1] = m42, matrix[3][2] = m43, matrix[3][3] = m44;
	}

	float* Matrix4::operator [] (int i)
	{
		return matrix[i];
	}

	/// <summary>Приводит к единичной матрице.</summary>
	void Matrix4::Identity(void)
	{
		matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
		matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
		matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
		matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
	}

	/// <summary>Инверсирует матрицу.</summary>
	Matrix4 Matrix4::Inverse(void) const
	{
		Matrix4 result;

		float m00 = matrix[0][0], m01 = matrix[0][1], m02 = matrix[0][2], m03 = matrix[0][3];
		float m10 = matrix[1][0], m11 = matrix[1][1], m12 = matrix[1][2], m13 = matrix[1][3];
		float m20 = matrix[2][0], m21 = matrix[2][1], m22 = matrix[2][2], m23 = matrix[2][3];
		float m30 = matrix[3][0], m31 = matrix[3][1], m32 = matrix[3][2], m33 = matrix[3][3];

		float v0 = m20 * m31 - m21 * m30;
		float v1 = m20 * m32 - m22 * m30;
		float v2 = m20 * m33 - m23 * m30;
		float v3 = m21 * m32 - m22 * m31;
		float v4 = m21 * m33 - m23 * m31;
		float v5 = m22 * m33 - m23 * m32;

		float t00 = +(v5 * m11 - v4 * m12 + v3 * m13);
		float t10 = -(v5 * m10 - v2 * m12 + v1 * m13);
		float t20 = +(v4 * m10 - v2 * m11 + v0 * m13);
		float t30 = -(v3 * m10 - v1 * m11 + v0 * m12);

		float invDet = 1 / (t00 * m00 + t10 * m01 + t20 * m02 + t30 * m03);

		result[0][0] = t00 * invDet;
		result[1][0] = t10 * invDet;
		result[2][0] = t20 * invDet;
		result[3][0] = t30 * invDet;

		result[0][1] = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		result[1][1] = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		result[2][1] = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		result[3][1] = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		v0 = m10 * m31 - m11 * m30;
		v1 = m10 * m32 - m12 * m30;
		v2 = m10 * m33 - m13 * m30;
		v3 = m11 * m32 - m12 * m31;
		v4 = m11 * m33 - m13 * m31;
		v5 = m12 * m33 - m13 * m32;

		result[0][2] = +(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		result[1][2] = -(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		result[2][2] = +(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		result[3][2] = -(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		v0 = m21 * m10 - m20 * m11;
		v1 = m22 * m10 - m20 * m12;
		v2 = m23 * m10 - m20 * m13;
		v3 = m22 * m11 - m21 * m12;
		v4 = m23 * m11 - m21 * m13;
		v5 = m23 * m12 - m22 * m13;

		result[0][3] = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
		result[1][3] = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
		result[2][3] = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
		result[3][3] = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

		return result;
	}

	Matrix4& Matrix4::operator *= (const Matrix4& m)
	{
		*this = Multiply(m);
		return *this;
	}

	Matrix4 Matrix4::operator * (const Matrix4& m) const
	{
		return Multiply(m);
	}

	/// <summary>Умножает данную матрицу на другую указанную матрицу.</summary>
	Matrix4 Matrix4::Multiply(const Matrix4& m) const
	{
		Matrix4 result;

		result.matrix[0][0] = (matrix[0][0] * m.matrix[0][0]) + (matrix[0][1] * m.matrix[1][0]) + (matrix[0][2] * m.matrix[2][0]) + (matrix[0][3] * m.matrix[3][0]);
		result.matrix[0][1] = (matrix[0][0] * m.matrix[0][1]) + (matrix[0][1] * m.matrix[1][1]) + (matrix[0][2] * m.matrix[2][1]) + (matrix[0][3] * m.matrix[3][1]);
		result.matrix[0][2] = (matrix[0][0] * m.matrix[0][2]) + (matrix[0][1] * m.matrix[1][2]) + (matrix[0][2] * m.matrix[2][2]) + (matrix[0][3] * m.matrix[3][2]);
		result.matrix[0][3] = (matrix[0][0] * m.matrix[0][3]) + (matrix[0][1] * m.matrix[1][3]) + (matrix[0][2] * m.matrix[2][3]) + (matrix[0][3] * m.matrix[3][3]);

		result.matrix[1][0] = (matrix[1][0] * m.matrix[0][0]) + (matrix[1][1] * m.matrix[1][0]) + (matrix[1][2] * m.matrix[2][0]) + (matrix[1][3] * m.matrix[3][0]);
		result.matrix[1][1] = (matrix[1][0] * m.matrix[0][1]) + (matrix[1][1] * m.matrix[1][1]) + (matrix[1][2] * m.matrix[2][1]) + (matrix[1][3] * m.matrix[3][1]);
		result.matrix[1][2] = (matrix[1][0] * m.matrix[0][2]) + (matrix[1][1] * m.matrix[1][2]) + (matrix[1][2] * m.matrix[2][2]) + (matrix[1][3] * m.matrix[3][2]);
		result.matrix[1][3] = (matrix[1][0] * m.matrix[0][3]) + (matrix[1][1] * m.matrix[1][3]) + (matrix[1][2] * m.matrix[2][3]) + (matrix[1][3] * m.matrix[3][3]);

		result.matrix[2][0] = (matrix[2][0] * m.matrix[0][0]) + (matrix[2][1] * m.matrix[1][0]) + (matrix[2][2] * m.matrix[2][0]) + (matrix[2][3] * m.matrix[3][0]);
		result.matrix[2][1] = (matrix[2][0] * m.matrix[0][1]) + (matrix[2][1] * m.matrix[1][1]) + (matrix[2][2] * m.matrix[2][1]) + (matrix[2][3] * m.matrix[3][1]);
		result.matrix[2][2] = (matrix[2][0] * m.matrix[0][2]) + (matrix[2][1] * m.matrix[1][2]) + (matrix[2][2] * m.matrix[2][2]) + (matrix[2][3] * m.matrix[3][2]);
		result.matrix[2][3] = (matrix[2][0] * m.matrix[0][3]) + (matrix[2][1] * m.matrix[1][3]) + (matrix[2][2] * m.matrix[2][3]) + (matrix[2][3] * m.matrix[3][3]);

		result.matrix[3][0] = (matrix[3][0] * m.matrix[0][0]) + (matrix[3][1] * m.matrix[1][0]) + (matrix[3][2] * m.matrix[2][0]) + (matrix[3][3] * m.matrix[3][0]);
		result.matrix[3][1] = (matrix[3][0] * m.matrix[0][1]) + (matrix[3][1] * m.matrix[1][1]) + (matrix[3][2] * m.matrix[2][1]) + (matrix[3][3] * m.matrix[3][1]);
		result.matrix[3][2] = (matrix[3][0] * m.matrix[0][2]) + (matrix[3][1] * m.matrix[1][2]) + (matrix[3][2] * m.matrix[2][2]) + (matrix[3][3] * m.matrix[3][2]);
		result.matrix[3][3] = (matrix[3][0] * m.matrix[0][3]) + (matrix[3][1] * m.matrix[1][3]) + (matrix[3][2] * m.matrix[2][3]) + (matrix[3][3] * m.matrix[3][3]);

		return result;
	}

	Matrix4& Matrix4::operator *= (float scalar)
	{
		*this = Multiply(scalar);
		return *this;
	}

	Matrix4 Matrix4::operator * (float scalar) const
	{
		return Multiply(scalar);
	}

	/// <summary>Умножает указанный скаляр на данную матрицу.</summary>
	Matrix4 Matrix4::Multiply(float scalar) const
	{
		return Matrix4(
			matrix[0][0] * scalar, matrix[0][1] * scalar, matrix[0][2] * scalar, matrix[0][3] * scalar,
			matrix[1][0] * scalar, matrix[1][1] * scalar, matrix[1][2] * scalar, matrix[1][3] * scalar,
			matrix[2][0] * scalar, matrix[2][1] * scalar, matrix[2][2] * scalar, matrix[2][3] * scalar,
			matrix[3][0] * scalar, matrix[3][1] * scalar, matrix[3][2] * scalar, matrix[3][3] * scalar);
	}
}