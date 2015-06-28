#ifndef RENDER_GEOMETRY_UTILS_H
#define RENDER_GEOMETRY_UTILS_H

#include "../../../SDK/Core/Scene/SceneComponentBase.h"
#include "../../../SDK/Core/Math/Vector2.h"
#include "../../../SDK/Core/Math/Vector3.h"
#include "../../../SDK/Core/Math/Vector4.h"
#include "../../../SDK/Core/Math/Vertex.h"

namespace Core
{
	class RenderGeometryUtils
	{
	public:
		static Scene::LGEOMETRYPACKET GetPrefabPlane()
		{
			Math::PVERTEX_NORMAL vertices = new Math::LVERTEX_NORMAL[4];
			vertices[0] = Math::VertexNormal(Math::Vector3(-1.0f, -1.0f, 0.0f), Math::Vector2(0.0f, 0.0f));
			vertices[1] = Math::VertexNormal(Math::Vector3(1.0f, -1.0f, 0.0f), Math::Vector2(1.0f, 0.0f));
			vertices[2] = Math::VertexNormal(Math::Vector3(-1.0f, 1.0f, 0.0f), Math::Vector2(0.0f, 1.0f));
			vertices[3] = Math::VertexNormal(Math::Vector3(1.0f, 1.0f, 0.0f), Math::Vector2(1.0f, 1.0f));

			UInt16* Indices = new UInt16[6];
			Indices[0] = 0; Indices[1] = 1; Indices[2] = 2;
			Indices[3] = 2; Indices[4] = 1; Indices[5] = 3;

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.numVertices = 4;
			geometryPacket.vertices = vertices;
			geometryPacket.numIndices = 6;
			geometryPacket.indices = Indices;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::TYPE_TRIANGLELIST;

			return geometryPacket;
		}
		static Scene::LGEOMETRYPACKET GetPrefabBox()
		{
			Math::PVERTEX_COLOR vertices = new Math::LVERTEX_COLOR[24];

			/* Far plane. */
			vertices[ 0] = Math::VertexColor(Math::Vector3( 0.5f, -0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 1] = Math::VertexColor(Math::Vector3(-0.5f,  0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 2] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 3] = Math::VertexColor(Math::Vector3( 0.5f,  0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			/* Right plane. */
			vertices[ 4] = Math::VertexColor(Math::Vector3( 0.5f, -0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 5] = Math::VertexColor(Math::Vector3( 0.5f,  0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 6] = Math::VertexColor(Math::Vector3( 0.5f, -0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 7] = Math::VertexColor(Math::Vector3( 0.5f,  0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			/* Front plane. */
			vertices[ 8] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[ 9] = Math::VertexColor(Math::Vector3( 0.5f,  0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[10] = Math::VertexColor(Math::Vector3( 0.5f, -0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[11] = Math::VertexColor(Math::Vector3(-0.5f,  0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			/* Left plane. */
			vertices[12] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[13] = Math::VertexColor(Math::Vector3(-0.5f,  0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[14] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[15] = Math::VertexColor(Math::Vector3(-0.5f,  0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			/* Upper plane. */
			vertices[16] = Math::VertexColor(Math::Vector3( 0.5f,  0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[17] = Math::VertexColor(Math::Vector3(-0.5f,  0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[18] = Math::VertexColor(Math::Vector3(-0.5f,  0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[19] = Math::VertexColor(Math::Vector3( 0.5f,  0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			/* Lower plane. */
			vertices[20] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[21] = Math::VertexColor(Math::Vector3( 0.5f, -0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[22] = Math::VertexColor(Math::Vector3(-0.5f, -0.5f, -0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
			vertices[23] = Math::VertexColor(Math::Vector3( 0.5f, -0.5f,  0.5f), Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));


			UInt16* indices = new UInt16[36];
			indices[0]  =  2; indices[1]  =  1; indices[2]  =  0;
			indices[3]  =  1; indices[4]  =  3; indices[5]  =  0;
			indices[6]  =  6; indices[7]  =  5; indices[8]  =  4;
			indices[9]  =  5; indices[10] =  7; indices[11] =  4;
			indices[12] = 10; indices[13] =  9; indices[14] =  8;
			indices[15] =  9; indices[16] = 11; indices[17] =  8;
			indices[18] = 14; indices[19] = 13; indices[20] = 12;
			indices[21] = 13; indices[22] = 15; indices[23] = 12;
			indices[24] = 18; indices[25] = 17; indices[26] = 16;
			indices[27] = 17; indices[28] = 19; indices[29] = 16;
			indices[30] = 22; indices[31] = 21; indices[32] = 20;
			indices[33] = 21; indices[34] = 23; indices[35] = 20;

			Scene::LGEOMETRYPACKET geometryPacket;
			geometryPacket.numVertices = 24;
			geometryPacket.vertices = vertices;
			geometryPacket.numIndices = 36;
			geometryPacket.indices = indices;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::TYPE_TRIANGLELIST;

			return geometryPacket;
		}

		static Scene::LGEOMETRYPACKET GetPrefabSphere(const UInt numRings, const UInt numSegments)
		{
			float deltaRingAngle = (Math::REAL_PI / numRings);
			float deltaSegmentAngle = (2 * Math::REAL_PI / numSegments);
			float radius = 1.0f;

			Math::PVERTEX_NORMAL vertices = new Math::LVERTEX_NORMAL[(numRings + 1) * (numSegments + 1)];
			int verticesIndex = 0;

			UInt16* indices = new UInt16[6 * numRings * (numSegments + 1)];
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
			geometryPacket.vertices = vertices;
			geometryPacket.numIndices = 6 * numRings * (numSegments + 1);
			geometryPacket.indices = indices;
			geometryPacket.numPrimitives = geometryPacket.numIndices / 3;
			geometryPacket.primitiveType = Gapi::TYPE_TRIANGLELIST;

			return geometryPacket;
		}
	};
}

#endif // RENDER_GEOMETRY_UTILS_H