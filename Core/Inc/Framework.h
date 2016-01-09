#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "../../SDK/Core/FrameworkBase.h"

#include "Render/RenderSystem.h"

#include "../../SDK/System/WindowBase.h"
#include "../../SDK/System/TimerBase.h"

#include "../../SDK/Core/Render/RenderSystemBase.h"

#include "../../SDK/Core/Scene/SceneStateBase.h"
#include "../../SDK/Core/Scene/SceneManagementBase.h"
#include "../../SDK/SceneGraph/SceneGraphBase.h"
#include "../../SDK/SceneGraph/SceneNodeBase.h"

#include "../../SDK/Platform.h"

namespace Core
{
	class Framework : public IFrameworkBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Framework(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Framework(void);

		/// <summary>Инициализация фреймворк.</summary>
		void Initialize(Scene::ISceneStateBase* state);

		/// <summary>Главный цикл сообщений.</summary>
		void Run(void);

		/// <summary>Деинициализация фреймворк.</summary>
		void Shutdown(void);

	private:
		System::IWindowBase* _window;
		System::ITimerBase* _timer;
		Render::IRenderSystemBase* _renderSystem;
		Scene::ISceneGraphBase* _sceneGraph;
		Scene::ISceneManagementBase* _sceneManagement;
	};
}

#endif // FRAMEWORK_H