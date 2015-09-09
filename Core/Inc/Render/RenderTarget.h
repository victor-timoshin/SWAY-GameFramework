#ifndef RENDERTARGET_H
#define RENDERTARGET_H

#include "../../../SDK/Platform.h"

namespace Render
{
	class RenderTarget
	{
	public:
		/// <summary>Конструктор класса.</summary>
		RenderTarget(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~RenderTarget(void);
	};
}

#endif // RENDERTARGET_H