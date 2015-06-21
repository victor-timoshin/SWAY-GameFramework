#ifndef SHADER_BASE_H
#define SHADER_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IRenderDeviceBase;
	class IShaderBase
	{
	public:
		/** Constructor. */
		IShaderBase(IRenderDeviceBase* device) {}

		/** Destructor. */
		virtual ~IShaderBase() {}

		virtual bool CreateFromFile(const char* vertexSource, const char* pixelSource) = 0;

		virtual void SetVConstantByName(const char* name, const void* source) = 0;

		virtual void SetPConstantByName(const char* name, const void* source) = 0;

		virtual void UseActiveObject() = 0;
	};

	CORE_API IShaderBase* RegisterShader(IRenderDeviceBase* device);
}

#endif