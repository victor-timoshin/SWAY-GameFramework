#ifndef GEOMETRYPACET_H
#define GEOMETRYPACET_H

#include "../../Gapi/Types.h"
#include "../../Platform.h"

namespace Scene
{
	typedef struct GeometryPacket
	{
		float* vertices;
		UByte* indices;
		UInt numVertices;
		UInt numIndices;
		UInt numPrimitives;
		Gapi::PRIMITIVETYPES primitiveType;
	} LGEOMETRYPACKET, *PGEOMETRYPACKET;
}

#endif // GEOMETRYPACET_H