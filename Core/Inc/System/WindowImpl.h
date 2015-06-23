#ifndef WINDOW_IMPL_H
#define WINDOW_IMPL_H

#include "../../../SDK/Core/System/WindowBase.h"

namespace Core
{
	namespace System
	{
		class WindowImpl : public IWindowBase
		{
		public:
			static const TCHAR AppWindowClass[];

			/** Constructor. */
			WindowImpl(const LWINDOWDESC& desc);

			/** Destructor. */
			virtual ~WindowImpl();

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