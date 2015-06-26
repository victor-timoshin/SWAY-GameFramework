#include "../../../Core/Inc/Scene/SceneGraph.h"
#include "../../../Core/Inc/Scene/SceneNode.h"
#include "../../../Core/Inc/Scene/Shape.h"
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

	ISceneComponentBase* SceneGraph::CreateBox(const char* name)
	{
		Core::Math::PVERTEXDIFFUSE_STRUCT vertices = new Core::Math::LVERTEXDIFFUSE_STRUCT[4];
		vertices[0] = Core::Math::VertexDiffuse(Core::Math::Vector3( 0.0f,  0.1f, 0.5f), Core::Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));
		vertices[1] = Core::Math::VertexDiffuse(Core::Math::Vector3( 0.5f, -0.5f, 0.5f), Core::Math::Vector4(255.0f, 0.0f, 255.0f, 255.0f));
		vertices[2] = Core::Math::VertexDiffuse(Core::Math::Vector3(-0.5f, -0.5f, 0.0f), Core::Math::Vector4(255.0f, 255.0f, 0.0f, 255.0f));
		vertices[3] = Core::Math::VertexDiffuse(Core::Math::Vector3( 0.5f,  0.5f, 0.0f), Core::Math::Vector4(0.0f, 255.0f, 255.0f, 255.0f));

		UInt16* indices = new UInt16[6];
		indices[0] = 0; indices[1] = 1; indices[2] = 2;
		indices[3] = 2; indices[4] = 1; indices[5] = 3;

		LGEOMETRYPACKET prefab;
		prefab.vertices = vertices;
		prefab.indices = indices;
		prefab.numVertices = 4;
		prefab.numIndices = 6;
		prefab.numPrimitives = 0;
		prefab.primitiveType = Gapi::TYPE_TRIANGLELIST;

		ISceneComponentBase* component = 0L;
		component = new Shape(renderSystem, prefab);
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