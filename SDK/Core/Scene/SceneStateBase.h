#ifndef SCENE_STATE_BASE_H
#define SCENE_STATE_BASE_H

#include "../../../SDK/Core/Scene/SceneGraphBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class ISceneStateBase
	{
	public:
		/** Constructor. */
		ISceneStateBase() {}
		
		/** Destructor. */
		virtual ~ISceneStateBase() {}

		virtual void Enter(ISceneGraphBase* sceneGraph) = 0;

		virtual void Exit() = 0;

		virtual void Pause() = 0;

		virtual void Resume() = 0;

		virtual void FrameStarted(OIS::IInputEventBase* event, float timeStep) = 0;

		virtual void FrameEnded() = 0;
	};
}

#endif // SCENE_STATE_BASE_H