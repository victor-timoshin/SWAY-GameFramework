#ifndef RENDERGEOMETRYUTILS_H
#define RENDERGEOMETRYUTILS_H

#include "../../../SDK/Math/Vector2.h"
#include "../../../SDK/Math/Vector3.h"
#include "../../../SDK/Math/Vector4.h"
#include "../../../SDK/Math/Vertex.h"
#include "../../../SDK/Math/Color.h"

namespace Core
{
	class RenderGeometryUtils
	{
	public:
		static Scene::LGEOMETRYPACKET GetPrefabPlane(void)
		{
			Math::PVERTEX_NORMAL vertices = new Math::LVERTEX_NORMAL[4];
			vertices[0] = Math::VertexNormal(Math::Vector3(-1.0f, -1.0f, 0.0f), Math::Vector2(0.0f, 0.0f));
			vertices[1] = Math::VertexNormal(Math::Vector3( 1.0f, -1.0f, 0.0f), Math::Vector2(1.0f, 0.0f));
			vertices[2] = Math::VertexNormal(Math::Vector3(-1.0f,  1.0f, 0.0f), Math::Vector2(0.0f, 1.0f));
			vertices[3] = Math::VertexNormal(Math::Vector3( 1.0f,  1.0f, 0.0f), Math::Vector2(1.0f, 1.0f));

			UByte* Indices = new UByte[6];
			Indices[0] = 0; Indices[1] = 1; Indices[2] = 2;
			Indices[3] = 2; Indices[4] = 1; Indices[5] = 3;

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.numVertices = 4;
			geometryPacket.vertices = (float*)vertices;
			geometryPacket.numIndices = 6;
			geometryPacket.indices = Indices;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::EPT_TRIANGLELIST;

			return geometryPacket;
		}

		static Scene::LGEOMETRYPACKET GetPrefabBox(const Math::Color& color = Math::Color(1.0f, 1.0f, 1.0f, 1.0f))
		{
			Math::PVERTEX_COLOR vertices = new Math::LVERTEX_COLOR[24];

			/* Front plane. */
			vertices[ 0] = Math::VertexColor(Math::Vector3(+0.5f, +0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v0
			vertices[ 1] = Math::VertexColor(Math::Vector3(-0.5f, +0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v1
			vertices[ 2] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v2
			vertices[ 3] = Math::VertexColor(Math::Vector3(+0.5f, -0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v3
			/* Right plane. */
			vertices[ 4] = Math::VertexColor(Math::Vector3(+0.5f, +0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v0
			vertices[ 5] = Math::VertexColor(Math::Vector3(+0.5f, -0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v3
			vertices[ 6] = Math::VertexColor(Math::Vector3(+0.5f, -0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v4
			vertices[ 7] = Math::VertexColor(Math::Vector3(+0.5f, +0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v5
			/* Top plane. */
			vertices[ 8] = Math::VertexColor(Math::Vector3(+0.5f, +0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v0
			vertices[ 9] = Math::VertexColor(Math::Vector3(+0.5f, +0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v5
			vertices[10] = Math::VertexColor(Math::Vector3(-0.5f, +0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v6
			vertices[11] = Math::VertexColor(Math::Vector3(-0.5f, +0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v1
			/* Left plane. */
			vertices[12] = Math::VertexColor(Math::Vector3(-0.5f, +0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v1
			vertices[13] = Math::VertexColor(Math::Vector3(-0.5f, +0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v6
			vertices[14] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v7
			vertices[15] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v2
			/* Bottom plane. */
			vertices[16] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v7
			vertices[17] = Math::VertexColor(Math::Vector3(+0.5f, -0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v4
			vertices[18] = Math::VertexColor(Math::Vector3(+0.5f, -0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v3
			vertices[19] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, +0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v2
			/* Back plane. */
			vertices[20] = Math::VertexColor(Math::Vector3(+0.5f, -0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v4
			vertices[21] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v7
			vertices[22] = Math::VertexColor(Math::Vector3(-0.5f, +0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v6
			vertices[23] = Math::VertexColor(Math::Vector3(+0.5f, +0.5f, -0.5f), Math::Vector4(color._r, color._g, color._b, color._a)); // v5

			UByte* indices = new UByte[36];
			indices[ 0] =  0; indices[ 1] =  1; indices[ 2] =  2; indices[ 3] =  2; indices[ 4] =  3; indices[ 5] =  0; // Front
			indices[ 6] =  4; indices[ 7] =  5; indices[ 8] =  6; indices[ 9] =  6; indices[10] =  7; indices[11] =  4; // Right
			indices[12] =  8; indices[13] =  9; indices[14] = 10; indices[15] = 10; indices[16] = 11; indices[17] =  8; // Top
			indices[18] = 12; indices[19] = 13; indices[20] = 14; indices[21] = 14; indices[22] = 15; indices[23] = 12; // Left
			indices[24] = 16; indices[25] = 17; indices[26] = 18; indices[27] = 18; indices[28] = 19; indices[29] = 16; // Bottom
			indices[30] = 20; indices[31] = 21; indices[32] = 22; indices[33] = 22; indices[34] = 23; indices[35] = 20; // Back

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.numVertices = 24;
			geometryPacket.vertices = (float*)vertices;
			geometryPacket.numIndices = 36;
			geometryPacket.indices = indices;
			geometryPacket.numPrimitives = geometryPacket.numIndices;
			geometryPacket.primitiveType = Gapi::EPT_TRIANGLELIST;

			return geometryPacket;
		}

		static Scene::LGEOMETRYPACKET GetPrefabSphere(const UInt numRings, const UInt numSegments)
		{
			float deltaRingAngle = (Math::REAL_PI / numRings);
			float deltaSegmentAngle = (2 * Math::REAL_PI / numSegments);
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

					Math::Vector3 normal = Math::Vector3(x0, y0, z0);
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
			geometryPacket.numVertices = (numRings + 1) * (numSegments + 1);
			geometryPacket.vertices = (float*)vertices;
			geometryPacket.numIndices = 6 * numRings * (numSegments + 1);
			geometryPacket.indices = indices;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::EPT_TRIANGLELIST;

			return geometryPacket;
		}
	};
}

#endif // RENDERGEOMETRYUTILS_H