#ifndef RENDER_SYSTEM_BASE_H
#define RENDER_SYSTEM_BASE_H

#include "../../../SDK/Core/System/WindowBase.h"
#include "../../../SDK/Core/Scene/SceneComponentBase.h"
#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/Core/Scene/CameraBase.h"
#include "../../../SDK/Platform.h"

namespace Render
{
	class IRenderSystemBase
	{
	public:
		/** Constructor. */
		IRenderSystemBase() {}

		/** Destructor. */
		virtual ~IRenderSystemBase() {}

		virtual void CreateDevice(const char* libraryName, Core::System::IWindowBase* window) = 0;

		virtual void CreateBuffer(Scene::ISceneComponentBase* component) = 0;

		virtual void RemoveBuffer(UInt id) = 0;

		virtual Core::Render::IRenderGeometryBase* GetGeometryBy(int id) = 0;

		virtual void FrameDrawed(Scene::ICameraBase* camera) = 0;
	};

	CORE_API IRenderSystemBase* RegisterRenderSystem();
}

#endif // RENDER_SYSTEM_BASE_H