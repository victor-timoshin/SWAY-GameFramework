#ifndef VERTEX_H
#define VERTEX_H

#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"

namespace Core
{
	namespace Math
	{
		typedef struct VertexDiffuseStruct
		{
			float r, g, b, a; // unsigned char
			float x, y, z;
		} LVERTEXDIFFUSE_STRUCT, *PVERTEXDIFFUSE_STRUCT;

		inline LVERTEXDIFFUSE_STRUCT VertexDiffuse(const Vector3& position, const Vector4& color)
		{
			LVERTEXDIFFUSE_STRUCT vertex;

			vertex.r = color._x;
			vertex.g = color._y;
			vertex.b = color._z;
			vertex.a = color._w;

			vertex.x = position._x;
			vertex.y = position._y;
			vertex.z = position._z;

			return vertex;
		}

		typedef struct VertexTexcoordStruct
		{
			float x, y, z;
			float u, v;
		} LVERTEXTEXCOORD_STRUCT, *PVERTEXTEXCOORD_STRUCT;

		inline LVERTEXTEXCOORD_STRUCT VertexTexCoord(const Vector3& position, const Vector2& texCoord)
		{
			LVERTEXTEXCOORD_STRUCT vertex;

			vertex.x = position._x;
			vertex.y = position._y;
			vertex.z = position._z;

			vertex.u = texCoord._x;
			vertex.v = texCoord._y;

			return vertex;
		}

		typedef struct VertexNormalStruct
		{
			float position[3];
			float textureCoordinates[2];
			float normal[3];
		} LVERTEXNORMAL_STRUCT, *PVERTEXNORMAL_STRUCT;

		inline LVERTEXNORMAL_STRUCT VertexNormal(const Vector3& position, const Vector2& texCoord, const Vector3& normal = Vector3(0.0f, 0.0f, 0.0f))
		{
			LVERTEXNORMAL_STRUCT vertex;

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
}

#endif // VERTEX_H