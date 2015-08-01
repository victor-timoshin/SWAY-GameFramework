#ifndef BUFFERBASE_H
#define BUFFERBASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	typedef struct VertexElementDesc
	{
		UInt16 stream;
		//int size;
		//int offset;
		VERTEXELEMENTTYPES type;
		VERTEXELEMENTFORMATS format;
	} LVERTEX_ELEMENT_DESC, *PVERTEX_ELEMENT_DESC;

	typedef struct InputVertexElementDesc
	{
		UInt16 stream;
		int size;
		int offset;
		VERTEXELEMENTTYPES type;
		VERTEXELEMENTFORMATS format;
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

	//typedef struct VertexDescStruct
	//{
	//	UInt16 stream;
	//	UByte type;
	//	UByte format;
	//} LVERTEXDESC_STRUCT, *PVERTEXDESC_STRUCT;

	class IBufferBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IBufferBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IBufferBase(void) {}

		/// <summary>Устанавливает декларацию вершин.</summary>
		virtual void SetVertexDeclaration(const PVERTEX_ELEMENT_DESC elementDesc, UInt numElements) = 0;

		virtual UInt Create(BUFFERTYPES type, UInt stride, UInt count) = 0;

		virtual void Destroy(void) = 0;

		virtual void SetData(void* source) = 0;

		virtual void* Lock(void) = 0;

		virtual void Unlock(void) = 0;

		virtual void Render(PRIMITIVETYPES primitiveType, IBufferBase* indexBufferBase, UInt numVertices, UInt primitiveCount) = 0;
	
		virtual UInt GetID(void) = 0;
	};

	CORE_API IBufferBase* RegisterBuffer(void);
}

#endif // BUFFERBASE_H