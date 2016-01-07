#include "../../../Core/Inc/Render/Effect.h"

namespace Core
{
	namespace Render
	{
		/// <summary>Конструктор класса.</summary>
		Effect::Effect(void* library, Gapi::IDeviceBase* device)
			: _renderDevice(device)
			, _shader(nullptr)
			, _isLoaded(false)
		{
			typedef Gapi::IShaderBase* IShaderCallback(void);
			_shader = reinterpret_cast<IShaderCallback*>(GetProcAddress((HMODULE)library, "RegisterShaderProgram"))();
		}

		/// <summary>Деструктор класса.</summary>
		Effect::~Effect(void)
		{
			SAFE_DELETE(_shader);
		}

		void Effect::Load(const char* vertexShader, const char* fragmentShader)
		{
			if (NOT _shader->Create())
				return;

			std::vector<UInt> shaders;
			shaders.push_back(_shader->Compile(Gapi::SHADER_TYPE::Vertex, _shader->Load(vertexShader)));
			shaders.push_back(_shader->Compile(Gapi::SHADER_TYPE::Fragment, _shader->Load(fragmentShader)));

			if (NOT _shader->Attach(shaders))
				return;

			if (NOT _shader->Link())
				return;

			if (NOT _shader->Validate())
				return;

			_isLoaded = true;
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

		Gapi::IShaderBase* Effect::GetShader(void)
		{
			return _shader;
		}

		bool Effect::HasLoaded(void) const
		{
			return _isLoaded;
		}
	}
}