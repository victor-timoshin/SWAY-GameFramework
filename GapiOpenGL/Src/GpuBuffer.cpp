#include "../../GapiOpenGL/Inc/GpuBuffer.h"
#include "../../GapiOpenGL/Inc/Device.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

#include <vector>

#define FORMAT_UNDEFINED 0

namespace Gapi
{
	UInt GpuBuffer::GetBufferType(BUFFER_TYPE type)
	{
		switch (type)
		{
		case ByfferType::Vertex: return GL_ARRAY_BUFFER_ARB;
		case ByfferType::Index:  return GL_ELEMENT_ARRAY_BUFFER_ARB;
		default:
			break;
		}
	}

	UInt GpuBuffer::GetBufferUsage(BUFFER_USAGE usage)
	{
		switch (usage)
		{
		case BUFFER_USAGE::Static:  return GL_STATIC_DRAW_ARB;
		case BUFFER_USAGE::Dynamic: return GL_DYNAMIC_DRAW_ARB;
		case BUFFER_USAGE::Stream:  return GL_STREAM_DRAW_ARB;
		default:
			break;
		}
	}

	UInt GpuBuffer::GetPrimitiveType(PRIMITIVE_TYPE type)
	{
		switch (type)
		{
		case PRIMITIVE_TYPE::PointList:     return GL_POINTS;
		case PRIMITIVE_TYPE::LineList:      return GL_LINES;
		case PRIMITIVE_TYPE::LineStrip:     return GL_LINE_STRIP;
		case PRIMITIVE_TYPE::TriangleList:  return GL_TRIANGLES;
		case PRIMITIVE_TYPE::TriangleStrip: return GL_TRIANGLE_STRIP;
		default:
			break;
		}
	}

	/// <summary>Конструктор класса.</summary>
	GpuBuffer::GpuBuffer(void)
		: _bufferID(0)
		, _bufferArrayID(0)
		, _byteStride(0)
		, _numElements(0)
	{
		memset(&_vertexFormatDesc, 0, sizeof(LVERTEX_FORMAT_DESC));
	}

	/// <summary>Деструктор класса.</summary>
	GpuBuffer::~GpuBuffer(void)
	{
		Destroy();
	}

	/// <summary>Устанавливает декларацию вершин.</summary>
	void GpuBuffer::SetVertexDeclaration(const std::vector<LVERTEX_ELEMENT_DESC>& elements)
	{
		std::vector<int> offset(elements.size(), 0);
		int stream = 0;

		for (UInt i = 0; i < elements.size(); ++i)
		{
			int stream = elements[i].stream;
			Gapi::VERTEX_ELEMENT_TYPE type = elements[i].type;
			Gapi::VERTEX_ELEMENT_FORMAT format = elements[i].format;

			switch (type)
			{
			case VERTEX_ELEMENT_TYPE::Position:
				_vertexFormatDesc.position.size = 3;
				_vertexFormatDesc.position.offset = offset[stream];
				_vertexFormatDesc.position.stream = stream;
				_vertexFormatDesc.position.type = type;
				_vertexFormatDesc.position.format = format;

				offset[stream] += 12;
				break;

			case VERTEX_ELEMENT_TYPE::Color:
				_vertexFormatDesc.color.size = 4;
				_vertexFormatDesc.color.offset = offset[stream];
				_vertexFormatDesc.color.stream = stream;
				_vertexFormatDesc.color.type = type;
				_vertexFormatDesc.color.format = format;

				offset[stream] += 16;
				break;

			case VERTEX_ELEMENT_TYPE::TexCoord:
				_vertexFormatDesc.texCoord.size = 2;
				_vertexFormatDesc.texCoord.offset = offset[stream];
				_vertexFormatDesc.texCoord.stream = stream;
				_vertexFormatDesc.texCoord.type = type;
				_vertexFormatDesc.texCoord.format = format;

				offset[stream] += 8;
				break;

			case VERTEX_ELEMENT_TYPE::Normal:
				_vertexFormatDesc.normal.size = 3;
				_vertexFormatDesc.normal.offset = offset[stream];
				_vertexFormatDesc.normal.stream = stream;
				_vertexFormatDesc.normal.type = type;
				_vertexFormatDesc.normal.format = format;

				offset[stream] += 12;
				break;

			case VERTEX_ELEMENT_TYPE::Tangent:
				_vertexFormatDesc.tangent.size = 3;
				_vertexFormatDesc.tangent.offset = offset[stream];
				_vertexFormatDesc.tangent.stream = stream;
				_vertexFormatDesc.tangent.type = type;
				_vertexFormatDesc.tangent.format = format;

				offset[stream] += 12;
				break;

			case VERTEX_ELEMENT_TYPE::Bitangent:
				_vertexFormatDesc.bitangent.size = 3;
				_vertexFormatDesc.bitangent.offset = offset[stream];
				_vertexFormatDesc.bitangent.stream = stream;
				_vertexFormatDesc.bitangent.type = type;
				_vertexFormatDesc.bitangent.format = format;

				offset[stream] += 12;
				break;

			default:
				break;
			}
		}
	}

