#ifndef GPUBUFFER_H
#define GPUBUFFER_H

#include "../../SDK/Gapi/BufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

#define BUFFER_OFFSET(x)((char*)0L + (x))

namespace Gapi
{
	class GpuBuffer : public IBufferBase
	{
	public:
		static UInt GetBufferType(BUFFER_TYPE type);
		static UInt GetBufferUsage(BUFFER_USAGE usage);
		static UInt GetPrimitiveType(PRIMITIVE_TYPE type);

		/// <summary>Конструктор класса.</summary>
		GpuBuffer(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~GpuBuffer(void);

		/// <summary>Устанавливает декларацию вершин.</summary>
		virtual void SetVertexDeclaration(const std::vector<LVERTEX_ELEMENT_DESC>& elements);

		virtual void CreateArray(BUFFER_TYPE type, UInt stride, UInt count, BUFFER_USAGE usage);

		virtual void Create(BUFFER_TYPE type, UInt stride, UInt count, BUFFER_USAGE usage);

		virtual void Destroy(void);

		virtual void SetData(void* source);

		virtual void* Map(void);

		virtual void* MapRange(int offset, int length);

		virtual void Unmap(void);

		virtual void BindVertexArray();
		virtual void UnbindVertexArray();
		virtual void RenderW(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt first, UInt numVertices, UInt primitiveCount);

		virtual void Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBuffer, UInt numVertices, UInt primitiveCount, UInt shaderProgram);

		virtual UInt GetID(void);

		virtual void SetByteStride(UInt stride);

		virtual UInt GetByteStride(void) const;

		UInt GetElementCount(void);

	protected:
		inline UInt GetNumPrimitives(UInt mode, UInt count)
		{
			switch (mode)
			{
			case Gapi::PRIMITIVE_TYPE::PointList:
				return count;
			case Gapi::PRIMITIVE_TYPE::LineList:
				return count / 2;
			case Gapi::PRIMITIVE_TYPE::LineStrip:
				return count - 1;
			case Gapi::PRIMITIVE_TYPE::TriangleList:
				return count / 3;
			case Gapi::PRIMITIVE_TYPE::TriangleStrip:
				return count - 2;
			default:
				return 0;
			}
		}

	private:
		UInt _bufferID;
		UInt _bufferArrayID;

		UInt _bufferTarget;

		LVERTEX_FORMAT_DESC _vertexFormatDesc;
		UInt _byteStride;
		UInt _numElements;
	};
}

#endif // GPUBUFFER_H