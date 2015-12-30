#include "../../GapiOpenGL/Inc/ShaderProgram.h"
#include "../../GapiOpenGL/Inc/WrapFunc.h"

namespace Gapi
{
	//std::string vertexSource = Load(vertexShader);
	////std::string vertexShader = "#version 400\n #define COMPILING_VS\n" + vertexSource;

	//std::string fragmentSource = Load(fragmentShader);
	////std::string fragmentShader = "#version 400\n #define COMPILING_FS\n" + fragmentSource;

	UInt ShaderProgram::GetShaderType(SHADER_TYPE type)
	{
		switch (type)
		{
		case SHADER_TYPE::Vertex:   return GL_VERTEX_SHADER_ARB;
		case SHADER_TYPE::Fragment: return GL_FRAGMENT_SHADER_ARB;
		default:
			break;
		}
	}

	/// <summary>Конструктор класса.</summary>
	ShaderProgram::ShaderProgram(void)
		: _programID(0)
		, _vertexShaderID(0)
		, _fragmentShaderID(0)
	{
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
			Utils::StreamLoggerWrite(Utils::LOG_LEVEL::Error, "ERROR: Could not open the file");
			std::cerr << "ERROR: Could not open the file" << filename << std::endl;
			exit(1);
		}

		std::string source((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		in.close();

		if (source.length() == 0)
		{
			Utils::StreamLoggerWrite(Utils::LOG_LEVEL::Error, "ERROR: Any data in the file");
			std::cerr << "ERROR: Any data in the file" << std::endl;
			exit(1);
		}

		return source;
	}

	bool ShaderProgram::Create(void)
	{
		bool result = true;
		_programID = GL_ARB_ShaderObjects::CreateProgramObject(SOURCE_LOCATION);
		return result;
	}

	void ShaderProgram::Destroy(void)
	{
		if (_programID != 0)
		{
			GL_ARB_VertexProgram::DeletePrograms(1, &_programID, SOURCE_LOCATION);
			_programID = 0;
		}
	}

	UInt ShaderProgram::Compile(SHADER_TYPE type, std::string source)
	{
		UInt objectID = GL_ARB_ShaderObjects::CreateShaderObject(ShaderProgram::GetShaderType(type), SOURCE_LOCATION);

		GL_ARB_ShaderObjects::ShaderSource(objectID, 1, (const GLcharARB**)source.c_str(), NULL, SOURCE_LOCATION);
		GL_ARB_ShaderObjects::CompileShader(objectID, SOURCE_LOCATION);

		if (CheckStatus(objectID, GL_OBJECT_COMPILE_STATUS_ARB))
			std::cout << "The shaders compilation was successfully" << std::endl;
		else
			std::cerr << "ERROR: The shaders compilation fail" << std::endl;

		return objectID;
	}

	bool ShaderProgram::Attach(std::vector<UInt> shaders)
	{
		for (auto shaderID : shaders)
			GL_ARB_ShaderObjects::AttachObject(_programID, shaderID, SOURCE_LOCATION);

		std::for_each(shaders.begin(), shaders.end(), glDeleteObjectARB);

		return true;
	}

	bool ShaderProgram::Link(void)
	{
		GL_ARB_ShaderObjects::LinkProgram(_programID, SOURCE_LOCATION);
		if (CheckStatus(_programID, GL_OBJECT_LINK_STATUS_ARB))
			std::cout << "The linking was successfully" << std::endl;
		else
		{
			std::cerr << "ERROR: The linking fail" << std::endl;
			return false;
		}

		return true;
	}

	bool ShaderProgram::Validate(void)
	{
		GL_ARB_ShaderObjects::ValidateProgram(_programID, SOURCE_LOCATION);
		if (CheckStatus(_programID, GL_OBJECT_VALIDATE_STATUS_ARB))
			std::cout << "The validate program was successfully" << std::endl;
		else
		{
			std::cerr << "ERROR: The validate program fail" << std::endl;
			return false;
		}

		return true;
	}

	int ShaderProgram::GetUniformLocation(const char* name)
	{
		int location;
		location = GL_ARB_ShaderObjects::GetUniformLocation(_programID, name, SOURCE_LOCATION);
		return location;
	}

	int ShaderProgram::GetAttributeLocation(const char* name)
	{
		int location;
		location = GL_ARB_VertexShader::GetAttributeLocation(_programID, name, SOURCE_LOCATION);
		return location;
	}

	void ShaderProgram::SetUniformMatrix4(int location, bool transpose, const void* value)
	{
		GL_ARB_ShaderObjects::UniformMatrix4(location, 1, transpose, (const GLfloat*)value, SOURCE_LOCATION);
	}

	void ShaderProgram::SetUniform1I(int location, int value)
	{
		GL_ARB_ShaderObjects::Uniform1I(location, value, SOURCE_LOCATION);
	}

	void ShaderProgram::SetUniform3F(int location, float x, float y, float z)
	{
		GL_ARB_ShaderObjects::Uniform3F(location, x, y, z, SOURCE_LOCATION);
	}

	void ShaderProgram::SetUniform4F(int location, float x, float y, float z, float w)
	{
		GL_ARB_ShaderObjects::Uniform4F(location, x, y, z, w, SOURCE_LOCATION);
	}

	void ShaderProgram::BindVertexAttributeArray(const char* name, UInt index, int size, UInt type, int stride, void* pointer)
	{
		int vertex = GL_ARB_VertexShader::GetAttributeLocation(_programID, name, SOURCE_LOCATION);

		GL_ARB_VertexProgram::EnableVertexAttributeArray(index, SOURCE_LOCATION);
		GL_ARB_VertexProgram::VertexAttributePointer(index, size, type, GL_FALSE, stride, pointer, SOURCE_LOCATION);
	}

	void ShaderProgram::BindClientStates(void)
	{

	}

	void ShaderProgram::UnbindClientStates(void)
	{
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);

		GL_ARB_Multitexture::ClientActiveTexture(GL_TEXTURE0, SOURCE_LOCATION);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		GL_ARB_Multitexture::ClientActiveTexture(GL_TEXTURE1, SOURCE_LOCATION);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		GL_ARB_Multitexture::ClientActiveTexture(GL_TEXTURE0, SOURCE_LOCATION);
	}

	void ShaderProgram::Bind(void)
	{
		GL_ARB_ShaderObjects::UseProgramObject(_programID, SOURCE_LOCATION);
	}

	void ShaderProgram::Unbind(void)
	{
		GL_ARB_ShaderObjects::UseProgramObject(0, SOURCE_LOCATION);
	}

	UInt ShaderProgram::GetShaderProgram(void)
	{
		return _programID;
	}

	bool ShaderProgram::CheckStatus(UInt object, UInt name)
	{
		GLint compiled = 0;
		GLint length = 0;

		GL_ARB_ShaderObjects::GetObjectParameterI(object, name, &compiled, SOURCE_LOCATION);
		if (compiled == 0)
		{
			GL_ARB_ShaderObjects::GetObjectParameterI(object, GL_OBJECT_INFO_LOG_LENGTH_ARB, &length, SOURCE_LOCATION);
			if (length > 1)
			{
				char* log = (char*)malloc(length);
				GL_ARB_ShaderObjects::GetInfoLog(object, length, &length, log, SOURCE_LOCATION);

				Utils::StreamLoggerWrite(Utils::LOG_LEVEL::Error, "%s", log);
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