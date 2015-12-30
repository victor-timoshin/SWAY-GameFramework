#ifndef SPRITE_H
#define SPRITE_H

#include "../../Math/Inc/Vector2.h"
#include "../../SDK/Platform.h"

namespace Scene
{
	typedef enum class FlipFlag
	{
		None,
		Vertical,
		Horizontal
	} FLIP_FLAG;

	class Sprite
	{
		DECL_PROPERTY_VIRTUAL_FLOAT(Opacity, _opacity) // Прозрачность.
		DECL_PROPERTY_VIRTUAL(Math::Vec2F, Anchor, _anchor)
		DECL_PROPERTY_VIRTUAL(FLIP_FLAG, Flip, _flipFlags)

	public:
		/// <summary>Конструктор класса.</summary>
		Sprite(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Sprite(void);

		/// <summary>Получает ширину спрайта.</summary>
		virtual float GetWidth(void) const;

		/// <summary>Получает высоту спрайта.</summary>
		virtual float GetHeight(void) const;

	private:
		float _width; // Ширина спрайта.
		float _height; // Высота спрайта.
	};
}

#endif // SPRITE_H