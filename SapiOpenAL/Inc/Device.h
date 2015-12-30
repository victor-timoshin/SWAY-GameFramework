#ifndef DEVICE_H
#define DEVICE_H

#include "../../SDK/Sapi/DeviceBase.h"
#include "../../SDK/Platform.h"
#include "../StdAfx.h"

#define NUM_BUFFERS 3
#define BUFFER_SIZE 4096

namespace Sapi
{
	class Device : public IDeviceBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		Device(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~Device(void);

		virtual void Create(const std::string& name);

		virtual void Destroy(void);

	private:
		ALCdevice* _device;
		ALCcontext* _context;

		bool _isEAX2; // Поддержка EAX2.0
		bool _isFloat32;
		bool _isFloat64;
		bool _isMultiChannel;
		bool _isDisconnect;
	};
}

#endif // DEVICE_H