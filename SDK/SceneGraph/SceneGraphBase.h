#ifndef SCENEGRAPHBASE_H
#define SCENEGRAPHBASE_H

#include "../Platform.h"

namespace Scene
{
	class ISceneNodeBase;
	class ISceneComponentBase;
	class ICameraBase;
	class ISceneGraphBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ISceneGraphBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ISceneGraphBase(void) {}

		virtual ICameraBase* CreateCamera(const char* name) = 0;

		virtual void DestroyCamera(const char* name) = 0;

		virtual void SetActiveCamera(ICameraBase* camera) = 0;

		virtual ICameraBase* GetActiveCamera(void) = 0;

		virtual ISceneComponentBase* CreateSprite(const char* name) = 0;

		virtual ISceneComponentBase* CreateBox(const char* name) = 0;

		virtual ISceneComponentBase* CreateSphere(const char* name) = 0;

		/// <summary>Полностью очищает сцену.</summary>
		virtual void Clear(void) = 0;

		virtual ISceneNodeBase* GetRootSceneNode(void) = 0;
	};

	CORE_API ISceneGraphBase* RegisterSceneGraph(void);
}

#endif // SCENEGRAPHBASE_H