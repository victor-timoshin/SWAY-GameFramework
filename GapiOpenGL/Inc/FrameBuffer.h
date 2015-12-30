#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "../../SDK/Gapi/FrameBufferBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class FrameBuffer : public IFrameBufferBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		FrameBuffer(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~FrameBuffer(void);

		virtual void Create(ITextureBase* texture);

		virtual void Destroy(void);

		virtual void Bind(void);

		virtual void Unbind(void);

	private:
		UInt _frameBufferID;
		UInt _renderBufferID;
	};
}

#endif // FRAMEBUFFER_H