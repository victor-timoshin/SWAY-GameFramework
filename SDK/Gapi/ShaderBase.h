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

		virtual UInt Compile(SHADER_TYPE type, std::string source) = 0;

		virtual bool Attach(std::vector<UInt> shaders) = 0;

		virtual bool Link(void) = 0;

		virtual bool Validate(void) = 0;

		virtual int GetAttributeLocation(const char* name) = 0;

		virtual int GetUniformLocation(const char* name) = 0;

		virtual void SetUniformMatrix4(int location, bool transpose, const void* value) = 0;

		virtual void SetUniform1I(int location, int value) = 0;

		virtual void SetUniform3F(int location, float x, float y, float z) = 0;

		virtual void SetUniform4F(int location, float x, float y, float z, float w) = 0;

		virtual void BindVertexAttributeArray(const char* name, UInt index, int size, UInt type, int stride, void* pointer) = 0;

		virtual void BindClientStates(void) = 0;

		virtual void UnbindClientStates(void) = 0;

		virtual void Bind(void) = 0;

		virtual void Unbind(void) = 0;

		virtual UInt GetShaderProgram(void) = 0;
	};

	CORE_API IShaderBase* RegisterShaderProgram(void);
}

#endif // SHADERBASE_H