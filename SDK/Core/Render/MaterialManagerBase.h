#ifndef MATERIALMANAGERBASE_H
#define MATERIALMANAGERBASE_H

#include "../../../SDK/Platform.h"

namespace Core
{
	namespace Render
	{
		class IMaterialBase;
		class IMaterialManagerBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			IMaterialManagerBase(void) {}

			/// <summary>Деструктор класса.</summary>
			virtual ~IMaterialManagerBase(void) {}

			virtual void Load(const std::string& fileName) = 0;

			virtual std::string Add(IMaterialBase* material) = 0;

			virtual IMaterialBase* GetMaterialByName(const std::string& name) = 0;
		};
	}
}

#endif // MATERIALMANAGERBASE_H