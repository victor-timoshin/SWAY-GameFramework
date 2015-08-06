#ifndef MATRIX4_H
#define MATRIX4_H

#include "../../SDK/Platform.h"

namespace Math
{
	class CORE_API Matrix4
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Matrix4(void);

		/// <summary>Конструктор класса.</summary>
		Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23,
			float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);

		float* operator [] (int i);

		/// <summary>Приводит к единичной матрице.</summary>
		void Identity(void);

		/// <summary>Инверсирует матрицу.</summary>
		Matrix4 Inverse(void) const;

		Matrix4& operator *= (const Matrix4& m);

		Matrix4 operator * (const Matrix4& m) const;

		/// <summary>Умножает данную матрицу на другую указанную матрицу.</summary>
		Matrix4 Multiply(const Matrix4& m) const;

		Matrix4& operator *= (float scalar);

		Matrix4 operator * (float scalar) const;

		/// <summary>Умножает указанный скаляр на данную матрицу.</summary>
		Matrix4 Multiply(float scalar) const;

	private:
		float matrix[4][4];
	};
}

#endif // MATRIX4_H