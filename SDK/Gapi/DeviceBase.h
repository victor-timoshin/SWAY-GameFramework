#ifndef DEVICEBASE_H
#define DEVICEBASE_H

#include "../../Math/Inc/Color.h"
#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IDeviceBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="handle">Хендл окна.</param>
		IDeviceBase(HWND handle) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IDeviceBase(void) {}

		virtual bool Create(void) = 0;

		virtual void Destroy(void) = 0;

		virtual void MakeCurrentContext(void) = 0;

		virtual void ResetCurrentContext(void) = 0;

		virtual void DoneCurrentContext(void) = 0;

#pragma region Features

		virtual void EnableFeature(FEATURE_TYPE featureType) = 0;

		virtual void DisableFeature(FEATURE_TYPE featureType) = 0;

		virtual void SetFrontFace(FRONT_FACE frontFace) = 0;

		virtual void SetCullFace(CULL_FACE cullFace) = 0;

		virtual void SetBlendFunction(BLEND_FUNCTION sourceFunction, BLEND_FUNCTION destinationFunction) = 0;

		virtual void SetDepthFunction(COMPARE_FUNCTION depthFunction) = 0;

		virtual void SetStencilFunction(COMPARE_FUNCTION stencilFunction, int reference, UInt mask) = 0;

		virtual void SetStencilOperation(STENCIL_OPERATION stencilFail, STENCIL_OPERATION depthFail, STENCIL_OPERATION depthPass) = 0;

#pragma endregion

#pragma region Masks

		virtual void SetColorMask(bool red, bool green, bool blue, bool alpha) = 0;

		virtual void SetDepthMask(bool depth) = 0;

		virtual void SetStencilMask(UInt mask) = 0;

#pragma endregion

		virtual void SetClearColor(float red, float green, float blue, float alpha) const = 0;

		virtual void SetClearColor(const Math::Color& color) const = 0;

		virtual void Clear(CLEAR_FLAG flags) = 0;

		virtual void SetClearDepth(int value) = 0;

		virtual void SetClearStencil(int value) = 0;

		virtual void SwapChain(void) = 0;

		virtual void Flush(void) = 0;

		virtual void SetViewport(UInt width, UInt height) = 0;

		virtual void SetScissor(UInt x, UInt y, UInt width, UInt height) = 0;

#pragma region Capabilities

		virtual const char* GetVersion(void) = 0;

		virtual const char* GetVendorName(void) = 0;

		virtual const char* GetRendererName(void) = 0;

		virtual const char* GetGLSLVersion(void) = 0;

		virtual void GetGlInfo(std::ostream& ostr) = 0;

#pragma endregion
	};

	CORE_API IDeviceBase* RegisterDevice(HWND handle);
}

#endif // DEVICEBASE_H