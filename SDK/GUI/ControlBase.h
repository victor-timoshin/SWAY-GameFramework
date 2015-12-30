#ifndef CONTROLBASE_H
#define CONTROLBASE_H

#include "../Platform.h"

namespace GUI
{
	class IControlBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IControlBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IControlBase(void) {}
	};

	CORE_API IControlBase* RegisterControl(void);
}

#endif // CONTROLBASE_H