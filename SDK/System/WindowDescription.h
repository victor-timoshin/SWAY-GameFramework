#ifndef WINDOWDESCRIPTION_H
#define WINDOWDESCRIPTION_H

#include "WindowMode.h"

#include "../Platform.h"

namespace System
{
	typedef struct WindowDescription
	{
#ifdef PLATFORM_WINDOW

		HWND handle; // Хэндл окна.
		WNDPROC proc; // Маршрутизатор сообщений.

#elif PLATFORM_LINUX

		Window handle;
		Display* display; // Указатель на структуру, описывающую соединение с X-сервером.

#endif

		WINDOW_MODE mode; // Режим окна.
		const char* title; // Заголовок окна.
		bool verticalSync; // Вертикальная синхронизация.
		UInt width; // Ширина экрана.
		UInt height; // Высота экрана.
	} WINDOW_DESCRIPTION, *WINDOW_DESCRIPTION_PTR;
}

#endif // WINDOWDESCRIPTION_H