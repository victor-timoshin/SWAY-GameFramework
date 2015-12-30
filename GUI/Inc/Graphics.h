#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../../SDK/Gapi/BufferBase.h"
#include "../../SDK/Gapi/ShaderBase.h"
#include "../../SDK/Gapi/ShaderBase.h"
#include "../../SDK/Gapi/TextureBase.h"
#include "../../SDK/Platform.h"

#include "../StdAfx.h"

namespace GUI
{
	class Graphics
	{
	public:
		static PFNGLACTIVETEXTUREPROC glActiveTextureARB;

		/// <summary>Конструктор класса.</summary>
		Graphics(void);

		/// <summary>Деструктор класса.</summary>
		~Graphics(void);

		void Create(void);

		UInt MakeTexture(UInt width, UInt height, const void* pixels);

		void PreRender(const Math::Color& color);

		void Render(void* data, UInt textureID);

		void PostRender(void);

	private:
		Gapi::IBufferBase* _vertexBuffer;
		Gapi::IBufferBase* _indexBuffer;
		Gapi::IShaderBase* _shader;
		Gapi::ITextureBase* _texture;
	};
}

#endif // GRAPHICS_H