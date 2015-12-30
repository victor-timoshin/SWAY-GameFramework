#include "../Inc/Vertex.h"

namespace Math
{
	LVERTEX_COLOR VertexColor(const Vector3F& position, const Vector4& color)
	{
		LVERTEX_COLOR vertex;

		vertex.x = position.GetX();
		vertex.y = position.GetY();
		vertex.z = position.GetZ();

		vertex.r = color._x;
		vertex.g = color._y;
		vertex.b = color._z;
		vertex.a = color._w;

		return vertex;
	}

	LVERTEX_TEXCOORD VertexTexCoord(const Vector3F& position, const Vector2F& texCoord)
	{
		LVERTEX_TEXCOORD vertex;
		vertex.SetPosition(position);
		vertex.SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
		vertex.SetTexCoord(texCoord);

		return vertex;
	}

	LVERTEX_NORMAL VertexNormal(const Vector3F& position, const Vector2F& texCoord, const Vector3F& normal)
	{
		LVERTEX_NORMAL vertex;

		vertex.position[0] = position.GetX();
		vertex.position[1] = position.GetY();
		vertex.position[2] = position.GetZ();

		vertex.textureCoordinates[0] = texCoord._x;
		vertex.textureCoordinates[1] = texCoord._y;

		vertex.normal[0] = normal.GetX();
		vertex.normal[1] = normal.GetY();
		vertex.normal[2] = normal.GetZ();

		return vertex;
	}
}