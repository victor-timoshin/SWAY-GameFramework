#ifndef IWINDOWBASE_H
#define IWINDOWBASE_H

#include "WindowModes.h"
#include "WindowDesc.h"
#include "MessageLoopStates.h"

#include "../OIS/InputBase.h"
#include "../Platform.h"

namespace System
{
	class IWindowBase
	{
	public:
		/// <summary>����������� ������.</summary>
		/// <param name="desc">�������� ����.</param>
		IWindowBase(const LWINDOWDESC& desc) {}

		/// <summary>���������� ������.</summary>
		virtual ~IWindowBase(void) {}

		/// <summary>������������ ����� ����.</summary>
		virtual void Register(void) = 0;

		/// <summary>�������������� ������.</summary>
		virtual void Unregister(void) = 0;

		/// <summary>������� ����� ����.</summary>
		virtual void Create(void) = 0;

		/// <summary>���������� ����.</summary>
		virtual void Destroy(void) = 0;

		/// <summary>��������� ����.</summary>
		virtual void Update(void) = 0;

		/// <summary>���� ��������� ��������� �� ����.</summary>
		/// <param name="state">��������� �����.</param>
		virtual bool MessageLoop(MESSAGELOOPSTATE state = EMLS_RUN) = 0;

		/// <summary>����������� ���������.</summary>
		/// <param name="text">����� ���������.</param>
		virtual void SetText(const TCHAR* text) = 0;

		/// <summary>���������� ����.</summary>
		virtual void Show(void) = 0;

		/// <summary>�������� ����.</summary>
		virtual void Hide(void) = 0;

		/// <summary>������������ ����.</summary>
		virtual void Maximize(void) = 0;

		/// <summary>���������� ����.</summary>
		virtual void Minimize(void) = 0;

		virtual const LWINDOWDESC& GetWindowDesc(void) const = 0;

		virtual OIS::IInputBase* GetInputManagement(void) = 0;
	};

	CORE_API IWindowBase* RegisterWindow(const LWINDOWDESC& desc);
	CORE_API LRESULT WINAPI ProcessEvent(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);
}

#endif // IWINDOWBASE_H