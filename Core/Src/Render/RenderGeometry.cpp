#include "../../../Core/Inc/Render/RenderGeometry.h"

#include <string.h>

namespace Core
{
	namespace Render
	{
		/** Constructor. */
		RenderGeometry::RenderGeometry(Scene::ISceneComponentBase* component, Gapi::IDeviceBase* device) : IRenderGeometryBase(component, device)
			, sceneComponent(component), renderDevice(device), vertexBuffer(0L), indexBuffer(0L), instanceId(-1) {}

		/** Destructor. */
		RenderGeometry::~RenderGeometry()
		{
			SAFE_DELETE(indexBuffer);
			SAFE_DELETE(vertexBuffer);
		}

		void RenderGeometry::CreateBuffer(void* library, Gapi::IShaderBase* shader)
		{
			const Scene::LGEOMETRYPACKET& geometryPacket = sceneComponent->GetGeometryPacket();

			typedef Gapi::IBufferBase* VertexBufferCallback(void*);
			vertexBuffer = reinterpret_cast<VertexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))(renderDevice);
			vertexBuffer->Create(sizeof Math::LVERTEXDIFFUSE_STRUCT, geometryPacket.numVertices);

			void* lockedVertexData = vertexBuffer->Lock();
			memcpy(lockedVertexData, geometryPacket.vertices, geometryPacket.numVertices * sizeof Math::LVERTEXDIFFUSE_STRUCT);
			vertexBuffer->Unlock();

			typedef Gapi::IBufferBase* IndexBufferCallback(void*);
			indexBuffer = reinterpret_cast<IndexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))(renderDevice);
			indexBuffer->Create(sizeof UInt16, geometryPacket.numIndices);

			void* lockedIndexData = indexBuffer->Lock();
			memcpy(lockedIndexData, geometryPacket.indices, geometryPacket.numIndices * sizeof UInt16);
			indexBuffer->Unlock();
		}

		void RenderGeometry::Draw()
		{
			const Scene::LGEOMETRYPACKET& geometryPacket = sceneComponent->GetGeometryPacket();

			vertexBuffer->Render(geometryPacket.primitiveType, indexBuffer, 0,
				geometryPacket.numVertices, geometryPacket.numPrimitives);
		}

		void RenderGeometry::SetInstanceId(UInt id)
		{
			instanceId = id;
		}

		UInt RenderGeometry::GetInstanceId()
		{
			return instanceId;
		}
	}
}