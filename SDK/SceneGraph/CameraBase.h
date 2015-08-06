#ifndef CAMERABASE_H
#define CAMERABASE_H

#include "../../Math/Inc/BoundingVolume.h"
#include "../../Math/Inc/Quaternion.h"
#include "../../Math/Inc/Matrix4.h"
#include "../../Math/Inc/Vector3.h"
#include "../../Math/Inc/MathCommon.h"

#include <string>

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

		virtual void LookAt(void) = 0;

		virtual void Perspective(float fov, float aspectRatio, float nearClip = 0.1f, float farClip = 1000.0f) = 0;
		
		virtual void OrthoOffCenter(float left, float top, float right, float bottom, float nearClip = 1.0f, float farClip = 0.0f) = 0;

		virtual void Update(void) = 0;

		virtual void Move(Math::Vector3& direction) = 0;

		virtual void Rotation(float yaw, float pitch, float roll) = 0;

		virtual const Math::Matrix4& GetViewMatrix(void) = 0;

		virtual const Math::Matrix4& GetProjectionMatrix(void) = 0;

		virtual void SetPosition(Math::Vector3& eye) = 0;

		virtual Math::Vector3 GetPosition(void) const = 0;

		virtual Math::Quaternion GetOrientation(void) const = 0;

		virtual void SetNearClipDistance(float value) = 0;

		virtual float GetNearClipDistance(void) const = 0;

		virtual void SetFarClipDistance(float value) = 0;

		virtual float GetFarClipDistance(void) const = 0;

		virtual Math::Vector3 GetXAxis(void) = 0;

		virtual Math::Vector3 GetYAxis(void) = 0;

		virtual Math::Vector3 GetZAxis(void) = 0;
	};
}

#endif // CAMERABASE_H