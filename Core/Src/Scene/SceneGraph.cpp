#include "../../../Core/Inc/Scene/SceneGraph.h"
#include "../../../Core/Inc/Scene/SceneNode.h"
#include "../../../Core/Inc/Scene/Shape.h"
#include "../../../Core/Inc/Scene/UniversalCamera.h"
#include "../../../Core/Inc/Render/RenderGeometryUtils.h"
#include "../../../SDK/Gapi/Types.h"

namespace Scene
{
	/** Constructor. */
	SceneGraph::SceneGraph(Render::IRenderSystemBase* render) : ISceneGraphBase(render)
		, renderSystem(render)
	{
		rootSceneNode = new SceneNode("RootSceneNode");
	}

	/** Destructor. */
	SceneGraph::~SceneGraph()
	{
		SAFE_DELETE(rootSceneNode);
	}

	ICameraBase* SceneGraph::CreateCamera(const char* name)
	{
		if (cameras.find(name) != cameras.end()) {}

		ICameraBase* camera = new UniversalCamera(name);
		cameras.insert(ICameraMap::value_type(name, camera));

		if (activeCamera == 0L)
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

	ICameraBase* SceneGraph::GetActiveCamera()
	{
		return activeCamera;
	}

	ISceneComponentBase* SceneGraph::CreateSprite(const char* name)
	{
		ISceneComponentBase* component = 0L;
		component = new Shape(renderSystem, Core::RenderGeometryUtils::GetPrefabPlane());
		component->SetComponentName(name);

		return component;
	}

	ISceneComponentBase* SceneGraph::CreateBox(const char* name)
	{
		ISceneComponentBase* component = 0L;
		component = new Shape(renderSystem, Core::RenderGeometryUtils::GetPrefabBox());
		component->SetComponentName(name);

		return component;
	}

	ISceneComponentBase* SceneGraph::CreateSphere(const char* name)
	{
		ISceneComponentBase* component = 0L;
		component = new Shape(renderSystem, Core::RenderGeometryUtils::GetPrefabSphere(8, 8));
		component->SetComponentName(name);

		return component;
	}

	void SceneGraph::Clear()
	{
		rootSceneNode->RemoveAll();
	}

	ISceneNodeBase* SceneGraph::GetRootSceneNode()
	{
		return rootSceneNode;
	}

	ISceneGraphBase* RegisterSceneGraph(Render::IRenderSystemBase* render)
	{
		return new SceneGraph(render);
	}
}