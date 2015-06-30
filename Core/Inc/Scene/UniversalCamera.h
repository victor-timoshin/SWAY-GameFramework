#ifndef UNIVERSAL_CAMERA_H
#define UNIVERSAL_CAMERA_H

#include "../../../SDK/Core/Scene/CameraBase.h"

namespace Scene
{
	class UniversalCamera : public ICameraBase
	{
	public:
		UniversalCamera(std::string name);

		virtual ~UniversalCamera() {}

		virtual void LookAt();

		virtual void Perspective(float fov, float aspectRatio, float nearClip = 0.1f, float farClip = 1000.0f);

		virtual void OrthoOffCenter(float left, float top, float right, float bottom, float nearClip = 1.0f, float farClip = 0.0f);

		virtual void Update();

		virtual bool ContainsBoundingVolume(Core::Math::BoundingVolume& box, Core::Math::Vector3& position);

		virtual void Move(Core::Math::Vector3& direction);

		virtual void Rotation(float yaw, float pitch, float roll);

		virtual const Core::Math::Matrix4& GetMatrixView();

		virtual const Core::Math::Matrix4& GetMatrixProjection();

		virtual void SetPosition(Core::Math::Vector3& eye);

		virtual Core::Math::Vector3 GetPosition() const;

		virtual float GetNearClip() const;

		virtual float GetFarClip() const;

		virtual Core::Math::Vector3 GetXAxis();

		virtual Core::Math::Vector3 GetYAxis();

		virtual Core::Math::Vector3 GetZAxis();

	protected:
		void NormalizePlane(LPLANEDATA_DESC& plane);

	private:
		Core::Math::Matrix4 matrixProjection;
		Core::Math::Matrix4 matrixView;

		float fov;
		float aspectRatio;
		float nearClip;
		float farClip;

		LPLANEDATA_DESC planes[6];

		Core::Math::Vector3 eye;
		Core::Math::Vector3 target;

		Core::Math::Quaternion orientation;

		Core::Math::Vector3 xAxis;
		Core::Math::Vector3 yAxis;
		Core::Math::Vector3 zAxis;
	};
}

#endif
