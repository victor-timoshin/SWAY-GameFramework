#include "../../../Core/Inc/Resource/Resource.h"

namespace Core
{
	namespace Resource
	{
		DEF_PROPERTY_STRING(ResourceBase, Name, _name)
		DEF_PROPERTY_STRING(ResourceBase, AssetFile, _assetFile)
		DEF_PROPERTY_STRING(ResourceBase, AssetPathActors, _assetPathActors)
		DEF_PROPERTY_STRING(ResourceBase, AssetPathLevels, _assetPathLevels)
		DEF_PROPERTY_STRING(ResourceBase, AssetPathShaders, _assetPathShaders)
		DEF_PROPERTY_STRING(ResourceBase, AssetPathTextures, _assetPathTextures)
		DEF_PROPERTY_STRING(ResourceBase, AssetPathFonts, _assetPathFonts)

		/// <summary>Конструктор класса.</summary>
		ResourceBase::ResourceBase(void)
		{
		}

		/// <summary>Деструктор класса.</summary>
		ResourceBase::~ResourceBase(void)
		{
		}
	}
}