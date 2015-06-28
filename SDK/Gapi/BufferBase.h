#ifndef BUFFER_BASE_H
#define BUFFER_BASE_H

#include "../../SDK/Gapi/Types.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	typedef struct VertexElementDesc
	{
		UInt16 stream;
		//int size;
		//int offset;
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
	} LVERTEX_FORMAT_DESC, *PVERTEX_FORMAT_DESC;

	//typedef struct VertexDescStruct
	//{
	//	UInt16 stream;
	//	UByte type;
	//	UByte format;
	//} LVERTEXDESC_STRUCT, *PVERTEXDESC_STRUCT;

	class IDeviceBase;
	class IBufferBase
	{
	public:
		/** Constructor. */
		IBufferBase(IDeviceBase* device) {}

		/** Destructor. */
		virtual ~IBufferBase() {}

		virtual void SetVertexDeclaration(const PVERTEX_ELEMENT_DESC elementDesc, UInt numElements) = 0;

		virtual UInt Create(UInt stride, UInt count) = 0;

		virtual void SetData(void* sourceData) = 0;

		virtual void* Lock() = 0;

		virtual void Unlock() = 0;

		virtual void Render(PRIMITIVE_TYPE primitiveType, IBufferBase* indexBufferBase, UInt baseVertexIndex, UInt numVertices, UInt primitiveCount) = 0;
	};

	CORE_API IBufferBase* RegisterBuffer(IDeviceBase* device);
}

#endif // BUFFER_BASE_H