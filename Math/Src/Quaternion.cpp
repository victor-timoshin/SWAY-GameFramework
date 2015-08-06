#include "../Inc/Quaternion.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Quaternion::Quaternion(void)
	{
		_x = _y = _z = _w = 0.0f;
	}

	/// <summary>Конструктор класса.</summary>
	Quaternion::Quaternion(const Quaternion& other)
	{
		_x = other._x;
		_y = other._y;
		_z = other._z;
		_w = other._w;
	}

	/// <summary>Конструктор класса.</summary>
	Quaternion::Quaternion(const float* other)
	{
		_x = other[0];
		_y = other[1];
		_z = other[2];
		_w = other[3];
	}

	/// <summary>Конструктор класса.</summary>
	Quaternion::Quaternion(float x, float y, float z, float w)
	{
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}

	void Quaternion::Identity(void)
	{
		_x = _y = _z = 0.0f;
		_w = 1.0f;
	}

	/// <summary>Возвращает квадрат длины данного кватерниона.</summary>
	float Quaternion::LengthSquared(void) const
	{
		return _x * _x + _y * _y + _z * _z + _w * _w;
	}

	/// <summary>Получает длину данного кватерниона.</summary>
	float Quaternion::Length(void)
	{
		return sqrtf(LengthSquared());
	}

	/// <summary>Нормализует данный кватернион.</summary>
	Quaternion Quaternion::Normalize(void) const
	{
		float lenSquared = LengthSquared();
		if (lenSquared > 0)
			return Multiply(1.0f / sqrt(lenSquared));

		return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
	}

	void Quaternion::FromAxisAngle(Vector3 axis, float angle)
	{
		float fHalfAngle = angle * 0.5f;
		float fSin = sin(fHalfAngle);

		_x = fSin * axis._x;
		_y = fSin * axis._y;
		_z = fSin * axis._z;

		_w = cos(fHalfAngle);
	}

	void Quaternion::ToRotationMatrix(Matrix4& m) const
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

		m[0][0] = 1.0f - (yy + zz);
		m[0][1] = xy + wz;
		m[0][2] = xz - wy;
		m[0][3] = 0.0f;

		m[1][0] = xy - wz;
		m[1][1] = 1.0f - (xx + zz);
		m[1][2] = yz + wx;
		m[1][3] = 0.0f;

		m[2][0] = xz + wy;
		m[2][1] = yz - wx;
		m[2][2] = 1.0f - (xx + yy);
		m[2][3] = 0.0f;

		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;
		m[3][3] = 1.0f;
	}

	void Quaternion::FromRotationMatrix(Matrix4& m)
	{
		float root = 0.0f;
		float trace = m[0][0] + m[1][1] + m[2][2];

		if (trace > 0.0f)
		{
			root = sqrtf(trace + 1.0f);

			_w = 0.5f * root;

			root = 0.5f / root;

			_x = (m[1][2] - m[2][1]) * root;
			_y = (m[2][0] - m[0][2]) * root;
			_z = (m[0][1] - m[1][0]) * root;
		}
		else
		{
			int next[3] = { 1, 2, 0 };
			int i = 0;

			if (m[1][1] > m[0][0]) i = 1;
			if (m[2][2] > m[i][i]) i = 2;

			int j = next[i];
			int k = next[j];

			root = sqrtf((m[i][i] - (m[j][j] + m[k][k])) + 1.0f);

			float* apkQuat[3] = { &_x, &_y, &_z };
			*apkQuat[i] = 0.5f * root;

			root = 0.5f / root;

			_w = (m[k][j] - m[j][k]) * root;

			*apkQuat[j] = (m[j][i] + m[i][j]) * root;
			*apkQuat[k] = (m[k][i] + m[i][k]) * root;
		}
	}

	bool Quaternion::operator == (const Quaternion& v) const
	{
		return Equals(v);
	}

	bool Quaternion::operator != (const Quaternion& v) const
	{
		return !Equals(v);
	}

	/// <summary>Сравнивает два кватерниона на наличие равенства.</summary>
	bool Quaternion::Equals(const Quaternion& v) const
	{
		return (_x == v._x && _y == v._y && _z == v._z && _w == v._w);
	}

	Quaternion& Quaternion::operator *= (const Quaternion& q)
	{
		*this = Multiply(q);
		return *this;
	}

	Quaternion Quaternion::operator * (const Quaternion& q) const
	{
		return Multiply(q);
	}

	/// <summary>Умножает указанный кватернион на данный кватернион.</summary>
	Quaternion Quaternion::Multiply(const Quaternion& q) const
	{
		return Quaternion(
			_w * q._x + _x * q._w + _y * q._z - _z * q._y,
			_w * q._y - _x * q._z + _y * q._w + _z * q._x,
			_w * q._z + _x * q._y - _y * q._x + _z * q._w,
			_w * q._w - _x * q._x - _y * q._y - _z * q._z);
	}

	Quaternion& Quaternion::operator *= (float scalar)
	{
		*this = Multiply(scalar);
		return *this;
	}

	Quaternion Quaternion::operator * (float scalar) const
	{
		return Multiply(scalar);
	}

	/// <summary>Умножает указанный скаляр на данный кватернион.</summary>
	Quaternion Quaternion::Multiply(const float scalar) const
	{
		return Quaternion(_x * scalar, _y * scalar, _z * scalar, _w * scalar);
	}
}