#include "../../GapiOpenGL/Inc/OGLShader.h"
#include "../../GapiOpenGL/Inc/OGLDevice.h"

#include <fstream>

namespace Gapi
{
	PFNGLCREATEPROGRAMOBJECTARBPROC OGLShader::glCreateProgramObjectARB = 0L;
	PFNGLDELETEPROGRAMSARBPROC OGLShader::glDeleteProgramsARB = 0L;
	PFNGLATTACHOBJECTARBPROC OGLShader::glAttachObjectARB = 0L;
	PFNGLDETACHOBJECTARBPROC OGLShader::glDetachObjectARB = 0L;
	PFNGLLINKPROGRAMARBPROC OGLShader::glLinkProgramARB = 0L;
	PFNGLUSEPROGRAMOBJECTARBPROC OGLShader::glUseProgramObjectARB = 0L;
	PFNGLCREATESHADEROBJECTARBPROC OGLShader::glCreateShaderObjectARB = 0L;
	PFNGLDELETEOBJECTARBPROC OGLShader::glDeleteObjectARB = 0L;
	PFNGLSHADERSOURCEARBPROC OGLShader::glShaderSourceARB = 0L;
	PFNGLCOMPILESHADERARBPROC OGLShader::glCompileShaderARB = 0L;
	PFNGLGETOBJECTPARAMETERIVARBPROC OGLShader::glGetObjectParameterivARB = 0L;
	PFNGLGETINFOLOGARBPROC OGLShader::glGetInfoLogARB = 0L;
	PFNGLVALIDATEPROGRAMARBPROC OGLShader::glValidateProgramARB = 0L;
	PFNGLGETUNIFORMLOCATIONARBPROC OGLShader::glGetUniformLocationARB = 0L;
	PFNGLUNIFORMMATRIX4FVARBPROC OGLShader::glUniformMatrix4fvARB = 0L;

	/** Constructor. */
	OGLShader::OGLShader(IDeviceBase* device) : IShaderBase(device)
		, program(0), vertexShader(0), pixelShader(0)
	{
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
	}

	/** Destructor. */
	OGLShader::~OGLShader()
	{
		glDetachObjectARB(program, pixelShader);
		glDeleteObjectARB(pixelShader);

		glDetachObjectARB(program, vertexShader);
		glDeleteObjectARB(vertexShader);

		glUseProgramObjectARB(0);
		glDeleteProgramsARB(1, &program);
	}

	bool OGLShader::CreateFromFile(const char* vertexSource, const char* fragmentSource)
	{
		program = glCreateProgramObjectARB();

		vertexShader = Compile(GL_VERTEX_SHADER_ARB, vertexSource);
		pixelShader = Compile(GL_FRAGMENT_SHADER_ARB, fragmentSource);

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

	void OGLShader::SetVConstantByName(const char* name, const void* source)
	{
		glUniformMatrix4fvARB(glGetUniformLocationARB(program, name), 1, GL_TRUE, (float*)source);
	}

	void OGLShader::UseActiveObject()
	{
		glUseProgramObjectARB(program);
	}

	UInt OGLShader::Compile(UInt type, const char* source)
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
		{
			MessageBox(0L, "Shader not compiled:\n", "GLERROR", MB_OK);
			return 0;
		}

		return object;
	}

	int OGLShader::CheckStatus(UInt object, UInt name)
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

	IShaderBase* RegisterShader(IDeviceBase* device)
	{
		return new OGLShader(device);
	}
}