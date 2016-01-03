#ifndef DEVICE_H
#define DEVICE_H

#include "../../SDK/Gapi/DeviceBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class Device : public IDeviceBase
	{
	public:
		static UInt GetFeatureType(FEATURE_TYPE featureType);
		static UInt GetFrontFace(FRONT_FACE face);
		static UInt GetCullFace(CULL_FACE face);
		static UInt GetBlendFunction(BLEND_FUNCTION blendFunction);
		static UInt GetCompareFunction(COMPARE_FUNCTION compareFunction);
		static UInt GetStencilOperation(STENCIL_OPERATION stencilOperation);

		/// <summary>Конструктор класса.</summary>
		/// <param name="handle">Хендл окна.</param>
		Device(HWND handle);

		/// <summary>Деструктор класса.</summary>
		virtual ~Device(void);

		virtual bool Create(void);

		virtual void Destroy(void);

		virtual void MakeCurrentContext(void);

		virtual void ResetCurrentContext(void);

		virtual void DoneCurrentContext(void);

#pragma region Features

		virtual void EnableFeature(FEATURE_TYPE featureType);

		virtual void DisableFeature(FEATURE_TYPE featureType);

		virtual void SetFrontFace(FRONT_FACE frontFace);

		virtual void SetCullFace(CULL_FACE cullFace);

		virtual void SetBlendFunction(BLEND_FUNCTION sourceFunction, BLEND_FUNCTION destinationFunction);

		virtual void SetDepthFunction(COMPARE_FUNCTION depthFunction);

		virtual void SetStencilFunction(COMPARE_FUNCTION stencilFunction, int reference, UInt mask);

		virtual void SetStencilOperation(STENCIL_OPERATION stencilFail, STENCIL_OPERATION depthFail, STENCIL_OPERATION depthPass);

#pragma endregion

#pragma region Masks

		virtual void SetColorMask(bool red, bool green, bool blue, bool alpha);

		virtual void SetDepthMask(bool depth);

		virtual void SetStencilMask(UInt mask);

#pragma endregion

		virtual void SetClearColor(float red, float green, float blue, float alpha) const;

		virtual void SetClearColor(const Math::Color& color) const;

		virtual void Clear(CLEAR_FLAG flags);

		virtual void SetClearDepth(int value);

		virtual void SetClearStencil(int value);

		virtual void SwapChain(void);

		virtual void Flush(void);

		virtual void SetViewport(UInt width, UInt height);

		virtual void SetScissor(UInt x, UInt y, UInt width, UInt height);

#pragma region Capabilities

		virtual const char* GetVersion(void);

		virtual const char* GetVendorName(void);

		virtual const char* GetRendererName(void);

		virtual const char* GetGLSLVersion(void);

		virtual void GetGlInfo(std::ostream& ostr);

		//virtual const char* GetExtensionStringList(void);

#pragma endregion

	private:
		HWND _windowHandle;
		HDC _deviceContext;
		HGLRC _renderContext;

		Utils::ILoggerBase* _logger;

		const char* _version;
		const char* _vendorName;
		const char* _rendererName;
		const char* _GLSLVersion;

		int _majorVersion;
		int _minorVersion;
	};
}

#endif // DEVICE_H