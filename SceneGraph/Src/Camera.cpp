#include "../Inc/Camera.h"

namespace Scene
{
	DEF_PROPERTY_FLOAT(Camera, FieldOfView, _fieldOfView)
	DEF_PROPERTY_FLOAT(Camera, AspectRatio, _aspectRatio)
	DEF_PROPERTY_FLOAT(Camera, NearPlane, _nearPlane)
	DEF_PROPERTY_FLOAT(Camera, FarPlane, _farPlane)

	DEF_PROPERTY(Camera, Math::Vec3F, XAxis, _xAxis)
	DEF_PROPERTY(Camera, Math::Vec3F, YAxis, _yAxis)
	DEF_PROPERTY(Camera, Math::Vec3F, ZAxis, _zAxis)

	/// <summary>Конструктор класса.</summary>
	/// <param name="name">Имя камеры.</param>
	Camera::Camera(std::string name) : ICameraBase(name)
	{
		_projectionMatrix.SetIdentity();
		_viewMatrix.SetIdentity();
		_viewProjectionMatrix.SetIdentity();

		_position = VEC3F_ZERO;
		_target = VEC3F_ZERO;

		_orientation.Identity();

		_fieldOfView = CAMERA_FOV;

		_xAxis = VEC3F_UNIT_X;
		_yAxis = VEC3F_UNIT_Y;
		_zAxis = VEC3F_UNIT_Z;

		_enableFrustum = true;
	}

	/// <summary>Деструктор класса.</summary>
	Camera::~Camera(void)
	{
	}

	void Camera::LookAt(const Math::Vec3F& target)
	{
		LookAt(_position, target, VEC3F_UNIT_Y);
	}

	void Camera::LookAt(const Math::Vec3F& eye, const Math::Vec3F& target, const Math::Vec3F& up)
	{
		_position = eye;
		_target = target;

		_zAxis = _position - target;
		_zAxis.Normalize();

		_xAxis = Math::Cross(up, _zAxis);
		_xAxis.Normalize();

		_yAxis = Math::Cross(_zAxis, _xAxis);
		_yAxis.Normalize();

		_viewMatrix.Set(0, 0, _xAxis._x);
		_viewMatrix.Set(1, 0, _xAxis._y);
		_viewMatrix.Set(2, 0, _xAxis._z);
		_viewMatrix.Set(3, 0, -Math::DotProduct(_xAxis, _position));

		_viewMatrix.Set(0, 1, _yAxis._x);
		_viewMatrix.Set(1, 1, _yAxis._y);
		_viewMatrix.Set(2, 1, _yAxis._z);
		_viewMatrix.Set(3, 1, -Math::DotProduct(_yAxis, _position));

		_viewMatrix.Set(0, 2, _zAxis._x);
		_viewMatrix.Set(1, 2, _zAxis._y);
		_viewMatrix.Set(2, 2, _zAxis._z);
		_viewMatrix.Set(3, 2, -Math::DotProduct(_zAxis, _position));

		_orientation.FromRotationMatrix(_viewMatrix);
	}

	void Camera::Perspective(float fov, float aspectRatio, float nearClip, float farClip)
	{
		_fieldOfView = fov;
		_aspectRatio = aspectRatio;
		_nearPlane = nearClip;
		_farPlane = farClip;

		_mode = PROJECTION_MODE::Perspective;
		_projectionMatrix.Perspective(_fieldOfView, aspectRatio, _nearPlane, _farPlane);

		if (_enableFrustum)
			_frustum.Construct(GetViewProjectionMatrix());
	}

	void Camera::OrthoOffCenter(float left, float top, float right, float bottom, float nearClip, float farClip)
	{
		_nearPlane = nearClip;
		_farPlane = farClip;

		_mode = PROJECTION_MODE::Orthographic;
		_projectionMatrix.OrthographicOffCenter(left, top, right, bottom, _nearPlane, _farPlane);

		if (_enableFrustum)
			_frustum.Construct(GetViewProjectionMatrix());
	}

