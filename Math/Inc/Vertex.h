#ifndef VERTEX_H
#define VERTEX_H

#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"

namespace Math
{
	typedef struct VertexColor
	{
		float x, y, z;
		float r, g, b, a; // unsigned char
	} LVERTEX_COLOR, *PVERTEX_COLOR;

	typedef struct VertexTexcoord
	{
		float x, y, z;
		float u, v;
	} LVERTEX_TEXCOORD, *PVERTEX_TEXCOORD;

	typedef struct VertexNormal
	{
		float position[3];
		float textureCoordinates[2];
		float normal[3];
	} LVERTEX_NORMAL, *PVERTEX_NORMAL;

	LVERTEX_COLOR CORE_API VertexColor(const Vector3& position, const Vector4& color);
	LVERTEX_TEXCOORD CORE_API VertexTexCoord(const Vector3& position, const Vector2& texCoord);
	LVERTEX_NORMAL CORE_API VertexNormal(const Vector3& position, const Vector2& texCoord, const Vector3& normal = Vector3(0.0f, 0.0f, 0.0f));
}

#endif // VERTEX_H