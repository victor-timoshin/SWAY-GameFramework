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
		: _activeCamera(nullptr)
	{
		_rootSceneNode = new SceneNode("root");
	}

	/// <summary>Деструктор класса.</summary>
	SceneGraph::~SceneGraph(void)
	{
		SAFE_DELETE(_rootSceneNode);
	}

	ISceneNodeBase* SceneGraph::GetRootSceneNode(void)
	{
		return _rootSceneNode;
	}

	ICameraBase* SceneGraph::CreateCamera(const char* name)
	{
		if (_cameras.find(name) != _cameras.end())
		{
		}

		ICameraBase* camera = new Camera(name);
		_cameras.insert(ICameraMap::value_type(name, camera));

		if (_activeCamera == nullptr)
			_activeCamera = camera;

		return camera;
	}

	void SceneGraph::DestroyCamera(const char* name)
	{
		ICameraMap::iterator i = _cameras.find(name);
		if (i != _cameras.end())
		{
			SAFE_DELETE(i->second);
			_cameras.erase(i);
		}
	}

	/// <summary>Устанавливает активную камеру.</summary>
	void SceneGraph::SetActiveCamera(ICameraBase* camera)
	{
		_activeCamera = camera;
	}

	/// <summary>Устанавливает активную камеру по имени.</summary>
	/// <param name="name">Имя камеры.</param>
	void SceneGraph::SetActiveCameraByName(const char* name)
	{
		ICameraMap::iterator i = _cameras.find(name);
		if (i != _cameras.end())
			_activeCamera = i->second;
	}

	/// <summary>Получает указатель на активную камеру.</summary>
	ICameraBase* SceneGraph::GetActiveCamera(void)
	{
		return _activeCamera;
	}

	/// <summary>Получает число камер в сцене.</summary>
	int SceneGraph::GetCameraCount(void) const
	{
		return _cameras.size();
	}

	/// <summary>Создает спрайт.</summary>
	/// <param name="name">Имя спрайта.</param>
	ISceneComponentBase* SceneGraph::CreateSprite(const char* name)
	{
		ISceneComponentBase* component = nullptr;
		component = new SceneComponent();
		component->SetGeometryPacket(Core::RenderGeometryUtils::GetPrefabPlane());
		component->SetComponentName(name);

		renderables.push_back(component);
		return component;
	}

	ISceneComponentBase* SceneGraph::CreateBox(const char* name)
	{
		ISceneComponentBase* component = nullptr;
		component = new SceneComponent();
		component->SetGeometryPacket(Core::RenderGeometryUtils::GetPrefabBox());
		component->SetComponentName(name);

		renderables.push_back(component);
		return component;
	}

	ISceneComponentBase* SceneGraph::CreateSphere(const char* name)
	{
		ISceneComponentBase* component = nullptr;
		component = new SceneComponent();
		component->SetGeometryPacket(Core::RenderGeometryUtils::GetPrefabSphere(8, 8));
		component->SetComponentName(name);

		renderables.push_back(component);
		return component;
	}

	void SceneGraph::Update(void)
	{
		_rootSceneNode->CascadeUpdate();
	}

	/// <summary>Полностью очищает сцену.</summary>
	void SceneGraph::Clear(void)
	{
		_rootSceneNode->RemoveAll();
	}

	ISceneGraphBase* RegisterSceneGraph(void)
	{
		return new SceneGraph();
	}
}