#include "../../../Core/Inc/Imaging/CodecFactory.h"

namespace Render
{
	/// <summary>Конструктор класса.</summary>
	CodecFactory::CodecFactory(void)
	{
	}

	/// <summary>Деструктор класса.</summary>
	CodecFactory::~CodecFactory(void)
	{
	}

	void CodecFactory::RegisterEncoder(const std::string name, Imaging::ILoaderBase* loader)
	{
		mapEncoderSystem.insert(std::make_pair(name, loader));
	}

	void CodecFactory::RegisterDecoder(void)
	{
	}

	void CodecFactory::UnregisterEncoder(const std::string& name)
	{
		mapEncoderSystem.erase(name);
	}

	void CodecFactory::UnregisterDecoder(void)
	{
	}

	void CodecFactory::CreateEncoder(const std::string& name)
	{
		TMapEncoderSystem::iterator i = mapEncoderSystem.find(name);
		if (i != mapEncoderSystem.end())
			i->second->LoadFromStream(std::ifstream());
	}

	void CodecFactory::CreateDecoder()
	{
	}
}