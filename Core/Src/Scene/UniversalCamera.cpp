#include "../../../Core/Inc/Scene/UniversalCamera.h"

namespace Scene
{
	UniversalCamera::UniversalCamera(std::string name) : ICameraBase(name)
	{
		matrixProjection.Identity();
		matrixView.Identity();

		fov = 45.0f;
		aspectRatio = 800.0f / 600.0f;
		orientation.Identity();
		eye = Core::Math::Vector3(0.0f, 0.0f, 0.0f);

		xAxis = Core::Math::Vector3(1.0f, 0.0f, 0.0f);
		yAxis = Core::Math::Vector3(0.0f, 1.0f, 0.0f);
		zAxis = Core::Math::Vector3(0.0f, 0.0f, 1.0f);
	}

	void UniversalCamera::LookAt()
	{
		zAxis.Normalize();
		xAxis = Core::Math::Cross(yAxis, zAxis);
		xAxis.Normalize();

		yAxis = Core::Math::Cross(zAxis, xAxis);
		yAxis.Normalize();
		xAxis.Normalize();

		matrixView[0][0] = xAxis._x;
		matrixView[0][1] = xAxis._y;
		matrixView[0][2] = xAxis._z;
		matrixView[0][3] = -Core::Math::DotProduct(xAxis, eye);

		matrixView[1][0] = yAxis._x;
		matrixView[1][1] = yAxis._y;
		matrixView[1][2] = yAxis._z;
		matrixView[1][2] = -Core::Math::DotProduct(yAxis, eye);

		matrixView[2][0] = zAxis._x;
		matrixView[2][1] = zAxis._y;
		matrixView[2][2] = zAxis._z;
		matrixView[2][3] = -Core::Math::DotProduct(zAxis, eye);

		orientation.FromRotationMatrix(matrixView);
	}

	void UniversalCamera::Perspective(float fovF, float aspectRatioF, float nearClipF, float farClipF)
	{
		nearClip = nearClipF;
		farClip = farClipF;

		float height = 1.0f / tanf((fovF * (Core::Math::REAL_PI / 180.0f)) * 0.5f);
		float width = height / aspectRatioF;

		matrixProjection[0][0] = 2.0f * nearClip / height;
		matrixProjection[0][1] = 0.0f;
		matrixProjection[0][2] = 0.0f;
		matrixProjection[0][3] = 0.0f;

		matrixProjection[1][0] = 0.0f;
		matrixProjection[1][1] = 2.0f * nearClip / width;
		matrixProjection[1][2] = 0.0f;
		matrixProjection[1][3] = 0.0f;

		matrixProjection[2][0] = 0.0f;
		matrixProjection[2][1] = 0.0f;
		matrixProjection[2][2] = farClip / (nearClip - farClip);
		matrixProjection[2][3] =-1.0f;

		matrixProjection[3][0] = 0.0f;
		matrixProjection[3][1] = 0.0f;
		matrixProjection[3][2] = nearClip * farClip / (nearClip - farClip);
		matrixProjection[3][3] = 0.0f;
	}

	void UniversalCamera::OrthoOffCenter(float left, float top, float right, float bottom, float nearClipF, float farClipF)
	{
		nearClip = nearClipF;
		farClip = farClipF;

		matrixProjection[0][0] = 2.0f / (right - left);
		matrixProjection[0][1] = 0.0f;
		matrixProjection[0][2] = 0.0f;
		matrixProjection[0][3] = 0.0f;

		matrixProjection[1][0] = 0.0f;
		matrixProjection[1][1] = 2.0f / (top - bottom);
		matrixProjection[1][2] = 0.0f;
		matrixProjection[1][3] = 0.0f;

		matrixProjection[2][0] = 0.0f;
		matrixProjection[2][1] = 0.0f;
		matrixProjection[2][2] = -2.0f / (farClip - nearClip);
		matrixProjection[2][3] = 0.0f;

		matrixProjection[3][0] =-(right + left) / (right - left);
		matrixProjection[3][1] =-(top + bottom) / (top - bottom);
		matrixProjection[3][2] = -(farClip + nearClip) / (farClip - nearClip);
		matrixProjection[3][3] = 1.0f;
	}

	void UniversalCamera::NormalizePlane(LPLANEDATA_DESC& plane)
	{
		float length = Core::Math::Length(Core::Math::Vector3(plane._a, plane._b, plane._c));

		plane._a /= length;
		plane._b /= length;
		plane._c /= length;
		plane._d /= length;
	}

