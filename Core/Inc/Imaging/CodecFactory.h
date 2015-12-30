#ifndef CODECFACTORY_H
#define CODECFACTORY_H

#include "../../../SDK/Core/Imaging/LoaderBase.h"
#include "../../../SDK/Platform.h"

namespace Render
{
	class CodecFactory
	{
	public:
		/// <summary>Конструктор класса.</summary>
		CodecFactory(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~CodecFactory(void);

		void RegisterEncoder(const std::string name, Imaging::ILoaderBase* loader);

		void RegisterDecoder(void);

		void UnregisterEncoder(const std::string& name);

		void UnregisterDecoder(void);

		void CreateEncoder(const std::string& name);

		void CreateDecoder(void);

	protected:
		typedef std::map<std::string, Imaging::ILoaderBase*> TMapEncoderSystem;

	private:
		TMapEncoderSystem mapEncoderSystem;
	};
}

#endif // CODECFACTORY_H