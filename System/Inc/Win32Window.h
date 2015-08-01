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
		Win32Window(const LWINDOWDESC& desc);

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
		virtual bool MessageLoop(MESSAGELOOPSTATE state);

		/// <summary>Устанавлиет заголовок.</summary>
		/// <param name="text">Текст заголовка.</param>
		virtual void SetText(const TCHAR* text);

		/// <summary>Показывает окно.</summary>
		virtual void Show(void);

		/// <summary>Скрывает окно.</summary>
		virtual void Hide(void);

		/// <summary>Развертывает окно.</summary>
		virtual void Maximize(void);

		/// <summary>Свертывает окно.</summary>
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