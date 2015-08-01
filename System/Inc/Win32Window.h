#ifndef WIN32WINDOW_H
#define WIN32WINDOW_H

#include "../../SDK/System/WindowBase.h"
#include "../StdAfx.h"

namespace System
{
	class Win32Window : public IWindowBase
	{
	public:
		static const TCHAR WindowClassName[];

		/// <summary>����������� ������.</summary>
		/// <param name="desc">�������� ����.</param>
		Win32Window(const LWINDOWDESC& desc);

		/// <summary>���������� ������.</summary>
		virtual ~Win32Window(void);

		/// <summary>������������ ����� ����.</summary>
		virtual void Register(void);

		/// <summary>�������������� ������.</summary>
		virtual void Unregister(void);

		/// <summary>������� ����� ����.</summary>
		virtual void Create(void);

		/// <summary>���������� ����.</summary>
		virtual void Destroy(void);

		/// <summary>��������� ����.</summary>
		virtual void Update(void);

		/// <summary>���� ��������� ��������� �� ����.</summary>
		/// <param name="state">��������� �����.</param>
		virtual bool MessageLoop(MESSAGELOOPSTATE state);

		/// <summary>����������� ���������.</summary>
		/// <param name="text">����� ���������.</param>
		virtual void SetText(const TCHAR* text);

		/// <summary>���������� ����.</summary>
		virtual void Show(void);

		/// <summary>�������� ����.</summary>
		virtual void Hide(void);

		/// <summary>������������ ����.</summary>
		virtual void Maximize(void);

		/// <summary>���������� ����.</summary>
		virtual void Minimize(void);

		virtual const LWINDOWDESC& GetWindowDesc(void) const;

		virtual OIS::IInputBase* GetInputManagement(void);

		LRESULT MessageProc(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK WindowProc(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);

	private:
		LWINDOWDESC windowDesc;
		HINSTANCE hInstance;
	};
}

#endif // WINDOWCTRL_H