#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vector3.h"

namespace Math
{
	class Matrix4
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Matrix4(void) {}

		/// <summary>Конструктор класса.</summary>
		Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23,
			float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
		{
			matrix[0][0] = m11, matrix[0][1] = m12, matrix[0][2] = m13, matrix[0][3] = m14;
			matrix[1][0] = m21, matrix[1][1] = m22, matrix[1][2] = m23, matrix[1][3] = m24;
			matrix[2][0] = m31, matrix[2][1] = m32, matrix[2][2] = m33, matrix[2][3] = m34;
			matrix[3][0] = m41, matrix[3][1] = m42, matrix[3][2] = m43, matrix[3][3] = m44;
		}

		void Identity(void)
		{
			matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
			matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
			matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
			matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
		}

		Matrix4& Inverse(void) const
		{
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

			float d00 = t00 * invDet;
			float d10 = t10 * invDet;
			float d20 = t20 * invDet;
			float d30 = t30 * invDet;

			float d01 = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
			float d11 = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
			float d21 = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
			float d31 = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

			v0 = m10 * m31 - m11 * m30;
			v1 = m10 * m32 - m12 * m30;
			v2 = m10 * m33 - m13 * m30;
			v3 = m11 * m32 - m12 * m31;
			v4 = m11 * m33 - m13 * m31;
			v5 = m12 * m33 - m13 * m32;

			float d02 = +(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
			float d12 = -(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
			float d22 = +(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
			float d32 = -(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

			v0 = m21 * m10 - m20 * m11;
			v1 = m22 * m10 - m20 * m12;
			v2 = m23 * m10 - m20 * m13;
			v3 = m22 * m11 - m21 * m12;
			v4 = m23 * m11 - m21 * m13;
			v5 = m23 * m12 - m22 * m13;

			float d03 = -(v5 * m01 - v4 * m02 + v3 * m03) * invDet;
			float d13 = +(v5 * m00 - v2 * m02 + v1 * m03) * invDet;
			float d23 = -(v4 * m00 - v2 * m01 + v0 * m03) * invDet;
			float d33 = +(v3 * m00 - v1 * m01 + v0 * m02) * invDet;

			Matrix4 matrix(
				d00, d01, d02, d03,
				d10, d11, d12, d13,
				d20, d21, d22, d23,
				d30, d31, d32, d33);

			return matrix;
		}

		float* operator[](int row)
		{
			return matrix[row];
		}

		Matrix4& operator*=(const Matrix4& rhs)
		{
			Matrix4 temp;
			temp.matrix[0][0] = (matrix[0][0] * rhs.matrix[0][0]) + (matrix[0][1] * rhs.matrix[1][0]) + (matrix[0][2] * rhs.matrix[2][0]) + (matrix[0][3] * rhs.matrix[3][0]);
			temp.matrix[0][1] = (matrix[0][0] * rhs.matrix[0][1]) + (matrix[0][1] * rhs.matrix[1][1]) + (matrix[0][2] * rhs.matrix[2][1]) + (matrix[0][3] * rhs.matrix[3][1]);
			temp.matrix[0][2] = (matrix[0][0] * rhs.matrix[0][2]) + (matrix[0][1] * rhs.matrix[1][2]) + (matrix[0][2] * rhs.matrix[2][2]) + (matrix[0][3] * rhs.matrix[3][2]);
			temp.matrix[0][3] = (matrix[0][0] * rhs.matrix[0][3]) + (matrix[0][1] * rhs.matrix[1][3]) + (matrix[0][2] * rhs.matrix[2][3]) + (matrix[0][3] * rhs.matrix[3][3]);

			temp.matrix[1][0] = (matrix[1][0] * rhs.matrix[0][0]) + (matrix[1][1] * rhs.matrix[1][0]) + (matrix[1][2] * rhs.matrix[2][0]) + (matrix[1][3] * rhs.matrix[3][0]);
			temp.matrix[1][1] = (matrix[1][0] * rhs.matrix[0][1]) + (matrix[1][1] * rhs.matrix[1][1]) + (matrix[1][2] * rhs.matrix[2][1]) + (matrix[1][3] * rhs.matrix[3][1]);
			temp.matrix[1][2] = (matrix[1][0] * rhs.matrix[0][2]) + (matrix[1][1] * rhs.matrix[1][2]) + (matrix[1][2] * rhs.matrix[2][2]) + (matrix[1][3] * rhs.matrix[3][2]);
			temp.matrix[1][3] = (matrix[1][0] * rhs.matrix[0][3]) + (matrix[1][1] * rhs.matrix[1][3]) + (matrix[1][2] * rhs.matrix[2][3]) + (matrix[1][3] * rhs.matrix[3][3]);

			temp.matrix[2][0] = (matrix[2][0] * rhs.matrix[0][0]) + (matrix[2][1] * rhs.matrix[1][0]) + (matrix[2][2] * rhs.matrix[2][0]) + (matrix[2][3] * rhs.matrix[3][0]);
			temp.matrix[2][1] = (matrix[2][0] * rhs.matrix[0][1]) + (matrix[2][1] * rhs.matrix[1][1]) + (matrix[2][2] * rhs.matrix[2][1]) + (matrix[2][3] * rhs.matrix[3][1]);
			temp.matrix[2][2] = (matrix[2][0] * rhs.matrix[0][2]) + (matrix[2][1] * rhs.matrix[1][2]) + (matrix[2][2] * rhs.matrix[2][2]) + (matrix[2][3] * rhs.matrix[3][2]);
			temp.matrix[2][3] = (matrix[2][0] * rhs.matrix[0][3]) + (matrix[2][1] * rhs.matrix[1][3]) + (matrix[2][2] * rhs.matrix[2][3]) + (matrix[2][3] * rhs.matrix[3][3]);

			temp.matrix[3][0] = (matrix[3][0] * rhs.matrix[0][0]) + (matrix[3][1] * rhs.matrix[1][0]) + (matrix[3][2] * rhs.matrix[2][0]) + (matrix[3][3] * rhs.matrix[3][0]);
			temp.matrix[3][1] = (matrix[3][0] * rhs.matrix[0][1]) + (matrix[3][1] * rhs.matrix[1][1]) + (matrix[3][2] * rhs.matrix[2][1]) + (matrix[3][3] * rhs.matrix[3][1]);
			temp.matrix[3][2] = (matrix[3][0] * rhs.matrix[0][2]) + (matrix[3][1] * rhs.matrix[1][2]) + (matrix[3][2] * rhs.matrix[2][2]) + (matrix[3][3] * rhs.matrix[3][2]);
			temp.matrix[3][3] = (matrix[3][0] * rhs.matrix[0][3]) + (matrix[3][1] * rhs.matrix[1][3]) + (matrix[3][2] * rhs.matrix[2][3]) + (matrix[3][3] * rhs.matrix[3][3]);

			*this = temp;
			return *this;
		}

		Matrix4& operator*=(float scalar)
		{
			matrix[0][0] *= scalar, matrix[0][1] *= scalar, matrix[0][2] *= scalar, matrix[0][3] *= scalar;
			matrix[1][0] *= scalar, matrix[1][1] *= scalar, matrix[1][2] *= scalar, matrix[1][3] *= scalar;
			matrix[2][0] *= scalar, matrix[2][1] *= scalar, matrix[2][2] *= scalar, matrix[2][3] *= scalar;
			matrix[3][0] *= scalar, matrix[3][1] *= scalar, matrix[3][2] *= scalar, matrix[3][3] *= scalar;
			return *this;
		}

		Matrix4 operator*(const Matrix4& rhs) const
		{
			Matrix4 temp(*this);
			temp *= rhs;
			return temp;
		}

		Matrix4 operator*(float scalar) const
		{
			Matrix4 temp(*this);
			temp *= scalar;
			return temp;
		}
	private:
		float matrix[4][4];
	};
}

#endif // MATRIX4_H