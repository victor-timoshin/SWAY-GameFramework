#ifndef RENDERGEOMETRY_H
#define RENDERGEOMETRY_H

#include "Debug/RenderLineDebug.h"

#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../Math/Inc/Vertex.h"

namespace Core
{
	namespace Render
	{
		class RenderGeometry : public IRenderGeometryBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			RenderGeometry(Scene::IRenderableBase* renderable);

			/// <summary>Деструктор класса.</summary>
			virtual ~RenderGeometry(void);

			virtual void BuildVBOs(void* library);

			void SetDebugLines(RenderLineDebug* lineDebug) {
				_lineDebug = lineDebug;
			}

			/// <summary>Отрисовывает геометрию.</summary>
			virtual void Draw(Scene::ICameraBase* camera);

			virtual void SetMaterial(IMaterialBase* material);

			virtual IMaterialBase* GetMaterial(void) const;

			virtual void SetInstanceId(UInt id);

			virtual UInt GetInstanceId(void);

			virtual Scene::IRenderableBase* GetRenderableComponent(void);
		private:
			IMaterialBase* _material;

			Scene::IRenderableBase* _renderableComponent;

			Gapi::IBufferBase* _vertexBuffer; // Буфер вершин.
			Gapi::IBufferBase* _indexBuffer; // Буфер индексов.

			UInt _instanceId;

			RenderLineDebug* _lineDebug;
		};
	}
}

#endif // RENDERGEOMETRY_H