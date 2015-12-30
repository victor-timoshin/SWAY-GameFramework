#include "../Inc/Control.h"

namespace GUI
{
	DEF_PROPERTY_STRING(Control, Name, _name)

	DEF_PROPERTY_INT(Control, Width, _width)
	DEF_PROPERTY_INT(Control, MinWidth, _minWidth)
	DEF_PROPERTY_INT(Control, MaxWidth, _maxWidth)

	DEF_PROPERTY_INT(Control, Height, _height)
	DEF_PROPERTY_INT(Control, MinHeight, _minHeight)
	DEF_PROPERTY_INT(Control, MaxHeight, _maxHeight)

	DEF_PROPERTY_INT(Control, Priority, _priority)
	DEF_PROPERTY_INT(Control, Opacity, _opacity)

	/// <summary>Конструктор класса.</summary>
	Control::Control(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Control::~Control(void)
	{
	}

	CORE_API IControlBase* RegisterControl(void)
	{
		return new Control();
	}
}