#ifndef FRAMEBUFFERBASE_H
#define FRAMEBUFFERBASE_H

#include "../../SDK/Gapi/TextureBase.h"
#include "../../SDK/Platform.h"

namespace Gapi
{
	class IFrameBufferBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IFrameBufferBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IFrameBufferBase(void) {}

		virtual void Create(ITextureBase* texture) = 0;

		virtual void Destroy(void) = 0;

		virtual void Bind(void) = 0;

		virtual void Unbind(void) = 0;
	};

	CORE_API IFrameBufferBase* RegisterFrameBuffer(void);
}

#endif // FRAMEBUFFERBASE_H