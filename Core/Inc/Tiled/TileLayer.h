#ifndef TILELAYER_H
#define TILELAYER_H

#include "../../../SDK/Platform.h"
#include "../../../Math/Inc/Size.h"

#include "Tile.h"
#include "TileLayerType.h"

namespace Tiled
{
	class TileLayer
	{
		DECL_PROPERTY_STRING(Name, _name) // Имя слоя.
		DECL_PROPERTY_FLOAT(Opacity, _opacity) // Прозрачность.
		DECL_PROPERTY_BOOLEAN(Visible, _visible) // Видимость слоя.

	public:
		/// <summary>Конструктор класса.</summary>
		TileLayer(void);

		/// <summary>Деструктор класса.</summary>
		~TileLayer(void);

		void SetCell(int x, int y, const Tile& cell);

		const Tile& GetCell(int x, int y) const;

	private:
		std::vector<Tile> _grid;

		TILE_LAYER_TYPE _type; // Тип слоя.

		int _x;
		int _y;
		int _width;
		int _height;
	};
}

#endif // TILELAYER_H