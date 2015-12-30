#ifndef NODE_H
#define NODE_H

#include "../Utils/FileStream.h"
#include "../../../SDK/Platform.h"

#include "../../../External/RapidXml/rapidxml.hpp"

#include <memory> // std::unique_ptr

namespace Xml
{
	class Node
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Node(void);

		/// <summary>Конструктор класса.</summary>
		Node(rapidxml::xml_document<char>* document, rapidxml::xml_node<char>* node);

		/// <summary>Деструктор класса.</summary>
		~Node(void);

		void AddAttribute(const char* name, const char* value);

		const char* GetName(void) const;

		const char* GetValue(void) const;

	private:
		rapidxml::xml_node<char>* _nodePtr;
		rapidxml::xml_document<char>* _document;
	};
}

#endif // DOCUMENT_H