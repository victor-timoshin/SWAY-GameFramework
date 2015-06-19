#ifndef RENDER_CONTEXT_BASE
#define RENDER_CONTEXT_BASE

#include "StdAfx.h"

namespace Gapi
{
	typedef enum WindowMode
	{
		Windowed,
		Fullscreen
	} WINDOWMODE;

	typedef struct WindowDesc
	{
		HWND handle;
		WNDPROC proc;
		WINDOWMODE mode;
		const char* title;
		UInt32 clientWidth;
		UInt32 clientHeight;
	} LWINDOWDESC, *PWINDOWDESC;

	class IRenderContextBase
	{
	public:
		/** Constructor. */
		IRenderContextBase(const LWINDOWDESC& desc) {}

		/** Destructor. */
		virtual ~IRenderContextBase() {}

		/** Creates a new window. */
		virtual void Create() = 0;

		virtual void Update() = 0;

		virtual bool MainLoop(bool isRequestingExit) = 0;

		virtual void SetText(const TCHAR* text) = 0;

		virtual void Show() = 0;

		virtual void Hide() = 0;

		virtual void Minimize() = 0;

		virtual void Maximize() = 0;

		virtual const LWINDOWDESC& GetWindowDesc() const = 0;
	};

	CORE_API IRenderContextBase* RegisterRenderContext(const LWINDOWDESC& desc);
	CORE_API LRESULT WINAPI ProcessEvent(HWND handle, UInt32 message, WPARAM wParam, LPARAM lParam);
}

#endif