#include "../Inc/Camera.h"

namespace Scene
{
	const Math::Vector3 Camera::WORLD_XAXIS(1.0f, 0.0f, 0.0f);
	const Math::Vector3 Camera::WORLD_YAXIS(0.0f, 1.0f, 0.0f);
	const Math::Vector3 Camera::WORLD_ZAXIS(0.0f, 0.0f, 1.0f);

	/// <summary>Конструктор класса.</summary>
	/// <param name="name">Имя камеры.</param>
	Camera::Camera(std::string name) : ICameraBase(name)
	{
		projectionMatrix.Identity();
		viewMatrix.Identity();

		fov = 45.0f;
		orientation.Identity();
		eye = Math::Vector3(0.0f, 0.0f, 0.0f);

		xAxis = Math::Vector3(1.0f, 0.0f, 0.0f);
		yAxis = Math::Vector3(0.0f, 1.0f, 0.0f);
		zAxis = Math::Vector3(0.0f, 0.0f, 1.0f);
	}

	void Camera::LookAt(void)
	{
		zAxis.Normalize();
		xAxis = Math::Cross(yAxis, zAxis);
		xAxis.Normalize();

		yAxis = Math::Cross(zAxis, xAxis);
		yAxis.Normalize();
		xAxis.Normalize();

		viewMatrix[0][0] = xAxis._x;
		viewMatrix[1][0] = xAxis._y;
		viewMatrix[2][0] = xAxis._z;
		viewMatrix[3][0] = -Math::DotProduct(xAxis, eye);

		viewMatrix[0][1] = yAxis._x;
		viewMatrix[1][1] = yAxis._y;
		viewMatrix[2][1] = yAxis._z;
		viewMatrix[3][1] = -Math::DotProduct(yAxis, eye);

		viewMatrix[0][2] = zAxis._x;
		viewMatrix[1][2] = zAxis._y;
		viewMatrix[2][2] = zAxis._z;
		viewMatrix[3][2] = -Math::DotProduct(zAxis, eye);

		orientation.FromRotationMatrix(viewMatrix);
	}

	void Camera::Perspective(float fovF, float aspectRatio, float nearClipF, float farClipF)
	{
		nearClip = nearClipF;
		farClip = farClipF;

		float height = 1.0f / tanf((fovF * (Math::REAL_PI / 180.0f)) * 0.5f);
		float width = height / aspectRatio;

		projectionMatrix[0][0] = 2.0f * nearClip / height;
		projectionMatrix[0][1] = 0.0f;
		projectionMatrix[0][2] = 0.0f;
		projectionMatrix[0][3] = 0.0f;

		projectionMatrix[1][0] = 0.0f;
		projectionMatrix[1][1] = 2.0f * nearClip / width;
		projectionMatrix[1][2] = 0.0f;
		projectionMatrix[1][3] = 0.0f;

		projectionMatrix[2][0] = 0.0f;
		projectionMatrix[2][1] = 0.0f;
		projectionMatrix[2][2] = farClip / (nearClip - farClip);
		projectionMatrix[2][3] =-1.0f;

		projectionMatrix[3][0] = 0.0f;
		projectionMatrix[3][1] = 0.0f;
		projectionMatrix[3][2] = nearClip * farClip / (nearClip - farClip);
		projectionMatrix[3][3] = 0.0f;
	}

	void Camera::OrthoOffCenter(float left, float top, float right, float bottom, float nearClipF, float farClipF)
	{
		nearClip = nearClipF;
		farClip = farClipF;

		projectionMatrix[0][0] = 2.0f / (right - left);
		projectionMatrix[0][1] = 0.0f;
		projectionMatrix[0][2] = 0.0f;
		projectionMatrix[0][3] = 0.0f;

		projectionMatrix[1][0] = 0.0f;
		projectionMatrix[1][1] = 2.0f / (top - bottom);
		projectionMatrix[1][2] = 0.0f;
		projectionMatrix[1][3] = 0.0f;

		projectionMatrix[2][0] = 0.0f;
		projectionMatrix[2][1] = 0.0f;
		projectionMatrix[2][2] = -2.0f / (farClip - nearClip);
		projectionMatrix[2][3] = 0.0f;

		projectionMatrix[3][0] =-(right + left) / (right - left);
		projectionMatrix[3][1] =-(top + bottom) / (top - bottom);
		projectionMatrix[3][2] = -(farClip + nearClip) / (farClip - nearClip);
		projectionMatrix[3][3] = 1.0f;
	}

	void Camera::Update(void)
	{
		orientation.Normalize();
		orientation.ToRotationMatrix(viewMatrix);

		xAxis = Math::Vector3(viewMatrix[0][0], viewMatrix[1][0], viewMatrix[2][0]);
		yAxis = Math::Vector3(viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);
		zAxis = Math::Vector3(viewMatrix[0][2], viewMatrix[1][2], viewMatrix[2][2]);

		viewMatrix[3][0] = -Math::DotProduct(xAxis, eye);
		viewMatrix[3][1] = -Math::DotProduct(yAxis, eye);
		viewMatrix[3][2] = -Math::DotProduct(zAxis, eye);
	}

	void Camera::Move(Math::Vector3& direction)
	{
		eye += xAxis * direction._x;
		eye += yAxis * direction._y;
		eye += zAxis * direction._z;

		Update();
	}

	void Camera::Rotation(float yaw, float pitch, float roll)
	{
		Math::Quaternion rotation;

		if (yaw != 0.0f)
		{
			rotation.FromAxisAngle(WORLD_YAXIS, Math::DegreesToRadians(yaw));
			orientation = rotation * orientation;
		}

		if(pitch != 0.0f)
		{
			rotation.FromAxisAngle(WORLD_XAXIS, Math::DegreesToRadians(pitch));
			orientation = orientation * rotation;
		}

		if(roll != 0.0f)
		{
			rotation.FromAxisAngle(WORLD_ZAXIS, Math::DegreesToRadians(roll));
			orientation = orientation * rotation;
		}

		Update();
	}

	const Math::Matrix4& Camera::GetViewMatrix(void)
	{
		return viewMatrix;
	}

	const Math::Matrix4& Camera::GetProjectionMatrix(void)
	{
		return projectionMatrix;
	}

	void Camera::SetPosition(Math::Vector3& eyeV)
	{
		eye = eyeV;
	}

	Math::Vector3 Camera::GetPosition(void) const
	{
		return eye;
	}

	void Camera::SetNearClipDistance(float value)
	{
		nearClip = value;
	}

	float Camera::GetNearClipDistance(void) const
	{
		return nearClip;
	}

	void Camera::SetFarClipDistance(float value)
	{
		farClip = value;
	}

	float Camera::GetFarClipDistance(void) const
	{
		return farClip;
	}

	Math::Vector3 Camera::GetXAxis(void)
	{
		return xAxis;
	}

	Math::Vector3 Camera::GetYAxis(void)
	{
		return yAxis;
	}

	Math::Vector3 Camera::GetZAxis(void)
	{
		return zAxis;
	}
}