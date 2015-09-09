#include "../../GapiOpenGL/Inc/ShaderProgram.h"

namespace Gapi
{
	//std::string vertexSource = Load(vertexShader);
	////std::string vertexShader = "#version 400\n #define COMPILING_VS\n" + vertexSource;

	//std::string fragmentSource = Load(fragmentShader);
	////std::string fragmentShader = "#version 400\n #define COMPILING_FS\n" + fragmentSource;

	UInt ShaderProgram::GetShaderType(SHADERTYPES type)
	{
		switch (type)
		{
			case EST_VERTEX: return GL_VERTEX_SHADER_ARB;
			case EST_FRAGMENT: return GL_FRAGMENT_SHADER_ARB;
		}

		return (SHADERTYPES)-1;
	}

	PFNGLCREATEPROGRAMOBJECTARBPROC ShaderProgram::glCreateProgramObjectARB = NULL;
	PFNGLDELETEPROGRAMSARBPROC ShaderProgram::glDeleteProgramsARB = NULL;
	PFNGLATTACHOBJECTARBPROC ShaderProgram::glAttachObjectARB = NULL;
	PFNGLDETACHOBJECTARBPROC ShaderProgram::glDetachObjectARB = NULL;
	PFNGLLINKPROGRAMARBPROC ShaderProgram::glLinkProgramARB = NULL;
	PFNGLUSEPROGRAMOBJECTARBPROC ShaderProgram::glUseProgramObjectARB = NULL;
	PFNGLCREATESHADEROBJECTARBPROC ShaderProgram::glCreateShaderObjectARB = NULL;
	PFNGLDELETEOBJECTARBPROC ShaderProgram::glDeleteObjectARB = NULL;
	PFNGLSHADERSOURCEARBPROC ShaderProgram::glShaderSourceARB = NULL;
	PFNGLCOMPILESHADERARBPROC ShaderProgram::glCompileShaderARB = NULL;
	PFNGLVALIDATEPROGRAMARBPROC ShaderProgram::glValidateProgramARB = NULL;
	PFNGLGETATTRIBLOCATIONARBPROC ShaderProgram::glGetAttribLocationARB = NULL;
	PFNGLGETUNIFORMLOCATIONARBPROC ShaderProgram::glGetUniformLocationARB = NULL;
	PFNGLUNIFORMMATRIX4FVARBPROC ShaderProgram::glUniformMatrix4fvARB = NULL;
	PFNGLUNIFORM3FARBPROC ShaderProgram::glUniform3fARB = NULL;
	PFNGLUNIFORM4FARBPROC ShaderProgram::glUniform4fARB = NULL;

	PFNGLGETOBJECTPARAMETERIVARBPROC ShaderProgram::glGetObjectParameterivARB = NULL;
	PFNGLGETINFOLOGARBPROC ShaderProgram::glGetInfoLogARB = NULL;

	/// <summary>Конструктор класса.</summary>
	ShaderProgram::ShaderProgram(void)
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
		LOAD_EXTENSION(PFNGLVALIDATEPROGRAMARBPROC, glValidateProgramARB);
		LOAD_EXTENSION(PFNGLGETATTRIBLOCATIONARBPROC, glGetAttribLocationARB);
		LOAD_EXTENSION(PFNGLGETUNIFORMLOCATIONARBPROC, glGetUniformLocationARB);
		LOAD_EXTENSION(PFNGLUNIFORMMATRIX4FVARBPROC, glUniformMatrix4fvARB);
		LOAD_EXTENSION(PFNGLUNIFORM3FARBPROC, glUniform3fARB);
		LOAD_EXTENSION(PFNGLUNIFORM4FARBPROC, glUniform4fARB);

