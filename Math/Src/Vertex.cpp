#include "../Inc/Vertex.h"

namespace Math
{
	LVERTEX_COLOR VertexColor(const Vector3& position, const Vector4& color)
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

	LVERTEX_TEXCOORD VertexTexCoord(const Vector3& position, const Vector2& texCoord)
	{
		LVERTEX_TEXCOORD vertex;

		vertex.x = position._x;
		vertex.y = position._y;
		vertex.z = position._z;

		vertex.u = texCoord._x;
		vertex.v = texCoord._y;

		return vertex;
	}

	LVERTEX_NORMAL VertexNormal(const Vector3& position, const Vector2& texCoord, const Vector3& normal)
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