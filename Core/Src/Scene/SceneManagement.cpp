#include "../../../Core/Inc/Scene/SceneManagement.h"

namespace Scene
{
	/** Constructor. */
	SceneManagement::SceneManagement() {}

	/** Destructor. */
	SceneManagement::~SceneManagement()
	{
		while (!stateStack.empty())
		{
			stateStack.back()->Exit();
			stateStack.pop_back();
		}
	}

	void SceneManagement::FrameStarted(OIS::IInputEventBase* event, float timeStep)
	{
		stateStack.back()->FrameStarted(event, timeStep);
	}

	void SceneManagement::FrameEnded()
	{
		stateStack.back()->FrameEnded();
	}

	void SceneManagement::ChangeState(ISceneStateBase* sceneState, ISceneGraphBase* sceneGraph)
	{
		while (!stateStack.empty())
		{
			stateStack.back()->Exit();
			stateStack.pop_back();
		}

		stateStack.push_back(sceneState);
		stateStack.back()->Enter(sceneGraph);
	}

	void SceneManagement::PushState(ISceneStateBase* sceneState, ISceneGraphBase* sceneGraph)
	{
		if (!stateStack.empty())
			stateStack.back()->Pause();

		stateStack.push_back(sceneState);
		stateStack.back()->Enter(sceneGraph);
	}

	void SceneManagement::PopState()
	{
		while (!stateStack.empty())
		{
			stateStack.back()->Exit();
			stateStack.pop_back();
		}

		if (!stateStack.empty())
			stateStack.back()->Resume();
	}

	ISceneManagementBase* RegisterSceneManagement()
	{
		return new SceneManagement();
	}
}