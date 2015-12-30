#include "../../../Core/Inc/Render/RenderSystem.h"
#include "../../../Core/Inc/Render/Material.h"
#include "../../../Core/Inc/Render/RenderGeometry.h"
#include "../../../Core/Inc/Utils/StreamLogger.h"
#include "../../../SDK/Core/Scene/RenderableBase.h"
#include "../../../Math/Inc/Frustum.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		RenderSystem::RenderSystem(void)
			: device(nullptr)
		{
		}

		/// <summary>Деструктор класса.</summary>
		RenderSystem::~RenderSystem(void)
		{
			SAFE_DELETE(device);

			for (IMaterialMap::iterator i = _materials.begin(); i != _materials.end(); ++i)
			{
				IMaterialBase* Object = i->second;
				delete Object;
			}

			_materials.clear();

			FreeLibrary((HMODULE)library);

			_fontManager->RemoveFont();
			SAFE_DELETE(_fontManager);
		}

		void RenderSystem::SetRenderableComponent(Scene::IRenderableBase* renderable, IMaterialBase* material)
		{
			renderableComponent = renderable;
			CreateBuffer(renderable, material);
		}

		bool RenderSystem::Initialize(const char* libraryName)
		{
			library = LoadLibrary(libraryName/*.dll*/);
			if (!library)
				return false;

			return true;
		}

		bool RenderSystem::CreateDevice(HWND windowHandle)
		{
			typedef Gapi::IDeviceBase* IDeviceCallback(HWND);
			device = reinterpret_cast<IDeviceCallback*>(GetProcAddress((HMODULE)library, "RegisterDevice"))(windowHandle);
			if (!device->Create())
				return false;

			_fontManager = GUI::RegisterFontManager();

			std::ofstream stream;
			stream.open("info.txt", std::ios::out);
			device->GetGlInfo(stream);

			_lineDebug = new RenderLineDebug(library);

			return true;
		}

		Gapi::IDeviceBase* RenderSystem::GetDevice(void)
		{
			return device;
		}

		bool RenderSystem::CreateMaterial(const char* name, const char* vertexShader, const char* fragmentShader, const char* textureName)
		{
			Material* material = new Material(library, device);
			if (material->Create(vertexShader, fragmentShader, textureName))
			{
				_materials.insert(IMaterialMap::value_type(name, material));
				return true;
			}

			return false;
		}

		IMaterialBase* RenderSystem::GetMaterialByName(const char* name)
		{
			IMaterialMap::iterator i = _materials.find(name);
			if (i != _materials.end())
				return i->second;

			return nullptr;
		}

		GUI::IFontBase* RenderSystem::CreateTTFont(const char* name, const char* filename)
		{
			return _fontManager->AddFont(name, filename);
		}

		GUI::IFontBase* RenderSystem::GetTTFont(std::string name)
		{
			return _fontManager->Find(name);
		}

		void RenderSystem::CreateBuffer(Scene::IRenderableBase* renderable, IMaterialBase* material)
		{
			Core::Render::IRenderGeometryBase* geometry = nullptr;
			geometry = new Core::Render::RenderGeometry(renderable);
			geometry->BuildVBOs(library);
			geometry->SetMaterial(material);

			renderGeometries.push_back(geometry);
		}

		void RenderSystem::RemoveBuffer(UInt idx)
		{
			std::vector<Core::Render::IRenderGeometryBase*>::iterator i = renderGeometries.begin();
			while (i != renderGeometries.end())
			{
				if ((*i)->GetInstanceId() == idx)
				{
					SAFE_DELETE(*i);
					i = renderGeometries.erase(i);
				}
				else ++i;
			}
		}

		IRenderGeometryBase* RenderSystem::GetGeometryByIndex(UInt idx)
		{
			return renderGeometries[idx];
		}

		void RenderSystem::FrameDrawed(Scene::ICameraBase* camera)
		{
			_numDisplayObjects = 0;

			device->Clear(Gapi::CLEARFLAG::Color | Gapi::CLEARFLAG::Depth | Gapi::CLEARFLAG::Stencil);
			device->SetClearColor(0.0f, 0.0f, 0.0f, 0.0f);

			if (camera != nullptr)
			{
				for (UInt currentGeometry = 0; currentGeometry < renderGeometries.size(); ++currentGeometry)
				{
					Scene::IRenderableBase* renderable = renderGeometries[currentGeometry]->GetRenderableComponent();
					Scene::LATTRIBUTE_PACKET attributePacket = renderable->GetAttributePacket();

					if (camera->IsVisible(attributePacket.aabb))
					{
						static_cast<RenderGeometry*>(renderGeometries[currentGeometry])->SetDebugLines(_lineDebug);
						renderGeometries[currentGeometry]->Draw(camera);
						_numDisplayObjects += 1;
					}
				}

				_lineDebug->DrawFrustum(camera->GetFrustum(), 0.0f, 0.0f, 0.0f, 0.0f);

				Math::Matrix4F lineDebugMatrix;
				lineDebugMatrix.SetIdentity();

				int modelMatrixLocation = _lineDebug->GetShader()->GetUniformLocation("ModelMatrix");
				int viewMatrixLocation = _lineDebug->GetShader()->GetUniformLocation("ViewMatrix");
				int projectionMatrixLocation = _lineDebug->GetShader()->GetUniformLocation("ProjectionMatrix");

				_lineDebug->GetShader()->Bind();
				_lineDebug->GetShader()->SetUniformMatrix4(modelMatrixLocation, true, &lineDebugMatrix);
				_lineDebug->GetShader()->SetUniformMatrix4(viewMatrixLocation, true, &camera->GetViewMatrix());
				_lineDebug->GetShader()->SetUniformMatrix4(projectionMatrixLocation, true, &camera->GetProjectionMatrix());
				_lineDebug->Draw();
				_lineDebug->GetShader()->Unbind();
			}

			_fontManager->DrawAll();

			device->SwapChain();
		}

		int RenderSystem::GetNumDisplayObjects(void) const
		{
			return _numDisplayObjects;
		}

		IRenderSystemBase* RegisterRenderSystem(void)
		{
			return new RenderSystem();
		}
	}
}