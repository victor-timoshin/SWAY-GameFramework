#include "../../GapiOpenGL/Inc/FrameBuffer.h"
#include "../../GapiOpenGL/Inc/Device.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

namespace Gapi
{
	/// <summary>Конструктор класса.</summary>
	FrameBuffer::FrameBuffer(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	FrameBuffer::~FrameBuffer(void)
	{
		Destroy();
	}

	void FrameBuffer::Create(ITextureBase* texture)
	{
		GL_ARB_FramebufferObject::GenFramebuffers(1, &_frameBufferID, SOURCE_LOCATION);
		GL_ARB_FramebufferObject::BindFramebuffer(GL_FRAMEBUFFER, _frameBufferID, SOURCE_LOCATION);

		GL_ARB_FramebufferObject::GenRenderbuffers(1, &_renderBufferID, SOURCE_LOCATION);
		GL_ARB_FramebufferObject::BindRenderbuffer(GL_RENDERBUFFER, _renderBufferID, SOURCE_LOCATION);

		//if (Texture::STENCIL)

		GL_ARB_FramebufferObject::RenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_STENCIL, texture->GetWidth(), texture->GetHeight(), SOURCE_LOCATION);
		
		//else

		//GL_ARB_FramebufferObject::RenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, texture->GetWidth(), texture->GetHeight(), SOURCE_LOCATION);
	
		GL_ARB_FramebufferObject::BindRenderbuffer(GL_RENDERBUFFER, 0, SOURCE_LOCATION);

		//if (Texture::DEPTH)

		GL_ARB_FramebufferObject::FramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture->GetID(), 0, SOURCE_LOCATION);
		
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);

		//else if (Texture::STENCIL)

		//GL_ARB_FramebufferObject::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->GetID(), 0, SOURCE_LOCATION);
		//GL_ARB_FramebufferObject::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _renderBufferID, SOURCE_LOCATION);
		//GL_ARB_FramebufferObject::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _renderBufferID, SOURCE_LOCATION);

		//else

		//GL_ARB_FramebufferObject::FramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->GetID(), 0, SOURCE_LOCATION);
		//GL_ARB_FramebufferObject::FramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _renderBufferID, SOURCE_LOCATION);
	
		if (GL_ARB_FramebufferObject::CheckFramebufferStatus(GL_FRAMEBUFFER, SOURCE_LOCATION) != GL_FRAMEBUFFER_COMPLETE)
		{

		}

		GL_ARB_FramebufferObject::BindFramebuffer(GL_FRAMEBUFFER, 0, SOURCE_LOCATION);
	}

	void FrameBuffer::Destroy(void)
	{
		if (GL_ARB_FramebufferObject::IsRenderbuffer(_renderBufferID))
			GL_ARB_FramebufferObject::DeleteRenderbuffers(1, &_renderBufferID);

		if (GL_ARB_FramebufferObject::IsFramebuffer(_frameBufferID))
			GL_ARB_FramebufferObject::DeleteFramebuffers(1, &_frameBufferID);
	}

	void FrameBuffer::Bind(void)
	{
		GL_ARB_FramebufferObject::BindFramebuffer(GL_FRAMEBUFFER, _frameBufferID, SOURCE_LOCATION);
	}

	void FrameBuffer::Unbind(void)
	{
		GL_ARB_FramebufferObject::BindFramebuffer(GL_FRAMEBUFFER, 0, SOURCE_LOCATION);
	}

	IFrameBufferBase* RegisterFrameBuffer(void)
	{
		return new FrameBuffer();
	}
}