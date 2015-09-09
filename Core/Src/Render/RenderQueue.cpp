#include "../../../Core/Inc/Render/RenderQueue.h"

namespace Render
{
	/// <summary>Конструктор класса.</summary>
	RenderQueue::RenderQueue(void)
	{

	}

	/// <summary>Деструктор класса.</summary>
	RenderQueue::~RenderQueue(void)
	{
	}

	void RenderQueue::AddRenderable(Core::Render::IRenderGeometryBase* geometry, UInt groupID, UInt priority)
	{
		renderGeometries.push_back(geometry);
	}

	void RenderQueue::PreRender(void)
	{
	}

	void RenderQueue::Render(void)
	{
		for (UInt i = 0; i < renderGeometries.size(); ++i)
		{
			renderGeometries[i]->Draw();
		}
	}

	void RenderQueue::PostRender(void)
	{
	}
}