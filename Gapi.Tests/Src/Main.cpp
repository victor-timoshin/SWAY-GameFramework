#include "../../Gapi/Inc/StdAfx.h"
#include "../../Gapi/Inc/RenderContextBase.h"
#include "../../Gapi/Inc/RenderDeviceBase.h"

#pragma comment(lib, "Gapi_Win32_Debug")

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
	Gapi::LWINDOWDESC windowDesc;
	windowDesc.proc = Gapi::ProcessEvent;
	windowDesc.mode = Gapi::WINDOWMODE::Windowed;
	windowDesc.title = "Test";
	windowDesc.clientWidth = WINDOW_WIDTH;
	windowDesc.clientHeight = WINDOW_HEIGHT;

	Gapi::IRenderContextBase* renderContext = 0L;
	renderContext = Gapi::RegisterRenderContext(windowDesc);
	renderContext->Create();
	renderContext->Update();
	renderContext->Show();

	Gapi::IRenderDeviceBase* renderDevice = 0L;
	renderDevice = Gapi::RegisterRenderDevice(renderContext);
	renderDevice->Initialize();

	while (renderContext->MainLoop(false))
	{
		renderDevice->Clear(0.0f, 0.0f, 0.0f, 0.0f);
		renderDevice->Swap();
	}

	SAFE_DELETE(renderDevice);
	SAFE_DELETE(renderContext);
	return 0;
}