#include "../../GapiOpenGL/Inc/GpuBuffer.h"
#include "../../GapiOpenGL/Inc/Device.h"

#include <vector>

#define FORMAT_UNDEFINED 0

namespace Gapi
{
	UInt GpuBuffer::GetBufferType(BUFFERTYPES type)
	{
		switch (type)
		{
		case EBT_VERTEX: return GL_ARRAY_BUFFER_ARB;
		case EBT_INDEX: return GL_ELEMENT_ARRAY_BUFFER_ARB;
		}

		return (BUFFERTYPES)-1;
	}

	UInt GpuBuffer::GetBufferUsage(BUFFER_USAGES usage)
	{
		switch (usage)
		{
		case EBU_STATIC: return GL_STATIC_DRAW_ARB;
		case EBU_DYNAMIC: return GL_DYNAMIC_DRAW_ARB;
		}

		return (BUFFER_USAGES)-1;
	}

	UInt GpuBuffer::GetPrimitiveType(PRIMITIVETYPES type)
	{
		switch (type)
		{
		case EPT_POINTLIST: return GL_POINTS;
		case EPT_LINELIST: return GL_LINES;
		case EPT_LINESTRIP: return GL_LINE_STRIP;
		case EPT_TRIANGLELIST: return GL_TRIANGLES;
		case EPT_TRIANGLESTRIP: return GL_TRIANGLE_STRIP;
		}

		return (PRIMITIVETYPES)-1;
	}

	PFNGLGENBUFFERSARBPROC GpuBuffer::glGenBuffersARB = NULL;
	PFNGLBINDBUFFERARBPROC GpuBuffer::glBindBufferARB = NULL;
	PFNGLBUFFERDATAARBPROC GpuBuffer::glBufferDataARB = NULL;
	PFNGLBUFFERSUBDATAARBPROC GpuBuffer::glBufferSubDataARB = NULL;
	PFNGLMAPBUFFERARBPROC GpuBuffer::glMapBufferARB = NULL;
	PFNGLUNMAPBUFFERARBPROC GpuBuffer::glUnmapBufferARB = NULL;
	PFNGLDELETEBUFFERSARBPROC GpuBuffer::glDeleteBuffersARB = NULL;
	PFNGLGETBUFFERPARAMETERIVARBPROC GpuBuffer::glGetBufferParameterivARB = NULL;

	PFNGLGENVERTEXARRAYSPROC GpuBuffer::glGenVertexArraysARB = NULL;
	PFNGLBINDVERTEXARRAYPROC GpuBuffer::glBindVertexArrayARB = NULL;
	PFNGLVERTEXATTRIBPOINTERPROC GpuBuffer::glVertexAttribPointerARB = NULL;
	PFNGLGETATTRIBLOCATIONARBPROC GpuBuffer::glGetAttribLocationARB = NULL;
	PFNGLENABLEVERTEXATTRIBARRAYPROC GpuBuffer::glEnableVertexAttribArrayARB = NULL;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC GpuBuffer::glDisableVertexAttribArrayARB = NULL;

	/// <summary>Конструктор класса.</summary>
	GpuBuffer::GpuBuffer(void)
		: bufferID(0), bufferType(0), byteStride(0), numElements(0)
	{
		LOAD_EXTENSION(PFNGLGENBUFFERSARBPROC, glGenBuffersARB);
		LOAD_EXTENSION(PFNGLBINDBUFFERARBPROC, glBindBufferARB);
		LOAD_EXTENSION(PFNGLBUFFERDATAARBPROC, glBufferDataARB);
		LOAD_EXTENSION(PFNGLBUFFERSUBDATAARBPROC, glBufferSubDataARB);
		LOAD_EXTENSION(PFNGLMAPBUFFERARBPROC, glMapBufferARB);
		LOAD_EXTENSION(PFNGLUNMAPBUFFERARBPROC, glUnmapBufferARB);
		LOAD_EXTENSION(PFNGLDELETEBUFFERSARBPROC, glDeleteBuffersARB);
		LOAD_EXTENSION(PFNGLGETBUFFERPARAMETERIVARBPROC, glGetBufferParameterivARB);

		LOAD_EXTENSION(PFNGLGENVERTEXARRAYSPROC, glGenVertexArraysARB);
		LOAD_EXTENSION(PFNGLBINDVERTEXARRAYPROC, glBindVertexArrayARB);
		LOAD_EXTENSION(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointerARB);
		LOAD_EXTENSION(PFNGLGETATTRIBLOCATIONARBPROC, glGetAttribLocationARB);
		LOAD_EXTENSION(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArrayARB);
		LOAD_EXTENSION(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArrayARB);

		memset(&vertexFormatDesc, 0, sizeof(LVERTEX_FORMAT_DESC));
	}

	/// <summary>Деструктор класса.</summary>
	GpuBuffer::~GpuBuffer(void)
	{
		Destroy();
	}

