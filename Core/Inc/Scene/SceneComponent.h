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
		SceneComponent(void);

		/** Destructor. */
		virtual ~SceneComponent(void) { }

		virtual void Notify(ISceneNodeBase* sceneNode);

		virtual ISceneNodeBase* GetSceneNode();

		virtual LATTRIBUTEPACKET GetAttributePacket();

		virtual void SetAttributePacket(LATTRIBUTEPACKET packet);

		virtual LGEOMETRYPACKET GetGeometryPacket();

		virtual void SetGeometryPacket(LGEOMETRYPACKET packet);

	private:
		ISceneNodeBase* attachedSceneNode;

		LATTRIBUTEPACKET attributePacket;
		LGEOMETRYPACKET geometryPacket;
	};
}

#endif // SCENE_COMPONENT_H