#include "../../../Core/Inc/Scene/Shape.h"

namespace Scene
{
	/** Constructor. */
	Shape::Shape(Render::IRenderSystemBase* render, const LGEOMETRYPACKET& packet)
		: renderSystem(render)
	{
		SetGeometryPacket(packet);
		renderSystem->CreateBuffer(this);
	}

	/** Destructor. */
	Shape::~Shape() {}
}