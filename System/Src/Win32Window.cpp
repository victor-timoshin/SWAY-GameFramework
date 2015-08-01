#include "../Inc/Win32Window.h"
#include "../../OIS/Inc/RawInputManagement.h"

OIS::IInputBase* inputManagement;

namespace System
{
	const TCHAR Win32Window::WindowClassName[] = TEXT("SWAY_WindowClassName");

	/// <summary>Конструктор класса.</summary>
	/// <param name="desc">Описание окна.</param>
	Win32Window::Win32Window(const LWINDOWDESC& desc) : IWindowBase(desc)
		, windowDesc(desc)
	{
		hInstance = GetModuleHandle(nullptr);

		Register();

		inputManagement = OIS::RegisterInputManagement();
	}

	/// <summary>Деструктор класса.</summary>
	Win32Window::~Win32Window(void)
	{
		Unregister();
		Destroy();
	}

	/// <summary>Ругистрирует класс окна.</summary>
	void Win32Window::Register(void)
	{
		WNDCLASSEX windowClassTemp = { 0 };

		if (GetClassInfoEx(hInstance, WindowClassName, &windowClassTemp) == FALSE)
		{
			WNDCLASSEX windowClass;
			windowClass.cbSize = sizeof WNDCLASSEX; // Размер структуры.
			windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Битовые флаги, определяющие стиль окна.
			windowClass.lpfnWndProc = (WNDPROC)windowDesc.proc; // Адрес оконной процедуры.
			windowClass.cbClsExtra = 0; // Размер дополнительной памяти класса.
			windowClass.cbWndExtra = 0; // Размер дополнительной памяти окна.
			windowClass.hInstance = hInstance; // Хэндл экземпляра приложения, которому принадлежит оконная процедура.
			windowClass.hIcon = NULL; // Хэндл значка (32x32 пикселя).
			windowClass.hIconSm = NULL; // Хэндл маленького значка (16x16 пикселей).
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW); // Хэндл курсора окна по умолчанию.
			windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH)); // Хэндл кисти окна по умолчанию или цвет фона.
			windowClass.lpszMenuName = NULL; // Оконное меню (имя ресурса).
			windowClass.lpszClassName = WindowClassName; // Имя класса.

			RegisterClassEx(&windowClass);
		}
	}

	/// <summary>Разрегистрация класса.</summary>
	void Win32Window::Unregister(void)
	{
		UnregisterClass(WindowClassName, hInstance);
	}

	/// <summary>Создает новое окно.</summary>
	void Win32Window::Create(void)
	{
		UInt32 windowExStyle = WS_EX_APPWINDOW;
		UInt32 windowStyle = WS_OVERLAPPEDWINDOW; // Стиль отображения окна по умолчанию.
		int x, y, h, w;

		if (windowDesc.mode == WINDOWMODE::EWM_FULLSCREEN)
		{
			windowStyle |= WS_POPUP;

			x = 0;
			y = 0;
			w = GetSystemMetrics(SM_CXSCREEN);
			h = GetSystemMetrics(SM_CXSCREEN);
		}
		else
		{
			/*  Изменение размеров клиентской области окна. */
			RECT windowRect = { 0, 0, windowDesc.width, windowDesc.height };
			x = CW_USEDEFAULT;
			y = CW_USEDEFAULT;
			w = windowRect.right - windowRect.left;
			h = windowRect.bottom - windowRect.top;
			AdjustWindowRectEx(&windowRect, windowStyle, false, windowExStyle);
		}

		/* Создается новое окно. */
		windowDesc.handle = CreateWindowEx(windowExStyle, WindowClassName,
			windowDesc.title, windowStyle, x, y, w, h, NULL, NULL, hInstance, NULL);
	}

	/// <summary>Уничтожает окно.</summary>
	void Win32Window::Destroy(void)
	{
		DestroyWindow(windowDesc.handle);
	}

	/// <summary>Обновляет окно.</summary>
	void Win32Window::Update(void)
	{
		UpdateWindow(windowDesc.handle);
	}

	/// <summary>Цикл обработки сообщений от окна.</summary>
	/// <param name="state">Состояние цикла.</param>
	bool Win32Window::MessageLoop(MESSAGELOOPSTATE state)
	{
		HACCEL accelTable = 0;
		MSG message;
		ZeroMemory(&message, sizeof MSG);

		while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				state = EMLS_END;

			if (!TranslateAccelerator(windowDesc.handle, accelTable, &message))
			{
				TranslateMessage(&message); // Преобразует ввод клавиш.
				DispatchMessage(&message); // Отправляет сообщения в обработчик.
			}
		}

		return state != EMLS_END;
	}

	/// <summary>Устанавлиет заголовок.</summary>
	/// <param name="text">Текст заголовка.</param>
	void Win32Window::SetText(const TCHAR* text)
	{
		SetWindowText(windowDesc.handle, text);
	}

	/// <summary>Показывает окно.</summary>
	void Win32Window::Show(void)
	{
		ShowWindow(windowDesc.handle, SW_SHOW);
	}

	/// <summary>Скрывает окно.</summary>
	void Win32Window::Hide(void)
	{
		ShowWindow(windowDesc.handle, SW_HIDE);
	}

	/// <summary>Развертывает окно.</summary>
	void Win32Window::Maximize(void)
	{
		ShowWindow(windowDesc.handle, SW_MAXIMIZE);
	}

	/// <summary>Свертывает окно.</summary>
	void Win32Window::Minimize(void)
	{
		ShowWindow(windowDesc.handle, SW_MINIMIZE);
	}

	const LWINDOWDESC& Win32Window::GetWindowDesc(void) const
	{
		return windowDesc;
	}

	OIS::IInputBase* Win32Window::GetInputManagement(void)
	{
		return inputManagement;
	}

	LRESULT Win32Window::MessageProc(HWND handle, UInt message, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT paint;
		HDC deviceContext;

		switch (message)
		{
		case WM_CREATE:
			inputManagement->RegisterDevices(handle);
			break;

		case WM_INPUT:
			deviceContext = GetDC(handle); // Получает контекст.
			inputManagement->HandleMessage(deviceContext, lParam);
			ReleaseDC(handle, deviceContext); // Освобождает контекст.
			break;

		case WM_PAINT:
			deviceContext = BeginPaint(handle, &paint);
			EndPaint(handle, &paint);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}

		return DefWindowProc(handle, message, wParam, lParam);
	}

	LRESULT CALLBACK Win32Window::WindowProc(HWND handle, UInt message, WPARAM wParam, LPARAM lParam)
	{
		Win32Window* window = (Win32Window*)GetWindowLongPtr(handle, GWLP_USERDATA);
		return window->MessageProc(handle, message, wParam, lParam);
	}

	IWindowBase* RegisterWindow(const LWINDOWDESC& desc)
	{
		return new Win32Window(desc);
	}

	LRESULT WINAPI ProcessEvent(HWND handle, UInt message, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT paint;
		HDC deviceContext;

		switch (message)
		{
		case WM_CREATE:
			inputManagement->RegisterDevices(handle);
			break;

		case WM_INPUT:
			deviceContext = GetDC(handle);
			inputManagement->HandleMessage(deviceContext, lParam);
			ReleaseDC(handle, deviceContext);
			break;

		case WM_PAINT:
			deviceContext = BeginPaint(handle, &paint);
			EndPaint(handle, &paint);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}

		return DefWindowProc(handle, message, wParam, lParam);
	}
}