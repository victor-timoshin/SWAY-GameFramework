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

		virtual void Clear(CLEARFLAGS flags) = 0;

		virtual void SetClearColor(float red, float green, float blue, float alpha) const = 0;

		virtual void SetClearColor(const Math::Color& color) const = 0;

		virtual void SwapChain(void) = 0;

		virtual void Flush(void) = 0;

		virtual void SetViewport(UInt width, UInt height) = 0;

		virtual void SetScissor(UInt x, UInt y, UInt width, UInt height) = 0;

		virtual void SetCullFormat(CULL_FORMATS format) = 0;

#pragma region Capabilities

		virtual const char* GetGlVersionString(void) = 0;

		virtual const char* GetGlVendorString(void) = 0;

		virtual const char* GetGlRendererString(void) = 0;

		virtual const char* GetGlslVersionString(void) = 0;

		virtual void GetGlInfo(std::ostream& ostr) = 0;

#pragma endregion
	};

	CORE_API IDeviceBase* RegisterDevice(HWND handle);
}

#endif // DEVICEBASE_H