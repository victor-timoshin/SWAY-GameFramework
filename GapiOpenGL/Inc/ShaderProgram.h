#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../../SDK/Gapi/ShaderBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class ShaderProgram : public IShaderBase
	{
	public:
		static UInt GetShaderType(SHADERTYPES type);

		static PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
		static PFNGLDELETEPROGRAMSARBPROC glDeleteProgramsARB;
		static PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
		static PFNGLDETACHOBJECTARBPROC glDetachObjectARB;
		static PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
		static PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;
		static PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
		static PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
		static PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
		static PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
		static PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB;
		static PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
		static PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB;

		static PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
		static PFNGLGETINFOLOGARBPROC glGetInfoLogARB;

		/// <summary>Конструктор класса.</summary>
		ShaderProgram(void);

		/// <summary>Деструктор класса.</summary>
		virtual ~ShaderProgram(void);

		virtual std::string Load(const char* filename);

		virtual bool Create(void);

		virtual void Destroy(void);

		virtual UInt Compile(SHADERTYPES type, const char* source);

		virtual bool Attach(std::vector<UInt> shaders);

		virtual bool Link(void);

		virtual bool Validate(void);

		virtual int GetUniformLocation(const char* name);

		virtual void SetUniformMatrix4(int location, bool transpose, const void* value);

		virtual void Bind(void);

		virtual void Unbind(void);

	protected:
		bool CheckStatus(UInt object, UInt name);

	private:
		std::vector<GLhandleARB> programIDs;

		UInt program;
		UInt vertexShader;
		UInt pixelShader;
	};
}

#endif // SHADERPROGRAM_H