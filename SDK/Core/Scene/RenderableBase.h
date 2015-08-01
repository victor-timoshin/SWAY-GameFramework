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
		/// <summary>����������� ������.</summary>
		IRenderableBase(void) {}

		/// <summary>���������� ������.</summary>
		virtual ~IRenderableBase(void) {}

		virtual LATTRIBUTEPACKET GetAttributePacket(void) = 0;

		virtual void SetAttributePacket(LATTRIBUTEPACKET packet) = 0;

		virtual LGEOMETRYPACKET GetGeometryPacket(void) = 0;

		virtual void SetGeometryPacket(LGEOMETRYPACKET packet) = 0;
	};
}

#endif // RENDERABLEBASE_H