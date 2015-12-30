#include "../../../Core/Inc/Tiled/TileLayer.h"

namespace Tiled
{
	DEF_PROPERTY_STRING(TileLayer, Name, _name)
	DEF_PROPERTY_FLOAT(TileLayer, Opacity, _opacity)
	DEF_PROPERTY_BOOLEAN(TileLayer, Visible, _visible)

	/// <summary>Конструктор класса.</summary>
	TileLayer::TileLayer(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	TileLayer::~TileLayer(void)
	{
	}

	void TileLayer::SetCell(int x, int y, const Tile& cell)
	{
		int width = 5;
		_grid[x + y * width] = cell;
	}

	const Tile& TileLayer::GetCell(int x, int y) const
	{
		return _grid.at(x + y * _width);
	}
}