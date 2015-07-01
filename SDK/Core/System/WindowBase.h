#ifndef WINDOW_BASE
#define WINDOW_BASE

#include "../OIS/InputBase.h"
#include "../../Platform.h"

namespace Core
{
	namespace System
	{
		typedef enum WindowMode
		{
			TYPE_WINDOWED = 0xB2C0,
			TYPE_FULLSCREEN = 0x9D44
		} WINDOWMODE;

		typedef struct WindowDesc
		{
			HWND handle;
			WNDPROC proc;
			WINDOWMODE mode;
			const char* title;
			UInt clientWidth;
			UInt clientHeight;
		} LWINDOWDESC, *PWINDOWDESC;

		//Win32Api
		class IWindowBase
		{
		public:
			/** Constructor. */
			IWindowBase(const LWINDOWDESC& desc) {}

			/** Destructor. */
			virtual ~IWindowBase() {}

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

			//virtual OIS::IInputEventBase* GetInputManagement() = 0;
			virtual OIS::IInputBase* GetInputManagement() = 0;
		};

		CORE_API IWindowBase* RegisterWindow(const LWINDOWDESC& desc);
		CORE_API LRESULT WINAPI ProcessEvent(HWND handle, UInt message, WPARAM wParam, LPARAM lParam);
	}
}

#endif // WINDOW_BASE