#include "../../../Core/Inc/System/WindowImpl.h"
#include "../../../Core/Inc/OIS/InputDevice.h"

OIS::IInputBase* inputDevice;

namespace Core
{
	namespace System
	{
		const TCHAR WindowImpl::AppWindowClass[] = TEXT("SWAY_WindowClass");

		/** Constructor. */
		WindowImpl::WindowImpl(const LWINDOWDESC& desc) : IWindowBase(desc)
			, windowDesc(desc)
		{
			hInstance = GetModuleHandle(0);
			inputDevice = OIS::RegisterInputDevice();

			WNDCLASSEX windowClassEx;
			windowClassEx.cbSize = sizeof WNDCLASSEX;
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
		}

		/** Destructor. */
		WindowImpl::~WindowImpl()
		{
			UnregisterClass(AppWindowClass, hInstance);
			DestroyWindow(windowDesc.handle);
		}

		/** Creates a new window. */
		void WindowImpl::Create()
		{
			UInt32 windowExStyle = WS_EX_APPWINDOW;
			UInt32 windowStyle = WS_OVERLAPPEDWINDOW;
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

			windowDesc.handle = CreateWindowEx(windowExStyle, AppWindowClass,
				windowDesc.title, windowStyle, x, y, w, h, 0L, 0L, hInstance, 0L);
		}

		void WindowImpl::Update()
		{
			UpdateWindow(windowDesc.handle);
		}

		bool WindowImpl::MainLoop(bool isRequestingExit)
		{
			MSG message;
			ZeroMemory(&message, sizeof MSG);

			while (PeekMessage(&message, 0L, 0, 0, PM_REMOVE))
			{
				if (message.message == WM_QUIT)
					isRequestingExit = true;

				TranslateMessage(&message);
				DispatchMessage(&message);
			}

			return isRequestingExit != true;
		}

		void WindowImpl::SetText(const TCHAR* text)
		{
			SetWindowText(windowDesc.handle, text);
		}

		void WindowImpl::Show()
		{
			ShowWindow(windowDesc.handle, SW_SHOW);
		}

		void WindowImpl::Hide()
		{
			ShowWindow(windowDesc.handle, SW_HIDE);
		}

		void WindowImpl::Minimize()
		{
			ShowWindow(windowDesc.handle, SW_MINIMIZE);
		}

		void WindowImpl::Maximize()
		{
			ShowWindow(windowDesc.handle, SW_MAXIMIZE);
		}

		const LWINDOWDESC& WindowImpl::GetWindowDesc() const
		{
			return windowDesc;
		}

		OIS::IInputEventBase* WindowImpl::GetInputDevice()
		{
			return inputDevice;
		}

		IWindowBase* RegisterWindow(const LWINDOWDESC& desc)
		{
			return new WindowImpl(desc);
		}

		LRESULT WINAPI ProcessEvent(HWND handle, UInt message, WPARAM wParam, LPARAM lParam)
		{
			PAINTSTRUCT paint;
			HDC deviceContext;

			switch (message)
			{
			case WM_CREATE:
				inputDevice->RegisterDevices(handle);
				break;

			case WM_INPUT:
				deviceContext = GetDC(handle);
				inputDevice->HandleMessage(deviceContext, lParam);
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
}