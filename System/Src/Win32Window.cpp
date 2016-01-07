#include "../Inc/Win32Window.h"
#include "../../OIS/Inc/RawInputManagement.h"

OIS::IInputBase* inputManagement;

namespace System
{
	const TCHAR Win32Window::WindowClassName[] = TEXT("SWAY_WindowClassName");

	/// <summary>Конструктор класса.</summary>
	/// <param name="desc">Описание окна.</param>
	Win32Window::Win32Window(const WINDOW_DESCRIPTION& desc) : IWindowBase(desc)
		, windowDesc(desc)
	{
#ifdef PLATFORM_WINDOW

		hInstance = GetModuleHandle(nullptr);

#endif

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
#ifdef PLATFORM_WINDOW

		WNDCLASSEX windowClassTemp = { 0 };

		if (GetClassInfoEx(hInstance, Win32Window::WindowClassName, &windowClassTemp) == FALSE)
		{
			WNDCLASSEX windowClass;
			windowClass.cbSize = sizeof WNDCLASSEX; // Размер структуры.
			windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Битовые флаги, определяющие стиль окна.
			windowClass.lpfnWndProc = (WNDPROC)windowDesc.proc; // Адрес оконной процедуры.
			windowClass.cbClsExtra = 0; // Размер дополнительной памяти класса.
			windowClass.cbWndExtra = 0; // Размер дополнительной памяти окна.
			windowClass.hInstance = hInstance; // Хэндл экземпляра приложения, которому принадлежит оконная процедура.
			windowClass.hIcon = nullptr; // Хэндл значка (32x32 пикселя).
			windowClass.hIconSm = nullptr; // Хэндл маленького значка (16x16 пикселей).
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW); // Хэндл курсора окна по умолчанию.
			windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH)); // Хэндл кисти окна по умолчанию или цвет фона.
			windowClass.lpszMenuName = nullptr; // Оконное меню (имя ресурса).
			windowClass.lpszClassName = WindowClassName; // Имя класса.

			ATOM windowAtom = RegisterClassEx(&windowClass);
		}

#elif PLATFORM_LINUX

		/* Устанавливаем связь с сервером. */
		windowDesc.display = XOpenDisplay(nullptr);

#endif
	}

	/// <summary>Разрегистрация класса.</summary>
	void Win32Window::Unregister(void)
	{
#ifdef PLATFORM_WINDOW

		UnregisterClass(WindowClassName, hInstance);

#elif PLATFORM_LINUX

		XCloseDisplay(windowDesc.display); // Закрываем соединение с сервером.

#endif
	}

	/// <summary>Создает новое окно.</summary>
	void Win32Window::Create(void)
	{
#ifdef PLATFORM_WINDOW

		UInt32 windowExStyle = WS_EX_APPWINDOW;
		UInt32 windowStyle = WS_OVERLAPPEDWINDOW; // Стиль отображения окна по умолчанию.
		int x, y, h, w;

		if (windowDesc.mode == WINDOW_MODE::Fullscreen)
		{
			windowStyle |= WS_POPUP;

			x = 0;
			y = 0;
			w = GetSystemMetrics(SM_CXSCREEN);
			h = GetSystemMetrics(SM_CXSCREEN);
		}
		else
		{
			// Изменение размеров клиентской области окна.
			RECT windowRect = { 0, 0, windowDesc.width, windowDesc.height };
			x = CW_USEDEFAULT;
			y = CW_USEDEFAULT;
			w = windowRect.right - windowRect.left;
			h = windowRect.bottom - windowRect.top;
			AdjustWindowRectEx(&windowRect, windowStyle, false, windowExStyle);
		}

		// Создается новое окно.
		windowDesc.handle = CreateWindowEx(
			windowExStyle,
			WindowClassName, // Имя класса.
			windowDesc.title, // Заголовок окна.
			windowStyle,
			x, y, // Координата верхнего левого угла окна.
			w, h, // Ширина/Высота окна.
			nullptr, // Хэндл родительского окна.
			nullptr, // Хэндл меню.
			hInstance, // Хэндл экземпляра приложения.
			nullptr
		);

#elif PLATFORM_LINUX

		XSetWindowAttributes Attributes;
		Attributes.background_pixel = XWhitePixel(windowDesc.display, 0);

		windowDesc.m_Handle = XCreateWindow(
			windowDesc.display, // Указатель на структуру, описывающую соединение с X-сервером.
			XRootWindow(windowDesc.display, 0), // Идентификатор родительского окна.
			0, 0, // Координата верхнего левого угла окна.
			windowDesc.width, windowDesc.height, // Ширина/Высота окна.
			0, // Толщина рамки вокруг окна.
			DefaultDepth(windowDesc.display, 0), // Количество разрядов, отводящихся для кодирования цвета в окне.
			InputOutput, // Класс окна.
			DefaultVisual(windowDesc.display, 0), // Визуальные характеристики окна.
			CWBackPixel,
			&Attributes // Расширенные параметры окна.
		);

		// Устанавливаем заголовок окна.
		XStoreName(windowDesc.display, windowDesc.handle, windowDesc.title);

		// Выбираем события, которые будет обрабатывать программа.
		XSelectInput(windowDesc.display, windowDesc.handle, ExposureMask | KeyPressMask);

#endif
	}

	/// <summary>Уничтожает окно.</summary>
	void Win32Window::Destroy(void)
	{
#ifdef PLATFORM_WINDOW

		DestroyWindow(windowDesc.handle);

#elif PLATFORM_LINUX

		XDestroyWindow(windowDesc.display, windowDesc.handle); // Уничтожаем окно.

#endif
	}

	/// <summary>Обновляет окно.</summary>
	void Win32Window::Update(void)
	{
#ifdef PLATFORM_WINDOW

		UpdateWindow(windowDesc.handle);

#elif PLATFORM_LINUX

		XMapWindow(windowDesc.display, windowDesc.handle);
		XFlush(windowDesc.display); // Принудительно отправляем команды на X-сервер, находящиеся в буфере.

#endif
	}

	/// <summary>Цикл обработки сообщений от окна.</summary>
	/// <param name="state">Состояние цикла.</param>
	bool Win32Window::MessageLoop(MESSAGE_LOOP_STATE messageLoopState)
	{
#ifdef PLATFORM_WINDOW

		HACCEL accelTable = 0;
		MSG message;
		ZeroMemory(&message, sizeof MSG);

		while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				messageLoopState = MESSAGE_LOOP_STATE::End;

			if (NOT TranslateAccelerator(windowDesc.handle, accelTable, &message))
			{
				TranslateMessage(&message); // Преобразует ввод клавиш.
				DispatchMessage(&message); // Отправляет сообщения в обработчик.
			}
		}

