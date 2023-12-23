#include "pchBloxy.h"
#include "OpenGLShader.h"

#include "File/File.h"

#include <glad/glad.h>


namespace Bloxy
{
	OpenGLShader::OpenGLShader(std::string_view filepath, ShaderType type)
		:m_RendererID(0)
	{
		int shaderType = 0;
		switch (type)
		{
		case Bloxy::ShaderType::Vertex:
			shaderType = GL_VERTEX_SHADER;
			break;
		case Bloxy::ShaderType::Fragment:
			shaderType = GL_FRAGMENT_SHADER;
			break;
		}

		m_RendererID = glCreateShader(shaderType);

		File file(filepath, FileType::Read);
		std::string stringSource = file.Read();
		const char* source = stringSource.c_str();

		glShaderSource(m_RendererID, 1, &source, nullptr);
		glCompileShader(m_RendererID);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteShader(m_RendererID);
	}

	uint32_t OpenGLShader::Get()
	{
		return m_RendererID;
	}
}