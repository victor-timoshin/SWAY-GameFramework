#ifndef CAMERA_H
#define CAMERA_H

#include "../../SDK/SceneGraph/CameraBase.h"

namespace Scene
{
	class Camera : public ICameraBase
	{
		DECL_PROPERTY_VIRTUAL_FLOAT(FieldOfView, _fieldOfView)
		DECL_PROPERTY_VIRTUAL_FLOAT(AspectRatio, _aspectRatio)
		DECL_PROPERTY_VIRTUAL_FLOAT(NearPlane, _nearPlane)
		DECL_PROPERTY_VIRTUAL_FLOAT(FarPlane, _farPlane)

		DECL_PROPERTY_VIRTUAL(Math::Vec3F, XAxis, _xAxis)
		DECL_PROPERTY_VIRTUAL(Math::Vec3F, YAxis, _yAxis)
		DECL_PROPERTY_VIRTUAL(Math::Vec3F, ZAxis, _zAxis)

	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя камеры.</param>
		Camera(std::string name);
		
		/// <summary>Деструктор класса.</summary>
		virtual ~Camera(void);

		virtual void LookAt(const Math::Vec3F& target);

		virtual void LookAt(const Math::Vec3F& eye, const Math::Vec3F& target, const Math::Vec3F& up);

		virtual void Perspective(float fov, float aspectRatio, float nearClip = 0.1f, float farClip = 1000.0f);

		virtual void OrthoOffCenter(float left, float top, float right, float bottom, float nearClip = 1.0f, float farClip = 0.0f);

		//virtual void SwitchToPerspective(float fieldOfView, float nearClip = 0.1f, float farClip = 1000.0f);

		//virtual void SwitchToOrtho(void);

		virtual void Update(void);

		virtual void Move(Math::Vec3F& direction);

		virtual void Rotation(float yaw, float pitch, float roll);

		virtual const Math::Matrix4F& GetProjectionMatrix(void);

		virtual const Math::Matrix4F& GetViewMatrix(void);

		virtual const Math::Matrix4F& GetViewProjectionMatrix(void);

		virtual const Math::Matrix4F& GetInverseViewProjectionMatrix(void);

		virtual void SetFrustum(bool enable);

		virtual const Math::Frustum& GetFrustum(void);

		virtual bool IsVisible(const Math::BoundingBox& box) const;
		
		//virtual void SetZoom(float delta);

		//virtual float GetZoom(void) const;

		//virtual void ResetZoom();

		virtual void SetPosition(Math::Vec3F& position);

		virtual Math::Vec3F GetPosition(void) const;

		virtual Math::Quaternion GetOrientation(void) const;

		virtual Math::Vec3F GetFront(void) const;
		virtual Math::Vec3F GetBack(void) const;
		virtual Math::Vec3F GetLeft(void) const;
		virtual Math::Vec3F GetRight(void) const;
		virtual Math::Vec3F GetUp(void) const;
		virtual Math::Vec3F GetDown(void) const;

		virtual PROJECTION_MODE GetMode(void) const;

		//virtual void InjectMouseMove(int x, int y) {}
		//virtual void InjectMouseDown(int x, int y) {}
		//virtual void InjectMouseRelease() {}
		//virtual void InjectWheelUp(void) {}
		//virtual void InjectWheelDown(void) {}

		//virtual void SetPosition(const Math::Vec2F& position) {}
		//virtual void SetDistance(float distance) {}

	protected:
		//Math::Vec3F UnprojectViewPoint(const Math::Vec3F& screen, const Math::Size& view);

	protected:
		PROJECTION_MODE _mode;

		Math::Matrix4F _projectionMatrix;
		Math::Matrix4F _viewMatrix;
		Math::Matrix4F _viewProjectionMatrix;

		Math::Vec3F _position;
		Math::Vec3F _target;

		Math::Quaternion _orientation;

		Math::Frustum _frustum;
		bool _enableFrustum;
	};
}

#endif