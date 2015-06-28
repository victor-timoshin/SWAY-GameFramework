#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"
#include "Matrix4.h"

#include <math.h>

namespace Core
{
	namespace Math
	{
		class Quaternion
		{
		public:
			Quaternion() {}

			Quaternion(const Quaternion& other)
				: _w(other._w), _x(other._x), _y(other._y), _z(other._z) {}

			Quaternion(const float* other)
				: _w(other[0]), _x(other[1]), _y(other[2]), _z(other[3]) {}

			Quaternion(float w, float x, float y, float z)
				: _w(w), _x(x), _y(y), _z(z) {}

			void Identity()
			{
				_w = 1.0f;
				_x = 0.0f, _y = 0.0f, _z = 0.0f;
			}

			float Norm() const
			{
				return _w * _w + _x * _x + _y * _y + _z * _z;
			}

			float Length() const
			{
				return sqrt(_w * _w + _x * _x + _y * _y + _z * _z);
			}

			Quaternion Conjugate() const
			{
				return Quaternion(_w, -_x, -_y, -_z);
			}

			void Invert()
			{
				float norm = _w * _w + _x * _x + _y * _y + _z * _z;
				if (norm > 0.0f)
				{
					float invNorm = 1.0f / norm;

					_w = _w * invNorm;
					_x = -_x * invNorm;
					_y = -_y * invNorm;
					_z = -_z * invNorm;
				}
			}

			void Normalize()
			{
				float length = 1.0f / sqrt(_w * _w + _x * _x + _y * _y + _z * _z);
				if (length != 0)
				{
					_x *= length;
					_y *= length;
					_z *= length;
					_w *= length;
				}
			}

			void FromAxisAngle(Vector3 axis, float angle)
			{
				float halfAngle = angle * 0.5f;
				float Sine = sin(halfAngle);

				_w = cos(halfAngle);
				_x = axis._x * Sine;
				_y = axis._y * Sine;
				_z = axis._z * Sine;
			}

			void ToRotationMatrix(Matrix4& matrix) const
			{
				float x = _x + _x;
				float y = _y + _y;
				float z = _z + _z;

				float xx = _x * x;
				float xy = _x * y;
				float xz = _x * z;

				float yy = _y * y;
				float yz = _y * z;

				float zz = _z * z;

				float wx = _w * x;
				float wy = _w * y;
				float wz = _w * z;

				matrix[0][0] = 1.0f - (yy + zz);
				matrix[0][1] = xy + wz;
				matrix[0][2] = xz - wy;
				matrix[0][3] = 0.0f;

				matrix[1][0] = xy - wz;
				matrix[1][1] = 1.0f - (xx + zz);
				matrix[1][2] = yz + wx;
				matrix[1][3] = 0.0f;

				matrix[2][0] = xz + wy;
				matrix[2][1] = yz - wx;
				matrix[2][2] = 1.0f - (xx + yy);
				matrix[2][3] = 0.0f;

				matrix[3][0] = 0.0f;
				matrix[3][1] = 0.0f;
				matrix[3][2] = 0.0f;
				matrix[3][3] = 1.0f;
			}

			void FromRotationMatrix(Matrix4& matrix)
			{
				float root = 0.0f;
				float trace = matrix[0][0] + matrix[1][1] + matrix[2][2];

				if (trace > 0.0f)
				{
					root = sqrtf(trace + 1.0f);

					_w = 0.5f * root;

					root = 0.5f / root;

					_x = (matrix[1][2] - matrix[2][1]) * root;
					_y = (matrix[2][0] - matrix[0][2]) * root;
					_z = (matrix[0][1] - matrix[1][0]) * root;
				}
				else
				{
					int next[3] = { 1, 2, 0 };
					int i = 0;

					if (matrix[1][1] > matrix[0][0]) i = 1;
					if (matrix[2][2] > matrix[i][i]) i = 2;

					int j = next[i];
					int k = next[j];

					root = sqrtf((matrix[i][i] - (matrix[j][j] + matrix[k][k])) + 1.0f);

					float* apkQuat[3] = { &_x, &_y, &_z };
					*apkQuat[i] = 0.5f * root;

					root = 0.5f / root;

					_w = (matrix[k][j] - matrix[j][k]) * root;

					*apkQuat[j] = (matrix[j][i] + matrix[i][j]) * root;
					*apkQuat[k] = (matrix[k][i] + matrix[i][k]) * root;
				}
			}

			Quaternion& operator*=(const Quaternion& rhs)
			{
				Quaternion temp(
					(_w * rhs._w) - (_x * rhs._x) - (_y * rhs._y) - (_z * rhs._z),
					(_w * rhs._x) + (_x * rhs._w) - (_y * rhs._z) + (_z * rhs._y),
					(_w * rhs._y) + (_x * rhs._z) + (_y * rhs._w) - (_z * rhs._x),
					(_w * rhs._z) - (_x * rhs._y) + (_y * rhs._x) + (_z * rhs._w));

				*this = temp;
				return *this;
			}

			Quaternion& operator*=(float scalar)
			{
				_w *= scalar, _x *= scalar, _y *= scalar, _z *= scalar;
				return *this;
			}

			Quaternion operator*(const Quaternion& rhs) const
			{
				Quaternion temp(*this);
				temp *= rhs;
				return temp;
			}

			Quaternion operator*(float scalar) const
			{
				Quaternion temp(*this);
				temp *= scalar;
				return temp;
			}
		public:
			float _w;
			float _x;
			float _y;
			float _z;
		};
	}
}

#endif // QUATERNION_H