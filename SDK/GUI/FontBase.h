#ifndef FONTBASE_H
#define FONTBASE_H

#include "../../Math/Inc/Vector2.h"
#include "../../Math/Inc/Vertex.h"
#include "../Platform.h"

#include "FontStyle.h"

namespace GUI
{
	class IFontBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IFontBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IFontBase(void) {}

		virtual void Create(void) = 0;

		virtual void Destroy(void) = 0;

		/// <summary>Получает имя шрифта.</summary>
		virtual std::string GetFamilyName(void) const = 0;

		/// <summary>Получает имя стиля.</summary>
		virtual std::string GetStyleName(void) const = 0;

		virtual void SetText(std::string text) = 0;

		virtual void SetPosition(Math::Vec2F position) = 0;

		virtual void SetPosition(float x, float y) = 0;

		virtual void SetScale(float scale) = 0;

		virtual void SetColor(const Math::Color& color) = 0;

		virtual void Draw2DText(void) = 0;
	};

	CORE_API IFontBase* RegisterTTFont(void);
}

#endif // FONTBASE_H