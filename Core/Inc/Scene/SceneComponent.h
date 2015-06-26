#ifndef SCENE_COMPONENT_H
#define SCENE_COMPONENT_H

#include "../../../SDK/Core/Scene/SceneComponentBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class SceneComponent : public ISceneComponentBase
	{
	public:
		/** Constructor. */
		SceneComponent();

		/** Destructor. */
		virtual ~SceneComponent();

		virtual void Notify(ISceneNodeBase* sceneNode);

		virtual ISceneNodeBase* GetSceneNode();

		virtual const LATTRIBUTEPACKET& GetAttributePacket() const;

		virtual void SetAttributePacket(const LATTRIBUTEPACKET& packet);

		virtual const LGEOMETRYPACKET& GetGeometryPacket() const;

		virtual void SetGeometryPacket(const LGEOMETRYPACKET& packet);

	private:
		ISceneNodeBase* attachedSceneNode;

		LATTRIBUTEPACKET attributePacket;
		LGEOMETRYPACKET geometryPacket;
	};
}

#endif // SCENE_COMPONENT_H