#include "../../../Core/Inc/Xml/Attribute.h"
#include "../../../SDK/Core/Utils/File.h"

namespace Xml
{
	/// <summary>Конструктор класса.</summary>
	Attribute::Attribute(void)
		: _attribute(0)
	{
	}

	/// <summary>Конструктор класса.</summary>
	Attribute::Attribute(rapidxml::xml_attribute<>* attribute)
		: _attribute(attribute)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Attribute::~Attribute(void)
	{
	}

	/// <summary>Получает указатель на объект класса.</summary>
	rapidxml::xml_attribute<>* Attribute::GetRapidXMLAttribute(void)
	{
		return _attribute;
	}

	/// <summary>Получает следующий атрибут.</summary>
	Attribute Attribute::GetNextAttribute(void)
	{
		return Attribute(_attribute->next_attribute(0));
	}

	/// <summary>Получает имя атрибута.</summary>
	const char* Attribute::GetName(void) const
	{
		return _attribute->name();
	}

	/// <summary>Получает значение атрибута.</summary>
	const char* Attribute::GetValue(void) const
	{
		return _attribute->value();
	}

	/// <summary>Получает целочисленное значение атрибута.</summary>
	int Attribute::GetValueInt(void) const
	{
		std::string value(_attribute->value());
		return Core::Utils::ToInt(value);
	}

	/// <summary>Получает логическое значение атрибута.</summary>
	bool Attribute::GetValueBool(void) const
	{
		std::string value = Core::Utils::ToLower(_attribute->value());
		return value == "true" OR value == "yes" OR value == "1" OR value == "on";
	}

	bool Attribute::IsValid(void) const
	{
		return _attribute != 0;
	}
}