#ifndef RENDER_CONTEXT
#define RENDER_CONTEXT

#include "RenderContextBase.h"

namespace Gapi
{
	class RenderContext: public IRenderContextBase
	{
	public:
		static const TCHAR AppWindowClass[];

		/** Constructor. */
		RenderContext(const LWINDOWDESC& desc);

		/** Destructor. */
		virtual ~RenderContext();

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
		HINSTANCE hInstance; // Win32 application instance handle.
	};
}

#endif