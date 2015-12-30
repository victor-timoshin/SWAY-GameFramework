#ifndef TOOLTIP_H
#define TOOLTIP_H

#include "../../SDK/GUI/ControlBase.h"
#include "../../SDK/Platform.h"

namespace GUI
{
	class Tooltip : public IControlBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Tooltip(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Tooltip(void);

	private:
	};
}

#endif // TOOLTIP_H