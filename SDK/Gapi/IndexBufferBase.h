#ifndef INDEX_BUFFER_BASE_H
#define INDEX_BUFFER_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IRenderDeviceBase;
	class IIndexBufferBase
	{
	public:
		/** Constructor. */
		IIndexBufferBase(IRenderDeviceBase* device) {}

		/** Destructor. */
		virtual ~IIndexBufferBase() {}

		virtual void Create(UInt numberOfIndices, UInt indexSize) = 0;

		virtual void SetData(void* indices) = 0;

		virtual void* Lock() = 0;

		virtual void Unlock() = 0;
	};

	CORE_API IIndexBufferBase* RegisterIndexBuffer(IRenderDeviceBase* device);
}

#endif