#ifndef COLOR_H
#define COLOR_H

#include "Vector4.h"

namespace Math
{
	class CORE_API Color
	{
		DECL_PROPERTY_INLINE_FLOAT(R, _r) // Канал красного цвета.
		DECL_PROPERTY_INLINE_FLOAT(G, _g) // Канал зеленого цвета.
		DECL_PROPERTY_INLINE_FLOAT(B, _b) // Канал синего цвета.
		DECL_PROPERTY_INLINE_FLOAT(A, _a) // Альфа-канал.

	public:
		/// <summary>Конструктор класса.</summary>
		Color(void);

		/// <summary>Конструктор класса.</summary>
		Color(const float rgba);

		/// <summary>Конструктор класса.</summary>
		Color(const float r, const float g, const float b, const float a);

		/// <summary>Деструктор класса.</summary>
		~Color(void) {}

		void Set(float r, float g, float b, float a = 1.0f);

		void Set(float rgba);

		Vector4 ToVector4(void) const;
	};
}

#define COLOR_WHITE Math::Color(1.0f, 1.0f, 1.0f, 1.0f)

#endif // COLOR_H