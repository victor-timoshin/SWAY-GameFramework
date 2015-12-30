#ifndef GEOMETRYPACET_H
#define GEOMETRYPACET_H

#include "../../../Math/Inc/Face.h"
#include "../../../Math/Inc/Vertex.h"

#include "../../Gapi/BufferBase.h"
#include "../../Gapi/Types.h"
#include "../../Platform.h"

namespace Scene
{
	typedef struct GeometryPacket
	{
		std::vector<Gapi::LVERTEX_ELEMENT_DESC> elements;
		float* vertices;
		std::vector<Math::LVERTEX_TEXCOORD> verticesEx;
		std::vector<Math::FACE> faces;
		UByte* indices;
		UInt byteStride;
		UInt numVertices;
		UInt numIndices;
		UInt numPrimitives;
		Gapi::PRIMITIVE_TYPE primitiveType;

		//UInt GetNumberOfFaces(void) const { return faces.size(); }
		//void SetFace(UInt i, const Math::FACE& face) { faces[i] = face; }
		//const Math::FACE& GetFace(UInt i) const { return faces[i]; }
		//Math::FACE& GetFace(UInt i) { return faces[i]; }
		//Math::FACE* GetFaceArray(void) { return faces.data(); }
		//void ResizeFaces(UInt newSize) { faces.resize(newSize); }
	} LGEOMETRYPACKET, *PGEOMETRYPACKET;
}

#endif // GEOMETRYPACET_H