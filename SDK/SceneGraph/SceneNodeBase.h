#ifndef SCENENODEBASE_H
#define SCENENODEBASE_H

#include "../SceneGraph/SceneComponentBase.h"
#include "../Core/Utils/Hierarchy.h"
#include "../Math/Quaternion.h"
#include "../Platform.h"

namespace Scene
{
	enum TransformSpace
	{
		TRANSFORM_PARENT,
		TRANSFORM_WORLD,
		TRANSFORM_LOCAL
	};

	class ISceneNodeBase : public Utils::THierarchy < ISceneNodeBase >
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя узла.</param>
		ISceneNodeBase(std::string name) : Utils::THierarchy<ISceneNodeBase>(name) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ISceneNodeBase(void) {}

		virtual ISceneNodeBase* CreateChild(const char* name) = 0;

		virtual void Attach(ISceneComponentBase* subscriber) = 0;

		virtual void Detach(ISceneComponentBase* subscriber) = 0;

		virtual void DetachAll(void) = 0;

		virtual ISceneComponentBase* GetAttachedComponentByName(const char* name) = 0;


		virtual void SetPosition(float x, float y, float z) = 0;

		virtual void SetRotation(Math::Vector3 axis, float angle, TransformSpace relativeTo) = 0;

		virtual void SetScale(float x, float y, float z) = 0;

		virtual void SetOrientation(float w, float x, float y, float z) = 0;

		virtual void SetOrientation(const Math::Quaternion& orientation) = 0;

		virtual Math::Matrix4 GetWorldMatrixTransform(void) = 0;

		virtual const Math::Quaternion& GetOrientation(void) const = 0;

		virtual const Math::Vector3& GetPosition(void) const = 0;

		virtual Math::Vector3 GetScale(void) = 0;
	};

	CORE_API ISceneNodeBase* RegisterSceneNode(std::string name);
}

#endif // SCENENODEBASE_H