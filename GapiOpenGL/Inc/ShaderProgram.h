#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../../SDK/Gapi/ShaderBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class ShaderProgram : public IShaderBase
	{
	public:
		static UInt GetShaderType(SHADER_TYPE type);

		/// <summary>Конструктор класса.</summary>
		ShaderProgram(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~ShaderProgram(void);

		virtual std::string Load(const char* filename);

		virtual bool Create(void);

		virtual void Destroy(void);

		virtual UInt Compile(SHADER_TYPE type, std::string source);

		virtual bool Attach(std::vector<UInt> shaders);

		virtual bool Link(void);

		virtual bool Validate(void);

		virtual int GetUniformLocation(const char* name);

		virtual int GetAttributeLocation(const char* name);

		virtual void SetUniformMatrix4(int location, bool transpose, const void* value);

		virtual void SetUniform1I(int location, int value);

		virtual void SetUniform3F(int location, float x, float y, float z);

		virtual void SetUniform4F(int location, float x, float y, float z, float w);

		virtual void BindVertexAttributeArray(const char* name, UInt index, int size, UInt type, int stride, void* pointer);

		virtual void BindClientStates(void);

		virtual void UnbindClientStates(void);

		virtual void Bind(void);

		virtual void Unbind(void);

		virtual UInt GetShaderProgram(void);

	protected:
		bool CheckStatus(UInt object, UInt name);

	private:
		GLhandleARB _programID;

		UInt _vertexShaderID;
		UInt _fragmentShaderID;
	};
}

#endif // SHADERPROGRAM_H