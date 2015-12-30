#include "../../../Core/Inc/Resource/ResourceManagement.h"

namespace Core
{
	namespace Resource
	{
		ResourceManagement* ResourceManagement::_management = nullptr;
		ResourceManagement& ResourceManagement::GetInstance(void)
		{
			return *_management;
		}

		/// <summary>Конструктор класса.</summary>
		ResourceManagement::ResourceManagement(void)
		{
			_management = this;
		}

		/// <summary>Деструктор класса.</summary>
		ResourceManagement::~ResourceManagement(void)
		{
			for (ResourceMap::iterator i = _resources.begin(); i != _resources.end(); ++i)
			{
				ResourceBase* object = i->second;
				delete object;
			}

			_resources.clear();
		}

		ResourceBase* ResourceManagement::Create(const std::string& name)
		{
			if (HasResource(name) == false)
				return nullptr;

			ResourceBase* resource = new ResourceBase();
			_resources.insert(std::make_pair(name, resource));

			return resource;
		}

		void ResourceManagement::Release(ResourceBase* resource)
		{
			const std::string name = resource->GetName();

			ResourceMap::const_iterator i = _resources.find(name);
			if (i != _resources.end() && i->second == resource)
				_resources.erase(i);
		}

		ResourceBase* ResourceManagement::GetResource(const std::string& name) const
		{
			ResourceMap::const_iterator i = _resources.find(name);
			if (i == _resources.end())
				return nullptr;

			return i->second;
		}

		bool ResourceManagement::HasResource(const std::string& name) const
		{
			return (GetResource(name) == nullptr) ? false : true;
		}
	}
}