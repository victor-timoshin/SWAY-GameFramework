#ifndef DEVICEBASE_H
#define DEVICEBASE_H

#include "../Platform.h"

namespace Sapi
{
	class IDeviceBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IDeviceBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IDeviceBase(void) {}

		virtual void Create(const std::string& name) = 0;

		virtual void Destroy(void) = 0;
	};

	CORE_API IDeviceBase* RegisterDevice(void);
}

#endif // DEVICEBASE_H