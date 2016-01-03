#ifndef ATLAS_H
#define ATLAS_H

#include "../../../Math/Inc/Rect.h"
#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/TextureBase.h"
#include "../../../SDK/Gapi/TextureSamplerBase.h"
#include "../../../SDK/Platform.h"

#include "../Resource/Resource.h"

namespace Core
{
	namespace Render
	{
		class Atlas
		{
		public:
			/// <summary>Конструктор класса.</summary>
			Atlas(void* library, Gapi::IDeviceBase* device);

			/// <summary>Деструктор класса.</summary>
			virtual ~Atlas(void);

			virtual void SetRegion(int x, int y, int width, int height, const UByte* data, int stride);
		};
	}
}

#endif // ATLAS_H