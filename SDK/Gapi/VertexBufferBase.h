#ifndef VERTEX_BUFFER_BASE_H
#define VERTEX_BUFFER_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IRenderDeviceBase;
	class IIndexBufferBase;
	class IVertexBufferBase
	{
	public:
		/** Constructor. */
		IVertexBufferBase(IRenderDeviceBase* device) {}

		/** Destructor. */
		virtual ~IVertexBufferBase() {}

		virtual void Create(UInt numberOfVertices, UInt vertexSize) = 0;

		virtual void SetData(void* vertices) = 0;

		virtual void* Lock() = 0;

		virtual void Unlock() = 0;

		virtual void Render(PRIMITIVE_TYPE primitiveType, IIndexBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numberOfVertices, UInt primitiveCount) = 0;
	};

	CORE_API IVertexBufferBase* RegisterVertexBuffer(IRenderDeviceBase* device);
}

#endif