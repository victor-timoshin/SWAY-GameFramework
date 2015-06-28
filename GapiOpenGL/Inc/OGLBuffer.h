#ifndef OGL_BUFFER_H
#define OGL_BUFFER_H

#include "../../SDK/Gapi/BufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

#define BUFFER_OFFSET(x)((char*)0L + (x))

namespace Gapi
{
	class OGLBuffer : public IBufferBase
	{
	public:
		static PFNGLGENBUFFERSARBPROC glGenBuffersARB;
		static PFNGLBINDBUFFERARBPROC glBindBufferARB;
		static PFNGLBUFFERDATAARBPROC glBufferDataARB;
		static PFNGLBUFFERSUBDATAARBPROC glBufferSubDataARB;
		static PFNGLMAPBUFFERARBPROC glMapBufferARB;
		static PFNGLUNMAPBUFFERARBPROC glUnmapBufferARB;
		static PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;
		static PFNGLGETBUFFERPARAMETERIVARBPROC glGetBufferParameterivARB;

		/** Constructor. */
		OGLBuffer(IDeviceBase* device);

		/** Destructor. */
		virtual ~OGLBuffer();

		virtual void SetVertexDeclaration(const PVERTEX_ELEMENT_DESC elementDesc, UInt numElements);

		virtual UInt Create(UInt stride, UInt count);

		virtual void SetData(void* sourceData);

		virtual void* Lock();

		virtual void Unlock();

		virtual void Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBuffer, UInt baseVertexIndex, UInt numVertices, UInt primitiveCount);

		UInt GetIndexBuffer();

		UInt GetElementCount();

	private:
		UInt bufferIdx;
		LVERTEX_FORMAT_DESC vertexFormatDesc;
		UInt byteStride;
		UInt numElements;
	};
}

#endif // OGL_BUFFER_H