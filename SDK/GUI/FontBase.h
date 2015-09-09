#ifndef FONTBASE_H
#define FONTBASE_H

#include "../../Math/Inc/Vector2.h"
#include "../../Math/Inc/Vertex.h"
#include "../Platform.h"

namespace GUI
{
	class IFontBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IFontBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IFontBase(void) {}

		virtual void Create(const char* filename) = 0;

		virtual void Destroy(void) = 0;

		//virtual void Begin(void) = 0;

		virtual void Draw2DText(std::string text, UInt positionX, UInt positionY, float scale, Math::Vector3 color) = 0;

		//virtual void End(void) = 0;
	};

	CORE_API IFontBase* RegisterTTFont(void);
}

#endif // FONTBASE_H