	/// <summary>Устанавливает декларацию вершин.</summary>
	void GpuBuffer::SetVertexDeclaration(const PVERTEX_ELEMENT_DESC elementDesc, UInt numAttributes)
	{
		std::vector<int> offset(numAttributes, 0);

		for (UInt i = 0; i < numAttributes; ++i)
		{
			int stream = elementDesc[i].stream;

			switch (elementDesc[i].type)
			{
			case VERTEXELEMENTTYPES::EVET_POSITION:
				vertexFormatDesc.position.size = 3;
				vertexFormatDesc.position.offset = offset[stream];
				vertexFormatDesc.position.stream = stream;
				vertexFormatDesc.position.type = elementDesc[i].type;
				vertexFormatDesc.position.format = elementDesc[i].format;

				offset[stream] += 12;
				break;

			case VERTEXELEMENTTYPES::EVET_COLOR:
				vertexFormatDesc.color.size = 4;
				vertexFormatDesc.color.offset = offset[stream];
				vertexFormatDesc.color.stream = stream;
				vertexFormatDesc.color.type = elementDesc[i].type;
				vertexFormatDesc.color.format = elementDesc[i].format;

				offset[stream] += 16;
				break;

			case VERTEXELEMENTTYPES::EVET_TEXCOORD:
				vertexFormatDesc.texCoord.size = 2;
				vertexFormatDesc.texCoord.offset = offset[stream];
				vertexFormatDesc.texCoord.stream = stream;
				vertexFormatDesc.texCoord.type = elementDesc[i].type;
				vertexFormatDesc.texCoord.format = elementDesc[i].format;

				offset[stream] += 8;
				break;

			case VERTEXELEMENTTYPES::EVET_NORMAL:
				vertexFormatDesc.normal.size = 3;
				vertexFormatDesc.normal.offset = offset[stream];
				vertexFormatDesc.normal.stream = stream;
				vertexFormatDesc.normal.type = elementDesc[i].type;
				vertexFormatDesc.normal.format = elementDesc[i].format;

				offset[stream] += 12;
				break;

			case VERTEXELEMENTTYPES::EVET_TANGENT:
				vertexFormatDesc.tangent.size = 3;
				vertexFormatDesc.tangent.offset = offset[stream];
				vertexFormatDesc.tangent.stream = stream;
				vertexFormatDesc.tangent.type = elementDesc[i].type;
				vertexFormatDesc.tangent.format = elementDesc[i].format;

				offset[stream] += 12;
				break;

			case VERTEXELEMENTTYPES::EVET_BITANGENT:
				vertexFormatDesc.bitangent.size = 3;
				vertexFormatDesc.bitangent.offset = offset[stream];
				vertexFormatDesc.bitangent.stream = stream;
				vertexFormatDesc.bitangent.type = elementDesc[i].type;
				vertexFormatDesc.bitangent.format = elementDesc[i].format;

				offset[stream] += 12;
				break;

			default:
				break;
			}
		}
	}

	UInt GpuBuffer::CreateArray(BUFFERTYPES type, UInt stride, UInt count, BUFFER_USAGES usage)
	{
		bufferType = GpuBuffer::GetBufferType(type);

		byteStride = stride;
		numElements = count;

		UInt dataSize = numElements * byteStride;

		glGenVertexArraysARB(1, &bufferID);
		CHECK_GLERROR();
		glGenBuffersARB(1, &bufferID);
		CHECK_GLERROR();
		glBindVertexArrayARB(bufferID);
		CHECK_GLERROR();
		glBindBufferARB(bufferType, bufferID);
		CHECK_GLERROR();
		glBufferDataARB(bufferType, dataSize, NULL, GpuBuffer::GetBufferUsage(usage));
		CHECK_GLERROR();

		return bufferID;
	}

	UInt GpuBuffer::Create(BUFFERTYPES type, UInt stride, UInt count, BUFFER_USAGES usage)
	{
		bufferType = GpuBuffer::GetBufferType(type);

		byteStride = stride;
		numElements = count;

		UInt dataSize = numElements * byteStride;

		glGenBuffersARB(1, &bufferID);
		CHECK_GLERROR();
		glBindBufferARB(bufferType, bufferID);
		CHECK_GLERROR();
		glBufferDataARB(bufferType, dataSize, NULL, GpuBuffer::GetBufferUsage(usage));
		CHECK_GLERROR();

		int bufferSize = 0;
		glGetBufferParameterivARB(bufferType, GL_BUFFER_SIZE_ARB, &bufferSize);
		if (dataSize != bufferSize)
		{
			glDeleteBuffersARB(1, &bufferID);
			bufferID = 0;
		}

		CHECK_GLERROR();

		return bufferID;
	}

	void GpuBuffer::Destroy(void)
	{
		glDeleteBuffersARB(1, &bufferID);
	}

