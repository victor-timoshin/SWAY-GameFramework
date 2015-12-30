#include "../Inc/Device.h"

namespace Sapi
{
	/// <summary>Конструктор класса.</summary>
	Device::Device(void)
		: _device(nullptr)
		, _context(nullptr)
		, _isEAX2(false)
		, _isFloat32(false)
		, _isFloat64(false)
		, _isMultiChannel(false)
		, _isDisconnect(false)
	{
	}

	/// <summary>Деструктор класса.</summary>
	Device::~Device(void)
	{
		Destroy();
	}

	void Device::Create(const std::string& name)
	{
		_device = alcOpenDevice((name.empty()) ? nullptr : name.c_str());
		if (_device)
		{
			_context = alcCreateContext(_device, nullptr);
			alcMakeContextCurrent(_context);
		}

		int major, minor;
		alcGetIntegerv(_device, ALC_MAJOR_VERSION, sizeof(int), &major);
		alcGetIntegerv(_device, ALC_MINOR_VERSION, sizeof(int), &minor);

		//"Using OpenAL device: %s" << alcGetString(_device, ALC_DEVICE_SPECIFIER);
		//"OpenAL version: %s" << alGetString(AL_VERSION);
		//"OpenAL vendor: %s" << alGetString(AL_VENDOR);
		//"OpenAL renderer: %s" << alGetString(AL_RENDERER);

		_isEAX2 = alIsExtensionPresent("EAX2.0");
		//_isEAX3 = alIsExtensionPresent("EAX3.0");
		//_isEAX4 = alIsExtensionPresent("EAX4.0");
		//_isEAX5 = alIsExtensionPresent("EAX5.0");
		_isFloat32 = alIsExtensionPresent("AL_EXT_float32");
		_isFloat64 = alIsExtensionPresent("AL_EXT_double");
		_isMultiChannel = alIsExtensionPresent("AL_EXT_MCFORMATS");
		_isDisconnect = alcIsExtensionPresent(_device, "ALC_EXT_disconnect");

		alGetError();
	}

	void Device::Destroy(void)
	{
		alcMakeContextCurrent(nullptr);

		if (_context != nullptr && _device != nullptr)
		{
			alcDestroyContext(_context);
			_context = nullptr;

			alcCloseDevice(_device);
			_device = nullptr;
		}

		_isEAX2 = false;
		_isFloat32 = false;
		_isFloat64 = false;
		_isMultiChannel = false;
		_isDisconnect = false;
	}

	IDeviceBase* RegisterDevice(void)
	{
		return new Device();
	}
}