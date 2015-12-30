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

		virtual ISceneNodeBase* GetRootSceneNode(void);

		virtual ICameraBase* CreateCamera(const char* name);

		virtual void DestroyCamera(const char* name);

		/// <summary>Устанавливает активную камеру.</summary>
		virtual void SetActiveCamera(ICameraBase* camera);

		/// <summary>Устанавливает активную камеру по имени.</summary>
		/// <param name="name">Имя камеры.</param>
		virtual void SetActiveCameraByName(const char* name);

		/// <summary>Получает указатель на активную камеру.</summary>
		virtual ICameraBase* GetActiveCamera(void);

		/// <summary>Получает число камер в сцене.</summary>
		virtual int GetCameraCount(void) const;

		/// <summary>Создает спрайт.</summary>
		/// <param name="name">Имя спрайта.</param>
		virtual ISceneComponentBase* CreateSprite(const char* name);

		virtual ISceneComponentBase* CreateBox(const char* name);

		virtual ISceneComponentBase* CreateSphere(const char* name);

		virtual void Update(void);

		/// <summary>Полностью очищает сцену.</summary>
		virtual void Clear(void);

	private:
		ISceneNodeBase* _rootSceneNode;

		std::vector<IRenderableBase*> renderables;

		typedef std::map<std::string, ICameraBase*> ICameraMap;
		ICameraMap _cameras;
		ICameraBase* _activeCamera;
	};
}

#endif // SCENEGRAPH_H