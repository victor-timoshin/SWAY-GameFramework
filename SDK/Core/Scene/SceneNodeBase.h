#ifndef SCENE_NODE_BASE_H
#define SCENE_NODE_BASE_H

#include "../../../SDK/Core/Scene/SceneComponentBase.h"
#include "../../../SDK/Core/Utils/Hierarchy.h"
#include "../../../SDK/Core/Math/Quaternion.h"
#include "../../../SDK/Platform.h"

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
		/** Constructor. */
		ISceneNodeBase(std::string name) : Utils::THierarchy<ISceneNodeBase>(name) {}

		/** Destructor. */
		virtual ~ISceneNodeBase() {}

		virtual ISceneNodeBase* CreateChild(const char* name) = 0;

		virtual void Attach(ISceneComponentBase* subscriber) = 0;

		virtual void Detach(ISceneComponentBase* subscriber) = 0;

		virtual void DetachAll() = 0;


		virtual void SetPosition(float x, float y, float z) = 0;

		virtual void SetRotation(Core::Math::Vector3 axis, float Angle, TransformSpace relativeTo) = 0;

		virtual void SetScale(float x, float y, float z) = 0;

		virtual void SetOrientation(float w, float x, float y, float z) = 0;

		virtual void SetOrientation(const Core::Math::Quaternion& orientation) = 0;

		virtual Core::Math::Matrix4 GetMatrixWorldTransform() = 0;

		virtual const Core::Math::Quaternion& GetOrientation() const = 0;

		virtual const Core::Math::Vector3& GetPosition() const = 0;

		virtual Core::Math::Vector3 GetScale() = 0;
	};

	CORE_API ISceneNodeBase* RegisterSceneNode();
}

#endif // SCENE_NODE_BASE_H