#ifndef SCENEMANAGEMENT_H
#define SCENEMANAGEMENT_H

#include "../../../SDK/Core/Scene/SceneManagementBase.h"
#include "../../../SDK/Core/Scene/SceneStateBase.h"
#include "../../../SDK/Platform.h"

#include <vector>

namespace Scene
{
	class SceneManagement: public ISceneManagementBase
	{
	public:
		/// <summary>����������� ������.</summary>
		SceneManagement(void) { }

		/// <summary>���������� ������.</summary>
		virtual ~SceneManagement(void);

		virtual void FrameStarted(OIS::IInputBase* event, float timeStep);
		virtual void FrameEnded();

		virtual void ChangeState(ISceneStateBase* sceneState, Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph);

		virtual void PushState(ISceneStateBase* sceneState, Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph);

		virtual void PopState(void);

	private:
		std::vector<ISceneStateBase*> stateStack;
	};

}

#endif // SCENEMANAGEMENT_H