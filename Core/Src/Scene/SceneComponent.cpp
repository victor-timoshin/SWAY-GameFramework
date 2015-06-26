#include "../../../Core/Inc/Scene/SceneComponent.h"

namespace Scene
{
	/** Constructor. */
	SceneComponent::SceneComponent()
		: attachedSceneNode(0L) {}

	/** Destructor. */
	SceneComponent::~SceneComponent() {}

	void SceneComponent::Notify(ISceneNodeBase* sceneNode)
	{
		attachedSceneNode = sceneNode;
	}

	ISceneNodeBase* SceneComponent::GetSceneNode()
	{
		return attachedSceneNode;
	}

	const LATTRIBUTEPACKET& SceneComponent::GetAttributePacket() const
	{
		return attributePacket;
	}

	void SceneComponent::SetAttributePacket(const LATTRIBUTEPACKET& packet)
	{
		attributePacket = packet;
	}

	const LGEOMETRYPACKET& SceneComponent::GetGeometryPacket() const
	{
		return geometryPacket;
	}

	void SceneComponent::SetGeometryPacket(const LGEOMETRYPACKET& packet)
	{
		geometryPacket = packet;
	}

	ISceneComponentBase* RegisterSceneComponent()
	{
		return new SceneComponent();
	}
}