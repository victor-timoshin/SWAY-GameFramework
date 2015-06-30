#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include "../../../SDK/Core/Scene/SceneNodeBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class SceneNode: public ISceneNodeBase
	{
	public:
		/** Constructor. */
		SceneNode(std::string name);

		/** Destructor. */
		virtual ~SceneNode();

		virtual ISceneNodeBase* CreateChild(const char* name);

		virtual void Attach(ISceneComponentBase* subscriber);

		virtual void Detach(ISceneComponentBase* subscriber);

		virtual void DetachAll();


		virtual void SetPosition(float x, float y, float z);

		virtual void SetRotation(Core::Math::Vector3 axis, float Angle, TransformSpace relativeTo);

		virtual void SetScale(float x, float y, float z);

		virtual void SetOrientation(float w, float x, float y, float z);

		virtual void SetOrientation(const Core::Math::Quaternion& orientation);

		virtual Core::Math::Matrix4 GetMatrixWorldTransform();

		virtual const Core::Math::Quaternion& GetOrientation() const;

		virtual const Core::Math::Vector3& GetPosition() const;

		virtual Core::Math::Vector3 GetScale();

	private:
		typedef std::map<std::string, ISceneComponentBase*> IComponentMap;
		IComponentMap components;

		Core::Math::Matrix4 matrixWorld;

		Core::Math::Quaternion orientation;
		Core::Math::Quaternion rotation;

		Core::Math::Vector3 position;
		Core::Math::Vector3 scale;
	};

}

#endif // SCENE_NODE_H