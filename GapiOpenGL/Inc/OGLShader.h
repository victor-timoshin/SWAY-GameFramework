#ifndef OGL_SHADER_H
#define OGL_SHADER_H

#include "../../SDK/Gapi/ShaderBase.h"
#include "../../GapiOpenGL/StdAfx.h"

namespace Gapi
{
	class OGLShader : public IShaderBase
	{
	public:
#ifdef PLATFORM_WINDOWS
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
		static PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
		static PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
		static PFNGLVALIDATEPROGRAMARBPROC glValidateProgramARB;
		static PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
		static PFNGLUNIFORMMATRIX4FVARBPROC glUniformMatrix4fvARB;
#endif

		/** Constructor. */
		OGLShader(IDeviceBase* device);

		/** Destructor. */
		virtual ~OGLShader();

		virtual bool CreateFromFile(const char* vertexSource, const char* fragmentSource);

		virtual void SetVConstantByName(const char* name, const void* source);

		virtual void SetPConstantByName(const char* name, const void* source);

		virtual void UseActiveObject();

	protected:
		UInt Compile(UInt type, const char* source);

		int CheckStatus(UInt object, UInt name);

	private:
		UInt program;
		UInt vertexShader;
		UInt pixelShader;
	};
}

#endif