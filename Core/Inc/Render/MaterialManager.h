#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Core/Render/MaterialManagerBase.h"
#include "../../../SDK/Platform.h"

#include "../ImageProvider/ImageProviderFactory.h"

#include "../Xml/Document.h"
#include "../Xml/Node.h"
#include "../Xml/Attribute.h"



namespace Core
{
	namespace Render
	{
		class MaterialManager : public IMaterialManagerBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			/// <param name="library">Хендл библиотеки.</param>
			/// <param name="device">Указатель на графический девайс.</param>
			MaterialManager(void* library, Gapi::IDeviceBase* device);

			/// <summary>Деструктор класса.</summary>
			virtual ~MaterialManager(void);

			virtual void Load(const std::string& fileName);

			virtual std::string Add(IMaterialBase* material);

			virtual IMaterialBase* GetMaterialByName(const std::string& name);

		private:
			void* _library;
			Gapi::IDeviceBase* _renderDevice;
			ImageProvider::ImageProviderFactory* _imageProvider;

			typedef std::map<std::string, IMaterialBase*> IMaterialMap;
			IMaterialMap _materials;
		};
	}
}

#endif // MATERIALMANAGER_H