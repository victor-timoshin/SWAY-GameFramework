#include "..\Inc\RenderDevice.h"

namespace Gapi
{
	/** Constructor. */
	RenderDevice::RenderDevice(IRenderContextBase* context) : IRenderDeviceBase(context)
		, deviceContext(0L)
		, renderContext(0L)
	{
		windowDesc = context->GetWindowDesc();
	}

	/** Destructor. */
	RenderDevice::~RenderDevice()
	{
		if (renderContext != 0L)
		{
			wglMakeCurrent(deviceContext, 0);
			wglDeleteContext(renderContext);
			renderContext = 0L;
		}

		if (deviceContext != 0L)
			ReleaseDC(windowDesc.handle, deviceContext);
	}

	void RenderDevice::Initialize()
	{
		PIXELFORMATDESCRIPTOR pixelFormatDesc;
		ZeroMemory(&pixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));

		pixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pixelFormatDesc.nVersion = 1;
		pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
		pixelFormatDesc.cColorBits = 24;
		pixelFormatDesc.cDepthBits = 16;
		pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;

		deviceContext = ::GetDC(windowDesc.handle);

		SetPixelFormat(deviceContext, ChoosePixelFormat(deviceContext, &pixelFormatDesc), &pixelFormatDesc);
		wglMakeCurrent(deviceContext, wglCreateContext(deviceContext));
	}

	void RenderDevice::Clear(float red, float green, float blue, float alpha)
	{
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);

		glClearDepth(1.0f);

		glDepthFunc(GL_LESS);
		glEnable(GL_DEPTH_TEST);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_NORMALIZE);

		glClearColor(red, green, blue, alpha);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	bool RenderDevice::Swap()
	{
		glFlush();
		CHECK_ERROR(SwapBuffers(deviceContext));

		return true;
	}

	IRenderDeviceBase* RegisterRenderDevice(IRenderContextBase* context)
	{
		return new RenderDevice(context);
	}
}