	void Camera::Update(void)
	{
		_orientation.Normalize();
		_orientation.ToRotationMatrix(_viewMatrix);

		_xAxis = Math::Vec3F(_viewMatrix.Get(0, 0), _viewMatrix.Get(1, 0), _viewMatrix.Get(2, 0));
		_yAxis = Math::Vec3F(_viewMatrix.Get(0, 1), _viewMatrix.Get(1, 1), _viewMatrix.Get(2, 1));
		_zAxis = Math::Vec3F(_viewMatrix.Get(0, 2), _viewMatrix.Get(1, 2), _viewMatrix.Get(2, 2));

		_viewMatrix.Set(3, 0, -Math::DotProduct(_xAxis, _position));
		_viewMatrix.Set(3, 1, -Math::DotProduct(_yAxis, _position));
		_viewMatrix.Set(3, 2, -Math::DotProduct(_zAxis, _position));

		if (_enableFrustum)
			_frustum.Construct(GetViewProjectionMatrix());
	}

	void Camera::Move(Math::Vec3F& direction)
	{
		_position += _xAxis * direction._x;
		_position += _yAxis * direction._y;
		_position += _zAxis * direction._z;

		Update();
	}

	void Camera::Rotation(float yaw, float pitch, float roll)
	{
		Math::Quaternion rotation;

		if (yaw != 0.0f)
		{
			rotation.FromAxisAngle(VEC3F_UNIT_Y, Math::DegreesToRadians(yaw));
			_orientation = rotation * _orientation;
		}

		if(pitch != 0.0f)
		{
			rotation.FromAxisAngle(VEC3F_UNIT_X, Math::DegreesToRadians(pitch));
			_orientation = _orientation * rotation;
		}

		if(roll != 0.0f)
		{
			rotation.FromAxisAngle(VEC3F_UNIT_Z, Math::DegreesToRadians(roll));
			_orientation = _orientation * rotation;
		}

		Update();
	}

	const Math::Matrix4F& Camera::GetProjectionMatrix(void)
	{
		return _projectionMatrix;
	}

	const Math::Matrix4F& Camera::GetViewMatrix(void)
	{
		return _viewMatrix;
	}

	const Math::Matrix4F& Camera::GetViewProjectionMatrix(void)
	{
		Math::Matrix4F::Multiply(_projectionMatrix, _viewMatrix, &_viewProjectionMatrix);
		return _viewProjectionMatrix;
	}

	const Math::Matrix4F& Camera::GetInverseViewProjectionMatrix(void)
	{
		Math::Mat4F inverse;
		GetViewProjectionMatrix().Invert(&inverse);

		return inverse;
	}

	void Camera::SetFrustum(bool enable)
	{
		_enableFrustum = enable;

		if (_enableFrustum)
			_frustum.Construct(GetViewProjectionMatrix());
	}

	const Math::Frustum& Camera::GetFrustum(void)
	{
		return _frustum;
	}

	bool Camera::IsVisible(const Math::BoundingBox& box) const
	{
		if (_enableFrustum && _frustum.IsBoundingBoxInside(box) != Math::FRUSTUM_ASPECT::Outside)
			return true;

		return false;
	}

	void Camera::SetPosition(Math::Vec3F& position)
	{
		_position = position;
	}

	Math::Vec3F Camera::GetPosition(void) const
	{
		return _position;
	}

	Math::Quaternion Camera::GetOrientation(void) const
	{
		return _orientation;
	}

	Math::Vec3F Camera::GetFront(void) const
	{
		return -_zAxis;
	}

	Math::Vec3F Camera::GetBack(void) const
	{
		return _zAxis;
	}

	Math::Vec3F Camera::GetLeft(void) const
	{
		return -_xAxis;
	}

	Math::Vec3F Camera::GetRight(void) const
	{
		return _xAxis;
	}

	Math::Vec3F Camera::GetUp(void) const
	{
		return _yAxis;
	}

	Math::Vec3F Camera::GetDown(void) const
	{
		return -_yAxis;
	}

	PROJECTION_MODE Camera::GetMode(void) const
	{
		return _mode;
	}
}