	void GpuBuffer::SetData(void* source)
	{
		if (bufferID)
		{
			glBindBufferARB(bufferType, bufferID);
			glBufferSubDataARB(bufferType, 0/*offset*/, numElements * byteStride, source);
			glBindBufferARB(bufferType, 0);

			CHECK_GLERROR();
		}
	}

	void* GpuBuffer::Lock(void)
	{
		void* buffer = 0;
		if (bufferID)
		{
			glBindBufferARB(bufferType, bufferID);
			buffer = glMapBufferARB(bufferType, /*GL_READ_WRITE*/GL_WRITE_ONLY_ARB);
			glBindBufferARB(bufferType, 0);

			CHECK_GLERROR();
		}

		return buffer;
	}

	void GpuBuffer::Unlock(void)
	{
		if (bufferID)
		{
			glBindBufferARB(bufferType, bufferID);
			glUnmapBufferARB(bufferType);
			glBindBufferARB(bufferType, 0);

			CHECK_GLERROR();
		}
	}

	void GpuBuffer::BindVertexArray(void)
	{
		glBindVertexArrayARB(bufferType);
	}

	void GpuBuffer::UnbindVertexArray(void)
	{
		glBindVertexArrayARB(0);
	}

	void GpuBuffer::RenderW(PRIMITIVETYPES primitiveType, IBufferBase* indexBufferBase, UInt numVertices, UInt shaderProgram)
	{
		if (vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
		{
			GLint texCoord = glGetAttribLocationARB(shaderProgram, "texCoord");

			glEnableVertexAttribArrayARB(texCoord);
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferID);
			glVertexAttribPointerARB(texCoord, vertexFormatDesc.texCoord.size, GL_FLOAT, GL_FALSE, byteStride, BUFFER_OFFSET(vertexFormatDesc.texCoord.offset));

			CHECK_GLERROR();
		}

		if (vertexFormatDesc.position.size != FORMAT_UNDEFINED)
		{
			GLint vertex = glGetAttribLocationARB(shaderProgram, "position");

			glEnableVertexAttribArrayARB(vertex);
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferID);
			glVertexAttribPointerARB(vertex, vertexFormatDesc.position.size, GL_FLOAT, GL_FALSE, byteStride, BUFFER_OFFSET(vertexFormatDesc.position.offset));

			CHECK_GLERROR();
		}

		glDrawArrays(GpuBuffer::GetPrimitiveType(primitiveType), 0, numVertices);

		if (vertexFormatDesc.position.size != FORMAT_UNDEFINED)
			glDisableVertexAttribArrayARB(0);

		if (vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
			glDisableVertexAttribArrayARB(1);
	}

	void GpuBuffer::Render(PRIMITIVETYPES primitiveType, IBufferBase* indexBufferBase, UInt numVertices, UInt primitiveCount)
	{
		GpuBuffer* indexBuffer = static_cast<GpuBuffer*>(indexBufferBase);

		if (vertexFormatDesc.bitangent.size != FORMAT_UNDEFINED)
		{
		}

		if (vertexFormatDesc.tangent.size != FORMAT_UNDEFINED)
		{
		}

		if (vertexFormatDesc.normal.size != FORMAT_UNDEFINED)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferID);
			glNormalPointer(GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.normal.offset));

			CHECK_GLERROR();
		}

		if (vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferID);
			glTexCoordPointer(vertexFormatDesc.texCoord.size, GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.texCoord.offset));

			CHECK_GLERROR();
		}

		if (vertexFormatDesc.color.size != FORMAT_UNDEFINED)
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferID);
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(vertexFormatDesc.color.size, GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.color.offset));

			CHECK_GLERROR();
		}

		if (vertexFormatDesc.position.size != FORMAT_UNDEFINED)
		{
			glBindBufferARB(GL_ARRAY_BUFFER_ARB, bufferID);
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(vertexFormatDesc.position.size, GL_FLOAT, byteStride, BUFFER_OFFSET(vertexFormatDesc.position.offset));

			CHECK_GLERROR();
		}

		if (indexBuffer != NULL)
		{
			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer->GetID());
			CHECK_GLERROR();

			glDrawElements(GpuBuffer::GetPrimitiveType(primitiveType), indexBuffer->GetElementCount(), GL_UNSIGNED_BYTE, 0/*offset*/);
			CHECK_GLERROR();

			glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, 0);
			CHECK_GLERROR();
		}
		else
		{
			glDrawArrays(GpuBuffer::GetPrimitiveType(primitiveType), 0, numVertices);
		}

		if (vertexFormatDesc.position.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_VERTEX_ARRAY);

		if (vertexFormatDesc.color.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_COLOR_ARRAY);

		if (vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		if (vertexFormatDesc.normal.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_NORMAL_ARRAY);

		glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	}

	UInt GpuBuffer::GetID(void)
	{
		return bufferID;
	}

	UInt GpuBuffer::GetElementCount(void)
	{
		return numElements;
	}

	IBufferBase* RegisterBuffer(void)
	{
		return new GpuBuffer();
	}
}