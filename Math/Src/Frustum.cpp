#include "../Inc/Frustum.h"
#include "../Inc/MathCommon.h"

namespace Math
{
	/// <summary>Конструктор класса.</summary>
	Frustum::Frustum(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Frustum::~Frustum(void)
	{
	}

	bool Frustum::ContainsBoundingVolume(Math::BoundingVolume& box, Math::Vector3& position)
	{
		for (int i = 0; i < 6; i++)
		{
			Math::Vector3 p, q;

			if (planes[i]._a >= 0.0f)
			{
				p._x = box.GetMinimum()._x + position._x;
				q._x = box.GetMaximum()._x + position._x;
			}
			else
			{
				p._x = box.GetMaximum()._x + position._x;
				q._x = box.GetMinimum()._x + position._x;
			}

			if (planes[i]._b >= 0.0f)
			{
				p._y = box.GetMinimum()._y + position._y;
				q._y = box.GetMaximum()._y + position._y;
			}
			else
			{
				p._y = box.GetMaximum()._y + position._y;
				q._y = box.GetMinimum()._y + position._y;
			}

			if (planes[i]._c >= 0.0f)
			{
				p._z = box.GetMinimum()._z + position._z;
				q._z = box.GetMaximum()._z + position._z;
			}
			else
			{
				p._z = box.GetMaximum()._z + position._z;
				q._z = box.GetMinimum()._z + position._z;
			}

			if ((Math::DotProduct(Math::Vector3(planes[i]._a, planes[i]._b, planes[i]._c), q) + planes[i]._d) < 0.0f)
				return false;
		}

		return true;
	}

	void Frustum::Generate(const Math::Matrix4& viewMatrix, const Math::Matrix4& projectionMatrix)
	{
		Math::Matrix4 comboMatrix = viewMatrix * projectionMatrix;

		/* Передняя плоскость */
		planes[0]._a = comboMatrix[0][2] + comboMatrix[0][2];
		planes[0]._b = comboMatrix[1][2] + comboMatrix[1][2];
		planes[0]._c = comboMatrix[2][2] + comboMatrix[2][2];
		planes[0]._d = comboMatrix[3][2] + comboMatrix[3][2];
		/* Задняя плоскость */
		planes[1]._a = comboMatrix[0][3] - comboMatrix[0][2];
		planes[1]._b = comboMatrix[1][3] - comboMatrix[1][2];
		planes[1]._c = comboMatrix[2][3] - comboMatrix[2][2];
		planes[1]._d = comboMatrix[3][3] - comboMatrix[3][2];
		/* Левая плоскость */
		planes[2]._a = comboMatrix[0][3] + comboMatrix[0][0];
		planes[2]._b = comboMatrix[1][3] + comboMatrix[1][0];
		planes[2]._c = comboMatrix[2][3] + comboMatrix[2][0];
		planes[2]._d = comboMatrix[3][3] + comboMatrix[3][0];
		/* Правая плоскость */
		planes[3]._a = comboMatrix[0][3] - comboMatrix[0][0];
		planes[3]._b = comboMatrix[1][3] - comboMatrix[1][0];
		planes[3]._c = comboMatrix[2][3] - comboMatrix[2][0];
		planes[3]._d = comboMatrix[3][3] - comboMatrix[3][0];
		/* Нижняя плоскость */
		planes[4]._a = comboMatrix[0][3] + comboMatrix[0][1];
		planes[4]._b = comboMatrix[1][3] + comboMatrix[1][1];
		planes[4]._c = comboMatrix[2][3] + comboMatrix[2][1];
		planes[4]._d = comboMatrix[3][3] + comboMatrix[3][1];
		/* Верхняя плоскость */
		planes[5]._a = comboMatrix[0][3] - comboMatrix[0][1];
		planes[5]._b = comboMatrix[1][3] - comboMatrix[1][1];
		planes[5]._c = comboMatrix[2][3] - comboMatrix[2][1];
		planes[5]._d = comboMatrix[3][3] - comboMatrix[3][1];

		for (int i = 0; i < 6; i++)
			NormalizePlane(planes[i]);
	}

	void Frustum::NormalizePlane(LPLANEDATA_DESC& plane)
	{
		float length = Math::Vector3(plane._a, plane._b, plane._c).Length();

		plane._a /= length;
		plane._b /= length;
		plane._c /= length;
		plane._d /= length;
	}
}