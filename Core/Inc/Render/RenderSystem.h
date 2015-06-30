#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "../../../SDK/Core/Render/RenderSystemBase.h"
#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/ShaderBase.h"
#include "../../../SDK/Platform.h"

#include <vector>

namespace Render
{
	class RenderSystem : public IRenderSystemBase
	{
	public:
		/** Constructor. */
		RenderSystem();

		/** Destructor. */
		virtual ~RenderSystem();

		virtual void CreateDevice(const char* libraryName, Core::System::IWindowBase* window);

		virtual void CreateBuffer(Scene::ISceneComponentBase* component);

		virtual void RemoveBuffer(UInt id);

		virtual Core::Render::IRenderGeometryBase* GetGeometryBy(int id);

		virtual void FrameDrawed(Scene::ICameraBase* camera);

	private:
		Gapi::IDeviceBase* renderDevice;
		Gapi::IShaderBase* shader;
		void* library;

		std::vector<Core::Render::IRenderGeometryBase*> renderGeometries;
	};
}

#endif // RENDER_SYSTEM_H