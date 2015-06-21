#ifndef WIN32_WINDOW_H
#define WIN32_WINDOW_H

#include "../../SDK/System/WindowBase.h"

namespace Gapi
{
	namespace Win32
	{
		class Win32Window : public IWindowBase
		{
		public:
			static const TCHAR AppWindowClass[];

			/** Constructor. */
			Win32Window(const LWINDOWDESC& desc);

			/** Destructor. */
			virtual ~Win32Window();

			/** Creates a new window. */
			virtual void Create();

			virtual void Update();

			virtual bool MainLoop(bool isRequestingExit);

			virtual void SetText(const TCHAR* text);

			virtual void Show();

			virtual void Hide();

			virtual void Minimize();

			virtual void Maximize();

			virtual const LWINDOWDESC& GetWindowDesc() const;

		private:
			LWINDOWDESC windowDesc;

#if defined(PLATFORM_WINDOWS)
			HINSTANCE hInstance; // Win32 application instance handle.
#else
			XEvent report;
#endif
		};
	}
}

#endif