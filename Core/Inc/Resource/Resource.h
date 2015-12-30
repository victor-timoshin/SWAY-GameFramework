#ifndef RESOURCE_H
#define RESOURCE_H

#include "../../../SDK/Platform.h"

namespace Core
{
	namespace Resource
	{
		class ResourceBase
		{
			DECL_PROPERTY_STRING(Name, _name)
			DECL_PROPERTY_STRING(AssetFile, _assetFile)
			DECL_PROPERTY_STRING(AssetPathActors, _assetPathActors)
			DECL_PROPERTY_STRING(AssetPathLevels, _assetPathLevels)
			DECL_PROPERTY_STRING(AssetPathShaders, _assetPathShaders)
			DECL_PROPERTY_STRING(AssetPathTextures, _assetPathTextures)
			DECL_PROPERTY_STRING(AssetPathFonts, _assetPathFonts)

		public:
			/// <summary>Конструктор класса.</summary>
			ResourceBase(void);

			/// <summary>Деструктор класса.</summary>
			virtual ~ResourceBase(void);
		};
	}
}

#endif // RESOURCE_H