	void UniversalCamera::Update()
	{
		orientation.Normalize();
		orientation.ToRotationMatrix(matrixView);

		xAxis = Core::Math::Vector3(matrixView[0][0], matrixView[1][0], matrixView[2][0]);
		yAxis = Core::Math::Vector3(matrixView[0][1], matrixView[1][1], matrixView[2][1]);
		zAxis = Core::Math::Vector3(matrixView[0][2], matrixView[1][2], matrixView[2][2]);

		matrixView[3][0] = -Core::Math::DotProduct(xAxis, eye);
		matrixView[3][1] = -Core::Math::DotProduct(yAxis, eye);
		matrixView[3][2] = -Core::Math::DotProduct(zAxis, eye);

		#pragma region Construct 6 planes based on the current view and projection
		{
			Core::Math::Matrix4 comboMatrix = matrixView * matrixProjection;

			/* Left clipping plane. */
			planes[0]._a = comboMatrix[3][0] + comboMatrix[0][0];
			planes[0]._b = comboMatrix[3][1] + comboMatrix[0][1];
			planes[0]._c = comboMatrix[3][2] + comboMatrix[0][2];
			planes[0]._d = comboMatrix[3][3] + comboMatrix[0][3];

			/* Right clipping plane. */
			planes[1]._a = comboMatrix[3][0] - comboMatrix[0][0];
			planes[1]._b = comboMatrix[3][1] - comboMatrix[0][1];
			planes[1]._c = comboMatrix[3][2] - comboMatrix[0][2];
			planes[1]._d = comboMatrix[3][3] - comboMatrix[0][3];

			/* Top clipping plane. */
			planes[2]._a = comboMatrix[3][0] + comboMatrix[1][0];
			planes[2]._b = comboMatrix[3][1] + comboMatrix[1][1];
			planes[2]._c = comboMatrix[3][2] + comboMatrix[1][2];
			planes[2]._d = comboMatrix[3][3] + comboMatrix[1][3];

			/* Bottom clipping plane. */
			planes[3]._a = comboMatrix[3][0] - comboMatrix[1][0];
			planes[3]._b = comboMatrix[3][1] - comboMatrix[1][1];
			planes[3]._c = comboMatrix[3][2] - comboMatrix[1][2];
			planes[3]._d = comboMatrix[3][3] - comboMatrix[1][3];

			/* Near clipping plane. */
			planes[4]._a = comboMatrix[3][0] + comboMatrix[2][0];
			planes[4]._b = comboMatrix[3][1] + comboMatrix[2][1];
			planes[4]._c = comboMatrix[3][2] + comboMatrix[2][2];
			planes[4]._d = comboMatrix[3][3] + comboMatrix[2][3];

			/* Far clipping plane. */
			planes[5]._a = comboMatrix[3][0] - comboMatrix[2][0];
			planes[5]._b = comboMatrix[3][1] - comboMatrix[2][1];
			planes[5]._c = comboMatrix[3][2] - comboMatrix[2][2];
			planes[5]._d = comboMatrix[3][3] - comboMatrix[2][3];

			for (int i = 0; i < 6; i++)
				NormalizePlane(planes[i]);
		}
		#pragma endregion
	}

	bool UniversalCamera::ContainsBoundingVolume(Core::Math::BoundingVolume& box, Core::Math::Vector3& position)
	{
		for(int i = 0; i < 6; i++)
		{
			Core::Math::Vector3 p, q;

			if(planes[i]._a >= 0.0f)
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

			if ((Core::Math::DotProduct(Core::Math::Vector3(planes[i]._a, planes[i]._b, planes[i]._c), q) + planes[i]._d) < 0.0f)
				return false;
		}

		return true;
	}

	void UniversalCamera::Move(Core::Math::Vector3& direction)
	{
		eye += xAxis * direction._x;
		eye += yAxis * direction._y;
		eye += zAxis * direction._z;

		Update();
	}

	void UniversalCamera::Rotation(float yaw, float pitch, float roll)
	{
		Core::Math::Quaternion rotation;

		if (yaw != 0.0f)
		{
			rotation.FromAxisAngle(Core::Math::Vector3(0.0f, 1.0f, 0.0f), yaw);
			orientation = orientation * rotation;
		}

		if(pitch != 0.0f)
		{
			rotation.FromAxisAngle(Core::Math::Vector3(1.0f, 0.0f, 0.0f), pitch);
			orientation = rotation * orientation;
		}

		if(roll != 0.0f)
		{
			rotation.FromAxisAngle(Core::Math::Vector3(0.0f, 0.0f, 1.0f), roll);
			orientation = orientation * rotation;
		}

		Update();
	}

	const Core::Math::Matrix4& UniversalCamera::GetMatrixView()
	{
		return matrixView;
	}

	const Core::Math::Matrix4& UniversalCamera::GetMatrixProjection()
	{
		return matrixProjection;
	}

	void UniversalCamera::SetPosition(Core::Math::Vector3& eyeV)
	{
		eye = eyeV;
	}

	Core::Math::Vector3 UniversalCamera::GetPosition() const
	{
		return eye;
	}

	float UniversalCamera::GetNearClip() const
	{
		return nearClip;
	}

	float UniversalCamera::GetFarClip() const
	{
		return farClip;
	}

	Core::Math::Vector3 UniversalCamera::GetXAxis()
	{
		return xAxis;
	}

	Core::Math::Vector3 UniversalCamera::GetYAxis()
	{
		return yAxis;
	}

	Core::Math::Vector3 UniversalCamera::GetZAxis()
	{
		return zAxis;
	}
}