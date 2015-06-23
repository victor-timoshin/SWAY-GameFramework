#ifndef OGL_BUFFER_H
#define OGL_BUFFER_H

#include "../../SDK/Gapi/BufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

#define BUFFER_OFFSET(x)((char*)0L + (x))

namespace Gapi
{
	class OGLBuffer: public IBufferBase
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
		OGLBuffer(IDeviceBase* device);

		/** Destructor. */
		virtual ~OGLBuffer();

		virtual void Create(UInt stride, UInt count);

		virtual void SetData(void* data);

		virtual void* Lock();

		virtual void Unlock();

		virtual void Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBuffer, UInt baseVertexIndex, UInt numberOfVertices, UInt primitiveCount);

		UInt GetBuffer();

		UInt GetComponentCount();

	private:
		UInt bufferId;
		UInt byteStride;
		UInt numComponents;
	};
}

#endif