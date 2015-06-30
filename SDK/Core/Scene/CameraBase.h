#ifndef CAMERA_BASE_H
#define CAMERA_BASE_H

#include "../../../SDK/Core/Math/BoundingVolume.h"
#include "../../../SDK/Core/Math/Quaternion.h"
#include "../../../SDK/Core/Math/Matrix4.h"
#include "../../../SDK/Core/Math/Vector3.h"
#include "../../../SDK/Core/Math/MathCommon.h"

#include <string>

namespace Scene
{
	typedef struct PlaneDataDesc
	{
		float _a;
		float _b;
		float _c;
		float _d;
	} LPLANEDATA_DESC, PPLANEDATA_DESC;

	class ICameraBase
	{
	public:
		ICameraBase(std::string name) {}
		
		virtual ~ICameraBase() {}

		virtual void LookAt() = 0;

		virtual void Perspective(float fov, float aspectRatio, float nearClip = 0.1f, float farClip = 1000.0f) = 0;
		
		virtual void OrthoOffCenter(float left, float top, float right, float bottom, float nearClip = 1.0f, float farClip = 0.0f) = 0;

		virtual void Update() = 0;

		virtual bool ContainsBoundingVolume(Core::Math::BoundingVolume& box, Core::Math::Vector3& position) = 0;

		virtual void Move(Core::Math::Vector3& direction) = 0;

		virtual void Rotation(float yaw, float pitch, float roll) = 0;

		virtual const Core::Math::Matrix4& GetMatrixView() = 0;

		virtual const Core::Math::Matrix4& GetMatrixProjection() = 0;

		virtual void SetPosition(Core::Math::Vector3& eye) = 0;

		virtual Core::Math::Vector3 GetPosition() const = 0;

		virtual float GetNearClip() const = 0;

		virtual float GetFarClip() const = 0;

		virtual Core::Math::Vector3 GetXAxis() = 0;

		virtual Core::Math::Vector3 GetYAxis() = 0;

		virtual Core::Math::Vector3 GetZAxis() = 0;
	};
}

#endif // CAMERA_BASE_H