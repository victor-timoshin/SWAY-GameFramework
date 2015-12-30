#ifndef VERTEXELEMENTTYPE_H
#define VERTEXELEMENTTYPE_H

namespace Gapi
{
	typedef enum class VertexElementType
	{
		Position  = 0x0605,
		Color     = 0x3407,
		TexCoord  = 0x309F,
		Normal    = 0x8CB7,
		Tangent   = 0x549F,
		Bitangent = 0x5018
	} VERTEX_ELEMENT_TYPE;
}

#endif // VERTEXELEMENTTYPE_H