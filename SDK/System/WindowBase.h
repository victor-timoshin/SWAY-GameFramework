#ifndef IWINDOWBASE_H
#define IWINDOWBASE_H

#include "WindowModes.h"
#include "WindowDesc.h"
#include "MessageLoopState.h"

#include "../OIS/InputBase.h"
#include "../Platform.h"

namespace System
{
	class IWindowBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="desc">Описание окна.</param>
		IWindowBase(const LWINDOWDESC& desc) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IWindowBase(void) {}

		/// <summary>Ругистрирует класс окна.</summary>
		virtual void Register(void) = 0;

		/// <summary>Разрегистрация класса.</summary>
		virtual void Unregister(void) = 0;

		/// <summary>Создает новое окно.</summary>
		virtual void Create(void) = 0;

		/// <summary>Уничтожает окно.</summary>
		virtual void Destroy(void) = 0;

		/// <summary>Обновляет окно.</summary>
		virtual void Update(void) = 0;

		/// <summary>Цикл обработки сообщений от окна.</summary>
		/// <param name="state">Состояние цикла.</param>
		virtual bool MessageLoop(MESSAGE_LOOP_STATE state) = 0;

		/// <summary>Устанавлиет заголовок.</summary>
		/// <param name="text">Текст заголовка.</param>
		virtual void SetTitle(const char* text) = 0;

		virtual const char* GetTitle(void) = 0;

		/// <summary>Показывает окно.</summary>
		virtual void Show(void) = 0;

		virtual void ShowDeactivated(void) = 0;

		virtual void ShowRestored(void) = 0;

		/// <summary>Развертывает окно.</summary>
		virtual void ShowMaximized(void) = 0;

		/// <summary>Свертывает окно.</summary>
		virtual void ShowMinimized(void) = 0;

		/// <summary>Скрывает окно.</summary>
		virtual void Hide(void) = 0;

		virtual bool IsVisible(void) = 0;

		virtual void Enable(void) = 0;

		virtual void Disable(void) = 0;

		virtual bool IsEnabled(void) = 0;

		virtual const LWINDOWDESC& GetWindowDesc(void) const = 0;

		virtual OIS::IInputBase* GetInputManagement(void) = 0;
	};

	CORE_API IWindowBase* RegisterWindow(const LWINDOWDESC& desc);
	CORE_API LRESULT WINAPI ProcessEvent(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);
}

#endif // IWINDOWBASE_H