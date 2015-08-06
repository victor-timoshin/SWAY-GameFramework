#ifndef GEOMETRYPACET_H
#define GEOMETRYPACET_H

#include "../../Gapi/BufferBase.h"
#include "../../Gapi/Types.h"
#include "../../Platform.h"

namespace Scene
{
	typedef struct GeometryPacket
	{
		std::vector<Gapi::LVERTEX_ELEMENT_DESC> elementDesc;
		float* vertices;
		UByte* indices;
		UInt byteStride;
		UInt numVertices;
		UInt numIndices;
		UInt numPrimitives;
		Gapi::PRIMITIVETYPES primitiveType;
	} LGEOMETRYPACKET, *PGEOMETRYPACKET;
}

#endif // GEOMETRYPACET_H