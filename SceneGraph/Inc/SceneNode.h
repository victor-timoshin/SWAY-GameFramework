#ifndef SCENENODE_H
#define SCENENODE_H

#include "../../SDK/SceneGraph/SceneNodeBase.h"
#include "../../SDK/SceneGraph/SceneNodeTypes.h"
#include "../../SDK/Platform.h"

namespace Scene
{
	class SceneNode: public ISceneNodeBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя узла.</param>
		SceneNode(std::string name);

		/// <summary>Деструктор класса.</summary>
		virtual ~SceneNode(void) { }

		virtual ISceneNodeBase* CreateChild(const char* name);

		virtual void Attach(ISceneComponentBase* subscriber);

		virtual void Detach(ISceneComponentBase* subscriber);

		virtual void DetachAll(void);

		virtual ISceneComponentBase* GetAttachedComponentByName(const char* name);


		virtual void SetPosition(float x, float y, float z);

		virtual void SetRotation(Math::Vector3 axis, float angle, TransformSpace relativeTo);

		virtual void SetScale(float x, float y, float z);

		virtual void SetOrientation(float w, float x, float y, float z);

		virtual void SetOrientation(const Math::Quaternion& orientation);

		virtual Math::Matrix4 GetWorldMatrixTransform(void);

		virtual const Math::Quaternion& GetOrientation(void) const;

		virtual const Math::Vector3& GetPosition(void) const;

		virtual Math::Vector3 GetScale(void);

	private:
		typedef std::map<std::string, ISceneComponentBase*> IComponentMap;
		IComponentMap components;

		Math::Matrix4 matrixWorld;

		Math::Quaternion orientation;
		Math::Quaternion rotation;

		Math::Vector3 position;
		Math::Vector3 scale;
	};
}

#endif // SCENENODE_H