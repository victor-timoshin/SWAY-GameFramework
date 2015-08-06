#include "../Inc/SceneGraph.h"
#include "../Inc/SceneNode.h"
#include "../Inc/SceneComponent.h"
#include "../Inc/Camera.h"
#include "../../Core/Inc/Render/RenderGeometryUtils.h"
#include "../../SDK/Gapi/Types.h"

namespace Scene
{
	/// <summary>Конструктор класса.</summary>
	SceneGraph::SceneGraph(void)
	{
		rootSceneNode = new SceneNode("root");
	}

	/// <summary>Деструктор класса.</summary>
	SceneGraph::~SceneGraph(void)
	{
		SAFE_DELETE(rootSceneNode);
	}

	ISceneNodeBase* SceneGraph::GetRootSceneNode(void)
	{
		return rootSceneNode;
	}

	ICameraBase* SceneGraph::CreateCamera(const char* name)
	{
		if (cameras.find(name) != cameras.end()) {}

		ICameraBase* camera = new Camera(name);
		cameras.insert(ICameraMap::value_type(name, camera));

		if (activeCamera == NULL)
			activeCamera = camera;

		return camera;
	}

	void SceneGraph::DestroyCamera(const char* name)
	{
		ICameraMap::iterator i = cameras.find(name);
		if (i != cameras.end())
		{
			SAFE_DELETE(i->second);
			cameras.erase(i);
		}
	}

	void SceneGraph::SetActiveCamera(ICameraBase* camera)
	{
		activeCamera = camera;
	}

	ICameraBase* SceneGraph::GetActiveCamera(void)
	{
		return activeCamera;
	}

	ISceneComponentBase* SceneGraph::CreateSprite(const char* name)
	{
		ISceneComponentBase* component = NULL;
		component = new SceneComponent();
		component->SetGeometryPacket(Core::RenderGeometryUtils::GetPrefabPlane());
		component->SetComponentName(name);

		renderables.push_back(component);
		return component;
	}

	ISceneComponentBase* SceneGraph::CreateBox(const char* name)
	{
		ISceneComponentBase* component = NULL;
		component = new SceneComponent();
		component->SetGeometryPacket(Core::RenderGeometryUtils::GetPrefabBox());
		component->SetComponentName(name);

		renderables.push_back(component);
		return component;
	}

	ISceneComponentBase* SceneGraph::CreateSphere(const char* name)
	{
		ISceneComponentBase* component = NULL;
		component = new SceneComponent();
		component->SetGeometryPacket(Core::RenderGeometryUtils::GetPrefabSphere(8, 8));
		component->SetComponentName(name);

		renderables.push_back(component);
		return component;
	}

	void SceneGraph::Update(void)
	{
		rootSceneNode->CascadeUpdate();
	}

	/// <summary>Полностью очищает сцену.</summary>
	void SceneGraph::Clear(void)
	{
		rootSceneNode->RemoveAll();
	}

	ISceneGraphBase* RegisterSceneGraph(void)
	{
		return new SceneGraph();
	}
}