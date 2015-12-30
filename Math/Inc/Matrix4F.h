#ifndef MATRIX4F_H
#define MATRIX4F_H

#include "Vector3.h"
#include "MathCommon.h"
#include "../../SDK/Platform.h"

#define MATRIX_SIZE (sizeof(float) * 16)

namespace Math
{
	static const float MATRIX_IDENTITY[16] =
	{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	class CORE_API Matrix4F
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Matrix4F(void);

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
		Matrix4F(float m00, float m01, float m02, float m03, float m10, float m11, float m12,
			float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

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
		void Set(float m00, float m01, float m02, float m03, float m10, float m11, float m12,
			float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);

		/// <summary>Устанавливает значения матрицы.</summary>
		void Set(const float* matrix);

		/// <summary>Устанавливает значения матрицы.</summary>
		void Set(const Matrix4F& matrix);

		void Set(int row, int col, float value);

		float Get(int row, int col) const;

		bool Invert(Matrix4F* dst) const;

		/// <summary>Приводит к единичной матрице.</summary>
		void SetIdentity(void);

		bool IsIdentity(void) const;

		void SetZero(void);

		void Perspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane);

		void Orthographic(float width, float height, float nearPlane, float farPlane);

		void OrthographicOffCenter(float left, float top, float right, float bottom, float nearPlane, float farPlane);

		Vector3F Transform(const Vector3F& vector) const;

		void Rotate(float angle, float x, float y, float z);

		void Rotate(const Vector3F& euler);

		void Subtract(const Matrix4F& matrix);

		void Add(float scalar);
		void Add(const Matrix4F& matrix);

		void Negate(void);
		void Negate(Matrix4F* dst) const;

		void Multiply(float scalar);
		void Multiply(const Matrix4F& matrix);

		static bool Compare(const Matrix4F& m1, const Matrix4F& m2);

		static void Subtract(const Matrix4F& m1, const Matrix4F& m2, Matrix4F* dst);

		static void Add(const Matrix4F& matrix, float scalar, Matrix4F* dst);
		static void Add(const Matrix4F& m1, const Matrix4F& m2, Matrix4F* dst);

		static void Multiply(const Matrix4F& matrix, float scalar, Matrix4F* dst);
		static void Multiply(const Matrix4F& m1, const Matrix4F& m2, Matrix4F* dst);

		inline const Matrix4F Matrix4F::operator+(const Matrix4F& matrix) const;
		inline Matrix4F& Matrix4F::operator+=(const Matrix4F& matrix);

		inline const Matrix4F Matrix4F::operator-(const Matrix4F& matrix) const;
		inline Matrix4F& Matrix4F::operator-=(const Matrix4F& matrix);
		inline const Matrix4F Matrix4F::operator-() const;

		inline const Matrix4F operator*(const Matrix4F& matrix) const;
		inline Matrix4F& operator*=(const Matrix4F& matrix);

		inline float& operator()(int row, int column);
		inline float operator()(int row, int column) const;

		inline operator const Matrix4F& () const;
		inline operator Matrix4F& ();

	public:
		float _values[16];
	};

	CORE_API typedef Matrix4F Mat4F;
}

#include "Matrix4F.inl"

#endif // MATRIX4F_H