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

	private:
		typedef std::map<std::string, ISceneComponentBase*> IComponentMap;
		IComponentMap components;
	};

}

#endif // SCENE_NODE_H