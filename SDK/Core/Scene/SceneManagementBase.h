#ifndef SCENE_MANAGEMENT_BASE_H
#define SCENE_MANAGEMENT_BASE_H

#include "../../../SDK/Core/Scene/SceneGraphBase.h"
#include "../../../SDK/Core/Utils/Singleton.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class ISceneStateBase;
	class ISceneManagementBase : public Utils::TSingleton<ISceneManagementBase>
	{
	public:
		/** Constructor. */
		ISceneManagementBase() {}

		/** Destructor. */
		virtual ~ISceneManagementBase() {}

		virtual void FrameStarted(float timeStep) = 0;

		virtual void FrameEnded() = 0;

		virtual void ChangeState(ISceneStateBase* sceneState, ISceneGraphBase* sceneGraph) = 0;

		virtual void PushState(ISceneStateBase* sceneState, ISceneGraphBase* sceneGraph) = 0;

		virtual void PopState() = 0;
	};

	CORE_API ISceneManagementBase* RegisterSceneManagement();
}

#endif // SCENE_MANAGEMENT_BASE_H