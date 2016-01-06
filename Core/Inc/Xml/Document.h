#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "../Utils/FileStream.h"
#include "../../StdAfx.h"

namespace Xml
{
	class Node;
	class Document
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Document(void);

		/// <summary>Деструктор класса.</summary>
		~Document(void);

		void Parse(const std::string& fileName, bool isParseComments);

		/// <summary>Получает корневой узел.</summary>
		Node GetRootNode(void) const;

	private:
		rapidxml::xml_document<> _document;
		char* _xmlString;
	};
}

#endif // DOCUMENT_H