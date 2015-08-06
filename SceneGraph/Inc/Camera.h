#ifndef CAMERA_H
#define CAMERA_H

#include "../../SDK/SceneGraph/CameraBase.h"

namespace Scene
{
	class Camera : public ICameraBase
	{
	public:
		static const Math::Vector3 WORLD_XAXIS;
		static const Math::Vector3 WORLD_YAXIS;
		static const Math::Vector3 WORLD_ZAXIS;

		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя камеры.</param>
		Camera(std::string name);
		
		/// <summary>Деструктор класса.</summary>
		virtual ~Camera(void) {}

		virtual void LookAt(void);

		virtual void Perspective(float fov, float aspectRatio, float nearClip = 0.1f, float farClip = 1000.0f);

		virtual void OrthoOffCenter(float left, float top, float right, float bottom, float nearClip = 1.0f, float farClip = 0.0f);

		virtual void Update(void);

		virtual void Move(Math::Vector3& direction);

		virtual void Rotation(float yaw, float pitch, float roll);

		virtual const Math::Matrix4& GetViewMatrix(void);

		virtual const Math::Matrix4& GetProjectionMatrix(void);

		virtual void SetPosition(Math::Vector3& eye);

		virtual Math::Vector3 GetPosition(void) const;

		virtual Math::Quaternion GetOrientation(void) const;

		virtual void SetNearClipDistance(float value);

		virtual float GetNearClipDistance(void) const;

		virtual void SetFarClipDistance(float value);

		virtual float GetFarClipDistance(void) const;

		virtual Math::Vector3 GetXAxis(void);

		virtual Math::Vector3 GetYAxis(void);

		virtual Math::Vector3 GetZAxis(void);

	private:
		Math::Matrix4 projectionMatrix;
		Math::Matrix4 viewMatrix;

		float fov;
		float nearClip;
		float farClip;

		Math::Vector3 eye;
		Math::Vector3 target;

		Math::Quaternion orientation;

		Math::Vector3 xAxis;
		Math::Vector3 yAxis;
		Math::Vector3 zAxis;
	};
}

#endif
