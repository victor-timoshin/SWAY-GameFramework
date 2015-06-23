#include "../../GapiOpenGL/Inc/OGLDevice.h"

namespace Gapi
{
	unsigned char OGLDevice::primitiveType[] = {
		GL_POINTS,
		GL_LINES,
		GL_LINE_STRIP,
		GL_TRIANGLES,
		GL_TRIANGLE_STRIP
	};

	unsigned char OGLDevice::Get(PRIMITIVE_TYPE Value) {
		return primitiveType[Value];
	}

	/** Constructor. */
	OGLDevice::OGLDevice(Core::System::IWindowBase* window) : IDeviceBase(window)
#ifdef PLATFORM_WINDOWS
		, deviceContext(0L)
		, renderContext(0L)
#endif
	{
		windowDesc = window->GetWindowDesc();
	}

	/** Destructor. */
	OGLDevice::~OGLDevice()
	{
#ifdef PLATFORM_WINDOWS
		if (renderContext != 0L)
		{
			wglMakeCurrent(deviceContext, 0);
			wglDeleteContext(renderContext);
			renderContext = 0L;
		}

		if (deviceContext != 0L)
			ReleaseDC(windowDesc.handle, deviceContext);
#endif
	}

	void OGLDevice::Initialize()
	{
#ifdef PLATFORM_WINDOWS
		PIXELFORMATDESCRIPTOR pixelFormatDesc;
		ZeroMemory(&pixelFormatDesc, sizeof(PIXELFORMATDESCRIPTOR));

		pixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
		pixelFormatDesc.nVersion = 1;
		pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
		pixelFormatDesc.cColorBits = 24;
		pixelFormatDesc.cDepthBits = 16;
		pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;

		deviceContext = GetDC(windowDesc.handle);

		SetPixelFormat(deviceContext, ChoosePixelFormat(deviceContext, &pixelFormatDesc), &pixelFormatDesc);
		wglMakeCurrent(deviceContext, wglCreateContext(deviceContext));
#else
		int dummy = 0;
		glXQueryExtension(windowDesc.display, &dummy, &dummy);

		int doubleBuffer[] = { GLX_RGBA, GLX_DEPTH_SIZE, 16, GLX_DOUBLEBUFFER, None };
		visualInfo = glXChooseVisual(windowDesc.display, DefaultScreen(windowDesc.display), doubleBuffer);
		if (visualInfo == 0L)
		{
			int singleBuffer[] = { GLX_RGBA, GLX_DEPTH_SIZE, 16, None };
			visualInfo = glXChooseVisual(windowDesc.display, DefaultScreen(windowDesc.display), singleBuffer);
		}

		context = glXCreateContext(windowDesc.display, visualInfo, None, GL_TRUE);
#endif

#if defined(DEBUG) || defined(_DEBUG)
#endif
	}

	void OGLDevice::Clear(float red, float green, float blue, float alpha)
	{
		glShadeModel(GL_SMOOTH);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_CULL_FACE);

		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

		glClearColor(red, green, blue, alpha);
		glClearStencil(0);
		glClearDepth(1.0f);

		glDepthFunc(GL_LEQUAL);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	bool OGLDevice::Swap()
	{
#ifdef PLATFORM_WINDOWS
		glFlush();
		CHECK_ERROR(SwapBuffers(deviceContext));
#endif

		return true;
	}

	void OGLDevice::SetViewport(float width, float height)
	{
		glViewport(0, 0, width, height);
	}

	IDeviceBase* RegisterDevice(Core::System::IWindowBase* context)
	{
		return new OGLDevice(context);
	}
}