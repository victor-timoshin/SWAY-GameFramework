#ifndef SCENENODE_H
#define SCENENODE_H

#include "../../SDK/SceneGraph/SceneNodeBase.h"
#include "../../SDK/SceneGraph/SceneNodeTypes.h"
#include "../../SDK/Platform.h"

#include "SceneNodeQueue.h"

namespace Scene
{
	class SceneNode : public ISceneNodeBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="name">Имя узла.</param>
		SceneNode(std::string name);

		/// <summary>Деструктор класса.</summary>
		virtual ~SceneNode(void) {}

		virtual ISceneNodeBase* CreateChild(const char* name);

		virtual void Attach(ISceneComponentBase* subscriber);

		virtual void Detach(ISceneComponentBase* subscriber);

		virtual void DetachAll(void);

		virtual ISceneComponentBase* GetAttachedComponentByName(const char* name);

		virtual void CascadeUpdate(void);

		virtual void SetPosition(const Math::Vector3F& position, TransformSpace relativeTo);

		virtual void SetPosition(float x, float y, float z, TransformSpace relativeTo);

		virtual void SetTranslate(const Math::Vector3F& translate, TransformSpace relativeTo);

		virtual void SetTranslate(float x, float y, float z, TransformSpace relativeTo);

		virtual void SetRotation(Math::Vector3F axis, float angle, TransformSpace relativeTo);

		virtual void SetScale(float x, float y, float z);

		virtual void SetOrientation(float w, float x, float y, float z);

		virtual void SetOrientation(const Math::Quaternion& orientation);

		virtual Math::Matrix4F GetWorldMatrix(void);

		virtual Math::Matrix4F GetMatrix(void);

		virtual const Math::Quaternion& GetOrientation(void) const;

		virtual const Math::Vector3F& GetPosition(void) const;

		virtual Math::Vector3F GetScale(void);

	private:
		typedef std::map<std::string, ISceneComponentBase*> IComponentMap;
		IComponentMap _components;

		Math::Matrix4F _matrixWorld;

		Math::Quaternion _orientation;
		Math::Quaternion _rotation;

		Math::Vector3F _position;
		Math::Vector3F _scale;
	};
}

#endif // SCENENODE_H