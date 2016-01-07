#include "../../../Core/Inc/Render/MaterialManager.h"
#include "../../../Core/Inc/Render/Material.h"

#include "../../../SDK/Core/Utils/File.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		/// <param name="library">Хендл библиотеки.</param>
		/// <param name="device">Указатель на графический девайс.</param>
		MaterialManager::MaterialManager(void* library, Gapi::IDeviceBase* device)
			: _library(library)
			, _renderDevice(device)
		{
			_imageProvider = new ImageProvider::ImageProviderFactory();
		}

		/// <summary>Деструктор класса.</summary>
		MaterialManager::~MaterialManager(void)
		{
			_materials.clear();

			SAFE_DELETE(_imageProvider);
		}

		void MaterialManager::Load(const std::string& fileName)
		{
			Xml::Document document;
			Xml::Node rootNode;

			document.Parse(fileName, false);

			rootNode = document.GetRootNode();
			if (NOT rootNode.IsValid())
				return;

			if (NOT Utils::CompareCaseInsensitive((const char*)rootNode.GetName(), "materials"))
				return;

			Xml::Node node = rootNode.GetFirstNode("material");
			while (node.IsValid())
			{
				Material* material = new Material(_library, _renderDevice);
				material->SetName(node.GetAttribute("name"));
				material->Load(_imageProvider, node);
				Add(material);

#ifdef GetNextSibling
#define GET_NEXT_SIBLING_DEFINED
#pragma push_macro("GetNextSibling")
#undef GetNextSibling
#endif // GetNextSibling

				node = node.GetNextSibling("material");

#ifdef GET_NEXT_SIBLING_DEFINED
#undef GET_NEXT_SIBLING_DEFINED
#pragma pop_macro("GetNextSibling")
#endif // GET_NEXT_SIBLING_DEFINED
			}
		}

		std::string MaterialManager::Add(IMaterialBase* material)
		{
			_materials.insert(IMaterialMap::value_type(material->GetName(), material));
			return material->GetName();
		}

		IMaterialBase* MaterialManager::GetMaterialByName(const std::string& name)
		{
			IMaterialMap::iterator iter = _materials.find(name);
			if (iter != _materials.end())
				return iter->second;

			return nullptr;
		}
	}
}