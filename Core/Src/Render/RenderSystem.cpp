#include "../../../Core/Inc/Render/RenderSystem.h"
#include "../../../Core/Inc/Render/Material.h"
#include "../../../Core/Inc/Render/RenderGeometry.h"
#include "../../../Core/Inc/Utils/StreamLogger.h"
#include "../../../SDK/Core/Scene/RenderableBase.h"
#include "../../../Math/Inc/Frustum.h"

namespace Render
{
	/// <summary>Конструктор класса.</summary>
	RenderSystem::RenderSystem(void)
		: device(NULL)
	{
		font = NULL;
	}

	/// <summary>Деструктор класса.</summary>
	RenderSystem::~RenderSystem(void)
	{
		SAFE_DELETE(material);
		SAFE_DELETE(device);

		FreeLibrary((HMODULE)library);
	}

	void RenderSystem::SetRenderableComponent(Scene::IRenderableBase* renderable)
	{
		renderableComponent = renderable;
		CreateBuffer(renderable);
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

		return true;
	}

	Gapi::IDeviceBase* RenderSystem::GetDevice(void)
	{
		return device;
	}

	bool RenderSystem::CreateMaterial(const char* vertexShader, const char* fragmentShader)
	{
		material = new Material(library, device);
		if (material->Create(vertexShader, fragmentShader))
			return true;

		return false;
	}

	bool RenderSystem::CreateTTFont(const char* filename)
	{
		font = GUI::RegisterTTFont();
		font->Create(filename);

		return true;
	}

	void RenderSystem::CreateBuffer(Scene::IRenderableBase* renderable)
	{
		Core::Render::IRenderGeometryBase* geometry = NULL;
		geometry = new Core::Render::RenderGeometry(renderable);
		geometry->BuildVBOs(library);

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

	Core::Render::IRenderGeometryBase* RenderSystem::GetGeometryByIndex(UInt idx)
	{
		return renderGeometries[idx];
	}

	void RenderSystem::FrameDrawed(Scene::ICameraBase* camera)
	{
		device->Clear(Gapi::CLEARFLAGS::ECF_COLOR | Gapi::CLEARFLAGS::ECF_DEPTH | Gapi::CLEARFLAGS::ECF_STENCIL);
		device->SetClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		if (camera != NULL)
		{
			Math::Frustum frustum;
			frustum.Generate(camera->GetViewMatrix(), camera->GetProjectionMatrix());

			numDisplayObjects = 0;
			for (UInt currentGeometry = 0; currentGeometry < renderGeometries.size(); ++currentGeometry)
			{
				Scene::IRenderableBase* renderable = renderGeometries[currentGeometry]->GetRenderableComponent();
				Scene::LATTRIBUTEPACKET attributes = renderable->GetAttributePacket();

				int modelMatrixUniformLocation = static_cast<Material*>(material)->GetShader()->GetUniformLocation("ModelMatrix");
				int viewMatrixUniformLocation = static_cast<Material*>(material)->GetShader()->GetUniformLocation("ViewMatrix");
				int projectionMatrixUniformLocation = static_cast<Material*>(material)->GetShader()->GetUniformLocation("ProjectionMatrix");

				static_cast<Material*>(material)->GetShader()->Bind();

				static_cast<Material*>(material)->GetShader()->SetUniformMatrix4(modelMatrixUniformLocation, true, &attributes.modelMatrix);
				static_cast<Material*>(material)->GetShader()->SetUniformMatrix4(viewMatrixUniformLocation, true, &camera->GetViewMatrix());
				static_cast<Material*>(material)->GetShader()->SetUniformMatrix4(projectionMatrixUniformLocation, true, &camera->GetProjectionMatrix());

				if (frustum.ContainsBoundingVolume(attributes.boundingBox,
					Math::Vector3(attributes.modelMatrix[3][0], attributes.modelMatrix[3][1], attributes.modelMatrix[3][2])))
				{
					renderGeometries[currentGeometry]->Draw();
					numDisplayObjects += 1;
				}

				static_cast<Material*>(material)->GetShader()->Unbind();
			}
		}

		if (font != NULL)
		{
			font->Draw2DText("Hello", 250.0f, 250.0f, 1.0f, Math::Vector3(1.0f, 1.0f, 1.0f));
		}

		device->SwapChain();
	}

	IRenderSystemBase* RegisterRenderSystem(void)
	{
		return new RenderSystem();
	}
}