#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "../../../SDK/Core/Scene/SceneGraphBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class ISceneNodeBase;
	class ISceneComponentBase;
	class SceneGraph : public ISceneGraphBase
	{
	public:
		/** Constructor. */
		SceneGraph(Render::IRenderSystemBase* render);

		/** Destructor. */
		virtual ~SceneGraph();

		virtual ISceneComponentBase* CreateBox(const char* name);

		virtual void Clear();

		virtual ISceneNodeBase* GetRootSceneNode();

	private:
		Render::IRenderSystemBase* renderSystem;
		ISceneNodeBase* rootSceneNode;
	};
}

#endif // SCENE_GRAPH_H