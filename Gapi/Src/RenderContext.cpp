#include "../Inc/RenderContext.h"

namespace Gapi
{
	const TCHAR RenderContext::AppWindowClass[] = TEXT("SWAYWindow");

	/** Constructor. */
	RenderContext::RenderContext(const LWINDOWDESC& desc): IRenderContextBase(desc)
		, windowDesc(desc)
	{
		hInstance = ::GetModuleHandle(0);
		
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
		::RegisterClassEx(&windowClassEx);
	}

	/** Destructor. */
	RenderContext::~RenderContext()
	{
		::UnregisterClass(AppWindowClass, hInstance);
		::DestroyWindow(windowDesc.handle);
	}

	/** Creates a new window. */
	void RenderContext::Create()
	{
		unsigned long windowExStyle = WS_EX_APPWINDOW;
		unsigned long windowStyle = WS_OVERLAPPEDWINDOW;
		int x, y, h, w;

		if (windowDesc.mode == WINDOWMODE::Fullscreen)
		{
			windowStyle |= WS_POPUP;

			x = 0;
			y = 0;
			w = ::GetSystemMetrics(SM_CXSCREEN);
			h = ::GetSystemMetrics(SM_CXSCREEN);
		}
		else
		{
			RECT windowRect = { 0, 0, windowDesc.clientWidth, windowDesc.clientHeight };
			x = CW_USEDEFAULT;
			y = CW_USEDEFAULT;
			w = windowRect.right - windowRect.left;
			h = windowRect.bottom - windowRect.top;
			::AdjustWindowRectEx(&windowRect, windowStyle, false, windowExStyle);
		}

		windowDesc.handle = ::CreateWindowEx(
			windowExStyle,
			AppWindowClass,
			windowDesc.title,
			windowStyle,
			x, y,
			w, h,
			0L,
			0L, hInstance, 0L);
	}

	void RenderContext::Update()
	{
		::UpdateWindow(windowDesc.handle);
	}

	bool RenderContext::MainLoop(bool isRequestingExit)
	{
		MSG message;
		ZeroMemory(&message, sizeof(MSG));

		while (PeekMessage(&message, 0L, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
				isRequestingExit = true;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		return isRequestingExit != true;
	}

	void RenderContext::SetText(const TCHAR* text)
	{
		::SetWindowText(windowDesc.handle, text);
	}

	void RenderContext::Show()
	{
		::ShowWindow(windowDesc.handle, SW_SHOW);
	}

	void RenderContext::Hide()
	{
		::ShowWindow(windowDesc.handle, SW_HIDE);
	}

	void RenderContext::Minimize()
	{
		::ShowWindow(windowDesc.handle, SW_MINIMIZE);
	}

	void RenderContext::Maximize()
	{
		::ShowWindow(windowDesc.handle, SW_MAXIMIZE);
	}

	const LWINDOWDESC& RenderContext::GetWindowDesc() const
	{
		return windowDesc;
	}

	IRenderContextBase* RegisterRenderContext(const LWINDOWDESC& desc)
	{
		return new RenderContext(desc);
	}

	LRESULT WINAPI ProcessEvent(HWND handle, UInt32 message, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT paint;
		HDC deviceContext;

		switch (message)
		{
		case WM_CREATE:
			break;
		case WM_INPUT:
			deviceContext = ::GetDC(handle);
			::ReleaseDC(handle, deviceContext);
			break;
		case WM_PAINT:
			deviceContext = ::BeginPaint(handle, &paint);
			::EndPaint(handle, &paint);
			break;

		case WM_DESTROY:
			::PostQuitMessage(0);
			break;
		}

		return DefWindowProc(handle, message, wParam, lParam);
	}
}