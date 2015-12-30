#ifndef FONTSTYLE_H
#define FONTSTYLE_H

#include "HorizontalAlign.h"
#include "VerticalAlign.h"

namespace GUI
{
	typedef struct FontStyle
	{
		Math::Color textColor; // Цвет текста.
		Math::Color outlineColor; // Цвет обводки.
		int outlineThickness; // Толщина обводки.
		Math::Color shadowColor; // Цвет тени.
		HORIZONTAL_ALIGN horizontalAlign; // Горизонтальное выравнивание.
		VERTICAL_ALIGN verticalAlign; // Вертикальное выравнивание.
	} LFONT_STYLE, *PFONT_STYLE;
}

#endif // FONTSTYLE_H