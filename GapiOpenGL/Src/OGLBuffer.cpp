#include "../../GapiOpenGL/Inc/OGLBuffer.h"
#include "../../GapiOpenGL/Inc/OGLDevice.h"

namespace Gapi
{
	PFNGLGENBUFFERSARBPROC OGLBuffer::glGenBuffersARB = 0L;
	PFNGLBINDBUFFERARBPROC OGLBuffer::glBindBufferARB = 0L;
	PFNGLBUFFERDATAARBPROC OGLBuffer::glBufferDataARB = 0L;
	PFNGLBUFFERSUBDATAARBPROC OGLBuffer::glBufferSubDataARB = 0L;
	PFNGLMAPBUFFERARBPROC OGLBuffer::glMapBufferARB = 0L;
	PFNGLUNMAPBUFFERARBPROC OGLBuffer::glUnmapBufferARB = 0L;

	/** Constructor. */
	OGLBuffer::OGLBuffer(IDeviceBase* device) : IBufferBase(device)
		, bufferId(0), byteStride(0), numElements(0)
	{
		LOAD_EXTENSION(PFNGLGENBUFFERSARBPROC, glGenBuffersARB);
		LOAD_EXTENSION(PFNGLBINDBUFFERARBPROC, glBindBufferARB);
		LOAD_EXTENSION(PFNGLBUFFERDATAARBPROC, glBufferDataARB);
		LOAD_EXTENSION(PFNGLBUFFERSUBDATAARBPROC, glBufferSubDataARB);
		LOAD_EXTENSION(PFNGLMAPBUFFERARBPROC, glMapBufferARB);
		LOAD_EXTENSION(PFNGLUNMAPBUFFERARBPROC, glUnmapBufferARB);
	}

	/** Destructor. */
	OGLBuffer::~OGLBuffer() {}

	void OGLBuffer::Create(UInt stride, UInt count)
	{
		byteStride = stride;
		numElements = count;

		glGenBuffersARB(1, &bufferId);
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferId);
		glBufferDataARB(GL_ARRAY_BUFFER_ARB, numElements * byteStride, 0L, GL_STREAM_DRAW_ARB);
	}

	void OGLBuffer::SetData(void* sourceData)
	{
		glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, numElements * byteStride, sourceData);
	}

	void* OGLBuffer::Lock()
	{
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferId);
		return glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	}

	void OGLBuffer::Unlock()
	{
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferId);
		glUnmapBufferARB(GL_ARRAY_BUFFER_ARB);
	}

	void OGLBuffer::Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numberOfVertices, UInt primitiveCount)
	{
		OGLBuffer* indexBuffer = static_cast<OGLBuffer*>(indexBufferBase);

		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferId);

		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glColorPointer(4, GL_FLOAT, byteStride, BUFFER_OFFSET(0));
		glVertexPointer(3, GL_FLOAT, byteStride, BUFFER_OFFSET(16));
		//glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(12));

		if (indexBuffer != 0L)
		{
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer->GetBuffer());
			glEnableClientState(GL_INDEX_ARRAY);
			glIndexPointer(GL_UNSIGNED_SHORT, 0, 0);

			glDrawElements(Gapi::OGLDevice::Get(primitiveType), indexBuffer->GetElementCount(), GL_UNSIGNED_SHORT, 0);

			glDisableClientState(GL_INDEX_ARRAY);
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
		}
		else
		{
			glDrawArrays(Gapi::OGLDevice::Get(primitiveType), 0, numberOfVertices);
		}

		//glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);

		glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	}

	UInt OGLBuffer::GetBuffer()
	{
		return bufferId;
	}

	UInt OGLBuffer::GetElementCount()
	{
		return numElements;
	}

	IBufferBase* RegisterBuffer(IDeviceBase* device)
	{
		return new OGLBuffer(device);
	}
}