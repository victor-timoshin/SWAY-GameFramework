#ifndef TILE_H
#define TILE_H

#include "../../../SDK/Platform.h"
#include "../../../Math/Inc/Size.h"

namespace Tiled
{
	class TileSet;
	class Tile
	{
		DECL_PROPERTY_INT(ID, _ID) // Уникальный идентификатор тайла.

	public:
		/// <summary>Конструктор класса.</summary>
		Tile(void);

		/// <summary>Конструктор класса.</summary>
		Tile(TileSet* tileSet);

		/// <summary>Деструктор класса.</summary>
		~Tile(void);

	private:
	};
}

#endif // TILE_H