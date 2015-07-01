#include "../../../Core/Inc/Render/RenderSystem.h"
#include "../../../Core/Inc/Render/RenderGeometry.h"

namespace Render
{
	/** Constructor. */
	RenderSystem::RenderSystem()
		: renderDevice(0L) {}

	/** Destructor. */
	RenderSystem::~RenderSystem()
	{
		SAFE_DELETE(shader);
		SAFE_DELETE(renderDevice);
		FreeLibrary((HMODULE)library);
	}

	void RenderSystem::CreateDevice(const char* libraryName, Core::System::IWindowBase* window)
	{
		library = LoadLibrary(libraryName/*.dll*/);
		if (!library)
			return;

		typedef Gapi::IDeviceBase* FunctionCallback(Core::System::IWindowBase*);
		renderDevice = reinterpret_cast<FunctionCallback*>(GetProcAddress((HMODULE)library, "RegisterDevice"))(window);
		renderDevice->Initialize();

		typedef Gapi::IShaderBase* IShaderBaseCallback(void*);
		shader = reinterpret_cast<IShaderBaseCallback*>(GetProcAddress((HMODULE)library, "RegisterShader"))(renderDevice);
		shader->CreateFromFile(
			"../../../Assets/Shaders/basic.vs",
			"../../../Assets/Shaders/basic.fs");
	}

	void RenderSystem::CreateBuffer(Scene::ISceneComponentBase* component)
	{
		Core::Render::IRenderGeometryBase* geometry = 0L;
		geometry = new Core::Render::RenderGeometry(component, renderDevice);
		geometry->BuildVBOs(library, 0L);

		renderGeometries.push_back(geometry);
	}

	void RenderSystem::RemoveBuffer(UInt id)
	{
		std::vector<Core::Render::IRenderGeometryBase*>::iterator i = renderGeometries.begin();
		while (i != renderGeometries.end())
		{
			if ((*i)->GetInstanceId() == id)
			{
				SAFE_DELETE(*i);
				i = renderGeometries.erase(i);
			}
			else ++i;
		}
	}

	Core::Render::IRenderGeometryBase* RenderSystem::GetGeometryBy(int id)
	{
		return renderGeometries[id];
	}

	void RenderSystem::FrameDrawed(Scene::ICameraBase* camera)
	{
		renderDevice->Clear(0.0f, 0.0f, 0.0f, 0.0f);
		renderDevice->SetViewport(800, 600);

		for (UInt i = 0; i < renderGeometries.size(); ++i)
		{
			Scene::ISceneComponentBase* component = renderGeometries[i]->GetSceneComponent();
			Scene::LATTRIBUTEPACKET attributes = component->GetAttributePacket();

			shader->SetVConstantByName("matrixWorld", &attributes.matrixWorld);
			shader->SetVConstantByName("matrixView", &camera->GetMatrixView());
			shader->SetVConstantByName("matrixProjection", &camera->GetMatrixProjection());

			//if (camera->ContainsBoundingVolume(attributes.boundingBox,
			//	Core::Math::Vector3(attributes.matrixWorld[3][0], attributes.matrixWorld[3][1], attributes.matrixWorld[3][2])))
			//{
				shader->UseActiveObject();
				renderGeometries[i]->Draw();
			//}
		}

		renderDevice->Swap();
	}

	IRenderSystemBase* RegisterRenderSystem()
	{
		return new RenderSystem();
	}
}