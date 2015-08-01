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

	inline LVERTEX_COLOR VertexColor(const Vector3& position, const Vector4& color)
	{
		LVERTEX_COLOR vertex;

		vertex.x = position._x;
		vertex.y = position._y;
		vertex.z = position._z;

		vertex.r = color._x;
		vertex.g = color._y;
		vertex.b = color._z;
		vertex.a = color._w;

		return vertex;
	}

	typedef struct VertexTexcoord
	{
		float x, y, z;
		float u, v;
	} LVERTEX_TEXCOORD, *PVERTEX_TEXCOORD;

	inline LVERTEX_TEXCOORD VertexTexCoord(const Vector3& position, const Vector2& texCoord)
	{
		LVERTEX_TEXCOORD vertex;

		vertex.x = position._x;
		vertex.y = position._y;
		vertex.z = position._z;

		vertex.u = texCoord._x;
		vertex.v = texCoord._y;

		return vertex;
	}

	typedef struct VertexNormal
	{
		float position[3];
		float textureCoordinates[2];
		float normal[3];
	} LVERTEX_NORMAL, *PVERTEX_NORMAL;

	inline LVERTEX_NORMAL VertexNormal(const Vector3& position, const Vector2& texCoord, const Vector3& normal = Vector3(0.0f, 0.0f, 0.0f))
	{
		LVERTEX_NORMAL vertex;

		vertex.position[0] = position._x;
		vertex.position[1] = position._y;
		vertex.position[2] = position._z;

		vertex.textureCoordinates[0] = texCoord._x;
		vertex.textureCoordinates[1] = texCoord._y;

		vertex.normal[0] = normal._x;
		vertex.normal[1] = normal._y;
		vertex.normal[2] = normal._z;

		return vertex;
	}
}

#endif // VERTEX_H