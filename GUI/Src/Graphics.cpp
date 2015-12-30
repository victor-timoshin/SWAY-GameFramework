#include "../Inc/Graphics.h"

namespace GUI
{
	PFNGLACTIVETEXTUREPROC Graphics::glActiveTextureARB = nullptr;

	/// <summary>Конструктор класса.</summary>
	Graphics::Graphics(void)
	{
		LOAD_EXTENSION(PFNGLACTIVETEXTUREPROC, glActiveTextureARB);
	}

	/// <summary>Деструктор класса.</summary>
	Graphics::~Graphics(void)
	{
		SAFE_DELETE(_vertexBuffer);
		SAFE_DELETE(_shader);
	}

	void Graphics::Create(void)
	{
		void* library = LoadLibrary("GapiOpenGL_Win32_Debug");

		typedef Gapi::IShaderBase* ShaderCallback(void);
		_shader = reinterpret_cast<ShaderCallback*>(GetProcAddress((HMODULE)library, "RegisterShaderProgram"))();
		if (_shader->Create())
		{
			std::vector<UInt> shaders;
			shaders.push_back(_shader->Compile(Gapi::SHADER_TYPE::Vertex, _shader->Load("../../../Assets/Shaders/gui_basic.vs")));
			shaders.push_back(_shader->Compile(Gapi::SHADER_TYPE::Fragment, _shader->Load("../../../Assets/Shaders/gui_basic.fs")));

			_shader->Attach(shaders);
			_shader->Link();
			_shader->Validate();
		}

		std::vector<Gapi::LVERTEX_ELEMENT_DESC> elements;
		elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Position, Gapi::VERTEX_ELEMENT_FORMAT::Float3 });
		elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::Color, Gapi::VERTEX_ELEMENT_FORMAT::Float4 });
		elements.push_back({ 0, Gapi::VERTEX_ELEMENT_TYPE::TexCoord, Gapi::VERTEX_ELEMENT_FORMAT::Float2 });

		typedef Gapi::IBufferBase* VertexBufferCallback(void);
		_vertexBuffer = reinterpret_cast<VertexBufferCallback*>(GetProcAddress((HMODULE)library, "RegisterBuffer"))();
		_vertexBuffer->SetVertexDeclaration(elements);
		_vertexBuffer->CreateArray(Gapi::BUFFER_TYPE::Vertex, sizeof(Math::LVERTEX_TEXCOORD), 6, Gapi::BUFFER_USAGE::Dynamic);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	}

	UInt Graphics::MakeTexture(UInt width, UInt height, const void* pixels)
	{
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		return texture;
	}

	void Graphics::PreRender(const Math::Color& color)
	{
		//glFrontFace(GL_CW);

		Math::Matrix4F projectionMatrix;
		projectionMatrix.OrthographicOffCenter(0, 0, 800, 600, 0.0f, 1.0f);

		_shader->Bind();
		_shader->SetUniformMatrix4(_shader->GetUniformLocation("projection"), false, &projectionMatrix);
		_shader->SetUniform4F(_shader->GetUniformLocation("textColor"), color.GetR(), color.GetG(), color.GetB(), color.GetA());

		glActiveTextureARB(GL_TEXTURE0);

		_vertexBuffer->BindVertexArray();
	}

	void Graphics::Render(void* data, UInt textureID)
	{
		glBindTexture(GL_TEXTURE_2D, textureID);

		_vertexBuffer->SetData(data);
		_vertexBuffer->RenderW(Gapi::PRIMITIVE_TYPE::TriangleList, nullptr, 0, 6, _shader->GetShaderProgram());
	}

	void Graphics::PostRender(void)
	{
		_vertexBuffer->UnbindVertexArray();
		glBindTexture(GL_TEXTURE_2D, 0);

		_shader->Unbind();
	}
}