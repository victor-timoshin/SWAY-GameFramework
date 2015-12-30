#ifndef GLYPH_H
#define GLYPH_H

#include "../../SDK/GUI/FontBase.h"
#include "../../SDK/Platform.h"
#include "../StdAfx.h"

namespace GUI
{
	typedef struct GlyphInfo
	{
		UInt textureID;
		Math::Vec2F size;
		Math::Vec2F bearing;
		//bool flipped;
		int advance;
	} LGLYPH_INFO, *PGLYPH_INFO;

	typedef struct GlyphSpan
	{
		int x, y, width, coverage;
	} LGLYPH_SPAN, PGLYPH_SPAN;

	class Glyph
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Glyph(FT_Library& library, FT_Face face, FT_ULong charcode, bool hinting, int outlineThickness);

		/// <summary>Деструктор класса.</summary>
		~Glyph(void);

		void Load(FT_Library& library, FT_Face face, FT_ULong charcode, bool hinting);

		void SetOutline(FT_Library& library, int outlineThickness);

	protected:
		static void SpanCallback(int y, int count, const FT_Span* spans, void* user);

	private:
		FT_Error _error;

		FT_Glyph _glyph;
		FT_Stroker _stroker;

		FT_Vector _position;

		float _xOffset;
		float _yOffset;
		float _advanceX;
		float _advanceY;
		float _bitmapLeft;
		float _bitmapTop;
		float _bitmapWidth;
		float _bitmapHeight;
	};

	class GlyphContainer
	{
	public:
		/// <summary>Конструктор класса.</summary>
		GlyphContainer(void)
		{
		}

		/// <summary>Деструктор класса.</summary>
		~GlyphContainer(void)
		{
		}

		void FindFontByChar(void)
		{

		}
	};
}

#endif // GLYPH_H