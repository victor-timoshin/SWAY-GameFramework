#ifndef FONTBASE_H
#define FONTBASE_H

#include "../../SDK/Platform.h"

namespace Gapi
{
	class IFontBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IFontBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IFontBase(void) {}

		virtual void Create(HWND handle) = 0;

		virtual void Destroy(void) = 0;

		virtual void DrawString(int x, int y, const char * string, ...) = 0;

		virtual void StartTextMode(int width, int height) = 0;

		virtual void EndTextMode(void) = 0;
	};

	CORE_API IFontBase* RegisterFont(void);
}

#endif // FONTBASE_H