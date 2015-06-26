#ifndef SCENE_MANAGEMENT_H
#define SCENE_MANAGEMENT_H

#include "../../../SDK/Core/Scene/SceneManagementBase.h"
#include "../../../SDK/Core/Scene/SceneStateBase.h"
#include "../../../SDK/Platform.h"

#include <vector>

namespace Scene
{
	class SceneManagement: public ISceneManagementBase
	{
	public:
		/** Constructor. */
		SceneManagement();

		/** Destructor. */
		virtual ~SceneManagement();

		virtual void FrameStarted(float timeStep);
		virtual void FrameEnded();

		virtual void ChangeState(ISceneStateBase* sceneState, ISceneGraphBase* sceneGraph);

		virtual void PushState(ISceneStateBase* sceneState, ISceneGraphBase* sceneGraph);

		virtual void PopState();

	private:
		std::vector<ISceneStateBase*> stateStack;
	};

}

#endif // SCENE_MANAGEMENT_H