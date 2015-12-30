#ifndef TILESET_H
#define TILESET_H

#include "../../../SDK/Platform.h"
#include "../../../Math/Inc/Size.h"

#include "Tile.h"

namespace Tiled
{
	class TileSet
	{
		DECL_PROPERTY_FLOAT(Width, _width) // Ширина набора.
		DECL_PROPERTY_FLOAT(Height, _height) // Высота набора.
		DECL_PROPERTY_FLOAT(Margin, _margin) // Отступ.

		DECL_PROPERTY_FLOAT(TileWidth, _tileWidth) // Ширина тайла в пикселях.
		DECL_PROPERTY_FLOAT(TileHeight, _tileHeight) // Высота тайла в пикселях.
		DECL_PROPERTY_FLOAT(TileSpacing, _tileSpacing) // Расстояние между тайлами.

	public:
		/// <summary>Конструктор класса.</summary>
		/// <param name="fileName">Имя загружаемого файла.</param>
		/// <param name="tileWidth">Ширина тайла в пикселях.</param>
		/// <param name="tileHeight">Высота тайла в пикселях.</param>
		/// <param name="tileSpacing">Расстояние между тайлами.</param>
		/// <param name="margin">Отступ.</param>
		TileSet(const char* fileName, int tileWidth, int tileHeight, int tileSpacing = 0, int margin = 0);

		/// <summary>Деструктор класса.</summary>
		~TileSet(void);

		/// <summary>Загружает файл набора тайлов.</summary>
		/// <param name="fileName">Имя загружаемого файла.</param>
		void LoadFromImage(const char* fileName);

		/// <summary>Устанавливает размер тайла.</summary>
		/// <param name="tileSize">Размер тайла.</param>
		void SetTileSize(Math::Size tileSize);

		/// <summary>Получает размер тайла.</summary>
		Math::Size GetTileSize(void) const;

		/// <summary>Получает количество рядов.</summary>
		UInt GetRowCount(void) const;

		/// <summary>Получает количество колонок.</summary>
		UInt GetColumnCount(void) const;

		bool IsEmpty(void) const;

		const std::map<int, Tile*>& GetTiles(void) const;

		/// <summary>Получает тайл по индексу из коллекции.</summary>
		Tile* GetTileByIndex(int index) const;

		/// <summary>Получает количество тайлов в коллекции.</summary>
		int GetTileCount(void) const;

	private:
		typedef std::map<int, Tile*> TileCollection;
		TileCollection _tiles; // Коллекция тайлов.

		UInt _rowCount; // Количество рядов.
		UInt _columnCount; // Количество колонок.
	};
}

#endif // TILESET_H