#ifndef RENDERQUEUE_H
#define RENDERQUEUE_H

#include "../../../SDK/Core/Render/RenderGeometryBase.h"
#include "../../../SDK/Platform.h"

namespace Render
{
	class RenderQueue
	{
	public:
		/// <summary>Конструктор класса.</summary>
		RenderQueue(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~RenderQueue(void);

		virtual void AddRenderable(Core::Render::IRenderGeometryBase* geometry, UInt groupId, UInt priority);

		virtual void PreRender(void);

		virtual void Render(UInt shaderProgram);

		virtual void PostRender(void);

	private:
		std::vector<Core::Render::IRenderGeometryBase*> renderGeometries;
	};
}

#endif // RENDERQUEUE_H