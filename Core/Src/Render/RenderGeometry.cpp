#include "../../../Core/Inc/Render/RenderGeometry.h"
#include "../../../Core/Inc/Render/Material.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		/// <param name="renderable">Указатель на базовый класс.</param>
		RenderGeometry::RenderGeometry(Scene::IRenderableBase* renderable) : IRenderGeometryBase(renderable)
			, _renderableComponent(renderable), _vertexBuffer(nullptr), _indexBuffer(nullptr), _instanceId(-1)
		{
		}

		/// <summary>Деструктор класса.</summary>
		RenderGeometry::~RenderGeometry(void)
		{
			SAFE_DELETE(_indexBuffer);
			SAFE_DELETE(_vertexBuffer);
		}

		/// <summary>Строит геометрию.</summary>
		/// <param name="library">Указатель на хенд графической библиотеки.</param>
		void RenderGeometry::BuildVBOs(void* library)
		{
			const Scene::LGEOMETRYPACKET& geometryPacket = _renderableComponent->GetGeometryPacket();

			if (geometryPacket.vertices != nullptr AND geometryPacket.numVertices != 0)
			{
				typedef Gapi::IBufferBase* VertexBufferCallback(void);
				_vertexBuffer = reinterpret_cast<VertexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))();
				_vertexBuffer->SetVertexDeclaration(geometryPacket.elements);
				_vertexBuffer->Create(Gapi::BUFFER_TYPE::Vertex, geometryPacket.byteStride, geometryPacket.numVertices, Gapi::BUFFER_USAGE::Static);

				void* lockedVertexData = _vertexBuffer->Map();
				if (lockedVertexData != nullptr)
				{
					memcpy(lockedVertexData, geometryPacket.vertices, geometryPacket.numVertices * geometryPacket.byteStride);
					_vertexBuffer->Unmap();
				}
			}

			if (geometryPacket.indices != nullptr AND geometryPacket.numIndices != 0)
			{
				typedef Gapi::IBufferBase* IndexBufferCallback(void);
				_indexBuffer = reinterpret_cast<IndexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))();
				_indexBuffer->Create(Gapi::BUFFER_TYPE::Index, sizeof(UByte), geometryPacket.numIndices, Gapi::BUFFER_USAGE::Static);

				void* lockedIndexData = _indexBuffer->Map();
				if (lockedIndexData != nullptr)
				{
					memcpy(lockedIndexData, geometryPacket.indices, geometryPacket.numIndices * sizeof(UByte));
					_indexBuffer->Unmap();
				}
			}
		}

		/// <summary>Отрисовывает геометрию.</summary>
		void RenderGeometry::Draw(Scene::ICameraBase* camera)
		{
			const Scene::LGEOMETRYPACKET& geometryPacket = _renderableComponent->GetGeometryPacket();
			const Scene::LATTRIBUTE_PACKET& attributePacket = _renderableComponent->GetAttributePacket();

			_lineDebug->AddLineAABB(attributePacket.aabb);

			int modelMatrixLocation = static_cast<Material*>(_material)->GetShader()->GetUniformLocation("ModelMatrix");
			int viewMatrixLocation = static_cast<Material*>(_material)->GetShader()->GetUniformLocation("ViewMatrix");
			int projectionMatrixLocation = static_cast<Material*>(_material)->GetShader()->GetUniformLocation("ProjectionMatrix");
			int textureUnitLocation = static_cast<Material*>(_material)->GetShader()->GetUniformLocation("DiffuseTexture");

			_material->Bind();

			static_cast<Material*>(_material)->GetShader()->SetUniformMatrix4(modelMatrixLocation, true, &attributePacket.modelMatrix);
			static_cast<Material*>(_material)->GetShader()->SetUniformMatrix4(viewMatrixLocation, true, &camera->GetViewMatrix());
			static_cast<Material*>(_material)->GetShader()->SetUniformMatrix4(projectionMatrixLocation, true, &camera->GetProjectionMatrix());
			static_cast<Material*>(_material)->GetShader()->SetUniform1I(textureUnitLocation, 0/*static_cast<Material*>(material)->GetTexture()->GetID()*/);

			_vertexBuffer->Render(geometryPacket.primitiveType, _indexBuffer, geometryPacket.numVertices, geometryPacket.numPrimitives, static_cast<Material*>(_material)->GetShader()->GetShaderProgram());

			_material->Unbind();
		}

		void RenderGeometry::SetMaterial(IMaterialBase* material)
		{
			_material = material;
		}

		IMaterialBase* RenderGeometry::GetMaterial(void) const
		{
			return _material;
		}

		void RenderGeometry::SetInstanceId(UInt id)
		{
			_instanceId = id;
		}

		UInt RenderGeometry::GetInstanceId(void)
		{
			return _instanceId;
		}

		Scene::IRenderableBase* RenderGeometry::GetRenderableComponent(void)
		{
			return _renderableComponent;
		}
	}
}