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

	void RenderQueue::AddRenderable(Core::Render::IRenderGeometryBase* geometry, UInt groupId, UInt priority)
	{
		//Core::Render::IRenderGeometryBase* geometry = NULL;
		//geometry = new Core::Render::RenderGeometry(renderable);
		//geometry->BuildVBOs(library);

		renderGeometries.push_back(geometry);
	}

	void RenderQueue::PreRender(void)
	{
	}

	void RenderQueue::Render(UInt shaderProgram)
	{
		for (UInt i = 0; i < renderGeometries.size(); ++i)
		{
			//renderGeometries[i]->Draw(shaderProgram);
		}
	}

	void RenderQueue::PostRender(void)
	{
	}
}