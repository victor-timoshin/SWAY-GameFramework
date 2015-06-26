#ifndef SHAPE_H
#define SHAPE_H

#include "SceneComponent.h"
#include "../../../SDK/Core/Render/RenderSystemBase.h"
#include "../../../SDK/Platform.h"

namespace Scene
{
	class Shape : public SceneComponent
	{
	public:
		/** Constructor. */
		Shape(Render::IRenderSystemBase* render, const LGEOMETRYPACKET& packet);

		/** Destructor. */
		virtual ~Shape();

	private:
		Render::IRenderSystemBase* renderSystem;
	};
}

#endif // SHAPE_H