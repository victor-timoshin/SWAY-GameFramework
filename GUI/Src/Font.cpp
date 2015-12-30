#include "../Inc/Font.h"

namespace GUI
{
	DEF_PROPERTY_STRING(Font, FamilyName, _familyName)
	DEF_PROPERTY_STRING(Font, StyleName, _styleName)
	DEF_PROPERTY_STRING(Font, Text, _text)

	inline int NextPowerOfTwo(int input)
	{
		int value = 1;
		while (value < input)
			value <<= 1;
		return value;
	}

	inline FT_ULong CharToFT_ULong(char c)
	{
		return static_cast<FT_ULong>(c < 0 ? static_cast<UByte>(256 + c) : static_cast<UByte>(c));
	}

	/// <summary>Конструктор класса.</summary>
	Font::Font(void)
		: _face(nullptr)
		, _encoding(FT_ENCODING_UNICODE)
		, _isLoaded(false)
		, _position(Math::Vec2F(0.0f, 0.0f))
		, _scale(1.0f)
	{
		_fontStyle.textColor = Math::Color(1.0f);
		_fontStyle.outlineThickness = 2;
	}

	/// <summary>Деструктор класса.</summary>
	Font::~Font(void)
	{
		SAFE_DELETE(_graphics);
		Destroy();
	}

	/// <summary>Загружает шрифт из файла.</summary>
	bool Font::LoadFromFile(FT_Library library, const char* path)
	{
		FT_Error error = FT_New_Face(library, path, 0, &_face);
		if (error == FT_Err_Unknown_File_Format)
		{
			std::cout << "Unsupported font file format" << std::endl;
			return false;
		}
		else if (error)
		{
			std::cout << "The font file cann't be opened %s\n" << path << std::endl;
			return false;
		}

		FT_Select_Charmap(_face, FT_ENCODING_UNICODE);
		bool isKerning = FT_HAS_KERNING(_face);

		SetFamilyName(_face->family_name);
		SetStyleName(_face->style_name);

		_italic = _face->style_flags & FT_STYLE_FLAG_ITALIC ? 1 : 0;
		_bold = _face->style_flags & FT_STYLE_FLAG_BOLD ? 1 : 0;
		_monospace = _face->face_flags & FT_FACE_FLAG_FIXED_WIDTH ? 1 : 0;

		return true;
	}

	bool Font::LoadFromMemory(FT_Library library, const UByte* memory, UInt size)
	{
		FT_Error error = FT_New_Memory_Face(library, memory, size, 0, &_face);
		return true;
	}

	void Font::FreeFont(void)
	{
		if (_face)
		{
			FT_Done_Face(_face);
			_face = 0;
		}
	}

	bool Font::HasLoaded(void) const
	{
		return _isLoaded;
	}

	/// <summary>Устанавливает размер.</summary>
	void Font::SetSize(int width, int height)
	{
		FT_Error error = FT_Set_Pixel_Sizes(_face, width, height);
		if (error)
			std::cout << "Could not set font size to %ux%u!\n" << width << height << std::endl;

		_width = width;
		_height = height;

		_ascender = _face->size->metrics.ascender / 64;
		_descender = _face->size->metrics.descender / 64;
		_maxAdvance = _face->size->metrics.max_advance / 64;
	}

