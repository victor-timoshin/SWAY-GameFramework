#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "../../../SDK/Core/Render/RenderSystemBase.h"
#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/Core/Render/MaterialBase.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/FontBase.h"
#include "../../../SDK/Platform.h"

#include <vector>

namespace Render
{
	class Scene::IRenderableBase;
	class RenderSystem : public IRenderSystemBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		RenderSystem(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~RenderSystem(void);

		virtual void SetRenderableComponent(Scene::IRenderableBase* renderable);

		virtual bool Initialize(const char* libraryName);

		virtual bool CreateDevice(HWND windowHandle);

		virtual Gapi::IDeviceBase* GetDevice(void);

		virtual bool CreateMaterial(const char* vertexShader, const char* fragmentShader);

		virtual void CreateBuffer(Scene::IRenderableBase* renderable);

		virtual void RemoveBuffer(UInt idx);

		virtual Core::Render::IRenderGeometryBase* GetGeometryByIndex(UInt idx);

		virtual void FrameDrawed(Scene::ICameraBase* camera);

	private:
		void* library;
		Gapi::IDeviceBase* device;
		Gapi::IFontBase* font;
		Render::IMaterialBase* material;

		std::vector<Core::Render::IRenderGeometryBase*> renderGeometries;
		int numDisplayObjects;

		Scene::IRenderableBase* renderableComponent;
	};
}

#endif // RENDERSYSTEM_H