		LOAD_EXTENSION(PFNGLGETOBJECTPARAMETERIVARBPROC, glGetObjectParameterivARB);
		LOAD_EXTENSION(PFNGLGETINFOLOGARBPROC, glGetInfoLogARB);
	}

	/// <summary>Деструктор класса.</summary>
	ShaderProgram::~ShaderProgram(void)
	{
		Destroy();
	}

	std::string ShaderProgram::Load(const char* filename)
	{
		std::ifstream in(filename, std::ios::binary);
		if (!in.is_open())
		{
			Utils::StreamLoggerWrite(Utils::LOGLEVELS::ELL_ERROR, "ERROR: Could not open the file");
			std::cerr << "ERROR: Could not open the file" << filename << std::endl;
			exit(1);
		}

		std::string source((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		in.close();

		if (source.length() == 0)
		{
			Utils::StreamLoggerWrite(Utils::LOGLEVELS::ELL_ERROR, "ERROR: Any data in the file");
			std::cerr << "ERROR: Any data in the file" << std::endl;
			exit(1);
		}

		return source;
	}

	bool ShaderProgram::Create(void)
	{
		bool result = true;

		programIDs.resize(1);
		for (size_t i = 0; i < programIDs.size(); ++i)
		{
			programIDs[i] = glCreateProgramObjectARB();
			result &= programIDs[i] != 0;
		}

		CHECK_GLERROR();
		return result;
	}

	void ShaderProgram::Destroy(void)
	{
		for (size_t i = 0; i < programIDs.size(); ++i)
		{
			if (programIDs[i] != 0)
			{
				glDeleteProgramsARB(1, &programIDs[i]);
				programIDs[i] = 0;
			}
		}

		programIDs.clear();
	}

	UInt ShaderProgram::Compile(SHADERTYPES type, const char* source)
	{
		UInt shaderID = glCreateShaderObjectARB(ShaderProgram::GetShaderType(type));
		CHECK_GLERROR();

		glShaderSourceARB(shaderID, 1, (const GLcharARB**)&source, NULL);
		CHECK_GLERROR();

		glCompileShaderARB(shaderID);
		CHECK_GLERROR();

		if (CheckStatus(shaderID, GL_OBJECT_COMPILE_STATUS_ARB))
			std::cout << "The shaders compilation was successfully" << std::endl;
		else
			std::cerr << "ERROR: The shaders compilation fail" << std::endl;

		return shaderID;
	}

	bool ShaderProgram::Attach(std::vector<UInt> shaders)
	{
		if (programIDs.empty())
			return false;

		for (size_t i = 0; i < programIDs.size(); ++i)
		{
			for (auto shaderID: shaders)
				glAttachObjectARB(programIDs[i], shaderID);
		}

		//for (size_t currentShaderIdx = 0; currentShaderIdx < shaders.size(); ++currentShaderIdx)
		//	glDetachObjectARB(programID, shaders[currentShaderIdx]);

		std::for_each(shaders.begin(), shaders.end(), glDeleteObjectARB);

		return true;
	}

	bool ShaderProgram::Link(void)
	{
		if (programIDs.empty())
			return false;

		for (size_t i = 0; i < programIDs.size(); ++i)
		{
			glLinkProgramARB(programIDs[i]);
			if (CheckStatus(programIDs[i], GL_OBJECT_LINK_STATUS_ARB))
				std::cout << "The linking was successfully" << std::endl;
			else
			{
				std::cerr << "ERROR: The linking fail" << std::endl;
				return false;
			}
		}

		return true;
	}

	bool ShaderProgram::Validate(void)
	{
		if (programIDs.empty())
			return false;

		for (size_t i = 0; i < programIDs.size(); ++i)
		{
			glValidateProgramARB(programIDs[i]);
			if (CheckStatus(programIDs[i], GL_OBJECT_VALIDATE_STATUS_ARB))
				std::cout << "The validate program was successfully" << std::endl;
			else
			{
				std::cerr << "ERROR: The validate program fail" << std::endl;
				return false;
			}
		}

		return true;
	}

	int ShaderProgram::GetUniformLocation(const char* name)
	{
		int location;
		for (size_t i = 0; i < programIDs.size(); ++i)
			location = glGetUniformLocationARB(programIDs[i], name);

		return location;
	}

	int ShaderProgram::GetAttributeLocation(const char* name)
	{
		int location;
		for (size_t i = 0; i < programIDs.size(); ++i)
			location = glGetAttribLocationARB(programIDs[i], name);

		return location;
	}

	void ShaderProgram::SetUniformMatrix4(int location, bool transpose, const void* value)
	{
		glUniformMatrix4fvARB(location, 1, transpose, (const GLfloat*)value);
	}

	void ShaderProgram::SetUniform3f(int location, int x, int y, int z)
	{
		glUniform3fARB(location, x, y, z);
	}

	void ShaderProgram::SetUniform4f(int location, int x, int y, int z, int w)
	{
		glUniform4fARB(location, x, y, z, w);
	}

	void ShaderProgram::Bind(void)
	{
		for (size_t i = 0; i < programIDs.size(); ++i)
			glUseProgramObjectARB(programIDs[i]);
	}

	void ShaderProgram::Unbind(void)
	{
		glUseProgramObjectARB(0);
	}

	bool ShaderProgram::CheckStatus(UInt object, UInt name)
	{
		GLint compiled = 0;
		GLint length = 0;

		glGetObjectParameterivARB(object, name, &compiled);
		if (compiled == 0)
		{
			glGetObjectParameterivARB(object, GL_OBJECT_INFO_LOG_LENGTH_ARB, &length);
			if (length > 1)
			{
				char* log = (char*)malloc(length);
				glGetInfoLogARB(object, length, &length, log);

				Utils::StreamLoggerWrite(Utils::LOGLEVELS::ELL_ERROR, log);
				std::cerr << log << std::endl;
				free(log);
			}
		}

		return compiled;
	}

	IShaderBase* RegisterShaderProgram(void)
	{
		return new ShaderProgram();
	}
}