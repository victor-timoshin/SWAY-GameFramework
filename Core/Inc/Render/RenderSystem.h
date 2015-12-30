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

			virtual bool CreateMaterial(const char* name, const char* vertexShader, const char* fragmentShader, const char* textureName);

			virtual IMaterialBase* GetMaterialByName(const char* name);

			virtual GUI::IFontBase* CreateTTFont(const char* name, const char* filename);

			virtual GUI::IFontBase* GetTTFont(std::string name);

			virtual void CreateBuffer(Scene::IRenderableBase* renderable, IMaterialBase* material);

			virtual void RemoveBuffer(UInt idx);

			virtual IRenderGeometryBase* GetGeometryByIndex(UInt idx);

			virtual void FrameDrawed(Scene::ICameraBase* camera);

			virtual int GetNumDisplayObjects(void) const;

		private:
			void* library;
			Gapi::IDeviceBase* device;

			typedef std::map<std::string, IMaterialBase*> IMaterialMap;
			IMaterialMap _materials;

			std::vector<IRenderGeometryBase*> renderGeometries;
			int _numDisplayObjects;

			Scene::IRenderableBase* renderableComponent;


			RenderLineDebug* _lineDebug;
			//std::vector<GUI::IFontBase*> _fonts;
			GUI::IFontManagerBase* _fontManager;
		};
	}
}

#endif // RENDERSYSTEM_H