#include "../../../Core/Inc/Xml/Node.h"

namespace Xml
{
	/// <summary>Конструктор класса.</summary>
	Node::Node(void)
		: _node(0)
	{
	}

	/// <summary>Конструктор класса.</summary>
	Node::Node(rapidxml::xml_node<>* node)
		: _node(node)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Node::~Node(void)
	{
	}

	/// <summary>Получает указатель на объект класса.</summary>
	rapidxml::xml_node<>* Node::GetRapidXMLNode(void)
	{
		return _node;
	}

	const char* Node::GetAttribute(const char* name) const
	{
		rapidxml::xml_attribute<>* attribute = _node->first_attribute(name);
		return (const char*)attribute->value();
	}

	Node Node::GetFirstNode(const char* name) const
	{
		return Node(_node->first_node(name));
	}

#ifdef GetNextSibling
#define GET_NEXT_SIBLING_DEFINED
#pragma push_macro("GetNextSibling")
#undef GetNextSibling
#endif // GetNextSibling

	Node Node::GetNextSibling(const char* name) const
	{
		return Node(_node->next_sibling(name));
	}

#ifdef GET_NEXT_SIBLING_DEFINED
#undef GET_NEXT_SIBLING_DEFINED
#pragma pop_macro("GetNextSibling")
#endif // GET_NEXT_SIBLING_DEFINED

	Attribute Node::GetFirstAttribute(void)
	{
		return Attribute(_node->first_attribute(0));
	}

	/// <summary>Получает имя узла.</summary>
	const char* Node::GetName(void) const
	{
		return _node->name();
	}

	/// <summary>Получает значение узла.</summary>
	const char* Node::GetValue(void) const
	{
		return _node->value();
	}

	bool Node::IsValid(void) const
	{
		return _node != 0;
	}
}