#ifndef SCENE_GRAPH_BASE_H
#define SCENE_GRAPH_BASE_H

#include "../../../SDK/Core/Render/RenderSystemBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class ISceneNodeBase;
	class ISceneComponentBase;
	class ISceneGraphBase
	{
	public:
		/** Constructor. */
		ISceneGraphBase(Render::IRenderSystemBase* render) {}

		/** Destructor. */
		virtual ~ISceneGraphBase() {}

		virtual ISceneComponentBase* CreateSprite(const char* name) = 0;

		virtual ISceneComponentBase* CreateBox(const char* name) = 0;

		virtual ISceneComponentBase* CreateSphere(const char* name) = 0;

		virtual void Clear() = 0;

		virtual ISceneNodeBase* GetRootSceneNode() = 0;
	};

	CORE_API ISceneGraphBase* RegisterSceneGraph(Render::IRenderSystemBase* render);
}

#endif // SCENE_GRAPH_BASE_H