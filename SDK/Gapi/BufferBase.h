#ifndef BUFFER_BASE_H
#define BUFFER_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IDeviceBase;
	class IBufferBase
	{
	public:
		/** Constructor. */
		IBufferBase(IDeviceBase* device) {}

		/** Destructor. */
		virtual ~IBufferBase() {}

		virtual void Create(UInt stride, UInt count) = 0;

		virtual void SetData(void* sourceData) = 0;

		virtual void* Lock() = 0;

		virtual void Unlock() = 0;

		virtual void Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numberOfVertices, UInt primitiveCount) = 0;
	};

	CORE_API IBufferBase* RegisterBuffer(IDeviceBase* device);
}

#endif // BUFFER_BASE_H