	void GpuBuffer::CreateArray(BUFFER_TYPE type, UInt stride, UInt count, BUFFER_USAGE usage)
	{
		_bufferTarget = GpuBuffer::GetBufferType(type);

		_byteStride = stride;
		_numElements = count;

		UInt dataSize = _numElements * _byteStride;

		GL_ARB_VertexArrayObject::GenerateVertexArrays(1, &_bufferArrayID, SOURCE_LOCATION);
		GL_ARB_VertexArrayObject::BindVertexArray(_bufferArrayID, SOURCE_LOCATION);

		GL_ARB_VertexBufferObject::GenerateBuffers(1, &_bufferID, SOURCE_LOCATION);

		GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);
		GL_ARB_VertexBufferObject::BufferData(_bufferTarget, dataSize, nullptr, GpuBuffer::GetBufferUsage(usage), SOURCE_LOCATION);
	}

	void GpuBuffer::Create(BUFFER_TYPE type, UInt stride, UInt count, BUFFER_USAGE usage)
	{
		_bufferTarget = GpuBuffer::GetBufferType(type);

		_byteStride = stride;
		_numElements = count;

		UInt dataSize = _numElements * _byteStride;

		GL_ARB_VertexBufferObject::GenerateBuffers(1, &_bufferID, SOURCE_LOCATION);

		GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);

		GL_ARB_VertexBufferObject::BufferData(_bufferTarget, dataSize, nullptr, GpuBuffer::GetBufferUsage(usage), SOURCE_LOCATION);

		int bufferSize = 0;
		GL_ARB_VertexBufferObject::GetBufferParameterI(_bufferTarget, GL_BUFFER_SIZE_ARB, &bufferSize, SOURCE_LOCATION);
		if (dataSize != bufferSize)
		{
			GL_ARB_VertexBufferObject::DeleteBuffers(1, &_bufferID);
			_bufferID = 0;
		}
	}

	void GpuBuffer::Destroy(void)
	{
		if (_bufferID != 0)
			GL_ARB_VertexBufferObject::DeleteBuffers(1, &_bufferID);

		if (_bufferArrayID != 0)
			GL_ARB_VertexArrayObject::DeleteVertexArrays(1, &_bufferArrayID);
	}

	void GpuBuffer::SetData(void* source)
	{
		if (_bufferID != 0)
		{
			GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::BufferSubData(_bufferTarget, 0, _numElements * _byteStride, source, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::UnbindBuffer(_bufferTarget, SOURCE_LOCATION);
		}
	}

	void* GpuBuffer::Map(void)
	{
		void* mappedBuffer = nullptr;
		if (_bufferID != 0)
		{
			GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);
			mappedBuffer = GL_ARB_VertexBufferObject::MapBuffer(_bufferTarget, /*GL_READ_WRITE*/GL_WRITE_ONLY_ARB, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::UnbindBuffer(_bufferTarget, SOURCE_LOCATION);
		}

		return mappedBuffer;
	}

	void* GpuBuffer::MapRange(int offset, int length)
	{
		void* mappedBuffer = nullptr;
		if (_bufferID != 0)
		{
			GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);
			mappedBuffer = GL_ARB_MapBufferRange::MapBufferRange(_bufferTarget, offset, length, GL_MAP_WRITE_BIT | GL_MAP_UNSYNCHRONIZED_BIT, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::UnbindBuffer(_bufferTarget, SOURCE_LOCATION);
		}

		return mappedBuffer;
	}

	void GpuBuffer::Unmap(void)
	{
		if (_bufferID != 0)
		{
			GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::UnmapBuffer(_bufferTarget, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::UnbindBuffer(_bufferTarget, SOURCE_LOCATION);
		}
	}

	void GpuBuffer::BindVertexArray()
	{
		GL_ARB_VertexArrayObject::BindVertexArray(_bufferArrayID, SOURCE_LOCATION);
	}
	void GpuBuffer::UnbindVertexArray()
	{
		GL_ARB_VertexArrayObject::UnbindVertexArray(SOURCE_LOCATION);
	}

	void GpuBuffer::RenderW(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt first, UInt numVertices, UInt shaderProgram)
	{
		if (_vertexFormatDesc.position.size != FORMAT_UNDEFINED)
		{
			int vertex = 0;// GL_ARB_VertexShader::GetAttributeLocation(shaderProgram, "position", SOURCE_LOCATION);

			//GL_ARB_VertexShader::BindAttributeLocation(shaderProgram, 0, "position", SOURCE_LOCATION);
			GL_ARB_VertexProgram::EnableVertexAttributeArray(vertex, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::BindBuffer(GL_ARRAY_BUFFER_ARB, _bufferID, SOURCE_LOCATION);
			GL_ARB_VertexProgram::VertexAttributePointer(vertex, _vertexFormatDesc.position.size, GL_FLOAT, GL_FALSE, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.position.offset), SOURCE_LOCATION);
		}

		if (_vertexFormatDesc.color.size != FORMAT_UNDEFINED)
		{
			int vertex = 1;// GL_ARB_VertexShader::GetAttributeLocation(shaderProgram, "textColor", SOURCE_LOCATION);

			GL_ARB_VertexProgram::EnableVertexAttributeArray(vertex, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::BindBuffer(GL_ARRAY_BUFFER_ARB, _bufferID, SOURCE_LOCATION);
			GL_ARB_VertexProgram::VertexAttributePointer(vertex, _vertexFormatDesc.color.size, GL_FLOAT, GL_FALSE, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.color.offset), SOURCE_LOCATION);
		}

		if (_vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
		{
			int texCoord = GL_ARB_VertexShader::GetAttributeLocation(shaderProgram, "texCoord", SOURCE_LOCATION);

			GL_ARB_VertexProgram::EnableVertexAttributeArray(texCoord, SOURCE_LOCATION);
			GL_ARB_VertexBufferObject::BindBuffer(GL_ARRAY_BUFFER_ARB, _bufferID, SOURCE_LOCATION);
			GL_ARB_VertexProgram::VertexAttributePointer(texCoord, _vertexFormatDesc.texCoord.size, GL_FLOAT, GL_FALSE, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.texCoord.offset), SOURCE_LOCATION);
		}

		//GL_ARB_VertexArrayObject::BindVertexArray(_bufferArrayID, SOURCE_LOCATION);

		glDrawArrays(GpuBuffer::GetPrimitiveType(primitiveType), first, numVertices);

		//GL_ARB_VertexArrayObject::UnbindVertexArray(SOURCE_LOCATION);

		if (_vertexFormatDesc.position.size != FORMAT_UNDEFINED)
			GL_ARB_VertexProgram::DisableVertexAttributeArray(0, SOURCE_LOCATION);

		if (_vertexFormatDesc.color.size != FORMAT_UNDEFINED)
			GL_ARB_VertexProgram::DisableVertexAttributeArray(1, SOURCE_LOCATION);

		if (_vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
			GL_ARB_VertexProgram::DisableVertexAttributeArray(2, SOURCE_LOCATION);
	}

	void GpuBuffer::Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt numVertices, UInt primitiveCount, UInt shaderProgram)
	{
		GpuBuffer* indexBuffer = static_cast<GpuBuffer*>(indexBufferBase);

		//if (vertexFormatDesc.bitangent.size != FORMAT_UNDEFINED)
		//{
		//}

		//if (vertexFormatDesc.tangent.size != FORMAT_UNDEFINED)
		//{
		//}

		GL_ARB_VertexBufferObject::BindBuffer(_bufferTarget, _bufferID, SOURCE_LOCATION);

		if (_vertexFormatDesc.position.size != FORMAT_UNDEFINED)
		{
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(_vertexFormatDesc.position.size, GL_FLOAT, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.position.offset));
			CHECK_OPENGL_ERROR(SOURCE_LOCATION);
		}

		if (_vertexFormatDesc.color.size != FORMAT_UNDEFINED)
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(_vertexFormatDesc.color.size, GL_FLOAT, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.color.offset));
			CHECK_OPENGL_ERROR(SOURCE_LOCATION);
		}

		if (_vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
		{
			GL_ARB_Multitexture::ClientActiveTexture(GL_TEXTURE0_ARB, SOURCE_LOCATION);
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(_vertexFormatDesc.texCoord.size, GL_FLOAT, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.texCoord.offset));
		
			CHECK_OPENGL_ERROR(SOURCE_LOCATION);
		}

		if (_vertexFormatDesc.normal.size != FORMAT_UNDEFINED)
		{
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_FLOAT, _byteStride, BUFFER_OFFSET(_vertexFormatDesc.normal.offset));

			CHECK_OPENGL_ERROR(SOURCE_LOCATION);
		}

		if (indexBuffer != nullptr)
		{
			GL_ARB_VertexBufferObject::BindBuffer(GL_ELEMENT_ARRAY_BUFFER_ARB, indexBuffer->GetID(), SOURCE_LOCATION);

			glDrawElements(GpuBuffer::GetPrimitiveType(primitiveType), 36/*indexBuffer->GetElementCount()*/, GL_UNSIGNED_BYTE, 0/*offset*/);
			CHECK_OPENGL_ERROR(SOURCE_LOCATION);

			GL_ARB_VertexBufferObject::UnbindBuffer(GL_ELEMENT_ARRAY_BUFFER_ARB, SOURCE_LOCATION);
		}
		else
		{
			glDrawArrays(GpuBuffer::GetPrimitiveType(primitiveType), 0, numVertices);
		}

		if (_vertexFormatDesc.position.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_VERTEX_ARRAY);

		if (_vertexFormatDesc.color.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_COLOR_ARRAY);

		if (_vertexFormatDesc.texCoord.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		if (_vertexFormatDesc.normal.size != FORMAT_UNDEFINED)
			glDisableClientState(GL_NORMAL_ARRAY);

		GL_ARB_VertexBufferObject::UnbindBuffer(GL_ARRAY_BUFFER_ARB, SOURCE_LOCATION);
	}

	UInt GpuBuffer::GetID(void)
	{
		return _bufferID;
	}

	UInt GpuBuffer::GetElementCount(void)
	{
		return _numElements;
	}

	void GpuBuffer::SetByteStride(UInt stride)
	{
		_byteStride = stride;
	}

	UInt GpuBuffer::GetByteStride(void) const
	{
		return _byteStride;
	}

	IBufferBase* RegisterBuffer(void)
	{
		return new GpuBuffer();
	}
}