#ifndef SCENEMANAGEMENT_H
#define SCENEMANAGEMENT_H

#include "../../../SDK/Core/Scene/SceneManagementBase.h"
#include "../../../SDK/Core/Scene/SceneStateBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class SceneManagement: public ISceneManagementBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		SceneManagement(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~SceneManagement(void);

		virtual void FrameStarted(OIS::IInputBase* event, float timeStep);
		virtual void FrameEnded(void);

		virtual void ChangeState(ISceneStateBase* sceneState, Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph);

		virtual void PushState(ISceneStateBase* sceneState, Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph);

		virtual void PopState(void);

	private:
		std::vector<ISceneStateBase*> _stateStack;
	};

}

#endif // SCENEMANAGEMENT_H