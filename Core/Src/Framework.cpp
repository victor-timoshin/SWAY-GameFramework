#include "../../Core/Inc/Framework.h"

#include "../../Core/Inc/AudioProvider/AudioLoader/WAVLoader.h"

namespace Core
{
	/// <summary>Конструктор класса.</summary>
	Framework::Framework(void)
		: _window(nullptr)
		, _timer(nullptr)
		, _renderSystem(nullptr)
		, _sceneGraph(nullptr)
		, _sceneManagement(nullptr)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Framework::~Framework(void)
	{
	}

	/// <summary>Инициализация фреймворк.</summary>
	void Framework::Initialize(Scene::ISceneStateBase* state)
	{
		System::WINDOW_DESCRIPTION windowDesc;
		windowDesc.proc = System::ProcessEvent;
		windowDesc.mode = System::WINDOW_MODE::Windowed;
		windowDesc.title = "Demo";
		windowDesc.width = WINDOW_WIDTH;
		windowDesc.height = WINDOW_HEIGHT;

		_window = System::RegisterWindow(windowDesc);
		_window->Create();
		_window->Update();
		_window->Show();

		_timer = System::RegisterTimer();
		_timer->Start();

		_renderSystem = Core::Render::RegisterRenderSystem();
		_renderSystem->Initialize("GapiOpenGL_Win32_Debug");
		_renderSystem->CreateDevice(_window->GetWindowDesc().handle);

		_sceneGraph = Scene::RegisterSceneGraph();

		_sceneManagement = Scene::RegisterSceneManagement();
		_sceneManagement->ChangeState(state, _renderSystem, _sceneGraph);
	}

	/// <summary>Главный цикл сообщений.</summary>
	void Framework::Run(void)
	{
		LARGE_INTEGER ticksPerSecond;
		LARGE_INTEGER currentTime;
		LARGE_INTEGER lastTime;
		UInt framesCount = 0; // Счетчик кадров.
		UInt framesPerSecond = 0; // Кадров в секунду.

		QueryPerformanceFrequency(&ticksPerSecond);
		QueryPerformanceCounter(&currentTime);
		QueryPerformanceCounter(&lastTime);

		while (_window->MessageLoop(System::MESSAGE_LOOP_STATE::Run))
		{
			// Получаем интервал времени, которое прошло с момента последней отрисовки сцены.
			float timeStep = static_cast<float>(_timer->GetInterval());

			_sceneManagement->FrameStarted(_window->GetInputManagement(), timeStep);

			_renderSystem->GetDevice()->SetViewport(WINDOW_WIDTH, WINDOW_HEIGHT);
			_renderSystem->FrameDrawed(_sceneGraph->GetActiveCamera());

			_sceneManagement->FrameEnded();

			// Увеличиваем счетчик кадров.
			framesCount++;

			// Если интервал времени между кадрами больше одной секунды.
			if (timeStep > 1000.0f)
			{
				_timer->Stop(); // Останавливаем таймер.

				framesPerSecond = framesCount; // Сохраняем значение счетчика.
				framesCount = 0; // Обнуляем счетчик.

				_timer->Start(); // Запускаем таймер.
			}

			lastTime = currentTime;
		}
	}

	/// <summary>Деинициализация фреймворк.</summary>
	void Framework::Shutdown(void)
	{
		SAFE_DELETE(_sceneManagement);
		SAFE_DELETE(_sceneGraph);
		SAFE_DELETE(_renderSystem);
		SAFE_DELETE(_timer);
		SAFE_DELETE(_window);
	}

	CORE_API IFrameworkBase* RegisterFramework(void)
	{
		return new Framework();
	}
}