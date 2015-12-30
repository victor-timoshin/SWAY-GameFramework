#ifndef RENDERSYSTEMBASE_H
#define RENDERSYSTEMBASE_H

#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/SceneGraph/CameraBase.h"
#include "../../../SDK/GUI/FontManagerBase.h"
#include "../../../SDK/GUI/FontBase.h"
#include "../../../SDK/Platform.h"

namespace Core
{
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

			virtual void SetRenderableComponent(Scene::IRenderableBase* renderable, IMaterialBase* material) = 0;

			virtual bool Initialize(const char* libraryName) = 0;

			virtual bool CreateDevice(HWND windowHandle) = 0;

			virtual Gapi::IDeviceBase* GetDevice(void) = 0;

			virtual bool CreateMaterial(const char* name, const char* vertexShader, const char* fragmentShader, const char* textureName) = 0;

			virtual IMaterialBase* GetMaterialByName(const char* name) = 0;

			virtual GUI::IFontBase* CreateTTFont(const char* name, const char* filename) = 0;

			virtual GUI::IFontBase* GetTTFont(std::string name) = 0;

			virtual void CreateBuffer(Scene::IRenderableBase* renderable, IMaterialBase* material) = 0;

			virtual void RemoveBuffer(UInt idx) = 0;

			virtual IRenderGeometryBase* GetGeometryByIndex(UInt idx) = 0;

			virtual void FrameDrawed(Scene::ICameraBase* camera) = 0;

			virtual int GetNumDisplayObjects(void) const = 0;
		};

		CORE_API IRenderSystemBase* RegisterRenderSystem(void);
	}

}

#endif // RENDERSYSTEMBASE_H