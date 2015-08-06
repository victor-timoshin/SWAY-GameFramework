#ifndef COLOR_H
#define COLOR_H

#include "Vector4.h"

namespace Math
{
	class CORE_API Color
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Color(void);

		/// <summary>Конструктор класса.</summary>
		Color(const float r, const float g, const float b, const float a = 1.0f);

		/// <summary>Деструктор класса.</summary>
		~Color(void);

		void SetRedChannel(float channel);

		float GetRedChannel(void) const;

		void SetGreenChannel(float channel);

		float GetGreenChannel(void) const;

		void SetBlueChannel(float channel);

		float GetBlueChannel(void) const;

		void SetAlphaChannel(float channel);

		float GetAlphaChannel(void) const;

	public:
		float _r; // Канал красного цвета.
		float _g; // Канал зеленого цвета.
		float _b; // Канал синего цвета.
		float _a; // Альфа-канал.
	};
}

#endif // COLOR_H