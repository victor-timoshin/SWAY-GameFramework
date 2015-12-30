#include "../../../Core/Inc/Xml/Document.h"
#include "../../../Core/Inc/Xml/Node.h"

namespace Xml
{
	/// <summary>Конструктор класса.</summary>
	Document::Document(void)
		: _documentPtr(new rapidxml::xml_document<>)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Document::~Document(void)
	{
	}

	void Document::Load(Core::Utils::FileStream stream)
	{
		_documentPtr->clear();

		char* xml_string = _documentPtr->allocate_string(0, stream.GetFileLength() + 1);

		//sr.loadData(xml_string, sr.size());
		//xml_string[sr.size()] = 0;
	}

	void Document::Save(const char* fileName)
	{

	}

	Node Document::AddChild(const char* name, const char* value) const
	{
		rapidxml::xml_node<>* node = _documentPtr->allocate_node(rapidxml::node_element, name, value);
		_documentPtr->append_node(node);

		return Node(_documentPtr.get(), node);
	}
}