#include "../Inc/Font.h"

namespace GUI
{
	PFNGLACTIVETEXTUREPROC Font::glActiveTextureARB = NULL;

	/// <summary>Конструктор класса.</summary>
	Font::Font(void)
	{
		numVertices = 64;
		numIndices = 96;
		
		offset = 0;

		LOAD_EXTENSION(PFNGLACTIVETEXTUREPROC, glActiveTextureARB);
	}

	/// <summary>Деструктор класса.</summary>
	Font::~Font(void)
	{
		Destroy();
	}

	void Font::Create(const char* path)
	{
		gapiLibrary = LoadLibrary("GapiOpenGL_Win32_Debug");

		typedef Gapi::IShaderBase* ShaderCallback(void);
		shader = reinterpret_cast<ShaderCallback*>(GetProcAddress((HMODULE)gapiLibrary, "RegisterShaderProgram"))();
		if (shader->Create())
		{
			std::vector<UInt> shaders;
			shaders.push_back(shader->Compile(Gapi::SHADERTYPES::EST_VERTEX, shader->Load("../../../Assets/Shaders/gui_basic.vs").c_str()));
			shaders.push_back(shader->Compile(Gapi::SHADERTYPES::EST_FRAGMENT, shader->Load("../../../Assets/Shaders/gui_basic.fs").c_str()));

			shader->Attach(shaders);
			shader->Link();
			shader->Validate();
		}

		/* Инициализация библиотеки. */
		if (freeTypeError = FT_Init_FreeType(&freeTypeLibrary))
			std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

		/* Загружаем файл шрифта. */
		if (freeTypeError = FT_New_Face(freeTypeLibrary, path, 0, &freeTypeFace))
			std::cout << "ERROR::FREETYPE: Error loading font %s\n" << path <<  std::endl;

		freeTypeError = FT_Set_Pixel_Sizes(freeTypeFace, 0, 48);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		PFONT_CHARACTER fontCharacter = (PFONT_CHARACTER)malloc(sizeof(LFONT_CHARACTER));

		FT_GlyphSlot freeTypeGlyphSlot;
		FT_Bitmap freeTypeBitmap;

		UInt glyphWidth;
		UInt glyphHeight;

		for (UInt charCode = 0; charCode < 128; charCode++)
		{
			if (FT_Load_Char(freeTypeFace, charCode, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
				continue;
			}

			freeTypeGlyphSlot = freeTypeFace->glyph;
			freeTypeBitmap = freeTypeGlyphSlot->bitmap;

			glyphWidth = freeTypeBitmap.width;
			glyphHeight = freeTypeBitmap.rows;

			GLuint texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, glyphWidth, glyphHeight, 0, GL_RED, GL_UNSIGNED_BYTE, freeTypeBitmap.buffer);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			LFONT_CHARACTER character = {
				texture,
				Math::Vector2(glyphWidth, glyphHeight),
				Math::Vector2(freeTypeGlyphSlot->bitmap_left, freeTypeGlyphSlot->bitmap_top),
				freeTypeGlyphSlot->advance.x
			};
			Characters.insert(std::pair<char, LFONT_CHARACTER>(charCode, character));
		}

		glBindTexture(GL_TEXTURE_2D, 0);

		FT_Done_Face(freeTypeFace);
		FT_Done_FreeType(freeTypeLibrary);


		Gapi::LVERTEX_ELEMENT_DESC elementDesc[] = {
			{ 0, Gapi::VERTEXELEMENTTYPES::EVET_POSITION, Gapi::VERTEXELEMENTFORMATS::EVEF_FLOAT },
			{ 0, Gapi::VERTEXELEMENTTYPES::EVET_TEXCOORD, Gapi::VERTEXELEMENTFORMATS::EVEF_FLOAT }
		};

		typedef Gapi::IBufferBase* VertexBufferCallback(void);
		vertexBuffer = reinterpret_cast<VertexBufferCallback*>(GetProcAddress((HMODULE)gapiLibrary, "RegisterBuffer"))();
		vertexBuffer->SetVertexDeclaration(elementDesc, 2);
		vertexBuffer->CreateArray(Gapi::BUFFERTYPES::EBT_VERTEX, sizeof(Math::LVERTEX_TEXCOORD), 6, Gapi::BUFFER_USAGES::EBU_DYNAMIC);
	}

	void Font::Destroy(void)
	{
		if (freeTypeFace)
		{
			FT_Done_Face(freeTypeFace);
			freeTypeFace = 0;
		}

		if (freeTypeLibrary)
		{
			FT_Done_FreeType(freeTypeLibrary);
			freeTypeLibrary = 0;
		}
	}

	void Font::Draw2DText(std::string text, UInt positionX, UInt positionY, float scale, Math::Vector3 color)
	{
		glFrontFace(GL_CW);

		Math::Matrix4 projectionMatrix;
		projectionMatrix.OrthoOffCenter(0, 0, 800, 600, 0.0f, 1.0f);

		shader->Bind();
		int projectionMatrixUniformLocation = shader->GetUniformLocation("projection");
		shader->SetUniformMatrix4(projectionMatrixUniformLocation, false, &projectionMatrix);

		int	textColorUniformLocation = shader->GetUniformLocation("textColor");
		shader->SetUniform4f(textColorUniformLocation, color._x, color._y, color._z, 1.0f);

		glActiveTextureARB(GL_TEXTURE0);

		vertexBuffer->BindVertexArray();

		for (std::string::const_iterator c = text.begin(); c != text.end(); c++)
		{
			LFONT_CHARACTER ch = Characters[*c];

			GLfloat xpos = positionX + ch.bearing._x * scale;
			GLfloat ypos = positionY - (ch.size._y - ch.bearing._y) * scale;

			GLfloat w = ch.size._x * scale;
			GLfloat h = ch.size._y * scale;

			GLfloat vertices[6][5] = {
				{ xpos,     ypos + h, 0.0, 0.0, 0.0 },
				{ xpos,     ypos,     0.0, 0.0, 1.0 },
				{ xpos + w, ypos,     0.0, 1.0, 1.0 },

				{ xpos,     ypos + h, 0.0, 0.0, 0.0 },
				{ xpos + w, ypos,     0.0, 1.0, 1.0 },
				{ xpos + w, ypos + h, 0.0, 1.0, 0.0 }
			};

			glBindTexture(GL_TEXTURE_2D, ch.textureID);

			vertexBuffer->SetData(&vertices);
			vertexBuffer->RenderW(Gapi::PRIMITIVETYPES::EPT_TRIANGLELIST, NULL, 6, shader->GetShaderProgram());

			positionX += (ch.advance >> 6) * scale;
		}

		vertexBuffer->UnbindVertexArray();
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	CORE_API IFontBase* RegisterTTFont(void)
	{
		return new Font();
	}
}