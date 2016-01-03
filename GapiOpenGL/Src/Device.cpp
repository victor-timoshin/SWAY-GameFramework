#include "../../GapiOpenGL/Inc/Device.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

namespace Gapi
{
	UInt Device::GetFeatureType(FEATURE_TYPE featureType)
	{
		switch (featureType)
		{
		case FEATURE_TYPE::Culling:        return GL_CULL_FACE;
		case FEATURE_TYPE::Blending:       return GL_BLEND;
		case FEATURE_TYPE::DepthTesting:   return GL_DEPTH_TEST;
		case FEATURE_TYPE::StencilTesting: return GL_STENCIL_TEST;
		default:
			return 0;
		}
	}

	UInt Device::GetCullFace(CULL_FACE face)
	{
		switch (face)
		{
		case CULL_FACE::Back:  return GL_BACK;
		case CULL_FACE::Front: return GL_FRONT;
		default:
			return 0;
		}
	}

	UInt Device::GetFrontFace(FRONT_FACE face)
	{
		switch (face)
		{
		case FRONT_FACE::ClockWise:        return GL_CW;
		case FRONT_FACE::CounterClockWise: return GL_CCW;
		default:
			return 0;
		}
	}

	UInt Device::GetBlendFunction(BLEND_FUNCTION blendFunction)
	{
		switch (blendFunction)
		{
		case BLEND_FUNCTION::Zero:                     return GL_ZERO;
		case BLEND_FUNCTION::One:                      return GL_ONE;
		case BLEND_FUNCTION::SourceColor:              return GL_SRC_COLOR;
		case BLEND_FUNCTION::OneMinusSourceColor:      return GL_ONE_MINUS_SRC_COLOR;
		case BLEND_FUNCTION::DestinationColor:         return GL_DST_COLOR;
		case BLEND_FUNCTION::OneMinusDestinationColor: return GL_ONE_MINUS_DST_COLOR;
		case BLEND_FUNCTION::SourceAlpha:              return GL_SRC_ALPHA;
		case BLEND_FUNCTION::OneMinusSourceAlpha:      return GL_ONE_MINUS_SRC_ALPHA;
		case BLEND_FUNCTION::DestinationAlpha:         return GL_DST_ALPHA;
		case BLEND_FUNCTION::OneMinusDestinationAlpha: return GL_ONE_MINUS_DST_ALPHA;
		case BLEND_FUNCTION::SourceAlphaSaturate:      return GL_SRC_ALPHA_SATURATE;
		default:
			return 0;
		}
	}

	UInt Device::GetCompareFunction(COMPARE_FUNCTION compareFunction)
	{
		switch (compareFunction)
		{
		case COMPARE_FUNCTION::Never:          return GL_NEVER;
		case COMPARE_FUNCTION::Always:         return GL_ALWAYS;
		case COMPARE_FUNCTION::Equal:          return GL_EQUAL;
		case COMPARE_FUNCTION::NotEqual:       return GL_NOTEQUAL;
		case COMPARE_FUNCTION::Less:           return GL_LESS;
		case COMPARE_FUNCTION::LessOrEqual:    return GL_LEQUAL;
		case COMPARE_FUNCTION::Greater:        return GL_GREATER;
		case COMPARE_FUNCTION::GreaterOrEqual: return GL_GEQUAL;
		default:
			return 0;
		}
	}

	UInt Device::GetStencilOperation(STENCIL_OPERATION stencilOperation)
	{
		switch (stencilOperation)
		{
		case STENCIL_OPERATION::Keep:          return GL_KEEP;
		case STENCIL_OPERATION::Zero:          return GL_ZERO;
		case STENCIL_OPERATION::Replace:       return GL_REPLACE;
		case STENCIL_OPERATION::Increment:     return GL_INCR;
		case STENCIL_OPERATION::IncrementWrap: return GL_INCR_WRAP;
		case STENCIL_OPERATION::Decrement:     return GL_DECR;
		case STENCIL_OPERATION::DecrementWrap: return GL_DECR_WRAP;
		case STENCIL_OPERATION::Invert:        return GL_INVERT;
		default:
			return 0;
		}
	}

	/// <summary>Конструктор класса.</summary>
	/// <param name="handle">Хендл окна.</param>
	Device::Device(HWND handle) : IDeviceBase(handle)
		, _windowHandle(handle)
		, _deviceContext(nullptr)
		, _renderContext(nullptr)
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

		_deviceContext = GetDC(_windowHandle);

		int pixelFormatIdx = ChoosePixelFormat(_deviceContext, &pixelFormatDesc);
		if (pixelFormatIdx == 0)
		{
			ReleaseDC(_windowHandle, _deviceContext);
			return false;
		}

		if (SetPixelFormat(_deviceContext, pixelFormatIdx, &pixelFormatDesc))
		{
			_renderContext = wglCreateContext(_deviceContext);
			if (_renderContext)
				MakeCurrentContext();
			else
			{
				ReleaseDC(_windowHandle, _deviceContext);
				wglDeleteContext(_renderContext);
				return false;
			}
		}
		else
		{
			ReleaseDC(_windowHandle, _deviceContext);
			return false;
		}

