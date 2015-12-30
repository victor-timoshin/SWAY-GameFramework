#ifndef SCENESTATEBASE_H
#define SCENESTATEBASE_H

#include "../../../SDK/SceneGraph/SceneGraphBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class ISceneStateBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		ISceneStateBase(void) {}
		
		/// <summary>Деструктор класса.</summary>
		virtual ~ISceneStateBase(void) {}

		virtual void Enter(Core::Render::IRenderSystemBase* renderSystem, ISceneGraphBase* sceneGraph) = 0;

		virtual void Exit(void) = 0;

		virtual void Pause(void) = 0;

		virtual void Resume(void) = 0;

		virtual void FrameStarted(OIS::IInputBase* event, float timeStep) = 0;

		virtual void FrameEnded(void) = 0;
	};
}

#endif // SCENESTATEBASE_H