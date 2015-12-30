#ifndef VERTEX_H
#define VERTEX_H

#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Color.h"

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
		float r, g, b, a; // unsigned char
		float u, v;

		/// <summary>Устанавливает координаты позиции вершины.</summary>
		void SetPosition(const Vec3F& position) { x = position.GetX(); y = position.GetY(); z = position.GetZ(); }

		/// <summary>Получает координаты позиции вершины.</summary>
		Vec3F GetPosition(void) const { return Vec3F(x, y, z); }

		/// <summary>Устанавливает цвет вершины.</summary>
		void SetColor(const Color& color) { r = color.GetR(); g = color.GetG(); b = color.GetB(); a = color.GetA(); }

		/// <summary>Получает цвет вершины.</summary>
		Color GetColor(void) const { return Color(r, g, b, a); }

		/// <summary>Устанавливает координаты текстуры.</summary>
		void SetTexCoord(const Vector2F& texCoord) { u = texCoord.GetX(); v = texCoord.GetY(); }

		/// <summary>Получает координаты текстуры.</summary>
		Vector2F GetTexCoord(void) const { return Vector2F(u, v); }
	} LVERTEX_TEXCOORD, *PVERTEX_TEXCOORD;

	typedef struct VertexNormal
	{
		float position[3];
		float textureCoordinates[2];
		float normal[3];
	} LVERTEX_NORMAL, *PVERTEX_NORMAL;

	LVERTEX_COLOR CORE_API VertexColor(const Vector3F& position, const Vector4& color);
	LVERTEX_TEXCOORD CORE_API VertexTexCoord(const Vector3F& position, const Vector2F& texCoord);
	LVERTEX_NORMAL CORE_API VertexNormal(const Vector3F& position, const Vector2F& texCoord, const Vector3F& normal = Vector3F(0.0f, 0.0f, 0.0f));
}

#endif // VERTEX_H