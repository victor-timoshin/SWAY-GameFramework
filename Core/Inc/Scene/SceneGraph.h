#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "../../../SDK/Core/Scene/SceneGraphBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class ISceneNodeBase;
	class ISceneComponentBase;
	class ICameraBase;
	class SceneGraph : public ISceneGraphBase
	{
	public:
		/** Constructor. */
		SceneGraph(Render::IRenderSystemBase* render);

		/** Destructor. */
		virtual ~SceneGraph();

		virtual ICameraBase* CreateCamera(const char* name);

		virtual void DestroyCamera(const char* name);

		virtual void SetActiveCamera(ICameraBase* camera);

		virtual ICameraBase* GetActiveCamera();

		virtual ISceneComponentBase* CreateSprite(const char* name);

		virtual ISceneComponentBase* CreateBox(const char* name);

		virtual ISceneComponentBase* CreateSphere(const char* name);

		virtual void Clear();

		virtual ISceneNodeBase* GetRootSceneNode();

	private:
		Render::IRenderSystemBase* renderSystem;
		ISceneNodeBase* rootSceneNode;

		typedef std::map<std::string, ICameraBase*> ICameraMap;
		ICameraMap cameras;
		ICameraBase* activeCamera;
	};
}

#endif // SCENE_GRAPH_H