#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "../Utils/FileStream.h"
#include "../../../SDK/Platform.h"

#include "../../../External/RapidXml/rapidxml.hpp"

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

		void Load(Core::Utils::FileStream stream);

		void Save(const char* fileName);

		Node AddChild(const char* name, const char* value) const;

	private:
		std::unique_ptr<rapidxml::xml_document<char>> _documentPtr;
	};
}

#endif // DOCUMENT_H