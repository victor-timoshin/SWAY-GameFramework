#ifndef RENDERGEOMETRY_H
#define RENDERGEOMETRY_H

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

			virtual void Draw(void);

			virtual void SetInstanceId(UInt id);

			virtual UInt GetInstanceId(void);

			virtual Scene::IRenderableBase* GetRenderableComponent(void);
		private:
			Scene::IRenderableBase* renderableComponent;

			Gapi::IBufferBase* vertexBuffer;
			Gapi::IBufferBase* indexBuffer;

			UInt instanceId;
		};
	}
}

#endif // RENDERGEOMETRY_H