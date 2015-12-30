#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "../../SDK/GUI/FontManagerBase.h"
#include "../../SDK/Core/Utils/File.h"
#include "../../SDK/Platform.h"

#include "Font.h"
#include "../StdAfx.h"

#define DEFAULT_FONT_SIZE 16

namespace GUI
{
	class FontManager : public IFontManagerBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		FontManager(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~FontManager(void);

		virtual IFontBase* AddFont(std::string name, std::string path);

		virtual IFontBase* Find(std::string name);

		virtual void RemoveFont(void);

		virtual void DrawAll(void);

	protected:
		/// <summary>Инициализация библиотеки FreeType.</summary>
		bool InitLibrary(void);

		/// <summary>Освобождает библиотеку FreeType.</summary>
		void FreeLibrary(void);

		bool HasLoaded(void) const;

	private:
		FT_Library _library; // Структура для инициализации библиотеки.
		bool _isLoaded;

		typedef std::map<std::string, Font*> FontMap;
		FontMap _fonts;
	};
}

#endif // FONTMANAGER_H