#ifndef CONTROL_H
#define CONTROL_H

#include "../../SDK/GUI/ControlBase.h"
#include "../../SDK/Platform.h"

namespace GUI
{
	class Control : public IControlBase
	{
		DECL_PROPERTY_STRING(Name, _name) // Имя.

		DECL_PROPERTY_INT(Width, _width) // Ширина.
		DECL_PROPERTY_INT(MinWidth, _minWidth) // Минимальная ширина.
		DECL_PROPERTY_INT(MaxWidth, _maxWidth) // Максиммальная ширина.

		DECL_PROPERTY_INT(Height, _height) // Высота.
		DECL_PROPERTY_INT(MinHeight, _minHeight) // Минимальная высота.
		DECL_PROPERTY_INT(MaxHeight, _maxHeight) // Максиммальная высота.

		DECL_PROPERTY_INT(Priority, _priority) // Приоритет.
		DECL_PROPERTY_INT(Opacity, _opacity) // Прозрачность.
		

	public:
		/// <summary>Конструктор класса.</summary>
		Control(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Control(void);

	protected:
		typedef std::map<std::string, Control*> TMapControl;

	private:
		Control* _parent;
		TMapControl _children;
	};
}

#endif // CONTROL_H