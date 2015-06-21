#include "../../GapiOpenGL/Inc/VertexBuffer.h"
#include "../../GapiOpenGL/Inc/IndexBuffer.h"
#include "../../GapiOpenGL/Inc/RenderDevice.h"

namespace Gapi
{
	namespace OpenGL
	{
#ifdef PLATFORM_WINDOWS
		PFNGLGENBUFFERSARBPROC VertexBuffer::glGenBuffersARB = 0L;
		PFNGLBINDBUFFERARBPROC VertexBuffer::glBindBufferARB = 0L;
		PFNGLBUFFERDATAARBPROC VertexBuffer::glBufferDataARB = 0L;
		PFNGLBUFFERSUBDATAARBPROC VertexBuffer::glBufferSubDataARB = 0L;
		PFNGLMAPBUFFERARBPROC VertexBuffer::glMapBufferARB = 0L;
		PFNGLUNMAPBUFFERARBPROC VertexBuffer::glUnmapBufferARB = 0L;
#endif

		/** Constructor. */
		VertexBuffer::VertexBuffer(IRenderDeviceBase* device) : IVertexBufferBase(device)
			, vertexBuffer(0)
			, vertexSize(0)
			, numberOfVertices(0)
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
		VertexBuffer::~VertexBuffer()
		{
		}

		void VertexBuffer::Create(UInt numberOfVertices, UInt vertexSize)
		{
			numberOfVertices = numberOfVertices;
			vertexSize = vertexSize;

			glGenBuffersARB(1, &vertexBuffer);
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertexBuffer);
			glBufferDataARB(GL_ARRAY_BUFFER_ARB, numberOfVertices * vertexSize, 0L, GL_STREAM_DRAW_ARB);
		}

		void VertexBuffer::SetData(void* vertices)
		{
			glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, numberOfVertices * vertexSize, vertices);
		}

		void* VertexBuffer::Lock()
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertexBuffer);
			return glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
		}

		void VertexBuffer::Unlock()
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertexBuffer);
			glUnmapBufferARB(GL_ARRAY_BUFFER_ARB);
		}

		void VertexBuffer::Render(PRIMITIVE_TYPE primitiveType, IIndexBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numberOfVertices, UInt primitiveCount)
		{
			IndexBuffer* indexBuffer = static_cast<IndexBuffer*>(indexBufferBase);

			glBindBufferARB(GL_ARRAY_BUFFER_ARB, vertexBuffer);

			glEnableClientState(GL_VERTEX_ARRAY);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);

			glVertexPointer(3, GL_FLOAT, vertexSize, BUFFER_OFFSET(0));
			glTexCoordPointer(2, GL_FLOAT, 0, BUFFER_OFFSET(12));

			if (indexBuffer != 0L)
			{
				glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer->GetBuffer());
				glEnableClientState(GL_INDEX_ARRAY);
				glIndexPointer(GL_UNSIGNED_SHORT, 0, 0);

				glDrawElements(Gapi::OpenGL::RenderDevice::Get(primitiveType), indexBuffer->GetNumberOfIndices(), GL_UNSIGNED_SHORT, 0);

				glDisableClientState(GL_INDEX_ARRAY);
				glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
			}
			else
			{
				glDrawArrays(Gapi::OpenGL::RenderDevice::Get(primitiveType), 0, numberOfVertices);
			}

			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			glDisableClientState(GL_VERTEX_ARRAY);

			glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
		}
	}

	IVertexBufferBase* RegisterVertexBuffer(IRenderDeviceBase* device)
	{
		return new OpenGL::VertexBuffer(device);
	}
}