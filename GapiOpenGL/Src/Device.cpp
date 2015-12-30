#include "../../GapiOpenGL/Inc/Device.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

namespace Gapi
{
	/// <summary>Конструктор класса.</summary>
	/// <param name="handle">Хендл окна.</param>
	Device::Device(HWND handle) : IDeviceBase(handle)
		, windowHandle(handle)
		, deviceContext(nullptr)
		, renderContext(nullptr)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Device::~Device(void)
	{
		Destroy();
	}

	bool Device::Create(void)
	{
		PIXELFORMATDESCRIPTOR pixelFormatDesc;
		ZeroMemory(&pixelFormatDesc, sizeof PIXELFORMATDESCRIPTOR);

		pixelFormatDesc.nSize = sizeof PIXELFORMATDESCRIPTOR; // Size of this pixel format descriptor.
		pixelFormatDesc.nVersion = 1; // Version number.
		pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixelFormatDesc.iPixelType = PFD_TYPE_RGBA; // Request an RGBA format.
		pixelFormatDesc.cColorBits = 24;
		pixelFormatDesc.cDepthBits = 16;
		pixelFormatDesc.iLayerType = PFD_MAIN_PLANE; // Main drawing layer.

		deviceContext = GetDC(windowHandle);

		int pixelFormatIdx = ChoosePixelFormat(deviceContext, &pixelFormatDesc);
		if (pixelFormatIdx == 0)
		{
			ReleaseDC(windowHandle, deviceContext);
			return false;
		}

		if (SetPixelFormat(deviceContext, pixelFormatIdx, &pixelFormatDesc))
		{
			renderContext = wglCreateContext(deviceContext);
			if (renderContext)
				MakeCurrentContext();
			else
			{
				ReleaseDC(windowHandle, deviceContext);
				wglDeleteContext(renderContext);
				return false;
			}
		}
		else
		{
			ReleaseDC(windowHandle, deviceContext);
			return false;
		}

		_version = (const char*)glGetString(GL_VERSION);
		_vendorName = (const char*)glGetString(GL_VENDOR);
		_rendererName = (const char*)glGetString(GL_RENDERER);
		_GLSLVersion = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

		glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
		glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

		// Инициализируем расширения.
		InitializeExtensions();

		return true;
	}

	void Device::Destroy(void)
	{
		if (renderContext != nullptr)
		{
			wglMakeCurrent(deviceContext, 0);
			wglDeleteContext(renderContext);
			renderContext = nullptr;
		}

		if (deviceContext != nullptr)
			ReleaseDC(windowHandle, deviceContext);
	}

	void Device::MakeCurrentContext(void)
	{
		if (deviceContext && wglGetCurrentContext() != renderContext)
			wglMakeCurrent(deviceContext, renderContext);

		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::ResetCurrentContext(void)
	{
		wglMakeCurrent(deviceContext, nullptr);
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::DoneCurrentContext(void)
	{
		wglMakeCurrent(nullptr, nullptr);
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::Clear(CLEARFLAG flags)
	{
		glShadeModel(GL_SMOOTH);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		GLfloat lightModelAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightModelAmbient);

		GLfloat lightAmbient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);

		GLfloat lightDiffuse[] = { 0.75f, 0.75f, 0.75f, 1.0f };
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);

		GLfloat materialAmbient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialAmbient);

		GLfloat materialDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);

		GLfloat lightPosition[] = { 0.0f, 0.0f, 2.5f, 1.0f };
		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);

		SetClearStencil(0);
		SetClearDepth(1.0f);

		glDepthFunc(GL_LEQUAL);

		glClear((flags & CLEARFLAG::Color ? GL_COLOR_BUFFER_BIT : 0) | (flags & CLEARFLAG::Depth ? GL_DEPTH_BUFFER_BIT : 0) | (flags & CLEARFLAG::Stencil ? GL_STENCIL_BUFFER_BIT : 0));
	}

	void Device::SetClearDepth(int value)
	{
		glClearDepth(value);
		//glClear(GL_DEPTH_BUFFER_BIT);
	}

	void Device::SetClearStencil(int value)
	{
		glClearStencil(value);
		//glClear(GL_STENCIL_BUFFER_BIT);
	}

	void Device::SetClearColor(float red, float green, float blue, float alpha) const
	{
		glClearColor(red, green, blue, alpha);
	}

	void Device::SetClearColor(const Math::Color& color) const
	{
		glClearColor(color.GetR(), color.GetG(), color.GetB(), color.GetA());
	}

	void Device::SwapChain(void)
	{
		SwapBuffers(deviceContext);
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::Flush(void)
	{
		glFlush();
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::SetViewport(UInt width, UInt height)
	{
		glViewport(0, 0, width, height);
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::SetScissor(UInt x, UInt y, UInt width, UInt height)
	{
		glScissor(x, y, width, height);
	}

	void Device::SetCullFormat(CULL_FORMAT format)
	{
		switch (format)
		{
		case CULL_FORMAT::ECF_CW:
			glEnable(GL_CULL_FACE);
			glFrontFace(GL_CW);
			break;

		case CULL_FORMAT::ECF_CCW:
			glEnable(GL_CULL_FACE);
			glFrontFace(GL_CCW);
			break;

		case CULL_FORMAT::ECF_NONE:
			glDisable(GL_CULL_FACE);
			break;
		}
	}

#pragma region Capabilities

	const char* Device::GetVersion(void)
	{
		sscanf_s(_version, isdigit(*_version) ? "%d.%d" : "%*[^0-9]%d.%d", &majorVersion, &minorVersion);
		return _version;
	}

	const char* Device::GetVendorName(void)
	{
		return _vendorName;
	}

	const char* Device::GetRendererName(void)
	{
		return _rendererName;
	}

	const char* Device::GetGLSLVersion(void)
	{
		return _GLSLVersion;
	}

	void Device::GetGlInfo(std::ostream& ostr)
	{
		ostr << std::endl;
		ostr << "GL_VERSION: " << GetVersion() << std::endl;
		ostr << "GL_VENDOR: " << GetVendorName() << std::endl;
		ostr << "GL_RENDERER: " << GetRendererName() << std::endl;
		ostr << "GL_SHADING_LANGUAGE_VERSION: " << GetGLSLVersion() << std::endl;
	}

#pragma endregion

	IDeviceBase* RegisterDevice(HWND handle)
	{
		return new Device(handle);
	}
}