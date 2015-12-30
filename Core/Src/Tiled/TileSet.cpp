#include "../../../Core/Inc/Tiled/TileSet.h"

namespace Tiled
{
	DEF_PROPERTY_FLOAT(TileSet, Width, _width)
	DEF_PROPERTY_FLOAT(TileSet, Height, _height)
	DEF_PROPERTY_FLOAT(TileSet, Margin, _margin)

	DEF_PROPERTY_FLOAT(TileSet, TileWidth, _tileWidth)
	DEF_PROPERTY_FLOAT(TileSet, TileHeight, _tileHeight)
	DEF_PROPERTY_FLOAT(TileSet, TileSpacing, _tileSpacing)

	/// <summary>Конструктор класса.</summary>
	/// <param name="fileName">Имя загружаемого файла.</param>
	/// <param name="tileWidth">Ширина тайла в пикселях.</param>
	/// <param name="tileHeight">Высота тайла в пикселях.</param>
	/// <param name="tileSpacing">Расстояние между тайлами.</param>
	/// <param name="margin">Отступ.</param>
	TileSet::TileSet(const char* fileName, int tileWidth, int tileHeight, int tileSpacing, int margin)
		: _tileWidth(tileWidth)
		, _tileHeight(tileHeight)
		, _tileSpacing(tileSpacing)
		, _width(0)
		, _height(0)
		, _margin(margin)
		, _rowCount(0)
		, _columnCount(0)
	{
		LoadFromImage(fileName);
	}

	/// <summary>Деструктор класса.</summary>
	TileSet::~TileSet(void)
	{
	}

	/// <summary>Загружает файл набора тайлов.</summary>
	/// <param name="fileName">Имя загружаемого файла.</param>
	void TileSet::LoadFromImage(const char* fileName)
	{
		int tileIndex = 0;

		for (int cols = _margin; cols <= _height - _tileHeight; cols += _tileHeight + _tileSpacing)
		{
			for (int rows = _margin; rows <= _width - _tileWidth; rows += _tileWidth + _tileSpacing)
			{
				_tiles.insert(TileCollection::value_type(tileIndex, new Tile()));
				tileIndex += 1;
			}
		}

		_rowCount = (_height - _margin + _tileSpacing) / (_tileHeight + _tileSpacing);
		_columnCount = (_width - _margin + _tileSpacing) / (_tileWidth + _tileSpacing);
	}

	/// <summary>Устанавливает размер тайла.</summary>
	/// <param name="tileSize">Размер тайла.</param>
	void TileSet::SetTileSize(Math::Size tileSize)
	{
		_tileWidth = tileSize.GetWidth();
		_tileHeight = tileSize.GetHeight();
	}

	/// <summary>Получает размер тайла.</summary>
	Math::Size TileSet::GetTileSize(void) const
	{
		return Math::Size(_tileWidth, _tileHeight);
	}

	/// <summary>Получает количество рядов.</summary>
	UInt TileSet::GetRowCount(void) const
	{
		return _rowCount;
	}

	/// <summary>Получает количество колонок.</summary>
	UInt TileSet::GetColumnCount(void) const
	{
		return _columnCount;
	}

	bool TileSet::IsEmpty(void) const
	{
		return _tileHeight > 0 && _tileHeight > 0;
	}

	const std::map<int, Tile*>& TileSet::GetTiles(void) const
	{
		return _tiles;
	}

	/// <summary>Получает тайл по индексу из коллекции.</summary>
	Tile* TileSet::GetTileByIndex(int index) const
	{
		TileCollection::const_iterator i = _tiles.find(index);
		if (i != _tiles.end())
			return i->second;

		return nullptr;
	}

	/// <summary>Получает количество тайлов в коллекции.</summary>
	int TileSet::GetTileCount(void) const
	{
		return _tiles.size();
	}
}