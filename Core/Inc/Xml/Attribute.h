#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "../../StdAfx.h"

namespace Xml
{
	class Attribute
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Attribute(void);

		/// <summary>Конструктор класса.</summary>
		Attribute(rapidxml::xml_attribute<>* attribute);

		/// <summary>Деструктор класса.</summary>
		~Attribute(void);

		/// <summary>Получает указатель на объект класса.</summary>
		rapidxml::xml_attribute<>* GetRapidXMLAttribute(void);

		/// <summary>Получает следующий атрибут.</summary>
		Attribute GetNextAttribute(void);

		/// <summary>Получает имя атрибута.</summary>
		const char* GetName(void) const;

		/// <summary>Получает значение атрибута.</summary>
		const char* GetValue(void) const;

		/// <summary>Получает целочисленное значение атрибута.</summary>
		int GetValueInt(void) const;

		/// <summary>Получает логическое значение атрибута.</summary>
		bool GetValueBool(void) const;

		bool IsValid(void) const;

	private:
		rapidxml::xml_attribute<>* _attribute;
	};
}

#endif // ATTRIBUTE_H