#ifndef CAMERABASE_H
#define CAMERABASE_H

#include "ProjectionMode.h"
#include "../../Math/Inc/Quaternion.h"
#include "../../Math/Inc/Matrix4F.h"
#include "../../Math/Inc/Vector3.h"
#include "../../Math/Inc/Vector2.h"
#include "../../Math/Inc/Size.h"
#include "../../Math/Inc/MathCommon.h"
#include "../../Math/Inc/Frustum.h"

#include <string>

#define CAMERA_FOV 45.0f

#define CAMERA_PERSP_NEAR_CLIP 0.1f
#define CAMERA_PERSP_FAR_CLIP 100.0f

#define CAMERA_ORTHO_NEAR_CLIP 1.0f
#define CAMERA_ORTHO_FAR_CLIP 0.0f

namespace Scene
{
	class ICameraBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя камеры.</param>
		ICameraBase(std::string name) {}
		
		/// <summary>Деструктор класса.</summary>
		virtual ~ICameraBase(void) {}

		virtual void LookAt(const Math::Vec3F& target) = 0;

		virtual void LookAt(const Math::Vec3F& eye, const Math::Vec3F& target, const Math::Vec3F& up) = 0;

		virtual void Perspective(float fov, float aspectRatio, float nearClip = CAMERA_PERSP_NEAR_CLIP, float farClip = CAMERA_PERSP_FAR_CLIP) = 0;
		
		virtual void OrthoOffCenter(float left, float top, float right, float bottom, float nearClip = CAMERA_ORTHO_NEAR_CLIP, float farClip = CAMERA_ORTHO_FAR_CLIP) = 0;

		virtual void Update(void) = 0;

		virtual void Move(Math::Vec3F& direction) = 0;

		virtual void Rotation(float yaw, float pitch, float roll) = 0;

		virtual const Math::Matrix4F& GetProjectionMatrix(void) = 0;

		virtual const Math::Matrix4F& GetViewMatrix(void) = 0;

		virtual const Math::Matrix4F& GetViewProjectionMatrix(void) = 0;

		virtual const Math::Matrix4F& GetInverseViewProjectionMatrix(void) = 0;

		virtual void SetFrustum(bool enable) = 0;

		virtual const Math::Frustum& GetFrustum(void) = 0;

		virtual bool IsVisible(const Math::BoundingBox& box) const = 0;

		virtual void SetPosition(Math::Vec3F& position) = 0;

		virtual Math::Vec3F GetPosition(void) const = 0;

		virtual Math::Quaternion GetOrientation(void) const = 0;

		virtual void SetFieldOfView(float fov) = 0;

		virtual float GetFieldOfView(void) const = 0;

		virtual void SetNearPlane(float value) = 0;

		virtual float GetNearPlane(void) const = 0;

		virtual void SetFarPlane(float value) = 0;

		virtual float GetFarPlane(void) const = 0;

		virtual void SetXAxis(Math::Vec3F axis) = 0;
		virtual Math::Vec3F GetXAxis(void) const = 0;

		virtual void SetYAxis(Math::Vec3F axis) = 0;
		virtual Math::Vec3F GetYAxis(void) const = 0;

		virtual void SetZAxis(Math::Vec3F axis) = 0;
		virtual Math::Vec3F GetZAxis(void) const = 0;

		virtual Math::Vec3F GetFront(void) const = 0;
		virtual Math::Vec3F GetBack(void) const = 0;
		virtual Math::Vec3F GetLeft(void) const = 0;
		virtual Math::Vec3F GetRight(void) const = 0;
		virtual Math::Vec3F GetUp(void) const = 0;
		virtual Math::Vec3F GetDown(void) const = 0;

		virtual PROJECTION_MODE GetMode(void) const = 0;

		//virtual void InjectMouseMove(int x, int y) = 0;
		//virtual void InjectMouseDown(int x, int y) = 0;
		//virtual void InjectMouseRelease(void) = 0;
		//virtual void InjectWheelUp(void) = 0;
		//virtual void InjectWheelDown(void) = 0;

		//virtual void SetPosition(const Math::Vec2F& position) = 0;
		//virtual void SetDistance(float distance) = 0;
	};
}

#endif // CAMERABASE_H