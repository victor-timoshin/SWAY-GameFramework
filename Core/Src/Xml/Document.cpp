#include "../../../Core/Inc/Xml/Document.h"
#include "../../../Core/Inc/Xml/Node.h"

namespace Xml
{
	/// <summary>Конструктор класса.</summary>
	Document::Document(void)
		: _xmlString(0)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Document::~Document(void)
	{
	}

	void Document::Parse(const std::string& fileName, bool isParseComments)
	{
		std::ifstream file(fileName);
		std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		buffer.push_back(0);

		std::string content(buffer.data());

		_xmlString = _document.allocate_string(content.c_str(), content.size() + 1);
		if (_xmlString)
		{
			const int flags = rapidxml::parse_trim_whitespace | rapidxml::parse_validate_closing_tags;

			if (isParseComments)
				_document.parse<flags | rapidxml::parse_comment_nodes>(&buffer[0]);
			else
				_document.parse<flags>(_xmlString);
		}
	}

	/// <summary>Получает корневой узел.</summary>
	Node Document::GetRootNode(void) const
	{
		return Node(_document.first_node(0));
	}
}