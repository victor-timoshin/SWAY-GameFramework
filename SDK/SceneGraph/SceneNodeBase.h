#ifndef SCENENODEBASE_H
#define SCENENODEBASE_H

#include "TransformableBase.h"
#include "../SceneGraph/SceneComponentBase.h"
#include "../Core/Utils/Hierarchy.h"
#include "../Platform.h"

namespace Scene
{
	class ISceneNodeBase : public Utils::THierarchy<ISceneNodeBase>, public ITransformableBase
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

		virtual void CascadeUpdate(void) = 0;
	};

	CORE_API ISceneNodeBase* RegisterSceneNode(std::string name);
}

#endif // SCENENODEBASE_H