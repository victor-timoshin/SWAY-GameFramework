#ifndef EFFECT_H
#define EFFECT_H

#include "../../../SDK/Gapi/DeviceBase.h"
#include "../../../SDK/Gapi/ShaderBase.h"
#include "../../../SDK/Platform.h"

#include "../Resource/Resource.h"

namespace Core
{
	namespace Render
	{
		class Effect : public Core::Resource::ResourceBase
		{
		public:
			/// <summary>Конструктор класса.</summary>
			Effect(void* library, Gapi::IDeviceBase* device);

			/// <summary>Деструктор класса.</summary>
			virtual ~Effect(void);

			virtual void Load(const char* vertexShader, const char* fragmentShader);

			virtual void Bind(void);

			virtual void Unbind(void);

			virtual std::string AddCompatibilityPrefixToShaderCode(const char* code);

			virtual Gapi::IShaderBase* GetShader(void);

			virtual bool HasLoaded(void) const;

		private:
			Gapi::IDeviceBase* _renderDevice;
			Gapi::IShaderBase* _shader;

			bool _isLoaded;
		};
	}
}

#endif // EFFECT_H