#include "../Inc/SceneComponent.h"
#include "../../SDK/SceneGraph/SceneNodeBase.h"

namespace Scene
{
	/// <summary>Конструктор класса.</summary>
	SceneComponent::SceneComponent(void)
		: attachedSceneNode(NULL)
	{
	}

	void SceneComponent::Notify(ISceneNodeBase* sceneNode)
	{
		attachedSceneNode = sceneNode;
	}

	ISceneNodeBase* SceneComponent::GetSceneNode(void)
	{
		return attachedSceneNode;
	}

	LATTRIBUTEPACKET SceneComponent::GetAttributePacket(void)
	{
		Math::Matrix4 worldMatrix;
		Math::BoundingVolume boundingBox;

		if (attachedSceneNode != NULL)
			worldMatrix = attachedSceneNode->GetWorldMatrixTransform();
		else
			worldMatrix.Identity();

		for (UInt i = 0; i < geometryPacket.numVertices; i++)
		{
			float* vertices = &geometryPacket.vertices[i];
			Math::Vector3 totalSize = Math::Vector3(
				vertices[0] * worldMatrix[0][0],
				vertices[1] * worldMatrix[1][1],
				vertices[2] * worldMatrix[2][2]);

			boundingBox.AddPoint(totalSize);
		}

		attributePacket.modelMatrix = worldMatrix;
		attributePacket.boundingBox = boundingBox;

		return attributePacket;
	}

	void SceneComponent::SetAttributePacket(LATTRIBUTEPACKET packet)
	{
		attributePacket = packet;
	}

	LGEOMETRYPACKET SceneComponent::GetGeometryPacket(void)
	{
		return geometryPacket;
	}

	void SceneComponent::SetGeometryPacket(LGEOMETRYPACKET packet)
	{
		geometryPacket = packet;
	}

	ISceneComponentBase* RegisterSceneComponent(void)
	{
		return new SceneComponent();
	}
}