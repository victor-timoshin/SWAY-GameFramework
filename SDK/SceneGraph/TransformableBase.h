#ifndef TRANSFORMABLEBASE_H
#define TRANSFORMABLEBASE_H

#include "../../Math/Inc/Quaternion.h"
#include "../../Math/Inc/Vector3.h"
#include "../../Math/Inc/MathCommon.h"
#include "../Platform.h"

namespace Scene
{
	enum TransformSpace
	{
		TRANSFORM_PARENT,
		TRANSFORM_WORLD,
		TRANSFORM_LOCAL
	};

	class ITransformableBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ITransformableBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ITransformableBase(void) {}

		virtual void SetPosition(const Math::Vector3& position, TransformSpace relativeTo = TRANSFORM_WORLD) = 0;

		virtual void SetPosition(float x, float y, float z, TransformSpace relativeTo = TRANSFORM_WORLD) = 0;

		virtual void SetTranslate(const Math::Vector3& translate, TransformSpace relativeTo = TRANSFORM_WORLD) = 0;

		virtual void SetTranslate(float x, float y, float z, TransformSpace relativeTo = TRANSFORM_WORLD) = 0;

		virtual void SetRotation(Math::Vector3 axis, float angle, TransformSpace relativeTo = TRANSFORM_WORLD) = 0;

		virtual void SetScale(float x, float y, float z) = 0;

		virtual void SetOrientation(float w, float x, float y, float z) = 0;

		virtual void SetOrientation(const Math::Quaternion& orientation) = 0;

		virtual Math::Matrix4 GetWorldMatrixTransform(void) = 0;

		virtual const Math::Quaternion& GetOrientation(void) const = 0;

		virtual const Math::Vector3& GetPosition(void) const = 0;

		virtual Math::Vector3 GetScale(void) = 0;
	};
}

#endif // TRANSFORMABLEBASE_H