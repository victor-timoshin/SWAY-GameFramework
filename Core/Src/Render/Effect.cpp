#include "../../../Core/Inc/Render/Effect.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		Effect::Effect(void* library, Gapi::IDeviceBase* device)
			: _renderDevice(device)
			, _shader(nullptr)
		{
			typedef Gapi::IShaderBase* IShaderCallback(void);
			_shader = reinterpret_cast<IShaderCallback*>(GetProcAddress((HMODULE)library, "RegisterShaderProgram"))();
		}

		/// <summary>Деструктор класса.</summary>
		Effect::~Effect(void)
		{
			SAFE_DELETE(_shader);
		}

		void Effect::Bind(void)
		{
			_shader->Bind();
		}

		void Effect::Unbind(void)
		{
			_shader->Unbind();
		}

		std::string Effect::AddCompatibilityPrefixToShaderCode(const char* code)
		{
			return std::string("SHADER_COMPATIBILITY_PREFIX") + code;
		}
	}
}