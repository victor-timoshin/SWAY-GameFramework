#ifndef BUFFERBASE_H
#define BUFFERBASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	typedef struct VertexElementDesc
	{
		UInt16 stream;
		VERTEX_ELEMENT_TYPE type;
		VERTEX_ELEMENT_FORMAT format;
	} LVERTEX_ELEMENT_DESC, *PVERTEX_ELEMENT_DESC;

	typedef struct InputVertexElementDesc
	{
		UInt16 stream;
		int size;
		int offset;
		VERTEX_ELEMENT_TYPE type;
		VERTEX_ELEMENT_FORMAT format;
	} LINPUT_VERTEX_ELEMENT_DESC, *PINPUT_VERTEX_ELEMENT_DESC;

	typedef struct VertexFormatDesc
	{
		LINPUT_VERTEX_ELEMENT_DESC position;
		LINPUT_VERTEX_ELEMENT_DESC color;
		LINPUT_VERTEX_ELEMENT_DESC texCoord;
		LINPUT_VERTEX_ELEMENT_DESC normal;
		LINPUT_VERTEX_ELEMENT_DESC tangent;
		LINPUT_VERTEX_ELEMENT_DESC bitangent;
	} LVERTEX_FORMAT_DESC, *PVERTEX_FORMAT_DESC;

	class IBufferBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IBufferBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IBufferBase(void) {}

		/// <summary>Устанавливает декларацию вершин.</summary>
		virtual void SetVertexDeclaration(const std::vector<LVERTEX_ELEMENT_DESC>& elements) = 0;

		virtual void CreateArray(BUFFER_TYPE type, UInt stride, UInt count, BUFFER_USAGE usage) = 0;
		virtual void Create(BUFFER_TYPE type, UInt stride, UInt count, BUFFER_USAGE usage) = 0;

		virtual void Destroy(void) = 0;

		virtual void SetData(void* source) = 0;

		virtual void* Map(void) = 0;

		virtual void* MapRange(int offset, int length) = 0;

		virtual void Unmap(void) = 0;

		virtual void BindVertexArray() = 0;
		virtual void UnbindVertexArray() = 0;
		virtual void RenderW(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt first, UInt numVertices, UInt primitiveCount) = 0;

		virtual void Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt numVertices, UInt primitiveCount, UInt shaderProgram) = 0;
	
		virtual UInt GetID(void) = 0;

		virtual void SetByteStride(UInt stride) = 0;

		virtual UInt GetByteStride(void) const = 0;
	};

	CORE_API IBufferBase* RegisterBuffer(void);
}

#endif // BUFFERBASE_H