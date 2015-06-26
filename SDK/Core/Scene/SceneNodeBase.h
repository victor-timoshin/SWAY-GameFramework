#ifndef SCENE_NODE_BASE_H
#define SCENE_NODE_BASE_H

#include "../../../SDK/Core/Scene/SceneComponentBase.h"
#include "../../../SDK/Core/Utils/Hierarchy.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
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
	};

	CORE_API ISceneNodeBase* RegisterSceneNode();
}

#endif // SCENE_NODE_BASE_H