#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "../../../SDK/Core/Render/RenderSystemBase.h"
#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/Core/Render/MaterialBase.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Platform.h"

#include "Debug/RenderLineDebug.h"

namespace Core
{
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

			virtual void SetRenderableComponent(Scene::IRenderableBase* renderable, IMaterialBase* material);

			virtual bool Initialize(const char* libraryName);

			virtual bool CreateDevice(HWND windowHandle);

			virtual Gapi::IDeviceBase* GetDevice(void);

			virtual IMaterialManagerBase* GetMaterialManager(void);

			virtual GUI::IFontBase* CreateTTFont(const char* name, const char* filename);

			virtual GUI::IFontBase* GetTTFont(std::string name);

			virtual void CreateBuffer(Scene::IRenderableBase* renderable, IMaterialBase* material);

			virtual void RemoveBuffer(UInt idx);

			virtual IRenderGeometryBase* GetGeometryByIndex(UInt idx);

			virtual void FrameDrawed(Scene::ICameraBase* camera);

			virtual int GetNumDisplayObjects(void) const;

		private:
			void* _library;
			Gapi::IDeviceBase* _device;

			IMaterialManagerBase* _materialManager;

			std::vector<IRenderGeometryBase*> renderGeometries;
			int _numDisplayObjects;

			Scene::IRenderableBase* renderableComponent;

			RenderLineDebug* _lineDebug;
			GUI::IFontManagerBase* _fontManager;
		};
	}
}

#endif // RENDERSYSTEM_H