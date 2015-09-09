#ifndef FONT_H
#define FONT_H

#include "../../SDK/GUI/FontBase.h"
#include "../../SDK/Platform.h"

#include "../../SDK/Gapi/BufferBase.h"
#include "../../SDK/Gapi/ShaderBase.h"
#include "../../SDK/Gapi/ShaderBase.h"
#include "../../SDK/Gapi/TextureBase.h"

#include "../StdAfx.h"

#include "../../SDK/Core/Scene/GeometryPacket.h"

#include "../../SDK/Core/Utils/LoggerBase.h"
#include "../../Math/Inc/Matrix4.h"

#include <gl/gl.h>
#include <gl/glu.h>

#include "../../GapiOpenGL/Inc/GL/glext.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

#pragma comment(lib, "Core_Win32_Debug")

namespace GUI
{
	typedef struct FontCharacter {
		UInt textureID;
		Math::Vector2 size;
		Math::Vector2 bearing;
		GLuint advance;
	} LFONT_CHARACTER, *PFONT_CHARACTER;

	class Font : public IFontBase
	{
	public:
		static PFNGLACTIVETEXTUREPROC glActiveTextureARB;

		/// <summary>Конструктор класса.</summary>
		Font(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Font(void);

		virtual void Create(const char* filename);

		virtual void Destroy(void);

		virtual void Draw2DText(std::string text, UInt positionX, UInt positionY, float scale, Math::Vector3 color);

	private:
		void* gapiLibrary;
		FT_Library freeTypeLibrary; // Структура для инициализации библиотеки.
		FT_Face freeTypeFace; // Шрифт, который загружается при помощи FT_Library.
		FT_Error freeTypeError;

		Gapi::IBufferBase* vertexBuffer;
		Gapi::IBufferBase* indexBuffer;
		Gapi::IShaderBase* shader;
		Gapi::ITextureBase* texture;

		std::map<char, LFONT_CHARACTER> Characters;
		GLuint VAO, VBO;

		Math::PVERTEX_TEXCOORD vertices;
		UInt offset;

		UInt numVertices;
		UInt numIndices;
	};
}

#endif // FONT_H