#ifndef FRAMEWORKBASE_H
#define FRAMEWORKBASE_H

#include "../System/WindowBase.h"
#include "../System/TimerBase.h"

#include "Render/RenderSystemBase.h"

#include "Scene/SceneStateBase.h"
#include "Scene/SceneManagementBase.h"

#include "../SceneGraph/SceneGraphBase.h"
#include "../SceneGraph/SceneNodeBase.h"

#include "../Platform.h"

namespace Core
{
	class IFrameworkBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IFrameworkBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IFrameworkBase(void) {}

		/// <summary>Инициализация фреймворк.</summary>
		virtual void Initialize(Scene::ISceneStateBase* state) = 0;

		/// <summary>Главный цикл сообщений.</summary>
		virtual void Run(void) = 0;

		/// <summary>Деинициализация фреймворк.</summary>
		virtual void Shutdown(void) = 0;
	};

	CORE_API IFrameworkBase* RegisterFramework(void);
}

#endif // FRAMEWORKBASE_H