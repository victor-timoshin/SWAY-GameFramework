#ifndef VERTEX_H
#define VERTEX_H

namespace Gapi
{
	typedef struct VertexDiffuseStruct
	{
		float x, y, z;
		unsigned long color;
	} LVERTEXDIFFUSE_STRUCT, *PVERTEXDIFFUSE_STRUCT;

	typedef struct VertexTexcoordStruct
	{
		float x, y, z;
		float u, v;
	} LVERTEXTEXCOORD_STRUCT, *PVERTEXTEXCOORD_STRUCT;

	typedef struct VertexNormalStruct
	{
		float position[3];
		float textureCoordinates[2];
		float normal[3];
	} LVERTEXNORMAL_STRUCT, *PVERTEXNORMAL_STRUCT;
}

#endif