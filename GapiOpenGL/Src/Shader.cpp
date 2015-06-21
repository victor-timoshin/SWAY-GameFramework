#include "../../GapiOpenGL/Inc/Shader.h"
#include "../../GapiOpenGL/Inc/RenderDevice.h"

#include <fstream>

namespace Gapi
{
	namespace OpenGL
	{
#ifdef PLATFORM_WINDOWS
		PFNGLCREATEPROGRAMOBJECTARBPROC Shader::glCreateProgramObjectARB = 0L;
		PFNGLDELETEPROGRAMSARBPROC Shader::glDeleteProgramsARB = 0L;
		PFNGLATTACHOBJECTARBPROC Shader::glAttachObjectARB = 0L;
		PFNGLDETACHOBJECTARBPROC Shader::glDetachObjectARB = 0L;
		PFNGLLINKPROGRAMARBPROC Shader::glLinkProgramARB = 0L;
		PFNGLUSEPROGRAMOBJECTARBPROC Shader::glUseProgramObjectARB = 0L;
		PFNGLCREATESHADEROBJECTARBPROC Shader::glCreateShaderObjectARB = 0L;
		PFNGLDELETEOBJECTARBPROC Shader::glDeleteObjectARB = 0L;
		PFNGLSHADERSOURCEARBPROC Shader::glShaderSourceARB = 0L;
		PFNGLCOMPILESHADERARBPROC Shader::glCompileShaderARB = 0L;
		PFNGLGETOBJECTPARAMETERIVARBPROC Shader::glGetObjectParameterivARB = 0L;
		PFNGLGETINFOLOGARBPROC Shader::glGetInfoLogARB = 0L;
		PFNGLVALIDATEPROGRAMARBPROC Shader::glValidateProgramARB = 0L;
		PFNGLGETUNIFORMLOCATIONARBPROC Shader::glGetUniformLocationARB = 0L;
		PFNGLUNIFORMMATRIX4FVARBPROC Shader::glUniformMatrix4fvARB = 0L;
#endif

		/** Constructor. */
		Shader::Shader(IRenderDeviceBase* device) : IShaderBase(device)
			, program(0)
			, vertexShader(0)
			, pixelShader(0)
		{
#ifdef PLATFORM_WINDOWS
			LOAD_EXTENSION(PFNGLCREATEPROGRAMOBJECTARBPROC, glCreateProgramObjectARB);
			LOAD_EXTENSION(PFNGLDELETEPROGRAMSARBPROC, glDeleteProgramsARB);
			LOAD_EXTENSION(PFNGLATTACHOBJECTARBPROC, glAttachObjectARB);
			LOAD_EXTENSION(PFNGLDETACHOBJECTARBPROC, glDetachObjectARB);
			LOAD_EXTENSION(PFNGLLINKPROGRAMARBPROC, glLinkProgramARB);
			LOAD_EXTENSION(PFNGLUSEPROGRAMOBJECTARBPROC, glUseProgramObjectARB);
			LOAD_EXTENSION(PFNGLCREATESHADEROBJECTARBPROC, glCreateShaderObjectARB);
			LOAD_EXTENSION(PFNGLDELETEOBJECTARBPROC, glDeleteObjectARB);
			LOAD_EXTENSION(PFNGLSHADERSOURCEARBPROC, glShaderSourceARB);
			LOAD_EXTENSION(PFNGLCOMPILESHADERARBPROC, glCompileShaderARB);
			LOAD_EXTENSION(PFNGLGETOBJECTPARAMETERIVARBPROC, glGetObjectParameterivARB);
			LOAD_EXTENSION(PFNGLGETINFOLOGARBPROC, glGetInfoLogARB);
			LOAD_EXTENSION(PFNGLVALIDATEPROGRAMARBPROC, glValidateProgramARB);
			LOAD_EXTENSION(PFNGLGETUNIFORMLOCATIONARBPROC, glGetUniformLocationARB);
			LOAD_EXTENSION(PFNGLUNIFORMMATRIX4FVARBPROC, glUniformMatrix4fvARB);
#endif
		}

		/** Destructor. */
		Shader::~Shader()
		{
			glDetachObjectARB(program, pixelShader);
			glDeleteObjectARB(pixelShader);

			glDetachObjectARB(program, vertexShader);
			glDeleteObjectARB(vertexShader);

			glUseProgramObjectARB(0);
			glDeleteProgramsARB(1, &program);
		}

		bool Shader::CreateFromFile(const char* vertexSource, const char* pixelSource)
		{
			program = glCreateProgramObjectARB();

			vertexShader = Compile(GL_VERTEX_SHADER_ARB, vertexSource);
			pixelShader = Compile(GL_FRAGMENT_SHADER_ARB, pixelSource);

			glAttachObjectARB(program, vertexShader);
			glAttachObjectARB(program, pixelShader);

			glLinkProgramARB(program);
			if (CheckStatus(program, GL_OBJECT_LINK_STATUS_ARB) != GL_TRUE)
				return false;

			glValidateProgramARB(program);
			if (CheckStatus(program, GL_OBJECT_VALIDATE_STATUS_ARB) != GL_TRUE)
				return false;

			return true;
		}

		void Shader::SetVConstantByName(const char* name, const void* source)
		{
			glUniformMatrix4fvARB(glGetUniformLocationARB(program, name), 1, GL_TRUE, (float*)source);
		}

		void Shader::SetPConstantByName(const char* name, const void* source)
		{

		}

		void Shader::UseActiveObject()
		{
			glUseProgramObjectARB(program);
		}

		UInt Shader::Compile(UInt type, const char* source)
		{
			char tempLine[128] = { 0 };
			int count = 0;

			std::ifstream input;
			input.open(source);

			if (!input.is_open())
				return 0;

			while (!input.eof())
			{
				input.getline(tempLine, 128, '\n');
				count++;
			}

			input.close();

			if (count == 0)
				return 0;

			std::ifstream sourceInput;
			char* shaderSource = new char[128 * count];

			sourceInput.open(source);
			sourceInput.getline(shaderSource, 128 * count, '\0');

			sourceInput.close();

			UInt object = glCreateShaderObjectARB(type);

			glShaderSourceARB(object, 1, (const char**)&shaderSource, 0L);
			glCompileShaderARB(object);

			if (CheckStatus(object, GL_OBJECT_COMPILE_STATUS_ARB) != GL_TRUE)
				return 0;

			return object;
		}

		int Shader::CheckStatus(UInt object, UInt name)
		{
			int infoLength, result = 0;
			glGetObjectParameterivARB(object, name, &result);

			if (result == GL_FALSE)
			{
				glGetObjectParameterivARB(object, GL_OBJECT_INFO_LOG_LENGTH_ARB, &infoLength);

				char* buffer = (char*)malloc(infoLength);
				glGetInfoLogARB(object, infoLength, 0L, buffer);
				MessageBox(0L, buffer, "Error", MB_OK);
				free(buffer);
			}

			return result;
		}
	}

	IShaderBase* RegisterShader(IRenderDeviceBase* device)
	{
		return new OpenGL::Shader(device);
	}
}