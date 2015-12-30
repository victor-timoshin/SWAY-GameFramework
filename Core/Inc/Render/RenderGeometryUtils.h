#ifndef RENDERGEOMETRYUTILS_H
#define RENDERGEOMETRYUTILS_H

#include "../../../Math/Inc/Vector2.h"
#include "../../../Math/Inc/Vector3.h"
#include "../../../Math/Inc/Vector4.h"
#include "../../../Math/Inc/Vertex.h"
#include "../../../Math/Inc/Color.h"

namespace Core
{
	class RenderGeometryUtils
	{
	public:
		static Scene::LGEOMETRYPACKET GetPrefabPlane(void)
		{
			Math::PVERTEX_NORMAL vertices = new Math::LVERTEX_NORMAL[4];
			vertices[0] = Math::VertexNormal(Math::Vector3F(-1.0f, -1.0f, 0.0f), Math::Vector2F(0.0f, 0.0f));
			vertices[1] = Math::VertexNormal(Math::Vector3F(+1.0f, -1.0f, 0.0f), Math::Vector2F(1.0f, 0.0f));
			vertices[2] = Math::VertexNormal(Math::Vector3F(-1.0f, +1.0f, 0.0f), Math::Vector2F(0.0f, 1.0f));
			vertices[3] = Math::VertexNormal(Math::Vector3F(+1.0f, +1.0f, 0.0f), Math::Vector2F(1.0f, 1.0f));
		
			UByte* indices = new UByte[6];
			indices[0] = 0; indices[1] = 1; indices[2] = 2;
			indices[3] = 2; indices[4] = 1; indices[5] = 3;

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Position, Gapi::VERTEX_ELEMENT_FORMAT::Float3 });
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::TexCoord, Gapi::VERTEX_ELEMENT_FORMAT::Float2 });
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Normal,   Gapi::VERTEX_ELEMENT_FORMAT::Float3 });
			geometryPacket.vertices = (float*)vertices;
			geometryPacket.byteStride = sizeof(Math::LVERTEX_NORMAL);
			geometryPacket.numVertices = 4;
			geometryPacket.indices = indices;
			geometryPacket.numIndices = 6;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::PRIMITIVE_TYPE::TriangleList;

			return geometryPacket;
		}

		static Scene::LGEOMETRYPACKET GetPrefabBox(const Math::Color& color = Math::Color(1.0f, 1.0f, 1.0f, 1.0f))
		{
			Math::PVERTEX_TEXCOORD vertices = new Math::LVERTEX_TEXCOORD[24];

			// Front plane.
			vertices[0]  = Math::VertexTexCoord(Math::Vec3F(+0.5f, +0.5f, +0.5f), Math::Vector2F(1.0f, 1.0f)); // v0
			vertices[1]  = Math::VertexTexCoord(Math::Vec3F(-0.5f, +0.5f, +0.5f), Math::Vector2F(0.0f, 1.0f)); // v1
			vertices[2]  = Math::VertexTexCoord(Math::Vec3F(-0.5f, -0.5f, +0.5f), Math::Vector2F(0.0f, 0.0f)); // v2
			vertices[3]  = Math::VertexTexCoord(Math::Vec3F(+0.5f, -0.5f, +0.5f), Math::Vector2F(1.0f, 0.0f)); // v3
			
			// Right plane.
			vertices[4]  = Math::VertexTexCoord(Math::Vector3F(+0.5f, +0.5f, +0.5f), Math::Vector2F(0.0f, 1.0f)); // v0
			vertices[5]  = Math::VertexTexCoord(Math::Vector3F(+0.5f, -0.5f, +0.5f), Math::Vector2F(0.0f, 0.0f)); // v3
			vertices[6]  = Math::VertexTexCoord(Math::Vector3F(+0.5f, -0.5f, -0.5f), Math::Vector2F(1.0f, 0.0f)); // v4
			vertices[7]  = Math::VertexTexCoord(Math::Vector3F(+0.5f, +0.5f, -0.5f), Math::Vector2F(1.0f, 1.0f)); // v5
			
			// Top plane.
			vertices[8]  = Math::VertexTexCoord(Math::Vector3F(+0.5f, +0.5f, +0.5f), Math::Vector2F(1.0f, 0.0f)); // v0
			vertices[9]  = Math::VertexTexCoord(Math::Vector3F(+0.5f, +0.5f, -0.5f), Math::Vector2F(1.0f, 1.0f)); // v5
			vertices[10] = Math::VertexTexCoord(Math::Vector3F(-0.5f, +0.5f, -0.5f), Math::Vector2F(0.0f, 1.0f)); // v6
			vertices[11] = Math::VertexTexCoord(Math::Vector3F(-0.5f, +0.5f, +0.5f), Math::Vector2F(0.0f, 0.0f)); // v1
			
			// Left plane.
			vertices[12] = Math::VertexTexCoord(Math::Vector3F(-0.5f, +0.5f, +0.5f), Math::Vector2F(1.0f, 1.0f)); // v1
			vertices[13] = Math::VertexTexCoord(Math::Vector3F(-0.5f, +0.5f, -0.5f), Math::Vector2F(0.0f, 1.0f)); // v6
			vertices[14] = Math::VertexTexCoord(Math::Vector3F(-0.5f, -0.5f, -0.5f), Math::Vector2F(0.0f, 0.0f)); // v7
			vertices[15] = Math::VertexTexCoord(Math::Vector3F(-0.5f, -0.5f, +0.5f), Math::Vector2F(1.0f, 0.0f)); // v2
			
			// Bottom plane.
			vertices[16] = Math::VertexTexCoord(Math::Vector3F(-0.5f, -0.5f, -0.5f), Math::Vector2F(1.0f, 1.0f)); // v7
			vertices[17] = Math::VertexTexCoord(Math::Vector3F(+0.5f, -0.5f, -0.5f), Math::Vector2F(0.0f, 1.0f)); // v4
			vertices[18] = Math::VertexTexCoord(Math::Vector3F(+0.5f, -0.5f, +0.5f), Math::Vector2F(0.0f, 0.0f)); // v3
			vertices[19] = Math::VertexTexCoord(Math::Vector3F(-0.5f, -0.5f, +0.5f), Math::Vector2F(1.0f, 0.0f)); // v2
			
			// Back plane.
			vertices[20] = Math::VertexTexCoord(Math::Vector3F(+0.5f, -0.5f, -0.5f), Math::Vector2F(0.0f, 0.0f)); // v4
			vertices[21] = Math::VertexTexCoord(Math::Vector3F(-0.5f, -0.5f, -0.5f), Math::Vector2F(1.0f, 0.0f)); // v7
			vertices[22] = Math::VertexTexCoord(Math::Vector3F(-0.5f, +0.5f, -0.5f), Math::Vector2F(1.0f, 1.0f)); // v6
			vertices[23] = Math::VertexTexCoord(Math::Vector3F(+0.5f, +0.5f, -0.5f), Math::Vector2F(0.0f, 1.0f)); // v5

			UByte* indices = new UByte[36];
			indices[0]  =  0; indices[1]  =  1; indices[2]  =  2; indices[3]  =  2; indices[4]  =  3; indices[5]  =  0; // Front
			indices[6]  =  4; indices[7]  =  5; indices[8]  =  6; indices[9]  =  6; indices[10] =  7; indices[11] =  4; // Right
			indices[12] =  8; indices[13] =  9; indices[14] = 10; indices[15] = 10; indices[16] = 11; indices[17] =  8; // Top
			indices[18] = 12; indices[19] = 13; indices[20] = 14; indices[21] = 14; indices[22] = 15; indices[23] = 12; // Left
			indices[24] = 16; indices[25] = 17; indices[26] = 18; indices[27] = 18; indices[28] = 19; indices[29] = 16; // Bottom
			indices[30] = 20; indices[31] = 21; indices[32] = 22; indices[33] = 22; indices[34] = 23; indices[35] = 20; // Back

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Position, Gapi::VERTEX_ELEMENT_FORMAT::Float3 });
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Color,    Gapi::VERTEX_ELEMENT_FORMAT::Float4 });
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::TexCoord, Gapi::VERTEX_ELEMENT_FORMAT::Float2 });
			geometryPacket.vertices = (float*)vertices;
			geometryPacket.byteStride = sizeof(Math::LVERTEX_TEXCOORD);
			geometryPacket.numVertices = 24;
			geometryPacket.indices = indices;
			geometryPacket.numIndices = 36;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::PRIMITIVE_TYPE::TriangleList;

			geometryPacket.verticesEx.reserve(24);

			for (int i = 0; i < 24; i++)
				geometryPacket.verticesEx.push_back(vertices[i]);

			geometryPacket.faces.reserve(36 /*numOfFaces*/);

			return geometryPacket;
		}

		static Scene::LGEOMETRYPACKET GetPrefabSphere(const UInt numRings, const UInt numSegments)
		{
			float deltaRingAngle = (MATH_REAL_PI / numRings);
			float deltaSegmentAngle = (2 * MATH_REAL_PI / numSegments);
			float radius = 1.0f;

			Math::PVERTEX_NORMAL vertices = new Math::LVERTEX_NORMAL[(numRings + 1) * (numSegments + 1)];
			int verticesIndex = 0;

			UByte* indices = new UByte[6 * numRings * (numSegments + 1)];
			int indicesIndex = 0;

			int offset = 0;

			for (UInt ring = 0; ring <= numRings; ring++)
			{
				float r0 = radius * sinf(ring * deltaRingAngle);
				float y0 = radius * cosf(ring * deltaRingAngle);

				for (UInt segment = 0; segment <= numSegments; segment++)
				{
					float x0 = r0 * sinf(segment * deltaSegmentAngle);
					float z0 = r0 * cosf(segment * deltaSegmentAngle);

					vertices[verticesIndex].position[0] = x0;
					vertices[verticesIndex].position[1] = y0;
					vertices[verticesIndex].position[2] = z0;

					vertices[verticesIndex].textureCoordinates[0] = (float)segment / (float)numSegments;
					vertices[verticesIndex].textureCoordinates[1] = (float)ring / (float)numRings;

					Math::Vector3F normal = Math::Vector3F(x0, y0, z0);
					normal.Normalize();

					vertices[verticesIndex].normal[0] = normal._x;
					vertices[verticesIndex].normal[1] = normal._y;
					vertices[verticesIndex].normal[2] = normal._z;

					verticesIndex++;

					if (ring != numRings)
					{
						indices[indicesIndex++] = offset + numSegments + 1;
						indices[indicesIndex++] = offset;
						indices[indicesIndex++] = offset + numSegments;
						indices[indicesIndex++] = offset + numSegments + 1;
						indices[indicesIndex++] = offset + 1;
						indices[indicesIndex++] = offset;

						offset++;
					}
				}
			}

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Position, Gapi::VERTEX_ELEMENT_FORMAT::Float3 });
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::TexCoord, Gapi::VERTEX_ELEMENT_FORMAT::Float2 });
			geometryPacket.elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Normal,   Gapi::VERTEX_ELEMENT_FORMAT::Float3 });
			geometryPacket.vertices = (float*)vertices;
			geometryPacket.byteStride = sizeof(Math::LVERTEX_NORMAL);
			geometryPacket.numVertices = (numRings + 1) * (numSegments + 1);
			geometryPacket.indices = indices;
			geometryPacket.numIndices = 6 * numRings * (numSegments + 1);
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::PRIMITIVE_TYPE::TriangleList;

			return geometryPacket;
		}
	};
}

#endif // RENDERGEOMETRYUTILS_H