#ifndef COLOR_H
#define COLOR_H

#include "Vector4.h"

namespace Math
{
	class Color
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Color(void)
			: _r(0.0f), _g(0.0f), _b(0.0f), _a(1.0f) {}

		/// <summary>Конструктор класса.</summary>
		Color(const float r, const float g, const float b, const float a = 1.0f)
			: _r(r), _g(g), _b(b), _a(a) {}

		/// <summary>Деструктор класса.</summary>
		~Color(void) { }

		void SetRedChannel(float channel)
		{
			_r = channel;
		}

		float GetRedChannel(void) const
		{
			return _r;
		}

		void SetGreenChannel(float channel)
		{
			_g = channel;
		}

		float GetGreenChannel(void) const
		{
			return _g;
		}

		void SetBlueChannel(float channel)
		{
			_b = channel;
		}

		float GetBlueChannel(void) const
		{
			return _b;
		}

		void SetAlphaChannel(float channel)
		{
			_a = channel;
		}

		float GetAlphaChannel(void) const
		{
			return _a;
		}
	public:
		float _r; // Канал красного цвета.
		float _g; // Канал зеленого цвета.
		float _b; // Канал синего цвета.
		float _a; // Альфа-канал.
	};
}

#endif // COLOR_H