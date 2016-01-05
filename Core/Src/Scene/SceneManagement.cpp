#include "../../../Core/Inc/Scene/SceneManagement.h"

namespace Scene
{
	/// <summary>Конструктор класса.</summary>
	SceneManagement::SceneManagement(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	SceneManagement::~SceneManagement(void)
	{
		while (NOT _stateStack.empty())
		{
			_stateStack.back()->Exit();
			_stateStack.pop_back();
		}
	}

	void SceneManagement::FrameStarted(OIS::IInputBase* event, float timeStep)
	{
		_stateStack.back()->FrameStarted(event, timeStep);
	}

	void SceneManagement::FrameEnded(void)
	{
		_stateStack.back()->FrameEnded();
	}

	void SceneManagement::ChangeState(ISceneStateBase* sceneState, Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph)
	{
		while (NOT _stateStack.empty())
		{
			_stateStack.back()->Exit();
			_stateStack.pop_back();
		}

		_stateStack.push_back(sceneState);
		_stateStack.back()->Enter(renderSystem, sceneGraph);
	}

	void SceneManagement::PushState(ISceneStateBase* sceneState, Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph)
	{
		if (NOT _stateStack.empty())
			_stateStack.back()->Pause();

		_stateStack.push_back(sceneState);
		_stateStack.back()->Enter(renderSystem, sceneGraph);
	}

	void SceneManagement::PopState(void)
	{
		while (NOT _stateStack.empty())
		{
			_stateStack.back()->Exit();
			_stateStack.pop_back();
		}

		if (NOT _stateStack.empty())
			_stateStack.back()->Resume();
	}

	ISceneManagementBase* RegisterSceneManagement(void)
	{
		return new SceneManagement();
	}
}