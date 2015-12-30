#include "../Inc/Sprite.h"

namespace Scene
{
	DEF_PROPERTY_FLOAT(Sprite, Opacity, _opacity) // Прозрачность.
	DEF_PROPERTY(Sprite, Math::Vec2F, Anchor, _anchor)
	DEF_PROPERTY(Sprite, FLIP_FLAG, Flip, _flipFlags)

	/// <summary>Конструктор класса.</summary>
	Sprite::Sprite(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Sprite::~Sprite(void)
	{
	}

	/// <summary>Получает ширину спрайта.</summary>
	float Sprite::GetWidth(void) const
	{
		return _width;
	}

	/// <summary>Получает высоту спрайта.</summary>
	float Sprite::GetHeight(void) const
	{
		return _height;
	}
}