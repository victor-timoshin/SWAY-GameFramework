#include "../../Core/Inc/Win32Window.h"

namespace Gapi
{
	namespace Win32
	{
		const TCHAR Win32Window::AppWindowClass[] = TEXT("SWAYWindow");

		/** Constructor. */
		Win32Window::Win32Window(const LWINDOWDESC& desc) : IWindowBase(desc)
			, windowDesc(desc)
		{

#if defined(_WINDOWS)
			hInstance = GetModuleHandle(0);

			WNDCLASSEX windowClassEx;
			windowClassEx.cbSize = sizeof(WNDCLASSEX);
			windowClassEx.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
			windowClassEx.lpfnWndProc = (WNDPROC)windowDesc.proc;
			windowClassEx.cbClsExtra = 0;
			windowClassEx.cbWndExtra = 0;
			windowClassEx.hInstance = hInstance;
			windowClassEx.hIcon = 0L;
			windowClassEx.hIconSm = 0L;
			windowClassEx.hCursor = LoadCursor(0L, IDC_ARROW);
			windowClassEx.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
			windowClassEx.lpszMenuName = 0L;
			windowClassEx.lpszClassName = AppWindowClass;
			RegisterClassEx(&windowClassEx);
#else
			windowDesc.display = XOpenDisplay(0L);
#endif
		}

		/** Destructor. */
		Win32Window::~Win32Window()
		{
#if defined(PLATFORM_WINDOWS)
			UnregisterClass(AppWindowClass, hInstance);
			DestroyWindow(windowDesc.handle);
#else
			XDestroyWindow(windowDesc.display, windowDesc.handle);
			XCloseDisplay(windowDesc.display);
#endif
		}

		/** Creates a new window. */
		void Win32Window::Create()
		{
#if defined(PLATFORM_WINDOWS)
			unsigned long windowExStyle = WS_EX_APPWINDOW;
			unsigned long windowStyle = WS_OVERLAPPEDWINDOW;
			int x, y, h, w;

			if (windowDesc.mode == WINDOWMODE::Fullscreen)
			{
				windowStyle |= WS_POPUP;

				x = 0;
				y = 0;
				w = GetSystemMetrics(SM_CXSCREEN);
				h = GetSystemMetrics(SM_CXSCREEN);
			}
			else
			{
				RECT windowRect = { 0, 0, windowDesc.clientWidth, windowDesc.clientHeight };
				x = CW_USEDEFAULT;
				y = CW_USEDEFAULT;
				w = windowRect.right - windowRect.left;
				h = windowRect.bottom - windowRect.top;
				AdjustWindowRectEx(&windowRect, windowStyle, false, windowExStyle);
			}

			windowDesc.handle = CreateWindowEx(
				windowExStyle,
				AppWindowClass,
				windowDesc.title,
				windowStyle,
				x, y,
				w, h,
				0L,
				0L, hInstance, 0L);
#else
			XSetWindowAttributes Attributes;
			Attributes.background_pixel = XWhitePixel(windowDesc.display, 0);

			windowDesc.handle = XCreateWindow(windowDesc.display, XRootWindow(windowDesc.display, 0), 0, 0,windowDesc.width, windowDesc.height,
				0, DefaultDepth(windowDesc.display, 0), InputOutput, DefaultVisual(windowDesc.display, 0), CWBackPixel, &Attributes);

			XStoreName(windowDesc.display, windowDesc.handle, windowDesc.title);
			XSelectInput(windowDesc.display, windowDesc.handle, ExposureMask | KeyPressMask);
#endif
		}

		void Win32Window::Update()
		{
#if defined(PLATFORM_WINDOWS)
			UpdateWindow(windowDesc.handle);
#else
			XMapWindow(windowDesc.display, m_WindowDesc.handle);
			XFlush(m_WindowDesc.display);
#endif
		}

		bool Win32Window::MainLoop(bool isRequestingExit)
		{
#if defined(PLATFORM_WINDOWS)
			MSG message;
			ZeroMemory(&message, sizeof(MSG));

			while (PeekMessage(&message, 0L, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_QUIT)
					isRequestingExit = true;

				TranslateMessage(&message);
				DispatchMessage(&message);
			}
#else
			XNextEvent(windowDesc.display, &report);
			switch (report.type)
			{
			case Expose:
				break;
			case KeyPress:
				isRequestingExit = true;
				XCloseDisplay(display);
				exit(0);
			}
#endif

			return isRequestingExit != true;
		}

		void Win32Window::SetText(const TCHAR* text)
		{
#ifdef PLATFORM_WINDOWS
			SetWindowText(windowDesc.handle, text);
#endif
		}

		void Win32Window::Show()
		{
#ifdef PLATFORM_WINDOWS
			ShowWindow(windowDesc.handle, SW_SHOW);
#endif
		}

		void Win32Window::Hide()
		{
#ifdef PLATFORM_WINDOWS
			ShowWindow(windowDesc.handle, SW_HIDE);
#endif
		}

		void Win32Window::Minimize()
		{
#ifdef PLATFORM_WINDOWS
			ShowWindow(windowDesc.handle, SW_MINIMIZE);
#endif
		}

		void Win32Window::Maximize()
		{
#ifdef PLATFORM_WINDOWS
			ShowWindow(windowDesc.handle, SW_MAXIMIZE);
#endif
		}

		const LWINDOWDESC& Win32Window::GetWindowDesc() const
		{
			return windowDesc;
		}
	}

	IWindowBase* RegisterWindow(const LWINDOWDESC& desc)
	{
		return new Win32::Win32Window(desc);
	}

#if defined(PLATFORM_WINDOWS)
	LRESULT WINAPI ProcessEvent(HWND handle, UInt message, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT paint;
		HDC deviceContext;

		switch (message)
		{
		case WM_CREATE:
			break;
		case WM_INPUT:
			deviceContext = GetDC(handle);
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

}