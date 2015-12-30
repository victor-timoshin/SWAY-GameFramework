#ifndef DEVICE_H
#define DEVICE_H

#include "../../SDK/Gapi/DeviceBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class Device : public IDeviceBase
	{
	public:
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

		virtual void Clear(CLEARFLAG flags);

		virtual void SetClearDepth(int value);

		virtual void SetClearStencil(int value);

		virtual void SetClearColor(float red, float green, float blue, float alpha) const;

		virtual void SetClearColor(const Math::Color& color) const;

		virtual void SwapChain(void);

		virtual void Flush(void);

		virtual void SetViewport(UInt width, UInt height);

		virtual void SetScissor(UInt x, UInt y, UInt width, UInt height);

		virtual void SetCullFormat(CULL_FORMAT format);

#pragma region Capabilities

		virtual const char* GetVersion(void);

		virtual const char* GetVendorName(void);

		virtual const char* GetRendererName(void);

		virtual const char* GetGLSLVersion(void);

		virtual void GetGlInfo(std::ostream& ostr);

		//virtual const char* GetExtensionStringList(void);

#pragma endregion

	private:
		HWND windowHandle;
		HDC deviceContext;
		HGLRC renderContext;

		Utils::ILoggerBase* logger;

		const char* _version;
		const char* _vendorName;
		const char* _rendererName;
		const char* _GLSLVersion;

		int majorVersion;
		int minorVersion;
	};
}

#endif // DEVICE_H