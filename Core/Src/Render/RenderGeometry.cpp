#include "../../../Core/Inc/Render/RenderGeometry.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		RenderGeometry::RenderGeometry(Scene::IRenderableBase* renderable) : IRenderGeometryBase(renderable)
			, renderableComponent(renderable), vertexBuffer(NULL), indexBuffer(NULL), instanceId(-1) {}

		/// <summary>Деструктор класса.</summary>
		RenderGeometry::~RenderGeometry(void)
		{
			SAFE_DELETE(indexBuffer);
			SAFE_DELETE(vertexBuffer);
		}

		void RenderGeometry::BuildVBOs(void* library)
		{
			const Scene::LGEOMETRYPACKET& geometryPacket = renderableComponent->GetGeometryPacket();

			Gapi::LVERTEX_ELEMENT_DESC elementDesc[] = {
				{ 0, Gapi::VERTEXELEMENTTYPES::EVET_POSITION, Gapi::VERTEXELEMENTFORMATS::EVEF_FLOAT },
				{ 0, Gapi::VERTEXELEMENTTYPES::EVET_COLOR, Gapi::VERTEXELEMENTFORMATS::EVEF_UBYTE }
			};

			if (geometryPacket.vertices != NULL && geometryPacket.numVertices != 0)
			{
				typedef Gapi::IBufferBase* VertexBufferCallback(void);
				vertexBuffer = reinterpret_cast<VertexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))();
				vertexBuffer->SetVertexDeclaration(elementDesc, 2);
				vertexBuffer->Create(Gapi::BUFFERTYPES::EBT_VERTEX, sizeof(Math::LVERTEX_COLOR), geometryPacket.numVertices);

				void* lockedVertexData = vertexBuffer->Lock();
				memcpy(lockedVertexData, geometryPacket.vertices, geometryPacket.numVertices * sizeof(Math::LVERTEX_COLOR));
				vertexBuffer->Unlock();
			}

			if (geometryPacket.indices != NULL && geometryPacket.numIndices != 0)
			{
				typedef Gapi::IBufferBase* IndexBufferCallback(void);
				indexBuffer = reinterpret_cast<IndexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))();
				indexBuffer->Create(Gapi::BUFFERTYPES::EBT_INDEX, sizeof(UByte), geometryPacket.numIndices);

				void* lockedIndexData = indexBuffer->Lock();
				memcpy(lockedIndexData, geometryPacket.indices, geometryPacket.numIndices * sizeof(UByte));
				indexBuffer->Unlock();
			}
		}

		void RenderGeometry::Draw(void)
		{
			const Scene::LGEOMETRYPACKET& geometryPacket = renderableComponent->GetGeometryPacket();
			vertexBuffer->Render(geometryPacket.primitiveType, indexBuffer, geometryPacket.numVertices, geometryPacket.numPrimitives);
		}

		void RenderGeometry::SetInstanceId(UInt id)
		{
			instanceId = id;
		}

		UInt RenderGeometry::GetInstanceId(void)
		{
			return instanceId;
		}

		Scene::IRenderableBase* RenderGeometry::GetRenderableComponent(void)
		{
			return renderableComponent;
		}
	}
}