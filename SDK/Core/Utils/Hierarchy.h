#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <string>
#include <map>

namespace Utils
{
	template<typename TYPE>
	class THierarchy
	{
	public:
		/// <summary>Конструктор класса.</summary>
		THierarchy(std::string name)
			: nodeName(name) {}

		/// <summary>Деструктор класса.</summary>
		~THierarchy(void) {}

		void AddChild(TYPE* child)
		{
			children.insert(typename ICollectionMap::value_type(child->GetNodeName(), child));
			child->SetParentNode(static_cast<TYPE*>(this));
		}

		void RemoveChild(TYPE* child)
		{
			typename ICollectionMap::iterator i = children.find(child->GetNodeName());
			if (i != children.end() && i->second == child)
			{
				children.erase(i);
				child->SetParentNode(0L);
			}
		}

		void RemoveAll(void)
		{
			for (typename ICollectionMap::iterator i = children.begin(); i != children.end(); ++i)
			{
				TYPE* Object = i->second;

				Object->SetParentNode(0L);
				delete Object;
			}

			children.clear();
		}

		TYPE* FindChild(std::string name)
		{
			typename ICollectionMap::iterator i = children.find(name);
			if (i != children.end())
				return i->second;

			return 0L;
		}

		unsigned int GetChildCount(void)
		{
			return static_cast<unsigned int>(children.size());
		}

		void SetParentNode(TYPE* parent)
		{
			parentNode = parent;
		}

		TYPE* GetParentNode(void)
		{
			return parentNode;
		}

		void SetNodeName(std::string name)
		{
			nodeName = name;
		}

		std::string GetNodeName(void)
		{
			return nodeName;
		}

	private:
		typedef std::map<std::string, TYPE*> ICollectionMap;
		ICollectionMap children;
		TYPE* parentNode;
		std::string nodeName;
	};
}

#endif // HIERARCHY_H