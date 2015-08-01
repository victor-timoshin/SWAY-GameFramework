#include "../../GapiOpenGL/Inc/Device.h"

namespace Gapi
{
	/// <summary>Конструктор класса.</summary>
	Device::Device(HWND handle) : IDeviceBase(handle)
		, windowHandle(handle), deviceContext(NULL), renderContext(NULL)
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

		glVersion = (const char*)glGetString(GL_VERSION);
		glVendor = (const char*)glGetString(GL_VENDOR);
		glRenderer = (const char*)glGetString(GL_RENDERER);
		glslVersion = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

		glGetIntegerv(GL_MAJOR_VERSION, &majorVersion);
		glGetIntegerv(GL_MINOR_VERSION, &minorVersion);

#if defined(DEBUG) || defined(_DEBUG)
		(void)IsExtensionSupported("GL_ARB_fragment_program"); // Fragment program support.
		(void)IsExtensionSupported("GL_ARB_vertex_program"); // Vertex program support.
		(void)IsExtensionSupported("GL_ARB_vertex_buffer_object"); // Vertex buffer object support.
		(void)IsExtensionSupported("GL_ARB_shader_objects"); // GLSL support.
		(void)IsExtensionSupported("GL_ARB_multitexture"); // Multitexture support.
		(void)IsExtensionSupported("GL_ARB_texture_compression"); // Compressed texture support.
#endif

		return true;
	}

	void Device::Destroy(void)
	{
		if (renderContext != NULL)
		{
			wglMakeCurrent(deviceContext, 0);
			wglDeleteContext(renderContext);
			renderContext = NULL;
		}

		if (deviceContext != NULL)
			ReleaseDC(windowHandle, deviceContext);
	}

	void Device::MakeCurrentContext(void)
	{
		if (deviceContext && wglGetCurrentContext() != renderContext)
			wglMakeCurrent(deviceContext, renderContext);

		CHECK_GLERROR();
	}

	void Device::ResetCurrentContext(void)
	{
		wglMakeCurrent(deviceContext, NULL);
		CHECK_GLERROR();
	}

	void Device::DoneCurrentContext(void)
	{
		wglMakeCurrent(NULL, NULL);
		CHECK_GLERROR();
	}

	void Device::Clear(CLEARFLAGS flags)
	{
		glShadeModel(GL_SMOOTH);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_CULL_FACE);

		//glFrontFace(GL_CW);

		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_COLOR_MATERIAL);

		glClearStencil(0);
		glClearDepth(1.0f);

		glDepthFunc(GL_LEQUAL);

		glClear((flags & CLEARFLAGS::ECF_COLOR ? GL_COLOR_BUFFER_BIT : 0) | (flags & CLEARFLAGS::ECF_DEPTH ? GL_DEPTH_BUFFER_BIT : 0) | (flags & CLEARFLAGS::ECF_STENCIL ? GL_STENCIL_BUFFER_BIT : 0));
	}

	void Device::SetClearColor(float red, float green, float blue, float alpha) const
	{
		glClearColor(red, green, blue, alpha);
	}

	void Device::SetClearColor(const Math::Color& color) const
	{
		glClearColor(color.GetRedChannel(), color.GetGreenChannel(), color.GetBlueChannel(), color.GetAlphaChannel());
	}

	void Device::SwapChain(void)
	{
		SwapBuffers(deviceContext);
		CHECK_GLERROR();
	}

	void Device::Flush(void)
	{
		glFlush();
		CHECK_GLERROR();
	}

	void Device::SetViewport(UInt width, UInt height)
	{
		glViewport(0, 0, width, height);
		CHECK_GLERROR();
	}

	void Device::SetScissor(UInt x, UInt y, UInt width, UInt height)
	{
		glScissor(x, y, width, height);
	}

#pragma region Capabilities

	const char* Device::GetGlVersionString(void)
	{
		sscanf_s(glVersion, isdigit(*glVersion) ? "%d.%d" : "%*[^0-9]%d.%d", &majorVersion, &minorVersion);
		return glVersion;
	}

	const char* Device::GetGlVendorString(void)
	{
		return glVendor;
	}

	const char* Device::GetGlRendererString(void)
	{
		return glRenderer;
	}

	const char* Device::GetGlslVersionString(void)
	{
		return glslVersion;
	}

	void Device::GetGlInfo(std::ostream& ostr)
	{
		ostr << std::endl;
		ostr << "GL_VERSION: " << glVersion << std::endl;
		ostr << "GL_VENDOR: " << glVendor << std::endl;
		ostr << "GL_RENDERER: " << glRenderer << std::endl;
		ostr << "GL_SHADING_LANGUAGE_VERSION: " << glslVersion << std::endl;
	}

#pragma endregion

	bool Device::IsExtensionSupported(const char* name)
	{
		/* Get all supported extensions. */
		const char* extensions = (const char*)glGetString(GL_EXTENSIONS);
		if (strstr(extensions, name) == NULL)
		{
			Utils::StreamLoggerWrite(Utils::LOGLEVELS::ELL_ERROR, "Extension %s is not supported.", name);
			return false;
		}

		return true;
	}

	IDeviceBase* RegisterDevice(HWND handle)
	{
		return new Device(handle);
	}
}