#include "../../../Core/Inc/Scene/SceneComponent.h"
#include "../../../SDK/Core/Scene/SceneNodeBase.h"

namespace Scene
{
	/** Constructor. */
	SceneComponent::SceneComponent(void)
		: attachedSceneNode(0L) {}

	void SceneComponent::Notify(ISceneNodeBase* sceneNode)
	{
		attachedSceneNode = sceneNode;
	}

	ISceneNodeBase* SceneComponent::GetSceneNode()
	{
		return attachedSceneNode;
	}

	LATTRIBUTEPACKET SceneComponent::GetAttributePacket()
	{
		Core::Math::Matrix4 matrixWorld;
		Core::Math::BoundingVolume boundingBox;

		if (attachedSceneNode != 0L)
			matrixWorld = attachedSceneNode->GetMatrixWorldTransform();
		else
			matrixWorld.Identity();

		for (UInt i = 0; i < geometryPacket.numVertices; i++)
		{
			UInt16* vertex = &geometryPacket.vertices[i];
			Core::Math::Vector3 totalSize = Core::Math::Vector3(
				vertex[0] * matrixWorld[0][0],
				vertex[1] * matrixWorld[1][1],
				vertex[2] * matrixWorld[2][2]);

			boundingBox.AddPoint(totalSize);
		}

		attributePacket.matrixWorld = matrixWorld;
		attributePacket.boundingBox = boundingBox;

		return attributePacket;
	}

	void SceneComponent::SetAttributePacket(LATTRIBUTEPACKET packet)
	{
		attributePacket = packet;
	}

	LGEOMETRYPACKET SceneComponent::GetGeometryPacket()
	{
		return geometryPacket;
	}

	void SceneComponent::SetGeometryPacket(LGEOMETRYPACKET packet)
	{
		geometryPacket = packet;
	}

	ISceneComponentBase* RegisterSceneComponent()
	{
		return new SceneComponent();
	}
}