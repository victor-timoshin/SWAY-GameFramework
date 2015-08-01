#include "../../../Core/Inc/Scene/SceneManagement.h"

namespace Scene
{
	/// <summary>Деструктор класса.</summary>
	SceneManagement::~SceneManagement(void)
	{
		while (!stateStack.empty())
		{
			stateStack.back()->Exit();
			stateStack.pop_back();
		}
	}

	void SceneManagement::FrameStarted(OIS::IInputBase* event, float timeStep)
	{
		stateStack.back()->FrameStarted(event, timeStep);
	}

	void SceneManagement::FrameEnded(void)
	{
		stateStack.back()->FrameEnded();
	}

	void SceneManagement::ChangeState(ISceneStateBase* sceneState, Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph)
	{
		while (!stateStack.empty())
		{
			stateStack.back()->Exit();
			stateStack.pop_back();
		}

		stateStack.push_back(sceneState);
		stateStack.back()->Enter(renderSystem, sceneGraph);
	}

	void SceneManagement::PushState(ISceneStateBase* sceneState, Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph)
	{
		if (!stateStack.empty())
			stateStack.back()->Pause();

		stateStack.push_back(sceneState);
		stateStack.back()->Enter(renderSystem, sceneGraph);
	}

	void SceneManagement::PopState(void)
	{
		while (!stateStack.empty())
		{
			stateStack.back()->Exit();
			stateStack.pop_back();
		}

		if (!stateStack.empty())
			stateStack.back()->Resume();
	}

	ISceneManagementBase* RegisterSceneManagement(void)
	{
		return new SceneManagement();
	}
}