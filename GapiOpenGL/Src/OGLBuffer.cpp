#include "../../GapiOpenGL/Inc/OGLBuffer.h"
#include "../../GapiOpenGL/Inc/OGLDevice.h"

#include <vector>

#define FORMAT_UNDEFINED 0

namespace Gapi
{
	PFNGLGENBUFFERSARBPROC OGLBuffer::glGenBuffersARB = 0L;
	PFNGLBINDBUFFERARBPROC OGLBuffer::glBindBufferARB = 0L;
	PFNGLBUFFERDATAARBPROC OGLBuffer::glBufferDataARB = 0L;
	PFNGLBUFFERSUBDATAARBPROC OGLBuffer::glBufferSubDataARB = 0L;
	PFNGLMAPBUFFERARBPROC OGLBuffer::glMapBufferARB = 0L;
	PFNGLUNMAPBUFFERARBPROC OGLBuffer::glUnmapBufferARB = 0L;
	PFNGLDELETEBUFFERSARBPROC OGLBuffer::glDeleteBuffersARB = 0L;
	PFNGLGETBUFFERPARAMETERIVARBPROC OGLBuffer::glGetBufferParameterivARB = 0L;

	/** Constructor. */
	OGLBuffer::OGLBuffer(IDeviceBase* device) : IBufferBase(device)
		, bufferIdx(0), byteStride(0), numElements(0)
	{
		LOAD_EXTENSION(PFNGLGENBUFFERSARBPROC, glGenBuffersARB);
		LOAD_EXTENSION(PFNGLBINDBUFFERARBPROC, glBindBufferARB);
		LOAD_EXTENSION(PFNGLBUFFERDATAARBPROC, glBufferDataARB);
		LOAD_EXTENSION(PFNGLBUFFERSUBDATAARBPROC, glBufferSubDataARB);
		LOAD_EXTENSION(PFNGLMAPBUFFERARBPROC, glMapBufferARB);
		LOAD_EXTENSION(PFNGLUNMAPBUFFERARBPROC, glUnmapBufferARB);
		LOAD_EXTENSION(PFNGLDELETEBUFFERSARBPROC, glDeleteBuffersARB);
		LOAD_EXTENSION(PFNGLGETBUFFERPARAMETERIVARBPROC, glGetBufferParameterivARB);

		memset(&vertexFormatDesc, 0, sizeof(LVERTEX_FORMAT_DESC));
	}

	/** Destructor. */
	OGLBuffer::~OGLBuffer() {
		glDeleteBuffersARB(1, &bufferIdx);
	}

	void OGLBuffer::SetVertexDeclaration(const PVERTEX_ELEMENT_DESC elementDesc, UInt numAttributes)
	{
		std::vector<int> offset(numAttributes, 0);

		for (UInt i = 0; i < numAttributes; ++i)
		{
			int stream = elementDesc[i].stream;

			switch (elementDesc[i].type)
			{
			case VertexElementType::TYPE_POSITION:
				vertexFormatDesc.position.size = 3;
				vertexFormatDesc.position.offset = offset[stream];
				vertexFormatDesc.position.stream = stream;
				vertexFormatDesc.position.type = elementDesc[i].type;
				vertexFormatDesc.position.format = elementDesc[i].format;

				offset[stream] += 12;
				break;

			case VertexElementType::TYPE_COLOR:
				vertexFormatDesc.color.size = 4;
				vertexFormatDesc.color.offset = offset[stream];
				vertexFormatDesc.color.stream = stream;
				vertexFormatDesc.color.type = elementDesc[i].type;
				vertexFormatDesc.color.format = elementDesc[i].format;

				offset[stream] += 16;
				break;

			case VertexElementType::TYPE_TEXCOORD:
				vertexFormatDesc.texCoord.size = 2;
				vertexFormatDesc.texCoord.offset = offset[stream];
				vertexFormatDesc.texCoord.stream = stream;
				vertexFormatDesc.texCoord.type = elementDesc[i].type;
				vertexFormatDesc.texCoord.format = elementDesc[i].format;

				offset[stream] += 8;
				break;

			case VertexElementType::TYPE_NORMAL:
				vertexFormatDesc.normal.size = 3;
				vertexFormatDesc.normal.offset = offset[stream];
				vertexFormatDesc.normal.stream = stream;
				vertexFormatDesc.normal.type = elementDesc[i].type;
				vertexFormatDesc.normal.format = elementDesc[i].format;

				offset[stream] += 12;
				break;

			default:
				break;
			}
		}
	}

	UInt OGLBuffer::Create(UInt stride, UInt count)
	{
		byteStride = stride;
		numElements = count;

		UInt dataSize = numElements * byteStride;

		glGenBuffersARB(1, &bufferIdx);
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
		glBufferDataARB(GL_ARRAY_BUFFER_ARB, dataSize, 0L, GL_STREAM_DRAW_ARB);

		int bufferSize = 0;
		glGetBufferParameterivARB(GL_ARRAY_BUFFER_ARB, GL_BUFFER_SIZE_ARB, &bufferSize);
		if (dataSize != bufferSize)
		{
			glDeleteBuffersARB(1, &bufferIdx);
			bufferIdx = 0;
		}

		return bufferIdx;
	}

	void OGLBuffer::SetData(void* sourceData)
	{
		glBufferSubDataARB(GL_ARRAY_BUFFER_ARB, 0, numElements * byteStride, sourceData);
	}

	void* OGLBuffer::Lock()
	{
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
		return glMapBufferARB(GL_ARRAY_BUFFER_ARB, GL_WRITE_ONLY_ARB);
	}

	void OGLBuffer::Unlock()
	{
		glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
		glUnmapBufferARB(GL_ARRAY_BUFFER_ARB);
	}

	void OGLBuffer::Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numVertices, UInt primitiveCount)
	{
		OGLBuffer* indexBuffer = static_cast<OGLBuffer*>(indexBufferBase);

		if (vertexFormatDesc.position.size != FORMAT_UNDEFINED)
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(vertexFormatDesc.position.size, GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.position.offset));
		}

		if (vertexFormatDesc.color.size != FORMAT_UNDEFINED)
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(vertexFormatDesc.color.size, GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.color.offset));
		}

		if (vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(vertexFormatDesc.texCoord.size, GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.texCoord.offset));
		}

		if (vertexFormatDesc.normal.size != FORMAT_UNDEFINED)
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferIdx);
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.normal.offset));
		}

		if (indexBuffer != 0L)
		{
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer->GetIndexBuffer());
			glEnableClientState(GL_INDEX_ARRAY);
			glIndexPointer(GL_UNSIGNED_SHORT, 0, 0);

			glDrawElements(Gapi::OGLDevice::Get(primitiveType), indexBuffer->GetElementCount(), GL_UNSIGNED_SHORT, 0);

			glDisableClientState(GL_INDEX_ARRAY);
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
		}
		else
		{
			glDrawArrays(Gapi::OGLDevice::Get(primitiveType), 0, numVertices);
		}

		if (vertexFormatDesc.normal.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_NORMAL_ARRAY);

		if (vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		if (vertexFormatDesc.color.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_COLOR_ARRAY);

		if (vertexFormatDesc.position.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_VERTEX_ARRAY);

		glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	}

	UInt OGLBuffer::GetIndexBuffer()
	{
		return bufferIdx;
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