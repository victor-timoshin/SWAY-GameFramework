#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "../../SDK/Gapi/VertexBufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	namespace OpenGL
	{
		class VertexBuffer: public IVertexBufferBase
		{
		public:
#ifdef PLATFORM_WINDOWS
			static PFNGLGENBUFFERSARBPROC glGenBuffersARB;
			static PFNGLBINDBUFFERARBPROC glBindBufferARB;
			static PFNGLBUFFERDATAARBPROC glBufferDataARB;
			static PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
			static PFNGLMAPBUFFERARBPROC glMapBufferARB;
			static PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
#endif

			/** Constructor. */
			VertexBuffer(IRenderDeviceBase* device);

			/** Destructor. */
			virtual ~VertexBuffer();

			virtual void Create(UInt numberOfVertices, UInt vertexSize);

			virtual void SetData(void* vertices);

			virtual void* Lock();

			virtual void Unlock();

			virtual void Render(PRIMITIVE_TYPE primitiveType, IIndexBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numberOfVertices, UInt primitiveCount);

		private:
			UInt vertexBuffer;
			UInt vertexSize;
			UInt numberOfVertices;
		};
	}
}

#endif