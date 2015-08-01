#ifndef RENDERABLEBASE_H
#define RENDERABLEBASE_H

#include "AttributePacket.h"
#include "GeometryPacket.h"
#include "../../Platform.h"

namespace Scene
{
	class IRenderableBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IRenderableBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IRenderableBase(void) {}

		virtual LATTRIBUTEPACKET GetAttributePacket(void) = 0;

		virtual void SetAttributePacket(LATTRIBUTEPACKET packet) = 0;

		virtual LGEOMETRYPACKET GetGeometryPacket(void) = 0;

		virtual void SetGeometryPacket(LGEOMETRYPACKET packet) = 0;
	};
}

#endif // RENDERABLEBASE_H