#include "../Inc/Win32Window.h"
#include "../../OIS/Inc/RawInputManagement.h"

OIS::IInputBase* inputManagement;

namespace System
{
	const TCHAR Win32Window::WindowClassName[] = TEXT("SWAY_WindowClassName");

	/// <summary>����������� ������.</summary>
	/// <param name="desc">�������� ����.</param>
	Win32Window::Win32Window(const LWINDOWDESC& desc) : IWindowBase(desc)
		, windowDesc(desc)
	{
		hInstance = GetModuleHandle(nullptr);

		Register();

		inputManagement = OIS::RegisterInputManagement();
	}

	/// <summary>���������� ������.</summary>
	Win32Window::~Win32Window(void)
	{
		Unregister();
		Destroy();
	}

	/// <summary>������������ ����� ����.</summary>
	void Win32Window::Register(void)
	{
		WNDCLASSEX windowClassTemp = { 0 };

		if (GetClassInfoEx(hInstance, WindowClassName, &windowClassTemp) == FALSE)
		{
			WNDCLASSEX windowClass;
			windowClass.cbSize = sizeof WNDCLASSEX; // ������ ���������.
			windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // ������� �����, ������������ ����� ����.
			windowClass.lpfnWndProc = (WNDPROC)windowDesc.proc; // ����� ������� ���������.
			windowClass.cbClsExtra = 0; // ������ �������������� ������ ������.
			windowClass.cbWndExtra = 0; // ������ �������������� ������ ����.
			windowClass.hInstance = hInstance; // ����� ���������� ����������, �������� ����������� ������� ���������.
			windowClass.hIcon = NULL; // ����� ������ (32x32 �������).
			windowClass.hIconSm = NULL; // ����� ���������� ������ (16x16 ��������).
			windowClass.hCursor = LoadCursor(NULL, IDC_ARROW); // ����� ������� ���� �� ���������.
			windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH)); // ����� ����� ���� �� ��������� ��� ���� ����.
			windowClass.lpszMenuName = NULL; // ������� ���� (��� �������).
			windowClass.lpszClassName = WindowClassName; // ��� ������.

			RegisterClassEx(&windowClass);
		}
	}

	/// <summary>�������������� ������.</summary>
	void Win32Window::Unregister(void)
	{
		UnregisterClass(WindowClassName, hInstance);
	}

	/// <summary>������� ����� ����.</summary>
	void Win32Window::Create(void)
	{
		UInt32 windowExStyle = WS_EX_APPWINDOW;
		UInt32 windowStyle = WS_OVERLAPPEDWINDOW; // ����� ����������� ���� �� ���������.
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
			/*  ��������� �������� ���������� ������� ����. */
			RECT windowRect = { 0, 0, windowDesc.width, windowDesc.height };
			x = CW_USEDEFAULT;
			y = CW_USEDEFAULT;
			w = windowRect.right - windowRect.left;
			h = windowRect.bottom - windowRect.top;
			AdjustWindowRectEx(&windowRect, windowStyle, false, windowExStyle);
		}

		/* ��������� ����� ����. */
		windowDesc.handle = CreateWindowEx(windowExStyle, WindowClassName,
			windowDesc.title, windowStyle, x, y, w, h, NULL, NULL, hInstance, NULL);
	}

	/// <summary>���������� ����.</summary>
	void Win32Window::Destroy(void)
	{
		DestroyWindow(windowDesc.handle);
	}

	/// <summary>��������� ����.</summary>
	void Win32Window::Update(void)
	{
		UpdateWindow(windowDesc.handle);
	}

	/// <summary>���� ��������� ��������� �� ����.</summary>
	/// <param name="state">��������� �����.</param>
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
				TranslateMessage(&message); // ����������� ���� ������.
				DispatchMessage(&message); // ���������� ��������� � ����������.
			}
		}

		return state != EMLS_END;
	}

	/// <summary>����������� ���������.</summary>
	/// <param name="text">����� ���������.</param>
	void Win32Window::SetText(const TCHAR* text)
	{
		SetWindowText(windowDesc.handle, text);
	}

	/// <summary>���������� ����.</summary>
	void Win32Window::Show(void)
	{
		ShowWindow(windowDesc.handle, SW_SHOW);
	}

	/// <summary>�������� ����.</summary>
	void Win32Window::Hide(void)
	{
		ShowWindow(windowDesc.handle, SW_HIDE);
	}

	/// <summary>������������ ����.</summary>
	void Win32Window::Maximize(void)
	{
		ShowWindow(windowDesc.handle, SW_MAXIMIZE);
	}

	/// <summary>���������� ����.</summary>
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
			deviceContext = GetDC(handle); // �������� ��������.
			inputManagement->HandleMessage(deviceContext, lParam);
			ReleaseDC(handle, deviceContext); // ����������� ��������.
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