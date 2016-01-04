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

		/// <summary>Конструктор класса.</summary>
		/// <param name="desc">Описание окна.</param>
		Win32Window(const WINDOW_DESCRIPTION& desc);

		/// <summary>Деструктор класса.</summary>
		virtual ~Win32Window(void);

		/// <summary>Ругистрирует класс окна.</summary>
		virtual void Register(void);

		/// <summary>Разрегистрация класса.</summary>
		virtual void Unregister(void);

		/// <summary>Создает новое окно.</summary>
		virtual void Create(void);

		/// <summary>Уничтожает окно.</summary>
		virtual void Destroy(void);

		/// <summary>Обновляет окно.</summary>
		virtual void Update(void);

		/// <summary>Цикл обработки сообщений от окна.</summary>
		/// <param name="state">Состояние цикла.</param>
		virtual bool MessageLoop(MESSAGE_LOOP_STATE state);

		/// <summary>Устанавлиет заголовок.</summary>
		/// <param name="text">Текст заголовка.</param>
		virtual void SetTitle(const char* text);

		virtual const char* GetTitle(void);

		/// <summary>Показывает окно.</summary>
		virtual void Show(void);

		virtual void ShowDeactivated(void);

		virtual void ShowRestored(void);

		/// <summary>Развертывает окно.</summary>
		virtual void ShowMaximized(void);

		/// <summary>Свертывает окно.</summary>
		virtual void ShowMinimized(void);

		/// <summary>Скрывает окно.</summary>
		virtual void Hide(void);

		virtual bool IsVisible(void);

		virtual void Enable(void);

		virtual void Disable(void);

		virtual bool IsEnabled(void);

		virtual const WINDOW_DESCRIPTION& GetWindowDesc(void) const;

		virtual OIS::IInputBase* GetInputManagement(void);

#ifdef PLATFORM_WINDOW

		LRESULT MessageProc(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK WindowProc(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);

#endif

	private:
		WINDOW_DESCRIPTION windowDesc;

#ifdef PLATFORM_WINDOW

		HINSTANCE hInstance;

#elif PLATFORM_LINUX

		XEvent _report;

#endif
	};
}

#endif // WINDOWCTRL_H