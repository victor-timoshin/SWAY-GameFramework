#ifndef NODE_H
#define NODE_H

#include "Attribute.h"

namespace Xml
{
	class Node
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Node(void);

		/// <summary>Конструктор класса.</summary>
		Node(rapidxml::xml_node<>* node);

		/// <summary>Деструктор класса.</summary>
		~Node(void);

		/// <summary>Получает указатель на объект класса.</summary>
		rapidxml::xml_node<>* GetRapidXMLNode(void);

		const char* GetAttribute(const char* name) const;

		Node GetFirstNode(const char* name) const;

#ifdef GetNextSibling
#define GET_NEXT_SIBLING_DEFINED
#pragma push_macro("GetNextSibling")
#undef GetNextSibling
#endif // GetNextSibling

		Node GetNextSibling(const char* name) const;

#ifdef GET_NEXT_SIBLING_DEFINED
#undef GET_NEXT_SIBLING_DEFINED
#pragma pop_macro("GetNextSibling")
#endif // GET_NEXT_SIBLING_DEFINED

		Attribute GetFirstAttribute(void);

		/// <summary>Получает имя узла.</summary>
		const char* GetName(void) const;

		/// <summary>Получает значение узла.</summary>
		const char* GetValue(void) const;

		bool IsValid(void) const;

	private:
		rapidxml::xml_node<>* _node;
	};
}

#endif // DOCUMENT_H