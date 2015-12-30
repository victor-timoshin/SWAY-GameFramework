#ifndef FONTMANAGERBASE_H
#define FONTMANAGERBASE_H

#include "../Platform.h"
#include "FontBase.h"

namespace GUI
{
	class IFontManagerBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IFontManagerBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IFontManagerBase(void) {}

		virtual IFontBase* AddFont(std::string name, std::string path) = 0;

		virtual IFontBase* Find(std::string name) = 0;

		virtual void RemoveFont(void) = 0;

		virtual void DrawAll(void) = 0;
	};

	CORE_API IFontManagerBase* RegisterFontManager(void);
}

#endif // FONTMANAGERBASE_H