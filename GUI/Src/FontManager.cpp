#include "../Inc/FontManager.h"

namespace GUI
{
	/// <summary>Конструктор класса.</summary>
	FontManager::FontManager(void)
		: _library(0)
		, _isLoaded(false)
	{
		InitLibrary();
	}

	/// <summary>Деструктор класса.</summary>
	FontManager::~FontManager(void)
	{
		FreeLibrary();
	}

	/// <summary>Инициализация библиотеки FreeType.</summary>
	bool FontManager::InitLibrary(void)
	{
		if (!HasLoaded())
		{
			FT_Error error = FT_Init_FreeType(&_library);
			if (error)
			{
				std::cout << "Could not init FreeType Library" << std::endl;
				return false;
			}

			_isLoaded = true;
		}

		int major, minor, patch;
		FT_Library_Version(_library, &major, &minor, &patch);

		return true;
	}

	/// <summary>Освобождает библиотеку FreeType.</summary>
	void FontManager::FreeLibrary(void)
	{
		if (!HasLoaded())
			return;

		if (_library)
		{
			FT_Done_FreeType(_library);
			_library = 0;
			_isLoaded = false;
		}
	}

	bool FontManager::HasLoaded(void) const
	{
		return _isLoaded;
	}

	IFontBase* FontManager::AddFont(std::string name, std::string path)
	{
		if (!Core::Utils::FileExists(path))
			return nullptr;

		Font* font = nullptr;

		font = new Font();
		bool result = font->LoadFromFile(_library, path.c_str());
		if (!result)
		{
			FreeLibrary();
			return nullptr;
		}

		font->SetSize(0, DEFAULT_FONT_SIZE);
		font->Create();

		_fonts.insert(std::pair<std::string, Font*>(name, font));
		return font;
	}

	IFontBase* FontManager::Find(std::string name)
	{
		FontMap::iterator iter = _fonts.find(name);
		if (iter != _fonts.end())
			return iter->second;

		return nullptr;
	}

	void FontManager::RemoveFont(void)
	{
		for (FontMap::iterator i = _fonts.begin(); i != _fonts.end(); ++i)
			delete i->second;

		_fonts.clear();
	}

	void FontManager::DrawAll(void)
	{
		for (FontMap::iterator i = _fonts.begin(); i != _fonts.end(); ++i)
		{
			IFontBase* object = i->second;
			object->Draw2DText();
		}
	}

	CORE_API IFontManagerBase* RegisterFontManager(void)
	{
		return new FontManager();
	}
}