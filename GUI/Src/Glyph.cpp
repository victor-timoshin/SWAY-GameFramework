#include "../Inc/Glyph.h"

namespace GUI
{
	/// <summary>Конструктор класса.</summary>
	Glyph::Glyph(FT_Library& library, FT_Face face, FT_ULong charcode, bool hinting, int outlineThickness)
		: _glyph(nullptr)
		, _stroker(nullptr)
	{
		Load(library, face, charcode, hinting);

		if (outlineThickness > 0)
			SetOutline(library, outlineThickness);
	}

	/// <summary>Деструктор класса.</summary>
	Glyph::~Glyph(void)
	{
		if (_stroker)
		{
			FT_Stroker_Done(_stroker);
			_stroker = nullptr;
		}

		if (_glyph)
		{
			FT_Done_Glyph(_glyph);
			_glyph = nullptr;
		}
	}

	void Glyph::Load(FT_Library& library, FT_Face face, FT_ULong charcode, bool hinting)
	{
		int flags = FT_LOAD_DEFAULT;

		if (hinting)
			flags |= FT_LOAD_FORCE_AUTOHINT;
		else
			flags |= FT_LOAD_NO_HINTING | FT_LOAD_NO_AUTOHINT;

		_error = FT_Load_Char(face, charcode, flags);
		if (_error)
			return;

		_error = FT_Load_Glyph(face, FT_Get_Char_Index(face, charcode), flags);
		if (_error)
			return;

		_error = FT_Get_Glyph(face->glyph, &_glyph);
		if (_error)
			return;
	}

	void Glyph::SetOutline(FT_Library& library, int outlineThickness)
	{
		_error = FT_Stroker_New(library, &_stroker);
		if (_error)
			return;

		FT_Stroker_Set(_stroker, outlineThickness * 64, FT_STROKER_LINECAP_ROUND, FT_STROKER_LINEJOIN_ROUND, 0);

		_error = FT_Glyph_StrokeBorder(&_glyph, _stroker, false, true);
		if (_error)
			return;


		FT_Raster_Params params;
		memset(&params, 0, sizeof(params));

		params.target = 0;
		params.flags = FT_RASTER_FLAG_DIRECT | FT_RASTER_FLAG_AA;
		params.user = this;
		params.gray_spans = Glyph::SpanCallback;

		FT_OutlineGlyph outlineGlyph = reinterpret_cast<FT_OutlineGlyph>(_glyph);

		_error = FT_Outline_Render(library, &outlineGlyph->outline, &params);
		if (_error)
			return;
	}

	void Glyph::SpanCallback(int y, int count, const FT_Span* spans, void* user)
	{
	}

	//FT_GlyphSlot glyph = face->glyph;
	//UInt size = 1;

	//_xOffset = face->glyph->metrics.horiBearingX >> 6;
	//_yOffset = face->glyph->metrics.horiBearingY >> 6;
	//_advanceX = static_cast<float>(glyph->advance.x >> 6) / static_cast<float>(size);
	//_advanceY = static_cast<float>(glyph->advance.y >> 6) / static_cast<float>(size);
	//_bitmapLeft = static_cast<float>(glyph->bitmap_left) / static_cast<float>(size);
	//_bitmapTop = static_cast<float>(glyph->bitmap_top) / static_cast<float>(size);
	//_bitmapWidth = static_cast<float>(glyph->bitmap.width) / static_cast<float>(size);
	//_bitmapHeight = static_cast<float>(glyph->bitmap.rows) / static_cast<float>(size);
}