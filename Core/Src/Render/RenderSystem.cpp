#include "../../../Core/Inc/Render/RenderSystem.h"
#include "../../../Core/Inc/Render/Material.h"
#include "../../../Core/Inc/Render/MaterialManager.h"
#include "../../../Core/Inc/Render/RenderGeometry.h"
#include "../../../Core/Inc/Utils/StreamLogger.h"
#include "../../../SDK/Core/Scene/RenderableBase.h"
#include "../../../Math/Inc/Frustum.h"

#include "../../../Core/Inc/AudioProvider/AudioLoader/WAVLoader.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		RenderSystem::RenderSystem(void)
			: _device(nullptr)
		{
		}

		/// <summary>Деструктор класса.</summary>
		RenderSystem::~RenderSystem(void)
		{
			SAFE_DELETE(_audio);
			SAFE_DELETE(_device);

			SAFE_DELETE(_materialManager);

			FreeLibrary((HMODULE)_library);

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
			_library = LoadLibrary(libraryName/*.dll*/);
			if (NOT _library)
				return false;

			return true;
		}

		bool RenderSystem::CreateDevice(HWND windowHandle)
		{
			typedef Gapi::IDeviceBase* IDeviceCallback(HWND);
			_device = reinterpret_cast<IDeviceCallback*>(GetProcAddress((HMODULE)_library, "RegisterDevice"))(windowHandle);
			if (NOT _device->Create())
				return false;

			_device->EnableFeature(Gapi::FEATURE_TYPE::DepthTesting);
			_device->EnableFeature(Gapi::FEATURE_TYPE::Culling);
			_device->EnableFeature(Gapi::FEATURE_TYPE::Blending);
			_device->EnableFeature(Gapi::FEATURE_TYPE::StencilTesting);

			_device->SetCullFace(Gapi::CULL_FACE::Back);
			_device->SetFrontFace(Gapi::FRONT_FACE::CounterClockWise);
			_device->SetBlendFunction(Gapi::BLEND_FUNCTION::SourceAlpha, Gapi::BLEND_FUNCTION::OneMinusSourceAlpha);
			_device->SetDepthFunction(Gapi::COMPARE_FUNCTION::Less);
			_device->SetStencilFunction(Gapi::COMPARE_FUNCTION::Never, 0, 0xFFFFFFFF);
			_device->SetStencilOperation(Gapi::STENCIL_OPERATION::Keep, Gapi::STENCIL_OPERATION::Keep, Gapi::STENCIL_OPERATION::Keep);

			_device->SetColorMask(true, true, true, true);
			_device->SetDepthMask(true);
			_device->SetStencilMask(0xFFFFFFFF);

			_materialManager = new MaterialManager(_library, _device);

			_fontManager = GUI::RegisterFontManager();

			_lineDebug = new RenderLineDebug(_library);

			_audio = Sapi::RegisterDevice();
			_audio->Create("");

			AudioProvider::AudioLoader::WAVLoader* loader = new AudioProvider::AudioLoader::WAVLoader();

			Core::Utils::FileStream stream;
			stream.OpenStream("../../../Assets/Sounds/test.wav", Core::Utils::FILE_TYPE::Binary);

			_audioBuffer = Sapi::RegisterBuffer();
			_audioBuffer->Fill(loader->LoadFromStream(stream.GetStream()));

			_audioSound = Sapi::RegisterSound();
			_audioSound->SetALBuffer(_audioBuffer);
			_audioSound->Play();

			return true;
		}

		Gapi::IDeviceBase* RenderSystem::GetDevice(void)
		{
			return _device;
		}

		IMaterialManagerBase* RenderSystem::GetMaterialManager(void)
		{
			return _materialManager;
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
			geometry->BuildVBOs(_library);
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

			_device->SetClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			_device->Clear(Gapi::CLEAR_FLAG::Color | Gapi::CLEAR_FLAG::Depth | Gapi::CLEAR_FLAG::Stencil);

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

			_device->SwapChain();
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