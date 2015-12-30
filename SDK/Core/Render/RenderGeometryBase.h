#ifndef RENDERGEOMETRYBASE_H
#define RENDERGEOMETRYBASE_H

#include "../../../SDK/Core/Scene/RenderableBase.h"
#include "../../../SDK/Core/Render/MaterialBase.h"

#include "../../../SDK/SceneGraph/CameraBase.h"

#include "../../../SDK/Gapi/BufferBase.h"
#include "../../../SDK/Gapi/ShaderBase.h"

namespace Core
{
	namespace Render
	{
		class IRenderGeometryBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			IRenderGeometryBase(Scene::IRenderableBase* renderable) {}

			/// <summary>Деструктор класса.</summary>
			virtual ~IRenderGeometryBase(void) {}

			virtual void BuildVBOs(void* library) = 0;

			/// <summary>Отрисовывает геометрию.</summary>
			virtual void Draw(Scene::ICameraBase* camera) = 0;

			virtual void SetMaterial(Render::IMaterialBase* material) = 0;

			virtual Render::IMaterialBase* GetMaterial(void) const = 0;

			virtual void SetInstanceId(UInt id) = 0;

			virtual UInt GetInstanceId(void) = 0;

			virtual Scene::IRenderableBase* GetRenderableComponent(void) = 0;
		};
	}
}

#endif // RENDERGEOMETRYBASE_H