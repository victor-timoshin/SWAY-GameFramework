#include "../../GapiOpenGL/Inc/IndexBuffer.h"
#include "../../GapiOpenGL/Inc/RenderDevice.h"

namespace Gapi
{
	namespace OpenGL
	{
#ifdef PLATFORM_WINDOWS
		PFNGLGENBUFFERSARBPROC IndexBuffer::glGenBuffersARB = 0L;
		PFNGLBINDBUFFERARBPROC IndexBuffer::glBindBufferARB = 0L;
		PFNGLBUFFERDATAARBPROC IndexBuffer::glBufferDataARB = 0L;
		PFNGLBUFFERSUBDATAARBPROC IndexBuffer::glBufferSubDataARB = 0L;
		PFNGLMAPBUFFERARBPROC IndexBuffer::glMapBufferARB = 0L;
		PFNGLUNMAPBUFFERARBPROC IndexBuffer::glUnmapBufferARB = 0L;
#endif

		/** Constructor. */
		IndexBuffer::IndexBuffer(IRenderDeviceBase* device) : IIndexBufferBase(device)
			, indexBuffer(0)
			, indexSize(0)
			, numberOfIndices(0)
		{
#ifdef PLATFORM_WINDOWS
			LOAD_EXTENSION(PFNGLGENBUFFERSARBPROC, glGenBuffersARB);
			LOAD_EXTENSION(PFNGLBINDBUFFERARBPROC, glBindBufferARB);
			LOAD_EXTENSION(PFNGLBUFFERDATAARBPROC, glBufferDataARB);
			LOAD_EXTENSION(PFNGLBUFFERSUBDATAARBPROC, glBufferSubDataARB);
			LOAD_EXTENSION(PFNGLMAPBUFFERARBPROC, glMapBufferARB);
			LOAD_EXTENSION(PFNGLUNMAPBUFFERARBPROC, glUnmapBufferARB);
#endif
		}

		/** Destructor. */
		IndexBuffer::~IndexBuffer()
		{
		}

		void IndexBuffer::Create(UInt numberOfIndices, UInt indexSize)
		{
			numberOfIndices = numberOfIndices;
			indexSize = indexSize;

			glGenBuffersARB(1, &indexBuffer);
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
			glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, numberOfIndices * indexSize, 0L, GL_STREAM_DRAW_ARB);
		}

		void IndexBuffer::SetData(void* indices)
		{
			glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, numberOfIndices * indexSize, indices);
		}

		void* IndexBuffer::Lock()
		{
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
			return glMapBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
		}

		void IndexBuffer::Unlock()
		{
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer);
			glUnmapBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB);
		}


		UInt IndexBuffer::GetBuffer()
		{
			return indexBuffer;
		}

		UInt IndexBuffer::GetNumberOfIndices()
		{
			return numberOfIndices;
		}
	}

	IIndexBufferBase* RegisterIndexBuffer(IRenderDeviceBase* device)
	{
		return new OpenGL::IndexBuffer(device);
	}
}