#ifndef RENDERSYSTEMBASE_H
#define RENDERSYSTEMBASE_H

#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/SceneGraph/CameraBase.h"
#include "../../../SDK/Platform.h"

namespace Render
{
	class Scene::IRenderableBase;
	class IRenderSystemBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IRenderSystemBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IRenderSystemBase(void) {}

		virtual void SetRenderableComponent(Scene::IRenderableBase* renderable) = 0;

		virtual bool Initialize(const char* libraryName) = 0;

		virtual bool CreateDevice(HWND windowHandle) = 0;

		virtual Gapi::IDeviceBase* GetDevice(void) = 0;

		virtual bool CreateMaterial(const char* vertexShader, const char* fragmentShader) = 0;

		virtual bool CreateTTFont(const char* filename) = 0;

		virtual void CreateBuffer(Scene::IRenderableBase* renderable) = 0;

		virtual void RemoveBuffer(UInt idx) = 0;

		virtual Core::Render::IRenderGeometryBase* GetGeometryByIndex(UInt idx) = 0;

		virtual void FrameDrawed(Scene::ICameraBase* camera) = 0;
	};

	CORE_API IRenderSystemBase* RegisterRenderSystem(void);
}

#endif // RENDERSYSTEMBASE_H