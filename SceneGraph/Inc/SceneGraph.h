#ifndef SCENEGRAPH_H
#define SCENEGRAPH_H

#include "../../SDK/SceneGraph/SceneGraphBase.h"
#include "../../SDK/Core/Scene/RenderableBase.h"
#include "../../SDK/Platform.h"

#include <vector>

namespace Scene
{
	class ISceneNodeBase;
	class ISceneComponentBase;
	class ICameraBase;
	class SceneGraph : public ISceneGraphBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		SceneGraph(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~SceneGraph(void);

		virtual ICameraBase* CreateCamera(const char* name);

		virtual void DestroyCamera(const char* name);

		virtual void SetActiveCamera(ICameraBase* camera);

		virtual ICameraBase* GetActiveCamera(void);

		virtual ISceneComponentBase* CreateSprite(const char* name);

		virtual ISceneComponentBase* CreateBox(const char* name);

		virtual ISceneComponentBase* CreateSphere(const char* name);

		/// <summary>Полностью очищает сцену.</summary>
		virtual void Clear(void);

		virtual ISceneNodeBase* GetRootSceneNode(void);

	private:
		ISceneNodeBase* rootSceneNode;

		std::vector<IRenderableBase*> renderables;

		typedef std::map<std::string, ICameraBase*> ICameraMap;
		ICameraMap cameras;
		ICameraBase* activeCamera;
	};
}

#endif // SCENEGRAPH_H