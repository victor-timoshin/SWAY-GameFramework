#ifndef SCENECOMPONENT_H
#define SCENECOMPONENT_H

#include "../../SDK/SceneGraph/SceneComponentBase.h"
#include "../../SDK/Platform.h"

namespace Scene
{
	class SceneComponent : public ISceneComponentBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		SceneComponent(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~SceneComponent(void) {}

		virtual void Notify(ISceneNodeBase* sceneNode);

		virtual ISceneNodeBase* GetSceneNode(void);

		virtual LATTRIBUTEPACKET GetAttributePacket(void);

		virtual void SetAttributePacket(LATTRIBUTEPACKET packet);

		virtual LGEOMETRYPACKET GetGeometryPacket(void);

		virtual void SetGeometryPacket(LGEOMETRYPACKET packet);

	private:
		ISceneNodeBase* attachedSceneNode;

		LATTRIBUTEPACKET attributePacket;
		LGEOMETRYPACKET geometryPacket;
	};
}

#endif // SCENECOMPONENT_H