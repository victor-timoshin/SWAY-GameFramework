#ifndef SHADERBASE_H
#define SHADERBASE_H

#include "../../SDK/Platform.h"

#include <vector>

namespace Gapi
{
	class IShaderBase
	{
	public:
		/// <summary>Конструктор класса.</summary>
		IShaderBase(void) {}

		/// <summary>Деструктор класса.</summary>
		virtual ~IShaderBase(void) {}

		virtual std::string Load(const char* filename) = 0;

		virtual bool Create(void) = 0;

		virtual void Destroy(void) = 0;

		virtual UInt Compile(SHADERTYPES type, const char* source) = 0;

		virtual bool Attach(std::vector<UInt> shaders) = 0;

		virtual bool Link(void) = 0;

		virtual bool Validate(void) = 0;

		virtual int GetUniformLocation(const char* name) = 0;

		virtual void SetUniformMatrix4(int location, bool transpose, const void* value) = 0;

		virtual void Bind(void) = 0;

		virtual void Unbind(void) = 0;
	};

	CORE_API IShaderBase* RegisterShaderProgram(void);
}

#endif // SHADERBASE_H