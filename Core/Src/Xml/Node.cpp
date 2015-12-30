#include "../../../Core/Inc/Xml/Node.h"

namespace Xml
{
	/// <summary>Конструктор класса.</summary>
	Node::Node(void)
		: _document(nullptr)
		, _nodePtr(nullptr)
	{
	}

	/// <summary>Конструктор класса.</summary>
	Node::Node(rapidxml::xml_document<char>* document, rapidxml::xml_node<char>* node)
		: _document(document)
		, _nodePtr(node)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Node::~Node(void)
	{
	}

	void Node::AddAttribute(const char* name, const char* value)
	{
		_nodePtr->append_attribute(_document->allocate_attribute(name, value));
	}

	const char* Node::GetName(void) const
	{
		return _nodePtr->name();
	}

	const char* Node::GetValue(void) const
	{
		return _nodePtr->value();
	}
}