#elif PLATFORM_LINUX

		XNextEvent(windowDesc.display, &report);
		switch (report.type)
		{
		case Expose:
			break;
		case KeyPress:
			messageLoopState = MESSAGE_LOOP_STATE::End;
			XCloseDisplay(display);
			exit(0);
		}

#endif

		return (messageLoopState == MESSAGE_LOOP_STATE::Run) ? true : false;
	}

	/// <summary>Устанавлиет заголовок.</summary>
	/// <param name="text">Текст заголовка.</param>
	void Win32Window::SetTitle(const char* text)
	{
		windowDesc.title = text;

#ifdef PLATFORM_WINDOW

		SetWindowText(windowDesc.handle, text);

#endif
	}

	const char* Win32Window::GetTitle(void)
	{
		return windowDesc.title;
	}

	/// <summary>Показывает окно.</summary>
	void Win32Window::Show(void)
	{
#ifdef PLATFORM_WINDOW

		ShowWindow(windowDesc.handle, SW_SHOW);

#endif
	}

	void Win32Window::ShowDeactivated(void)
	{
#ifdef PLATFORM_WINDOW

		ShowWindow(windowDesc.handle, SW_SHOWNOACTIVATE);
		SetWindowPos(windowDesc.handle, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_NOACTIVATE);

#endif
	}

	void Win32Window::ShowRestored(void)
	{
#ifdef PLATFORM_WINDOW

		ShowWindow(windowDesc.handle, SW_RESTORE);

#endif
	}

	/// <summary>Развертывает окно.</summary>
	void Win32Window::ShowMaximized(void)
	{
#ifdef PLATFORM_WINDOW

		ShowWindow(windowDesc.handle, SW_MAXIMIZE);

#endif
	}

	/// <summary>Свертывает окно.</summary>
	void Win32Window::ShowMinimized(void)
	{
#ifdef PLATFORM_WINDOW

		ShowWindow(windowDesc.handle, SW_MINIMIZE);

#endif
	}

	/// <summary>Скрывает окно.</summary>
	void Win32Window::Hide(void)
	{
#ifdef PLATFORM_WINDOW

		ShowWindow(windowDesc.handle, SW_HIDE);

#endif
	}

	bool Win32Window::IsVisible(void)
	{
#ifdef PLATFORM_WINDOW

		return IsWindowVisible(windowDesc.handle) != 0;

#endif
	}

	void Win32Window::Enable(void)
	{
#ifdef PLATFORM_WINDOW

		EnableWindow(windowDesc.handle, TRUE);

#endif
	}

	void Win32Window::Disable(void)
	{
#ifdef PLATFORM_WINDOW

		EnableWindow(windowDesc.handle, FALSE);

#endif
	}

	bool Win32Window::IsEnabled(void)
	{
#ifdef PLATFORM_WINDOW

		return IsWindowEnabled(windowDesc.handle) != 0;

#endif
	}

	const WINDOW_DESCRIPTION& Win32Window::GetWindowDesc(void) const
	{
		return windowDesc;
	}

	OIS::IInputBase* Win32Window::GetInputManagement(void)
	{
		return inputManagement;
	}

#ifdef PLATFORM_WINDOW

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

#endif

	IWindowBase* RegisterWindow(const WINDOW_DESCRIPTION& desc)
	{
		return new Win32Window(desc);
	}
}