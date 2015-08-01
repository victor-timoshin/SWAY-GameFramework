#ifndef SCENEMANAGEMENTBASE_H
#define SCENEMANAGEMENTBASE_H

#include "../../OIS/InputBase.h"
#include "../../Core/Render/RenderSystemBase.h"
#include "../../SceneGraph/SceneGraphBase.h"
#include "../../Core/Utils/Singleton.h"
#include "../../Platform.h"

namespace Scene
{
	class ISceneStateBase;
	class ISceneManagementBase : public Utils::TSingleton<ISceneManagementBase>
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ISceneManagementBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~ISceneManagementBase(void) {}

		virtual void FrameStarted(OIS::IInputBase* event, float timeStep) = 0;

		virtual void FrameEnded(void) = 0;

		virtual void ChangeState(ISceneStateBase* sceneState, Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph) = 0;

		virtual void PushState(ISceneStateBase* sceneState, Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph) = 0;

		virtual void PopState(void) = 0;
	};

	CORE_API ISceneManagementBase* RegisterSceneManagement(void);
}

#endif // SCENEMANAGEMENTBASE_H