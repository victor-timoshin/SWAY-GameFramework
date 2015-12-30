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

		virtual LATTRIBUTE_PACKET GetAttributePacket(void);

		virtual void SetAttributePacket(LATTRIBUTE_PACKET packet);

		virtual LGEOMETRYPACKET GetGeometryPacket(void);

		virtual void SetGeometryPacket(LGEOMETRYPACKET packet);

	private:
		ISceneNodeBase* _attachedSceneNode;

		LATTRIBUTE_PACKET _attributePacket;
		LGEOMETRYPACKET _geometryPacket;
	};
}

#endif // SCENECOMPONENT_H