	void Font::Create(void)
	{
		_graphics = new Graphics();
		_graphics->Create();

		UInt glyphWidth, glyphHeight;

		for (UInt charcode = 0; charcode < 128; charcode++)
		{
			if (FT_Load_Char(_face, charcode, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
				continue;
			}

			FT_GlyphSlot glyphSlot = _face->glyph;
			FT_Bitmap bitmap = glyphSlot->bitmap;

			glyphWidth = bitmap.width;
			glyphHeight = bitmap.rows;

			UInt textureID = _graphics->MakeTexture(glyphWidth, glyphHeight, bitmap.buffer);

			LGLYPH_INFO fontCharacter = {
				textureID,
				Math::Vector2F(bitmap.width, bitmap.rows),
				Math::Vector2F(glyphSlot->bitmap_left, glyphSlot->bitmap_top),
				glyphSlot->advance.x
			};

			_glyphInfo.insert(std::pair<char, LGLYPH_INFO>(charcode, fontCharacter));
		}

		glBindTexture(GL_TEXTURE_2D, 0);

		Destroy();
	}

	void Font::CopyBitmapToBufferData(FT_Bitmap& bitmap, UByte* expandedData, int imgW, UInt w, UInt h, int row, int col)
	{
		for (UInt j = 0; j < h; j++)
		{
			for (UInt i = 0; i < w; i++)
			{
				int r = row * h + j;
				int c = col * w + i;
				expandedData[2 * (r * imgW + c)] = 255;
				expandedData[2 * (r * imgW + c) + 1] = 
					(i >= bitmap.width || j >= bitmap.rows) ? 0 : bitmap.buffer[i + bitmap.width * (bitmap.rows - 1 - j)];
			}
		}
	}

	void Font::Destroy(void)
	{
		FreeFont();
	}

	void Font::SetPosition(Math::Vec2F position)
	{
		_position = position;
	}

	void Font::SetPosition(float x, float y)
	{
		_position = Math::Vec2F(x, y);
	}

	void Font::SetScale(float scale)
	{
		_scale = scale;
	}

	void Font::SetColor(const Math::Color& color)
	{
		_fontStyle.textColor = color;
	}

	void Font::Draw2DText(void)
	{
		Math::Vec2F tempPosition = _position;

		_graphics->PreRender(_fontStyle.textColor);

		for (std::string::const_iterator c = _text.begin(); c != _text.end(); c++)
		{
			LGLYPH_INFO ch = _glyphInfo[*c];

			float xpos = tempPosition.GetX() + ch.bearing._x * _scale;
			float ypos = tempPosition.GetY() - (ch.size.GetY() - ch.bearing._y) * _scale;

			float w = ch.size.GetX() * _scale;
			float h = ch.size.GetY() * _scale;

			GLfloat quad[6][9] = {
				{ xpos,     ypos - h, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
				{ xpos,     ypos,     0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f },
				{ xpos + w, ypos,     0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f },

				{ xpos,     ypos - h, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
				{ xpos + w, ypos,     0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f },
				{ xpos + w, ypos - h, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f }
			};

			_graphics->Render(quad, ch.textureID);

			tempPosition._x += (ch.advance >> 6) * _scale;
		}

		_graphics->PostRender();
	}

	/// <summary>Устанавливает толщину обводки символа.</summary>
	void Font::SetOutlineThickness(UInt thickness)
	{
		_fontStyle.outlineThickness = thickness;
	}

	/// <summary>Получает толщину обводки символа.</summary>
	UInt Font::GetOutlineThickness(void) const
	{
		return _fontStyle.outlineThickness;
	}

	UInt Font::GetGlyphIndex(const char charcode) const
	{
		return static_cast<UInt>(FT_Get_Char_Index(_face, charcode));
	}

	float Font::GetAdvance(const char charcode) const
	{
		FT_Load_Glyph(_face, FT_Get_Char_Index(_face, charcode), FT_LOAD_DEFAULT);
		return static_cast<float>(_face->glyph->metrics.horiAdvance >> 6);
	}

	float Font::GetOffset(const char charcode) const
	{
		FT_Load_Glyph(_face, FT_Get_Char_Index(_face, charcode), FT_LOAD_DEFAULT);
		return static_cast<float>(_face->glyph->metrics.horiBearingX >> 6);
	}

	float Font::GetWidth(const char charcode) const
	{
		FT_Load_Glyph(_face, FT_Get_Char_Index(_face, charcode), FT_LOAD_DEFAULT);
		return static_cast<float>(_face->glyph->metrics.width >> 6);
	}

	CORE_API IFontBase* RegisterTTFont(void)
	{
		return new Font();
	}
}