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
		Device(HWND handle);

		/// <summary>Деструктор класса.</summary>
		virtual ~Device(void);

		virtual bool Create(void);

		virtual void Destroy(void);

		virtual void MakeCurrentContext(void);

		virtual void ResetCurrentContext(void);

		virtual void DoneCurrentContext(void);

		virtual void Clear(CLEARFLAGS flags);

		virtual void SetClearColor(float red, float green, float blue, float alpha) const;

		virtual void SetClearColor(const Math::Color& color) const;

		virtual void SwapChain(void);

		virtual void Flush(void);

		virtual void SetViewport(UInt width, UInt height);

		virtual void SetScissor(UInt x, UInt y, UInt width, UInt height);

#pragma region Capabilities

		virtual const char* GetGlVersionString(void);

		virtual const char* GetGlVendorString(void);

		virtual const char* GetGlRendererString(void);

		virtual const char* GetGlslVersionString(void);

		virtual void GetGlInfo(std::ostream& ostr);

#pragma endregion

	protected:
		bool IsExtensionSupported(const char* name);

	private:
		HWND windowHandle;
		HDC deviceContext;
		HGLRC renderContext;

		Utils::ILoggerBase* logger;

		const char* glVersion;
		const char* glVendor;
		const char* glRenderer;
		const char* glslVersion;

		int majorVersion;
		int minorVersion;
	};
}

#endif // DEVICE_H