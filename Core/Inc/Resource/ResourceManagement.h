#ifndef RESOURCEMANAGEMENT_H
#define RESOURCEMANAGEMENT_H

#include "Resource.h"
#include "../../../SDK/Platform.h"

namespace Core
{
	namespace Resource
	{
		// ResourceCache
		class ResourceManagement
		{
		public:
			static ResourceManagement& GetInstance(void);

			/// <summary>Конструктор класса.</summary>
			ResourceManagement(void);

			/// <summary>Деструктор класса.</summary>
			virtual ~ResourceManagement(void);

			virtual ResourceBase* Create(const std::string& name);

			virtual void Release(ResourceBase* resource);

			virtual ResourceBase* GetResource(const std::string& name) const;

			virtual bool HasResource(const std::string& name) const;

		private:
			static ResourceManagement* _management;

			typedef std::map<std::string, ResourceBase*> ResourceMap;
			ResourceMap _resources;
		};
	}
}

#endif // RESOURCEMANAGEMENT_H