#include "../../GapiOpenGL/Inc/OGLDevice.h"

namespace Gapi
{
	UByte OGLDevice::Get(PRIMITIVE_TYPE type)
	{
		switch (type)
		{
			case TYPE_POINTLIST: return GL_POINTS;
			case TYPE_LINELIST: return GL_LINES;
			case TYPE_LINESTRIP: return GL_LINE_STRIP;
			case TYPE_TRIANGLELIST: return GL_TRIANGLES;
			case TYPE_TRIANGLESTRIP: return GL_TRIANGLE_STRIP;
		}

		return (PRIMITIVE_TYPE)-1;
	}

	/** Constructor. */
	OGLDevice::OGLDevice(Core::System::IWindowBase* window) : IDeviceBase(window)
		, deviceContext(0L), renderContext(0L)
	{
		windowDesc = window->GetWindowDesc();
	}

	/** Destructor. */
	OGLDevice::~OGLDevice()
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

	void OGLDevice::Initialize()
	{
		PIXELFORMATDESCRIPTOR pixelFormatDesc;
		ZeroMemory(&pixelFormatDesc, sizeof PIXELFORMATDESCRIPTOR);

		pixelFormatDesc.nSize = sizeof PIXELFORMATDESCRIPTOR;
		pixelFormatDesc.nVersion = 1;
		pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
		pixelFormatDesc.cColorBits = 24;
		pixelFormatDesc.cDepthBits = 16;
		pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;

		deviceContext = GetDC(windowDesc.handle);

		SetPixelFormat(deviceContext, ChoosePixelFormat(deviceContext, &pixelFormatDesc), &pixelFormatDesc);
		wglMakeCurrent(deviceContext, wglCreateContext(deviceContext));

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
		glFlush();
		CHECK_ERROR(SwapBuffers(deviceContext));

		return true;
	}

	void OGLDevice::SetViewport(UInt width, UInt height)
	{
		glViewport(0, 0, width, height);
	}

	IDeviceBase* RegisterDevice(Core::System::IWindowBase* window)
	{
		return new OGLDevice(window);
	}

}