		_version = (const char*)glGetString(GL_VERSION);
		_vendorName = (const char*)glGetString(GL_VENDOR);
		_rendererName = (const char*)glGetString(GL_RENDERER);
		_GLSLVersion = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

		glGetIntegerv(GL_MAJOR_VERSION, &_majorVersion);
		glGetIntegerv(GL_MINOR_VERSION, &_minorVersion);

		// Инициализируем расширения.
		InitializeExtensions();

		return true;
	}

	void Device::Destroy(void)
	{
		if (_renderContext != nullptr)
		{
			wglMakeCurrent(_deviceContext, 0);
			wglDeleteContext(_renderContext);
			_renderContext = nullptr;
		}

		if (_deviceContext != nullptr)
			ReleaseDC(_windowHandle, _deviceContext);
	}

	void Device::MakeCurrentContext(void)
	{
		if (_deviceContext AND wglGetCurrentContext() != _renderContext)
			wglMakeCurrent(_deviceContext, _renderContext);

		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::ResetCurrentContext(void)
	{
		wglMakeCurrent(_deviceContext, nullptr);
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

	void Device::DoneCurrentContext(void)
	{
		wglMakeCurrent(nullptr, nullptr);
		CHECK_OPENGL_ERROR(SOURCE_LOCATION);
	}

#pragma region Features

	void Device::EnableFeature(FEATURE_TYPE featureType)
	{
		UInt capability = Device::GetFeatureType(featureType);
		if (NOT capability)
			return;

		glEnable(capability);
	}

	void Device::DisableFeature(FEATURE_TYPE featureType)
	{
		UInt capability = Device::GetFeatureType(featureType);
		if (NOT capability)
			return;

		glDisable(capability);
	}

	void Device::SetFrontFace(FRONT_FACE frontFace)
	{
		UInt mode = Device::GetFrontFace(frontFace);
		if (NOT mode)
			return;

		glFrontFace(mode);
	}

	void Device::SetCullFace(CULL_FACE cullFace)
	{
		UInt mode = Device::GetCullFace(cullFace);
		if (NOT mode)
			return;

		glCullFace(mode);
	}

	void Device::SetBlendFunction(BLEND_FUNCTION sourceFunction, BLEND_FUNCTION destinationFunction)
	{
		UInt sourceFactor = Device::GetBlendFunction(sourceFunction);
		UInt destinationFactor = Device::GetBlendFunction(destinationFunction);

		if (NOT sourceFactor OR NOT destinationFactor)
			return;

		glBlendFunc(sourceFactor, destinationFactor);
	}

	void Device::SetDepthFunction(COMPARE_FUNCTION depthFunction)
	{
		UInt function = Device::GetCompareFunction(depthFunction);
		if (NOT function)
			return;

		glDepthFunc(function);
	}

	void Device::SetStencilFunction(COMPARE_FUNCTION stencilFunction, int reference, UInt mask)
	{
		UInt function = Device::GetCompareFunction(stencilFunction);
		if (NOT function)
			return;

		glStencilFunc(function, reference, mask);
	}

	void Device::SetStencilOperation(STENCIL_OPERATION stencilFail, STENCIL_OPERATION depthFail, STENCIL_OPERATION depthPass)
	{
		UInt currentStencilFail = Device::GetStencilOperation(stencilFail);
		UInt currentDepthFail   = Device::GetStencilOperation(depthFail);
		UInt currentDepthPass   = Device::GetStencilOperation(depthPass);

		if (NOT currentStencilFail OR NOT currentDepthFail OR NOT currentDepthPass)
			return;

		glStencilOp(currentStencilFail, currentDepthFail, currentDepthPass);
	}

#pragma endregion

#pragma region Masks

	void Device::SetColorMask(bool red, bool green, bool blue, bool alpha)
	{
		glColorMask(red, green, blue, alpha);
	}

	void Device::SetDepthMask(bool depth)
	{
		glDepthMask(depth);
	}

	void Device::SetStencilMask(UInt mask)
	{
		glStencilMask(mask);
	}

#pragma endregion

	void Device::SetClearColor(float red, float green, float blue, float alpha) const
	{
		glClearColor(red, green, blue, alpha);
	}

	void Device::SetClearColor(const Math::Color& color) const
	{
		glClearColor(color.GetR(), color.GetG(), color.GetB(), color.GetA());
	}

	void Device::Clear(CLEAR_FLAG flags)
	{
		glShadeModel(GL_SMOOTH);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

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

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);

		SetClearStencil(0);
		SetClearDepth(1);

		glClear((flags & CLEAR_FLAG::Color ? GL_COLOR_BUFFER_BIT : 0) | (flags & CLEAR_FLAG::Depth ? GL_DEPTH_BUFFER_BIT : 0) | (flags & CLEAR_FLAG::Stencil ? GL_STENCIL_BUFFER_BIT : 0));
	}

	void Device::SetClearDepth(int value)
	{
		glClearDepth(value);
	}

	void Device::SetClearStencil(int value)
	{
		glClearStencil(value);
	}

	void Device::SwapChain(void)
	{
		SwapBuffers(_deviceContext);
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

#pragma region Capabilities

	const char* Device::GetVersion(void)
	{
		sscanf_s(_version, isdigit(*_version) ? "%d.%d" : "%*[^0-9]%d.%d", &_majorVersion, &_minorVersion);
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