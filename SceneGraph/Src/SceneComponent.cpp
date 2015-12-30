#include "../Inc/SceneComponent.h"
#include "../../SDK/SceneGraph/SceneNodeBase.h"

namespace Scene
{
	/// <summary>Конструктор класса.</summary>
	SceneComponent::SceneComponent(void)
		: _attachedSceneNode(nullptr)
	{
	}

	void SceneComponent::Notify(ISceneNodeBase* sceneNode)
	{
		_attachedSceneNode = sceneNode;
	}

	ISceneNodeBase* SceneComponent::GetSceneNode(void)
	{
		return _attachedSceneNode;
	}

	LATTRIBUTE_PACKET SceneComponent::GetAttributePacket(void)
	{
		Math::Matrix4F worldMatrix;
		Math::BoundingBox aabb;

		if (_attachedSceneNode != nullptr)
			worldMatrix = _attachedSceneNode->GetWorldMatrix();
		else
			worldMatrix.SetIdentity();

		_attributePacket.modelMatrix = worldMatrix;

		for (UInt i = 0; i < _geometryPacket.numVertices; i++)
			aabb.Include(_geometryPacket.verticesEx[i].GetPosition());

		_attributePacket.aabb = aabb;
		_attributePacket.aabb.Transform(worldMatrix);

		return _attributePacket;
	}

	void SceneComponent::SetAttributePacket(LATTRIBUTE_PACKET packet)
	{
		_attributePacket = packet;
	}

	LGEOMETRYPACKET SceneComponent::GetGeometryPacket(void)
	{
		return _geometryPacket;
	}

	void SceneComponent::SetGeometryPacket(LGEOMETRYPACKET packet)
	{
		_geometryPacket = packet;
	}

	ISceneComponentBase* RegisterSceneComponent(void)
	{
		return new SceneComponent();
	}
}