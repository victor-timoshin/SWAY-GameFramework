#ifndef FONT_H
#define FONT_H

#include "../../SDK/GUI/FontBase.h"
#include "../../SDK/Platform.h"

#include "Graphics.h"
#include "Glyph.h"
#include "../StdAfx.h"

namespace GUI
{
	typedef struct FontInfo
	{

	} LFONT_INFO, *PFONT_INFO;

	class Font : public IFontBase
	{
		DECL_PROPERTY_VIRTUAL_STRING(FamilyName, _familyName) // Имя шрифта.
		DECL_PROPERTY_VIRTUAL_STRING(StyleName, _styleName) // Имя стиля.
		DECL_PROPERTY_VIRTUAL_STRING(Text, _text) // Строка текста.

	public:
		/// <summary>Конструктор класса.</summary>
		Font(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Font(void);

		/// <summary>Загружает шрифт из файла.</summary>
		virtual bool LoadFromFile(FT_Library library, const char* path);

		virtual bool LoadFromMemory(FT_Library library, const UByte* memory, UInt size);

		virtual void FreeFont(void);

		virtual bool HasLoaded(void) const;

		/// <summary>Устанавливает размер.</summary>
		virtual void SetSize(int width, int height);

		virtual void Create(void);

		virtual void Destroy(void);

		virtual void SetPosition(Math::Vec2F position);

		virtual void SetPosition(float x, float y);

		virtual void SetScale(float scale);

		virtual void SetColor(const Math::Color& color);

		virtual void Draw2DText(void);

		/// <summary>Устанавливает толщину обводки символа.</summary>
		void SetOutlineThickness(UInt thickness);

		/// <summary>Получает толщину обводки символа.</summary>
		UInt GetOutlineThickness(void) const;

		FT_Face GetFace(void) const { return _face; }

	protected:
		void CopyBitmapToBufferData(FT_Bitmap& bitmap, UByte* expandedData, int imgW, unsigned w, unsigned h, int row, int col);

		UInt GetGlyphIndex(const char charcode) const;

		float GetAdvance(const char charcode) const;

		float GetOffset(const char charcode) const;

		float GetWidth(const char charcode) const;

	public:
		FT_Face _face;  // Объект для хранения шрифта.
		FT_Encoding _encoding;

		int _italic;
		int _bold;
		int _monospace;

		int _width;
		int _height;

		int _ascender;
		int _descender;
		int _maxAdvance;

		bool _isLoaded;

		Graphics* _graphics;

		std::map<UInt, LGLYPH_INFO> _glyphInfo;

		LFONT_STYLE _fontStyle;

		Math::Vec2F _position;
		float _scale;
	};
}

#endif // FONT_H